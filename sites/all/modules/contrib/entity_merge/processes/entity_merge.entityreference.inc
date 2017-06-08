<?php
/**
 * @file
 * Contains merge process for repointing entity reference fields.
 */

class EntityMergeProcessEntityReference extends EntityMergeProcessBase {

  /**
   * Overrides EntityMergeProcessBase::registerSubProcesses().
   *
   * Register a different sub process for each entity reference field.
   */
  public function registerSubProcesses() {
    $processes = array();

    $fields = db_select('field_config', 'fc')
      ->condition('type', 'entityreference')
      ->condition('storage_type', 'field_sql_storage')
      ->fields('fc', array('field_name'))
      ->execute()
      ->fetchCol();

    foreach ($fields as $field_name) {
      $field = field_info_field($field_name);
      if ($field['settings']['target_type'] != $this->entityType) {
        continue;
      }

      $processes[$field_name] = array(
        'class' => 'EntityMergeProcessEntityReferenceField',
        'field_name' => $field_name,
      );
    }

    return $processes;
  }
}

class EntityMergeProcessEntityReferenceField extends EntityMergeProcessBase {

  /**
   * Overrides EntityMergeProcessBase::run().
   */
  public function run() {
    $this->finished = FALSE;
    $start = microtime(TRUE);

    $target_id = entity_id($this->entityType, $this->targetEntity);
    $ids = drupal_map_assoc(array(
      entity_id($this->entityType, $this->entity1),
      entity_id($this->entityType, $this->entity2),
    ));
    // Remove our target ID as that doesn't need changing.
    unset($ids[$target_id]);

    // In some cases (bizarrely) the entity ids are the same. Check for this to
    // avoid PDO Exceptions.
    if (empty($ids)) {
      $this->finished = TRUE;
      return;
    }

    $field_name = $this->conf['field_name'];
    $field = field_info_field($field_name);
    $table = _field_sql_storage_tablename($field);
    $column_name = $field_name . '_target_id';
    $result = db_select($table, 'f')
      ->fields('f', array('entity_type', 'entity_id'))
      ->condition($column_name, $ids)
      ->orderBy('f.entity_type')
      ->execute();

    $referencing_entities = array();
    foreach ($result as $row) {
      $referencing_entities[$row->entity_type][] = $row->entity_id;
    }

    foreach ($referencing_entities as $r_entity_type => $r_entity_ids) {
      foreach (entity_load($r_entity_type, $r_entity_ids) as $r_entity) {
        // Now we have an entity we need to find where the reference is.
        $count = 0;
        $items = $r_entity->{$field_name}[LANGUAGE_NONE];
        foreach ($items as $delta => $item) {
          // Does this item reference either of the originals?
          if (in_array($item['target_id'], $ids)) {
            // First time we've found a match.
            if (!$count) {
              $items[$delta]['target_id'] = $target_id;
              $count++;
            }
            else {
              unset($items[$delta]);
            }
          }
        }
        if ($count) {
          $r_entity->{$field_name}[LANGUAGE_NONE] = array_values($items);

          // If this is a field collection item, we need to treat items that
          // have lost their host entity specially to avoid exceptions.
          if ($r_entity_type == 'field_collection_item' && !$r_entity->hostEntityId()) {
            // We skip host save as it will throw an error, but we do want to
            // still save so that the data is correct.
            $r_entity->save(TRUE);
          }
          else {
            entity_save($r_entity_type, $r_entity);
          }
        }

        if ((microtime(TRUE) - $start) > 59) {
          return;
        }
      }
    }

    $this->finished = TRUE;
  }

  /**
   * Overrides EntityMergeProcessBase::finish().
   */
  public function finish() {
    if ($this->finished) {
      parent::finish();
    }
    else {
      $this->queue->createItem($this);
    }
  }
}

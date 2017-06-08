<?php
/**
 * @file
 * Hooks implemented on behalf of other modules by entity_merge.
 */

/**
 * Implements hook_entity_merge_register_processes()
 */
function entity_merge_entity_merge_register_processes() {
  $processes = array();
  if (module_exists('entityreference')) {
    $processes['entityreference'] = array(
      'class' => 'EntityMergeProcessEntityReference',
      'weight' => 21, // happen after the target entity is saved.
    );
  }

  if (module_exists('og')) {
    $processes['og'] = array(
      'class' => 'EntityMergeProcessOg',
      'weight' => 99, // Last thing before deleting entities.
    );
  }

  return $processes;
}

/**
 * Implements hook_entity_merge_field_items_alter().
 */
function entity_merge_entity_merge_field_items_alter(&$items, $target_entity, $context) {
  if ($context['field']['type'] == 'taxonomy_term_reference') {
    _entity_merge_taxonomy_field_items_alter($items, $target_entity, $context);
  }

  if ($context['field']['type'] == 'entityreference') {
    _entity_merge_entityreference_field_items_alter($items, $target_entity, $context);
  }

  // List field types need duplicates reducing.
  if ($context['field']['module'] == 'list') {
    _entity_merge_list_field_items_alter($items, $target_entity, $context);
  }

  // Make sure field collection items do not get duplicate references.
  if ($context['field']['type'] == 'field_collection') {
    _entity_merge_field_collection_field_items_alter($items, $target_entity, $context);
  }
}

/**
 * Make sure taxonomy_term_reference fields do not reference a tid twice.
 *
 * Implements hook_entity_merge_field_items_alter() on behalf of the taxonomy
 * module.
 */
function _entity_merge_taxonomy_field_items_alter(&$items, $target_entity, $context) {
  $has_tids = array();
  foreach ($items as $delta => $item) {
    if (in_array($item['tid'], $has_tids) || empty($item['tid'])) {
      unset($items[$delta]);
    }
    else {
      $has_tids[] = $item['tid'];
    }
  }
}

/**
 * Make sure enityreference fields do not reference the same entity twice.
 *
 * Implements hook_entity_merge_field_items_alter() on behalf of the
 * entityreference module.
 *
 * @todo: Consider blocking self references.
 */
function _entity_merge_entityreference_field_items_alter(&$items, $target_entity, $context) {
  // Entity reference fields with OG behaviors need to not make any changes.
  if (module_exists('og') && !empty($context['field']['settings']['handler_settings']['behaviors']['og_behavior']['status'])) {
    list($target_id) = entity_extract_ids($context['entity_type'], $target_entity);

    // Clear out the items.
    $items = array();

    // If our target is one of our sources, retain the existing values.
    if ($target_id) {
      list($entity1_id) = entity_extract_ids($context['entity_type'], $context['entity1']);
      list($entity2_id) = entity_extract_ids($context['entity_type'], $context['entity1']);

      if ($target_id == $entity1_id) {
        if (isset($context['entity1']->{$context['field']['field_name']}[$context['langcode']])) {
          $items = $context['entity1']->{$context['field']['field_name']}[$context['langcode']];
        }
      }
      elseif ($target_id == $entity2_id) {
        if (isset($context['entity2']->{$context['field']['field_name']}[$context['langcode']])) {
          $items = $context['entity2']->{$context['field']['field_name']}[$context['langcode']];
        }
      }
    }

    // We don't need to de-dupe when just copying.
    return;
  }

  $has_target_ids = array();
  foreach ($items as $delta => $item) {
    if (in_array($item['target_id'], $has_target_ids)
      || empty($item['target_id'])) {
      unset($items[$delta]);
    }
    else {
      $has_target_ids[] = $item['target_id'];
    }
  }
}

/**
 * Reduce duplicates in fields provided by the list module.
 *
 * Implements hook_entity_merge_field_items_alter() on behalf of the list
 * module.
 */
function _entity_merge_list_field_items_alter(&$items, $target_entity, $context) {
  $has_value = array();
  foreach ($items as $delta => $item) {
    if (in_array($item['value'], $has_value)) {
      unset($items[$delta]);
    }
    else {
      $has_value[] = $item['value'];
    }
  }
}

/**
 * Make sure one field collection does not end up being referenced twice.
 *
 * Implements hook_entity_merge_field_items_alter() on behalf of the list
 * module.
 */
function _entity_merge_field_collection_field_items_alter(&$items, $target_entity, $context) {
  $entities = array();
  $target_id = entity_id($context['entity_type'], $target_entity);
  if (($id1 = entity_id($context['entity_type'], $context['entity1'])) != $target_id) {
    $entities[$id1] = $context['entity1'];
  }
  if (($id2 = entity_id($context['entity_type'], $context['entity2'])) != $target_id) {
    $entities[$id2] = $context['entity2'];
  }

  $field_name = $context['field']['field_name'];
  $target_items = array();
  foreach ($items as $item) {
    $target_items[] = $item['value'];
  }

  foreach ($entities as $id => $entity) {
    foreach ($entity->{$field_name}[LANGUAGE_NONE] as $delta => $item) {
      if (!in_array($item['value'], $target_items)) {
        continue;
      }

      // This is an item that is now referenced by the target_entity therefore
      // we need to remove the reference from the old entity. We do this in the
      // database directly and reset the cache, otherwise the field collection
      // items themselves would get deleted.
      // First remove item from the entity.
      unset($entity->{$field_name}[LANGUAGE_NONE][$delta]);

      // Second update the database.
      // @todo: Make this storage method agnostic.
      db_delete('field_data_'.$field_name)
        ->condition('entity_id', $id)
        ->condition('entity_type', $context['entity_type'])
        ->condition('delta', $delta)
        ->execute();
      db_update('field_data_'.$field_name)
        ->expression('delta', 'delta - 1')
        ->condition('entity_id', $id)
        ->condition('entity_type', $context['entity_type'])
        ->condition('delta', $delta, '>')
        ->execute();

      list(,$vid,) = entity_extract_ids($context['entity_type'], $entity);
      $dq = db_delete('field_revision_'.$field_name);
      $dq->condition('entity_id', $id);
      $dq->condition('entity_type', $context['entity_type']);
      $dq->condition('delta', $delta);
      $uq = db_update('field_revision_'.$field_name);
      $uq->expression('delta', 'delta - 1');
      $uq->condition('entity_id', $id);
      $uq->condition('entity_type', $context['entity_type']);
      $uq->condition('delta', $delta, '>');
      if (!empty($vid)) {
        $dq->condition('revision_id', $vid);
        $uq->condition('revision_id', $vid);
      }
      $dq->execute();
      $uq->execute();
    }
    // Third update deltas on entity object and reset cache.
    if (!empty($entity->{$field_name}[LANGUAGE_NONE])) {
      $entity->{$field_name}[LANGUAGE_NONE] = array_values($entity->{$field_name}[LANGUAGE_NONE]);
    }
    else {
      $entity->{$field_name} = array();
    }
    entity_get_controller($context['entity_type'])->resetCache(array($id));
  }
}

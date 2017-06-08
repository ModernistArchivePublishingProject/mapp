<?php
/**
 * @file
 * Contains merge process for OG group memberships.
 */

class EntityMergeProcessOg extends EntityMergeProcessBase {

  /**
   * Mapping of field names.
   *
   * Outer keys are the field we want and inner keys are whether we want to
   * group version.
   *
   * @var array
   */
  protected $membership_fields = array(
    'type' => array(
      FALSE => 'entity_type',
      TRUE => 'group_type',
    ),
    'id' => array(
      FALSE => 'etid',
      TRUE => 'gid',
    ),
  );

  /**
   * Overrides EntityMergeProcessBase::registerSubProcesses().
   *
   * Register de-duping sub processes.
   */
  public function registerSubProcesses() {
    $processes = array();

    // Add merge memberships for this entity as the audience.
    $this->addDedupeProcesses($processes, FALSE);

    // Add merge memberships for this entity as the group.
    $this->addDedupeProcesses($processes, TRUE);

    return $processes;
  }

  /**
   * Move all the remaining memberships onto the target entity.
   */
  function finish() {
    // Move memberships for this entity as the audience.
    $this->moveMembership(FALSE);

    // Move memberships for this entity as the group.
    $this->moveMembership(TRUE);

    // Refresh the cache for our two entities.
    list($entity1_id) = entity_extract_ids($this->entityType, $this->entity1);
    cache_clear_all('field:' . $this->entityType . ':' . $entity1_id, 'cache_field');
    list($entity2_id) = entity_extract_ids($this->entityType, $this->entity2);
    cache_clear_all('field:' . $this->entityType . ':' . $entity2_id, 'cache_field');
    entity_get_controller('og_membership')->resetCache();
    entity_get_controller($this->entityType)->resetCache();

    parent::finish();
  }

  /**
   * Find duplicates and create merge processes for them.
   *
   * @param array $processes
   *   The processes array we want to add to.
   * @param bool $group
   *   Whether the entities we are merging are the group or the audience.
   *
   * @return array
   *   An array of sub processes.
   *
   * @see EntityMergeProcessBase::registerSubProcesses()
   */
  protected function addDedupeProcesses(array &$processes, $group) {
    // Look for any memberships that exist for both entities.
    $query = db_select('og_membership', 'm1');
    $condition_id_field = $this->membership_fields['id'][!$group];
    $query->join('og_membership', 'm2',
      "m2.field_name = m1.field_name AND m2.entity_type = m1.entity_type AND m2.group_type = m1.group_type AND m2.{$condition_id_field} = m1.{$condition_id_field}");
    $query->addField('m1', 'id', 'm1_id');
    $query->addField('m2', 'id', 'm2_id');

    // Get our ids.
    list($entity1_id) = entity_extract_ids($this->entityType, $this->entity1);
    list($entity2_id) = entity_extract_ids($this->entityType, $this->entity2);

    // Set up our conditions correctly.
    $query->condition('m1.' . $this->membership_fields['type'][$group], $this->entityType);
    $query->condition('m1.' . $this->membership_fields['id'][$group], $entity1_id);
    $query->condition('m2.' . $this->membership_fields['id'][$group], $entity2_id);

    $duplicates = $query->execute()->fetchAllKeyed();

    // If we have duplicates, queue them up to be merged.
    if (count($duplicates)) {
      // Find out the merge class to be used.
      $info = entity_get_info('og_membership');
      $merge_class = $info['merge handler class'];

      // Add a process for each item.
      foreach ($duplicates as $membership1 => $membership2) {
        $entity1_membership = og_membership_load($membership1);
        $entity2_membership = og_membership_load($membership2);

        $processes[] = array(
          'class' => $merge_class,
          'entityType' => 'og_membership',
          'entity1' => $entity1_membership,
          'entity2' => $entity2_membership,
          'targetEntity' => FALSE,
        );
      }
    }
  }

  /**
   * Move memberships onto the target entity.
   *
   * @param bool $group
   *   Whether the entities we are merging are the group or the audience.
   */
  protected function moveMembership($group) {
    list($target_id) = entity_extract_ids($this->entityType, $this->targetEntity);
    list($entity1_id) = entity_extract_ids($this->entityType, $this->entity1);
    list($entity2_id) = entity_extract_ids($this->entityType, $this->entity2);

    // We don't need to move from our target to itself.
    $ids = array_diff(array($entity1_id, $entity2_id), array($target_id));

    // Make sure we have some Ids.
    if (empty($ids)) {
      return;
    }

    // Build our query.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'og_membership');
    $query->propertyCondition($this->membership_fields['type'][$group], $this->entityType);
    $query->propertyCondition($this->membership_fields['id'][$group], $ids);
    $result = $query->execute();

    if (!empty($result['og_membership'])) {
      foreach (entity_load('og_membership', array_keys($result['og_membership']), array(), TRUE) as $membership) {
        $membership->{$this->membership_fields['id'][$group]} = $target_id;
        entity_save('og_membership', $membership);
      }
    }
  }
}

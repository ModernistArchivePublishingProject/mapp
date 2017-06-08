<?php
/**
 * @file
 * Contains merge process for invoking merge hooks.
 */

class EntityMergeProcessDeleteSources extends EntityMergeProcessBase {

  /**
   * Overrides EntityMergeProcessBase::run()
   */
  public function run() {
    list($target_id) = entity_extract_ids($this->entityType, $this->targetEntity);

    // Delete any entities which aren't the target.
    foreach (array(1, 2) as $i) {
      list($entity_id) = entity_extract_ids($this->entityType, $this->{'entity' . $i});
      if ($entity_id != $target_id) {
        entity_delete($this->entityType, $entity_id);
      }
    }
  }
}

<?php
/**
 * @file
 * Contains merge process for invoking merge hooks.
 */

class EntityMergeProcessSaveTarget extends EntityMergeProcessBase {

  /**
   * Overrides EntityMergeProcessBase::run()
   */
  public function run() {
    entity_save($this->entityType, $this->targetEntity);
  }
}

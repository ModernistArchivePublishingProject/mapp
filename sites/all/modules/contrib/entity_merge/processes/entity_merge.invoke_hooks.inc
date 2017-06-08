<?php
/**
 * @file
 * Contains merge process for invoking merge hooks.
 */

class EntityMergeProcessInvokeHooks extends EntityMergeProcessBase {

  /**
   * Overrides EntityMergeProcessBase::run()
   */
  public function run() {
    module_invoke_all('entity_merge', $this->targetEntity, $this->entity1, $this->entity2, $this->entityType);
    module_invoke_all('entity_merge_' . $this->entityType, $this->targetEntity, $this->entity1, $this->entity2);
  }

}

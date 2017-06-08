<?php
/**
 * @file
 * Contains default entity merge handler.
 */

/**
 * Default merge handler class for entities.
 */
class EntityMergeHandlerOgMembership extends EntityMergeHandlerDefault {

  /**
   * Overrides EntityMergeHandlerBase::registerSubProcesses().
   */
  public function registerSubProcesses() {
    $processes = parent::registerSubProcesses();

    $processes['delete_sources'] = array(
      'class' => 'EntityMergeProcessDeleteSources',
      'weight' => 100, // Should always run last.
    );

    return $processes;
  }
}

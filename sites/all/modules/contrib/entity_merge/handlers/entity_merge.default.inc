<?php
/**
 * @file
 * Contains default entity merge handler.
 */

/**
 * Default merge handler class for entities.
 */
class EntityMergeHandlerDefault extends EntityMergeHandlerBase {

  /**
   * Overrides EntityMergeHandlerBase::merge().
   *
   * This handler merges entity_2 into entity_1 and saves entity_1. To create a
   * a new entity on merge you should use a different merge callback.
   */
  public function merge($time = 0, $queue_name = 'entity_merge') {
    // Get the time at the start.
    $end_time = microtime(TRUE) + $time;

    // Set the queue
    $this->setQueue(DrupalQueue::get($queue_name));
    $this->prepare()->go();

    while (microtime(TRUE) < $end_time && $item = $this->queue->claimItem()) {
      $item->data->prepare()->go();
      $this->queue->deleteItem($item);
    }
  }
}

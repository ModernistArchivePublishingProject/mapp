<?php
/**
 * @file
 * Contains interface for entity merge handlers.
 */

/**
 * Interface for EntityMergeHandler classes.
 */
interface EntityMergeHandlerInterface {

  /**
   * Merge two entities.
   *
   * @param stdClass|Object $entity_1
   *   The first entity to merge. Fields on this entity will take precedent over
   *   fields on entity_2.
   * @param stdClass|Object $entity_2
   *   The second entity to merge.
   *
   * @return stdClass|Object
   *   The merged entity.
   */
  public function merge();
}

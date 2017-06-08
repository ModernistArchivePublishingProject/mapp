<?php
/**
 * @file
 * Contains interface class for entity merge processes.
 */

/**
 * Interface class for entity merge processes.
 */
interface EntityMergeProcessInterface {

  /**
   * Prepare the process.
   */
  public function prepare();

  /**
   * Run the process.
   */
  public function go();

}

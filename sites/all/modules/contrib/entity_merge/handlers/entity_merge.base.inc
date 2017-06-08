<?php
/**
 * @file
 * Contains base entity merge handler to encapsulate merging logic.
 */

/**
 * Base class for all EntityMergeHandler classes.
 */
abstract class EntityMergeHandlerBase extends EntityMergeProcessBase implements EntityMergeHandlerInterface {

  /**
   * Overrides EntityMergeProcessBase::registerSubProcesses().
   */
  public function registerSubProcesses() {
    $processes = array();

    $processes['merge_fields'] = array(
      'class' => 'EntityMergeProcessMergeFields',
      'weight' => -5,
    );

    $processes['invoke_hooks'] = array(
      'class' => 'EntityMergeProcessInvokeHooks',
      'weight' => 10,
    );

    $processes['save_target'] = array(
      'class' => 'EntityMergeProcessSaveTarget',
      'weight' => 20,
    );

    return $processes;
  }

  /**
   * Invoke process registration hooks.
   */
  public function invokeProcessRegistrationHooks(&$processes = array()) {
    $processes += module_invoke_all('entity_merge_register_processes', $this->entityType, $this->entity1, $this->entity2, $this->conf);
    $this->sortSubProcesses($processes);
    $context = array(
      $this->entity1,
      $this->entity2,
    );
    drupal_alter('entity_merge_register_processes', $processes, $this->entityType, $context);
  }

  /**
   * Sort Processes.
   */
  public function sortSubProcesses(&$processes) {
    uasort($processes, 'drupal_sort_weight');
  }

  /**
   * Overrides EntityMergeProcessBase::prepare().
   */
  public function prepare() {
    $this->targetEntity = clone $this->entity1;
    $processes = $this->registerSubProcesses();
    $this->invokeProcessRegistrationHooks($processes);
    $this->prepareSubProcesses($processes);
    $this->log('start');
    return $this;
  }

  /**
   * Log that we have finished.
   */
  public function finish() {
    $this->log('finish');
    parent::finish();
  }
  /**
   * Log when the handler starts or finishes.
   */
  public function log($option) {
    $row = new stdClass;
    $row->entity_type = $this->entityType;
    $row->entity_id_1 = entity_id($this->entityType, $this->entity1);
    $row->entity_id_2 = entity_id($this->entityType, $this->entity2);

    if ($option == 'start') {
      $row->start_time = time();

      drupal_write_record('entity_merge_semaphore', $row);
      $this->id = $row->id;
    }
    else {
      $row->id = $this->id;
      $row->finish_time = time();

      drupal_write_record('entity_merge_semaphore', $row, 'id');
    }
  }

}

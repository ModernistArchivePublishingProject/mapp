<?php
/**
 * @file
 * Contains base class for entity merge processes.
 */

/**
 * Base class for entity merge processes.
 */
abstract class EntityMergeProcessBase implements EntityMergeProcessInterface {

  /**
   * The entity type being merged.
   * @var string
   */
  protected $entityType;

  /**
   * The current queue.
   */
  protected $queue;

  /**
   * The parent process
   */
  public $parentProcess;

  /**
   * The sub processes
   */
  protected $subProcesses = array();

  /**
   * The current sub process.
   */
  protected $currentSubProcess = FALSE;

  /**
   * The first entity to be merged.
   */
  protected $entity1;

  /**
   * The second entity to be merged.
   */
  protected $entity2;

  /**
   * The id in the semaphore table.
   */
  protected $id;

  public function __construct($entity_type, $entity1, $entity2, $queue = FALSE, $target_entity = FALSE, $parent = FALSE, $conf = array()) {
    $this->entityType = $entity_type;
    $this->entity1 = $entity1;
    $this->entity2 = $entity2;
    $this->queue = $queue;
    $this->targetEntity = $target_entity;
    $this->parentProcess = $parent;
    $this->conf = $conf;
  }

  /**
   * Set the QueueObject
   */
  public function setQueue($queue) {
    $this->queue = $queue;
  }

  /**
   * Register subprocesses.
   *
   * @return array
   *  An array keyed by a unique string and containing atleast
   *  - class: The class used to run the sub process.
   *  - weight: The weight. Sub processes will be done in order of weight.
   */
  public function registerSubProcesses() {
    return array();
  }

  /**
   * Prepare sub-processes.
   */
  public function prepareSubProcesses($processes) {
    foreach ($processes as $name => $proc) {
      if (empty($proc['class']) || !class_exists($proc['class'])) {
        throw new Exception('Class ' . $proc['class'] . ' was not found');
      }

      $class = $proc['class'];
      $entityType = isset($proc['entityType']) ? $proc['entityType'] : $this->entityType;
      $entity1 = isset($proc['entity1']) ? $proc['entity1'] : $this->entity1;
      $entity2 = isset($proc['entity2']) ? $proc['entity2'] : $this->entity2;
      $targetEntity = isset($proc['targetEntity']) ? $proc['targetEntity'] : $this->targetEntity;

      // Get the config to pass onto the sub-process.
      $skip_keys = array('class', 'entityType', 'entity1', 'entity2', 'targetEntity');
      $conf = array_diff_key($proc, array_fill_keys($skip_keys, TRUE));

      // Merge in the parent config.
      $conf += $this->conf;

      $this->subProcesses[$name] = new $class($entityType, $entity1, $entity2, $this->queue, $targetEntity, $this, $conf);
    }
  }

  /**
   * Prepare this process.
   */
  public function prepare() {
    $processes = $this->registerSubProcesses();
    $this->prepareSubProcesses($processes);
    return $this;
  }

  /**
   * Implements EntityMergeProcessIntergace::start();
   */
  public function go() {
    if (!empty($this->subProcesses)) {
      $this->queueNextProcess();
      return;
    }

    $this->run();
    $this->finish();
  }

  /**
   * Run Method.
   */
  public function run() {}

  /**
   * Finish running. Pass off control to the parent.
   */
  public function finish() {
    if (!empty($this->parentProcess)) {
      if (!$this->parentProcess->queueNextProcess()) {
        $this->parentProcess->finish();
      }
    }
  }

  /**
   * Queue the next process
   */
  public function queueNextProcess() {
    if ($this->currentSubProcess === FALSE) {
      $this->currentSubProcess = key($this->subProcesses);
    }
    else {
      $next = FALSE;
      $assigned = FALSE;
      foreach(array_keys($this->subProcesses) as $key) {
        if ($next) {
          $this->currentSubProcess = $key;
          $assigned = TRUE;
          break;
        }
        if ($key == $this->currentSubProcess) {
          $next = TRUE;
        }
      }
      if (!$assigned) {
        return FALSE;
      }
    }

    // Actually Queue the process.
    $this->queue->createItem($this->subProcesses[$this->currentSubProcess]);
    return TRUE;
  }
}

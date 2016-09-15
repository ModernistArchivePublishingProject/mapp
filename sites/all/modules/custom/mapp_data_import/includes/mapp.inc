<?php
abstract class MAPPMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->path = drupal_get_path('module', 'mapp_data_import') . '/data_sources';
  }
}
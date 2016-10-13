<?php

abstract class MAPPMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->path = drupal_get_path('module', 'mapp_data_import') . '/data_sources';

    $this->csv_options = array(
      'header_rows' => TRUE,
      'embedded_newlines' => TRUE,
    );

  }

  public function prepareRow($row) {
    // Skip manually entered rows
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }
  }

  public function MAPPImageMigration() {

    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_images',
      array('host_entity_type' => 'node'));

    // Image file mapping
    $this->addFieldMapping('field_image', 'Image');
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'mapp_data_import') . '/images');
    $this->addFieldMapping('field_image:file_replace')
      ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    // Basic mappings
    $this->addFieldMapping('field_caption', 'Image Caption');
    $this->addFieldMapping('field_source', 'Image Source');

    // Entity references
    $this->addFieldMapping('field_rights_holder', 'Rights Holder')
      ->sourceMigration(array('PersonNode')); // TODO: add business & library migration

  }

}

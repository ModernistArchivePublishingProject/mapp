<?php

class ImagesMigration extends Migration {

  protected $baseDir;

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import files.');
    $this->baseDir = drupal_get_path('module', 'mapp_data_import') . '/images';

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'sourceid' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => t('Source ID'),
        ),
      ),
      MigrateDestinationFile::getKeySchema()
    );

    $directories = array(
      $this->baseDir,
    );

    // Edit to include the desired extensions.
    $allowed = 'jpg jpeg gif png tif';
    if (module_exists('file_entity')) {
      $allowed = variable_get('file_entity_default_allowed_extensions', $allowed);
    }
    $file_mask = '/^.*\.(' . str_replace(array(',', ' '), '|', $allowed) . ')$/i';
    $list = new MigrateListFiles($directories, $this->baseDir, $file_mask);
    // Send FALSE as second argument to prevent loading of file data, which we
    // don't need.
    $item = new MigrateItemFile($this->baseDir, FALSE);
    $fields = array('sourceid' => t('File name with path'));
    $this->source = new MigrateSourceList($list, $item, $fields);
    $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

    // Save to the default file scheme.
    $this->addFieldMapping('destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://');
    // Use the full file path in the file name so that we retain the directory
    // structure.
    $this->addFieldMapping('destination_file', 'destination_file');
    // Set the value to the file name, including path.
    $this->addFieldMapping('value', 'file_uri');
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->file_uri = $this->baseDir . $row->sourceid;

    // Remove the leading forward slash.
    $row->destination_file = substr($row->sourceid, 1);
  }

}

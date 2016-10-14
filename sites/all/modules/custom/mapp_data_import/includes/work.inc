<?php

abstract class WorkMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->path .= '/work.csv'; // Append CSV filename to path set in MAPPMigration
    $this->source = new MigrateSourceCSV($this->path, array(), $this->csv_options);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'csvrownum' => array(
          'type' => 'int',
          'unsigned' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );
  }
}

class WorkNodeMigration extends WorkMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Work nodes from CSV');
    $this->destination = new MigrateDestinationNode('work');

    // Basic mappings
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_description', 'Description');
    $this->addFieldMapping('field_copyright_date', 'Copyright Date');

    // Tax term references
    $this->addFieldMapping('field_work_type', 'Type');
    $this->addFieldMapping('field_work_type:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_work_type:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_language', 'Original Language');
    $this->addFieldMapping('field_language:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_language:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_copyright_status', 'Copyright Status');
    $this->addFieldMapping('field_copyright_status:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_copyright_status:create_term')
      ->defaultValue(TRUE);

    // Entity references
    $this->entity_reference_fields = array (
      'Author' => 'field_author',
      'Editor' => 'field_editor',
      'Translator' => 'field_translator',
    );
    $this->addFieldMapping('field_author', 'Author')
      ->separator('|')
      ->sourceMigration(array('PersonNode')); // TODO: add business migration
    $this->addFieldMapping('field_editor', 'Editor')
      ->separator('|')
      ->sourceMigration(array('PersonNode'));
    $this->addFieldMapping('field_translator', 'Translator')
      ->separator('|')
      ->sourceMigration(array('PersonNode'));

  }

  public function prepareRow($row) {

    // Skip manually entered rows
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }

    parent::prepareRow($row);

    // Convert the date into ISO format.
    if (isset($row->{'Copyright Date'})) {
      $row->{'Copyright Date'} .= '-01-01T00:00:00';
    }

  }

  public function prepare($entity, $row) {

    $this->MAPP_populate_entity_refs($entity, $row);

  }

}

class WorkImagesFcMigration extends WorkMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->MAPPImageMigration();

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('WorkNode');
    $this->addFieldMapping('field_image:destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://images/work');
  }
}

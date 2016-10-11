<?php


class WorkNodeMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate Work nodes from CSV');
    $this->path .= '/work.csv'; // Append CSV filename to path set in MAPPMigration
    $options = array(
      'header_rows' => TRUE,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($this->path, array(), $options);
    $this->destination = new MigrateDestinationNode('work');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'csvrownum' => array(
          'type' => 'int',
          'unsigned' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

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
    $this->addFieldMapping('field_author', 'Author')
      ->separator(',')
      ->sourceMigration(array('PersonNode')); // TODO: add business migration
    $this->addFieldMapping('field_editor', 'Editor')
      ->separator(',')
      ->sourceMigration(array('PersonNode'));
    $this->addFieldMapping('field_translator', 'Translator')
      ->separator(',')
      ->sourceMigration(array('PersonNode'));

  }

  public function prepareRow($row) {

    // Skip manually entered rows
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }

  }

}

class WorkImagesFcMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate Images FC from CSV');
    $this->path .= '/work.csv'; // Append CSV filename to path set in MAPPMigration
    $options = array(
      'header_rows' => TRUE,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($this->path, array(), $options);
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_images',
      array('host_entity_type' => 'node'));
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'csvrownum' => array(
          'type' => 'int',
          'unsigned' => TRUE,
        )
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('WorkNode');

    // Image file mapping


    // Basic mappings
    $this->addFieldMapping('field_caption', 'Image Caption');
    $this->addFieldMapping('field_source', 'Image Source');

    // Entity references
    $this->addFieldMapping('field_rights_holder', 'Rights Holder')
      ->sourceMigration(array('PersonNode')); // TODO: add business & library migration
  }

  public function prepareRow($row) {

    // Skip manually entered rows
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }

  }

}


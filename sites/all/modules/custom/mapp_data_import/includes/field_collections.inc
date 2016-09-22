<?php


/*
 * Migrate the Biography field into the correct field collection
 */
class BiographyFcMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate Biography FC from CSV');
    $this->path .= '/person.csv'; // Append CSV filename to path set in MAPPMigration
    $options = array(
      'header_rows' => TRUE,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($this->path, array(), $options);
    $this->destination = new MigrateDestinationFieldCollection(
      'field_coll_biography',
      array('host_entity_type' => 'node'));
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'csvrownum' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('PersonNode');

    // Basic mappings
    $this->addFieldMapping('field_biography', 'Biography Narrative');

    // Tax term references
    $this->addFieldMapping('field_content_authored_by', 'Authored By');
    $this->addFieldMapping('field_content_authored_by:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_content_authored_by:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_content_edited_by', 'Edited By');
    $this->addFieldMapping('field_content_edited_by:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_content_edited_by:ignore_case')
      ->defaultValue(TRUE);

  }

  public function prepareRow($row) {

    // Skip manually entered rows
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }

  }

}

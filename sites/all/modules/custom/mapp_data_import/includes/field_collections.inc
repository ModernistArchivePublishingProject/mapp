<?php


/*
 * Migrate the Biography field into the correct field collection
 */
class BiographyFcMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate Biography FC from CSV');
    $this->path .= '/person.csv'; // Append CSV filename to path set in MAPPMigration
    $this->source = new MigrateSourceCSV($this->path, array(), array('header_rows' => 1));
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


  }
}
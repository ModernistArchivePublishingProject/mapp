<?php


class PersonNodeMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate Person nodes from CSV');
    $this->path .= '/person.csv'; // Append CSV filename to path set in MAPPMigration
    $this->source = new MigrateSourceCSV($this->path, array(), array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('person');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'csvrownum' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Basic mappings
    $this->addFieldMapping('title', 'Original Name');
    $this->addFieldMapping('field_name_authority', 'Identifiers');
    $this->addFieldMapping('field_birth_date:year', 'Birth Date');
    $this->addFieldMapping('field_death_date:year', 'Death Date');

    $this->addFieldMapping('field_birth_place', 'Birth Nation');
    $this->addFieldMapping('field_birth_place:locality', 'Birth City');
    $this->addFieldMapping('field_death_place', 'Death Nation');
    $this->addFieldMapping('field_death_place:locality', 'Death City');

    // Tax term references
    $this->addFieldMapping('field_gender', 'Gender');
      //->sourceMigration('tax_specialization');
    $this->addFieldMapping('field_occupation', 'Occupation')
      ->separator(',');
      //->sourceMigration('tax_specialization')

    // Entity references
    $this->addFieldMapping('field_bibliographic_item', 'Bibliographic Item');
      // ->sourceMigration(array('node_person_to_profile2'));


  }
}


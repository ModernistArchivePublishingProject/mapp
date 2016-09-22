<?php


class PersonNodeMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate Person nodes from CSV');
    $this->path .= '/person.csv'; // Append CSV filename to path set in MAPPMigration
    $options = array(
      'header_rows' => TRUE,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($this->path, array(), $options);
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

    $this->addFieldMapping('field_birth_place', 'Birth Nation');
    $this->addFieldMapping('field_birth_place:locality', 'Birth City');
    $this->addFieldMapping('field_death_place', 'Death Nation');
    $this->addFieldMapping('field_death_place:locality', 'Death City');

    // Partial date
    $this->addFieldMapping('field_birth_date')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_birth_date:year', 'Birth Date');
    $this->addFieldMapping('field_death_date')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_death_date:year', 'Death Date');

    // Tax term references
    $this->addFieldMapping('field_gender', 'Gender');
    $this->addFieldMapping('field_gender:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_occupation', 'Occupation')
      ->separator(',');
    $this->addFieldMapping('field_occupation:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_occupation:ignore_case')
      ->defaultValue(TRUE);


    // Entity references
    $this->addFieldMapping('field_bibliographic_item', 'Bibliographic Item');
      // ->sourceMigration(array('node_person_to_profile2'));


  }

  public function prepareRow($row) {

    // Skip manually entered rows
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }

  }

}


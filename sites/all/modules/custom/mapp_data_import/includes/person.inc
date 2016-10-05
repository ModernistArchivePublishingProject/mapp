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


class PersonBiographyFcMigration extends MAPPMigration {
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


class PersonImagesFcMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate Images FC from CSV');
    $this->path .= '/person.csv'; // Append CSV filename to path set in MAPPMigration
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
          'not null' => TRUE,
        )
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('PersonNode');

    // Image file mapping


    // Basic mappings
    $this->addFieldMapping('field_caption', 'Image Caption');
    $this->addFieldMapping('field_source', 'Image Source');

  }

  public function prepareRow($row) {

    // Skip manually entered rows
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }

  }

}


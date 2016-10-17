<?php

abstract class PersonMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->path .= '/person.csv'; // Append CSV filename to path set in MAPPMigration
    $this->source = new MigrateSourceCSV($this->path, array(), $this->csv_options);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'name' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );
  }
}

class PersonNodeMigration extends PersonMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Person nodes from CSV');
    $this->destination = new MigrateDestinationNode('person');

    // Basic mappings
    $this->addFieldMapping('title', 'name');
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
      ->separator('|');
    $this->addFieldMapping('field_occupation:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_occupation:ignore_case')
      ->defaultValue(TRUE);

    // Entity references
    $this->entity_reference_fields = array (
      'Bibliographic Item' => 'field_bibliographic_item',
    );
    $this->addFieldMapping('field_bibliographic_item', 'Bibliographic Item');
    // ->sourceMigration(array('BiblioNode')); //TODO: add biblio migration if a spreadsheet is created for it

  }

  public function prepare($entity, $row) {

    $this->MAPP_populate_entity_refs($entity, $row);

  }
  
}

class PersonBiographyFcMigration extends PersonMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Biography FC from CSV');
    $this->destination = new MigrateDestinationFieldCollection(
      'field_coll_biography',
      array('host_entity_type' => 'node'));

    $this->addFieldMapping('host_entity_id', 'name')
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
}

class PersonImagesFcMigration extends PersonMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->MAPPImageMigration();

    $this->addFieldMapping('host_entity_id', 'name')
      ->sourceMigration('PersonNode');
    $this->addFieldMapping('field_image:destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://images/person');
  }
}


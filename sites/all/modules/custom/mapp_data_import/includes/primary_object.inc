<?php

abstract class PrimaryObjectMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->path .= '/primary_object.csv'; // Append CSV filename to path set in MAPPMigration
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

class PrimaryObjectNodeMigration extends PrimaryObjectMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Primary Object nodes from CSV');
    $this->destination = new MigrateDestinationNode('primary_object');

    // Basic mappings
    $this->addFieldMapping('field_description', 'Description');
    $this->addFieldMapping('field_marginalia', 'Marginalia');
    $this->addFieldMapping('field_annotations', 'Annotations');
    $this->addFieldMapping('field_impression', 'Impression');
    $this->addFieldMapping('field_identifier', 'Identifier (Call Number)');
    $this->addFieldMapping('field_link_digitized', 'Links to Digitized Material');

    // Tax term references
    $this->addFieldMapping('field_condition', 'Condition');
    $this->addFieldMapping('field_condition:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_condition:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_damage', 'Damage');
    $this->addFieldMapping('field_damage:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_damage:create_term')
      ->defaultValue(TRUE);

    // Entity references
    $this->entity_reference_fields = array (
      'Edition' => 'field_edition_ref',
      'Owner' => 'field_owner',
      'Reader' => 'field_reader',
      'Library' => 'field_library',
    );
    $this->addFieldMapping('field_edition_ref', 'Edition')
      ->separator('|')
      ->sourceMigration(array('EditionNode'));
    $this->addFieldMapping('field_owner', 'Owner')
      ->separator('|')
      ->sourceMigration(array('PersonNode'));
    $this->addFieldMapping('field_reader', 'Reader')
      ->separator('|')
      ->sourceMigration(array('PersonNode'));
    $this->addFieldMapping('field_library', 'Library'); // TODO: Add library (if created) migration

  }

}

class PrimaryObjectPurchaserFcMigration extends PrimaryObjectMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Purchaser FC from CSV');
    $this->destination = new MigrateDestinationFieldCollection(
      'field_purchasers',
      array('host_entity_type' => 'node'));

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('PrimaryObjectNode');

    // Entity references
    $this->entity_reference_fields = array (
      'Purchasers' => 'field_purchaser',
    );
    $this->addFieldMapping('field_purchaser', 'Purchasers')
      ->separator('|')
      ->sourceMigration(array('PersonNode'));
  }

}

class PrimaryObjectImagesFcMigration extends PrimaryObjectMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->MAPPImageMigration();

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('PrimaryObjectNode');
    $this->addFieldMapping('field_image:destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://images/primary_object');
  }
}

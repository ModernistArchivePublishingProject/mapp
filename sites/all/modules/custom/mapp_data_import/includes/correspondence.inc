<?php

abstract class CorrespondenceMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->path .= '/correspondence.csv'; // Append CSV filename to path set in MAPPMigration
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

class CorrespondenceNodeMigration extends CorrespondenceMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Correspondence nodes from CSV');
    $this->destination = new MigrateDestinationNode('correspondence');

    // Basic mappings
    $this->addFieldMapping('field_description', 'Description');
    $this->addFieldMapping('field_publication_date', 'Date written');

    // Address fields
    $this->addFieldMapping('field_sent_from', 'From Country');
    $this->addFieldMapping('field_sent_from:locality', 'From City');
    $this->addFieldMapping('field_sent_from:postal_code', 'From Postcode');
    $this->addFieldMapping('field_sent_from:thoroughfare', 'From Address 1');
    $this->addFieldMapping('field_sent_from:premise', 'From Address 2');

    $this->addFieldMapping('field_sent_to', 'To Country');
    $this->addFieldMapping('field_sent_to:locality', 'To City');
    $this->addFieldMapping('field_sent_to:postal_code', 'To Postcode');
    $this->addFieldMapping('field_sent_to:thoroughfare', 'To Address 1');
    $this->addFieldMapping('field_sent_to:premise', 'To Address 2');

    // Tax term references
    $this->addFieldMapping('field_correspondence_type', 'Correspondence Type');
    $this->addFieldMapping('field_correspondence_type:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_correspondence_type:create_term')
      ->defaultValue(TRUE);

    // Entity references
    $this->entity_reference_fields = array (
      'Author' => 'field_author',
      'Recipient' => 'field_recipient',
      'Related to' => 'field_related_to',
      'Library' => 'field_library',
    );
    $this->addFieldMapping('field_author', 'Author')
      ->separator('|')
      ->sourceMigration(array('PersonNode')); // TODO: add business migration
    $this->addFieldMapping('field_recipient', 'Recipient')
      ->separator('|')
      ->sourceMigration(array('PersonNode')); // TODO: add business migration
    $this->addFieldMapping('field_related_to', 'Related to')
      ->sourceMigration(array('WorkNode')); // TODO: add business and library (if created) migrations
    $this->addFieldMapping('field_library', 'Library'); // TODO: Add library (if created) migration

  }

  public function prepare($entity, $row) {

    $this->MAPP_populate_entity_refs($entity, $row);

  }

}

class CorrespondenceImagesFcMigration extends CorrespondenceMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->MAPPImageMigration();

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('CorrespondenceNode');
    $this->addFieldMapping('field_image:destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://images/correspondence');
  }
}

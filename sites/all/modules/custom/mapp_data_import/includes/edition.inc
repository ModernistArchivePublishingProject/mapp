<?php

abstract class EditionMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->path .= '/edition.csv'; // Append CSV filename to path set in MAPPMigration
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

class EditionNodeMigration extends EditionMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Edition nodes from CSV');
    $this->destination = new MigrateDestinationNode('edition');

    // Basic mappings
    $this->addFieldMapping('field_description', 'Description');
    $this->addFieldMapping('field_link_digitized', 'Links to Digitized Materials');
    $this->addFieldMapping('field_pages', 'Number of Pages');
    $this->addFieldMapping('field_price', 'Price');
    $this->addFieldMapping('field_print_run', 'Print Run');
    $this->addFieldMapping('field_size', 'Size');

    // Tax term references
    $this->addFieldMapping('field_edition', 'Type of Edition');
    $this->addFieldMapping('field_edition_type:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_edition_type:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_language', 'Language');
    $this->addFieldMapping('field_language:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_language:create_term')
      ->defaultValue(TRUE);

    // Entity references
    $this->entity_reference_fields = array (
      'Work' => 'field_work',
      'Publisher' => 'field_publisher',
      'Printer' => 'field_printer',
      'Illustrator' => 'field_illustrator',
    );
    $this->addFieldMapping('field_work', 'Work')
      ->separator('|')
      ->sourceMigration(array('WorkNode'));
    $this->addFieldMapping('field_publisher', 'Publisher')
      ->separator('|')
      ->sourceMigration(array('BusinessNode'));
    $this->addFieldMapping('field_printer', 'Printer')
      ->separator('|')
      ->sourceMigration(array('BusinessNode'));
    $this->addFieldMapping('field_illustrator', 'Illustrator')
      ->separator('|')
      ->sourceMigration(array('BusinessNode', 'PersonNode'));
  }

}

class EditionPurchaserFcMigration extends EditionMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Purchaser FC from CSV');
    $this->destination = new MigrateDestinationFieldCollection(
      'field_purchasers',
      array('host_entity_type' => 'node'));

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('EditionNode');

    // Entity references
    $this->entity_reference_fields = array (
      'Purchasers' => 'field_purchaser',
    );
    $this->addFieldMapping('field_purchaser', 'Purchasers')
      ->separator('|')
      ->sourceMigration(array('PersonNode'));
  }

}

class EditionImagesFcMigration extends EditionMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->MAPPImageMigration();

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('EditionNode');
    $this->addFieldMapping('field_image:destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://images/edition');
  }
}

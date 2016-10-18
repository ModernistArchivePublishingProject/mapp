<?php

abstract class BusinessMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->path .= '/business.csv'; // Append CSV filename to path set in MAPPMigration
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

class BusinessNodeMigration extends BusinessMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Business nodes from CSV');
    $this->destination = new MigrateDestinationNode('business');

    // Basic mappings
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('field_website', 'Website');

    // Tax term references
    $this->addFieldMapping('field_business_type', 'Type');
    $this->addFieldMapping('field_business_type:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_business_type:create_term')
      ->defaultValue(TRUE);

  }
}

class BusinessNarrativeFcMigration extends BusinessMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Narrative FC from CSV');
    $this->destination = new MigrateDestinationFieldCollection(
      'field_narrative',
      array('host_entity_type' => 'node'));

    $this->addFieldMapping('host_entity_id', 'name')
      ->sourceMigration('BusinessNode');

    // Basic mappings
    $this->addFieldMapping('field_description', 'Description');

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

class BusinessHistoryFcMigration extends BusinessMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Business History FC from CSV');
    $this->destination = new MigrateDestinationFieldCollection(
      'field_business_history',
      array('host_entity_type' => 'node'));

    $this->addFieldMapping('host_entity_id', 'name')
      ->sourceMigration('BusinessNode');

    // Basic mappings
    $this->addFieldMapping('field_date_opened', 'Date opened');
    $this->addFieldMapping('field_date_closed', 'Date closed');

    // Address mappings
    $this->addFieldMapping('field_address', 'Address (Country)');
    $this->addFieldMapping('field_address:locality', 'Town/City');
    $this->addFieldMapping('field_address:thoroughfare', 'Address 1');
    $this->addFieldMapping('field_address:premise', 'Address 2');
    $this->addFieldMapping('field_address:administrative_area', 'County');
    $this->addFieldMapping('field_address:postal_code', 'Postal code');

    // Partial date
    $this->addFieldMapping('field_approximate_date')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_approximate_date:year', 'Approximate date opened year');
    $this->addFieldMapping('field_approximate_date:year_to', 'Approximate date closed year');

  }

  public function prepareRow($row) {

    // Skip manually entered rows
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }

    parent::prepareRow($row);

    // Convert the non-approximate dates into ISO format.
    if (!empty($row->{'Date opened'})) {
      $row->{'Date opened'} .= '-01-01T00:00:00';
    }
    if (!empty($row->{'Date closed'})) {
      $row->{'Date closed'} .= '-01-01T00:00:00';
    }

  }

}


class BusinessImagesFcMigration extends BusinessMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->MAPPImageMigration();

    $this->addFieldMapping('host_entity_id', 'name')
      ->sourceMigration('BusinessNode');
    $this->addFieldMapping('field_image:destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://images/business');
  }
}


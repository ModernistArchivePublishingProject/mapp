<?php

abstract class RelatedMaterialsMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->path .= '/related_materials.csv'; // Append CSV filename to path set in MAPPMigration
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

class RelatedMaterialsNodeMigration extends RelatedMaterialsMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate Related Materials nodes from CSV');
    $this->destination = new MigrateDestinationNode('related_materials');

    // Basic mappings
    $this->addFieldMapping('field_description', 'Description');
    $this->addFieldMapping('field_copyright_date', 'Copyright Date');

    // Partial date
    $this->addFieldMapping('field_rm_date_created')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_rm_date_created:year', 'Date created');
    $this->addFieldMapping('field_rm_date_created:year_to', 'Leave blank');

    // Tax term references
    $this->addFieldMapping('field_genre', 'Type');
    $this->addFieldMapping('field_genre:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_genre:create_term')
      ->defaultValue(TRUE);

    // Entity references
    $this->entity_reference_fields = array (
      'Library' => 'field_library',
      'Related to' => 'field_material_related_to',
    );
    $this->addFieldMapping('field_library', 'Library'); // TODO: Add library (if created) migration
    $this->addFieldMapping('field_material_related_to', 'Related to')
      ->separator('|')
      ->sourceMigration(array('PersonNode', 'CorrespondenceNode', 'RelatedMaterialsNode', 'WorkNode', 'BusinessNode', 'EditionNode', 'PrimaryObjectNode')); // TODO: Add library (if created) migration
  }


  public function prepareRow($row) {

    // Skip manually entered rows
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }

    parent::prepareRow($row);

    // Split Date created into to and from if range is provided
    if (!empty($row->{'Date created'})) {
      $date_parts = explode ('-', $row->{'Date created'});
      if (count ($date_parts)) {
        $row->{'Date created'} = $date_parts[0];
        $row->{'Leave blank'} = $date_parts[1];
      }
    }

  }

  public function prepare($entity, $row) {

    $this->MAPP_populate_entity_refs($entity, $row);

  }

}

class RelatedMaterialsImagesFcMigration extends RelatedMaterialsMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->MAPPImageMigration();

    $this->addFieldMapping('host_entity_id', 'csvrownum')
      ->sourceMigration('RelatedMaterialsNode');
    $this->addFieldMapping('field_image:destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://images/related_materials');
  }
}

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
    $this->addFieldMapping('title', 'Original Name');
    $this->addFieldMapping('field_name_authority:url', 'Identifiers');
    $this->addFieldMapping('field_birth_date:year', 'Birth Date');
    $this->addFieldMapping('field_death_date:year', 'Death Date');

    $this->addFieldMapping('field_birth_place', 'Birth Nation');
    $this->addFieldMapping('field_birth_place:locality', 'Birth City');
    $this->addFieldMapping('field_death_place', 'Death Nation');
    $this->addFieldMapping('field_death_place:locality', 'Death City');

    // Avoid warnings about unused fields
    $this->addFieldMapping(NULL, 'Birth Address');
    $this->addFieldMapping(NULL, 'Death Address');
// Birth Address       Birth Address
// Death Address       Death Address
// Image(s)            Image(s)
// Relationships       Relationships
// Bibliographic Item  Bibliographic Item

  }
}

//class PersonTermMigration extends MAPPMigration {
//  public function __construct($arguments) {
//    parent::__construct($arguments);
//    $this->columns = array(
//      'Occupation',
//      'Gender'
//    );
//    $this->description = t('Migrate Person terms from CSV');
//    $this->path .= '/person.csv'; // Append CSV filename to path set in MAPPMigration
//    $this->source = new MigrateSourceCSV($this->path, $this->columns, array('header_rows' => 1));
//    $this->destination = new MigrateDestinationTerm('field_gender');
////    field_occupation
//    $this->map = new MigrateSQLMap($this->machineName,
//      array(
//        'csvrownum' => array(
//          'type' => 'int',
//          'unsigned' => TRUE,
//          'not null' => TRUE,
//        )
//      ),
//      MigrateDestinationNode::getKeySchema()
//    );
//    // Occupation          Occupation
//    // Gender              Gender
//  }
//}


///*
// * Migrate the Biography field into the correct field collection
// */
//class PersonBiographyMigration extends MAPPMigration {
//  public function __construct($arguments) {
//    parent::__construct($arguments);
//    $this->columns = array('Biography');
//    $this->description = t('Migrate Person biography from CSV');
//    $this->path .= '/person.csv'; // Append CSV filename to path set in MAPPMigration
//    $this->source = new MigrateSourceCSV($this->path, $this->columns, array('header_rows' => 1));
//    $this->destination = new MigrateDestinationFieldCollection(
//      'field_coll_biography',
//      array('host_entity_type' => 'node'));
//    $this->map = new MigrateSQLMap($this->machineName,
//      array(
//        'csvrownum' => array(
//          'type' => 'int',
//          'unsigned' => TRUE,
//          'not null' => TRUE,
//        )
//      ),
//      MigrateDestinationNode::getKeySchema()
//    );
//    //    Biography           Biography
//    $this->addFieldMapping('host_entity_id', 'person')->sourceMigration('PersonNode');
//    $this->addFieldMapping('field_biography', 'Biography');
//  }
//}

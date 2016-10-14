<?php
class BusinessTermMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate Business terms from CSV');
//    $this->source = new MigrateSourceCSV($this->path, $this->csvcolumns(), array('header_rows' => 1));
    $this->source = new MigrateSourceCSV($this->path);
    $this->destination =
      new MigrateDestinationNode('business');
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
  }
}

class BusinessNodeMigration extends MAPPMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate Business nodes from CSV');
//    $this->source = new MigrateSourceCSV($this->path, $this->csvcolumns(), array('header_rows' => 1));
    $this->source = new MigrateSourceCSV($this->path);
    $this->destination =
      new MigrateDestinationNode('business');
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
  }
}
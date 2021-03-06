<?php

abstract class MAPPMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->path = drupal_get_path('module', 'mapp_data_import') . '/data_sources';

    $this->csv_options = array(
      'header_rows' => TRUE,
      'embedded_newlines' => TRUE,
    );

  }

  public function prepareRow($row) {

    // Skip manually entered rows
    // If the child class has its own prepareRow, it needs to do this on its own, even though it calls this code.
    if (!empty($row->{"Manually Entered?"})) {
      return FALSE;
    }

    // Trim all values
    foreach($row as $row_prop_name => $row_prop) {
      $row_prop2 = trim($row_prop);
      if ($row_prop <> $row_prop2) {
        $row->{$row_prop_name} = $row_prop2;
      }
    }
  }

  public function prepare($entity, $row) {

    $this->MAPP_populate_entity_refs($entity, $row);

  }

  public function MAPPImageMigration() {

    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_images',
      array('host_entity_type' => 'node'));

    // Image file mapping
    $this->addFieldMapping('field_image', 'Image')
      ->separator('|');
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'mapp_data_import') . '/images');
    $this->addFieldMapping('field_image:file_replace')
      ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    // Basic mappings
    $this->addFieldMapping('field_caption', 'Image Caption');
    $this->addFieldMapping('field_source', 'Image Source');

    // Entity references
    $this->entity_reference_fields = array (
      'Rights Holder' => 'field_rights_holder',
    );
    $this->addFieldMapping('field_rights_holder', 'Rights Holder')
      ->separator('|')
      ->sourceMigration(array('PersonNode', 'BusinessNode')); // TODO: Add library (if created) migration

  }

  // Populate entity reference fields in cases where the referenced content
  // was entered manually (ie. does not get populated by sourceMigration)
  public function MAPP_populate_entity_refs($entity, $row) {
    if (empty ($this->entity_reference_fields)) {
      return;
    }
    foreach ($this->entity_reference_fields as $source_field => $target_field) {
      if (!empty ($row->{$source_field}) && empty($entity->{$target_field}[LANGUAGE_NONE])) {
        $target_types = field_info_field($target_field);
        $target_types = $target_types['settings']['handler_settings']['target_bundles'];
        //print "target types for $target_field: " . print_r ($target_types);

        $source_values = explode('|', $row->{$source_field});
        foreach ($source_values as $source_value_index => $source_value) {
          $query = new EntityFieldQuery();

          $match_count = 0;
          // If numeric, assume this is an NID, not a node title
          if (is_numeric($source_value)) {
            $match_count = 1;
            // Just give the switches the data structure they already expect
            $target_entities['node'] = array($source_value => $source_value);
          } else {
            $target_entities = $query->entityCondition('entity_type', 'node')
              ->propertyCondition('type', $target_types)
              ->propertyCondition('title', $source_value)
              ->propertyCondition('status', 1)
              ->execute();
          }

          if (isset($target_entities['node'])) {
            $match_count = count($target_entities['node']);
          }
          switch ($match_count) {
            case 0:
              $this->queueMessage('No match for ' . $source_field . ': ' . $source_value . '.', 2);
              break;
            case 1:
              //print "\n1 match for $source_field: " . $row->{$source_field};
              $entity->{$target_field}[LANGUAGE_NONE][$source_value_index]['target_id'] = key($target_entities['node']);
              break;
            default:
              $this->queueMessage('There are ' . $match_count . ' matches for ' . $source_field . ': ' . $source_value . '. NIDS: ' . implode(', ', array_keys($target_entities['node'])) . '. Using the first one.', 2);
              $entity->{$target_field}[LANGUAGE_NONE][$source_value_index]['target_id'] = key($target_entities['node']);
              break;
          }
        }
      }
    }
  }

}

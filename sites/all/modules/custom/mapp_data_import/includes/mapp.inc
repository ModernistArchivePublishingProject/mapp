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

    // For entity references to CSV row numbers, substract one from the row number since the migration does not count the header row.
    if (isset ($this->entity_reference_fields)) {
      foreach ($this->entity_reference_fields as $source_field => $target_field) {
        if (is_numeric ($row->{$source_field})) {
          $row->{$source_field}-=1;
        }
      }
    }

  }

  public function MAPPImageMigration() {

    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_images',
      array('host_entity_type' => 'node'));

    // Image file mapping
    $this->addFieldMapping('field_image', 'Image');
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'mapp_data_import') . '/images');
    $this->addFieldMapping('field_image:file_replace')
      ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    // Basic mappings
    $this->addFieldMapping('field_caption', 'Image Caption');
    $this->addFieldMapping('field_source', 'Image Source');

    // Entity references
    $this->addFieldMapping('field_rights_holder', 'Rights Holder')
      ->separator('|')
      ->sourceMigration(array('PersonNode')); // TODO: add business & library (if created) migrations

  }

  // Populate entity reference fields in cases where the referenced content
  // was entered manually (ie. does not get populated by sourceMigration)
  public function MAPP_populate_entity_refs($entity, $row) {
    foreach ($this->entity_reference_fields as $source_field => $target_field) {
      if (!empty ($row->{$source_field}) && empty($entity->{$target_field})) {
        $target_types = field_info_field($target_field)['settings']['handler_settings']['target_bundles'];
        //print "target types for $target_field: " . print_r ($target_types);
        $query = new EntityFieldQuery();
        $target_entities = $query->entityCondition('entity_type', 'node')
          ->propertyCondition('type', $target_types)
          ->propertyCondition('title', $row->{$source_field})
          ->propertyCondition('status', 1)
          ->execute();
        $match_count = 0;
        if (isset($target_entities['node'])) {
          $match_count = count($target_entities['node']);
        }
        switch ($match_count) {
          case 0:
            $this->queueMessage('No match for ' . $source_field . ': ' . $row->{$source_field}, 2);
            break;
          case 1:
            //print "\n1 match for $source_field: " . $row->{$source_field};
            $entity->{$target_field}[LANGUAGE_NONE][0]['target_id'] = key($target_entities['node']);
            break;
          default:
            $this->queueMessage('There are ' . $match_count. ' matches for $source_field: ' . $row->{$source_field} . '. NIDS: ' . implode(', ', array_keys($target_entities['node'])) . '. Using the first one.', 2);
            $entity->{$target_field}[LANGUAGE_NONE][0]['target_id'] = key($target_entities['node']);
            break;
        }
      }
    }
  }

}

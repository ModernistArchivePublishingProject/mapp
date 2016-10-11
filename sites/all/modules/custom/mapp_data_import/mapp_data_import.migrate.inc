<?php
/**
 * Implements hook_migrate_api().
 */
function mapp_data_import_migrate_api() {
  module_load_include('inc', 'mapp_data_import', 'includes/person');
//  module_load_include('inc', 'mapp_data_import', 'includes/business');
//  module_load_include('inc', 'mapp_data_import', 'includes/library');
//  module_load_include('inc', 'mapp_data_import', 'includes/work');
//  module_load_include('inc', 'mapp_data_import', 'includes/edition');
//  module_load_include('inc', 'mapp_data_import', 'includes/primary_object');
//  module_load_include('inc', 'mapp_data_import', 'includes/related_materials');
//  module_load_include('inc', 'mapp_data_import', 'includes/correspondence');

  // Migrations class and dependencies
  $migrations = array(

    'Images' => array(
      'class_name' => 'ImagesMigration',
      'group_name' => 'mapp',
    ),

    'PersonNode' => array(
      'class_name' => 'PersonNodeMigration',
      'group_name' => 'mapp',
    ),
    'PersonBiographyFc' => array(
      'class_name' => 'PersonBiographyFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('PersonNode')
    ),
    'PersonImagesFc' => array(
      'class_name' => 'PersonImagesFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('PersonNode', 'Images')
    ),

    'WorkNode' => array(
      'class_name' => 'WorkNodeMigration',
      'group_name' => 'mapp',
    ),
    'WorkImagesFc' => array(
      'class_name' => 'WorkImagesFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('WorkNode', 'Images')
    ),

  );

  // API and groups information
  $api = array(
    'api' => 2,
    'groups' => array(
      'mapp' => array(
        'title' => t('MAPP'),
      ),
    ),
    'migrations' => $migrations,
  );
  return $api;
}

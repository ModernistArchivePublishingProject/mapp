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
      'dependencies' => array('PersonNode')
    ),

    'WorkNode' => array(
      'class_name' => 'WorkNodeMigration',
      'group_name' => 'mapp',
    ),
    'WorkImagesFc' => array(
      'class_name' => 'WorkImagesFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('WorkNode')
    ),

    'CorrespondenceNode' => array(
      'class_name' => 'CorrespondenceNodeMigration',
      'group_name' => 'mapp',
    ),
    'CorrespondenceImagesFc' => array(
      'class_name' => 'CorrespondenceImagesFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('CorrespondenceNode')
    ),

    'RelatedMaterialsNode' => array(
      'class_name' => 'RelatedMaterialsNodeMigration',
      'group_name' => 'mapp',
    ),
    'RelatedMaterialsImagesFc' => array(
      'class_name' => 'RelatedMaterialsImagesFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('RelatedMaterialsNode')
    ),

    'BusinessNode' => array(
      'class_name' => 'BusinessNodeMigration',
      'group_name' => 'mapp',
    ),
    'BusinessNarrativeFc' => array(
      'class_name' => 'BusinessNarrativeFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('BusinessNode')
    ),
    'BusinessHistoryFc' => array(
      'class_name' => 'BusinessHistoryFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('BusinessNode')
    ),
    'BusinessImagesFc' => array(
      'class_name' => 'BusinessImagesFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('BusinessNode')
    ),

    'EditionNode' => array(
      'class_name' => 'EditionNodeMigration',
      'group_name' => 'mapp',
    ),
    'EditionPurchaserFc' => array(
      'class_name' => 'EditionPurchaserFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('EditionNode')
    ),
    'EditionImagesFc' => array(
      'class_name' => 'EditionImagesFcMigration',
      'group_name' => 'mapp',
      'dependencies' => array('EditionNode')
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

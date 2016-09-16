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
      //'dependencies' => array('PersonTerm')
    ),
//    'PersonBiography' => array(
//      'class_name' => 'PersonBiographyMigration',
//      'group_name' => 'people',
//      'dependencies' => array('PersonNode')
//    ),
//    'PersonTerm' => array(
//      'class_name' => 'PersonTermMigration',
//      'group_name' => 'people'
//    ),
//    'BusinessTerm' => array(
//      'class_name' => 'BusinessTermMigration',
//      'group_name' => 'organizations',
//    ),
//    'BusinessNode' => array(
//      'class_name' => 'BusinessNodeMigration',
//      'group_name' => 'organizations',
//      'dependencies' => array('BusinessTerm')
//    ),
//    'LibraryNode' => array(
//      'class_name' => 'LibraryNodeMigration',
//      'group_name' => 'organizations',
//    ),
//    'WorkTerm' => array(
//      'class_name' => 'WorkTermMigration',
//      'group_name' => 'works',
//    ),
//    'WorkNode' => array(
//      'class_name' => 'WorkNodeMigration',
//      'group_name' => 'works',
//      'dependencies' => array('WorkTerm')
//    ),
//    'EditionTerm' => array(
//      'class_name' => 'EditionTermMigration',
//      'group_name' => 'editions',
//    ),
//    'EditionNode' => array(
//      'class_name' => 'EditionNodeMigration',
//      'group_name' => 'editions',
//      'dependencies' => array('EditionTerm')
//    ),
//    'PrimaryObjectTerm' => array(
//      'class_name' => 'PrimaryObjectTermMigration',
//      'group_name' => 'primary_objects',
//    ),
//    'PrimaryObjectNode' => array(
//      'class_name' => 'PrimaryObjectNodeMigration',
//      'group_name' => 'primary_objects',
//      'dependencies' => array('PrimaryObjectTerm')
//    ),
//    'RelatedMaterialsTerm' => array(
//      'class_name' => 'RelatedMaterialsTermMigration',
//      'group_name' => 'related',
//    ),
//    'RelatedMaterialsNode' => array(
//      'class_name' => 'RelatedMaterialsNodeMigration',
//      'group_name' => 'related',
//      'dependencies' => array('RelatedMaterialsTerm')
//    ),
//    'CorrespondenceTerm' => array(
//      'class_name' => 'CorrespondenceTermMigration',
//      'group_name' => 'related',
//    ),
//    'CorrespondenceNode' => array(
//      'class_name' => 'CorrespondenceNodeMigration',
//      'group_name' => 'related',
//      'dependencies' => array('CorrespondenceTerm')
//    ),
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

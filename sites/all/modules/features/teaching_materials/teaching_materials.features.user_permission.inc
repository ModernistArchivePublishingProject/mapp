<?php
/**
 * @file
 * teaching_materials.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function teaching_materials_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create teaching_materials content'.
  $permissions['create teaching_materials content'] = array(
    'name' => 'create teaching_materials content',
    'roles' => array(
      'Affiliate Member' => 'Affiliate Member',
      'Research Fellow' => 'Research Fellow',
      'Team Member' => 'Team Member',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any teaching_materials content'.
  $permissions['delete any teaching_materials content'] = array(
    'name' => 'delete any teaching_materials content',
    'roles' => array(
      'Team Member' => 'Team Member',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own teaching_materials content'.
  $permissions['delete own teaching_materials content'] = array(
    'name' => 'delete own teaching_materials content',
    'roles' => array(
      'Affiliate Member' => 'Affiliate Member',
      'Research Fellow' => 'Research Fellow',
      'Team Member' => 'Team Member',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any teaching_materials content'.
  $permissions['edit any teaching_materials content'] = array(
    'name' => 'edit any teaching_materials content',
    'roles' => array(
      'Team Member' => 'Team Member',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own teaching_materials content'.
  $permissions['edit own teaching_materials content'] = array(
    'name' => 'edit own teaching_materials content',
    'roles' => array(
      'Affiliate Member' => 'Affiliate Member',
      'Research Fellow' => 'Research Fellow',
      'Team Member' => 'Team Member',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}

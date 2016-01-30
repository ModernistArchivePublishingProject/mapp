<?php
/**
 * @file
 * mapp_workbench.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mapp_workbench_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'Student Member' => 'Student Member',
      'Team Member' => 'Team Member',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  return $permissions;
}

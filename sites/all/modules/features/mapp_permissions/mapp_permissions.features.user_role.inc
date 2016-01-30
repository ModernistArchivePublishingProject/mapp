<?php
/**
 * @file
 * mapp_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mapp_permissions_user_default_roles() {
  $roles = array();

  // Exported role: Student Member.
  $roles['Student Member'] = array(
    'name' => 'Student Member',
    'weight' => 4,
  );

  // Exported role: Team Member.
  $roles['Team Member'] = array(
    'name' => 'Team Member',
    'weight' => 3,
  );

  return $roles;
}

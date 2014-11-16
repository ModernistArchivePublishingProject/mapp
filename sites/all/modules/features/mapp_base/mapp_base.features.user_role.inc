<?php
/**
 * @file
 * mapp_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mapp_base_user_default_roles() {
  $roles = array();

  // Exported role: Team Member.
  $roles['Team Member'] = array(
    'name' => 'Team Member',
    'weight' => 3,
  );

  return $roles;
}

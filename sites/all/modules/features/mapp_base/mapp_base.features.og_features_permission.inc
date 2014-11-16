<?php
/**
 * @file
 * mapp_base.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function mapp_base_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:press:add user'
  $permissions['node:press:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:administer group'
  $permissions['node:press:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:approve and deny subscription'
  $permissions['node:press:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:manage members'
  $permissions['node:press:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:manage permissions'
  $permissions['node:press:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:manage roles'
  $permissions['node:press:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:subscribe'
  $permissions['node:press:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:press:subscribe without approval'
  $permissions['node:press:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:press:unsubscribe'
  $permissions['node:press:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:press:update body field'
  $permissions['node:press:update body field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:update field_bio field'
  $permissions['node:press:update field_bio field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:update field_display_name field'
  $permissions['node:press:update field_display_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:update field_image field'
  $permissions['node:press:update field_image field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:update field_link field'
  $permissions['node:press:update field_link field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:update field_url field'
  $permissions['node:press:update field_url field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:update group'
  $permissions['node:press:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:update group_group field'
  $permissions['node:press:update group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:update og_user_node field'
  $permissions['node:press:update og_user_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:press:view body field'
  $permissions['node:press:view body field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:press:view field_bio field'
  $permissions['node:press:view field_bio field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:press:view field_display_name field'
  $permissions['node:press:view field_display_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:press:view field_image field'
  $permissions['node:press:view field_image field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:press:view field_link field'
  $permissions['node:press:view field_link field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:press:view field_url field'
  $permissions['node:press:view field_url field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:press:view group_group field'
  $permissions['node:press:view group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:press:view og_user_node field'
  $permissions['node:press:view og_user_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}

<?php
/**
 * @file
 * mapp_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function mapp_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_presses:presses
  $menu_links['main-menu_presses:presses'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'presses',
    'router_path' => 'presses',
    'link_title' => 'Presses',
    'options' => array(
      'identifier' => 'main-menu_presses:presses',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 0,
  );
  // Exported menu link: main-menu_team:team
  $menu_links['main-menu_team:team'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'team',
    'router_path' => 'team',
    'link_title' => 'Team',
    'options' => array(
      'identifier' => 'main-menu_team:team',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Presses');
  t('Team');


  return $menu_links;
}

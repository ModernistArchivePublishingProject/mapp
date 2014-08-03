<?php
/**
 * @file
 * mapp_base.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function mapp_base_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about:node/1
  $menu_links['main-menu_about:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_about:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');


  return $menu_links;
}

<?php
/**
 * @file
 * teaching_materials.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function teaching_materials_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_teaching-materials:teaching-materials.
  $menu_links['main-menu_teaching-materials:teaching-materials'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'teaching-materials',
    'router_path' => 'teaching-materials',
    'link_title' => 'Teaching Materials',
    'options' => array(
      'identifier' => 'main-menu_teaching-materials:teaching-materials',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Teaching Materials');

  return $menu_links;
}

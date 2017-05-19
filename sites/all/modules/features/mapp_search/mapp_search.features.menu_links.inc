<?php
/**
 * @file
 * mapp_search.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function mapp_search_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_search:search.
  $menu_links['main-menu_search:search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_search:search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');

  return $menu_links;
}

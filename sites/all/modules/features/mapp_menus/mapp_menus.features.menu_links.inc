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

  // Exported menu link: main-menu_about:node/1.
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
  // Exported menu link: main-menu_blog:blog.
  $menu_links['main-menu_blog:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_blog:blog',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: main-menu_browse:node/4682.
  $menu_links['main-menu_browse:node/4682'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4682',
    'router_path' => 'node/%',
    'link_title' => 'Browse',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_browse:node/4682',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_contact:contact.
  $menu_links['main-menu_contact:contact'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contact:contact',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
  );
  // Exported menu link: main-menu_presses:presses.
  $menu_links['main-menu_presses:presses'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'presses',
    'router_path' => 'presses',
    'link_title' => 'Presses',
    'options' => array(
      'identifier' => 'main-menu_presses:presses',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: main-menu_team:node/7489.
  $menu_links['main-menu_team:node/7489'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7489',
    'router_path' => 'node/%',
    'link_title' => 'Team',
    'options' => array(
      'identifier' => 'main-menu_team:node/7489',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Blog');
  t('Browse');
  t('Contact');
  t('Presses');
  t('Team');

  return $menu_links;
}

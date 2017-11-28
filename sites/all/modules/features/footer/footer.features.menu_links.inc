<?php
/**
 * @file
 * footer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function footer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_bibliography:biblio.
  $menu_links['menu-footer-menu_bibliography:biblio'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'biblio',
    'router_path' => 'biblio',
    'link_title' => 'Bibliography',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_bibliography:biblio',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-menu_funders--partners:node/205.
  $menu_links['menu-footer-menu_funders--partners:node/205'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/205',
    'router_path' => 'node/%',
    'link_title' => 'Funders & Partners',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_funders--partners:node/205',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-menu_login:user/login.
  $menu_links['menu-footer-menu_login:user/login'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_login:user/login',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-menu_publications--presentations:node/7488.
  $menu_links['menu-footer-menu_publications--presentations:node/7488'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/7488',
    'router_path' => 'node/%',
    'link_title' => 'Publications & Presentations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_publications--presentations:node/7488',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-menu_terms--conditions:node/197.
  $menu_links['menu-footer-menu_terms--conditions:node/197'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/197',
    'router_path' => 'node/%',
    'link_title' => 'Terms & Conditions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_terms--conditions:node/197',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bibliography');
  t('Funders & Partners');
  t('Login');
  t('Publications & Presentations');
  t('Terms & Conditions');

  return $menu_links;
}

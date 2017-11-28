<?php
/**
 * @file
 * student_projects.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function student_projects_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_student-projects:student-projects.
  $menu_links['main-menu_student-projects:student-projects'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'student-projects',
    'router_path' => 'student-projects',
    'link_title' => 'Student Projects',
    'options' => array(
      'identifier' => 'main-menu_student-projects:student-projects',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Student Projects');

  return $menu_links;
}

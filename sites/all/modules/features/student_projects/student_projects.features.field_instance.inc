<?php
/**
 * @file
 * student_projects.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function student_projects_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-blog-field_post_type'.
  $field_instances['node-blog-field_post_type'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_post_type',
    'label' => 'Post Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Post Type');

  return $field_instances;
}

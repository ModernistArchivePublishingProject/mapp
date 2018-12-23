<?php

/**
 * @file
 * teaching_materials.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function teaching_materials_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function teaching_materials_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function teaching_materials_node_info() {
  $items = array(
    'teaching_materials' => array(
      'name' => t('Teaching Materials'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

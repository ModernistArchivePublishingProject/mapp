<?php
/**
 * @file
 * mapp_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mapp_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mapp_base_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function mapp_base_image_default_styles() {
  $styles = array();

  // Exported image style: square_icons.
  $styles['square_icons'] = array(
    'name' => 'square_icons',
    'label' => 'Square Icons',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
          'height' => 200,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function mapp_base_node_info() {
  $items = array(
    'bp_book' => array(
      'name' => t('Book'),
      'base' => 'node_content',
      'description' => t('The metadata and files for a single book. Not to be confused with Drupal\'s core book structure. Used by Bibliopedia.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'partner' => array(
      'name' => t('Partner'),
      'base' => 'node_content',
      'description' => t('Add information about partners, funders, and other supporters of the project. For display in the footers.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'press' => array(
      'name' => t('Press'),
      'base' => 'node_content',
      'description' => t('Information about a press. Used to group together works, books, other materials.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

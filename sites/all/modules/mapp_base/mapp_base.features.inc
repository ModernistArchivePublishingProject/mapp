<?php
/**
 * @file
 * mapp_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mapp_base_ctools_plugin_api($module = NULL, $api = NULL) {
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
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
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
  );
  drupal_alter('node_info', $items);
  return $items;
}

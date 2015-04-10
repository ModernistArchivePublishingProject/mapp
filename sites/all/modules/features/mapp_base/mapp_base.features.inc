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
 * Implements hook_image_default_styles().
 */
function mapp_base_image_default_styles() {
  $styles = array();

  // Exported image style: square_icons.
  $styles['square_icons'] = array(
    'label' => 'Square Icons',
    'effects' => array(
      2 => array(
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

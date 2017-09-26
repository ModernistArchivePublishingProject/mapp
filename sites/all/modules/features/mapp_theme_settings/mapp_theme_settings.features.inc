<?php
/**
 * @file
 * mapp_theme_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mapp_theme_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

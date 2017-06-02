<?php
/**
 * @file
 * content_path_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_path_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

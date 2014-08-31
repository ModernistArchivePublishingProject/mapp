<?php
/**
 * @file
 * mapp_base.box.inc
 */

/**
 * Implements hook_default_box().
 */
function mapp_base_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'enter_site_button';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Enter Site Button';
  $box->options = array(
    'body' => array(
      'value' => '<p><a id="enter" class="mapp-button" href="presses">ENTER</a></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['enter_site_button'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'presses_banner';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Banner image for Presses view';
  $box->options = array(
    'body' => array(
      'value' => '<p><img id="presses-banner" src="http://192.168.44.44/mapp/sites/default/files/publisherquilt.jpeg" alt="" width="669" height="240" /></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['presses_banner'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'splash_image';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Front page splash image';
  $box->options = array(
    'body' => array(
      'value' => '<p><img src="http://192.168.44.44/mapp/sites/default/files/printing_press_albion.JPG" alt="Albion printing press" width="1244" height="530" /></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['splash_image'] = $box;

  return $export;
}

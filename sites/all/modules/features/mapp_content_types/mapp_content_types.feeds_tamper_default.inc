<?php

/**
 * @file
 * mapp_content_types.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function mapp_content_types_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'person-identifiers-explode';
  $feeds_tamper->importer = 'person';
  $feeds_tamper->source = 'Identifiers';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['person-identifiers-explode'] = $feeds_tamper;

  return $export;
}

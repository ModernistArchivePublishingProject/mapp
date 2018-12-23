<?php

/**
 * @file
 * mapp_views.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mapp_views_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_business_pattern';
  $strongarm->value = 'business/[node:title]';
  $export['pathauto_node_business_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_person_pattern';
  $strongarm->value = 'person/[node:title]';
  $export['pathauto_node_person_pattern'] = $strongarm;

  return $export;
}

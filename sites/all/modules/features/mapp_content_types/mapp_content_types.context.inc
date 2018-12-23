<?php

/**
 * @file
 * mapp_content_types.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function mapp_content_types_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'works_authored';
  $context->description = 'Show works authored on Person page';
  $context->tag = 'Person';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'person' => 'person',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-works_authored-block' => array(
          'module' => 'views',
          'delta' => 'works_authored-block',
          'region' => 'content_supplemental',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Person');
  t('Show works authored on Person page');
  $export['works_authored'] = $context;

  return $export;
}

<?php

/**
 * @file
 * mapp_front_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function mapp_front_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = '';
  $context->tag = 'Front';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'views-front_page_content_feed-block' => array(
          'module' => 'views',
          'delta' => 'front_page_content_feed-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-latest_biographies-block' => array(
          'module' => 'views',
          'delta' => 'latest_biographies-block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front');
  $export['front_page'] = $context;

  return $export;
}

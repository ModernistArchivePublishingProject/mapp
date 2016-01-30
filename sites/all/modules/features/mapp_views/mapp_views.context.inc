<?php
/**
 * @file
 * mapp_views.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function mapp_views_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bibliography';
  $context->description = 'Bibliographic Item references';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'business' => 'business',
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
        'views-bibliography-block' => array(
          'module' => 'views',
          'delta' => 'bibliography-block',
          'region' => 'content_supplemental',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Bibliographic Item references');
  $export['bibliography'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'press_editions';
  $context->description = 'Show editions related to a press';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'business' => 'business',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        7 => 7,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-press_related_objects-block' => array(
          'module' => 'views',
          'delta' => 'press_related_objects-block',
          'region' => 'content_supplemental',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show editions related to a press');
  $export['press_editions'] = $context;

  return $export;
}

<?php
/**
 * @file
 * correspondence.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function correspondence_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'letters_received';
  $context->description = '';
  $context->tag = 'correspondence';
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
        'views-correspondence-block_1' => array(
          'module' => 'views',
          'delta' => 'correspondence-block_1',
          'region' => 'content_supplemental',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('correspondence');
  $export['letters_received'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'letters_related_to';
  $context->description = 'Letters related to Work';
  $context->tag = 'correspondence';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'work' => 'work',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-correspondence-block_2' => array(
          'module' => 'views',
          'delta' => 'correspondence-block_2',
          'region' => 'content_supplemental',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Letters related to Work');
  t('correspondence');
  $export['letters_related_to'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'letters_sent';
  $context->description = '';
  $context->tag = 'correspondence';
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
        'views-correspondence-block' => array(
          'module' => 'views',
          'delta' => 'correspondence-block',
          'region' => 'content_supplemental',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('correspondence');
  $export['letters_sent'] = $context;

  return $export;
}

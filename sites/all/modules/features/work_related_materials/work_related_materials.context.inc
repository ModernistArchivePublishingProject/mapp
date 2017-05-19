<?php
/**
 * @file
 * work_related_materials.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function work_related_materials_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'work_related_materials';
  $context->description = 'Materials related to a work';
  $context->tag = 'Work';
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
        'views-related_materials-block' => array(
          'module' => 'views',
          'delta' => 'related_materials-block',
          'region' => 'content_supplemental',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Materials related to a work');
  t('Work');
  $export['work_related_materials'] = $context;

  return $export;
}

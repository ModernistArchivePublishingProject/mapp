<?php
/**
 * @file
 * mapp_content_types.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mapp_content_types_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'person';
  $feeds_importer->config = array(
    'name' => 'Person',
    'description' => 'Import people metadata',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Birth Nation',
            'target' => 'field_birth_place:country',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Birth City',
            'target' => 'field_birth_place:locality',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Birth Address',
            'target' => 'field_birth_place:dependent_locality',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Identifiers',
            'target' => 'url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'person',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['person'] = $feeds_importer;

  return $export;
}

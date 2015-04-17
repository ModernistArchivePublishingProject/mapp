<?php
/**
 * @file
 * mapp_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mapp_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mapp_content_types_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mapp_content_types_node_info() {
  $items = array(
    'business' => array(
      'name' => t('Business'),
      'base' => 'node_content',
      'description' => t('Metadata describing a business. Could be a publishing house, a printer, etc.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'correspondence' => array(
      'name' => t('Correspondence'),
      'base' => 'node_content',
      'description' => t('A letter'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'edition' => array(
      'name' => t('Edition'),
      'base' => 'node_content',
      'description' => t('"All of the copies of a book printed from the same setting of type, at one time or over a period of time, with no major changes, additions or revisions. Minor changes, such as the correction of some misspelled words, or the addition of a dedication, or similar very minor alterations, may be made and the revised copies are still considered as part of the same edition, simply being described as different states or issues. Second or subsequent editions usually involve the entire resetting of type." (IOBA definition)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'library' => array(
      'name' => t('Library'),
      'base' => 'node_content',
      'description' => t('A library that holds one or more books in the database.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'partner' => array(
      'name' => t('Partner'),
      'base' => 'node_content',
      'description' => t('Partners, funders, and other supporters of the project. For display in the footers.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('Details about a person.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'primary_object' => array(
      'name' => t('Primary Object'),
      'base' => 'node_content',
      'description' => t('Metadata to describe the material expression of an edition.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'related_materials' => array(
      'name' => t('Related Materials'),
      'base' => 'node_content',
      'description' => t('Materials related to the production process or reception of a work.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'work' => array(
      'name' => t('Work'),
      'base' => 'node_content',
      'description' => t('A work is the abstract, generalizable metadata about a book, letter, or other item. It is not the material (printed) expression of the work. Includes metadata like call numbers, author, editor, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

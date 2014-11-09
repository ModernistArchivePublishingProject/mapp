<?php
/**
 * @file
 * content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_types_node_info() {
  $items = array(
    'association_copy' => array(
      'name' => t('Association Copy'),
      'base' => 'node_content',
      'description' => t('A book once belonging to the author, or signed or annotated by the author to someone closely associated with the author of the book or the book itself in some way. Also, a book inscribed by its author to a famous person, or owned by someone of interest.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'bp_book' => array(
      'name' => t('Book'),
      'base' => 'node_content',
      'description' => t('Metadata to describe a physical book, which is the material expression of a Work.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
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

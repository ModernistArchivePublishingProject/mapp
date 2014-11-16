<?php
/**
 * @file
 * mapp_base.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mapp_base_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_libraries|node|bp_book|form';
  $field_group->group_name = 'group_libraries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bp_book';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Libraries',
    'weight' => '5',
    'children' => array(
      0 => 'field_library',
      1 => 'field_link_digitized',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-libraries field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_libraries|node|bp_book|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication|node|bp_book|form';
  $field_group->group_name = 'group_publication';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bp_book';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publication Details',
    'weight' => '4',
    'children' => array(
      0 => 'field_publisher',
      1 => 'field_printer',
      2 => 'field_size',
      3 => 'field_publication_date',
      4 => 'field_price',
      5 => 'field_pages',
      6 => 'field_print_run',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publication field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_publication|node|bp_book|form'] = $field_group;

  return $export;
}

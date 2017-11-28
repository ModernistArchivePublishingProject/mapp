<?php
/**
 * @file
 * mapp_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mapp_content_types_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_material|node|edition|form';
  $field_group->group_name = 'group_material';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'edition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Material ',
    'weight' => '6',
    'children' => array(
      0 => 'field_edition',
      1 => 'field_pages',
      2 => 'field_print_run',
      3 => 'field_publication_date',
      4 => 'field_size',
      5 => 'field_price',
      6 => 'field_paper_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-material field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_material|node|edition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people|node|edition|form';
  $field_group->group_name = 'group_people';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'edition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'People',
    'weight' => '5',
    'children' => array(
      0 => 'field_illustrator',
      1 => 'field_printer',
      2 => 'field_publisher',
      3 => 'field_purchasers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-people field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_people|node|edition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resources|node|related_materials|form';
  $field_group->group_name = 'group_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'related_materials';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Resources',
    'weight' => '3',
    'children' => array(
      0 => 'field_library',
      1 => 'field_link_digitized',
      2 => 'field_identifier',
      3 => 'field_fc_images',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-resources field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_resources|node|related_materials|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Material ');
  t('People');
  t('Resources');

  return $field_groups;
}

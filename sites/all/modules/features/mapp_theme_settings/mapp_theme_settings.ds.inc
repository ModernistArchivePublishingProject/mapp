<?php
/**
 * @file
 * mapp_theme_settings.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function mapp_theme_settings_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_fc_images',
      ),
      'right' => array(
        1 => 'field_other_names',
        2 => 'field_gender',
        3 => 'field_occupation',
        4 => 'field_birth_date',
        5 => 'field_birth_place',
        6 => 'field_death_date',
        7 => 'field_death_place',
        8 => 'field_relationships',
        9 => 'field_business_relationship',
        10 => 'field_name_authority',
        11 => 'field_file_attachments',
      ),
      'footer' => array(
        12 => 'field_coll_biography',
      ),
    ),
    'fields' => array(
      'field_fc_images' => 'left',
      'field_other_names' => 'right',
      'field_gender' => 'right',
      'field_occupation' => 'right',
      'field_birth_date' => 'right',
      'field_birth_place' => 'right',
      'field_death_date' => 'right',
      'field_death_place' => 'right',
      'field_relationships' => 'right',
      'field_business_relationship' => 'right',
      'field_name_authority' => 'right',
      'field_file_attachments' => 'right',
      'field_coll_biography' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|person|default'] = $ds_layout;

  return $export;
}

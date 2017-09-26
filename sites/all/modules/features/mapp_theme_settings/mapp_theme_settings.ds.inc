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
        0 => 'field_other_names',
        1 => 'field_gender',
        2 => 'field_occupation',
        3 => 'field_birth_date',
        4 => 'field_birth_place',
        5 => 'field_death_date',
        6 => 'field_death_place',
        7 => 'field_relationships',
        8 => 'field_business_relationship',
        9 => 'field_name_authority',
        10 => 'field_file_attachments',
      ),
      'right' => array(
        11 => 'field_fc_images',
      ),
      'footer' => array(
        12 => 'field_coll_biography',
      ),
    ),
    'fields' => array(
      'field_other_names' => 'left',
      'field_gender' => 'left',
      'field_occupation' => 'left',
      'field_birth_date' => 'left',
      'field_birth_place' => 'left',
      'field_death_date' => 'left',
      'field_death_place' => 'left',
      'field_relationships' => 'left',
      'field_business_relationship' => 'left',
      'field_name_authority' => 'left',
      'field_file_attachments' => 'left',
      'field_fc_images' => 'right',
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

<?php
/**
 * @file
 * work_related_materials.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function work_related_materials_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'related_materials';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Materials';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Materials';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_material_related_to_target_id']['id'] = 'field_material_related_to_target_id';
  $handler->display->display_options['relationships']['field_material_related_to_target_id']['table'] = 'field_data_field_material_related_to';
  $handler->display->display_options['relationships']['field_material_related_to_target_id']['field'] = 'field_material_related_to_target_id';
  $handler->display->display_options['relationships']['field_material_related_to_target_id']['label'] = 'Work Related To';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['element_type'] = '0';
  $handler->display->display_options['fields']['field_author']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_author']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_author']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_author']['field_api_classes'] = TRUE;
  /* Field: Content: Genre */
  $handler->display->display_options['fields']['field_genre']['id'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['table'] = 'field_data_field_genre';
  $handler->display->display_options['fields']['field_genre']['field'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['element_type'] = '0';
  $handler->display->display_options['fields']['field_genre']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_genre']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_genre']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_genre']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_genre']['field_api_classes'] = TRUE;
  /* Field: Content: Date Created */
  $handler->display->display_options['fields']['field_rm_date_created']['id'] = 'field_rm_date_created';
  $handler->display->display_options['fields']['field_rm_date_created']['table'] = 'field_data_field_rm_date_created';
  $handler->display->display_options['fields']['field_rm_date_created']['field'] = 'field_rm_date_created';
  $handler->display->display_options['fields']['field_rm_date_created']['element_type'] = '0';
  $handler->display->display_options['fields']['field_rm_date_created']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_rm_date_created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rm_date_created']['click_sort_column'] = 'timestamp';
  $handler->display->display_options['fields']['field_rm_date_created']['settings'] = array(
    'use_override' => 'none',
    'format' => 'custom',
    'component_settings' => array(
      'meridiem' => 'a',
      'year_designation' => 'ce',
      'display' => array(
        'year' => 'estimate_label',
        'month' => 'none',
        'day' => 'none',
        'hour' => 'none',
        'minute' => 'none',
        'second' => 'none',
        'timezone' => 'none',
      ),
      'separator' => array(
        'date' => ' ',
        'time' => ':',
        'datetime' => ' ',
        'other' => ' ',
        'range' => '',
      ),
      'components' => array(
        'year' => array(
          'format' => 'Y-ce',
          'empty' => '',
          'weight' => '0',
        ),
        'month' => array(
          'format' => 'M',
          'empty' => '',
          'weight' => '1',
        ),
        'day' => array(
          'format' => 'j-S',
          'empty' => '',
          'weight' => '2',
        ),
        'hour' => array(
          'format' => 'h',
          'empty' => '',
          'weight' => '3',
        ),
        'minute' => array(
          'format' => 'i',
          'empty' => '',
          'weight' => '4',
        ),
        'second' => array(
          'format' => 's',
          'empty' => '',
          'weight' => '5',
        ),
        'timezone' => array(
          'format' => 'T',
          'empty' => '',
          'weight' => '6',
        ),
        'c1' => array(
          'value' => '',
          'weight' => '7',
        ),
        'c2' => array(
          'value' => '',
          'weight' => '8',
        ),
        'c3' => array(
          'value' => '',
          'weight' => '9',
        ),
        'approx' => array(
          'value' => '',
          'weight' => '-1',
        ),
      ),
    ),
  );
  $handler->display->display_options['fields']['field_rm_date_created']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_rm_date_created']['field_api_classes'] = TRUE;
  /* Field: Field: Library */
  $handler->display->display_options['fields']['field_library']['id'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['table'] = 'field_data_field_library';
  $handler->display->display_options['fields']['field_library']['field'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['label'] = 'Library Held By';
  $handler->display->display_options['fields']['field_library']['element_type'] = '0';
  $handler->display->display_options['fields']['field_library']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_library']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_library']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_library']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_library']['field_api_classes'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_material_related_to_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'related_materials' => 'related_materials',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['related_materials'] = $view;

  return $export;
}

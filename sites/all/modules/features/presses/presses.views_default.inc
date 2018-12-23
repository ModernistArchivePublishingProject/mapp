<?php

/**
 * @file
 * presses.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function presses_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'presses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Presses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Presses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Image(s) (field_fc_images) */
  $handler->display->display_options['relationships']['field_fc_images_value']['id'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['table'] = 'field_data_field_fc_images';
  $handler->display->display_options['relationships']['field_fc_images_value']['field'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['delta'] = '-1';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  /* Field: Global: Base url */
  $handler->display->display_options['fields']['base_url']['id'] = 'base_url';
  $handler->display->display_options['fields']['base_url']['table'] = 'views';
  $handler->display->display_options['fields']['base_url']['field'] = 'base_url';
  $handler->display->display_options['fields']['base_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['base_url']['show_link'] = 0;
  $handler->display->display_options['fields']['base_url']['show_link_options'] = array(
    'link_path' => '',
    'link_text' => '',
    'link_class' => '',
    'link_title' => '',
    'link_rel' => '',
    'link_fragment' => '',
    'link_query' => '',
    'link_target' => '',
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['empty'] = '<a href="[path]"><img src="[base_url]/sites/default/files/MAPP_Logo_Orange_Compact_small.jpeg" /></a>';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'square_icons',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_image']['separator'] = '';
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_image]
[title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Number of Related Items (field_number_of_related_items) */
  $handler->display->display_options['sorts']['field_number_of_related_items_count']['id'] = 'field_number_of_related_items_count';
  $handler->display->display_options['sorts']['field_number_of_related_items_count']['table'] = 'field_data_field_number_of_related_items';
  $handler->display->display_options['sorts']['field_number_of_related_items_count']['field'] = 'field_number_of_related_items_count';
  $handler->display->display_options['sorts']['field_number_of_related_items_count']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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
    'business' => 'business',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_business_type) */
  $handler->display->display_options['filters']['field_business_type_tid']['id'] = 'field_business_type_tid';
  $handler->display->display_options['filters']['field_business_type_tid']['table'] = 'field_data_field_business_type';
  $handler->display->display_options['filters']['field_business_type_tid']['field'] = 'field_business_type_tid';
  $handler->display->display_options['filters']['field_business_type_tid']['value'] = array(
    7 => '7',
  );
  $handler->display->display_options['filters']['field_business_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_business_type_tid']['vocabulary'] = 'business_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'presses';
  $handler->display->display_options['menu']['title'] = 'Presses';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['presses'] = $view;

  return $export;
}

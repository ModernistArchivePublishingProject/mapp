<?php
/**
 * @file
 * correspondence.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function correspondence_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'correspondence';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Correspondence';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Correspondence';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'view_node' => 'view_node',
    'field_author' => 'field_author',
    'field_recipient' => 'field_recipient',
    'field_publication_date' => 'field_publication_date',
    'title' => 'title',
    'field_correspondence_type' => 'field_correspondence_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_recipient' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_correspondence_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_author_target_id']['id'] = 'field_author_target_id';
  $handler->display->display_options['relationships']['field_author_target_id']['table'] = 'field_data_field_author';
  $handler->display->display_options['relationships']['field_author_target_id']['field'] = 'field_author_target_id';
  $handler->display->display_options['relationships']['field_author_target_id']['label'] = 'Author';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_recipient_target_id']['id'] = 'field_recipient_target_id';
  $handler->display->display_options['relationships']['field_recipient_target_id']['table'] = 'field_data_field_recipient';
  $handler->display->display_options['relationships']['field_recipient_target_id']['field'] = 'field_recipient_target_id';
  $handler->display->display_options['relationships']['field_recipient_target_id']['label'] = 'Recipient';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_to_target_id']['id'] = 'field_related_to_target_id';
  $handler->display->display_options['relationships']['field_related_to_target_id']['table'] = 'field_data_field_related_to';
  $handler->display->display_options['relationships']['field_related_to_target_id']['field'] = 'field_related_to_target_id';
  $handler->display->display_options['relationships']['field_related_to_target_id']['label'] = 'Related To';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="fa fa-link"></a>';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_type'] = 'span';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = 'From';
  $handler->display->display_options['fields']['field_author']['element_type'] = '0';
  $handler->display->display_options['fields']['field_author']['element_class'] = 'people';
  $handler->display->display_options['fields']['field_author']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_author']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_author']['empty'] = 'Unknown';
  $handler->display->display_options['fields']['field_author']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  /* Field: Content: Recipient */
  $handler->display->display_options['fields']['field_recipient']['id'] = 'field_recipient';
  $handler->display->display_options['fields']['field_recipient']['table'] = 'field_data_field_recipient';
  $handler->display->display_options['fields']['field_recipient']['field'] = 'field_recipient';
  $handler->display->display_options['fields']['field_recipient']['label'] = 'To';
  $handler->display->display_options['fields']['field_recipient']['element_type'] = '0';
  $handler->display->display_options['fields']['field_recipient']['element_class'] = 'people';
  $handler->display->display_options['fields']['field_recipient']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_recipient']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_recipient']['empty'] = 'Unknown';
  $handler->display->display_options['fields']['field_recipient']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_recipient']['delta_offset'] = '0';
  /* Field: Field: Date Created */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_publication_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_publication_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_publication_date']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_to_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Related To';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Correspondence Type */
  $handler->display->display_options['fields']['field_correspondence_type']['id'] = 'field_correspondence_type';
  $handler->display->display_options['fields']['field_correspondence_type']['table'] = 'field_data_field_correspondence_type';
  $handler->display->display_options['fields']['field_correspondence_type']['field'] = 'field_correspondence_type';
  $handler->display->display_options['fields']['field_correspondence_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_correspondence_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_correspondence_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_correspondence_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_correspondence_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_correspondence_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_correspondence_type']['field_api_classes'] = TRUE;
  /* Sort criterion: Field: Date Created (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  /* Sort criterion: Content: Author (field_author) */
  $handler->display->display_options['sorts']['field_author_target_id']['id'] = 'field_author_target_id';
  $handler->display->display_options['sorts']['field_author_target_id']['table'] = 'field_data_field_author';
  $handler->display->display_options['sorts']['field_author_target_id']['field'] = 'field_author_target_id';
  /* Sort criterion: Content: Recipient (field_recipient) */
  $handler->display->display_options['sorts']['field_recipient_target_id']['id'] = 'field_recipient_target_id';
  $handler->display->display_options['sorts']['field_recipient_target_id']['table'] = 'field_data_field_recipient';
  $handler->display->display_options['sorts']['field_recipient_target_id']['field'] = 'field_recipient_target_id';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_related_to_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'correspondence' => 'correspondence',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;

  /* Display: Block - Sender */
  $handler = $view->new_display('block', 'Block - Sender', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Letters Sent';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_author_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block - Recipient */
  $handler = $view->new_display('block', 'Block - Recipient', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Letters Received';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_recipient_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block - Related To */
  $handler = $view->new_display('block', 'Block - Related To', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="fa fa-link"></span>';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = 'From';
  $handler->display->display_options['fields']['field_author']['element_type'] = '0';
  $handler->display->display_options['fields']['field_author']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_author']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_author']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_author']['separator'] = ',';
  $handler->display->display_options['fields']['field_author']['field_api_classes'] = TRUE;
  /* Field: Content: Recipient */
  $handler->display->display_options['fields']['field_recipient']['id'] = 'field_recipient';
  $handler->display->display_options['fields']['field_recipient']['table'] = 'field_data_field_recipient';
  $handler->display->display_options['fields']['field_recipient']['field'] = 'field_recipient';
  $handler->display->display_options['fields']['field_recipient']['label'] = 'To';
  $handler->display->display_options['fields']['field_recipient']['element_type'] = '0';
  $handler->display->display_options['fields']['field_recipient']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_recipient']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_recipient']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_recipient']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_recipient']['field_api_classes'] = TRUE;
  /* Field: Field: Date Created */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_publication_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_publication_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_publication_date']['field_api_classes'] = TRUE;
  /* Field: Content: Correspondence Type */
  $handler->display->display_options['fields']['field_correspondence_type']['id'] = 'field_correspondence_type';
  $handler->display->display_options['fields']['field_correspondence_type']['table'] = 'field_data_field_correspondence_type';
  $handler->display->display_options['fields']['field_correspondence_type']['field'] = 'field_correspondence_type';
  $handler->display->display_options['fields']['field_correspondence_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_correspondence_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_correspondence_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_correspondence_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_correspondence_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_correspondence_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_correspondence_type']['field_api_classes'] = TRUE;
  $export['correspondence'] = $view;

  return $export;
}

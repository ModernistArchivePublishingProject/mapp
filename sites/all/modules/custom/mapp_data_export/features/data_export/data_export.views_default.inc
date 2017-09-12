<?php
/**
 * @file
 * data_export.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function data_export_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'people_data_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'People Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Image(s) (field_fc_images) */
  $handler->display->display_options['relationships']['field_fc_images_value']['id'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['table'] = 'field_data_field_fc_images';
  $handler->display->display_options['relationships']['field_fc_images_value']['field'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Other Names */
  $handler->display->display_options['fields']['field_other_names']['id'] = 'field_other_names';
  $handler->display->display_options['fields']['field_other_names']['table'] = 'field_data_field_other_names';
  $handler->display->display_options['fields']['field_other_names']['field'] = 'field_other_names';
  $handler->display->display_options['fields']['field_other_names']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_other_names']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_other_names']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_other_names']['separator'] = '|';
  /* Field: Content: Birth Date */
  $handler->display->display_options['fields']['field_birth_date']['id'] = 'field_birth_date';
  $handler->display->display_options['fields']['field_birth_date']['table'] = 'field_data_field_birth_date';
  $handler->display->display_options['fields']['field_birth_date']['field'] = 'field_birth_date';
  $handler->display->display_options['fields']['field_birth_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_birth_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_birth_date']['click_sort_column'] = 'timestamp';
  $handler->display->display_options['fields']['field_birth_date']['settings'] = array(
    'use_override' => 'none',
    'format' => 'medium',
    'component_settings' => array(
      'meridiem' => 'a',
      'year_designation' => 'ce',
      'display' => array(
        'year' => 'estimate_label',
        'month' => 'estimate_label',
        'day' => 'estimate_label',
        'hour' => 'estimate_label',
        'minute' => 'estimate_label',
        'second' => 'estimate_label',
        'timezone' => 'date_only',
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
  /* Field: Content: Death Date */
  $handler->display->display_options['fields']['field_death_date']['id'] = 'field_death_date';
  $handler->display->display_options['fields']['field_death_date']['table'] = 'field_data_field_death_date';
  $handler->display->display_options['fields']['field_death_date']['field'] = 'field_death_date';
  $handler->display->display_options['fields']['field_death_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_death_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_death_date']['click_sort_column'] = 'timestamp';
  $handler->display->display_options['fields']['field_death_date']['settings'] = array(
    'use_override' => 'none',
    'format' => 'medium',
    'component_settings' => array(
      'meridiem' => 'a',
      'year_designation' => 'ce',
      'display' => array(
        'year' => 'estimate_label',
        'month' => 'estimate_label',
        'day' => 'estimate_label',
        'hour' => 'estimate_label',
        'minute' => 'estimate_label',
        'second' => 'estimate_label',
        'timezone' => 'date_only',
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
  /* Field: Content: Occupation */
  $handler->display->display_options['fields']['field_occupation']['id'] = 'field_occupation';
  $handler->display->display_options['fields']['field_occupation']['table'] = 'field_data_field_occupation';
  $handler->display->display_options['fields']['field_occupation']['field'] = 'field_occupation';
  $handler->display->display_options['fields']['field_occupation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_occupation']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_occupation']['separator'] = '|';
  /* Field: Content: Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gender']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_gender']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Authority Record */
  $handler->display->display_options['fields']['field_name_authority']['id'] = 'field_name_authority';
  $handler->display->display_options['fields']['field_name_authority']['table'] = 'field_data_field_name_authority';
  $handler->display->display_options['fields']['field_name_authority']['field'] = 'field_name_authority';
  $handler->display->display_options['fields']['field_name_authority']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_name_authority']['alter']['text'] = '[field_name_authority-value]';
  $handler->display->display_options['fields']['field_name_authority']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_authority']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_authority']['settings'] = array(
    'trim_length' => '',
    'nofollow' => 0,
  );
  $handler->display->display_options['fields']['field_name_authority']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_name_authority']['separator'] = '|';
  /* Field: Content: Birth Place - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_birth_place_thoroughfare']['id'] = 'field_birth_place_thoroughfare';
  $handler->display->display_options['fields']['field_birth_place_thoroughfare']['table'] = 'field_data_field_birth_place';
  $handler->display->display_options['fields']['field_birth_place_thoroughfare']['field'] = 'field_birth_place_thoroughfare';
  $handler->display->display_options['fields']['field_birth_place_thoroughfare']['label'] = 'Birth Address';
  $handler->display->display_options['fields']['field_birth_place_thoroughfare']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_birth_place_thoroughfare']['element_default_classes'] = FALSE;
  /* Field: Content: Birth Place - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_birth_place_locality']['id'] = 'field_birth_place_locality';
  $handler->display->display_options['fields']['field_birth_place_locality']['table'] = 'field_data_field_birth_place';
  $handler->display->display_options['fields']['field_birth_place_locality']['field'] = 'field_birth_place_locality';
  $handler->display->display_options['fields']['field_birth_place_locality']['label'] = 'Birth City';
  $handler->display->display_options['fields']['field_birth_place_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_birth_place_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Birth Place - Country */
  $handler->display->display_options['fields']['field_birth_place_country']['id'] = 'field_birth_place_country';
  $handler->display->display_options['fields']['field_birth_place_country']['table'] = 'field_data_field_birth_place';
  $handler->display->display_options['fields']['field_birth_place_country']['field'] = 'field_birth_place_country';
  $handler->display->display_options['fields']['field_birth_place_country']['label'] = 'Birth Nation';
  $handler->display->display_options['fields']['field_birth_place_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_birth_place_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_birth_place_country']['display_name'] = 0;
  /* Field: Content: Death Place - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_death_place_thoroughfare']['id'] = 'field_death_place_thoroughfare';
  $handler->display->display_options['fields']['field_death_place_thoroughfare']['table'] = 'field_data_field_death_place';
  $handler->display->display_options['fields']['field_death_place_thoroughfare']['field'] = 'field_death_place_thoroughfare';
  $handler->display->display_options['fields']['field_death_place_thoroughfare']['label'] = 'Death Address';
  $handler->display->display_options['fields']['field_death_place_thoroughfare']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_death_place_thoroughfare']['element_default_classes'] = FALSE;
  /* Field: Content: Death Place - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_death_place_locality']['id'] = 'field_death_place_locality';
  $handler->display->display_options['fields']['field_death_place_locality']['table'] = 'field_data_field_death_place';
  $handler->display->display_options['fields']['field_death_place_locality']['field'] = 'field_death_place_locality';
  $handler->display->display_options['fields']['field_death_place_locality']['label'] = 'Death City';
  $handler->display->display_options['fields']['field_death_place_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_death_place_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Death Place - Country */
  $handler->display->display_options['fields']['field_death_place_country']['id'] = 'field_death_place_country';
  $handler->display->display_options['fields']['field_death_place_country']['table'] = 'field_data_field_death_place';
  $handler->display->display_options['fields']['field_death_place_country']['field'] = 'field_death_place_country';
  $handler->display->display_options['fields']['field_death_place_country']['label'] = 'Death Nation';
  $handler->display->display_options['fields']['field_death_place_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_death_place_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_death_place_country']['display_name'] = 0;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'url_type' => '0',
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_image']['separator'] = '|';
  /* Field: Field collection item: Caption */
  $handler->display->display_options['fields']['field_caption']['id'] = 'field_caption';
  $handler->display->display_options['fields']['field_caption']['table'] = 'field_data_field_caption';
  $handler->display->display_options['fields']['field_caption']['field'] = 'field_caption';
  $handler->display->display_options['fields']['field_caption']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_caption']['label'] = 'Image Caption';
  $handler->display->display_options['fields']['field_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_caption']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_caption']['type'] = 'text_plain';
  /* Field: Field collection item: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_source']['label'] = 'Image Source';
  $handler->display->display_options['fields']['field_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_source']['type'] = 'text_plain';
  /* Field: Content: Further Reading */
  $handler->display->display_options['fields']['field_bibliographic_item']['id'] = 'field_bibliographic_item';
  $handler->display->display_options['fields']['field_bibliographic_item']['table'] = 'field_data_field_bibliographic_item';
  $handler->display->display_options['fields']['field_bibliographic_item']['field'] = 'field_bibliographic_item';
  $handler->display->display_options['fields']['field_bibliographic_item']['label'] = 'Bibliographic Item';
  $handler->display->display_options['fields']['field_bibliographic_item']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bibliographic_item']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bibliographic_item']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_bibliographic_item']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_bibliographic_item']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_bibliographic_item']['separator'] = '|';
  /* Field: Content: Business Relationships */
  $handler->display->display_options['fields']['field_business_relationship']['id'] = 'field_business_relationship';
  $handler->display->display_options['fields']['field_business_relationship']['table'] = 'field_data_field_business_relationship';
  $handler->display->display_options['fields']['field_business_relationship']['field'] = 'field_business_relationship';
  $handler->display->display_options['fields']['field_business_relationship']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_business_relationship']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_business_relationship']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_business_relationship']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_business_relationship']['separator'] = '| ';
  /* Field: Content: Relationships */
  $handler->display->display_options['fields']['field_relationships']['id'] = 'field_relationships';
  $handler->display->display_options['fields']['field_relationships']['table'] = 'field_data_field_relationships';
  $handler->display->display_options['fields']['field_relationships']['field'] = 'field_relationships';
  $handler->display->display_options['fields']['field_relationships']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_relationships']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_relationships']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_relationships']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_relationships']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_relationships']['separator'] = '|';
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_file_attachments']['id'] = 'field_file_attachments';
  $handler->display->display_options['fields']['field_file_attachments']['table'] = 'field_data_field_file_attachments';
  $handler->display->display_options['fields']['field_file_attachments']['field'] = 'field_file_attachments';
  $handler->display->display_options['fields']['field_file_attachments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_attachments']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_file_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_attachments']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_attachments']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_file_attachments']['separator'] = '|';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'person' => 'person',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'people.csv';
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['people_data_export'] = $view;

  return $export;
}

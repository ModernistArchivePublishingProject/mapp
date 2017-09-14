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
  $view->name = 'businesses_data_export';
  $view->description = '';
  $view->tag = 'data_export';
  $view->base_table = 'node';
  $view->human_name = 'Businesses Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Businesses Data Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_business_type']['id'] = 'field_business_type';
  $handler->display->display_options['fields']['field_business_type']['table'] = 'field_data_field_business_type';
  $handler->display->display_options['fields']['field_business_type']['field'] = 'field_business_type';
  $handler->display->display_options['fields']['field_business_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_business_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_business_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_business_type']['separator'] = '|';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_image']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
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
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = TRUE;
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
  $handler->display->display_options['fields']['field_source']['element_default_classes'] = FALSE;
  /* Field: Field: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website']['alter']['text'] = '[field_website-value]';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_website']['settings'] = array(
    'trim_length' => '80',
    'nofollow' => 0,
  );
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

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'businesses.csv';
  $export['businesses_data_export'] = $view;

  $view = new view();
  $view->name = 'correspondence_data_export';
  $view->description = '';
  $view->tag = 'data_export';
  $view->base_table = 'node';
  $view->human_name = 'Correspondence Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Correspondence CSV Download';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Image(s) (field_fc_images) */
  $handler->display->display_options['relationships']['field_fc_images_value']['id'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['table'] = 'field_data_field_fc_images';
  $handler->display->display_options['relationships']['field_fc_images_value']['field'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  $handler->display->display_options['fields']['field_caption']['alter']['trim_whitespace'] = TRUE;
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
  /* Field: Field collection item: Rights Holder */
  $handler->display->display_options['fields']['field_rights_holder']['id'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['table'] = 'field_data_field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['field'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_rights_holder']['label'] = 'Image Rights Holder';
  $handler->display->display_options['fields']['field_rights_holder']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_rights_holder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_rights_holder']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_rights_holder']['separator'] = '|';
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['field_image_url']['id'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['table'] = 'field_data_field_image_url';
  $handler->display->display_options['fields']['field_image_url']['field'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_image_url']['label'] = 'Image URL';
  $handler->display->display_options['fields']['field_image_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_image_url']['type'] = 'link_plain';
  /* Field: Content: Date Written */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Correspondence Type */
  $handler->display->display_options['fields']['field_correspondence_type']['id'] = 'field_correspondence_type';
  $handler->display->display_options['fields']['field_correspondence_type']['table'] = 'field_data_field_correspondence_type';
  $handler->display->display_options['fields']['field_correspondence_type']['field'] = 'field_correspondence_type';
  $handler->display->display_options['fields']['field_correspondence_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_correspondence_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_correspondence_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_correspondence_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_correspondence_type']['separator'] = '|';
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_author']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_author']['separator'] = '|';
  /* Field: Content: Recipient */
  $handler->display->display_options['fields']['field_recipient']['id'] = 'field_recipient';
  $handler->display->display_options['fields']['field_recipient']['table'] = 'field_data_field_recipient';
  $handler->display->display_options['fields']['field_recipient']['field'] = 'field_recipient';
  $handler->display->display_options['fields']['field_recipient']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recipient']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_recipient']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_recipient']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_recipient']['separator'] = '|';
  /* Field: Content: Typist */
  $handler->display->display_options['fields']['field_typist']['id'] = 'field_typist';
  $handler->display->display_options['fields']['field_typist']['table'] = 'field_data_field_typist';
  $handler->display->display_options['fields']['field_typist']['field'] = 'field_typist';
  $handler->display->display_options['fields']['field_typist']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_typist']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_typist']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  /* Field: Content: Related To */
  $handler->display->display_options['fields']['field_related_to']['id'] = 'field_related_to';
  $handler->display->display_options['fields']['field_related_to']['table'] = 'field_data_field_related_to';
  $handler->display->display_options['fields']['field_related_to']['field'] = 'field_related_to';
  $handler->display->display_options['fields']['field_related_to']['label'] = 'Related to NID';
  $handler->display->display_options['fields']['field_related_to']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_to']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_related_to']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_related_to']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_related_to']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_related_to']['separator'] = '|';
  /* Field: Content: Related To */
  $handler->display->display_options['fields']['field_related_to_1']['id'] = 'field_related_to_1';
  $handler->display->display_options['fields']['field_related_to_1']['table'] = 'field_data_field_related_to';
  $handler->display->display_options['fields']['field_related_to_1']['field'] = 'field_related_to';
  $handler->display->display_options['fields']['field_related_to_1']['label'] = 'Related To Title';
  $handler->display->display_options['fields']['field_related_to_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_related_to_1']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_related_to_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_related_to_1']['separator'] = '|';
  /* Field: Content: Sent To - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_sent_to_thoroughfare']['id'] = 'field_sent_to_thoroughfare';
  $handler->display->display_options['fields']['field_sent_to_thoroughfare']['table'] = 'field_data_field_sent_to';
  $handler->display->display_options['fields']['field_sent_to_thoroughfare']['field'] = 'field_sent_to_thoroughfare';
  /* Field: Content: Sent To - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_sent_to_premise']['id'] = 'field_sent_to_premise';
  $handler->display->display_options['fields']['field_sent_to_premise']['table'] = 'field_data_field_sent_to';
  $handler->display->display_options['fields']['field_sent_to_premise']['field'] = 'field_sent_to_premise';
  $handler->display->display_options['fields']['field_sent_to_premise']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_to_premise']['element_default_classes'] = FALSE;
  /* Field: Content: Sent To - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_sent_to_locality']['id'] = 'field_sent_to_locality';
  $handler->display->display_options['fields']['field_sent_to_locality']['table'] = 'field_data_field_sent_to';
  $handler->display->display_options['fields']['field_sent_to_locality']['field'] = 'field_sent_to_locality';
  $handler->display->display_options['fields']['field_sent_to_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_to_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Sent To - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_sent_to_administrative_area']['id'] = 'field_sent_to_administrative_area';
  $handler->display->display_options['fields']['field_sent_to_administrative_area']['table'] = 'field_data_field_sent_to';
  $handler->display->display_options['fields']['field_sent_to_administrative_area']['field'] = 'field_sent_to_administrative_area';
  $handler->display->display_options['fields']['field_sent_to_administrative_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_to_administrative_area']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sent_to_administrative_area']['display_name'] = 1;
  /* Field: Content: Sent To - Country */
  $handler->display->display_options['fields']['field_sent_to_country']['id'] = 'field_sent_to_country';
  $handler->display->display_options['fields']['field_sent_to_country']['table'] = 'field_data_field_sent_to';
  $handler->display->display_options['fields']['field_sent_to_country']['field'] = 'field_sent_to_country';
  $handler->display->display_options['fields']['field_sent_to_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_to_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sent_to_country']['display_name'] = 0;
  /* Field: Content: Sent To - Postal code */
  $handler->display->display_options['fields']['field_sent_to_postal_code']['id'] = 'field_sent_to_postal_code';
  $handler->display->display_options['fields']['field_sent_to_postal_code']['table'] = 'field_data_field_sent_to';
  $handler->display->display_options['fields']['field_sent_to_postal_code']['field'] = 'field_sent_to_postal_code';
  $handler->display->display_options['fields']['field_sent_to_postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_to_postal_code']['element_default_classes'] = FALSE;
  /* Field: Content: Sent From - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_sent_from_thoroughfare']['id'] = 'field_sent_from_thoroughfare';
  $handler->display->display_options['fields']['field_sent_from_thoroughfare']['table'] = 'field_data_field_sent_from';
  $handler->display->display_options['fields']['field_sent_from_thoroughfare']['field'] = 'field_sent_from_thoroughfare';
  /* Field: Content: Sent From - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_sent_from_premise']['id'] = 'field_sent_from_premise';
  $handler->display->display_options['fields']['field_sent_from_premise']['table'] = 'field_data_field_sent_from';
  $handler->display->display_options['fields']['field_sent_from_premise']['field'] = 'field_sent_from_premise';
  $handler->display->display_options['fields']['field_sent_from_premise']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_from_premise']['element_default_classes'] = FALSE;
  /* Field: Content: Sent From - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_sent_from_locality']['id'] = 'field_sent_from_locality';
  $handler->display->display_options['fields']['field_sent_from_locality']['table'] = 'field_data_field_sent_from';
  $handler->display->display_options['fields']['field_sent_from_locality']['field'] = 'field_sent_from_locality';
  $handler->display->display_options['fields']['field_sent_from_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_from_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Sent From - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_sent_from_administrative_area']['id'] = 'field_sent_from_administrative_area';
  $handler->display->display_options['fields']['field_sent_from_administrative_area']['table'] = 'field_data_field_sent_from';
  $handler->display->display_options['fields']['field_sent_from_administrative_area']['field'] = 'field_sent_from_administrative_area';
  $handler->display->display_options['fields']['field_sent_from_administrative_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_from_administrative_area']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sent_from_administrative_area']['display_name'] = 0;
  /* Field: Content: Sent From - Country */
  $handler->display->display_options['fields']['field_sent_from_country']['id'] = 'field_sent_from_country';
  $handler->display->display_options['fields']['field_sent_from_country']['table'] = 'field_data_field_sent_from';
  $handler->display->display_options['fields']['field_sent_from_country']['field'] = 'field_sent_from_country';
  $handler->display->display_options['fields']['field_sent_from_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_from_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sent_from_country']['display_name'] = 0;
  /* Field: Content: Sent From - Postal code */
  $handler->display->display_options['fields']['field_sent_from_postal_code']['id'] = 'field_sent_from_postal_code';
  $handler->display->display_options['fields']['field_sent_from_postal_code']['table'] = 'field_data_field_sent_from';
  $handler->display->display_options['fields']['field_sent_from_postal_code']['field'] = 'field_sent_from_postal_code';
  $handler->display->display_options['fields']['field_sent_from_postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sent_from_postal_code']['element_default_classes'] = FALSE;
  /* Field: Field: Library */
  $handler->display->display_options['fields']['field_library']['id'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['table'] = 'field_data_field_library';
  $handler->display->display_options['fields']['field_library']['field'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_library']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_library']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_library']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_library']['separator'] = '|';
  /* Field: Field: Link(s) to Digitized Materials */
  $handler->display->display_options['fields']['field_link_digitized']['id'] = 'field_link_digitized';
  $handler->display->display_options['fields']['field_link_digitized']['table'] = 'field_data_field_link_digitized';
  $handler->display->display_options['fields']['field_link_digitized']['field'] = 'field_link_digitized';
  $handler->display->display_options['fields']['field_link_digitized']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_link_digitized']['alter']['text'] = '[field_link_digitized-value]';
  $handler->display->display_options['fields']['field_link_digitized']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_digitized']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link_digitized']['settings'] = array(
    'trim_length' => '80',
    'nofollow' => 0,
  );
  $handler->display->display_options['fields']['field_link_digitized']['delta_offset'] = '0';
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
    'correspondence' => 'correspondence',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'correspondence.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['correspondence_data_export'] = $view;

  $view = new view();
  $view->name = 'editions_data_export';
  $view->description = '';
  $view->tag = 'data_export';
  $view->base_table = 'node';
  $view->human_name = 'Editions Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Editions CSV Download';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Image(s) (field_fc_images) */
  $handler->display->display_options['relationships']['field_fc_images_value']['id'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['table'] = 'field_data_field_fc_images';
  $handler->display->display_options['relationships']['field_fc_images_value']['field'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Work */
  $handler->display->display_options['fields']['field_work']['id'] = 'field_work';
  $handler->display->display_options['fields']['field_work']['table'] = 'field_data_field_work';
  $handler->display->display_options['fields']['field_work']['field'] = 'field_work';
  $handler->display->display_options['fields']['field_work']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_work']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_author']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_author']['separator'] = '|';
  /* Field: Content: Editor */
  $handler->display->display_options['fields']['field_editor']['id'] = 'field_editor';
  $handler->display->display_options['fields']['field_editor']['table'] = 'field_data_field_editor';
  $handler->display->display_options['fields']['field_editor']['field'] = 'field_editor';
  $handler->display->display_options['fields']['field_editor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_editor']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_editor']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_editor']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_editor']['separator'] = '|';
  /* Field: Content: Translator */
  $handler->display->display_options['fields']['field_translator']['id'] = 'field_translator';
  $handler->display->display_options['fields']['field_translator']['table'] = 'field_data_field_translator';
  $handler->display->display_options['fields']['field_translator']['field'] = 'field_translator';
  $handler->display->display_options['fields']['field_translator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_translator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_translator']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_translator']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_translator']['separator'] = '|';
  /* Field: Content: Publisher */
  $handler->display->display_options['fields']['field_publisher']['id'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['table'] = 'field_data_field_publisher';
  $handler->display->display_options['fields']['field_publisher']['field'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_publisher']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publisher']['separator'] = '|';
  /* Field: Content: Printer */
  $handler->display->display_options['fields']['field_printer']['id'] = 'field_printer';
  $handler->display->display_options['fields']['field_printer']['table'] = 'field_data_field_printer';
  $handler->display->display_options['fields']['field_printer']['field'] = 'field_printer';
  $handler->display->display_options['fields']['field_printer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_printer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_printer']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_printer']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_printer']['separator'] = '|';
  /* Field: Content: Illustrator */
  $handler->display->display_options['fields']['field_illustrator']['id'] = 'field_illustrator';
  $handler->display->display_options['fields']['field_illustrator']['table'] = 'field_data_field_illustrator';
  $handler->display->display_options['fields']['field_illustrator']['field'] = 'field_illustrator';
  $handler->display->display_options['fields']['field_illustrator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_illustrator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_illustrator']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  /* Field: Content: Genre */
  $handler->display->display_options['fields']['field_work_type']['id'] = 'field_work_type';
  $handler->display->display_options['fields']['field_work_type']['table'] = 'field_data_field_work_type';
  $handler->display->display_options['fields']['field_work_type']['field'] = 'field_work_type';
  $handler->display->display_options['fields']['field_work_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_work_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_work_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['label'] = 'Original Language';
  $handler->display->display_options['fields']['field_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_language']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_language']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Copyright Status */
  $handler->display->display_options['fields']['field_copyright_status']['id'] = 'field_copyright_status';
  $handler->display->display_options['fields']['field_copyright_status']['table'] = 'field_data_field_copyright_status';
  $handler->display->display_options['fields']['field_copyright_status']['field'] = 'field_copyright_status';
  $handler->display->display_options['fields']['field_copyright_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_copyright_status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_copyright_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Publication Date */
  $handler->display->display_options['fields']['field_copyright_date']['id'] = 'field_copyright_date';
  $handler->display->display_options['fields']['field_copyright_date']['table'] = 'field_data_field_copyright_date';
  $handler->display->display_options['fields']['field_copyright_date']['field'] = 'field_copyright_date';
  $handler->display->display_options['fields']['field_copyright_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_copyright_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_copyright_date']['settings'] = array(
    'format_type' => 'year_only',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
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
  /* Field: Field collection item: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_source']['label'] = 'Image Source';
  $handler->display->display_options['fields']['field_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_source']['type'] = 'text_plain';
  /* Field: Field collection item: Rights Holder */
  $handler->display->display_options['fields']['field_rights_holder']['id'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['table'] = 'field_data_field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['field'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_rights_holder']['label'] = 'Image Rights Holder';
  $handler->display->display_options['fields']['field_rights_holder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_rights_holder']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_rights_holder']['separator'] = '|';
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['field_image_url']['id'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['table'] = 'field_data_field_image_url';
  $handler->display->display_options['fields']['field_image_url']['field'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_image_url']['label'] = 'Image URL';
  $handler->display->display_options['fields']['field_image_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_image_url']['type'] = 'link_plain';
  /* Field: Content: Number of pages */
  $handler->display->display_options['fields']['field_pages']['id'] = 'field_pages';
  $handler->display->display_options['fields']['field_pages']['table'] = 'field_data_field_pages';
  $handler->display->display_options['fields']['field_pages']['field'] = 'field_pages';
  $handler->display->display_options['fields']['field_pages']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pages']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pages']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Paper Type */
  $handler->display->display_options['fields']['field_paper_type']['id'] = 'field_paper_type';
  $handler->display->display_options['fields']['field_paper_type']['table'] = 'field_data_field_paper_type';
  $handler->display->display_options['fields']['field_paper_type']['field'] = 'field_paper_type';
  $handler->display->display_options['fields']['field_paper_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_paper_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_paper_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price']['element_default_classes'] = FALSE;
  /* Field: Content: Print run */
  $handler->display->display_options['fields']['field_print_run']['id'] = 'field_print_run';
  $handler->display->display_options['fields']['field_print_run']['table'] = 'field_data_field_print_run';
  $handler->display->display_options['fields']['field_print_run']['field'] = 'field_print_run';
  $handler->display->display_options['fields']['field_print_run']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_print_run']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_print_run']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Size */
  $handler->display->display_options['fields']['field_size']['id'] = 'field_size';
  $handler->display->display_options['fields']['field_size']['table'] = 'field_data_field_size';
  $handler->display->display_options['fields']['field_size']['field'] = 'field_size';
  $handler->display->display_options['fields']['field_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_size']['element_default_classes'] = FALSE;
  /* Field: Content: Type of Edition */
  $handler->display->display_options['fields']['field_edition']['id'] = 'field_edition';
  $handler->display->display_options['fields']['field_edition']['table'] = 'field_data_field_edition';
  $handler->display->display_options['fields']['field_edition']['field'] = 'field_edition';
  $handler->display->display_options['fields']['field_edition']['label'] = 'Type';
  $handler->display->display_options['fields']['field_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_edition']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_edition']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_edition']['separator'] = '|';
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
    'edition' => 'edition',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'editions.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['editions_data_export'] = $view;

  $view = new view();
  $view->name = 'people_data_export';
  $view->description = '';
  $view->tag = 'data_export';
  $view->base_table = 'node';
  $view->human_name = 'People Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People CSV Download';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['people_data_export'] = $view;

  $view = new view();
  $view->name = 'primary_objects_data_export';
  $view->description = '';
  $view->tag = 'data_export';
  $view->base_table = 'node';
  $view->human_name = 'Primary Objects Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Primary Objects CSV Download';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Image(s) (field_fc_images) */
  $handler->display->display_options['relationships']['field_fc_images_value']['id'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['table'] = 'field_data_field_fc_images';
  $handler->display->display_options['relationships']['field_fc_images_value']['field'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Edition */
  $handler->display->display_options['fields']['field_edition_ref']['id'] = 'field_edition_ref';
  $handler->display->display_options['fields']['field_edition_ref']['table'] = 'field_data_field_edition_ref';
  $handler->display->display_options['fields']['field_edition_ref']['field'] = 'field_edition_ref';
  $handler->display->display_options['fields']['field_edition_ref']['label'] = 'Edition ID';
  $handler->display->display_options['fields']['field_edition_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition_ref']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_edition_ref']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_edition_ref']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  /* Field: Content: Owner */
  $handler->display->display_options['fields']['field_owner']['id'] = 'field_owner';
  $handler->display->display_options['fields']['field_owner']['table'] = 'field_data_field_owner';
  $handler->display->display_options['fields']['field_owner']['field'] = 'field_owner';
  $handler->display->display_options['fields']['field_owner']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_owner']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_owner']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_owner']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_owner']['separator'] = '|';
  /* Field: Content: Reader */
  $handler->display->display_options['fields']['field_reader']['id'] = 'field_reader';
  $handler->display->display_options['fields']['field_reader']['table'] = 'field_data_field_reader';
  $handler->display->display_options['fields']['field_reader']['field'] = 'field_reader';
  $handler->display->display_options['fields']['field_reader']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_reader']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_reader']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_reader']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_reader']['separator'] = '|';
  /* Field: Content: Condition */
  $handler->display->display_options['fields']['field_condition']['id'] = 'field_condition';
  $handler->display->display_options['fields']['field_condition']['table'] = 'field_data_field_condition';
  $handler->display->display_options['fields']['field_condition']['field'] = 'field_condition';
  $handler->display->display_options['fields']['field_condition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_condition']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_condition']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Damage */
  $handler->display->display_options['fields']['field_damage']['id'] = 'field_damage';
  $handler->display->display_options['fields']['field_damage']['table'] = 'field_data_field_damage';
  $handler->display->display_options['fields']['field_damage']['field'] = 'field_damage';
  $handler->display->display_options['fields']['field_damage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_damage']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_damage']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_damage']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_damage']['separator'] = '|';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_image']['label'] = 'Image(s)';
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '[field_image]';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'url_type' => '3',
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
  /* Field: Field collection item: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_source']['label'] = 'Image Source';
  $handler->display->display_options['fields']['field_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_source']['type'] = 'text_plain';
  /* Field: Field collection item: Rights Holder */
  $handler->display->display_options['fields']['field_rights_holder']['id'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['table'] = 'field_data_field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['field'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_rights_holder']['label'] = 'Image Rights Holder';
  $handler->display->display_options['fields']['field_rights_holder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_rights_holder']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_rights_holder']['separator'] = '|';
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
    'primary_object' => 'primary_object',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'primary_objects.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['primary_objects_data_export'] = $view;

  $view = new view();
  $view->name = 'related_materials_data_export';
  $view->description = '';
  $view->tag = 'data_export';
  $view->base_table = 'node';
  $view->human_name = 'Related Materials Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Materials CSV Download';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Image(s) (field_fc_images) */
  $handler->display->display_options['relationships']['field_fc_images_value']['id'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['table'] = 'field_data_field_fc_images';
  $handler->display->display_options['relationships']['field_fc_images_value']['field'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_author']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_author']['separator'] = '|';
  /* Field: Content: Date Written */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'Date Created';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'year_only',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_genre']['id'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['table'] = 'field_data_field_genre';
  $handler->display->display_options['fields']['field_genre']['field'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['label'] = 'Genre';
  $handler->display->display_options['fields']['field_genre']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_genre']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_genre']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_genre']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_genre']['separator'] = '|';
  /* Field: Content: Related To */
  $handler->display->display_options['fields']['field_material_related_to']['id'] = 'field_material_related_to';
  $handler->display->display_options['fields']['field_material_related_to']['table'] = 'field_data_field_material_related_to';
  $handler->display->display_options['fields']['field_material_related_to']['field'] = 'field_material_related_to';
  $handler->display->display_options['fields']['field_material_related_to']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_material_related_to']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_material_related_to']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_material_related_to']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_material_related_to']['separator'] = '|';
  /* Field: Content: Publication Process */
  $handler->display->display_options['fields']['field_publication_process']['id'] = 'field_publication_process';
  $handler->display->display_options['fields']['field_publication_process']['table'] = 'field_data_field_publication_process';
  $handler->display->display_options['fields']['field_publication_process']['field'] = 'field_publication_process';
  $handler->display->display_options['fields']['field_publication_process']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_process']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_process']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_publication_process']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publication_process']['separator'] = '|';
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
  /* Field: Field: Identifier */
  $handler->display->display_options['fields']['field_identifier']['id'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier']['field'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_identifier']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_identifier']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_identifier']['delta_offset'] = '0';
  /* Field: Field: Library */
  $handler->display->display_options['fields']['field_library']['id'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['table'] = 'field_data_field_library';
  $handler->display->display_options['fields']['field_library']['field'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_library']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_library']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_library']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_library']['separator'] = '|';
  /* Field: Field: Link(s) to Digitized Materials */
  $handler->display->display_options['fields']['field_link_digitized']['id'] = 'field_link_digitized';
  $handler->display->display_options['fields']['field_link_digitized']['table'] = 'field_data_field_link_digitized';
  $handler->display->display_options['fields']['field_link_digitized']['field'] = 'field_link_digitized';
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
  $handler->display->display_options['fields']['field_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_caption']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_caption']['type'] = 'text_plain';
  /* Field: Field collection item: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_source']['type'] = 'text_plain';
  /* Field: Field collection item: Rights Holder */
  $handler->display->display_options['fields']['field_rights_holder']['id'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['table'] = 'field_data_field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['field'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_rights_holder']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_rights_holder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_rights_holder']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_rights_holder']['separator'] = '|';
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['field_image_url']['id'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['table'] = 'field_data_field_image_url';
  $handler->display->display_options['fields']['field_image_url']['field'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_image_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_image_url']['type'] = 'link_plain';
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
    'related_materials' => 'related_materials',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'related_materials.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['related_materials_data_export'] = $view;

  $view = new view();
  $view->name = 'works_data_export';
  $view->description = '';
  $view->tag = 'data_export';
  $view->base_table = 'node';
  $view->human_name = 'Works Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Works CSV Download';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Image(s) (field_fc_images) */
  $handler->display->display_options['relationships']['field_fc_images_value']['id'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['table'] = 'field_data_field_fc_images';
  $handler->display->display_options['relationships']['field_fc_images_value']['field'] = 'field_fc_images_value';
  $handler->display->display_options['relationships']['field_fc_images_value']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_author']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_author']['separator'] = '|';
  /* Field: Content: Editor */
  $handler->display->display_options['fields']['field_editor']['id'] = 'field_editor';
  $handler->display->display_options['fields']['field_editor']['table'] = 'field_data_field_editor';
  $handler->display->display_options['fields']['field_editor']['field'] = 'field_editor';
  $handler->display->display_options['fields']['field_editor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_editor']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_editor']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_editor']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_editor']['separator'] = '|';
  /* Field: Content: Translator */
  $handler->display->display_options['fields']['field_translator']['id'] = 'field_translator';
  $handler->display->display_options['fields']['field_translator']['table'] = 'field_data_field_translator';
  $handler->display->display_options['fields']['field_translator']['field'] = 'field_translator';
  $handler->display->display_options['fields']['field_translator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_translator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_translator']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_translator']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_translator']['separator'] = '|';
  /* Field: Content: Genre */
  $handler->display->display_options['fields']['field_work_type']['id'] = 'field_work_type';
  $handler->display->display_options['fields']['field_work_type']['table'] = 'field_data_field_work_type';
  $handler->display->display_options['fields']['field_work_type']['field'] = 'field_work_type';
  $handler->display->display_options['fields']['field_work_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_work_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_work_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['label'] = 'Original Language';
  $handler->display->display_options['fields']['field_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_language']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_language']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Copyright Status */
  $handler->display->display_options['fields']['field_copyright_status']['id'] = 'field_copyright_status';
  $handler->display->display_options['fields']['field_copyright_status']['table'] = 'field_data_field_copyright_status';
  $handler->display->display_options['fields']['field_copyright_status']['field'] = 'field_copyright_status';
  $handler->display->display_options['fields']['field_copyright_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_copyright_status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_copyright_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Publication Date */
  $handler->display->display_options['fields']['field_copyright_date']['id'] = 'field_copyright_date';
  $handler->display->display_options['fields']['field_copyright_date']['table'] = 'field_data_field_copyright_date';
  $handler->display->display_options['fields']['field_copyright_date']['field'] = 'field_copyright_date';
  $handler->display->display_options['fields']['field_copyright_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_copyright_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_copyright_date']['settings'] = array(
    'format_type' => 'year_only',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
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
  /* Field: Field collection item: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_source']['label'] = 'Image Source';
  $handler->display->display_options['fields']['field_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_source']['type'] = 'text_plain';
  /* Field: Field collection item: Rights Holder */
  $handler->display->display_options['fields']['field_rights_holder']['id'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['table'] = 'field_data_field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['field'] = 'field_rights_holder';
  $handler->display->display_options['fields']['field_rights_holder']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_rights_holder']['label'] = 'Image Rights Holder';
  $handler->display->display_options['fields']['field_rights_holder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rights_holder']['settings'] = array(
    'bypass_access' => 1,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_rights_holder']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_rights_holder']['separator'] = '|';
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['field_image_url']['id'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['table'] = 'field_data_field_image_url';
  $handler->display->display_options['fields']['field_image_url']['field'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['relationship'] = 'field_fc_images_value';
  $handler->display->display_options['fields']['field_image_url']['label'] = 'Image URL';
  $handler->display->display_options['fields']['field_image_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_image_url']['type'] = 'link_plain';
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
    'work' => 'work',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'works.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['works_data_export'] = $view;

  return $export;
}

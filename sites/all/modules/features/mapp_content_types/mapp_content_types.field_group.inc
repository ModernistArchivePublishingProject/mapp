<?php
/**
 * @file
 * mapp_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mapp_content_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|correspondence|form';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'correspondence';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '5',
    'children' => array(
      0 => 'field_correspondence_type',
      1 => 'field_related_to',
      2 => 'field_publication_date',
      3 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_about|node|correspondence|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|related_materials|form';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'related_materials';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '1',
    'children' => array(
      0 => 'field_author',
      1 => 'field_description',
      2 => 'field_publication_date',
      3 => 'field_tags',
      4 => 'field_genre',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_about|node|related_materials|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_birth|node|person|form';
  $field_group->group_name = 'group_birth';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Birth',
    'weight' => '5',
    'children' => array(
      0 => 'field_birth_location',
      1 => 'field_birth_place',
      2 => 'field_birth_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-birth field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_birth|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_death|node|person|form';
  $field_group->group_name = 'group_death';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Death',
    'weight' => '6',
    'children' => array(
      0 => 'field_death_location',
      1 => 'field_death_place',
      2 => 'field_death_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-death field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_death|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|edition|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'edition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '4',
    'children' => array(
      0 => 'field_edition',
      1 => 'field_language',
      2 => 'field_pages',
      3 => 'field_price',
      4 => 'field_print_run',
      5 => 'field_publication_date',
      6 => 'field_size',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-details field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_details|node|edition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_libraries|node|bp_book|form';
  $field_group->group_name = 'group_libraries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'primary_object';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Libraries',
    'weight' => '8',
    'children' => array(
      0 => 'field_library',
      1 => 'field_link_digitized',
      2 => 'field_identifier',
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
  $field_group->identifier = 'group_libraries|node|edition|form';
  $field_group->group_name = 'group_libraries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'edition';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_links';
  $field_group->data = array(
    'label' => 'Libraries',
    'weight' => '7',
    'children' => array(
      0 => 'field_identifier',
      1 => 'field_library',
      2 => 'field_link_digitized',
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
  $export['group_libraries|node|edition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|node|edition|form';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'edition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '3',
    'children' => array(
      0 => 'field_illustrator',
      1 => 'field_printer',
      2 => 'field_publisher',
      3 => 'field_work',
      4 => 'group_libraries',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-links field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_links|node|edition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_locations|node|correspondence|form';
  $field_group->group_name = 'group_locations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'correspondence';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Locations',
    'weight' => '6',
    'children' => array(
      0 => 'field_library',
      1 => 'field_link_digitized',
      2 => 'field_geocoded_from',
      3 => 'field_sent_from',
      4 => 'field_sent_to',
      5 => 'field_geocoded_to',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-locations field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_locations|node|correspondence|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|work|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'work';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '5',
    'children' => array(
      0 => 'field_genre',
      1 => 'field_copyright_status',
      2 => 'field_call_number',
      3 => 'field_copyright_date',
      4 => 'field_work_type',
      5 => 'field_identifier',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_metadata|node|work|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people|node|correspondence|form';
  $field_group->group_name = 'group_people';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'correspondence';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'People',
    'weight' => '4',
    'children' => array(
      0 => 'field_author',
      1 => 'field_recipient',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-people field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_people|node|correspondence|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people|node|work|form';
  $field_group->group_name = 'group_people';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'work';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'People',
    'weight' => '4',
    'children' => array(
      0 => 'field_author',
      1 => 'field_editor',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'People',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_people|node|work|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_process|node|related_materials|form';
  $field_group->group_name = 'group_publication_process';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'related_materials';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publication Process',
    'weight' => '2',
    'children' => array(
      0 => 'field_publication_process',
      1 => 'field_material_related_to',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publication-process field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_publication_process|node|related_materials|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reception|node|material_expression|form';
  $field_group->group_name = 'group_reception';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'primary_object';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Reception History',
    'weight' => '7',
    'children' => array(
      0 => 'field_damage',
      1 => 'field_condition',
      2 => 'field_reader',
      3 => 'field_owner',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-reception field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_reception|node|material_expression|form'] = $field_group;

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
      0 => 'field_link_digitized',
      1 => 'field_images',
      2 => 'field_library',
      3 => 'field_identifier',
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
  $export['group_resources|node|related_materials|form'] = $field_group;

  return $export;
}

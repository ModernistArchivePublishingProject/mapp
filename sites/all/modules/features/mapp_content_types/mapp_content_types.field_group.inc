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
  $field_group->identifier = 'group_about|node|business|form';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'business';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '1',
    'children' => array(
      0 => 'field_website',
      1 => 'field_business_type',
      2 => 'field_bibliographic_item',
      3 => 'field_fc_images',
      4 => 'field_narrative',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_about|node|business|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|correspondence|default';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'correspondence';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '4',
    'children' => array(
      0 => 'field_correspondence_type',
      1 => 'field_publication_date',
      2 => 'field_related_to',
      3 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_about|node|correspondence|default'] = $field_group;

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
      1 => 'field_publication_date',
      2 => 'field_related_to',
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
  $field_groups['group_about|node|correspondence|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|related_materials|default';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'related_materials';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '0',
    'children' => array(
      0 => 'field_author',
      1 => 'field_description',
      2 => 'field_genre',
      3 => 'field_publication_date',
      4 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_about|node|related_materials|default'] = $field_group;

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
      2 => 'field_genre',
      3 => 'field_publication_date',
      4 => 'field_tags',
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
  $field_groups['group_about|node|related_materials|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_birth|node|person|default';
  $field_group->group_name = 'group_birth';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Birth',
    'weight' => '5',
    'children' => array(
      0 => 'field_birth_place',
      1 => 'field_birth_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-birth field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_birth|node|person|default'] = $field_group;

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
    'weight' => '7',
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
  $field_groups['group_birth|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_business|node|business|default';
  $field_group->group_name = 'group_business';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'business';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Business Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_website',
      1 => 'field_owned_by',
      2 => 'field_person_involved',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-business field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_business|node|business|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_death|node|person|default';
  $field_group->group_name = 'group_death';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Death',
    'weight' => '6',
    'children' => array(
      0 => 'field_death_place',
      1 => 'field_death_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-death field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_death|node|person|default'] = $field_group;

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
    'weight' => '8',
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
  $field_groups['group_death|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|business|default';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'business';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
      1 => 'field_images',
      2 => 'field_business_history',
      3 => 'field_fc_images',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-description field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_description|node|business|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|edition|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'edition';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '5',
    'children' => array(
      0 => 'field_edition',
      1 => 'field_language',
      2 => 'field_pages',
      3 => 'field_print_run',
      4 => 'field_publication_date',
      5 => 'field_size',
      6 => 'field_purchasers',
      7 => 'field_price',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-details field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_details|node|edition|default'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_edition',
      1 => 'field_language',
      2 => 'field_pages',
      3 => 'field_print_run',
      4 => 'field_publication_date',
      5 => 'field_size',
      6 => 'field_purchasers',
      7 => 'field_price',
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
  $field_groups['group_details|node|edition|form'] = $field_group;

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
    'weight' => '10',
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
  $field_groups['group_libraries|node|bp_book|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_libraries|node|edition|default';
  $field_group->group_name = 'group_libraries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'edition';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_links';
  $field_group->data = array(
    'label' => 'Libraries',
    'weight' => '10',
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
      ),
    ),
  );
  $field_groups['group_libraries|node|edition|default'] = $field_group;

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
  $field_groups['group_libraries|node|edition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_libraries|node|primary_object|default';
  $field_group->group_name = 'group_libraries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'primary_object';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Libraries',
    'weight' => '9',
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
      ),
    ),
  );
  $field_groups['group_libraries|node|primary_object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|node|edition|default';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'edition';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '4',
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
      ),
    ),
  );
  $field_groups['group_links|node|edition|default'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_illustrator',
      1 => 'field_printer',
      2 => 'field_publisher',
      3 => 'field_work',
      4 => 'field_library_identifier',
      5 => 'group_libraries',
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
  $field_groups['group_links|node|edition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_locations|node|correspondence|default';
  $field_group->group_name = 'group_locations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'correspondence';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Locations',
    'weight' => '5',
    'children' => array(
      0 => 'field_library',
      1 => 'field_link_digitized',
      2 => 'field_sent_from',
      3 => 'field_sent_to',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-locations field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_locations|node|correspondence|default'] = $field_group;

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
      0 => 'field_geocoded_from',
      1 => 'field_geocoded_to',
      2 => 'field_library',
      3 => 'field_link_digitized',
      4 => 'field_sent_from',
      5 => 'field_sent_to',
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
  $field_groups['group_locations|node|correspondence|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|work|default';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'work';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '4',
    'children' => array(
      0 => 'field_copyright_date',
      1 => 'field_copyright_status',
      2 => 'field_genre',
      3 => 'field_language',
      4 => 'field_identifier',
      5 => 'field_work_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_metadata|node|work|default'] = $field_group;

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
      0 => 'field_copyright_date',
      1 => 'field_copyright_status',
      2 => 'field_genre',
      3 => 'field_language',
      4 => 'field_identifier',
      5 => 'field_work_type',
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
  $field_groups['group_metadata|node|work|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people|node|correspondence|default';
  $field_group->group_name = 'group_people';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'correspondence';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'People',
    'weight' => '3',
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
      ),
    ),
  );
  $field_groups['group_people|node|correspondence|default'] = $field_group;

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
  $field_groups['group_people|node|correspondence|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people|node|work|default';
  $field_group->group_name = 'group_people';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'work';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'People',
    'weight' => '3',
    'children' => array(
      0 => 'field_author',
      1 => 'field_editor',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-people field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_people|node|work|default'] = $field_group;

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
      2 => 'field_translator',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'People',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_people|node|work|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_process|node|related_materials|default';
  $field_group->group_name = 'group_publication_process';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'related_materials';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publication Process',
    'weight' => '1',
    'children' => array(
      0 => 'field_material_related_to',
      1 => 'field_publication_process',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publication-process field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_publication_process|node|related_materials|default'] = $field_group;

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
      0 => 'field_material_related_to',
      1 => 'field_publication_process',
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
  $field_groups['group_publication_process|node|related_materials|form'] = $field_group;

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
    'weight' => '9',
    'children' => array(
      0 => 'field_condition',
      1 => 'field_damage',
      2 => 'field_owner',
      3 => 'field_reader',
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
  $field_groups['group_reception|node|material_expression|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reception|node|primary_object|default';
  $field_group->group_name = 'group_reception';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'primary_object';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Reception History',
    'weight' => '8',
    'children' => array(
      0 => 'field_condition',
      1 => 'field_damage',
      2 => 'field_owner',
      3 => 'field_reader',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-reception field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_reception|node|primary_object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relationships|node|business|form';
  $field_group->group_name = 'group_relationships';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'business';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relationships',
    'weight' => '11',
    'children' => array(
      0 => 'field_person_involved',
      1 => 'field_business_relationship',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-relationships field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_relationships|node|business|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resources|node|related_materials|default';
  $field_group->group_name = 'group_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'related_materials';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Resources',
    'weight' => '2',
    'children' => array(
      0 => 'field_images',
      1 => 'field_library',
      2 => 'field_link_digitized',
      3 => 'field_identifier',
      4 => 'field_fc_images',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-resources field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_resources|node|related_materials|default'] = $field_group;

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
      0 => 'field_images',
      1 => 'field_library',
      2 => 'field_link_digitized',
      3 => 'field_identifier',
      4 => 'field_fc_images',
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
  t('About');
  t('Birth');
  t('Business Information');
  t('Death');
  t('Description');
  t('Details');
  t('Libraries');
  t('Links');
  t('Locations');
  t('Metadata');
  t('People');
  t('Publication Process');
  t('Reception History');
  t('Relationships');
  t('Resources');

  return $field_groups;
}

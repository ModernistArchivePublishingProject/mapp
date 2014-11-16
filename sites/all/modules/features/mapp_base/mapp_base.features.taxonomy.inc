<?php
/**
 * @file
 * mapp_base.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mapp_base_taxonomy_default_vocabularies() {
  return array(
    'partner_type' => array(
      'name' => 'Partner Type',
      'machine_name' => 'partner_type',
      'description' => 'For organizing project partners',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}

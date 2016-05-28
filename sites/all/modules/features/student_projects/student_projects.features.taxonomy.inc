<?php
/**
 * @file
 * student_projects.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function student_projects_taxonomy_default_vocabularies() {
  return array(
    'blog_post_type' => array(
      'name' => 'Blog Post Type',
      'machine_name' => 'blog_post_type',
      'description' => 'To distinguish team blog, student projects, etc.',
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

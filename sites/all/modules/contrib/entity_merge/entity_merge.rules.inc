<?php

/**
 * Implements entity_merge_rules_action_info().
 */
function entity_merge_rules_action_info() {
  $actions = array();
  $actions['entity_merge'] = array(
    'label' => t('Merge Entities'),
    'description' => t('Initiate a merge of two entities. This operation may be completed on cron later.'),
    'group' => t('Entities'),
    'parameter' => array(
      'entity1' => array(
        'type' => 'entity',
        'label' => t('Entity 1'),
        'description' => t('The primary entity to merge.'),
        'wrapped' => TRUE,
      ),
      'entity2' => array(
        'type' => 'entity',
        'label' => t('Entity 2'),
        'description' => t('The secondary entity to merge.'),
        'wrapped' => TRUE,
      ),
    ),
    'base' => 'entity_merge_rules_action_entity_merge',
  );

  return $actions;
}

/**
 * Rules action callback for merging entities.
 */
function entity_merge_rules_action_entity_merge($entity1, $entity2) {
  if ($entity1->type() != $entity2->type()) {
    throw new RulesEvaluationException('Cannot merge two entities of different types.');
  }

  entity_merge($entity1, $entity2, $entity1->type());
}


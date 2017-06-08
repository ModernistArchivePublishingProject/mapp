<?php
/**
 * @file
 * Contains merge process for merging fields.
 */

class EntityMergeProcessMergeFields extends EntityMergeProcessBase {

  /**
   * Overrides EntityMergeProcessBase::run()
   */
  public function run() {
    list(,,$bundle) = entity_extract_ids($this->entityType, $this->targetEntity);

    $instances = field_info_instances($this->entityType, $bundle);

    foreach ($instances as $field_name => $instance) {
      $field = field_info_field($field_name);

      // Put all the field items into one items array. We make sure we don't have
      // too many items later.
      $entity1_items = is_array($this->entity1->{$field_name}) ? $this->entity1->{$field_name} : array();
      $entity2_items = is_array($this->entity2->{$field_name}) ? $this->entity2->{$field_name} : array();
      $new_items = array_merge_recursive($entity1_items, $entity2_items);

      $empty_hook = $field['module'] . '_field_is_empty';
      $empty_hook_exists = function_exists($empty_hook);

      // Set up the context for alter hooks.
      $context = array(
        'field' => $field,
        'instance' => $instance,
        'entity1' => $this->entity1,
        'entity2' => $this->entity2,
        'entity_type' => $this->entityType,
      );

      // Discard items that are empty.
      foreach ($new_items as $langcode => &$items) {
        foreach ($items as $delta => $item) {
          if (empty($item)) {
            unset($new_items[$delta]);
            continue;
          }

          if (!$empty_hook_exists) {
            continue;
          }

          if ($empty_hook($item, $field)) {
            unset($new_items[$delta]);
            continue;
          }
        }

        // Allow modules to alter the field items.
        $context['langcode'] = $langcode;
        drupal_alter('entity_merge_field_items', $items, $this->targetEntity, $context);

        // Re-index the items.
        $items = array_values($items);

        // If there are no items, remove this language.
        if (!count($items)) {
          unset($new_items[$langcode]);
        }
      }

      // Make sure we only have the right number of items.
      if ($field['cardinality'] != FIELD_CARDINALITY_UNLIMITED) {
        foreach ($new_items as &$items) {
          if (count($items) > $field['cardinality']) {
            $items = array_slice($items, 0, $field['cardinality']);
          }
        }
      }

      // Set the item array, or if empty set to NULL.
      $this->targetEntity->{$field_name} = !empty($new_items) ? $new_items : NULL;
    }
  }
}

<?php
/**
 * @file
 * nbatax.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nbatax_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_nba_search_term'
  $field_bases['field_nba_search_term'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_nba_search_term',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 30,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}

<?php
/**
 * @file
 * searchtax.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function searchtax_taxonomy_default_vocabularies() {
  return array(
    'search' => array(
      'name' => 'search',
      'machine_name' => 'search',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}

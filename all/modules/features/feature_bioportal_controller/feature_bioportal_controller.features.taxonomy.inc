<?php
/**
 * @file
 * feature_bioportal_controller.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_bioportal_controller_taxonomy_default_vocabularies() {
  return array(
    'nba2text' => array(
      'name' => 'nba2text',
      'machine_name' => 'nba2text',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'search' => array(
      'name' => 'search',
      'machine_name' => 'search',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
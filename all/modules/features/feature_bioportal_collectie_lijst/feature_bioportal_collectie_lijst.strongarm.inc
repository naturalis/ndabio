<?php
/**
 * @file
 * feature_bioportal_collectie_lijst.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_bioportal_collectie_lijst_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__naturalis_featured_content';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__naturalis_featured_content'] = $strongarm;

  return $export;
}

<?php
/**
 * @file
 * feature_bioportal_collectie_lijst.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_bioportal_collectie_lijst_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_collectie_afbeelding'.
  $field_bases['field_collectie_afbeelding'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_collectie_afbeelding',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 9,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}

<?php
/**
 * @file
 * nbatax.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nbatax_strongarm() {
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
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_naturalis_featured_content';
  $strongarm->value = '0';
  $export['language_content_type_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_naturalis_featured_content';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_naturalis_featured_content';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_naturalis_featured_content';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_naturalis_featured_content';
  $strongarm->value = '1';
  $export['node_preview_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_naturalis_featured_content';
  $strongarm->value = 0;
  $export['node_submitted_naturalis_featured_content'] = $strongarm;

  return $export;
}

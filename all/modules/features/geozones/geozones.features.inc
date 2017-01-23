<?php
/**
 * @file
 * geozones.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function geozones_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function geozones_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function geozones_node_info() {
  $items = array(
    'national_search_area' => array(
      'name' => t('Search area'),
      'base' => 'node_content',
      'description' => t('Predefined search areas to use with NDA services. Areas are defined as geoJson.'),
      'has_title' => '1',
      'title_label' => t('Locality'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

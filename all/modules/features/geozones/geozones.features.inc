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
      'name' => t('National search area'),
      'base' => 'node_content',
      'description' => t('Search areas within the Netherlands'),
      'has_title' => '1',
      'title_label' => t('Locality'),
      'help' => '',
    ),
  );
  return $items;
}

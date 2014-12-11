<?php
/**
 * @file
 * bioportal_search_log.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bioportal_search_log_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bioportal_search_log_node_info() {
  $items = array(
    'search_log' => array(
      'name' => t('Search log'),
      'base' => 'node_content',
      'description' => t('Logs fields from search form'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

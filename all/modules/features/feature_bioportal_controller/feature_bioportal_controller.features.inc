<?php
/**
 * @file
 * feature_bioportal_controller.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_bioportal_controller_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_bioportal_controller_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_bioportal_controller_node_info() {
  $items = array(
    'naturalis_featured_content' => array(
      'name' => t('Naturalis Featured content'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'naturalis_help' => array(
      'name' => t('Naturalis Help Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'naturalis_page' => array(
      'name' => t('Naturalis  Basic Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Paginatitel'),
      'help' => '',
    ),
    'naturalis_service_menu_page' => array(
      'name' => t('Naturalis  Service Menu Page'),
      'base' => 'node_content',
      'description' => t('Adds a page that will referenced to from the Service Menu in the Naturlis Bottom Bar. Typically: colofon, disclaimer, '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ndabio_header_image' => array(
      'name' => t('Bioportal Header Image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'search_log' => array(
      'name' => t('Search log'),
      'base' => 'node_content',
      'description' => t('Logs fields from search form'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

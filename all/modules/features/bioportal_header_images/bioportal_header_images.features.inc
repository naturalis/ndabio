<?php
/**
 * @file
 * bioportal_header_images.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bioportal_header_images_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function bioportal_header_images_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function bioportal_header_images_node_info() {
  $items = array(
    'ndabio_header_image' => array(
      'name' => t('Bioportal Header Image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

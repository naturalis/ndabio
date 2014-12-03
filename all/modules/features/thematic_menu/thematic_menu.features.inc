<?php
/**
 * @file
 * thematic_menu.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function thematic_menu_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function thematic_menu_node_info() {
  $items = array(
    'naturalis_featured_content' => array(
      'name' => t('Naturalis Featured content'),
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

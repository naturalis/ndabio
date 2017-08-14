<?php
/**
 * @file
 * feature_bioportal_nodes_menus.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_bioportal_nodes_menus_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

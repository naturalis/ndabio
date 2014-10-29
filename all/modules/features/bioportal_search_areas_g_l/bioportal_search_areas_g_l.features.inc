<?php
/**
 * @file
 * bioportal_search_areas_g_l.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bioportal_search_areas_g_l_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

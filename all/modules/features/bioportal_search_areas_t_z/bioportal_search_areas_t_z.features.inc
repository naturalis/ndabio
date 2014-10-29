<?php
/**
 * @file
 * bioportal_search_areas_t_z.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bioportal_search_areas_t_z_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

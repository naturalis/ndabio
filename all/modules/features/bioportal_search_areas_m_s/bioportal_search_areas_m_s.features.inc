<?php
/**
 * @file
 * bioportal_search_areas_m_s.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bioportal_search_areas_m_s_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

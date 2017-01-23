<?php
/**
 * @file
 * bioportal_nl.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bioportal_nl_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

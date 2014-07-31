<?php
/**
 * @file
 * bioportal_controller.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bioportal_controller_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

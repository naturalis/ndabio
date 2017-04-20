<?php
/**
 * @file
 * naturalis_basic_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function naturalis_basic_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

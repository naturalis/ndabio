<?php
/**
 * @file
 * bioportal_controller.box.inc
 */

/**
 * Implements hook_default_box().
 */
function bioportal_controller_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'site_explanation';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Introduction';
  $box->options = array(
    'body' => array(
      'value' => 'At Naturalis Biodiversity Center, we collect, conserve and study animals, plants, fungi, fossils and rocks. This site allows you to search through records of specimen and species descriptions collected by Naturalis and other Dutch institutions.',
      'format' => 'plain_text',
    ),
    'additional_classes' => '',
  );
  $export['site_explanation'] = $box;

  return $export;
}

<?php
/**
 * @file
 * bioportal_header_images.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bioportal_header_images_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-ndabio_header_image-field_ndabio_header_image'
  $field_instances['node-ndabio_header_image-field_ndabio_header_image'] = array(
    'bundle' => 'ndabio_header_image',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ndabio_header_image',
    'label' => 'ndabio_header_image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('ndabio_header_image');

  return $field_instances;
}

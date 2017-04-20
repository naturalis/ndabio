<?php
/**
 * @file
 * naturalis_basic_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function naturalis_basic_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-naturalis_page-field_file'.
  $field_instances['node-naturalis_page-field_file'] = array(
    'bundle' => 'naturalis_page',
    'deleted' => 0,
    'description' => 'Attached files are accessible for anyone with the direct link.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_file',
    'label' => 'Attached file(s)',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => '',
      'file_extensions' => 'gz tar zip',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Attached file(s)');
  t('Attached files are accessible for anyone with the direct link.');

  return $field_instances;
}

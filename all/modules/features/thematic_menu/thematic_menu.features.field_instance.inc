<?php
/**
 * @file
 * thematic_menu.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function thematic_menu_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-naturalis_featured_content-body'.
  $field_instances['node-naturalis_featured_content-body'] = array(
    'bundle' => 'naturalis_featured_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-naturalis_featured_content-field_nba_search_term'.
  $field_instances['node-naturalis_featured_content-field_nba_search_term'] = array(
    'bundle' => 'naturalis_featured_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This should correspond to the term send to the NBA. If a term relates to an existing node of this type the content of the node will be placed above the search results in a block.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_nba_search_term',
    'label' => 'NBA search term',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

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
  t('Body');
  t('NBA search term');
  t('This should correspond to the term send to the NBA. If a term relates to an existing node of this type the content of the node will be placed above the search results in a block.');

  return $field_instances;
}

<?php
/**
 * @file
 * bioportal_geoview.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bioportal_geoview_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'geoview';
  $context->description = '';
  $context->tag = 'geographic search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*geographic-search' => '*geographic-search',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-areas-block' => array(
          'module' => 'views',
          'delta' => 'areas-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-areas-block_1' => array(
          'module' => 'views',
          'delta' => 'areas-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-areas-block_2' => array(
          'module' => 'views',
          'delta' => 'areas-block_2',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('geographic search');
  $export['geoview'] = $context;

  return $export;
}

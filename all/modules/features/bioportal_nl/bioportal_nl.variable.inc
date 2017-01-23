<?php
/**
 * @file
 * bioportal_nl.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function bioportal_nl_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['en'] = array(
  'site_name' => 'BioPortal',
  'site_slogan' => 'Browse Dutch natural history collections',
);
  $realm_variables['language']['nl'] = array(
  'site_name' => 'BioPortal',
  'site_slogan' => 'Blader door Nederlandse natuurhistorische collecties',
);

return $realm_variables;
}

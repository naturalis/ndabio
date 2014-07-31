<?php
/**
 * @file
 * bioportal_controller.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bioportal_controller_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'search',
  );

  return $permissions;
}

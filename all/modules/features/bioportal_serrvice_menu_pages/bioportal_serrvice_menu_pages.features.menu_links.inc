<?php
/**
 * @file
 * bioportal_serrvice_menu_pages.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function bioportal_serrvice_menu_pages_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-naturalis-help-menu_help:node/2.
  $menu_links['menu-naturalis-help-menu_help:node/2'] = array(
    'menu_name' => 'menu-naturalis-help-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-naturalis-help-menu_help:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-naturalis-help-menu_help:node/3765.
  $menu_links['menu-naturalis-help-menu_help:node/3765'] = array(
    'menu_name' => 'menu-naturalis-help-menu',
    'link_path' => 'node/3765',
    'router_path' => 'node/%',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-naturalis-help-menu_help:node/3765',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Help');

  return $menu_links;
}

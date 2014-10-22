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

  // Exported menu link: menu-naturalis-service-menu_colophon:node/1663
  $menu_links['menu-naturalis-service-menu_colophon:node/1663'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'node/1663',
    'router_path' => 'node/%',
    'link_title' => 'Colophon',
    'options' => array(
      'identifier' => 'menu-naturalis-service-menu_colophon:node/1663',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-naturalis-service-menu_contact:contact
  $menu_links['menu-naturalis-service-menu_contact:contact'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-naturalis-service-menu_contact:contact',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-naturalis-service-menu_disclaimer:node/1664
  $menu_links['menu-naturalis-service-menu_disclaimer:node/1664'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'node/1664',
    'router_path' => 'node/%',
    'link_title' => 'Disclaimer',
    'options' => array(
      'identifier' => 'menu-naturalis-service-menu_disclaimer:node/1664',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Colophon');
  t('Contact');
  t('Disclaimer');


  return $menu_links;
}

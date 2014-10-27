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

  // Exported menu link: main-menu_about:node/1667
  $menu_links['main-menu_about:node/1667'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1667',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'main-menu_about:node/1667',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_for-developers:node/1666
  $menu_links['main-menu_for-developers:node/1666'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1666',
    'router_path' => 'node/%',
    'link_title' => 'For developers',
    'options' => array(
      'identifier' => 'main-menu_for-developers:node/1666',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-naturalis-service-menu_colophon:node/1663
  $menu_links['menu-naturalis-service-menu_colophon:node/1663'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'node/1663',
    'router_path' => 'node/%',
    'link_title' => 'Colophon',
    'options' => array(
      'identifier' => 'menu-naturalis-service-menu_colophon:node/1663',
      'attributes' => array(
        'title' => '',
      ),
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
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Colophon');
  t('Disclaimer');
  t('For developers');


  return $menu_links;
}

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
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_type-exemplaren:<front>
  $menu_links['main-menu_type-exemplaren:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Type-exemplaren',
    'options' => array(
      'query' => array(
        'thematic_search' => 'type_exemplaren',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_type-exemplaren:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
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
  t('About');
  t('Colophon');
  t('Contact');
  t('Disclaimer');
  t('For developers');
  t('Type-exemplaren');


  return $menu_links;
}

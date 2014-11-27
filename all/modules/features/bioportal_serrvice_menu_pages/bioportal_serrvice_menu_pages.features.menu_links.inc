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

  // Exported menu link: main-menu_about:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb
  $menu_links['main-menu_about:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb',
    'router_path' => 'uuid',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'main-menu_about:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb',
      'alter' => TRUE,
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
  );
  // Exported menu link: main-menu_over:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb
  $menu_links['main-menu_over:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb',
    'router_path' => 'uuid',
    'link_title' => 'Over',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_over:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: menu-naturalis-externe-links_naar-naturalisnl:http://www.naturalis.nl
  $menu_links['menu-naturalis-externe-links_naar-naturalisnl:http://www.naturalis.nl'] = array(
    'menu_name' => 'menu-naturalis-externe-links',
    'link_path' => 'http://www.naturalis.nl',
    'router_path' => '',
    'link_title' => 'Naar Naturalis.nl',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-naturalis-externe-links_naar-naturalisnl:http://www.naturalis.nl',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-naturalis-service-menu_colophon:uuid/node/794d5b17-da10-492e-839d-bbfce2ad70b4
  $menu_links['menu-naturalis-service-menu_colophon:uuid/node/794d5b17-da10-492e-839d-bbfce2ad70b4'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'uuid/node/794d5b17-da10-492e-839d-bbfce2ad70b4',
    'router_path' => 'uuid',
    'link_title' => 'Colophon',
    'options' => array(
      'identifier' => 'menu-naturalis-service-menu_colophon:uuid/node/794d5b17-da10-492e-839d-bbfce2ad70b4',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-naturalis-service-menu_contact:uuid/node/a2f56bf1-1289-45f2-96a5-c25a057d6679
  $menu_links['menu-naturalis-service-menu_contact:uuid/node/a2f56bf1-1289-45f2-96a5-c25a057d6679'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'uuid/node/a2f56bf1-1289-45f2-96a5-c25a057d6679',
    'router_path' => 'uuid',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-naturalis-service-menu_contact:uuid/node/a2f56bf1-1289-45f2-96a5-c25a057d6679',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-naturalis-service-menu_disclaimer:uuid/node/1dfa43fc-f62c-4d40-a016-4e4f40952954
  $menu_links['menu-naturalis-service-menu_disclaimer:uuid/node/1dfa43fc-f62c-4d40-a016-4e4f40952954'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'uuid/node/1dfa43fc-f62c-4d40-a016-4e4f40952954',
    'router_path' => 'uuid',
    'link_title' => 'Disclaimer',
    'options' => array(
      'identifier' => 'menu-naturalis-service-menu_disclaimer:uuid/node/1dfa43fc-f62c-4d40-a016-4e4f40952954',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Colophon');
  t('Contact');
  t('Disclaimer');
  t('Naar Naturalis.nl');
  t('Over');


  return $menu_links;
}

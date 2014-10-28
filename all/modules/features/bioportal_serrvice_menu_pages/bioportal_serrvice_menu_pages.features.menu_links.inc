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
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'uuid' => '9c021310-9a55-495b-b798-dbbc56a1c5bb',
    'vuuid' => 'e63ebfd4-7207-489c-9a7d-e0e88405195e',
  );
  // Exported menu link: main-menu_for-developers:uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273
  $menu_links['main-menu_for-developers:uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273',
    'router_path' => 'uuid',
    'link_title' => 'For developers',
    'options' => array(
      'identifier' => 'main-menu_for-developers:uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'uuid' => 'ee159a0a-2bc8-44bd-aac9-33ce07af5273',
    'vuuid' => 'd80e510e-2406-42aa-b88c-c925611a12ca',
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
    'customized' => 0,
    'uuid' => '794d5b17-da10-492e-839d-bbfce2ad70b4',
    'vuuid' => '101b5be0-93e3-401a-9f4b-26c191a3fe3a',
  );
  // Exported menu link: menu-naturalis-service-menu_contact:uuid/node/a2f56bf1-1289-45f2-96a5-c25a057d6679
  $menu_links['menu-naturalis-service-menu_contact:uuid/node/a2f56bf1-1289-45f2-96a5-c25a057d6679'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'uuid/node/a2f56bf1-1289-45f2-96a5-c25a057d6679',
    'router_path' => 'uuid',
    'link_title' => 'Contact',
    'options' => array(
      'identifier' => 'menu-naturalis-service-menu_contact:uuid/node/a2f56bf1-1289-45f2-96a5-c25a057d6679',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'uuid' => 'a2f56bf1-1289-45f2-96a5-c25a057d6679',
    'vuuid' => '3d1bb58c-6fc9-4510-b687-9807be997379',
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
    'customized' => 0,
    'uuid' => '1dfa43fc-f62c-4d40-a016-4e4f40952954',
    'vuuid' => '3cb3b8aa-9ab7-40b5-b5a7-44230587469e',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Colophon');
  t('Contact');
  t('Disclaimer');
  t('For developers');


  return $menu_links;
}

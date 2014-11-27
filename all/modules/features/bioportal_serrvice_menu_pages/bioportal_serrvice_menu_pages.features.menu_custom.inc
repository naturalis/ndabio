<?php
/**
 * @file
 * bioportal_serrvice_menu_pages.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bioportal_serrvice_menu_pages_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-naturalis-externe-links.
  $menus['menu-naturalis-externe-links'] = array(
    'menu_name' => 'menu-naturalis-externe-links',
    'title' => 'Naturalis Externe Links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Naturalis Externe Links');


  return $menus;
}

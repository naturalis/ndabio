<?php
/**
 * @file
 * feature_bioportal_nodes_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function feature_bioportal_nodes_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-naturalis-externe-links.
  $menus['menu-naturalis-externe-links'] = array(
    'menu_name' => 'menu-naturalis-externe-links',
    'title' => 'Naturalis Externe Links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-naturalis-help-menu.
  $menus['menu-naturalis-help-menu'] = array(
    'menu_name' => 'menu-naturalis-help-menu',
    'title' => 'Naturalis Help Menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-naturalis-language-menu.
  $menus['menu-naturalis-language-menu'] = array(
    'menu_name' => 'menu-naturalis-language-menu',
    'title' => 'Naturalis Language Menu',
    'description' => 'Provides a switch for quickly changing language',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-naturalis-service-menu.
  $menus['menu-naturalis-service-menu'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'title' => 'Naturalis Service Menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('Naturalis Externe Links');
  t('Naturalis Help Menu');
  t('Naturalis Language Menu');
  t('Naturalis Service Menu');
  t('Provides a switch for quickly changing language');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}

<?php
/**
 * @file
 * bioportal_thematic_search.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function bioportal_thematic_search_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_digital-collections:<front>
  $menu_links['main-menu_digital-collections:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Digital Collections',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_digital-collections:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_extinct:explore/extinct
  $menu_links['main-menu_extinct:explore/extinct'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/extinct',
    'router_path' => 'explore',
    'link_title' => 'Extinct',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_extinct:explore/extinct',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_glaspreparaten:explore/glas
  $menu_links['main-menu_glaspreparaten:explore/glas'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/glas',
    'router_path' => 'explore',
    'link_title' => 'Glaspreparaten',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_glaspreparaten:explore/glas',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_songbirds:explore/songbirds
  $menu_links['main-menu_songbirds:explore/songbirds'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/songbirds',
    'router_path' => 'explore',
    'link_title' => 'Songbirds',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_songbirds:explore/songbirds',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_suriname:explore/suriname
  $menu_links['main-menu_suriname:explore/suriname'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/suriname',
    'router_path' => 'explore',
    'link_title' => 'Suriname',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_suriname:explore/suriname',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_type-exemplaren:explore/type
  $menu_links['main-menu_type-exemplaren:explore/type'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/type',
    'router_path' => 'explore',
    'link_title' => 'Type-exemplaren',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_type-exemplaren:explore/type',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Digital Collections');
  t('Extinct');
  t('Glaspreparaten');
  t('Songbirds');
  t('Suriname');
  t('Type-exemplaren');


  return $menu_links;
}

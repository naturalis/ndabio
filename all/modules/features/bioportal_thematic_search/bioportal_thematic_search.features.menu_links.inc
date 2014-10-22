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
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_extinct:<front>
  $menu_links['main-menu_extinct:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Extinct',
    'options' => array(
      'query' => array(
        'thematic_search' => 'uitgestorven',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_extinct:<front>',
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
  // Exported menu link: main-menu_glaspreparaten:<front>
  $menu_links['main-menu_glaspreparaten:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Glaspreparaten',
    'options' => array(
      'query' => array(
        'thematic_search' => 'glaspreparaten',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_glaspreparaten:<front>',
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
  // Exported menu link: main-menu_songbirds:<front>
  $menu_links['main-menu_songbirds:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Songbirds',
    'options' => array(
      'query' => array(
        'thematic_search' => 'zangvogels',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_songbirds:<front>',
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
  // Exported menu link: main-menu_suriname:<front>
  $menu_links['main-menu_suriname:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Suriname',
    'options' => array(
      'query' => array(
        'thematic_search' => 'suriname',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_suriname:<front>',
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

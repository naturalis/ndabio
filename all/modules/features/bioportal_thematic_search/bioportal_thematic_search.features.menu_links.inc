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
    'parent_identifier' => 'main-menu_thematisch-zoeken:<front>',
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
    'parent_identifier' => 'main-menu_thematisch-zoeken:<front>',
  );
  // Exported menu link: main-menu_thematisch-zoeken:<front>
  $menu_links['main-menu_thematisch-zoeken:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Thematisch zoeken',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_thematisch-zoeken:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
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
    'parent_identifier' => 'main-menu_thematisch-zoeken:<front>',
  );
  // Exported menu link: main-menu_uitgestorven:<front>
  $menu_links['main-menu_uitgestorven:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Uitgestorven',
    'options' => array(
      'query' => array(
        'thematic_search' => 'uitgestorven',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_uitgestorven:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_thematisch-zoeken:<front>',
  );
  // Exported menu link: main-menu_zangvogels:<front>
  $menu_links['main-menu_zangvogels:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Zangvogels',
    'options' => array(
      'query' => array(
        'thematic_search' => 'zangvogels',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_zangvogels:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_thematisch-zoeken:<front>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Glaspreparaten');
  t('Suriname');
  t('Thematisch zoeken');
  t('Type-exemplaren');
  t('Uitgestorven');
  t('Zangvogels');


  return $menu_links;
}

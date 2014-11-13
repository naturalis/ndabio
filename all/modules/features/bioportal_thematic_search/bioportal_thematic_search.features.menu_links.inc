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

  // Exported menu link: main-menu_arts:explore/arts/Arts
  $menu_links['main-menu_arts:explore/arts/Arts'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/arts/Arts',
    'router_path' => 'explore/%/%',
    'link_title' => 'Arts',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_arts:explore/arts/Arts',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
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
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_extinct-birds:explore/extinct-birds/Extinct birds
  $menu_links['main-menu_extinct-birds:explore/extinct-birds/Extinct birds'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/extinct-birds/Extinct birds',
    'router_path' => 'explore/%/%',
    'link_title' => 'Extinct birds',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_extinct-birds:explore/extinct-birds/Extinct birds',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_martin:explore/martin/Martin collection
  $menu_links['main-menu_martin:explore/martin/Martin collection'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/martin/Martin collection',
    'router_path' => 'explore/%/%',
    'link_title' => 'Martin',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_martin:explore/martin/Martin collection',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_siebold:explore/siebold/Siebold
  $menu_links['main-menu_siebold:explore/siebold/Siebold'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/siebold/Siebold',
    'router_path' => 'explore/%/%',
    'link_title' => 'Siebold',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_siebold:explore/siebold/Siebold',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Arts');
  t('Digital Collections');
  t('Extinct birds');
  t('Martin');
  t('Siebold');


  return $menu_links;
}

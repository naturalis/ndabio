<?php
/**
 * @file
 * thematic_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function thematic_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_arts-collection:nba/result
  $menu_links['main-menu_arts-collection:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Arts collection',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_arts-collection:nba/result',
      'query' => array(
        'theme' => 'arts',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_beekbergerwoud-collectie:nba/result
  $menu_links['main-menu_beekbergerwoud-collectie:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Beekbergerwoud collectie',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_beekbergerwoud-collectie:nba/result',
      'query' => array(
        'theme' => 'beekbergerwoud',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_beekbergerwoud-collection:nba/result
  $menu_links['main-menu_beekbergerwoud-collection:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Beekbergerwoud collection',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_beekbergerwoud-collection:nba/result',
      'query' => array(
        'theme' => 'beekbergerwoud',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_bijzondere-collecties:<front>
  $menu_links['main-menu_bijzondere-collecties:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Bijzondere collecties',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_bijzondere-collecties:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_explore-highlights:<front>
  $menu_links['main-menu_explore-highlights:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Explore highlights',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_explore-highlights:<front>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_extinct-birds:nba/result
  $menu_links['main-menu_extinct-birds:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Extinct birds',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_extinct-birds:nba/result',
      'query' => array(
        'theme' => 'extinct-birds',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_martin-collectie-van-fossiele-schelpen:nba/result
  $menu_links['main-menu_martin-collectie-van-fossiele-schelpen:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Martin collectie van fossiele schelpen',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_martin-collectie-van-fossiele-schelpen:nba/result',
      'query' => array(
        'theme' => 'martin',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_martin-collection-of-fossil-shell:nba/result
  $menu_links['main-menu_martin-collection-of-fossil-shell:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Martin collection of fossil shell',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_martin-collection-of-fossil-shell:nba/result',
      'query' => array(
        'theme' => 'martin',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_prentencollectie:nba/result
  $menu_links['main-menu_prentencollectie:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Prentencollectie',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_prentencollectie:nba/result',
      'query' => array(
        'theme' => 'arts',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_siebold-collectie:nba/result
  $menu_links['main-menu_siebold-collectie:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Siebold collectie',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_siebold-collectie:nba/result',
      'query' => array(
        'theme' => 'siebold',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_siebold-collection:nba/result
  $menu_links['main-menu_siebold-collection:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Siebold collection',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_siebold-collection:nba/result',
      'query' => array(
        'theme' => 'siebold',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_uitgestorven-vogels:nba/result
  $menu_links['main-menu_uitgestorven-vogels:nba/result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nba/result',
    'router_path' => 'nba/result',
    'link_title' => 'Uitgestorven vogels',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_uitgestorven-vogels:nba/result',
      'query' => array(
        'theme' => 'extinct-birds',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Arts collection');
  t('Beekbergerwoud collectie');
  t('Beekbergerwoud collection');
  t('Bijzondere collecties');
  t('Explore highlights');
  t('Extinct birds');
  t('Martin collectie van fossiele schelpen');
  t('Martin collection of fossil shell');
  t('Prentencollectie');
  t('Siebold collectie');
  t('Siebold collection');
  t('Uitgestorven vogels');


  return $menu_links;
}

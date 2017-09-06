<?php
/**
 * @file
 * feature_bioportal_nodes_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_bioportal_nodes_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about:node/3792.
  $menu_links['main-menu_about:node/3792'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3792',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_about:node/3792',
      'node_type' => 'naturalis_page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_api:node/3791.
  $menu_links['main-menu_api:node/3791'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3791',
    'router_path' => 'node/%',
    'link_title' => 'API',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_api:node/3791',
      'node_type' => 'naturalis_page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_api:node/3794.
  $menu_links['main-menu_api:node/3794'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3794',
    'router_path' => 'node/%',
    'link_title' => 'API',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_api:node/3794',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_arts-collection:result.
  $menu_links['main-menu_arts-collection:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Arts collection',
    'options' => array(
      'query' => array(
        'theme' => 'arts',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_arts-collection:result',
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
  // Exported menu link: main-menu_beekbergerwoud-collection:result.
  $menu_links['main-menu_beekbergerwoud-collection:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Beekbergerwoud collection',
    'options' => array(
      'query' => array(
        'theme' => 'beekbergerwoud',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_beekbergerwoud-collection:result',
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
  // Exported menu link: main-menu_beekbergerwoudcollectie:result.
  $menu_links['main-menu_beekbergerwoudcollectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Beekbergerwoudcollectie',
    'options' => array(
      'query' => array(
        'theme' => 'beekbergerwoud',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_beekbergerwoudcollectie:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_bijzondere-collecties:<front>.
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
  // Exported menu link: main-menu_dashboard:dashboard.
  $menu_links['main-menu_dashboard:dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_dashboard:dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_data-sets:node/3790.
  $menu_links['main-menu_data-sets:node/3790'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3790',
    'router_path' => 'node/%',
    'link_title' => 'Data sets',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_data-sets:node/3790',
      'node_type' => 'naturalis_page',
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
  );
  // Exported menu link: main-menu_datasets:node/3810.
  $menu_links['main-menu_datasets:node/3810'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3810',
    'router_path' => 'node/%',
    'link_title' => 'Datasets',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'node_type' => 'naturalis_page',
      'identifier' => 'main-menu_datasets:node/3810',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_dubois-collection:result.
  $menu_links['main-menu_dubois-collection:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Dubois collection',
    'options' => array(
      'query' => array(
        'theme' => 'dubois',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_dubois-collection:result',
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
  // Exported menu link: main-menu_duboiscollectie:result.
  $menu_links['main-menu_duboiscollectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Duboiscollectie',
    'options' => array(
      'query' => array(
        'theme' => 'dubois',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_duboiscollectie:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_explore-highlights:<front>.
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
  // Exported menu link: main-menu_extinct-birds:result.
  $menu_links['main-menu_extinct-birds:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Extinct birds',
    'options' => array(
      'query' => array(
        'theme' => 'extinct-birds',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_extinct-birds:result',
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
  // Exported menu link: main-menu_jongmans-collection:result.
  $menu_links['main-menu_jongmans-collection:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Jongmans collection',
    'options' => array(
      'query' => array(
        'theme' => 'jongmans',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_jongmans-collection:result',
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
  // Exported menu link: main-menu_jongmanscollectie:result.
  $menu_links['main-menu_jongmanscollectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Jongmanscollectie',
    'options' => array(
      'query' => array(
        'theme' => 'jongmans',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_jongmanscollectie:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_mammoetcollectie:result.
  $menu_links['main-menu_mammoetcollectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Mammoetcollectie',
    'options' => array(
      'query' => array(
        'theme' => 'mammoth',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_mammoetcollectie:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_mammoth-collection:result.
  $menu_links['main-menu_mammoth-collection:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Mammoth collection',
    'options' => array(
      'query' => array(
        'theme' => 'mammoth',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_mammoth-collection:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_martin-collection:result.
  $menu_links['main-menu_martin-collection:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Martin collection',
    'options' => array(
      'query' => array(
        'theme' => 'martin',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_martin-collection:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_martincollectie:result.
  $menu_links['main-menu_martincollectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Martincollectie',
    'options' => array(
      'query' => array(
        'theme' => 'martin',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_martincollectie:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_meteorietencollectie:result.
  $menu_links['main-menu_meteorietencollectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Meteorietencollectie',
    'options' => array(
      'query' => array(
        'theme' => 'meteorites',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_meteorietencollectie:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_meteorite-collection:result.
  $menu_links['main-menu_meteorite-collection:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Meteorite collection',
    'options' => array(
      'query' => array(
        'theme' => 'meteorites',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_meteorite-collection:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_over:node/3793.
  $menu_links['main-menu_over:node/3793'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3793',
    'router_path' => 'node/%',
    'link_title' => 'Over',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_over:node/3793',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_prentencollectie:result.
  $menu_links['main-menu_prentencollectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Prentencollectie',
    'options' => array(
      'query' => array(
        'theme' => 'arts',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_prentencollectie:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_siebold-collection:result.
  $menu_links['main-menu_siebold-collection:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Siebold collection',
    'options' => array(
      'query' => array(
        'theme' => 'siebold',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_siebold-collection:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_sieboldcollectie:result.
  $menu_links['main-menu_sieboldcollectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Sieboldcollectie',
    'options' => array(
      'query' => array(
        'theme' => 'siebold',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_sieboldcollectie:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_timor-collection:result.
  $menu_links['main-menu_timor-collection:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Timor collection',
    'options' => array(
      'query' => array(
        'theme' => 'timor',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_timor-collection:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_timorcollectie:result.
  $menu_links['main-menu_timorcollectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Timorcollectie',
    'options' => array(
      'query' => array(
        'theme' => 'timor',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_timorcollectie:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_uitgestorven-vogels:result.
  $menu_links['main-menu_uitgestorven-vogels:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Uitgestorven vogels',
    'options' => array(
      'query' => array(
        'theme' => 'extinct-birds',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_uitgestorven-vogels:result',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: menu-naturalis-externe-links_naturalisnl:https://www.naturalis.nl/en/.
  $menu_links['menu-naturalis-externe-links_naturalisnl:https://www.naturalis.nl/en/'] = array(
    'menu_name' => 'menu-naturalis-externe-links',
    'link_path' => 'https://www.naturalis.nl/en/',
    'router_path' => '',
    'link_title' => 'Naturalis.nl',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-naturalis-externe-links_naturalisnl:https://www.naturalis.nl/en/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-naturalis-externe-links_naturalisnl:https://www.naturalis.nl/nl/.
  $menu_links['menu-naturalis-externe-links_naturalisnl:https://www.naturalis.nl/nl/'] = array(
    'menu_name' => 'menu-naturalis-externe-links',
    'link_path' => 'https://www.naturalis.nl/nl/',
    'router_path' => '',
    'link_title' => 'Naturalis.nl',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-naturalis-externe-links_naturalisnl:https://www.naturalis.nl/nl/',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-naturalis-help-menu_help:node/2.
  $menu_links['menu-naturalis-help-menu_help:node/2'] = array(
    'menu_name' => 'menu-naturalis-help-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-naturalis-help-menu_help:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-naturalis-help-menu_help:node/3765.
  $menu_links['menu-naturalis-help-menu_help:node/3765'] = array(
    'menu_name' => 'menu-naturalis-help-menu',
    'link_path' => 'node/3765',
    'router_path' => 'node/%',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-naturalis-help-menu_help:node/3765',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-naturalis-language-menu_en:<front>.
  $menu_links['menu-naturalis-language-menu_en:<front>'] = array(
    'menu_name' => 'menu-naturalis-language-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'EN',
    'options' => array(
      'query' => array(
        'language' => 'en',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-naturalis-language-menu_en:<front>',
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
  // Exported menu link: menu-naturalis-language-menu_nl:<front>.
  $menu_links['menu-naturalis-language-menu_nl:<front>'] = array(
    'menu_name' => 'menu-naturalis-language-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'NL',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'query' => array(
        'language' => 'nl',
      ),
      'identifier' => 'menu-naturalis-language-menu_nl:<front>',
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
  // Exported menu link: menu-naturalis-service-menu_colofon:node/3798.
  $menu_links['menu-naturalis-service-menu_colofon:node/3798'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'node/3798',
    'router_path' => 'node/%',
    'link_title' => 'Colofon',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-naturalis-service-menu_colofon:node/3798',
      'node_type' => 'naturalis_service_menu_page',
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
  );
  // Exported menu link: menu-naturalis-service-menu_colophon:node/3797.
  $menu_links['menu-naturalis-service-menu_colophon:node/3797'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'node/3797',
    'router_path' => 'node/%',
    'link_title' => 'Colophon',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-naturalis-service-menu_colophon:node/3797',
      'node_type' => 'naturalis_service_menu_page',
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
  );
  // Exported menu link: menu-naturalis-service-menu_contact:node/3626.
  $menu_links['menu-naturalis-service-menu_contact:node/3626'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'node/3626',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'node_type' => 'naturalis_service_menu_page',
      'identifier' => 'menu-naturalis-service-menu_contact:node/3626',
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
  );
  // Exported menu link: menu-naturalis-service-menu_contact:node/6.
  $menu_links['menu-naturalis-service-menu_contact:node/6'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'node_type' => 'naturalis_service_menu_page',
      'identifier' => 'menu-naturalis-service-menu_contact:node/6',
      'alter' => TRUE,
      'attributes' => array(),
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
  );
  // Exported menu link: menu-naturalis-service-menu_disclaimer:node/1.
  $menu_links['menu-naturalis-service-menu_disclaimer:node/1'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Disclaimer',
    'options' => array(
      'node_type' => 'naturalis_service_menu_page',
      'identifier' => 'menu-naturalis-service-menu_disclaimer:node/1',
      'alter' => TRUE,
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
  );
  // Exported menu link: menu-naturalis-service-menu_disclaimer:node/3401.
  $menu_links['menu-naturalis-service-menu_disclaimer:node/3401'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
    'link_path' => 'node/3401',
    'router_path' => 'node/%',
    'link_title' => 'Disclaimer',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-naturalis-service-menu_disclaimer:node/3401',
      'node_type' => 'naturalis_service_menu_page',
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
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('API');
  t('About');
  t('Arts collection');
  t('Beekbergerwoud collection');
  t('Beekbergerwoudcollectie');
  t('Bijzondere collecties');
  t('Colofon');
  t('Colophon');
  t('Contact');
  t('Dashboard');
  t('Data sets');
  t('Datasets');
  t('Disclaimer');
  t('Dubois collection');
  t('Duboiscollectie');
  t('EN');
  t('Explore highlights');
  t('Extinct birds');
  t('Help');
  t('Jongmans collection');
  t('Jongmanscollectie');
  t('Mammoetcollectie');
  t('Mammoth collection');
  t('Martin collection');
  t('Martincollectie');
  t('Meteorietencollectie');
  t('Meteorite collection');
  t('NL');
  t('Naturalis.nl');
  t('Over');
  t('Prentencollectie');
  t('Siebold collection');
  t('Sieboldcollectie');
  t('Timor collection');
  t('Timorcollectie');
  t('Uitgestorven vogels');

  return $menu_links;
}

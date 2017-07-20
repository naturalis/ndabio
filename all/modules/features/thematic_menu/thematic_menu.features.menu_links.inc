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

  // Exported menu link: main-menu_about:node/3792.
  $menu_links['main-menu_about:node/3792'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3792',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_about:node/3792',
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
  // Exported menu link: main-menu_api:node/3791.
  $menu_links['main-menu_api:node/3791'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3791',
    'router_path' => 'node/%',
    'link_title' => 'API',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_api:node/3791',
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
    'weight' => 0,
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
    'weight' => -46,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
  );
  // Exported menu link: main-menu_beekbergerwoud-collectie:result.
  $menu_links['main-menu_beekbergerwoud-collectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Beekbergerwoud collectie',
    'options' => array(
      'query' => array(
        'theme' => 'beekbergerwoud',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_beekbergerwoud-collectie:result',
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
    'weight' => -44,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
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
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_data-sets:node/3790',
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
  // Exported menu link: main-menu_datasets:node/3795.
  $menu_links['main-menu_datasets:node/3795'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3795',
    'router_path' => 'node/%',
    'link_title' => 'Datasets',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_datasets:node/3795',
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
    'weight' => -50,
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
    'weight' => 0,
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
    'weight' => -46,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );
  // Exported menu link: main-menu_siebold-collectie:result.
  $menu_links['main-menu_siebold-collectie:result'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'result',
    'router_path' => 'result',
    'link_title' => 'Siebold collectie',
    'options' => array(
      'query' => array(
        'theme' => 'siebold',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_siebold-collectie:result',
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
    'weight' => -48,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_explore-highlights:<front>',
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
    'weight' => -50,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_bijzondere-collecties:<front>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('API');
  t('About');
  t('Arts collection');
  t('Beekbergerwoud collectie');
  t('Beekbergerwoud collection');
  t('Bijzondere collecties');
  t('Dashboard');
  t('Data sets');
  t('Datasets');
  t('Explore highlights');
  t('Extinct birds');
  t('Over');
  t('Prentencollectie');
  t('Siebold collectie');
  t('Siebold collection');
  t('Uitgestorven vogels');

  return $menu_links;
}

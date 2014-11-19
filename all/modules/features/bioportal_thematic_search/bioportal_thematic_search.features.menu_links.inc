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

  // Exported menu link: main-menu_about:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb
  $menu_links['main-menu_about:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb',
    'router_path' => 'uuid',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'main-menu_about:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb',
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
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
    'uuid' => '9c021310-9a55-495b-b798-dbbc56a1c5bb',
    'vuuid' => '87c35120-e8ca-40cd-abbc-2cf82838c358',
  );
  // Exported menu link: main-menu_arts-collection:explore/arts/Arts collection
  $menu_links['main-menu_arts-collection:explore/arts/Arts collection'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/arts/Arts collection',
    'router_path' => 'explore/%/%',
    'link_title' => 'Arts collection',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_arts-collection:explore/arts/Arts collection',
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
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_beekbergerwoud-collectie:explore/beekbergerwoud/Beekbergerwoud collectie
  $menu_links['main-menu_beekbergerwoud-collectie:explore/beekbergerwoud/Beekbergerwoud collectie'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/beekbergerwoud/Beekbergerwoud collectie',
    'router_path' => 'explore/%/%',
    'link_title' => 'Beekbergerwoud collectie',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_beekbergerwoud-collectie:explore/beekbergerwoud/Beekbergerwoud collectie',
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
    'parent_identifier' => 'main-menu_digitale-collecties:<front>',
  );
  // Exported menu link: main-menu_beekbergerwoud-collection:explore/beekbergerwoud/Beekbergerwoud collection
  $menu_links['main-menu_beekbergerwoud-collection:explore/beekbergerwoud/Beekbergerwoud collection'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/beekbergerwoud/Beekbergerwoud collection',
    'router_path' => 'explore/%/%',
    'link_title' => 'Beekbergerwoud collection',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_beekbergerwoud-collection:explore/beekbergerwoud/Beekbergerwoud collection',
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
  // Exported menu link: main-menu_digitale-collecties:<front>
  $menu_links['main-menu_digitale-collecties:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Digitale Collecties',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_digitale-collecties:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'nl',
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
    'weight' => -50,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_for-developers:uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273
  $menu_links['main-menu_for-developers:uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273',
    'router_path' => 'uuid',
    'link_title' => 'For developers',
    'options' => array(
      'identifier' => 'main-menu_for-developers:uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273',
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
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
    'uuid' => 'ee159a0a-2bc8-44bd-aac9-33ce07af5273',
    'vuuid' => 'b68516bb-5f66-4a36-90e1-45faaa66a706',
  );
  // Exported menu link: main-menu_martin-collectie-van-fossiele-schelpen:explore/martin/Martin collectie van fossiele schelpen
  $menu_links['main-menu_martin-collectie-van-fossiele-schelpen:explore/martin/Martin collectie van fossiele schelpen'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/martin/Martin collectie van fossiele schelpen',
    'router_path' => 'explore/%/%',
    'link_title' => 'Martin collectie van fossiele schelpen',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_martin-collectie-van-fossiele-schelpen:explore/martin/Martin collectie van fossiele schelpen',
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
    'parent_identifier' => 'main-menu_digitale-collecties:<front>',
  );
  // Exported menu link: main-menu_martin-collection-of-fossil-shell:explore/martin/Martin collection of fossil shell
  $menu_links['main-menu_martin-collection-of-fossil-shell:explore/martin/Martin collection of fossil shell'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/martin/Martin collection of fossil shell',
    'router_path' => 'explore/%/%',
    'link_title' => 'Martin collection of fossil shell',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_martin-collection-of-fossil-shell:explore/martin/Martin collection of fossil shell',
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
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_over:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb
  $menu_links['main-menu_over:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb',
    'router_path' => 'uuid',
    'link_title' => 'Over',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_over:uuid/node/9c021310-9a55-495b-b798-dbbc56a1c5bb',
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
    'uuid' => '9c021310-9a55-495b-b798-dbbc56a1c5bb',
    'vuuid' => '87c35120-e8ca-40cd-abbc-2cf82838c358',
  );
  // Exported menu link: main-menu_prentencollectie:explore/arts/Prentencollectie
  $menu_links['main-menu_prentencollectie:explore/arts/Prentencollectie'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/arts/Prentencollectie',
    'router_path' => 'explore/%/%',
    'link_title' => 'Prentencollectie',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_prentencollectie:explore/arts/Prentencollectie',
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
    'parent_identifier' => 'main-menu_digitale-collecties:<front>',
  );
  // Exported menu link: main-menu_siebold-collectie:explore/siebold/Siebold collectie
  $menu_links['main-menu_siebold-collectie:explore/siebold/Siebold collectie'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/siebold/Siebold collectie',
    'router_path' => 'explore/%/%',
    'link_title' => 'Siebold collectie',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_siebold-collectie:explore/siebold/Siebold collectie',
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
    'parent_identifier' => 'main-menu_digitale-collecties:<front>',
  );
  // Exported menu link: main-menu_siebold-collection:explore/siebold/Siebold collection
  $menu_links['main-menu_siebold-collection:explore/siebold/Siebold collection'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/siebold/Siebold collection',
    'router_path' => 'explore/%/%',
    'link_title' => 'Siebold collection',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_siebold-collection:explore/siebold/Siebold collection',
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
    'parent_identifier' => 'main-menu_digital-collections:<front>',
  );
  // Exported menu link: main-menu_uitgestorven-vogels:explore/extinct-birds/Uitgestorven vogels
  $menu_links['main-menu_uitgestorven-vogels:explore/extinct-birds/Uitgestorven vogels'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explore/extinct-birds/Uitgestorven vogels',
    'router_path' => 'explore/%/%',
    'link_title' => 'Uitgestorven vogels',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_uitgestorven-vogels:explore/extinct-birds/Uitgestorven vogels',
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
    'parent_identifier' => 'main-menu_digitale-collecties:<front>',
  );
  // Exported menu link: main-menu_voor-ontwikkelaars:uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273
  $menu_links['main-menu_voor-ontwikkelaars:uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273',
    'router_path' => 'uuid',
    'link_title' => 'Voor ontwikkelaars',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_voor-ontwikkelaars:uuid/node/ee159a0a-2bc8-44bd-aac9-33ce07af5273',
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
    'uuid' => 'ee159a0a-2bc8-44bd-aac9-33ce07af5273',
    'vuuid' => 'b68516bb-5f66-4a36-90e1-45faaa66a706',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Arts collection');
  t('Beekbergerwoud collectie');
  t('Beekbergerwoud collection');
  t('Digital Collections');
  t('Digitale Collecties');
  t('Extinct birds');
  t('For developers');
  t('Martin collectie van fossiele schelpen');
  t('Martin collection of fossil shell');
  t('Over');
  t('Prentencollectie');
  t('Siebold collectie');
  t('Siebold collection');
  t('Uitgestorven vogels');
  t('Voor ontwikkelaars');


  return $menu_links;
}

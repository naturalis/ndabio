<?php
/**
 * @file
 * feature_bioportal_nodes_menus.features.uuid_features_menu.inc
 */

/**
 * Implements hook_menu_default_uuid_features_menu().
 */
function feature_bioportal_nodes_menus_menu_default_uuid_features_menu() {
  $menu_uuid_links = array();

  // Exported menu link: 03e550c3-3b2c-4834-b1d7-e347027279bc
  $menu_uuid_links['03e550c3-3b2c-4834-b1d7-e347027279bc'] = array(
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
    'uuid' => '03e550c3-3b2c-4834-b1d7-e347027279bc',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: 0fa7b9b3-95ab-49e2-b8ce-b64be7b54033
  $menu_uuid_links['0fa7b9b3-95ab-49e2-b8ce-b64be7b54033'] = array(
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
    'uuid' => '0fa7b9b3-95ab-49e2-b8ce-b64be7b54033',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: 219ce88e-87c5-4bf9-8e31-db6762ff03ce
  $menu_uuid_links['219ce88e-87c5-4bf9-8e31-db6762ff03ce'] = array(
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
    'uuid' => '219ce88e-87c5-4bf9-8e31-db6762ff03ce',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: 21ff32d3-e03f-40e5-b1aa-cb6161d3cfa4
  $menu_uuid_links['21ff32d3-e03f-40e5-b1aa-cb6161d3cfa4'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
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
    'uuid' => '21ff32d3-e03f-40e5-b1aa-cb6161d3cfa4',
    'uuid_path' => 'node/4514bac5-0a1e-4989-ad4a-97a99e38a28c',
  );
  // Exported menu link: 291f4217-acf7-4127-8a4b-6217773f6229
  $menu_uuid_links['291f4217-acf7-4127-8a4b-6217773f6229'] = array(
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
    'uuid' => '291f4217-acf7-4127-8a4b-6217773f6229',
  );
  // Exported menu link: 316631a8-00a5-48b6-b716-177a5807dc21
  $menu_uuid_links['316631a8-00a5-48b6-b716-177a5807dc21'] = array(
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
    'uuid' => '316631a8-00a5-48b6-b716-177a5807dc21',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: 325874cc-09ec-4414-b465-b06315aaba5c
  $menu_uuid_links['325874cc-09ec-4414-b465-b06315aaba5c'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
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
    'uuid' => '325874cc-09ec-4414-b465-b06315aaba5c',
    'uuid_path' => 'node/1dfa43fc-f62c-4d40-a016-4e4f40952954',
  );
  // Exported menu link: 3a4176b6-8ab2-4225-8854-e8cb493de559
  $menu_uuid_links['3a4176b6-8ab2-4225-8854-e8cb493de559'] = array(
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
    'uuid' => '3a4176b6-8ab2-4225-8854-e8cb493de559',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: 40e0c405-e144-42e3-998c-837fe8d64f52
  $menu_uuid_links['40e0c405-e144-42e3-998c-837fe8d64f52'] = array(
    'menu_name' => 'menu-naturalis-help-menu',
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
    'uuid' => '40e0c405-e144-42e3-998c-837fe8d64f52',
    'uuid_path' => 'node/3fbad984-3780-4e5e-b2a9-71488272d5b7',
  );
  // Exported menu link: 4117f8e3-1283-44ff-b707-91d53bcb4e78
  $menu_uuid_links['4117f8e3-1283-44ff-b707-91d53bcb4e78'] = array(
    'menu_name' => 'main-menu',
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
    'uuid' => '4117f8e3-1283-44ff-b707-91d53bcb4e78',
    'uuid_path' => 'node/4b62ec6d-1a70-4ee6-8b10-7d0cba0e2bc9',
  );
  // Exported menu link: 439b5b0f-aae5-47ca-b0da-510a2e3e2f61
  $menu_uuid_links['439b5b0f-aae5-47ca-b0da-510a2e3e2f61'] = array(
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
    'uuid' => '439b5b0f-aae5-47ca-b0da-510a2e3e2f61',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: 4905d5e7-0aea-45fd-ba62-dfc69c03e7b9
  $menu_uuid_links['4905d5e7-0aea-45fd-ba62-dfc69c03e7b9'] = array(
    'menu_name' => 'main-menu',
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
    'uuid' => '4905d5e7-0aea-45fd-ba62-dfc69c03e7b9',
    'uuid_path' => 'node/40aaf623-f183-4bc3-a362-5dedaf994571',
  );
  // Exported menu link: 49a40633-db0d-480e-9990-a8aa4203dd79
  $menu_uuid_links['49a40633-db0d-480e-9990-a8aa4203dd79'] = array(
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
    'uuid' => '49a40633-db0d-480e-9990-a8aa4203dd79',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: 5157369f-cf42-40ed-9629-9c1c3c666552
  $menu_uuid_links['5157369f-cf42-40ed-9629-9c1c3c666552'] = array(
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
    'uuid' => '5157369f-cf42-40ed-9629-9c1c3c666552',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: 585b2390-fedc-4b0e-84bd-6b2017fb265b
  $menu_uuid_links['585b2390-fedc-4b0e-84bd-6b2017fb265b'] = array(
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
    'uuid' => '585b2390-fedc-4b0e-84bd-6b2017fb265b',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: 5ce2fb4f-3039-4ea7-9404-7ee189e55cc0
  $menu_uuid_links['5ce2fb4f-3039-4ea7-9404-7ee189e55cc0'] = array(
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
    'uuid' => '5ce2fb4f-3039-4ea7-9404-7ee189e55cc0',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: 66802e78-0e08-4a88-b138-f0d61e52b9f5
  $menu_uuid_links['66802e78-0e08-4a88-b138-f0d61e52b9f5'] = array(
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
    'uuid' => '66802e78-0e08-4a88-b138-f0d61e52b9f5',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: 6f5fb969-d53c-4ee6-9822-ad09085401ac
  $menu_uuid_links['6f5fb969-d53c-4ee6-9822-ad09085401ac'] = array(
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
    'uuid' => '6f5fb969-d53c-4ee6-9822-ad09085401ac',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: 81ddacab-db3a-4a96-80ae-4ff57fe0ec8d
  $menu_uuid_links['81ddacab-db3a-4a96-80ae-4ff57fe0ec8d'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'uuid' => '81ddacab-db3a-4a96-80ae-4ff57fe0ec8d',
  );
  // Exported menu link: 86f871d4-29cc-4586-8ff8-2046f82505e8
  $menu_uuid_links['86f871d4-29cc-4586-8ff8-2046f82505e8'] = array(
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
    'uuid' => '86f871d4-29cc-4586-8ff8-2046f82505e8',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: 87812cd2-8a6c-4811-9ba7-90bfa8d22f72
  $menu_uuid_links['87812cd2-8a6c-4811-9ba7-90bfa8d22f72'] = array(
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
    'uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: 8d4937b3-c429-4345-8140-6f09b7512199
  $menu_uuid_links['8d4937b3-c429-4345-8140-6f09b7512199'] = array(
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
    'uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: 92d40877-0c84-4981-91d0-5c94443f0204
  $menu_uuid_links['92d40877-0c84-4981-91d0-5c94443f0204'] = array(
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
    'uuid' => '92d40877-0c84-4981-91d0-5c94443f0204',
  );
  // Exported menu link: 9419fe33-c2c3-446a-8a24-1207b6f63c16
  $menu_uuid_links['9419fe33-c2c3-446a-8a24-1207b6f63c16'] = array(
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
    'uuid' => '9419fe33-c2c3-446a-8a24-1207b6f63c16',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: 9455a85f-c86a-4d1f-8f3c-6d76bb8a9498
  $menu_uuid_links['9455a85f-c86a-4d1f-8f3c-6d76bb8a9498'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
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
    'uuid' => '9455a85f-c86a-4d1f-8f3c-6d76bb8a9498',
    'uuid_path' => 'node/a2f56bf1-1289-45f2-96a5-c25a057d6679',
  );
  // Exported menu link: 984066d7-dfe9-4fda-97cb-c095e0b47478
  $menu_uuid_links['984066d7-dfe9-4fda-97cb-c095e0b47478'] = array(
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
    'uuid' => '984066d7-dfe9-4fda-97cb-c095e0b47478',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: 99cbc1f2-d29e-499a-b3ca-e72388d0da2a
  $menu_uuid_links['99cbc1f2-d29e-499a-b3ca-e72388d0da2a'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/help',
    'router_path' => 'admin/help',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => 'Reference for usage, configuration, and modules.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'uuid' => '99cbc1f2-d29e-499a-b3ca-e72388d0da2a',
    'parent_uuid' => 'dcf4cd2d-a8c4-4ad5-b21a-f15bfe7d3964',
  );
  // Exported menu link: ad90c2e0-a764-42cf-a677-91de3260c9b4
  $menu_uuid_links['ad90c2e0-a764-42cf-a677-91de3260c9b4'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
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
    'uuid' => 'ad90c2e0-a764-42cf-a677-91de3260c9b4',
    'uuid_path' => 'node/3e237a01-bd06-477b-a693-da1c7686f9f1',
  );
  // Exported menu link: b107bc47-a60d-4de8-aac2-e174a889921e
  $menu_uuid_links['b107bc47-a60d-4de8-aac2-e174a889921e'] = array(
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
    'uuid' => 'b107bc47-a60d-4de8-aac2-e174a889921e',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: b90d959a-1ae3-42ac-b0e1-84724e70d478
  $menu_uuid_links['b90d959a-1ae3-42ac-b0e1-84724e70d478'] = array(
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
    'uuid' => 'b90d959a-1ae3-42ac-b0e1-84724e70d478',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: c642405a-6a88-4b78-b13e-c1835d9d1414
  $menu_uuid_links['c642405a-6a88-4b78-b13e-c1835d9d1414'] = array(
    'menu_name' => 'main-menu',
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
    'uuid' => 'c642405a-6a88-4b78-b13e-c1835d9d1414',
    'uuid_path' => 'node/046583ea-ed92-4f82-9641-f2821bea952a',
  );
  // Exported menu link: cb5bfc72-c588-4618-8107-3861a3d3c79e
  $menu_uuid_links['cb5bfc72-c588-4618-8107-3861a3d3c79e'] = array(
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
    'uuid' => 'cb5bfc72-c588-4618-8107-3861a3d3c79e',
  );
  // Exported menu link: cd81e3ea-9bd2-4d29-8c34-5b3b3a9f7f13
  $menu_uuid_links['cd81e3ea-9bd2-4d29-8c34-5b3b3a9f7f13'] = array(
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
    'uuid' => 'cd81e3ea-9bd2-4d29-8c34-5b3b3a9f7f13',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: cda6eb29-347b-41f3-b657-9c85a5c93d77
  $menu_uuid_links['cda6eb29-347b-41f3-b657-9c85a5c93d77'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
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
    'uuid' => 'cda6eb29-347b-41f3-b657-9c85a5c93d77',
    'uuid_path' => 'node/7c8af603-88eb-418e-a735-6822dd7fe7f0',
  );
  // Exported menu link: d0672b67-b806-4d75-a3f5-3f4265f062ed
  $menu_uuid_links['d0672b67-b806-4d75-a3f5-3f4265f062ed'] = array(
    'menu_name' => 'main-menu',
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
    'uuid' => 'd0672b67-b806-4d75-a3f5-3f4265f062ed',
    'uuid_path' => 'node/400c73b8-5ad3-44eb-a513-c019e8ef8fce',
  );
  // Exported menu link: d1e09642-24f2-4408-a609-4278f02c7445
  $menu_uuid_links['d1e09642-24f2-4408-a609-4278f02c7445'] = array(
    'menu_name' => 'main-menu',
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
    'uuid' => 'd1e09642-24f2-4408-a609-4278f02c7445',
    'uuid_path' => 'node/e96f0452-3460-4202-964f-9451ae5a7aa9',
  );
  // Exported menu link: d23b1463-7173-4846-899c-a30fd145e725
  $menu_uuid_links['d23b1463-7173-4846-899c-a30fd145e725'] = array(
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
    'uuid' => 'd23b1463-7173-4846-899c-a30fd145e725',
    'parent_uuid' => '87812cd2-8a6c-4811-9ba7-90bfa8d22f72',
  );
  // Exported menu link: d65ffe53-ed2d-4681-a115-0900dfe46b1a
  $menu_uuid_links['d65ffe53-ed2d-4681-a115-0900dfe46b1a'] = array(
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
    'uuid' => 'd65ffe53-ed2d-4681-a115-0900dfe46b1a',
    'parent_uuid' => '8d4937b3-c429-4345-8140-6f09b7512199',
  );
  // Exported menu link: d67e98d5-05cb-4a4e-bf23-2e2cad1fdc9c
  $menu_uuid_links['d67e98d5-05cb-4a4e-bf23-2e2cad1fdc9c'] = array(
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
    'uuid' => 'd67e98d5-05cb-4a4e-bf23-2e2cad1fdc9c',
  );
  // Exported menu link: db8a6bec-dba3-4c6b-a8bc-446606f445f5
  $menu_uuid_links['db8a6bec-dba3-4c6b-a8bc-446606f445f5'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/views-plugins',
    'router_path' => 'admin/reports/views-plugins',
    'link_title' => 'Views plugins',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of plugins used in all views.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid' => 'db8a6bec-dba3-4c6b-a8bc-446606f445f5',
    'parent_uuid' => '0d641b0a-250c-409a-adee-78328e8fca97',
  );
  // Exported menu link: e1665b85-a93a-4c93-b81e-0b0e39a4b261
  $menu_uuid_links['e1665b85-a93a-4c93-b81e-0b0e39a4b261'] = array(
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
    'uuid' => 'e1665b85-a93a-4c93-b81e-0b0e39a4b261',
  );
  // Exported menu link: ec4cc0b3-3786-4dd2-b91a-0b0f457f7613
  $menu_uuid_links['ec4cc0b3-3786-4dd2-b91a-0b0f457f7613'] = array(
    'menu_name' => 'menu-naturalis-help-menu',
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
    'uuid' => 'ec4cc0b3-3786-4dd2-b91a-0b0f457f7613',
    'uuid_path' => 'node/f5db4539-d3d6-4008-8725-ad5156f4be66',
  );
  // Exported menu link: ee82418c-4ccc-4a44-a2e1-80f1935cf1a4
  $menu_uuid_links['ee82418c-4ccc-4a44-a2e1-80f1935cf1a4'] = array(
    'menu_name' => 'main-menu',
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
    'uuid' => 'ee82418c-4ccc-4a44-a2e1-80f1935cf1a4',
    'uuid_path' => 'node/7b5e25e8-c9cb-49c0-b450-5d403222a1cc',
  );
  // Exported menu link: f6d5efe2-18fd-444a-a1a0-0967044cdd24
  $menu_uuid_links['f6d5efe2-18fd-444a-a1a0-0967044cdd24'] = array(
    'menu_name' => 'menu-naturalis-service-menu',
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
    'uuid' => 'f6d5efe2-18fd-444a-a1a0-0967044cdd24',
    'uuid_path' => 'node/794d5b17-da10-492e-839d-bbfce2ad70b4',
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
  t('Views plugins');

  return $menu_uuid_links;
}

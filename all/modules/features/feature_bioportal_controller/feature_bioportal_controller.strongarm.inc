<?php
/**
 * @file
 * feature_bioportal_controller.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_bioportal_controller_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__search_log';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => 2,
        ),
        'title' => array(
          'weight' => 0,
        ),
        'path' => array(
          'weight' => 1,
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__search_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_naturalis_featured_content';
  $strongarm->value = 2;
  $export['language_content_type_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_search_log';
  $strongarm->value = 0;
  $export['language_content_type_search_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_default';
  $strongarm->value = (object) array(
    'language' => 'nl',
    'name' => 'Dutch',
    'native' => 'Nederlands',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'nl',
    'weight' => '0',
    'javascript' => 'V-cbMJJwz9wmuD3sx2a2nUKuUhG0t8ZyxbrUNWMcRr4',
  );
  $export['language_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_naturalis_featured_content';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_search_log';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_search_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_naturalis_featured_content';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_search_log';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_search_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_baseurl';
  $strongarm->value = 'http://api.biodiversitydata.nl/v2';
  $export['ndabioresults_config_baseurl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_debug';
  $strongarm->value = '1';
  $export['ndabioresults_config_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_debug_encoded';
  $strongarm->value = '0';
  $export['ndabioresults_config_debug_encoded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_defaultsort';
  $strongarm->value = '_score';
  $export['ndabioresults_config_defaultsort'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_defaultsortdirection';
  $strongarm->value = 'DESC';
  $export['ndabioresults_config_defaultsortdirection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_initialmaxgroupresults';
  $strongarm->value = '10';
  $export['ndabioresults_config_initialmaxgroupresults'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_initialmaxresults';
  $strongarm->value = '10';
  $export['ndabioresults_config_initialmaxresults'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_log';
  $strongarm->value = '/var/log/logstash/bioportal.log';
  $export['ndabioresults_config_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_maxgroupresults';
  $strongarm->value = 10;
  $export['ndabioresults_config_maxgroupresults'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_maxpagesinpaginator';
  $strongarm->value = '20';
  $export['ndabioresults_config_maxpagesinpaginator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_maxresults';
  $strongarm->value = '100';
  $export['ndabioresults_config_maxresults'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_multimediaservice';
  $strongarm->value = 'multimedia/search';
  $export['ndabioresults_config_multimediaservice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_namespecimenservice';
  $strongarm->value = 'specimen/search';
  $export['ndabioresults_config_namespecimenservice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_specimendetailservice';
  $strongarm->value = 'specimen/get-specimen';
  $export['ndabioresults_config_specimendetailservice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_specimenmultimediaservice';
  $strongarm->value = 'multimedia/get-multimedia-object-for-specimen-within-result-set';
  $export['ndabioresults_config_specimenmultimediaservice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_specimennameservice';
  $strongarm->value = 'specimen/name-search';
  $export['ndabioresults_config_specimennameservice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_taxondetailservice';
  $strongarm->value = 'taxon/get-taxon';
  $export['ndabioresults_config_taxondetailservice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_taxonmultimediaservice';
  $strongarm->value = 'multimedia/get-multimedia-object-for-taxon-within-result-set';
  $export['ndabioresults_config_taxonmultimediaservice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_taxonservice';
  $strongarm->value = 'taxon/search';
  $export['ndabioresults_config_taxonservice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabioresults_config_timeout';
  $strongarm->value = '30';
  $export['ndabioresults_config_timeout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabio_config_jsonp';
  $strongarm->value = 'http://naturalis_installation_profile.local:8083/?q=naturalis/json';
  $export['ndabio_config_jsonp'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndabio_config_nda';
  $strongarm->value = 'http://nda.naturalis.nl';
  $export['ndabio_config_nda'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_naturalis_featured_content';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_search_log';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_search_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_naturalis_featured_content';
  $strongarm->value = 1;
  $export['node_preview_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_search_log';
  $strongarm->value = 1;
  $export['node_preview_search_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_naturalis_featured_content';
  $strongarm->value = 0;
  $export['node_submitted_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_search_log';
  $strongarm->value = 1;
  $export['node_submitted_search_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_featured_content_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_featured_content_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_featured_content_nl_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_featured_content_nl_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_featured_content_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_featured_content_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_featured_content_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_featured_content_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_help_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_help_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_help_nl_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_help_nl_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_help_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_help_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_help_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_help_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_page_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_page_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_page_nl_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_page_nl_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_page_pattern';
  $strongarm->value = '[node:title]';
  $export['pathauto_node_naturalis_page_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_page_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_page_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_service_menu_page_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_service_menu_page_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_service_menu_page_nl_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_service_menu_page_nl_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_service_menu_page_pattern';
  $strongarm->value = '[node:title]';
  $export['pathauto_node_naturalis_service_menu_page_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_naturalis_service_menu_page_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_naturalis_service_menu_page_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_ndabio_header_image_pattern';
  $strongarm->value = '';
  $export['pathauto_node_ndabio_header_image_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_search_log_pattern';
  $strongarm->value = '';
  $export['pathauto_node_search_log_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_nba2text_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_nba2text_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_search_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_search_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'search/advancednda';
  $export['site_frontpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_mail';
  $strongarm->value = 'bioportal@naturalis.nl';
  $export['site_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'BioPortal';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_slogan';
  $strongarm->value = 'Browse through Dutch natural history collections';
  $export['site_slogan'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_bioportal_theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 0,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'zurb_foundation_top_bar_enable' => 1,
    'zurb_foundation_top_bar_grid' => 1,
    'zurb_foundation_top_bar_sticky' => 0,
    'zurb_foundation_top_bar_scrolltop' => 1,
    'zurb_foundation_top_bar_is_hover' => 1,
    'zurb_foundation_top_bar_menu_text' => 'Menu',
    'zurb_foundation_top_bar_custom_back_text' => 1,
    'zurb_foundation_top_bar_back_text' => 'Back',
    'zurb_foundation_tooltip_enable' => 1,
    'zurb_foundation_tooltip_position' => 'tip-top',
    'zurb_foundation_tooltip_mode' => 'text',
    'zurb_foundation_tooltip_text' => 'More information?',
    'zurb_foundation_tooltip_touch' => 0,
    'zurb_foundation_disable_core_css' => 0,
    'zurb_foundation_html_tags' => 1,
    'zurb_foundation_messages_modal' => 0,
    'zurb_foundation_pager_center' => 1,
    'naturalis_theme_bottom_bar_crumble' => 1,
    'naturalis_theme_bottom_bar_links' => 1,
    'naturalis_theme_bottom_bar_copyright' => 0,
    'naturalis_theme_bottom_bar_service_menu' => 1,
    'naturalis_theme_background_color' => 'purple',
    'naturalis_theme_logo_background_color' => 'purple',
    'naturalis_theme_logo_color' => 'white',
    'zurb_foundation__active_tab' => 'edit-naturalis-header',
  );
  $export['theme_bioportal_theme_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'bioportal_theme';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_naturalis_theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 0,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'zurb_foundation_top_bar_enable' => 1,
    'zurb_foundation_top_bar_grid' => 1,
    'zurb_foundation_top_bar_sticky' => 0,
    'zurb_foundation_top_bar_scrolltop' => 1,
    'zurb_foundation_top_bar_is_hover' => 1,
    'zurb_foundation_top_bar_menu_text' => 'Menu',
    'zurb_foundation_top_bar_custom_back_text' => 1,
    'zurb_foundation_top_bar_back_text' => 'Back',
    'zurb_foundation_tooltip_enable' => 1,
    'zurb_foundation_tooltip_position' => 'tip-top',
    'zurb_foundation_tooltip_mode' => 'text',
    'zurb_foundation_tooltip_text' => 'More information?',
    'zurb_foundation_tooltip_touch' => 0,
    'zurb_foundation_disable_core_css' => 0,
    'zurb_foundation_html_tags' => 1,
    'zurb_foundation_messages_modal' => 0,
    'zurb_foundation_pager_center' => 1,
    'naturalis_theme_bottom_bar_crumble' => 1,
    'naturalis_theme_bottom_bar_links' => 1,
    'naturalis_theme_bottom_bar_copyright' => 0,
    'naturalis_theme_bottom_bar_service_menu' => 1,
    'naturalis_theme_background_color' => 'blue',
    'naturalis_theme_logo_background_color' => 'blue',
    'naturalis_theme_logo_color' => 'white',
    'zurb_foundation__active_tab' => 'edit-naturalis-header',
  );
  $export['theme_naturalis_theme_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 0,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
  );
  $export['theme_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_naturalis_featured_content';
  $strongarm->value = array(
    'status' => 0,
    'priority' => 0.5,
  );
  $export['xmlsitemap_settings_node_naturalis_featured_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_naturalis_help';
  $strongarm->value = array(
    'status' => 1,
    'priority' => 0.5,
  );
  $export['xmlsitemap_settings_node_naturalis_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_naturalis_page';
  $strongarm->value = array(
    'status' => 1,
    'priority' => 0.5,
  );
  $export['xmlsitemap_settings_node_naturalis_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_naturalis_service_menu_page';
  $strongarm->value = array(
    'status' => 1,
    'priority' => 0.5,
  );
  $export['xmlsitemap_settings_node_naturalis_service_menu_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_ndabio_header_image';
  $strongarm->value = array(
    'status' => 0,
    'priority' => 0.5,
  );
  $export['xmlsitemap_settings_node_ndabio_header_image'] = $strongarm;

  return $export;
}

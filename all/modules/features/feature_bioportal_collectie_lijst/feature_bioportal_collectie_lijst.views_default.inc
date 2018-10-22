<?php
/**
 * @file
 * feature_bioportal_collectie_lijst.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_bioportal_collectie_lijst_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'collecties';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Collecties';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Collecties';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['row_class'] = 'col-align--top';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_nba_search_term' => 'field_nba_search_term',
    'field_nba_search_term_1' => 'field_nba_search_term_1',
  );
  /* Field: Content: NBA search term */
  $handler->display->display_options['fields']['field_nba_search_term']['id'] = 'field_nba_search_term';
  $handler->display->display_options['fields']['field_nba_search_term']['table'] = 'field_data_field_nba_search_term';
  $handler->display->display_options['fields']['field_nba_search_term']['field'] = 'field_nba_search_term';
  $handler->display->display_options['fields']['field_nba_search_term']['label'] = '';
  $handler->display->display_options['fields']['field_nba_search_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_nba_search_term']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_nba_search_term']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_nba_search_term']['alter']['path'] = '/result?theme=[field_nba_search_term]';
  $handler->display->display_options['fields']['field_nba_search_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nba_search_term']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '/result?theme=[field_nba_search_term]';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Afbeelding */
  $handler->display->display_options['fields']['field_collectie_afbeelding']['id'] = 'field_collectie_afbeelding';
  $handler->display->display_options['fields']['field_collectie_afbeelding']['table'] = 'field_data_field_collectie_afbeelding';
  $handler->display->display_options['fields']['field_collectie_afbeelding']['field'] = 'field_collectie_afbeelding';
  $handler->display->display_options['fields']['field_collectie_afbeelding']['label'] = '';
  $handler->display->display_options['fields']['field_collectie_afbeelding']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_collectie_afbeelding']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_collectie_afbeelding']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'naturalis_featured_content' => 'naturalis_featured_content',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'collecties_org';

  /* Display: Highlights */
  $handler = $view->new_display('page', 'Highlights', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Collections';
  $handler->display->display_options['display_description'] = 'English collections';
  $handler->display->display_options['path'] = 'collections';

  /* Display: Bijzondere collecties */
  $handler = $view->new_display('page', 'Bijzondere collecties', 'page_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'naturalis_featured_content' => 'naturalis_featured_content',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'nl' => 'nl',
  );
  $handler->display->display_options['path'] = 'collecties';
  $translatables['collecties'] = array(
    t('Master'),
    t('Collecties'),
    t('more'),
    t('Apply'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Asc'),
    t('Desc'),
    t('Page'),
    t('Highlights'),
    t('Collections'),
    t('English collections'),
    t('Bijzondere collecties'),
  );
  $export['collecties'] = $view;

  return $export;
}

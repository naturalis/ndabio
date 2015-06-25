<?php

/**
 * Implements template_preprocess_html().
 *
 */


/**
 * Implements template_preprocess_page
 *
 */
function bioportal_theme_preprocess_page(&$variables) {
  $block = module_invoke('boxes', 'block_view', 'site_explanation');
  $variables['intro'] = $block['content'];

  _embeded_view($variables);

  // Override ZURB's dynamic sidebars

  // Convenience variables
  if (!empty($variables['page']['sidebar_first'])){
    $left = $variables['page']['sidebar_first'];
  }

  if (!empty($variables['page']['sidebar_second'])) {
    $right = $variables['page']['sidebar_second'];
  }

  if (!empty($left) && !empty($right)) {
    $variables['main_grid'] = 'large-7';
    $variables['sidebar_first_grid'] = 'large-2';
    $variables['sidebar_sec_grid'] = 'large-3';

  } elseif (empty($left) && !empty($right)) {
    $variables['main_grid'] = 'large-10';
    $variables['sidebar_first_grid'] = '';
    $variables['sidebar_sec_grid'] = 'large-1';

  } elseif (!empty($left) && empty($right)) {
    $variables['main_grid'] = 'large-10';
    $variables['sidebar_first_grid'] = 'large-2';
    $variables['sidebar_sec_grid'] = '';

  } else {
    $variables['main_grid'] = 'large-12';
    $variables['sidebar_first_grid'] = '';
    $variables['sidebar_sec_grid'] = '';
  }

  // Base path for use in the templates
  $variables['base_url'] = $GLOBALS['base_url'] . "/";

  // Override Language Menu
  $block = module_invoke('ndabio', 'block_view', 'ndabio_languageselect');
  $variables['language_menu'] = $block['content'];

}

function bioportal_theme_ndabio_omnisearch(&$variables){
  $element = $variables['element'];

  $output  = "<div class='row collapse'>";
  $output .= "  <div class='small-10 large-6 large-offset-2 columns'>";
  $output .=      drupal_render( $element['term']);
  $output .= "  </div>";
  $output .= "  <div class='small-2 large-2 end columns'>";
  $output .=      drupal_render( $element['submit']);
  $output .= "  </div>";
  $output .= "</div>";

  return $output;
}

/**
 * Implements template_preprocess_page
 *
 * completely remove all the HTML output around the page content in Drupal 7 by
 * implementing both hook_preprocess_page and hook_preprocess_html
 *
 */

function _embeded_view(&$variables) {
  if (isset($_GET['response_type']) && $_GET['response_type'] == 'embed') {
    $variables['theme_hook_suggestions'][] = 'page__embed';
  }
}

function bioportal_theme_preprocess_html(&$variables) {

  drupal_add_css(
    path_to_theme() . '/css/ie.css',
    array('weight' => CSS_THEME, 'browsers' => array('IE' => 'lt IE 7', '!IE' => FALSE),
    'preprocess' => FALSE)
  );


  if (isset($_GET['response_type']) && $_GET['response_type'] == 'embed') {
    $variables['theme_hook_suggestions'][] = 'html__embed';
  }
}


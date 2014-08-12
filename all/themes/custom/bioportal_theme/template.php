<?php

/**
 * Implements template_preprocess_html().
 *
 */
//function bioportal_theme_preprocess_html(&$variables) {
//  // Add conditional CSS for IE. To use uncomment below and add IE css file
//  drupal_add_css(path_to_theme() . '/css/ie.css', array('weight' => CSS_THEME, 'browsers' => array('!IE' => FALSE), 'preprocess' => FALSE));
//
//  // Need legacy support for IE downgrade to Foundation 2 or use JS file below
//  // drupal_add_js('http://ie7-js.googlecode.com/svn/version/2.1(beta4)/IE7.js', 'external');
//}

/**
 * Implements template_preprocess_page
 *
 */
function bioportal_theme_preprocess_page(&$variables) {
}

function bioportal_theme_ndabio_omnisearch(&$variables){
  $element = $variables['element'];

  $output  = "<div class='row collapse'>";
  $output .= "  <div class='small-9 large-6 large-offset-2 columns'>";
  $output .= drupal_render( $element['ndabio_adv']);
  $output .= "  </div>";
  $output .= "  <div class='small-3 large-2 end columns'>";
  $output .= drupal_render( $element['submit']);
  $output .= "  </div>";
  $output .= "</div>";

  // $output ='<div class="row collapse">
  //   <div class="small-3 large-2 columns">
  //     <span class="prefix">http://</span>
  //   </div>
  //   <div class="small-9 large-10 columns">
  //     <input type="text" placeholder="Enter your URL...">
  //   </div>
  // </div>
  // <div class="row">
  //   <div class="large-6 columns">
  //     <div class="row collapse">
  //       <div class="small-10 columns">
  //         <input type="text" placeholder="Hex Value">
  //       </div>
  //       <div class="small-2 columns">
  //         <a href="#" class="button postfix">Go</a>
  //       </div>
  //     </div>
  //   </div>
  //   <div class="large-6 columns">
  //     <div class="row collapse">
  //       <div class="small-9 columns">
  //         <input type="text" placeholder="Value">
  //       </div>
  //       <div class="small-3 columns">
  //         <span class="postfix radius">Label</span>
  //       </div>
  //     </div>
  //   </div>
  // </div>';

  return $output;
}
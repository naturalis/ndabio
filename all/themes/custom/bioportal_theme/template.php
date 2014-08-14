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

  return $output;
}

function bioportal_theme_form_element($variables) {
  $element = &$variables['element'];
  $show_wrapper = TRUE;

  if ( isset($element['#nowrapper'])){
    if ( $element['#nowrapper'] == "true"){
      $show_wrapper = FALSE;
    }
  };

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }

  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = $show_wrapper ?  '<div' . drupal_attributes($attributes) . '>' . "\n" : '';

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
      $output .= "<div class='row'>\n" ;
      $output .= "\t<div class='large-2 large-offset-2 small-5 columns'> " . theme('form_element_label', $variables). "</div>\n";
      $output .= "\t<div class='large-5 small-7 columns end'> " .  $prefix . $element['#children'] . $suffix . "</div>\n";
      $output .= "</div>\n";
      break;
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= $show_wrapper ? "</div>\n" : "";

  return $output;
}

function bioportal_theme_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  } elseif ( $element["#title_display"] == "before" ){
    $attributes['class'] = 'inline';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

 // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
}

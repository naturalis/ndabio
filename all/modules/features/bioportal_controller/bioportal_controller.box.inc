<?php
/**
 * @file
 * bioportal_controller.box.inc
 */

/**
 * Implements hook_default_box().
 */
function bioportal_controller_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'site_explanation';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Introduction';
  $box->options = array(
    'body' => array(
      'value' => 'Bij Naturalis Biodiversity Center willen we biodiversiteit beschrijven, begrijpen en verklaren. We verzamelen, bewaren en bestuderen dieren, planten en stenen.  De verscheidenheid van het leven op aarde, op het niveau van genen, soorten en ecosystemen. Biodiversiteit omvat alle soorten die er op aarde zijn, waaronder alle dier- en plantensoorten. Op deze site kunt u door deze verzamelelde gegevens zoeken.   ',
      'format' => 'plain_text',
    ),
    'additional_classes' => '',
  );
  $export['site_explanation'] = $box;

  return $export;
}

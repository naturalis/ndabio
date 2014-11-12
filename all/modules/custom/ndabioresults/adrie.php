<?php

function ndabioresults_config_form($form, &$form_state) {
  $form['ndabioresults_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Naturalis config')
  );

  //NBA Base URL
  $form['ndabioresults_config']['ndabioresults_config_baseurl'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA base URL'),
    '#default_value' => variable_get('ndabioresults_config_baseurl', "http://nba.naturalis.nl/"),
    '#size' => 140,
    '#maxlength' => 200,
    '#description' => t('The base URL of the NBA.'),
    '#required' => TRUE
  );



  return system_settings_form($form);
}


/**
 * Constant: base url of NBA service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function ndaBaseUrl () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'http://10.42.1.178:8080/nl.naturalis.nda.service.rest/api/';
    }
    return $var;
}

/**
 * Constant: search flags
 *
 * @return array
 */
function searchFlags () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = array('andOr', 'sort', 'sortDirection', 'maxResults', 'offset');
    }
    return $var;
}

/**
 * Constant: maximum results for initial "overview" query
 *
 * @return integer
 */
function maxResultsInitial () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 10;
    }
    return $var;
}

/**
 * Constant: maximum results for subsequent queries
 *
 * @return integer
 */
function maxResults () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 100;
    }
    return $var;
}

/**
 * Constant: default sort field
 *
 * @return string
 */
function defaultSort () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = '_score';
    }
    return $var;
}

/**
 * Constant: default sort direction
 *
 * @return string
 */
function defaultSortDirection () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'DESC';
    }
    return $var;
}

/**
 * Constant: maximum results for subsequent queries
 *
 * @return integer
 */
function maxPagesInPaginator () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 20;
    }
    return $var;
}


/**
 * Constant: name of specimen service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function specimenService () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'specimen/search';
    }
    return $var;
}

/**
 * Constant: name of specimen name service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function specimenNamesService () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'specimen/name-search';
    }
    return $var;
}

/**
 * Constant: name of specimen detail service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function specimenDetailService () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'specimen/get-specimen';
    }
    return $var;
}

/**
 * Constant: name of multimedia per specimen service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function specimenMultimediaService () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'multimedia/get-multimedia-object-for-specimen-within-result-set';
    }
    return $var;
}

/**
 * Constant: name of taxon service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function taxonService () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'taxon/search';
    }
    return $var;
}

/**
 * Constant: name of taxon detail service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function taxonDetailService () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'taxon/get-taxon';
    }
    return $var;
}

/**
 * Constant: name of multimedia per taxon service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function taxonMultimediaService () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'multimedia/get-multimedia-object-for-taxon-within-result-set';
    }
    return $var;
}

/**
 * Constant: name of multimedia service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function multimediaService () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = 'multimedia/search';
    }
    return $var;
}

/**
 * Constant: order of search results output
 *
 * Determines print order of search result, currently
 * multimedia, taxon, specimen name, specimen.
 *
 * @return array
 */
function resultOrder () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = array(
        	multimediaService(),
        	taxonService(),
        	specimenNamesService(),
        	specimenService()
        );
    }
    return $var;
}

/**
 * Mapping function: maps service to parse/print functions
 *
 * Each service response is handled by distinct parse and
 * print functions. This function provides the mapping.
 *
 * @return array Names of parse and print function for the service of choice
 */
function serviceToFunctions () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = array(
        	taxonService() => array(
        		'parse' => 'parseTaxa',
        		'print' => 'printTaxa',
        	    'info' => 'results taxa'
        	),
        	specimenNamesService() => array(
        		'parse' => 'parseSpecimensByTaxon',
        		'print' => 'printSpecimensByTaxon',
        	    'info' => 'results specimens by name'
        	),
        	multimediaService() => array(
        		'parse' => 'parseMultimedia',
        		'print' => 'printMultimedia',
        	    'info' => 'results multimedia'
        	),
        	specimenService() => array(
        		'parse' => 'parseSpecimens',
        		'print' => 'printSpecimens',
        	    'info' => 'results specimens'
        	),
        	specimenDetailService() => array(
        		'parse' => 'parseSpecimenDetail',
        		'print' => 'printSpecimenDetail',
        	    'info' => 'detail specimen'
        	),
        	taxonDetailService() => array(
        		'parse' => 'parseTaxonDetail',
        		'print' => 'printTaxonDetail',
        	    'info' => 'detail taxon'
        	),
        	taxonMultimediaService() => array(
        		'parse' => 'parseTaxonMediaDetail',
        		'print' => 'printTaxonMediaDetail',
        	    'info' => 'detail multimedia by taxon'
        	),
        	specimenMultimediaService() => array(
        		'parse' => 'parseSpecimenMediaDetail',
        		'print' => 'printSpecimenMediaDetail',
        	    'info' => 'detail multimedia by specimen'
        	)
        );
    }
    return $var;
}
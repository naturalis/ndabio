<?php

define("NBABASEURL", "http://10.42.1.163:8080/");
define("NBAINITMAXRESULTS", 10);
define("NBAMAXRESULTS", 100);
define("NBADEFAULTSORT", '_score');
define("NBADEFAULTSORTDIRECTION", 'DESC');
define("NBAMAXPAGESINPAGINATOR", 20);
define("NBASPECIMENSERVICE", 'specimen/search');
define("NBASPECIMENNAMESERVICE", 'specimen/name-search');
define("NBASPECIMENDETAILSERVICE", 'specimen/get-specimen');
define("NBASPECIMENMULTIMEDIASERVICE", 'multimedia/get-multimedia-object-for-specimen-within-result-set');
define("NBATAXONSERVICE", 'taxon/search');
define("NBATAXONDETAILSERVICE", 'taxon/get-taxon');
define("NBATAXONMULTIMEDIASERVICE", 'multimedia/get-multimedia-object-for-taxon-within-result-set');
define("NBAMULTIMEDIASERVICE", 'multimedia/search');



function ndabioresults_config_form($form, &$form_state) {
  $form['ndabioresults_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Naturalis config')
  );

  //NBA Base URL
  $form['ndabioresults_config']['ndabioresults_config_baseurl'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA base URL'),
    '#default_value' => variable_get('ndabioresults_config_baseurl', NBABASEURL),
    '#size' => 140,
    '#maxlength' => 200,
    '#description' => t('The base URL of the NBA.') . '<br />' . t('Default') . ': ' . NBABASEURL,
    '#required' => TRUE
  );
  //Maximum results for initial "overview"
  $form['ndabioresults_config']['ndabioresults_config_initialmaxresults'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Initial max results'),
    '#default_value' => variable_get('ndabioresults_config_initialmaxresults', NBAINITMAXRESULTS),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('Number of maximum results for initial "overview" query.') . '<br />' . t('Default') . ': ' . NBAINITMAXRESULTS,
    '#required' => TRUE
  );
  //Maximum results for subsequent queries
  $form['ndabioresults_config']['ndabioresults_config_maxresults'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Maximum results'),
    '#default_value' => variable_get('ndabioresults_config_maxresults', NBAMAXRESULTS),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('Number of maximum results for subsequent queries.') . '<br />' . t('Default') . ': ' . NBAMAXRESULTS,
    '#required' => TRUE
  );

  //Constant: default sort field
  $form['ndabioresults_config']['ndabioresults_config_defaultsort'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Default sort field'),
    '#default_value' => variable_get('ndabioresults_config_defaultsort', NBADEFAULTSORT),
    '#size' => 30,
    '#maxlength' => 30,
    '#description' => t('Default sort field.') . '<br />' . t('Default') . ': ' . NBADEFAULTSORT,
    '#required' => TRUE
  );

  //Constant: default sort direction
  $form['ndabioresults_config']['ndabioresults_config_defaultsortdirection'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Default sort field direction'),
    '#default_value' => variable_get('ndabioresults_config_defaultsortdirection', NBADEFAULTSORTDIRECTION),
    '#size' => 20,
    '#maxlength' => 20,
    '#description' => t('Default sort field direction.') . '<br />' . t('Default') . ': ' . NBADEFAULTSORTDIRECTION,
    '#required' => TRUE
  );

  //Constant: maximum results for subsequent queries
  $form['ndabioresults_config']['ndabioresults_config_maxpagesinpaginator'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Maximum number of pages in the paginator'),
    '#default_value' => variable_get('ndabioresults_config_maxpagesinpaginator', NBAMAXPAGESINPAGINATOR),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('Maximum number of pages in the paginator.') . '<br />' . t('Default') . ': ' . NBAMAXPAGESINPAGINATOR,
    '#required' => TRUE
  );

  //Constant: name of specimen service
  $form['ndabioresults_config']['ndabioresults_config_namespecimenservice'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Name of specimen service'),
    '#default_value' => variable_get('ndabioresults_config_namespecimenservice', NBASPECIMENSERVICE),
    '#size' => 50,
    '#maxlength' => 100,
    '#description' => t('Name of specimen service.') . '<br />' . t('Default') . ': ' . NBASPECIMENSERVICE,
    '#required' => TRUE
  );

  //Constant: name of specimen name service
  $form['ndabioresults_config']['ndabioresults_config_specimennameservice'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Name of specimen name service'),
    '#default_value' => variable_get('ndabioresults_config_specimennameservice', NBASPECIMENNAMESERVICE),
    '#size' => 50,
    '#maxlength' => 100,
    '#description' => t('Name of specimen name service.') . '<br />' . t('Default') . ': ' . NBASPECIMENNAMESERVICE,
    '#required' => TRUE
  );

  //Constant: name of specimen detail service
  $form['ndabioresults_config']['ndabioresults_config_specimendetailservice'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Name of specimen detail service'),
    '#default_value' => variable_get('ndabioresults_config_specimendetailservice', NBASPECIMENDETAILSERVICE),
    '#size' => 50,
    '#maxlength' => 100,
    '#description' => t('Name of specimen detail service.') . '<br />' . t('Default') . ': ' . NBASPECIMENDETAILSERVICE,
    '#required' => TRUE
  );

  //Constant: name of multimedia per specimen service
  $form['ndabioresults_config']['ndabioresults_config_specimenmultimediaservice'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Name of multimedia per specimen service'),
    '#default_value' => variable_get('ndabioresults_config_specimenmultimediaservice', NBASPECIMENMULTIMEDIASERVICE),
    '#size' => 50,
    '#maxlength' => 100,
    '#description' => t('Name of multimedia per specimen service.') . '<br />' . t('Default') . ': ' . NBASPECIMENMULTIMEDIASERVICE,
    '#required' => TRUE
  );

  //Constant: name of taxon service
  $form['ndabioresults_config']['ndabioresults_config_taxonservice'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Name of taxon service'),
    '#default_value' => variable_get('ndabioresults_config_taxonservice', NBATAXONSERVICE),
    '#size' => 50,
    '#maxlength' => 100,
    '#description' => t('Name of taxon service.') . '<br />' . t('Default') . ': ' . NBATAXONSERVICE,
    '#required' => TRUE
  );

  //Constant: name of taxon detail service
  $form['ndabioresults_config']['ndabioresults_config_taxondetailservice'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Name of taxon detail service'),
    '#default_value' => variable_get('ndabioresults_config_taxondetailservice', NBATAXONDETAILSERVICE),
    '#size' => 50,
    '#maxlength' => 100,
    '#description' => t('Name of taxon detail service.') . '<br />' . t('Default') . ': ' . NBATAXONDETAILSERVICE,
    '#required' => TRUE
  );


  //Constant: name of multimedia per taxon service
  $form['ndabioresults_config']['ndabioresults_config_taxonmultimediaservice'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Name of multimedia per taxon service'),
    '#default_value' => variable_get('ndabioresults_config_taxonmultimediaservice', NBATAXONMULTIMEDIASERVICE),
    '#size' => 50,
    '#maxlength' => 100,
    '#description' => t('Name of multimedia per taxon service.') . '<br />' . t('Default') . ': ' . NBATAXONMULTIMEDIASERVICE,
    '#required' => TRUE
  );

  //Constant: name of multimedia service
  $form['ndabioresults_config']['ndabioresults_config_multimediaservice'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Name of multimedia service'),
    '#default_value' => variable_get('ndabioresults_config_multimediaservice', NBAMULTIMEDIASERVICE),
    '#size' => 50,
    '#maxlength' => 100,
    '#description' => t('Name of multimedia service.') . '<br />' . t('Default') . ': ' . NBAMULTIMEDIASERVICE,
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
  return variable_get('ndabioresults_config_baseurl', NBABASEURL);
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
  return variable_get('ndabioresults_config_initialmaxresults', NBAINITMAXRESULTS);
}

/**
 * Constant: maximum results for subsequent queries
 *
 * @return integer
 */
function maxResults () {
  return variable_get('ndabioresults_config_maxresults', NBAMAXRESULTS);
}

/**
 * Constant: default sort field
 *
 * @return string
 */
function defaultSort () {
  return variable_get('ndabioresults_config_defaultsort', NBADEFAULTSORT);
}

/**
 * Constant: default sort direction
 *
 * @return string
 */
function defaultSortDirection () {
  return variable_get('ndabioresults_config_defaultsortdirection', NBADEFAULTSORTDIRECTION);
}

/**
 * Constant: maximum results for subsequent queries
 *
 * @return integer
 */
function maxPagesInPaginator () {
  return variable_get('ndabioresults_config_maxpagesinpaginator', NBAMAXPAGESINPAGINATOR);
}


/**
 * Constant: name of specimen service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function specimenService () {
  return variable_get('ndabioresults_config_namespecimenservice', NBASPECIMENSERVICE);
}

/**
 * Constant: name of specimen name service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function specimenNamesService () {
  return variable_get('ndabioresults_config_specimennameservice', NBASPECIMENNAMESERVICE);
}

/**
 * Constant: name of specimen detail service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function specimenDetailService () {
  return variable_get('ndabioresults_config_specimendetailservice', NBASPECIMENDETAILSERVICE);
}

/**
 * Constant: name of multimedia per specimen service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function specimenMultimediaService () {
  return variable_get('ndabioresults_config_specimenmultimediaservice', NBASPECIMENMULTIMEDIASERVICE);
}

/**
 * Constant: name of taxon service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function taxonService () {
  return variable_get('ndabioresults_config_taxonservice', NBATAXONSERVICE);
}

/**
 * Constant: name of taxon detail service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function taxonDetailService () {
  return variable_get('ndabioresults_config_taxondetailservice', NBATAXONDETAILSERVICE);
}

/**
 * Constant: name of multimedia per taxon service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function taxonMultimediaService () {
  return variable_get('ndabioresults_config_taxonmultimediaservice', NBATAXONMULTIMEDIASERVICE);
}

/**
 * Constant: name of multimedia service
 *
 * @todo Config option in module?
 *
 * @return string
 */
function multimediaService () {
  return variable_get('ndabioresults_config_multimediaservice', NBAMULTIMEDIASERVICE);
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
        	    'info' => 'results taxa',
        	    'method' => 'get'
        	),
        	specimenNamesService() => array(
        		'parse' => 'parseSpecimensByTaxon',
        		'print' => 'printSpecimensByTaxon',
        	    'info' => 'results specimens by name',
        	    'method' => 'post'
        	),
            multimediaService() => array(
        		'parse' => 'parseMultimedia',
        		'print' => 'printMultimedia',
        	    'info' => 'results multimedia',
        	    'method' => 'post'
        	),
        	specimenService() => array(
        		'parse' => 'parseSpecimens',
        		'print' => 'printSpecimens',
        	    'info' => 'results specimens',
        	    'method' => 'get'
        	),
        	specimenDetailService() => array(
        		'parse' => 'parseSpecimenDetail',
        		'print' => 'printSpecimenDetail',
        	    'info' => 'detail specimen',
        	    'method' => 'get'
        	),
        	taxonDetailService() => array(
        		'parse' => 'parseTaxonDetail',
        		'print' => 'printTaxonDetail',
        	    'info' => 'detail taxon',
        	    'method' => 'get'
        	),
        	taxonMultimediaService() => array(
        		'parse' => 'parseTaxonMediaDetail',
        		'print' => 'printTaxonMediaDetail',
        	    'info' => 'detail multimedia by taxon',
        	    'method' => 'get'
        	),
        	specimenMultimediaService() => array(
        		'parse' => 'parseSpecimenMediaDetail',
        		'print' => 'printSpecimenMediaDetail',
        	    'info' => 'detail multimedia by specimen',
        	    'method' => 'get'
        	)
        );
    }
    return $var;
}
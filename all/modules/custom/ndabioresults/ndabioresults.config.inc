<?php

define("NBABASEURL", "http://api.biodiversitydata.nl/v2/");
define("NBALOG", "/tmp/bioportal.log.json");
define("NBAINITMAXRESULTS", 10);
define("NBAMAXRESULTS", 100);
define("NBADEFAULTSORT", '_score');
define("NBADEFAULTSORTDIRECTION", 'DESC');
define("NBAMAXPAGESINPAGINATOR", 20);


function ndabioresults_config_form($form, &$form_state) {
  $form['ndabioresults_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Naturalis config')
  );

  $form['ndabioresults_config']['ndabioresults_config_general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General NBA services'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // NBA Base URL
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_baseurl'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA base URL'),
    '#default_value' => variable_get('ndabioresults_config_baseurl', NBABASEURL),
    '#size' => 140,
    '#maxlength' => 200,
    '#description' => t('The base URL of the NBA.') . '<br />' . t('Default') . ': ' . NBABASEURL,
    '#required' => TRUE
  );

  //LOG file location
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_log'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA JSON Log file'),
    '#default_value' => variable_get('ndabioresults_config_log', NBALOG),
    '#size' => 140,
    '#maxlength' => 200,
    '#description' => t('NBA JSON Log file.') . '<br />' . t('Default') . ': ' . NBALOG,
    '#required' => TRUE
  );

  // Maximum results for initial "overview"
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_initialmaxresults'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Initial max results'),
    '#default_value' => variable_get('ndabioresults_config_initialmaxresults', NBAINITMAXRESULTS),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('Number of maximum results for initial "overview" query.') . '<br />' . t('Default') . ': ' . NBAINITMAXRESULTS,
    '#required' => TRUE
  );

  // Maximum results for subsequent queries
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_maxresults'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Maximum results'),
    '#default_value' => variable_get('ndabioresults_config_maxresults', NBAMAXRESULTS),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('Number of maximum results for subsequent queries.') . '<br />' . t('Default') . ': ' . NBAMAXRESULTS,
    '#required' => TRUE
  );

  // Constant: default sort field
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_defaultsort'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Default sort field'),
    '#default_value' => variable_get('ndabioresults_config_defaultsort', NBADEFAULTSORT),
    '#size' => 30,
    '#maxlength' => 30,
    '#description' => t('Default sort field.') . '<br />' . t('Default') . ': ' . NBADEFAULTSORT,
    '#required' => TRUE
  );

  // Constant: default sort direction
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_defaultsortdirection'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Default sort field direction'),
    '#default_value' => variable_get('ndabioresults_config_defaultsortdirection', NBADEFAULTSORTDIRECTION),
    '#size' => 20,
    '#maxlength' => 20,
    '#description' => t('Default sort field direction.') . '<br />' . t('Default') . ': ' . NBADEFAULTSORTDIRECTION,
    '#required' => TRUE
  );

  // Constant: maximum results for subsequent queries
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_maxpagesinpaginator'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Maximum number of pages in the paginator'),
    '#default_value' => variable_get('ndabioresults_config_maxpagesinpaginator', NBAMAXPAGESINPAGINATOR),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('Maximum number of pages in the paginator.') . '<br />' . t('Default') . ': ' . NBAMAXPAGESINPAGINATOR,
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
         $var = array(
            'sort',
            'sortDirection',
            'size',
            'from',
            'logicalOperator',
            'andOr',
         );
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
 * Constant: maximum results for grouped results (currently specimen name search)
 *
 * @return integer
 */
function maxGroupResults () {
  return variable_get('ndabioresults_config_maxgroupresults', NBAMAXGROUPRESULTS);
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
 * Constant: default group sort
 * This parameter currently cannot be set by the user in the module
 *
 * @return string
 */
function defaultGroupSort () {
    return NBADEFAULTGROUPSORT;
}

/**
 * Constant: default group sort direction
 * This parameter currently cannot be set by the user in the module
 *
 * @return string
 */
function defaultGroupSortDirection () {
    return NBADEFAULTSORTGROUPDIRECTION;
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
 * Constant: order of search results output
 *
 * Determines print order of search result, currently
 * multimedia, taxon, specimen.
 *
 * @return array
 */
function resultOrder () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = array(
        	'multimedia',
        	'taxon',
        	'specimen',
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
        	'taxon' => array(
        		'parse' => 'parseTaxa',
        		'print' => 'printTaxa',
        	    'info' => 'results taxa',
        	    'method' => 'get'
        	),
            'multimedia' => array(
        		'parse' => 'parseMultimedia',
        		'print' => 'printMultimedia',
        	    'info' => 'results multimedia',
        	    'method' => 'post'
        	),
        	'specimen' => array(
        		'parse' => 'parseSpecimens',
        		'print' => 'printSpecimens',
        	    'info' => 'results specimens',
        	    'method' => 'post'
        	),
        );
    }
    return $var;
}

function searchServices () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
         $var = array(
        	'multimedia',
        	'taxon',
        	'specimen',
        );
    }
    return $var;
}

function nbaFieldMapping ()
{
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
        $var = array(
            'multimedia' => [
                'className' => [
                    'identifications.defaultClassification.className'
                ],
                'class' => [
                    'identifications.defaultClassification.className'
                ],
                'family' => [
                    'identifications.defaultClassification.family'
                ],
                'genusOrMonomial' => [
                    'identifications.defaultClassification.genus',
                    'identifications.scientificName.genusOrMonomial'
                ],
                'genus' => [
                    'identifications.defaultClassification.genus',
                    'identifications.scientificName.genusOrMonomial'
                ],
                'kingdom' => [
                    'identifications.defaultClassification.kingdom'
                ],
                'localityText' => [
                    'gatheringEvents.localityText'
                ],
                'locality' => [
                    'gatheringEvents.localityText'
                ],
                'order' => [
                    'identifications.defaultClassification.order'
                ],
                'phaseOrStage' => [
                    'phasesOrStages'
                ],
                'phylum' => [
                    'identifications.defaultClassification.phylum'
                ],
                'registrationNumber' => [
                    'unitID'
                ],
                'sex' => [
                    'sexes'
                ],
                'sourceSystem' => [
                    'sourceSystem.name'
                ],
                'scientificName' => [
                    'identifications.scientificName.fullScientificName'
                ],
                'specificEpithet' => [
                    'identifications.defaultClassification.specificEpithet',
                    'identifications.scientificName.specificEpithet'
                ],
                'species' => [
                    'identifications.defaultClassification.specificEpithet',
                    'identifications.scientificName.specificEpithet'
                ],
                'infraspecificEpithet' => [
                    'identifications.defaultClassification.infraspecificEpithet',
                    'identifications.scientificName.infraspecificEpithet'
                ],
                'subspecies' => [
                    'identifications.defaultClassification.infraspecificEpithet',
                    'identifications.scientificName.infraspecificEpithet'
                ],
                'typeStatus' => [
                    'specimenTypeStatus'
                ],
                'vernacularName' => [
                    'identifications.vernacularNames.name'
                ],
                'commonName' => [
                    'identifications.vernacularNames.name'
                ]
            ],
            'specimen' => [
                'className' => [
                    'identifications.defaultClassification.className'
                ],
                'class' => [
                    'identifications.defaultClassification.className'
                ],
                'collectingStartDate' => [
                    'gatheringEvent.dateTimeBegin'
                ],
                'collectorsFieldNumber' => [
                    'collectorsFieldNumber'
                ],
                'gatheringAgent' => [
                    'gatheringEvent.gatheringPersons.fullName',
                    'gatheringEvent.gatheringOrganizations.name'
                ],
                'collector' => [
                    'gatheringEvent.gatheringPersons.fullName',
                    'gatheringEvent.gatheringOrganizations.name'
                ],
                'family' => [
                    'identifications.defaultClassification.family'
                ],
                'genusOrMonomial' => [
                    'identifications.defaultClassification.genus',
                    'identifications.scientificName.genusOrMonomial'
                ],
                'genus' => [
                    'identifications.defaultClassification.genus',
                    'identifications.scientificName.genusOrMonomial'
                ],
                'kingdom' => [
                    'identifications.defaultClassification.kingdom'
                ],
                'localityText' => [
                    'gatheringEvent.localityText'
                ],
                'locality' => [
                    'gatheringEvent.localityText'
                ],
                'order' => [
                    'identifications.defaultClassification.order'
                ],
                'phylum' => [
                    'identifications.defaultClassification.phylum'
                ],
                'registrationNumber' => [
                    'unitID'
                ],
                'collectionType' => [
                    'collectionType'
                ],
                'sourceSystem' => [
                    'sourceSystem.name'
                ],
                'scientificName' => [
                    'identifications.scientificName.fullScientificName'
                ],
                'specificEpithet' => [
                    'identifications.defaultClassification.specificEpithet',
                    'identifications.scientificName.specificEpithet'
                ],
                'species' => [
                    'identifications.defaultClassification.specificEpithet',
                    'identifications.scientificName.specificEpithet'
                ],
                'infraspecificEpithet' => [
                    'identifications.defaultClassification.infraspecificEpithet',
                    'identifications.scientificName.infraspecificEpithet'
                ],
                'subgenus' => [
                    'identifications.defaultClassification.subgenus',
                    'identifications.scientificName.subgenus'
                ],
                'subspecies' => [
                    'identifications.defaultClassification.infraspecificEpithet',
                    'identifications.scientificName.infraspecificEpithet'
                ],
                'vernacularName' => [
                    'identifications.vernacularNames.name'
                ],
                'commonName' => [
                    'identifications.vernacularNames.name'
                ]
            ],
            'taxon' => [
                'className' => [
                    'defaultClassification.className'
                ],
                'class' => [
                    'defaultClassification.className'
                ],
                'expert' => [
                    'experts.fullName',
                    'synonyms.experts.fullName',
                    'vernacularNames.experts.fullName'
                ],
                'expertOrganisation' => [
                    'experts.organization.name',
                    'synonyms.experts.organization.name',
                    'vernacularNames.organization.name'
                ],
                'family' => [
                    'defaultClassification.family'
                ],
                'subgenus' => [
                    'defaultClassification.subgenus',
                    'acceptedName.subgenus'
                ],
                'subgenusAny' => [
                    'defaultClassification.subgenus',
                    'acceptedName.subgenus',
                    'synonyms.subgenus'
                ],
                'genus' => [
                    'defaultClassification.genus',
                    'acceptedName.genusOrMonomial'
                ],
                'genusOrMonomial' => [
                    'defaultClassification.genus',
                    'acceptedName.genusOrMonomial'
                ],
                'genusAny' => [
                    'defaultClassification.genus',
                    'acceptedName.genusOrMonomial',
                    'synonyms.genusOrMonomial'
                ],
                'order' => [
                    'defaultClassification.order'
                ],
                'phylum' => [
                    'defaultClassification.phylum'
                ],
                'specificEpithet' => [
                    'defaultClassification.specificEpithet',
                    'acceptedName.specificEpithet'
                ],
                'species' => [
                    'defaultClassification.specificEpithet',
                    'acceptedName.specificEpithet'
                ],
                'speciesAny' => [
                    'defaultClassification.specificEpithet',
                    'acceptedName.specificEpithet',
                    'synonyms.specificEpithet'
                ],
                'infraspecificEpithet' => [
                    'defaultClassification.infraspecificEpithet',
                    'acceptedName.infraspecificEpithet'
                ],
                'subspecies' => [
                    'defaultClassification.infraspecificEpithet',
                    'acceptedName.infraspecificEpithet'
                ],
                'taxonomicStatus' => [
                    'synonyms.taxonomicStatus',
                    'acceptedName.taxonomicStatus'
                ],
                'vernacularName' => [
                    'vernacularNames.name'
                ],
                'commonName' => [
                    'vernacularNames.name'
                ],
                'kingdom' => [
                    'defaultClassification.kingdom'
                ],
                'sourceSystem' => [
                    'sourceSystem.name'
                ],
            ]
        );
    }
    return $var;
}

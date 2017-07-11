<?php



define("NBABASEURL", "http://api.biodiversitydata.nl/v2/");
define("NBALOG", "/tmp/bioportal.log.json");
define("NBAINITMAXRESULTS", 10);
define("NBAINITMAXGROUPRESULTS", 10);
define("NBAMAXRESULTS", 100);
define("NBATIMEOUT", 5);
define("NBAMAXPAGESINPAGINATOR", 20);
define("NBADEBUG", 0);
define("NBADEBUGENCODED", 0);




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
    '#title' => t('NBA json log file'),
    '#default_value' => variable_get('ndabioresults_config_log', NBALOG),
    '#size' => 140,
    '#maxlength' => 200,
    '#description' => t('Location of Log file.') . '<br />' . t('Default') . ': ' . NBALOG,
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

  // Maximum results per group for initial "overview"
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_initialmaxgroupresults'] = array(
  		'#type' => 'textfield',
  		'#title' => t('NBA Maximum results per group'),
  		'#default_value' => variable_get('ndabioresults_config_initialmaxgroupresults', NBAINITMAXGROUPRESULTS),
  		'#size' => 10,
  		'#maxlength' => 10,
  		'#description' => t('Number of maximum results per grouped result for initial "overview" query.') . '<br />' . t('Default') . ': ' . NBAINITMAXGROUPRESULTS,
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
  
  // Constant: timeout
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('NBA Timeout'),
    '#default_value' => variable_get('ndabioresults_config_timeout', NBATIMEOUT),
    '#size' => 30,
    '#maxlength' => 30,
    '#description' => t('NBA timeout (in seconds).') . '<br />' . t('Default') . ': ' . NBATIMEOUT,
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

  // Constant: maximum results for subsequent queries
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_debug'] = array(
    '#type' => 'textfield',
    '#title' => t('Display NBA QuerySpec'),
    '#default_value' => variable_get('ndabioresults_config_debug', NBADEBUG),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('DEBUG: Display query sent to the NBA.') . '<br />' . t('Default') . ': ' . NBADEBUG,
    '#required' => TRUE
  );
  
  // Constant: maximum results for subsequent queries
  $form['ndabioresults_config']['ndabioresults_config_general']['ndabioresults_config_debug_encoded'] = array(
    '#type' => 'textfield',
    '#title' => t('Display NBA QuerySpec url-encoded'),
    '#default_value' => variable_get('ndabioresults_config_debug_encoded', NBADEBUGENCODED),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('DEBUG: Url-encoded QuerySpec which can be used directly to query the NBA') . '<br />' . t('Default') . ': ' . NBADEBUGENCODED,
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
function nbaBaseUrl () {
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
         	'referrer',
         	'groupSort'
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
function maxGroupResultsInitial () {
  return variable_get('ndabioresults_config_initialmaxgroupresults', NBAINITMAXGROUPRESULTS);
}


/**
 * Constant: default sort field
 *
 * @return string
 */
function nbaTimeout () {
  return variable_get('ndabioresults_config_timeout', NBATIMEOUT);
}

/**
 * Constant: maximum results for subsequent queries
 *
 * @return integer
 */
function maxPagesInPaginator () {
  return variable_get('ndabioresults_config_maxpagesinpaginator', NBAMAXPAGESINPAGINATOR);
}


function nbaDebug () {
  return variable_get('ndabioresults_config_debug', NBADEBUG);
}

function nbaDebugEncoded () {
  return variable_get('ndabioresults_config_debug_encoded', NBADEBUGENCODED);
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
                'geoShape' => [
                    'gatheringEvents.siteCoordinates.geoShape'
                ],
                'gid' => [
                    'gatheringEvents.siteCoordinates.geoShape'
                ],
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
                    'sourceSystem.code'
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
                    'identifications.typeStatus'
                ],
             	'vernacularName' => [
                    'identifications.vernacularNames.name'
                ],
                'commonName' => [
                    'identifications.vernacularNames.name'
                ],
             	'collectionType' => [
            		'collectionType'
            	],
             	'theme' => [
            		'theme'
            	]
            ],
            'specimen' => [
                'geoShape' => [
                    'gatheringEvent.siteCoordinates.geoShape'
                ],
                'gid' => [
                    'gatheringEvent.siteCoordinates.geoShape'
                ],
                'className' => [
                    'identifications.defaultClassification.className'
                ],
                'class' => [
                    'identifications.defaultClassification.className'
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
                'sourceSystem' => [
                    'sourceSystem.code'
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
                ],
            	'typeStatus' => [
            		'identifications.typeStatus'
            	],
             	'collectionType' => [
            		'collectionType'
            	],
             	'theme' => [
            		'theme'
            	]
            ],
            'taxon' => [
                'className' => [
                    'defaultClassification.className'
                ],
                'class' => [
                    'defaultClassification.className'
                ],
                'family' => [
                    'defaultClassification.family'
                ],
                'subgenus' => [
                    'defaultClassification.subgenus',
                    'acceptedName.subgenus',
                    'synonyms.subgenus'
                ],
                'genus' => [
                    'defaultClassification.genus',
                    'acceptedName.genusOrMonomial',
                    'synonyms.genusOrMonomial',
                ],
                'genusOrMonomial' => [
                    'defaultClassification.genus',
                    'acceptedName.genusOrMonomial',
                    'synonyms.genusOrMonomial',
                ],
                'order' => [
                    'defaultClassification.order'
                ],
                'phylum' => [
                    'defaultClassification.phylum'
                ],
                'specificEpithet' => [
                    'defaultClassification.specificEpithet',
                    'acceptedName.specificEpithet',
                    'synonyms.specificEpithet'
                ],
                'species' => [
                    'defaultClassification.specificEpithet',
                    'acceptedName.specificEpithet',
                    'synonyms.specificEpithet'
                ],
                'infraspecificEpithet' => [
                    'defaultClassification.infraspecificEpithet',
                    'acceptedName.infraspecificEpithet',
                    'synonyms.infraspecificEpithet'
                ],
                'subspecies' => [
                    'defaultClassification.infraspecificEpithet',
                    'acceptedName.infraspecificEpithet',
                	'synonyms.infraspecificEpithet'	
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
                    'sourceSystem.code'
                ]
            ],
        );
    }
    return $var;
}

function nbaNameResolutionFieldMapping ()
{
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
        $var = array(
            'multimedia' => [
                'genusOrMonomial' => [
                    'identifications.taxonomicEnrichments.synonyms.genusOrMonomial'
                ],
                'genus' => [
                    'identifications.taxonomicEnrichments.synonyms.genusOrMonomial'
                ],
                'scientificName' => [
                    'identifications.taxonomicEnrichments.synonyms.fullScientificName'
                ],
                'specificEpithet' => [
                    'identifications.taxonomicEnrichments.synonyms.specificEpithet'
                ],
                'species' => [
                    'identifications.taxonomicEnrichments.synonyms.specificEpithet'
                ],
                'infraspecificEpithet' => [
                    'identifications.taxonomicEnrichments.synonyms.infraspecificEpithet'
                ],
                'subspecies' => [
                    'identifications.taxonomicEnrichments.synonyms.infraspecificEpithet'
                ],
             	'vernacularName' => [
                    'identifications.taxonomicEnrichments.vernacularNames.name'
                ],
                'commonName' => [
                    'identifications.taxonomicEnrichments.vernacularNames.name'
                ],
            ],
            'specimen' => [
                'genusOrMonomial' => [
                    'identifications.taxonomicEnrichments.synonyms.genusOrMonomial'
                ],
                'genus' => [
                    'identifications.taxonomicEnrichments.synonyms.genusOrMonomial'
                ],
                'scientificName' => [
                    'identifications.taxonomicEnrichments.synonyms.fullScientificName'
                ],
                'specificEpithet' => [
                    'identifications.taxonomicEnrichments.synonyms.specificEpithet'
                ],
                'species' => [
                    'identifications.taxonomicEnrichments.synonyms.specificEpithet'
                ],
                'infraspecificEpithet' => [
                    'identifications.taxonomicEnrichments.synonyms.infraspecificEpithet'
                ],
                'subspecies' => [
                    'identifications.taxonomicEnrichments.synonyms.infraspecificEpithet'
                ],
             	'vernacularName' => [
                    'identifications.taxonomicEnrichments.vernacularNames.name'
                ],
                'commonName' => [
                    'identifications.taxonomicEnrichments.vernacularNames.name'
                ],
            ],
        );
    }
    return $var;
}



function nameHits ()
{
	$var = &drupal_static(__FUNCTION__);
	if (!isset($var)) {
		$var = array(
			'multimedia' => [
				'identifications.defaultClassification.genus',
				'identifications.scientificName.genusOrMonomial',
				'identifications.defaultClassification.subgenus',
				'identifications.scientificName.subgenus',
				'identifications.defaultClassification.specificEpithet',
				'identifications.scientificName.specificEpithet',
				'identifications.defaultClassification.infraspecificEpithet',
				'identifications.scientificName.infraspecificEpithet',
				'identifications.scientificName.fullScientificName',
			],			
			'specimen' => [
				'identifications.defaultClassification.genus',
				'identifications.scientificName.genusOrMonomial',
				'identifications.defaultClassification.subgenus',
				'identifications.scientificName.subgenus',
				'identifications.defaultClassification.specificEpithet',
				'identifications.scientificName.specificEpithet',
				'identifications.defaultClassification.infraspecificEpithet',
				'identifications.scientificName.infraspecificEpithet',
				'identifications.scientificName.fullScientificName',
			],
			'taxon' => [
				'defaultClassification.genus',
				'acceptedName.genusOrMonomial',
				'defaultClassification.subgenus',
				'acceptedName.subgenus',
				'defaultClassification.specificEpithet',
				'acceptedName.specificEpithet',
				'defaultClassification.infraspecificEpithet',
				'acceptedName.infraspecificEpithet',
				'acceptedName.fullScientificName',
			],
			'names.specimens' => [
				'specimens.matchingIdentifications.defaultClassification.genus',
				'specimens.matchingIdentifications.scientificName.genusOrMonomial',
				'specimens.matchingIdentifications.defaultClassification.subgenus',
				'specimens.matchingIdentifications.scientificName.subgenus',
				'specimens.matchingIdentifications.defaultClassification.specificEpithet',
				'specimens.matchingIdentifications.scientificName.specificEpithet',
				'specimens.matchingIdentifications.defaultClassification.infraspecificEpithet',
				'specimens.matchingIdentifications.scientificName.infraspecificEpithet',
				'specimens.matchingIdentifications.scientificName.fullScientificName',
			],
			'names.taxa' => [
				'taxa.defaultClassification.genus',
				'taxa.acceptedName.genusOrMonomial',
				'taxa.defaultClassification.subgenus',
				'taxa.acceptedName.subgenus',
				'taxa.defaultClassification.specificEpithet',
				'taxa.acceptedName.specificEpithet',
				'taxa.defaultClassification.infraspecificEpithet',
				'taxa.acceptedName.infraspecificEpithet',
				'taxa.acceptedName.fullScientificName',
			], 
		);
	}
	return $var;
}


function scientificNameElements ()
{
	$var = &drupal_static(__FUNCTION__);
	if (!isset($var)) {
		$var = [
			'genusOrMonomial', 
			'genus',
			'specificEpithet', 
			'infraspecificMarker',
			'infraspecificEpithet', 
			'authorshipVerbatim',
		];
	}
	return $var;
}

function scientificNameElementsInItalics ()
{
	$var = &drupal_static(__FUNCTION__);
	if (!isset($var)) {
		$var = [
			'genusOrMonomial',
			'specificEpithet',
			'infraspecificEpithet',
		];
	}
	return $var;
}

function sortOptions ()
{
	$var = &drupal_static(__FUNCTION__);
	if (!isset($var)) {
		$var = [
			'specimen' => [
				t('relevance') => [
					'path' => 'score',
					'direction' => null
				],
				t('specimen') . ' [A-Z]' => [
					'path' => 'unitID',
					'direction' => 'asc'
				],
					t('specimen') . ' [Z-A]' => [
					'path' => 'unitID',
					'direction' => 'desc'
				],
				t('species') . ' [A-Z]' => [
					'path' => 'identifications.scientificName.genusOrMonomial,'  .
						'identifications.scientificName.specificEpithet,' .
						'identifications.scientificName.infraspecificEpithet',
					'direction' => 'asc,asc,asc'
				],
				t('species') . ' [Z-A]' => [
					'path' => 'identifications.scientificName.genusOrMonomial,'  .
						'identifications.scientificName.specificEpithet,' .
						'identifications.scientificName.infraspecificEpithet',
					'direction' => 'desc,desc,desc'
				]
			],
			'names.specimens' => [
				t('species') . ' [A-Z]' => [
					'path' => 'specimens.matchingIdentifications.scientificName.genusOrMonomial,' .
						'specimens.matchingIdentifications.scientificName.specificEpithet,' .
						'specimens.matchingIdentifications.scientificName.infraspecificEpithet',
					'direction' => 'asc,asc,asc'
				],
				t('species') . ' [Z-A]' => [
					'path' => 'specimens.matchingIdentifications.scientificName.genusOrMonomial,' .
						'specimens.matchingIdentifications.scientificName.specificEpithet,' .
						'specimens.matchingIdentifications.scientificName.infraspecificEpithet',
					'direction' => 'desc,desc,desc'
				],
				t('specimen count') . ' [9-0]' => [
					'path' => 'specimenCount',
					'direction' => 'desc'
				],
				t('specimen count') . ' [0-9]' => [
					'path' => 'specimenCount',
					'direction' => 'asc'
				],
			],
			'names.taxa' => [
				t('relevance') => [
					'path' => 'score',
					'direction' => null
				],
				t('name') . ' [A-Z]' => [
					'path' => 'taxa.acceptedName.genusOrMonomial,' . 
						'taxa.acceptedName.specificEpithet,' . 
						'taxa.acceptedName.infraspecificEpithet',
					'direction' => 'asc,asc,asc'
				],
				t('name') . ' [Z-A]' => [
					'path' => 'taxa.acceptedName.genusOrMonomial,' . 
						'taxa.acceptedName.specificEpithet,' . 
						'taxa.acceptedName.infraspecificEpithet',
					'direction' => 'desc,desc,desc'
				],
			],
		];
	}
	return $var;
}


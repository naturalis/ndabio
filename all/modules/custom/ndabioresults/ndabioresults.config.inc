<?php

// Default values
define("NBABASEURL", "http://api.biodiversitydata.nl/v2/");
define("NBALOG", "/tmp/bioportal.log.json");
define("NBAINITMAXRESULTS", 10);
define("NBAINITMAXGROUPRESULTS", 10);
define("NBAMAXRESULTS", 100);
define("NBATIMEOUT", 5);
define("NBAMAXPAGESINPAGINATOR", 20);
define("NBADEBUG", 0);
define("NBADEBUGENCODED", 0);

// Minimum string length for individual elements in simple search term
define("NBAMINSTRINGLENGTHSIMPLESEARCH", 3);
// ES boost factor for full length simple search term (if there are more elements)
define("NBASIMPLESEARCHFULLTERMBOOST", 2);
// ES boost factor for exact match
define("NBASIMPLESEARCHEXACTMATCHBOOST", 5);



function ndabioresults_config_form ($form, &$form_state) {
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
 
  $form['#submit'][] = 'ndabioresults_admin_settings_submit'; 
  return system_settings_form($form);
}

/**
 * Used to write nba base url (ndabioresults_config_baseurl) to text file
 */
function ndabioresults_admin_settings_submit ($form, &$form_state) {
	_writeBaseFile($form_state['values']['ndabioresults_config_baseurl']);
	drupal_set_message(t('NBA base URL saved to text file:') . ' ' . NBABASEURLFILE, 'status');
	return system_settings_form($form);
}

/**
 * Constant: base url of NBA service
 *
 * @todo Config option in module?
 *      
 * @return string
 */
function _nbaBaseUrl () {
	return variable_get('ndabioresults_config_baseurl', NBABASEURL);
}

/**
 * Constant: search flags
 *
 * @return array
 */
function _searchFlags () {
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
function _maxResultsInitial () {
	return variable_get('ndabioresults_config_initialmaxresults', NBAINITMAXRESULTS);
}

/**
 * Constant: maximum results for subsequent queries
 *
 * @return integer
 */
function _maxResults () {
	return variable_get('ndabioresults_config_maxresults', NBAMAXRESULTS);
}


/**
 * Constant: maximum results for grouped results (currently specimen name search)
 *
 * @return integer

function maxGroupResultsInitial () {
  return variable_get('ndabioresults_config_initialmaxgroupresults', NBAINITMAXGROUPRESULTS);
}
 */

/**
 * Constant: default sort field
 *
 * @return string
 */
function _nbaTimeout () {
	return variable_get('ndabioresults_config_timeout', NBATIMEOUT);
}

/**
 * Max size taxon url cache
 * 
 * Taxon urls are stored to reduce the number of queries to the NBA.
 * However, crawlers should not blow up the session.
 * 
 * @return number
 */
function _maxSizeTaxonUrlCache () {
	return 1000;
}

/**
 * Setting for debugging (1/0)
 * 
 * @return int
 */
function _nbaDebug () {
	return variable_get('ndabioresults_config_debug', NBADEBUG);
}

/**
 * Setting to encode queries (1/0)
 * 
 * Handy when used directly in a url
 * 
 * @return int
 */
function _nbaDebugEncoded () {
	return variable_get('ndabioresults_config_debug_encoded', NBADEBUGENCODED);
}

/**
 * Search services (excludes geo)
 * 
 * @return array
 */
function _searchServices () {
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
 * Mapping from search form fields to NBA paths
 * 
 * @return array
 */
function _nbaFieldMapping () {
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
                'family' => [
                    'identifications.defaultClassification.family'
                ],
                'genusOrMonomial' => [
                    'identifications.defaultClassification.genus',
                    'identifications.scientificName.genusOrMonomial'
                ],
                'kingdom' => [
                    'identifications.defaultClassification.kingdom'
                ],
                'localityText' => [
                    'gatheringEvents.localityText',
                	'gatheringEvents.locality'	
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
                'infraspecificEpithet' => [
                    'identifications.defaultClassification.infraspecificEpithet',
                    'identifications.scientificName.infraspecificEpithet'
                ],
                'typeStatus' => [
                    'identifications.typeStatus'
                ],
             	'vernacularName' => [
                    'identifications.vernacularNames.name',
                    'identifications.taxonomicEnrichments.vernacularNames.name'
             	],
             	'collectionType' => [
            		'collectionType'
            	],
             	'theme' => [
            		'theme'
            	],
            	'license' => [
            		'license'
            	], 
            		
            	// BIOPORVTWO-257
                'gatheringAgent' => [
                    'gatheringEvents.gatheringPersons.fullName',
                    'gatheringEvents.gatheringOrganizations.name'
                ],
                'subgenus' => [
                    'identifications.scientificName.subgenus',
                    'identifications.defaultClassification.subgenus',
                    'identifications.taxonomicEnrichments.synonyms.subgenus'
                ],
            		
 /*           	// Nog toevoegen aan NBA...
            		
            	'kindOfUnit' => [
            		'recordBasis',
            		'kindOfUnit'
            	],
            	'collectorsFieldNumber' => [
                    'collectorsFieldNumber'
                ],

 */           		
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
                'collectorsFieldNumber' => [
                    'collectorsFieldNumber'
                ],
                'gatheringAgent' => [
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
                'kingdom' => [
                    'identifications.defaultClassification.kingdom'
                ],
                'localityText' => [
                    'gatheringEvent.localityText',
                    'gatheringEvent.locality'
                ],
                'order' => [
                    'identifications.defaultClassification.order'
                ],
                'phylum' => [
                    'identifications.defaultClassification.phylum'
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
                'infraspecificEpithet' => [
                    'identifications.defaultClassification.infraspecificEpithet',
                    'identifications.scientificName.infraspecificEpithet'
                ],
                'subgenus' => [
                    'identifications.defaultClassification.subgenus',
                    'identifications.scientificName.subgenus'
                ],
                'vernacularName' => [
                    'identifications.vernacularNames.name',
                    'identifications.taxonomicEnrichments.vernacularNames.name'
                ],
            	'typeStatus' => [
            		'identifications.typeStatus'
            	],
             	'collectionType' => [
            		'collectionType'
            	],
             	'theme' => [
            		'theme'
            	],
            	'phaseOrStage' => [
            		'phaseOrStage'	
            	],
            	'unitID' => [
            		'unitID'	
            	],
            	'sex' => [
            		'sex'
            	],
            	'kindOfUnit' => [
            		'recordBasis',
            		'kindOfUnit'
            	],
            ],
            'taxon' => [
                'className' => [
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
                'infraspecificEpithet' => [
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
                'kingdom' => [
                    'defaultClassification.kingdom'
                ],
                'sourceSystem' => [
                    'sourceSystem.code'
                ],
            	'scientificName' => [
            		'acceptedName.fullScientificName'
            	]
            ],
        );
    }
    return $var;
}

/**
 * Additional paths used for name resolution
 * 
 * @return array
 */
function _nbaNameResolutionFieldMapping () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
        $var = array(
            'multimedia' => [
                'genusOrMonomial' => [
                    'identifications.taxonomicEnrichments.synonyms.genusOrMonomial'
                ],
                'scientificName' => [
                    'identifications.taxonomicEnrichments.synonyms.fullScientificName'
                ],
                'specificEpithet' => [
                    'identifications.taxonomicEnrichments.synonyms.specificEpithet'
                ],
                'infraspecificEpithet' => [
                    'identifications.taxonomicEnrichments.synonyms.infraspecificEpithet'
                ],
             	'vernacularName' => [
                    'identifications.taxonomicEnrichments.vernacularNames.name'
                ],
            ],
            'specimen' => [
                'genusOrMonomial' => [
                    'identifications.taxonomicEnrichments.synonyms.genusOrMonomial'
                ],
                'scientificName' => [
                    'identifications.taxonomicEnrichments.synonyms.fullScientificName'
                ],
                'specificEpithet' => [
                    'identifications.taxonomicEnrichments.synonyms.specificEpithet'
                ],
                'infraspecificEpithet' => [
                    'identifications.taxonomicEnrichments.synonyms.infraspecificEpithet'
                ],
             ],
        );
    }
    return $var;
}

/**
 * Name-releated paths
 * 
 * @return array
 */
function _nameHits () {
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
		);
	}
	return $var;
}

/**
 * Paths that will receive an ES boost in the condition
 * 
 * @return array
 */
function _boostPaths () {
	$var = &drupal_static(__FUNCTION__);
	if (!isset($var)) {
		$var = [
			'multimedia' => [
				'identifications.defaultClassification.genus' => 2,
				'identifications.scientificName.genusOrMonomial' => 2,
				'identifications.defaultClassification.specificEpithet' => 2,
				'identifications.scientificName.specificEpithet' => 2,
				'identifications.defaultClassification.infraspecificEpithet' => 2,
				'identifications.scientificName.infraspecificEpithet' => 1.5,
				'identifications.scientificName.fullScientificName' => 1.5,
				'identifications.vernacularNames.name' => 3,
                'identifications.taxonomicEnrichments.vernacularNames.name' => 2
			],			
			'specimen' => [
				'identifications.defaultClassification.genus' => 2,
				'identifications.scientificName.genusOrMonomial' => 2,
				'identifications.defaultClassification.specificEpithet' => 2,
				'identifications.scientificName.specificEpithet' => 2,
				'identifications.defaultClassification.infraspecificEpithet' => 1.5,
				'identifications.scientificName.infraspecificEpithet' => 1.5,
				'identifications.scientificName.fullScientificName' => 2,
				'identifications.vernacularNames.name' => 5,
                'identifications.taxonomicEnrichments.vernacularNames.name' => 2
			],
			'taxon' => [
				'defaultClassification.genus' => 2,
				'acceptedName.genusOrMonomial' => 2,
				'defaultClassification.specificEpithet' => 2,
				'acceptedName.specificEpithet' => 2,
				'defaultClassification.infraspecificEpithet' => 1.25,
				'acceptedName.infraspecificEpithet' => 1.25,
				'acceptedName.fullScientificName' => 2,
				'vernacularNames.name' => 3
			],
		];
	}
	return $var;
}

/* Do not print hits
 * 
 * Hits in array key are not printed if there also is a hit in the array value.
 * If value is null, hit is always hidden in results
 * 
 */
function _doNotPrintHits () {
	return [
		'locality' => 'localityText',
		'theme' => null,
	];
}


function _scientificNameElements () {
	$var = &drupal_static(__FUNCTION__);
	if (!isset($var)) {
		$var = [
			'genusOrMonomial', 
			'subgenus',
			'specificEpithet', 
			'infraspecificMarker',
			'infraspecificEpithet', 
			'authorshipVerbatim',
		];
	}
	return $var;
}

function _scientificNameElementsInItalics () {
	$var = &drupal_static(__FUNCTION__);
	if (!isset($var)) {
		$var = [
			'genusOrMonomial',
			'subgenus',
			'specificEpithet',
			'infraspecificEpithet',
		];
	}
	return $var;
}

function _groupByScientificNameElements () {
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

function _sortOptions () {
	$var = &drupal_static(__FUNCTION__);
	if (!isset($var)) {
		$var = [
			'specimen' => [
				t('relevance') => [
					'path' => 'sort=score',
				],
				t('specimen') . ' [A-Z]' => [
					'path' => 'sort=unitID&sortDirection=asc'
				],
				t('specimen') . ' [Z-A]' => [
					'path' => 'sort=unitID&sortDirection=desc'
				],
				t('scientific name') . ' [A-Z]' => [
					'path' => 'sort=identifications.scientificName.genusOrMonomial,'  .
						'identifications.scientificName.specificEpithet,' .
						'identifications.scientificName.infraspecificEpithet,' . 
						'identifications.scientificName.fullScientificName&' .
						'sortDirection=asc,asc,asc,asc'
				],
				t('scientific name') . ' [Z-A]' => [
					'path' => 'sort=identifications.scientificName.genusOrMonomial,'  .
						'identifications.scientificName.specificEpithet,' .
						'identifications.scientificName.infraspecificEpithet,' . 
						'identifications.scientificName.fullScientificName&' .
						'sortDirection=desc,desc,desc,desc'
				]
			],
			'names.specimens' => [
				t('relevance') => [
					'path' => 'sort=score'
				],
				t('scientific name') . ' [A-Z]' => [
					'path' => 'groupSort=name_asc'
				],
				t('scientific name') . ' [Z-A]' => [
					'path' => 'groupSort=name_desc'
				],
				t('specimen count') . ' [9-0]' => [
					'path' => 'groupSort=count_desc'
				],
				t('specimen count') . ' [0-9]' => [
					'path' => 'groupSort=count_asc'
				],
			],
			'taxon' => [
				t('relevance') => [
					'path' => 'sort=score'
				],
				t('name') . ' [A-Z]' => [
					'path' => 'sort=acceptedName.genusOrMonomial,' . 
						'acceptedName.specificEpithet,' . 
						'acceptedName.infraspecificEpithet&' .
						'sortDirection=asc,asc,asc'
				],
				t('name') . ' [Z-A]' => [
					'path' => 'sort=acceptedName.genusOrMonomial,' . 
						'acceptedName.specificEpithet,' . 
						'acceptedName.infraspecificEpithet&' .
						'sortDirection=desc,desc,desc'
				],
			],
			'names.taxa' => [
				t('relevance') => [
					'path' => 'sort=score'
				],
				t('name') . ' [A-Z]' => [
					'path' => 'groupSort=name_asc'
				],
				t('name') . ' [Z-A]' => [
					'path' => 'groupSort=name_desc'
				],
			],
		];
	}
	return $var;
}


<?php 
define('NDABIO_GMAPKEY', 'AIzaSyCv168azSiPAf0wjVe36gNqdANDqEXkpvQ');
define("NBABASEURLFILE", "/tmp/nbabase.txt");


function ndabio_config_form ($form, &$form_state) {
	$form['ndabio_config'] = array(
		'#type' => 'fieldset',
		'#title' => t('Naturalis Data API config') 
	);
	$form['ndabio_config']['ndabio_config_gmapkey'] = array(
		'#type' => 'textfield',
		'#title' => t('Google maps key'),
		'#default_value' => variable_get('ndabio_config_gmapkey', NDABIO_GMAPKEY),
		'#size' => 140,
		'#maxlength' => 200,
		'#description' => t('The key used by Google maps for a geographic search.') . '<br />' . 
			t('Default') . ': ' . NDABIO_GMAPKEY,'#required' => TRUE 
	);
	
	return system_settings_form($form);
}

/**
 * These fields are select in the search form
 * 
 * @return array
 */
function _advancedSelectFields () {
	return [
        'sourceSystem', 
		'collectionType',
		'typeStatus',
		'sex',
		'phaseOrStage',
		'kingdom',
		'kindOfUnit',
		'license'
	];
}

/**
 * These fields are multiselect in the search form
 * 
 * @return array
 */
function _advancedMultiSelectFields () {
	return [
		's_kindOfUnit',
		'm_license'
	];
}

/**
 * Advanced search form exceptions
 * 
 * Default setting for advanced search is to used "optimal operator" and
 * to use the search term as is (not split by space). 
 * This method lists any exceptions.
 * 
 * @return array
 */
function _nbaAdvancedSearchExceptions () {
    $var = &drupal_static(__FUNCTION__);
    if (!isset($var)) {
        $var = array(
            'multimedia' => [
                'localityText' => [
                    'split' => true,
                	'operator' => 'MATCHES'
                ],
              	'vernacularName' => [
                    'split' => false,
                	'operator' => 'CONTAINS'
                ],
            ],
            'specimen' => [
                'collectorsFieldNumber' => [
                    'split' => true,
                	'operator' => 'MATCHES'
                ],
                'gatheringAgent' => [
                    'split' => true,
                	'operator' => 'MATCHES'
                ],
                'localityText' => [
                    'split' => true,
                	'operator' => 'MATCHES'
                ],
                'vernacularName' => [
                    'split' => false,
                 	'operator' => 'CONTAINS'
                ],
                'unitID' => [
                    'split' => false,
                 	'operator' => 'EQUALS_IC'
                ],
            ],
            'taxon' => [
                'vernacularName' => [
                    'split' => false,
                 	'operator' => 'CONTAINS'
                ],
            ],
        );
    }
    return $var;
}

/**
 * Favourites in country list
 * 
 * @return array
 */
function _geoCountryFavourites () {
	return [
        'en' => ['Netherlands', 'Aruba', 'Bonaire', 'Curaçao', 'Saba', 'Sint Eustasius', 'Sint Maarten', 'Indonesia', 'Suriname'],
        'nl' => ['Nederland', 'Aruba', 'Bonaire', 'Curaçao', 'Saba', 'Sint Eustasius', 'Sint Maarten', 'Indonesië', 'Suriname'],
    ];
}

/**
 * Rename entries in municipality list
 * 
 * @return array
 */
function _geoMunicipalityFixes () {
	return [
        "'s-Gravenhage" => 'Den Haag',
        "'s-Hertogenbosch" => 'Den Bosch',
    ];
}

/**
 * Lookup for nature geo areas suffices
 * 
 * These suffices are used to append to nature areas: Area (Suffix)
 * 
 * @return array
 */
function _geoNatureAreasSuffices () {
	return [
		'Landschap Noord-Holland',
		'Staatsbosbeheer',
		'PWN',
		'Natura 2000',
		'Beschermde Natuurmonumenten',
		'Wetlands 2005',
	];
}


/**
 * Values to omit from kind of unit select
 * 
 * @return array
 */
function _discardKindOfUnitSelectValues () {
	return [
		'fossilspecimen',
		'indet.',
		'multimediaobject',
		'not a',
		'not applicable',
		'not',
		'other',
		'otherspecimen',
		'preservedspecimen',
		'unknown',
		'unspecified',
		'virtual specimen',
	];
}

/**
 * Dynamically fetch min size for NBA contains query
 * 
 * @return int
 */
function _nbaMinContainsStringSize () {
    $nbaMinContainsStringSize = &drupal_static(__FUNCTION__);
    if (!$nbaMinContainsStringSize) {
        $cacheId = 'nbaMinContainsStringSize';
        $cache = cache_get($cacheId, 'cache');
        if ($cache && !empty($cache->data)) {
            $nbaMinContainsStringSize = $cache->data;
            return $nbaMinContainsStringSize;
        }
        $client = _initNbaClient();
        $nbaMinContainsStringSize = $client->getOperatorContainsMinTermLength();
        cache_set($cacheId, $nbaMinContainsStringSize);
        unset($client);
    }
    return $nbaMinContainsStringSize;
}

/**
 * Dynamically fetch max size for NBA contains query
 * 
 * @return int
 */
function _nbaMaxContainsStringSize () {
    $nbaMaxContainsStringSize = &drupal_static(__FUNCTION__);
    if (!$nbaMaxContainsStringSize) {
        $cacheId = 'nbaMaxContainsStringSize(';
        $cache = cache_get($cacheId, 'cache');
        if ($cache && !empty($cache->data)) {
            $nbaMaxContainsStringSize = $cache->data;
            return $nbaMaxContainsStringSize;
        }
        $client = _initNbaClient();
        $nbaMaxContainsStringSize = $client->getOperatorContainsMaxTermLength();
        cache_set($cacheId, $nbaMaxContainsStringSize);
        unset($client);
    }
    return $nbaMaxContainsStringSize;
}

/**
 * Dynamically fetch max result windows for NBA taxon and specimen services
 * 
 * @return array
 */
function _nbaMaxResultWindow () {
    $nbaMaxResultWindow = &drupal_static(__FUNCTION__);
    if (!$nbaMaxResultWindow) {
        $cacheId = 'nbaMaxResultWindow';
        $cache = cache_get($cacheId, 'cache');
        if ($cache && !empty($cache->data)) {
            $nbaMaxResultWindow = $cache->data;
            return $nbaMaxResultWindow;
        }
        $client = _initNbaClient();
        $nbaMaxResultWindow = false;
        foreach (['taxon', 'specimen', 'multimedia'] as $service) {
        	try {
        		$nbaMaxResultWindow[$service] = $client->{$service}()->getIndexMaxResultWindow();
        	} catch (Exception $e) { }
        }
        cache_set($cacheId, $nbaMaxResultWindow);
        unset($client);
    }
    return $nbaMaxResultWindow;
    
}


/**
 * Dynamically fetch max result windows for NBA taxon and specimen services
 * 
 * @return array
 */
function _nbaMaxNumPerScientificNameGroup () {
    $nbaMaxNumPerScientificNameGroup = &drupal_static(__FUNCTION__);
    if (!$nbaMaxNumPerScientificNameGroup) {
        $cacheId = 'nbaMaxNumPerScientificNameGroup';
        $cache = cache_get($cacheId, 'cache');
        if ($cache && !empty($cache->data)) {
            $nbaMaxNumPerScientificNameGroup = $cache->data;
            return $nbaMaxNumPerScientificNameGroup;
        }
        $client = _initNbaClient();
        $nbaMaxNumPerScientificNameGroup = false;
        foreach (['taxon', 'specimen'] as $service) {
        	try {
        		$nbaMaxNumPerScientificNameGroup[$service] = 
        			$client->{$service}()->getGroupByScientificNameMaxNumBuckets();
        	} catch (Exception $e) { 
        		p($e);die();
        	}
        }
        cache_set($cacheId, $nbaMaxNumPerScientificNameGroup);
        unset($client);
    }
    return $nbaMaxNumPerScientificNameGroup;
    
}

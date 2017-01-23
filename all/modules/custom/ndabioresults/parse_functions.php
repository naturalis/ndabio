<?php
/**
 * Parses specimen media detail json to PHP array
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseSpecimenMediaDetail ($json) {
    if (!$json || !validJson($json)) {
		handleError('parseSpecimenMediaDetail: no or invalid json response');
	}
	$data = json_decode($json);
//p($data);
	$row = $data->searchResults[0];

	foreach ($row->result as $field => $value) {
		if (!is_array($value) && !is_object($value)) {
			$output[$field] = $value;
		}
	}

	$output['source'] = $row->result->associatedSpecimen->sourceSystem->name;
	//$output['navigation'] = getNavigation($data);
	$output['names'] = getSpecimenNames($row, array('idBlock' => 'associatedSpecimens'));
	$output['unitID'] = setUnitId($row->result->associatedSpecimen->unitID);
	$output['mediaUnitID'] = $row->result->unitID;
	$output['imgSrc'] = getImageUrl($row);
	$output['phaseOrStage'] = !empty($row->result->phasesOrStages) ?
	   $row->result->phasesOrStages :
	   $row->result->associatedSpecimen->phaseOrStage;
	$output['locality'] = !empty($row->result->gatheringEvents[0]->localityText) ?
	   $row->result->gatheringEvents[0]->localityText :
	   $row->result->associatedSpecimen->gatheringEvent->localityText;
	$output['dateTimeBegin'] = !empty($row->result->gatheringEvents[0]->dateTimeBegin) ?
	   timeStampToDate($row->result->gatheringEvents[0]->dateTimeBegin) :
	   timeStampToDate($row->result->associatedSpecimen->gatheringEvent->dateTimeBegin);

	return $output;
}




/**
 * Parses taxon media detail json to PHP array
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseTaxonMediaDetail ($json) {
	if (!$json || !validJson($json)) {
		handleError('parseTaxonMediaDetail: no or invalid json response');
	}
	$data = json_decode($json);
	$row = $data->searchResults[0];

	foreach ($row->result as $field => $value) {
		if (!is_array($value) && !is_object($value)) {
			$output[$field] = $value;
		}
	}

	$output['source'] = $row->result->associatedTaxon->sourceSystem->name;
	$output['acceptedName'] = formatScientificName(
		$row->result->associatedTaxon->acceptedName->fullScientificName,
		$row->result->associatedTaxon->acceptedName
	);
	$output['names'] = getTaxonMultimediaNames($row);
	$output['phaseOrStage'] = $row->result->phasesOrStages;
	//$output['navigation'] = getNavigation($data);
	$output['imgSrc'] = getImageUrl($row);
	$output['locality'] = $row->result->gatheringEvents[0]->localityText;
	$output['date'] = timeStampToDate($row->result->gatheringEvents[0]->dateTimeBegin);
	$output['license'] = $row->result->license;
	$output['sourceUrls'][$output['source']] = $row->result->associatedTaxon->recordURI;

	return $output;
}



/**
 * Parses taxon detail json to PHP array
 *
 * Optional: adds fields to exclude to $skipFields array
 *
 * @todo Descriptions are hard-coded for NSR and CoL
 * @param string $json NBA response
 * @return array $output
 */
function parseTaxonDetail ($json) {
	$skipFields = array(
		'objectPublic'
		// etc
	);
	if (!$json || !validJson($json)) {
		handleError('parseTaxonDetail: no or invalid json response');
	}
	$data = json_decode($json);

	$output['acceptedName'] = formatScientificName(
		$data->searchResults[0]->result->acceptedName->fullScientificName,
		$data->searchResults[0]->result->acceptedName
	);
	$output['taxonID'] = getTaxonId($data);
	$output['nameElements'] =
	   getScientificNameElementsWithDuplicates($data->searchResults[0]->result->acceptedName);
	$output['sourceUrls'] = getSourceUrls($data);
	foreach ($data->searchResults as $row) {
		$source = $row->result->sourceSystem->name;

		if (!empty($row->result->defaultClassification)) {
			$output['classifications']['default'][$source] =
				parseClassification($row->result->defaultClassification);
		}
		if (!empty($row->result->synonyms)) {
			foreach ($row->result->synonyms as $i => $synonym) {
				$output['synonyms'][$source][] = formatScientificName(
					$row->result->synonyms[$i]->fullScientificName,
					$row->result->synonyms[$i]
				);
			}
		}
		if (!empty($row->result->descriptions)) {
		    // @todo: hard coded for NSR and CoL
		    foreach ($row->result->descriptions as $i => $description) {
		        // NSR Dutch
		        if (strtolower($description->category) == 'algemeen') {
                    $output['descriptions']['Dutch'][$source] =
					   $description->description;
		        }
		        // NSR English
		        if (strtolower($description->category) == 'summary') {
                    $output['descriptions']['English'][$source] =
					   $description->description;
		        }
		        // CoL English
		        if (empty($description->category) && !empty($description->description)) {
                    $output['descriptions']['English'][$source] =
					   $description->description;
		        }
		    }
		}
		if (!empty($row->result->vernacularNames)) {
			foreach ($row->result->vernacularNames as $i => $name) {
				$output['commonNames'][$source][$name->language][] = $name->name;
			}

		}
	}
	return $output;
}



/**
 * Parses specimen detail json to PHP array
 *
 * Optional: adds fields to exclude to $skipFields array
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseSpecimenDetail ($json) {

    $skipFields = array(
        'objectPublic',
	    'sourceSystemId',
        'sourceID',
	    'owner',
	    'title',
	    'multiMediaPublic',
	    'licenseType',
	    'license',
	    'assemblyID',
	    'collectionType'
		// etc
	);
	if (!$json || !validJson($json)) {
		handleError('parseSpecimenDetail : no or invalid json response');
	}
	$data = json_decode($json);

	foreach ($data->searchResults[0]->result as $field => $value) {
		if (!is_array($value) && !is_object($value) && !in_array($field, $skipFields)) {
			$output[$field] = setUnitId($value, $field);
		}
	}
	$output['assemblageID'] = $data->searchResults[0]->result->assemblageID;
	$output['collectionType'] = $data->searchResults[0]->result->collectionType;
	$output['source'] = isset($data->searchResults[0]->result->sourceSystem) ?
	   $data->searchResults[0]->result->sourceSystem->name : '';
	$output['names'] = getSpecimenNames($data->searchResults[0], array('links' => $data->links));
	$output['vernaculars'] = getSpecimenVernaculars($data->searchResults[0]);
	$output['gatheringEvent'] = getGatheringEventSpecimens($data);
	$output['license'] = $data->searchResults[0]->result->license;
	$output['otherSpecimens'] = getOtherSpecimens($data);
	// $output['navigation'] = getNavigation($data);

	return $output;
}



/**
 * Gets other specimens in "specimen collection" (Brahms)
 *
 * @param array $row Other specimens in set section of NBA response
 * @return array|void Array with other specimens
 */
function getOtherSpecimens ($row) {
	if (!empty($row->searchResults[0]->result->otherSpecimensInSet)) {
		foreach ($row->searchResults[0]->result->otherSpecimensInSet as $i => $specimen) {
			$s = array();
			$s['unitID'] = setUnitId($specimen->unitID);
			$s['collectionType'] = $specimen->collectionType;
			$s['url'] = getSpecimenInCollectionUrl($row, $i);
			$c[] = $s;
		}
	}
	return isset($c) ? $c : null;
}



/**
 * Get previous/next links from NBA response
 *
 * @param array $data NBA response
 * @return array|void Array with previous and next links
 */
function getNavigation ($data) {
	if (isset($data->links) && !empty($data->links)) {
		foreach ($data->links as $link) {
			if ($link->rel == 'prev' || $link->rel == 'next') {
				$output[$link->rel] = $link->href;
			}
		}
	}
	return isset($output) ? $output : null;
}



/**
 * Returns url for a taxon associated with the specimen
 *
 * Quite a complicated way to find the appropriate url for a taxon. The entire
 * links object is passed and matched against the name components of the scientific
 * name. Only when a match is complete the link is considered matching
 *
 * @param object $links
 * @param array $scientificName
 * @return string|void Url to the name
 */
function getTaxonUrl ($links, $scientificName) {
	if (!empty($links)) {
		foreach ($links as $link) {
			if ($link->rel == '_taxon') {
			    // All parts in query should be present in $scientificName object
			    $parts = parse_url(urldecode($link->href));
                safe_parse_str($parts['query'], $q);
                $diff = array_diff($q, (array)$scientificName);
                if (empty($diff)) {
                    return $link->href;
                }
			}
		}
	}
	return false;
}




/**
 * Urls for data sources
 *
 * @param array $data NBA json response
 * @return array|void $output Array with key source name, value url
 */
function getSourceUrls ($data) {
    foreach ($data->searchResults as $row) {
        $urls[$row->result->sourceSystem->name] = $row->result->recordURI;
    }
    return isset($urls) ? $urls : null;
}



/**
 * Prints single source as formatted html
 *
 * @param array $data
 * @param string $source
 * @return string Formatted html
 */
function printSource($data, $source) {
    if (isset($data['sourceUrls'][$source])) {
        return '<a href="' . $data['sourceUrls'][$source] . '" target="_blank">' . $source . '</a>';
    }
    return $source;
}



/**
 * Parses classification of taxon
 *
 * @param object $classification Classification section of NBA response
 * @return array|void
 */
function parseClassification ($classification) {
    if (empty($classification) || empty($type)) {
        return $classification;
    }
    if ($type == 'system') {
        foreach ($classification as $rank) {
            $c[$rank->rank] = $rank->name;
        }
    }
    return isset($c) ? $c : $classification;
}




/**
 * Scientific names and their urls for a specimen
 *
 * @param array $row Individual record in NBA response
 * @param array $p: options
 *    links => links to species (optional)
 *    idBLock => alternate id block (optional)
 * @return array|void Array of names and their urls
 */
function getSpecimenNames ($row, $p) {
    $links = isset($p['links']) ? $p['links'] : $row->links;
    $idBlock = isset($p['idBlock']) ?
        $row->result->associatedSpecimen->identifications :
        $row->result->identifications;

    if (empty($idBlock)) {
        return array();
    }

    foreach ($idBlock as $i => $id) {
		$output[] = array(
			'name' => formatScientificName(
				$id->scientificName->fullScientificName,
				$id->scientificName
			),
			'url' => getTaxonUrl($links, $id->scientificName),
		    'preferred' => $id->preferred ? 1 : 0
		);
	}

	if (isset($output)) {
    	usort($output, function($a, $b) {
            return $b['preferred'] - $a['preferred'];
        });
	    return $output;
	}
	return array();
}


/**
 * Vernacular names for a specimen
 *
 * @param array $row Identification section of NBA response
 * @return array|void Array of names
 */
function getSpecimenVernaculars ($row) {
    if (!isset($row->result->identifications) || empty($row->result->identifications)) {
        return array();
    }
    foreach ($row->result->identifications as $id) {
		if (!empty($id->vernacularNames)) {
		    foreach ($id->vernacularNames as $name) {
		        $output[] = $name->name;
		    }
		}
	}
	return isset($output) ? $output : false;
}


/**
 * Gets gathering event data for specimen
 *
 * @param array $row Gathering event section of NBA response
 * @return array|void
 */
function getGatheringEventSpecimens ($row, $i = 0) {
	if (!empty($row->searchResults[$i]->result->gatheringEvent)) {
        $event = $row->searchResults[$i]->result->gatheringEvent;
		foreach ($event as $k => $v) {
		    if (!is_array($v) && !is_object($k) && $v != '') {
		        // Translate datetime from Unix to proper date
		        if ($k == 'dateTimeBegin' || $k == 'dateTimeEnd') {
		            $v = timeStampToDate($v);
		        }
                $d[$k] = $v;
		    }
		}
		if (!empty($event->gatheringAgents)) {
		    foreach ($event->gatheringAgents as $a) {
                $agent[] = $a->fullName . (!empty($a->organization) ?
                    ' (' . $a->organization . ')' : '');
		    }
		    $d['gatheringAgents'] = $agent;
		}
		if (!empty($event->siteCoordinates)) {
		    foreach ($event->siteCoordinates as $c) {
                if ($c->longitudeDecimal != 0 && $c->latitudeDecimal != 0) {
                    $coordinates['lat'] = $c->latitudeDecimal;
                    $coordinates['lon'] = $c->longitudeDecimal;
                }
		    }
		    $d['siteCoordinates'] = isset($coordinates) ?
		        $coordinates : null;
		}
	}
	return isset($d) ? $d : null;
}

/**
 * Parses multimedia json to PHP array
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseMultimedia ($json) {
	if (!$json || !validJson($json)) {
		handleError('parseMultimedia: no or invalid json response');
	}
	$data = json_decode($json);

    // @TODO: disabled navigation for the time being
// unset($_SESSION['ndaNavigation']);
// setNavigation($data);

	$output['searchTerms'] = getSearchTerms($data);
	$output['total'] = getTotalRows($data);

	if (!$output['searchTerms']) {
		handleError('parseMultimedia: invalid json response');
	}
	if ($output['total'] == 0) {
	    $output['results'] = array();
        return $output;
	}
	foreach ($data->searchResults as $row) {
		$type = !empty($row->result->associatedTaxon) ? 'associatedTaxon' :
            'associatedSpecimen';
		$d['title'] = $type == 'associatedTaxon' ? $row->result->title : '';
		$d['caption'] = $type == 'associatedTaxon' ? $row->result->caption : '';
		$d['score'] = $row->percentage;
		$d['url'] = getMultimediaDetailLink($row);
		$d['source'] = !empty($row->result->{$type}->sourceSystem) ?
            $row->result->{$type}->sourceSystem->name : '';
		list($d['imgSrc'], $d['format']) = getImageData($row);
		// Reset image url if this is stored in MediaLib;
		// use medium format to speed up loading times
		if (strpos($d['imgSrc'], 'medialib') !== false) {
            $d['imgSrc'] = str_replace('format/large', 'format/medium', $d['imgSrc']);
		}
		$d['hits'] = getHits($row, false);
		$d['taxon'] = getMultimediaTaxon($row, $output['searchTerms']);
		$d['unitID'] = getMultimediaUnitId($row, $output['searchTerms']);
		$output['results'][] = $d;
	}

	$output['self'] = getSelfLink($data);
	$output['showAll'] = getShowAll($data);
	$output['paginator'] = getPaginator($data);

	// Only set filter when performing initial search
	if ($output['searchTerms']['_maxResults'][0] == maxResultsInitial()) {
	    $_SESSION['ndaFilters']['multimedia'] = $output['showAll'];
	}

	return isset($output) ? $output : false;
}

/**
 * Gets url to multimedia detail
 *
 * @param array $row NBA response
 * @return string Url
 */
function getMultimediaDetailLink ($row) {
    foreach ($row->links as $link) {
        if ($link->rel == '_multimedia') {
            return $link->href;
        }
    }
}



/**
 * Gets unit id associated with multimedia
 *
 * @param array $row Json data
 * @param array $searchTerms Optional parameter so search terms can be highlighted
 * @return string|void Registration number (= unit id)
 */
function getMultimediaUnitId ($row, $searchTerms = false) {
    if (isset($row->result->associatedSpecimen->unitID)) {
        $output = setUnitId($row->result->associatedSpecimen->unitID);
        return $searchTerms ? highlightSearchTerms($output, $searchTerms) : $output;
    }
    return null;
}

/**
 * Gets scientific name associated with multimedia
 *
 * @param array $row Json data
 * @param array $searchTerms Optional parameter so search terms can be highlighted
 * @return string|void Scientific name
 */
function getMultimediaTaxon ($row, $searchTerms = false) {
    if (isset($row->result->associatedTaxon->acceptedName) &&
        !empty($row->result->associatedTaxon->acceptedName)) {
        return formatScientificName(
    		$row->result->associatedTaxon->acceptedName->fullScientificName,
    		$row->result->associatedTaxon->acceptedName,
            $searchTerms
	    );
    }
    if (isset($row->result->associatedSpecimen->identifications) &&
        !empty($row->result->associatedSpecimen->identifications)) {
        return formatScientificName(
    		$row->result->associatedSpecimen->identifications[0]->scientificName->fullScientificName,
    		$row->result->associatedSpecimen->identifications[0]->scientificName,
            $searchTerms
	    );
    }
    return null;
}

/**
 * Parses specimen data json searched by name to PHP array
 *
 * Unlike the other parse functions, this one may forward to json to "specialised"
 * function: parseSpecimensByMap(). Additionally,this function differentiates between
 * grouped results and results per single taxon.
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseSpecimensByTaxon ($json) {
	if (!$json || !validJson($json)) {
		handleError('parseSpecimensByTaxon: no or invalid json response');
	}
	$data = json_decode($json);
//p($data);
	$output['searchTerms'] = getSearchTerms($data);

	$output['total'] = getTotalRows($data);
	if (!$output['searchTerms']) {
		handleError('parseSpecimensByTaxon: invalid json response');
	}

    // If showMap parameter has been set, parsing and printing should be redirected
    // to parse-/printSpecimensByMap
    if (isset($output['searchTerms']['_showMap'])) {
        return parseSpecimensByMap($data);
    }

	if ($output['total'] == 0) {
	    $output['results'] = array();
        return $output;
	}

    // Parameter that determines if results are for group or single taxon
    $single = isset($output['searchTerms']['single']) ? true : false;
    $maxResults = isGroupService(specimenNamesService()) ?
        maxGroupResults() : maxResults();

    foreach ($data->resultGroups as $row) {
		$d = array();
		$d['name'] = formatScientificName(
			$row->sharedValue,
			$row->searchResults[0]->result->identifications[0]->scientificName,
    		$output['searchTerms']
		);
		$d['url'] = getTaxonUrl($row->searchResults[0]->links,
		    $row->searchResults[0]->result->identifications[0]->scientificName);
		$d['fullScientificName'] = $row->sharedValue;
		$d['count'] = isGroupService(specimenNamesService()) ?
            $row->totalSize : count($row->searchResults);
		$d['sources'] = getSources($row);
		$d['score'] = $row->searchResults[0]->percentage;
		foreach ($row->searchResults as $i => $sp) {
    		$assemblageID = $sp->result->assemblageID;
    		$s['unitID'] = setUnitId($sp->result->unitID);
    		$s['recordBasis'] = $sp->result->recordBasis;
    		$s['kindOfUnit'] = $sp->result->kindOfUnit;
    		$s['preparationType'] = $sp->result->preparationType;
    		$s['collectionType'] = $sp->result->collectionType;
    		$s['url'] = $sp->links[0]->href;
    		$s['score'] = $sp->score;
            empty($assemblageID) ? $d['specimens'][] = $s :
                $d['sets'][$assemblageID][] = $s;
		}
		$d['allLink'] = $d['count'] > $maxResults ?
            specimenNamesService() . '/?identifications.scientificName.fullScientificName.raw=' .
            urlencode($row->sharedValue) . '&_sort=unitID&_sortDirection=ASC' : '';
		$output['results'][] = $d;
	}

	$output['self'] = getSelfLink($data);
	$output['showAll'] = getShowAll($data, isGroupService(specimenNamesService()));
	$output['paginator'] = $single ?
	   getPaginatorWithinGroup($data) :
	   getPaginator($data, isGroupService(specimenNamesService()));
	$output['single'] = $single;

	// Only set filter when performing initial search
	if ($output['searchTerms']['_maxResults'][0] == maxResultsInitial()) {
	    $_SESSION['ndaFilters']['specimenName'] = $output['showAll'];
	}

	return isset($output) ? $output : false;
}



/**
 * Gets scientific names for taxon media detail response
 *
 * @param array $row search results section of json response
 * @return array|void Array with formatted names and their links
 */
function getTaxonMultimediaNames ($row) {
	if (!empty($row->result->associatedTaxon->acceptedName)) {
	    $output[] = array(
    		'name' => formatScientificName(
    			$row->result->associatedTaxon->acceptedName->fullScientificName,
    			$row->result->associatedTaxon->acceptedName
    		),
    		'url' => getTaxonUrl($row->links, $row->result->associatedTaxon->acceptedName)
    	);
	}
	return isset($output) ? $output : false;
}



/**
 * Parses specimen data json to PHP array
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseSpecimens ($json) {
	if (!$json || !validJson($json)) {
		handleError('parseSpecimens: no or invalid json response');
	}
	$data = json_decode($json);

	$output['searchTerms'] = getSearchTerms($data);
	$output['total'] = getTotalRows($data);
	if (!$output['searchTerms']) {
		handleError('parseSpecimens: invalid json response');
	}
	if ($output['total'] == 0) {
	    $output['results'] = array();
        return $output;
	}
	foreach ($data->searchResults as $row) {
		$d = array();
		$d['unitID'] = setUnitId($row->result->unitID);
		$d['url'] = $row->links[0]->href;
		$d['hits'] = getHits($row, false);
		$d['source'] = $row->result->sourceSystem->name;
		$d['score'] = $row->percentage;
		$d['names'] = getSpecimenNames($row);
		$output['results'][] = $d;
	}

	$output['self'] = getSelfLink($data);
	$output['showAll'] = getShowAll($data);
	$output['paginator'] = getPaginator($data);

	// Only set filter when performing initial search
	if ($output['searchTerms']['_maxResults'][0] == maxResultsInitial()) {
	    $_SESSION['ndaFilters']['specimen'] = $output['showAll'];
	}

	return isset($output) ? $output : false;
}


/**
 * Parses specimen data json searched by name and map to PHP array
 *
 * As the data arrives to this function through parseSpecimensByTaxon(),
 * json parsing and validation can be skipped.
 *
 * @param array $data Parsed json from parseSpecimensByTaxon()
 * @return array $output
 */
function parseSpecimensByMap ($data) {

	$output['searchTerms'] = getSearchTerms($data);
	$output['total'] = getTotalRows($data);
	$output['_showMap'] = true;

	foreach ($data->resultGroups as $row) {
		$d = array();
		$name = formatScientificName(
			$row->sharedValue,
		    // @todo
			//$row->searchResults[0]->result->identifications[getResultOffset($row)]->scientificName,
			$row->searchResults[0]->result->identifications[0]->scientificName,
		    getHits($row->searchResults[0])
		);
		$sources = getSources($row);
		foreach ($row->searchResults as $i => $sp) {
    		$d['name'] = $name;
    		$d['taxonUrl'] = getTaxonUrl($row->searchResults[0]->links,
		        $row->searchResults[0]->result->identifications[0]->scientificName);
    		$d['url'] = $sp->links[0]->href;
    		$d['source'] = implode(', ', $sources);
    		$d['assemblageID'] = $sp->result->assemblageID;
    		$d['unitID'] = setUnitId($sp->result->unitID);
    		$gatheringEvent = getGatheringEventSpecimens($row, $i);
    		$d['localityText'] = $gatheringEvent['localityText'];
    		$d['date'] = $gatheringEvent['dateTimeBegin'];
    		$d['lat'] = $gatheringEvent['siteCoordinates']['lat'];
    		$d['lon'] = $gatheringEvent['siteCoordinates']['lon'];
    		$output['results'][] = $d;
		}
	}

	$output['self'] = getSelfLink($data);
	return isset($output) ? $output : false;
}



/**
 * Gets _offset from json
 *
 * @param array $data Json
 * @return int Offset
 */
function getOffset ($data) {
    if (isset($data->queryParameters->_offset[0])) {
        return $data->queryParameters->_offset[0];
    }
    return 0;
}

/**
 * Gets _groupOffset from json
 *
 * @param array $data Json
 * @return int Group offset
 */
function getGroupOffset ($data) {
    if (isset($data->queryParameters->_groupOffset[0])) {
        return $data->queryParameters->_groupOffset[0];
    }
    return 0;
}

/**
 * Gets image url from json
 *
 * @param array $row Json
 * @return string|void Url
 */
function getImageUrl ($row) {
    if (!empty($row->result->serviceAccessPoints)) {
    	$key = key(get_object_vars($row->result->serviceAccessPoints));
    	return $row->result->serviceAccessPoints->{$key}->accessUri;
    }
    return null;
}

/**
 * Gets image url plus format from json
 *
 * @param array $row Json
 * @return array|void Array with url and format
 */
function getImageData ($row) {
    if (!empty($row->result->serviceAccessPoints)) {
    	$key = key(get_object_vars($row->result->serviceAccessPoints));
    	return array(
    	   $row->result->serviceAccessPoints->{$key}->accessUri,
    	   $row->result->serviceAccessPoints->{$key}->format
    	);
    }
    return null;
}

/**
 * Gets the fields containing data matching the search term(s)
 *
 * @param array $row Parsed json
 * @param boolean $stripTags Should html tags be removed?
 * @return array Array with field => value pairs
 */
function getHits ($row, $stripTags = true) {
    // Exclude matches in these fields
    $noHits = array(
        'fullScientificName',
        'theme',
        'raw'
    );
	foreach ($row->matchInfo as $info) {
		// Extract field from path.to.field; field is the last part
		$e = explode('.', $info->path);
		$field = end($e);
		if (!in_array($field, $noHits)) {
            $hits[$field] = $stripTags ? strip_tags($info->valueHighlighted) :
                $info->valueHighlighted;
		}
	}
	return isset($hits) ? $hits : array();
}




/**
 * Get url for Nth specimen in "collection"/set
 *
 * @param int $i Offset for specimen in searchResults->links
 * @return string|void Url
 */
function getSpecimenInCollectionUrl ($row, $i) {
	if (!empty($row->searchResults[0]->links)) {
		foreach ($row->searchResults[0]->links as $link) {
			if ($link->rel == 'specimen-detail.otherSpecimensInSet.' . $i) {
				return $link->href;
			}
		}
	}
	return null;
}


/**
 * Parses taxon json to PHP array
 *
 * @param string $json
 * @return array $output
 */
function parseTaxa ($json) {
    global $language;
	if (!$json || !validJson($json)) {
		handleError('parseTaxon: no or invalid json response');
	}
	$data = json_decode($json);

	$output['total'] = getTotalRows($data);
	$output['searchTerms'] = getSearchTerms($data);
	if (!$output['searchTerms']) {
		handleError('parseTaxon: invalid json response');
	}
	if ($output['total'] == 0 || empty($data->resultGroups)) {
	    $output['results'] = array();
        return $output;
	}
	foreach ($data->resultGroups as $row) {
		$d = array();
		// Accepted scientific name, synonym, or common name
		$d['type'] = getResultType($row);
		$d['rank'] = $row->searchResults[0]->result->taxonRank;
		$d['name'] = formatScientificName(
			strip_tags($row->searchResults[0]->result->acceptedName->fullScientificName),
			$row->searchResults[0]->result->acceptedName,
			$output['searchTerms']
		);
		if ($d['type'] == 'accepted') {
			$d['description'] = t(ucfirst($d['rank']));
		} else if ($d['type'] == 'synonym') {
            $offset = getTaxonSynonymOffset($row);
			$d['description'] = t('Synonym') . ': ' .
                formatScientificName(
    				strip_tags($row->searchResults[0]->result->synonyms[$offset]->fullScientificName),
    				$row->searchResults[0]->result->synonyms[$offset],
    				$output['searchTerms']
    			);
		} else if ($d['type'] == 'common') {
			$d['description'] = t('Common name(s)') . ': ';

			foreach ($row->searchResults[0]->matchInfo as $i => $info) {
                $vernaculars[] = highlightSearchTerms(
    				strip_tags($info->valueHighlighted),
    				$output['searchTerms']
    		    );
			}
			$d['description'] .= implode(', ', $vernaculars);
			/*
            foreach ($row->searchResults[0]->matchInfo as $i => $info) {
                $hits = explode('<span class="search_hit">', $info->valueHighlighted);
                foreach ($hits as $hit) {
                    $vernaculars[] = highlightSearchTerms(
            			trim(strip_tags($hit)),
            			$output['searchTerms']
            	    );
                }
            }
            $d['description'] .= implode(', ', array_filter($vernaculars));
            */
			unset($vernaculars);
		}

		$d['url'] = urldecode($row->searchResults[0]->links[0]->href);
		$d['sources'] = getSources($row);
		$d['commonNames'] = ($d['type'] != 'common' ? getCommonNames($row, true) : array());
		$d['score'] = $row->searchResults[0]->percentage;
		$output['results'][] = $d;
	}

	$output['self'] = getSelfLink($data);
	$output['showAll'] = getShowAll($data);
	$output['paginator'] = getPaginator($data);

	// Only set filter when performing initial search
	if ($output['searchTerms']['_maxResults'][0] == maxResultsInitial()) {
	    $_SESSION['ndaFilters']['taxon'] = $output['showAll'];
	}

	return isset($output) ? $output : false;
}

/** Gets offset of matched synonym in taxon response
 *
 * Indirect way to determine the offset of the matched synonym: check match
 * against value of field in synonyms and return offset of first hit
 *
 * @param array $row Parsed json
 * @return int|void $i
 */
function getTaxonSynonymOffset ($row) {
/*
    $path = $row->searchResults[0]->matchInfo[0]->path;
    $field = str_replace('synonyms.', '', $path);
    foreach ($row->searchResults[0]->result->synonyms as $i => $synonyms) {
        if ($synonyms->$field ==
            strip_tags($row->searchResults[0]->matchInfo[0]->valueHighlighted)) {
            return $i;
        }
    }
    return false;
*/
    $fields = $hits = array();
    // Determine offset of search results in synonyms
    // First create array with field => hit
    foreach ($row->searchResults[0]->matchInfo as $i => $info) {
        // Path should start with synonym.
        if (strpos($info->path, 'synonym') === 0) {
            // Possible hits are all listed in a single row, as such:
            // <span class="search_hit">HIT</span>
            $hightlights = explode('</span><span class="search_hit">', $info->valueHighlighted);
            $fields[str_replace('synonyms.', '', $info->path)] =
                array_unique(array_map('strip_tags', $hightlights));
        }
    }
    foreach ($row->searchResults[0]->result->synonyms as $i => $synonym) {
        foreach ($fields as $field => $matches) {
            foreach ($matches as $match) {
                if ($synonym->$field == $match) {
                    $hits[$i][] = $match;
                }
            }
        }
    }
    $hits = array_map('count', $hits);
    return array_search(max($hits), $hits);
}



/**
 * Returns all sources for taxon/specimen
 *
 * @param array $row Parsed json
 * @return array|void
 */
function getSources ($row) {
	foreach ($row->searchResults as $i => $obj) {
		$output[$obj->result->sourceSystem->name] = $i;
	}
	return isset($output) ? array_flip($output) : false;
}

/**
 * Gets common names for taxon
 *
 * Return format is array(name => language), so duplicates will be avoided.
 * Language check is optional. If selected, only common names for the
 * current interface language will be returned.
 *
 * @param array $row Parsed json
 * @param boolean $languageCheck
 * @return array|void
 */
function getCommonNames ($row, $languageCheck = false) {
	global $language;
	foreach ($row->searchResults as $i => $taxon) {
		if (isset($taxon->result->vernacularNames)) {
			foreach ($taxon->result->vernacularNames as $name) {
				// If language is set, only store when language of
				// common name matches that of interface...
				if ($languageCheck) {
					if ($name->language == $language->name) {
						$output[$name->name] = $name->language;
					}
				// ... else always return all names
				} else {
					$output[$name->name] = $name->language;
				}
			}
		}
	}
	return isset($output) ? $output : false;
}


/**
 * Decorates description in taxon result table
 *
 * @param array $row Parsed json
 * @return string
 */
function decorateDescription ($row) {
	return ($row['type'] != 'accepted' ?
		t(ucfirst($row['type'])) . ($row['type'] == 'common' ? ' ' . t('name') : '') .
		' ' . t('for') . ' ' :  '') . ($row['type'] == 'accepted' ? t(ucfirst($row['rank'])) :
		t($row['rank']));
}

/**
 * Gets Show all... link
 *
 * Show all link is shown only when the user does not come from a form and
 * when the number of results exceeds the maximum number of initial results.
 * The latter setting depends on the fact if it's a service that has regulr or grouped
 * results.
 *
 * @param array $data Parsed json
 * @param boolean $groupResult Service has grouped results?
 * @return string|void Url
 */
function getShowAll ($data, $groupResult = false) {
	if (isset($_SESSION['ndaRequestType']) && $_SESSION['ndaRequestType'] == 'form' &&
	    getTotalRows($data) > maxResultsInitial()) {
	    $self = getSelfLink($data);
	    if (!empty($self)) {
            return setUrlPars(
                geoShapeToSession($self, true),
                array('_maxResults' => $groupResult ? maxGroupResults() : maxResults()),
                true
            );
	    }
	}
	return null;
}

/**
 * Gets sort parameter
 *
 * Gets sort parameter from self link or, if self link is not provided,
 * returns default value
 *
 * @param string $self Self link
 * @param boolean $groupResult Service has grouped results?
 * @return string Result from self link or default value if self link is not provided
 */
function getSort ($self, $groupResult = false) {
    $p = $groupResult ? '_groupSort' : '_sort';
    if (!empty($self)) {
        $value = getUrlParValue(urldecode($self), $p);
        if (!empty($value)) {
            return $value;
        }
    }
    return $groupResult ? defaultGroupSort() : defaultSort();
}


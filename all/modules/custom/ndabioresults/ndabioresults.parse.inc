<?php


function _parseTaxonDetail ($data) {
	
//p($data);
	
	$service = 'names.taxa';

	$skipFields = [];

	foreach ((array) $data as $field => $value) {
		if (!is_array($value) && !is_object($value) && !in_array($field, $skipFields)) {
			$output[$field] = _setUnitId($value, $field);
		}
	}

	foreach ($data->taxa as $row) {
		$acceptedNames[] = _formatScientificName($row->acceptedName);
		$row = $row->taxonDetails;
		$source = $row->sourceSystem->name;

		if (isset($row->defaultClassification)) {
			$output['classifications']['default'][$source] =
				_parseClassification($row->defaultClassification);
		}
		if (isset($row->synonyms)) {
			foreach ($row->synonyms as $i => $synonym) {
				$output['synonyms'][$source][] = _formatScientificName($synonym);
			}
		}
		if (isset($row->descriptions)) {
		    // @todo: hard coded for NSR and CoL
		    foreach ($row->descriptions as $i => $description) {
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
		if (isset($row->vernacularNames)) {
			foreach ($row->vernacularNames as $i => $name) {
				$output['commonNames'][$source][$name->language][] = $name->name;
			}

		}
	}
	$output['acceptedName'] = $acceptedNames[0];
	$output['multimedia'] = $data->multimedia;
	$output['specimens'] = $data->specimens;
	
	
	return $output;
}





function _parseTaxa ($data, $options) {
	
	$service = 'names.taxa';
	
	$output['total'] = $data->totalSize;
	_getTaxonDetails($data);

//p($data);

	if ($output['total'] == 0 || empty($data->resultSet)) {
	    $output['results'] = [];
        return $output;
	}
	foreach ($data->resultSet as $i => $row) {
		// Accepted scientific name, synonym, or common name
		$d = $sources = $names = [];
		foreach ($row->item->taxa as $taxon) {
			
//die($taxon->sourceSystem->code);
			
			$hits = _getHits($service, $taxon);
			$type = _getResultType($hits);
			$sources[] = _getSourceNameBySourceCode($taxon->sourceSystem->code);
			if ($type == 'common') {
				$names['common'][] = _getTaxonVernaculars($service, $taxon, $hits, true);
			} else {
				$names[$type][] = _getTaxonScientificName($service, $taxon, $type, $hits);
			}
			
		}
		
		$d['type'] = _getResultType($hits);
		$d['rank'] = $row->item->taxa[0]->taxonDetails->taxonRank;
		$d['name'] = implode('<br>', array_unique($names['accepted']));
		if ($d['type'] == 'accepted') {
			$d['description'] = t(ucfirst($d['rank']));
		} else if ($d['type'] == 'synonym') {
			$d['description'] = t('Synonym') . ': ' .
                implode('; ', array_unique($names['synonym']));
		} else if ($d['type'] == 'common') {
			$d['description'] = t('Common name(s)') . ': ' .
				implode('; ', array_unique($names['common']));
		}

		$d['url'] = _setBasePath() . 'taxon/' . 
			urlencode(ucfirst(str_replace(' ', '_', $row->item->name))) . '/' . 
			http_build_query(_setDetailSearchTerms($service, $i));
		$d['sources'] = $sources;
		$d['commonNames'] = ($d['type'] != 'common' ? _getCommonNames($row, true) : []);
		$output['results'][] = $d;
	}

	// Show all link
	if (in_array('showAll', $options) && $output['total'] > maxResultsInitial()) {
		$output['showAll'] = _setBasePath() . 'result/taxon/' .
			_setShowAllQuery($output['total'], _getQueryTerms($service));
	}
	// Paginator
	if (in_array('paginator', $options)) {
		$output['paginator'] = 
			_getPaginator('specimen', $output['total'], _getPaginatorOffset($service));
	}
	
	return isset($output) ? $output : false;
}

function _getCommonNames ($row, $languageCheck = false) {
	global $language;
	foreach ($row->item->taxa as $i => $taxon) {
		if (isset($taxon->taxonDetails->vernacularNames)) {
			foreach ($taxon->taxonDetails->vernacularNames as $name) {
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


function _getResultType ($hits) {
	$result = [];
	foreach ($hits as $path => $hit) {
		if (strpos($path, 'synonyms') !== false) {
			$result[] = 'synonym';
		} else if (strpos($path, 'vernacularNames') !== false) {
			$result[] = 'common';
		} else {
			$result[] = 'accepted';
		}
	}
	foreach (['accepted', 'synonym', 'common'] as $type) {
		if (in_array($type, $result)) {
			return $type;
		}
	}
	return false;
}



function _parseMultimedia ($data, $options = []) {
	if (!isset($data->resultSet) || empty($data->resultSet)) {
		return false;
	}
	
	$service = 'multimedia';
	$output['total'] = _getTotalRows($data);
	
//p($data);
	
	foreach ($data->resultSet as $i => $row) {
		$type = isset($row->item->associatedTaxonReference) && 
			!empty($row->item->associatedTaxonReference) ?  'taxon' : 'specimen';
		$d['title'] = $type == 'taxon' && isset($row->item->title) ? 
			$row->item->title : null;
		$d['caption'] = $type == 'taxon' && isset($row->item->caption) ?
			$row->item->caption : null;
		$d['url'] = _setBasePath() . $service . '/' . urlencode($row->item->unitID) . '/' . 
			http_build_query(_setDetailSearchTerms($service, $i));
		$d['source'] = isset($row->item->sourceSystem->name) ? 
			$row->item->sourceSystem->name : null;
		$d['imgSrc'] = isset($row->item->serviceAccessPoints[0]->accessUri) ?
			$row->item->serviceAccessPoints[0]->accessUri: null;
		$d['format'] = isset($row->item->serviceAccessPoints[0]->format) ?
			$row->item->serviceAccessPoints[0]->format: null;
		// Reset image url if this is stored in MediaLib;
		// use medium format to speed up loading times
		if (strpos($d['imgSrc'], 'medialib') !== false) {
			$d['imgSrc'] = str_replace('format/large', 'format/medium', $d['imgSrc']);
		}
		$hits = _getHits($service, $row->item);
		$d['hits'] = _setNonNameHits($service, $hits);
		$d['taxon'] = _getSpecimenScientificNames($service, $row, $hits);
		$d['unitID'] = _getMultimediaUnitId($row, $hits);
		$output['results'][] = $d;
	}
	// Show all link
	if (in_array('showAll', $options) && $output['total'] > maxResultsInitial()) {
		$output['showAll'] = _setBasePath() . 'result/' . $service . '/' .
			_setShowAllQuery($output['total'], _getQueryTerms($service));
	}
	// Paginator
	if (in_array('paginator', $options)) {
		$output['paginator'] = 
			_getPaginator($service, _getTotalRows($data), _getPaginatorOffset($service));
	}
	
//p($output);	
	return isset($output) ? $output : false;
}

/**
 * Parses specimen media detail json to PHP array
 *
 * @param string $json NBA response
 * @return array $output
 */
function _parseSpecimenMediaDetail ($data) {
	if (!isset($data->id)) {
		return false;
	}
//p($data);	
	foreach ((array) $data as $field => $value) {
		if (!is_array($value) && !is_object($value)) {
			$output[$field] = $value;
		}
	}
	$output['source'] = $data->sourceSystem->name;
	$output['names'] = _getSpecimenNames($data->associatedSpecimen->identifications);
	$output['unitID'] = _setUnitId($data->associatedSpecimen->unitID);
	$output['mediaUnitID'] = $data->unitID;
	$output['imgSrc'] = isset($data->serviceAccessPoints[0]->accessUri) ?
		$data->serviceAccessPoints[0]->accessUri: null;
	$output['phaseOrStage'] = isset($data->phasesOrStages) ?
	    $data->phasesOrStages :
		isset($data->associatedSpecimen->phaseOrStage) ? 
			$data->associatedSpecimen->phaseOrStage : null;
	$output['locality'] = isset($data->gatheringEvents[0]->localityText) ?
	   $data->gatheringEvents[0]->localityText :
	   isset($data->associatedSpecimen->gatheringEvent->localityText) ?
			$data->associatedSpecimen->gatheringEvent->localityText : null;
	$output['dateTimeBegin'] = isset($data->gatheringEvents[0]->dateTimeBegin) ?
		_dateTimeToDate($data->gatheringEvents[0]->dateTimeBegin) :
		isset($data->associatedSpecimen->gatheringEvent->dateTimeBegin) ?
	   		_dateTimeToDate($data->associatedSpecimen->gatheringEvent->dateTimeBegin) : null;
//p($output);
	return $output;
}



function _parseSpecimenDetail ($data) {
	
	if (!isset($data->id)) {
		return false;
	}
//p($data);

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
	    'collectionType',
    	//'referrer'
		// etc
	);

	foreach ((array) $data as $field => $value) {
		if (!is_array($value) && !is_object($value) && !in_array($field, $skipFields)) {
			$output[$field] = _setUnitId($value, $field);
		}
	}
	
	$output['assemblageID'] = isset($data->assemblageID) ?
		_formatAssemblageId($data->assemblageID) : null;
	//$output['collectionType'] = $data->collectionType;
	$output['source'] = isset($data->sourceSystem) ? $data->sourceSystem->name : null;
	$output['names'] = _getSpecimenNames($data->identifications);
	$output['typeStatuses'] = _getSpecimenTypeStatuses($data->identifications);
	$output['vernaculars'] = _getSpecimenVernaculars($data->identifications);
	$output['gatheringEvent'] = _getGatheringEventSpecimens($data->gatheringEvent);
	//$output['license'] = $data->searchResults[0]->result->license;
	$output['otherSpecimens'] = isset($data->assemblageID) ? _getOtherSpecimens($data) : null;
	$output['multimedia'] = $data->multimedia;
	return $output;
}




/**
 * Get url for Nth specimen in "collection"/set
 *
 * @param int $i Offset for specimen in searchResults->links
 * @return string|void Url
 */
function _getSpecimenInCollectionUrl ($data, $scientificNameGroup) {
	foreach ($data->identifications as $id) {
		if ($id->scientificName->scientificNameGroup == $scientificNameGroup) {
			return _setBasePath() . 'specimen/' . urlencode($data->unitID);
		}
	}
	return null;
}





/**
 * Parses taxon media detail json to PHP array
 *
 * @param string $json NBA response
 * @return array $output
 */
function _parseTaxonMediaDetail ($data) {
	if (!isset($data->id)) {
		return false;
	}
	
//p($data);	
	foreach ((array) $data as $field => $value) {
		if (!is_array($value) && !is_object($value)) {
			$output[$field] = $value;
		}
	}
	$output['source'] = $data->sourceSystem->name;
	$output['acceptedName'] = _getScientificName($data->associatedTaxon);
	$output['acceptedNameUrl'] = _getTaxonUrl($data->associatedTaxon);
	$output['phaseOrStage'] = isset($data->phasesOrStages) ?
		$data->phasesOrStages : null;
	$output['imgSrc'] = isset($data->serviceAccessPoints[0]->accessUri) ?
		$data->serviceAccessPoints[0]->accessUri: null;
	$output['locality'] = isset($data->gatheringEvents[0]->localityText) ?
		$data->gatheringEvents[0]->localityText : null;
	$output['date'] = isset($data->gatheringEvents[0]->dateTimeBegin) ?
		_dateTimeToDate($data->gatheringEvents[0]->dateTimeBegin) : null;
	$output['license'] = $data->license;
	$output['sourceUrls'][$output['source']] = $data->associatedTaxon->recordURI;
	
//p($output);
	
	return $output;
}

function _getScientificName ($object, $full = true) {
//p($object);	
	// Can be used to generate a full italicized name (default) or 
	// a simple non-formatted name without authorship
	$elements = $full ? scientificNameElements() : scientificNameElementsInItalics();
	// Name can be stored in either acceptedName (taxon) or 
	// scientificName (specimen); try both
	foreach (['acceptedName', 'scientificName'] as $path) {
		foreach ($elements as $i => $element) {
			$name[$i] = isset($object->{$path}->{$element}) && 
				!empty(trim($object->{$path}->{$element})) ?
				trim($object->{$path}->{$element}) : null;
			// Italics only for full option
			if (!empty($name[$i]) && $full &&
				in_array($element, scientificNameElementsInItalics())) {
				$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
			}
		}
		// Some specimens don't have a properly formatted name;
		// revert to fullScientificName
		if ($path == 'scientificName' && empty($name[0])) {
			$name[0] = $object->{$path}->fullScientificName;
			unset($name[1], $name[2], $name[3]);
		}
		if (!empty(array_filter($name))) {
			return implode(' ', array_filter($name));
		}
	}
	return null;
}


function _getTaxonUrl ($object, $checkNba = true) {
	// Name can be stored in either acceptedName (taxon) or 
	// scientificName (specimen); try both
	foreach (['acceptedName', 'scientificName'] as $path) {
		foreach (scientificNameElementsInItalics() as $i => $element) {
			$name[$i] = isset($object->{$path}->{$element}) &&
				!empty(trim($object->{$path}->{$element})) ?
				trim($object->{$path}->{$element}) : null;
		}
		if (!empty(array_filter($name))) {
			$url = _setBasePath() . 'taxon/' . implode('_', array_filter($name));
			// Only fetch if we're sure taxon exists in NBA
			if (!$checkNba || $checkNba && _getTaxonFromNba($name)) {
				return $url;
			}
		}
	}
	return null;
}

function _setDetailSearchTerms ($service, $i) {
	// Differentiate between from details and general!!
	$from = (int) _getQueryTerms($service)['from'];
	$terms = _getQueryTerms($service);
	if (isset($terms['size'])) {
		unset($terms['size']);
	}
	$terms['from'] = max(0, $from + $i - 1);
	return $terms;
}



function _setNonNameHits ($service, $hits = []) {
	if (!empty($hits)) {
		foreach ($hits as $path => $hit) {
			if (in_array($path, nameHits()[$service])) {
				unset($hits[$path]);
			}
		}
		return _highlightHits($service, $hits);
	}
}

function _getTaxonVernaculars ($service, $taxon, $hits, $hitsOnly = false) {
	if (isset($taxon->vernacularNames)) {
		foreach (_getQueryPaths($service) as $path => $value) {
			$paths[str_replace('taxa.', '', $path)] = $value;
		}
		// Same for hits
		foreach ($hits as $path => $value) {
			$temp[str_replace('taxa.', '', $path)] = $value;
		}
		$hits = isset($temp) ? $temp : $hits;

//p($taxon); p($paths); p($hits); echo $type; die();
	
		foreach ($taxon->vernacularNames as $i => $name) {
			$vernacular = new stdClass();
			$vernacular->name = _highlightMatch($name->name, 
				$paths['vernacularNames.name']['values']);
			$vernacular->language = $name->language;
			$vernaculars[$i] = $vernacular;
		}
		if ($hitsOnly) {
			array_udiff($vernaculars, $taxon->vernacularNames,
				function ($a, $b) {
					return strcmp($a->name, $b->name);
				}
			);
		}
		return $vernaculars;
	}
	return false;
}

function _getTaxonScientificName ($service, $taxon, $type, $hits = []) {
	// Trim taxa prefix from path to facilite highlighting
	if ($service) {
		foreach (_getQueryPaths($service) as $path => $value) {
			$paths[str_replace('taxa.', '', $path)] = $value;
		}
	}
	// Same for hits
	foreach ($hits as $path => $value) {
		$temp[str_replace('taxa.', '', $path)] = $value;
	}
	$hits = isset($temp) ? $temp : $hits;
	$type = $type == 'synonym' ? 'synonyms' : 'acceptedName';

	$name = [];
	// Elements in regular scientific name elements
	foreach (scientificNameElements() as $i => $element) {
		$name[$i] = isset($taxon->{$type}->{$element}) && 
			!empty(trim($taxon->{$type}->{$element})) ? 
			trim($taxon->{$type}->{$element}) : '';
		// Highlight (assume always LIKE operator for name fields)
		if (isset($hits[$type . '.' . $element])) {
			$name[$i] = _highlightMatch($taxon->{$type}->{$element}, 
				$paths[$type . '.' . $element]['values']);
		}
		// Italics
		if (!empty($name[$i]) && in_array($element, scientificNameElementsInItalics())) {
			$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
		}
	}
	return !empty($name) ? implode(' ', array_filter($name)) : false;
}

function _formatScientificName ($object) {
	$name = [];
	// Elements in regular scientific name elements
	foreach (scientificNameElements() as $i => $element) {
		$name[$i] = isset($object->{$element}) && 
			!empty(trim($object->{$element})) ? 
			trim($object->{$element}) : '';
		// Italics
		if (!empty($name[$i]) && in_array($element, scientificNameElementsInItalics())) {
			$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
		}
	}
	// Only fullScientificName is available; genus, etc are empty
	if (empty($name[0])) {
		$name[0] = $object->fullScientificName;
		unset($name[1], $name[2], $name[3]);
	}
	return !empty($name) ? implode(' ', array_filter($name)) : false;
}

function _getSpecimenScientificNames ($service, $row, $hits = [], $createLinks = false) {
	$paths = _getQueryPaths($service);
	foreach ($row->item->identifications as $j => $identification) {
		$name = [];
		// Elements in regular scientific name elements
		foreach (scientificNameElements() as $i => $element) {
			$name[$i] = isset($identification->scientificName->{$element}) && 
				!empty(trim($identification->scientificName->{$element})) ? 
				trim($identification->scientificName->{$element}) : '';
			// Highlight (assume always LIKE operator for name fields)
			if (!empty($name[$i]) && isset($hits['identifications.scientificName.' . $element])) {
				$name[$i] = _highlightMatch($identification->scientificName->{$element}, 
					$paths['identifications.scientificName.' . $element]['values']);
			}
			// Italics
			if (!empty($name[$i]) && in_array($element, scientificNameElementsInItalics())) {
				$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
			}
		}
		if (!empty($name)) {
			// Could also be a hit in fullScientificName; try highlighting
			if (isset($paths['identifications.scientificName.fullScientificName'])) {
				foreach ($name as $i => $element) {
					// Only add if not highlighted yet
					if (strpos($element, 'class="result-query"') === false) {
						$name[$i] = _highlightMatch($name[$i], 
							$paths['identifications.scientificName.fullScientificName']['values']);
					}
				}
			}
			// Only fullScientificName is available; genus, etc are empty
			if (empty($name[0])) {
				$name[0] = $identification->scientificName->fullScientificName;
				unset($name[1], $name[2], $name[3]);
				// Try highlighting
				if (isset($paths['identifications.scientificName.fullScientificName'])) {
					$name[0] = _highlightMatch($name[0], 
						$paths['identifications.scientificName.fullScientificName']['values']);
				}
			}
			$names[$j] = implode(' ', array_filter($name));
		}
		if ($createLinks) {
			$url = _getTaxonUrl($identification, true);
			if ($url) {
				$names[$j] = '<a href="' . $url . '">' . $names[$j] . '</a>';
			}
		}
	}
	return isset($names) ? implode('; ', array_unique($names)) : false;
}

function _getMultimediaUnitId ($row, $hits = []) {
	if (isset($row->item->associatedSpecimenReference)) {
		$pos = strpos($row->item->associatedSpecimenReference, '@');
		$id = substr($row->item->associatedSpecimenReference, 0, $pos);
		// Highlight
		if (isset($hits['unitID'])) {
			$highlight = _highlightMatch($id, ['unitID']);
			$id = str_replace($id, _setUnitId($id), $highlight);
		}
		return $id;
	}
	return null;
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
function _parseSpecimensMap ($data) {
//p($data);
	$output['total'] = $data->resultSet[0]->item->specimenCount;
	$d['acceptedNames'] = _getSpecimenAcceptedNames($data->resultSet[0]);
	
	
	foreach ($data->resultSet[0]->item->specimens as $i => $specimen) {
		$d['nonAcceptedNames'] = [];
		$d['unitID'] = _setUnitId($specimen->unitID);
		$d['source'] = _getSourceNameBySourceCode($specimen->sourceSystem->code);
		$d['assemblageID'] = _formatAssemblageId($specimen->assemblageID);
		$s['recordBasis'] = $specimen->recordBasis;
		$d['kindOfUnit'] = $specimen->kindOfUnit;
		$d['taxonUrl'] = _getTaxonUrl($specimen);
		$d['url'] = _setBasePath() . 'specimen/' . urlencode($d['unitID']);
		$d['localityText'] = isset($specimen->gatheringEvent->localityText) ?
			$specimen->gatheringEvent->localityText : null;
		$d['date'] = isset($specimen->gatheringEvent->dateTimeBegin) ?
			_dateTimeToDate($specimen->gatheringEvent->dateTimeBegin) : null;
		$d['lat'] = $specimen->gatheringEvent->siteCoordinates[0]->geoShape->coordinates[1];
		$d['lon'] = $specimen->gatheringEvent->siteCoordinates[0]->geoShape->coordinates[0];
		
		if (empty($d['acceptedNames'])) {
			$name = $specimen->matchingIdentifications[0]->scientificName;
			$d['nonAcceptedNames'][md5(serialize($name))] = $name;
		}
		
		$output['results'][] = $d;
	}

	$name = _setSpecimenScientificName($d);
	for ($i = 0; $i < count($output['results']); $i++) {
		unset($output['results'][$i]['nonAcceptedNames'], $output['results'][$i]['acceptedNames']);
		$output['results'][$i]['name'] = $name;
	}
	
	if ($output['total'] > maxResults() && count($output['results']) <= maxResults()) {
		$terms = _getQueryTerms('names.specimens');
		$terms['size'] = $output['total'];
		$url = _setBasePath() . 'result/specimen/map/' . 
			urlencode($data->resultSet[0]->item->name) . '/' . http_build_query($terms);
		$output['message'] = sprintf(t('The first %s specimens are displayed'), maxResults()) . 
			'. <a href="' . $url . '">' . sprintf(t('Display all %s specimens'), $output['total']) . ".</a>\n";
	} else if ($output['total'] > 1) {
		$output['message'] = sprintf(
			t('%s specimens are displayed'), 
			count($output['results'])
		) . '.';
	}
	return isset($output) ? $output : false;
}

function _parseSpecimens ($data, $options = []) {
	if (!isset($data->resultSet) || empty($data->resultSet)) {
		return false;
	}
	
	$service = 'specimen';
	
	$output['total'] = $data->totalSize;
	
//p($data);
	
	foreach ($data->resultSet as $i => $row) {
		$d = [];
		//$d['url'] = _setSpecimensAllLink($row);
		$d['source'] = $row->item->sourceSystem->name;

		$d['unitID'] = _setUnitId($row->item->unitID);
		$d['recordBasis'] = $row->item->recordBasis;
		$d['kindOfUnit'] = $row->item->kindOfUnit;
		$d['preparationType'] = $row->item->preparationType;
		$d['collectionType'] = $row->item->collectionType;
		$d['url'] = _setBasePath() . 'specimen/' . urlencode($row->item->unitID) . '/' . 
			http_build_query(_setDetailSearchTerms($service, $i));
		
		$hits = _getHits($service, $row->item);
		$d['hits'] = _setNonNameHits($service, $hits);
		$d['names'] = _getSpecimenScientificNames($service, $row, $hits, true);			
		$output['results'][] = $d;
	}
/*	
	$terms = _getStoredQueryTerms($service);
	$terms['from'] = 0;
*/	
	// Show all link
	if (in_array('showAll', $options) && $output['total'] > maxResultsInitial()) {
		$output['showAll'] = _setBasePath() . 'result/specimen/' .
			_setShowAllQuery($output['total'], _getQueryTerms($service));
	}
	// Paginator
	if (in_array('paginator', $options)) {
		$output['paginator'] = 
			_getPaginator($service, $output['total'], _getPaginatorOffset($service));
	}
	return $output;
}

function _getReferredSearch ($url) {
	safe_parse_str($url, $terms);
	return isset($terms['referrer']) ? _decodeReferrer($terms['referrer']) : false;
}

function _setSortUrl ($path, $direction) {
	return _resetUrl() . ($path == 'score' ? '' : '&sort=' . $path . 
		'&sortDirection=' . $direction);
}

function _getCurrentSort () {
	$pathComponents = explode('/', _getCurrentUrl());
	safe_parse_str(array_pop($pathComponents), $terms);
	return [
		'path' => isset($terms['sort']) ? $terms['sort'] : 'score',
		'direction' => isset($terms['sortDirection']) ? $terms['sortDirection'] : null
	];
}

// Strips sort parameters and sets from to 0
function _resetUrl () {
	$pathComponents = explode('/', _getCurrentUrl());
	$path = array_pop($pathComponents);
	safe_parse_str($path, $terms);
	foreach (['sort', 'sortDirection', 'service'] as $flag) {
		if (isset($terms[$flag])) {
			unset($terms[$flag]);
		}
	}
	$terms['from'] = 0;
	return implode('/', $pathComponents) . '/' . http_build_query($terms);
}

function _setTaxonId ($object) {
	foreach (scientificNameElementsInItalics() as $element) {
		$name[] = isset($object->{$element}) && !empty(isset($object->{$element})) ? 
			$object->{$element} : null;
	}
	return ucfirst(implode('_', array_filter($name)));
}


function _parseSpecimensTaxon ($data, $options = []) {
	if (!isset($data->resultSet) || empty($data->resultSet)) {
		return false;
	}
	$service = 'names.specimens';
	// Default sort is not score, must be set explicitly!
	$sortExtension = '';
	if (!array_key_exists('sort', _getQueryTerms($service))) {
		$sortExtension = '&sort=identifications.scientificName.genusOrMonomial,' .
			'identifications.scientificName.specificEpithet,' .
			'identifications.scientificName.infraspecificEpithet&' .
			'sortDirection=asc,asc,asc';
	}
	$output['total'] = $data->totalSize;
	_getSpecimenDetails($data);
//p($data);
	//@todo: from
	//$from = (int) _getStoredQueryTerms($service)['from'];
	foreach ($data->resultSet as $row) {
		$d = [];
		// to do: add highlighting, author, italics
		$d['scientificNameGroup'] = $row->item->name;
		$d['acceptedNames'] = _getSpecimenAcceptedNames($row);
		//$d['url'] = _setSpecimensAllLink($row);
		$d['count'] = $row->item->specimenCount;
		$d['sources'] = _getSpecimenSources($row);
		$d['nameHits'] = $d['nonAcceptedNames'] = [];
		//$d['score'] = 0;
		foreach ($row->item->specimens as $i => $sp) {
			$specimen = $sp->specimenDetails;
			$s['unitID'] = _setUnitId($specimen->unitID);
			$s['recordBasis'] = isset($specimen->recordBasis) ? 
				$specimen->recordBasis : null;
			$s['kindOfUnit'] = isset($specimen->kindOfUnit) ? 
				$specimen->kindOfUnit : null;
			$s['preparationType'] = isset($specimen->preparationType) ? 
				$specimen->preparationType : null;
			$s['collectionType'] = $specimen->collectionType;
			$s['url'] = _setBasePath() . 'specimen/' . urlencode($specimen->unitID) . '/' . 
				urlencode($row->item->name) . '/' .
				http_build_query(_setDetailSearchTerms($service, $i)) . $sortExtension;
			$hits = _getHits($service, $sp);
			$s['hits'] = _setNonNameHits($service, $hits);
			$d['nameHits'] = _appendNameHits($d['nameHits'], $hits);
			// Only bother with non-accepted names if no accepted names are available
			if (empty($d['acceptedNames'])) {
				$d['nonAcceptedNames'] = 
					_appendNonAcceptedNames($d['nonAcceptedNames'], $sp, $row->item->name);
			}
			!isset($specimen->assemblageID) ? $d['specimens'][] = $s :
				$d['sets'][_formatAssemblageId($specimen->assemblageID)][] = $s;
		}
		$d['fullScientificName'] = _setSpecimenScientificName($d);
//@todo: restore when NBA bug is fixed!		
//$d['allLink'] = $d['count'] > maxResultsInitial() ?
		$d['allLink'] = $d['count'] > 1 ?
			_setBasePath() . 'result/specimen/taxon/' . urlencode($row->item->name) . '/' .
			http_build_query(_getQueryTerms($service)) . $sortExtension : null;
		
		// No use for nameHits anymore; discard
		unset($d['nameHits']);
		$d['mapUrl'] = null;
		if (_isGeoSearch()) {
			$d['mapUrl'] = _setBasePath() . 'result/specimen/map/' . 
				urlencode($row->item->name) . '/' . http_build_query(_getQueryTerms($service));
		}
		$output['results'][] = $d;
	}
	
/*	
	$terms = _getQueryTerms($service);
	$terms['from'] = 0;
*/	
	$output['specimensTotal'] = isset($data->specimensTotal) ? 
		$data->specimensTotal : $output['results'][0]['count'];
	$output['paginatorTotal'] = isset($data->specimensTotal) ? 
		$data->totalSize : $output['results'][0]['count'];
	$output['from'] = isset($data->specimensFrom) ? 
		$data->specimensFrom : _getPaginatorOffset($service);
	
	// Show all link
	if (in_array('showAll', $options) && $output['total'] > maxResultsInitial()) {
		$output['showAll'] = _setBasePath() . 'result/specimen/' .
			_setShowAllQuery($output['total'], _getQueryTerms($service)) . 
			$sortExtension;
	}
	// Paginator
	if (in_array('paginator', $options)) {
		$output['paginator'] = 
			_getPaginator($service, $output['paginatorTotal'], $output['from']);
	}
	return $output;
}

function _formatAssemblageId ($id) {
	$parts = explode('@', $id);
	if (count($parts) == 2) {
		return $parts[1] . '-' . $parts[0];
	}
	return false;
}


function _setSpecimenScientificName ($data) {
	$paths = _getQueryPaths('names.specimens');
	$hits = isset($data['nameHits']) ? $data['nameHits'] : [];
	$source = !empty($data['acceptedNames']) ? $data['acceptedNames'] : $data['nonAcceptedNames'];

	// First extract and format available scientific names...
	// If a taxon occurs in NSR/CoL, use those sources to format the name.
	// If not, used the scientific names associated with the preferred identifications
	// for each specimen.
	foreach ($source as $j => $identification) {
		$name = [];
		// Elements in regular scientific name elements
		// Use individual name parts for CRS records! CRS specimens can be identified by not
		// being aggregated in a set:
		if (!isset($data['sets'])) {
			foreach (scientificNameElements() as $i => $element) {
				$name[$i] = isset($identification->{$element}) && !empty(trim($identification->{$element})) ? 
					trim($identification->{$element}) : '';
				// Hits can be in both defaultClassification and scientificName
				foreach (['defaultClassification', 'scientificName'] as $category) {
					$hitPath = 'identifications.' . $category . '.' . $element;
					// Highlight (assume always LIKE operator for name fields)
					if (!empty($name[$i]) && isset($hits[$hitPath])) {
						$name[$i] = _highlightMatch($identification->{$element}, $paths[$hitPath]['values']);
					}
				}
				// Italics
				if (!empty($name[$i]) && in_array($element, scientificNameElementsInItalics())) {
					$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
				}
			}
		// BRAHMS: generate from fullScientificName
		} else {
			// First highlight
			$name[0] = _highlightMatch($identification->fullScientificName, array_unique(array_values($hits)));
			foreach (scientificNameElementsInItalics() as $element) {
				if (isset($identification->{$element}) && !empty(trim($identification->{$element}))) {
					$name[0] = str_replace($identification->{$element}, 
						'<span class="scientific">' . $identification->{$element} . '</span>', $name[0]);
				}
			}
		}
		
//p($data['nonAcceptedNames']); p($name); die();
		
		if (!empty($name)) {
			// Could also be a hit in fullScientificName; try highlighting
			if (isset($paths['identifications.scientificName.fullScientificName'])) {
				foreach ($name as $i => $element) {
					// Only add if not highlighted yet
					if (strpos($element, 'class="result-query"') === false) {
						$name[$i] = _highlightMatch($name[$i], 
							$paths['identifications.scientificName.fullScientificName']['values']);
					}
				}
			}
			// Only fullScientificName is available; genus, etc are empty
			if (empty($name[0])) {
				$name[0] = $identification->fullScientificName;
				unset($name[1], $name[2], $name[3]);
				// Try highlighting
				if (isset($paths['identifications.scientificName.fullScientificName'])) {
					$name[0] = _highlightMatch($name[0], 
						$paths['identifications.scientificName.fullScientificName']['values']);
				}
			}
			$names[isset($identification->source) ? $identification->source : $j] = 
				implode(' ', array_filter($name));
		}
	}
	// if we end up with one name it's simple
	if (count($names) == 1) {
		return array_values($names)[0];
	}
	// If acceptedNames has been used, return the NSR name
	if (!empty($data['acceptedNames'])) {
		return $names['NSR'];
	}
	// Return formatted version of scientificNameGroup
	foreach ($names as $i => $name) {
		if (strtolower(strip_tags($name)) == $data['scientificNameGroup']) {
			return $name;
		}
	}
	// If we have reached this point, we might as well return the first non-accepted name
	return array_values($names)[0];
}


function _appendNonAcceptedNames ($nonAcceptedNames, $row, $scientificNameGroup) {
	foreach ($row->specimenDetails->identifications as $identification) {
		if ($scientificNameGroup == $identification->scientificName->scientificNameGroup) {
			$nonAcceptedNames[md5(serialize($identification->scientificName))] = 
				$identification->scientificName;
		}
	}
	return $nonAcceptedNames;
}

function _appendNameHits ($nameHits, $hits = []) {
	if (!empty($hits)) {
		foreach ($hits as $path => $value) {
			if (in_array($path, nameHits()['names.specimens'])) {
				$nameHits[$path] = $value;
			}
		}
	}
	return $nameHits;
}

function _getSpecimenAcceptedNames ($row) {
//p($row);
	if (isset($row->item->taxa)) {
		foreach ($row->item->taxa as $taxon) {
			$taxon->acceptedName->source = $taxon->sourceSystem->code;
			$data[$taxon->acceptedName->fullScientificName] = $taxon->acceptedName;
		}
	}
	return isset($data) ? array_values($data) : null;
}


/* Old
function _getHits ($service, $result) {
	// Path used are stored in session
	$queryPaths = _getQueryPaths($service);
	if (!$queryPaths) {
		return false;
	}
	foreach ($queryPaths as $path => $item) {
		// Convert NBA path to object path
		$pathElements = explode('.', $path);
		// Chop off first part of path in case of names service
		if (strpos($service, '.') !== false) {
			unset($pathElements[0]);
		}
		$hits = _getHitInResult($pathElements, $result, 
			$item['value'], $item['operator']);
		if (!empty($hits)) {
			$output[$path] = $hits[0];
		}
	}
	return isset($output) ? $output : false;
}
*/


function _getHits ($service, $result) {
	// Path used are stored in session
	$queryPaths = _getQueryPaths($service);
	if (!$queryPaths) {
		return false;
	}
	foreach ($queryPaths as $path => $item) {
		$hits = [];
		// Convert NBA path to object path
		$pathElements = explode('.', $path);
		// Chop off first part of path in case of names service
		if (strpos($service, '.') !== false) {
			unset($pathElements[0]);
		}
		foreach ($item['values'] as $value) {
			$hit = _getHitInResult($pathElements, $result, $value, $item['operator']);
			if (!empty($hit)) {
				$hits[] = $hit;
			}
		}
		// Store value only once; it will always be the same value found multiple times
		if (!empty($hits)) {
			$output[$path] = $hits[0][0];
		}
	}
	return isset($output) ? $output : false;
}

 
 
function _getHitInResult ($pathElements, $result, $value, $operator) {
	if (!$pathElements || !$result || !$value || !$operator) {
		return false;
	}
	$hits = [];
	// Append pathElements to object path; as object will contain arrays with
	// child objects, we need to approach this recursively, tracking progress
	foreach ($pathElements as $deeper) {
		if (isset($result->{$deeper})) {
			$result = $result->{$deeper};
			// Current path is tracked in $pathTracker
			$pathTracker = !isset($pathTracker) ?
				array_splice($pathElements, 1) : array_splice($pathTracker, 1);
			// Must go recursive if object contains array of child objects...
			if (is_array($result)) {
				foreach ($result as $row) {
					$newHits = _getHitInResult($pathTracker, $row, $value, $operator);
					if (!empty($newHits)) {
						$hits = $hits + $newHits;
					}
				}
			}
			// Tracker is empty, we must have reached the correct path
			if (empty($pathTracker)) {
				// Convert array to string if necessary
				if (is_array($result)) {
					$result = array_values($result)[0];
				}
				// Operator determines if we have a hit: 
				// LIKE...
				if (($operator == 'LIKE' && stripos($result, $value) !== false) ||
				// ... MATCHES or EQUALS_IC	
					(($operator == 'MATCHES' || $operator == 'EQUALS_IC') && 
						preg_match("/\b$value\b/i", $result)) ||
				// ... EQUALS
					($operator == 'EQUALS' && $value == $result)) {
					$hits[] = $result;
				}
			}
		}
	}
	return $hits;
}

/* Highlight and reduces path to last word to facilitate translation */
function _highlightHits ($service, $hits = []) {
	$paths = _getQueryPaths($service);
	if (!empty($hits)) {
		foreach ($hits as $path => $hit) {
			$tmp = explode('.', $path);
			$output[array_pop($tmp)] = 
				_highlightMatch($hit, $paths[$path]['values']);
		}
	}
	return isset($output) ? $output : false;
}


/**
 * Highlight match
 *
 * Experimental highlight function from Linnaeus NG by Maarten Schermer
 *
 * @param string $haystack Input string
 * @param array $needles Matches
 * @return string
 */
function _highlightMatch ($haystack, $needles) {
	// Intermediate set required to prevent highlighting of html
	$f = [
		'<span class="scientific">',
		'</span>',
		'&nbsp;',
		'<span class="result-query">',
	];
	$r = [
		chr(4),
		chr(7),
		chr(13),
		chr(14),
	];
	$haystack = str_replace($f, $r, $haystack);
	
	foreach ($needles as $needle) {
		$needle = trim($needle);
		if (!is_string($needle) || stripos(strip_tags($haystack), $needle) === false || 
			is_null($needle)) {
			continue;
		}
		$q = str_split($needle);
		$x = ')(\<[^<]*\>)*(';
		$q = str_replace('( )', '(\s*)', '(' . implode($x, $q) . ')');
		$haystack = preg_replace_callback('/' . $q . '/i', function ($m) {
			return chr(14) . preg_replace_callback('(<(.*?)>)', function ($m) {
				return chr(7) . $m[0] . chr(14);
			}, $m[0]) . chr(7);
		}, $haystack);
	}
	
	
	// Restore temporarily replaced tags
	return str_replace($r, $f, $haystack);
}


function _setShowAllQuery ($total, $criteria) {
	if ($total > maxResultsInitial()) {
		$criteria['size'] = maxResults();
		return http_build_query($criteria);
	}
	return null;
}



/**
 * Total size
 *
 * Number of results in json response
 *
 * @param array $data Parsed json
 * @return number|boolean
 */
function _getTotalRows ($data) {
	if (isset($data->totalSize)) {
		return (int)$data->totalSize;
	}
	return false;
}

/**
 * Replaces registration numbers with multiple spaces with non-breaking spaces
 *
 * Some Brahms registration numbers contain double spaces, e.g. L  012345;
 * If these are used without modification, they are presented on the site with
 * a single space, and these numbers cannot be properly copy/pasted to search fields.
 *
 * @param string $string
 * @param string $field Extra parameter so function can be used in loop over json data
 * @return string $string
 */
function _setUnitId ($string, $field = false) {
	if (!$field || $field == 'unitID') {
		return str_replace(' ', '&nbsp;', $string);
	}
	return $string;
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
function _getSpecimenNames ($identifications = []) {
    foreach ($identifications as $identification) {
    	$name = _getScientificName($identification);
    	if (!empty($name)) {
			$output[] = [
				'name' => $name,
				'url' => _getTaxonUrl($identification),
			    'preferred' => $identification->preferred ? 1 : 0
			];
    	}
	}
	if (isset($output)) {
    	usort($output, function($a, $b) {
            return $b['preferred'] - $a['preferred'];
        });
	    return $output;
	}
	return [];
}


function _getSpecimenTypeStatuses ($identifications = []) {
    foreach ($identifications as $identification) {
    	if (isset($identification->typeStatus)) {
			$output[] = [
				'name' => _getScientificName($identification),
				'typeStatus' => $identification->typeStatus,
			    'preferred' => $identification->preferred ? 1 : 0
			];
    	}
	}
	if (isset($output)) {
    	usort($output, function($a, $b) {
            return $b['preferred'] - $a['preferred'];
        });
	    return $output;
	}
	return [];
}


































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
 * Parses classification of taxon
 *
 * @param object $classification Classification section of NBA response
 * @return array|void
 */
function _parseClassification ($classification) {
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
function _getSpecimenVernaculars ($identifications = []) {
    if (empty($identifications)) {
        return [];
    }
    foreach ($identifications as $id) {
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
function _getGatheringEventSpecimens ($event = []) {
	foreach ($event as $k => $v) {
		if (!is_array($v) && !is_object($k) && $v != '') {
			if ($k == 'dateTimeBegin' || $k == 'dateTimeEnd') {
				$v = _dateTimeToDate($v);
			}
			$d[$k] = $v;
		}
	}
	if (isset($event->gatheringPersons)) {
		foreach ($event->gatheringPersons as $a) {
			$agent[] = $a->fullName . (isset($a->organization->name) ? 
				' (' . $a->organization->name . ')' : '');
		}
		$d['gatheringAgents'] = $agent;
	}
	if (isset($event->siteCoordinates)) {
		foreach ($event->siteCoordinates as $c) {
			if (isset($c->longitudeDecimal) && isset($c->latitudeDecimal)) {
				$coordinates['lat'] = $c->latitudeDecimal;
				$coordinates['lon'] = $c->longitudeDecimal;
			}
		}
		$d['siteCoordinates'] = isset($coordinates) ? $coordinates : null;
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
	$output['total'] = getTotalRows($data);	$output['_showMap'] = true;

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
 * Total size
 *
 * Number of results in json response
 *
 * @param array $data Parsed json
 * @return number|boolean
 */
function getTotalRows ($data, $groupResult = false) {
	if (isset($data->totalSize)) {
		return (int)$data->totalSize;
	}
	return false;
}

/**
 * Special case function for number of results in json response within a grouped result
 *
 * @param array $data Parsed json
 * @return number|boolean
 */
function getTotalRowsWithinGroup ($data) {
	if (isset($data->resultGroups[0]->totalSize)) {
		return (int)$data->resultGroups[0]->totalSize;
	}
	return false;
}

/**
 * Gets query parameters
 *
 * @param array $data Parsed json
 * @return array|void Parameters
*/
function getSearchTerms ($data) {
	if (isset($data->queryParameters)) {
		return (array)$data->queryParameters;
	}
	return false;
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
	$output['searchTerms'] = getQueryTerms('taxon');

	if (!$output['searchTerms']) {
		handleError('parseTaxon: invalid json response');
	}
	if ($output['total'] == 0 || empty($data->resultSet)) {
	    $output['results'] = array();
        return $output;
	}
	foreach ($data->resultSet as $row) {
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

/**
 *
 * Gets offset for synonym/common name in taxon response
 *
 * Returns offset of result; used only for synonyms and common names to
 * determine the array key containing the hit
 *
 * NOTE: currently not in use because final NBA response does not match
 * mock object for which this function was developed...
 *
 * @param array $row Parsed json
 * @return unknown
 */
function getResultOffset ($row) {
	preg_match('/\[(.*?)\]/', $row->searchResults[0]->matchInfo[0]->path, $m);
	return $m[1];
}

/**
 * Gets result type (accepted/synonym/common) for taxon
 *
 * Returns type of result:
 * acceptedName.fullScientificName
 * acceptedName.synonyms[0].scientificName.fullScientificName
 * acceptedName.commonNames[0].name
 *
 * @param array $row Parsed json
 * @return string accepted/synonym/common

function getResultType ($row) {
	$path = $row->searchResults[0]->matchInfo[0]->path;
	return strpos($path, 'synonym') !== false ? 'synonym' :
		(strpos($path, 'vernacularNames') !== false ? 'common' : 'accepted');
}
 */

function getResultType ($row) {
	$path = $row->searchResults[0]->matchInfo[0]->path;
	return strpos($path, 'synonym') !== false ? 'synonym' :
		(strpos($path, 'vernacularNames') !== false ? 'common' : 'accepted');
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


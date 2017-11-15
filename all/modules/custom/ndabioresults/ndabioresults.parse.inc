<?php

/**
 * Parses taxon media detail NBA response to PHP array
 *
 * @param object $data
 * @return boolean|array
 */
function _parseTaxonDetail ($data) {
	
//p($data);
	
	$service = 'names.taxa';
	$skipFields = [];
	$timer = _setTimer();
	
	foreach ((array) $data as $field => $value) {
		if (!is_array($value) && !is_object($value) && !in_array($field, $skipFields)) {
			$output[$field] = $value;
		}
	}
	
	foreach ($data->taxa as $row) {
		$acceptedNames[] = _formatScientificName($row->acceptedName);
		$row = $row->taxonDetails;
		$source = $row->sourceSystem->name;
		$output['sourceUrls'][$source] = $row->recordURI;
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
				if (isset($description->category) && 
					(strtolower($description->category) == 'algemeen' ||
					strtolower($description->category) == 'samenvatting')) {
					$output['descriptions']['Dutch'][$source] = $description->description;
				}
				// NSR English
				if (isset($description->category) && strtolower($description->category) == 'summary') {
					$output['descriptions']['English'][$source] = $description->description;
				}
				// CoL English
				if ((!isset($description->category) || empty($description->category)) && 
					!empty($description->description)) {
					$output['descriptions']['English'][$source] = $description->description;
				}
			}
		}
		if (isset($row->vernacularNames)) {
			foreach ($row->vernacularNames as $i => $name) {
				$key = isset($name->language) ? $name->language : null;
				$output['commonNames'][$source][$key][] = $name->name;
			}
		}
	}
	$output['acceptedName'] = $acceptedNames[0];
	$output['multimedia'] = $data->multimedia;
	$output['specimens'] = $data->specimens;
	
	_addDebugMessage('Parsing taxon', _getTimer($timer));
	
	return isset($output) ? $output : false;;
}

/**
 * Parses taxa NBA response to PHP array
 * 
 * Offers options to include 'Show all' and 'Media' links, paginator.
 *
 * @param object $data
 * @param array $options
 * @return boolean|array
 */
function _parseTaxa ($data, $options) {
	
	$service = 'names.taxa';
	$timer = _setTimer();
	
	if (empty($data->resultSet) || $data->totalSize == 0) {
		$output['results'] = [];
        return $output;
	}
		
	$output['total'] = $data->totalSize;

	$output['result_warning'] = _exceedsMaxResults($service, $data->totalSize) ?
		 _maxResultWarning($service) : '';
	
//p($data);

	foreach ($data->resultSet as $i => $row) {
		// Accepted scientific name, synonym, or common name
		$d = $sources = $names = $tmp = [];
		foreach ($row->item->taxa as $taxon) {
			$hits = _getHits($service, $taxon);
			$type = _getResultType($hits);
			$sources[] = _getSourceNameBySourceCode($taxon->sourceSystem->code);
			$names['common'] = _getTaxonVernaculars($service, $taxon, true);
			$names['accepted'][] = _getTaxonAcceptedName($service, $taxon, $hits);
			$names['synonyms'][] = _getTaxonSynonyms($service, $taxon, $hits, true);
		}
		// Reformat synonyms
		if (!empty(array_filter($names['synonyms']))) {
			foreach ($names['synonyms'] as $i => $v) {
				if (!empty($v)) {
					foreach ($v as $j => $synonym) {
						$tmp[$synonym] = $i . $j;
					}
				}
			}
			$tmp = array_values(array_flip($tmp));
			$names['synonyms'] = !empty($tmp) ? $tmp : null;
		}
		
		// Well, finally...
		$d['type'] = _getResultType($hits);
		$d['rank'] = $row->item->taxa[0]->taxonRank;
		$d['name'] = implode('<br>', array_unique($names['accepted']));
		if ($d['type'] == 'accepted') {
			$d['description'] = t(ucfirst($d['rank']));
		} else if ($d['type'] == 'synonym') {
			$d['description'] = (count($names['synonyms']) == 1 ? t('Synonym') : t('Synonyms')) . 
				': ' . implode('; ', $names['synonyms']);
		} else if ($d['type'] == 'common') {
			$vernaculars = [];
			foreach ($names['common'] as $vernacular) {
				$vernaculars[] = $vernacular['name'] . 
					(!empty($vernacular['language']) ? ' (' . t($vernacular['language']) . ')' : '');
			}
			$d['description'] = (count($vernaculars) == 1 ? t('Common name') : t('Common names')) . 
				': ' . implode('; ', $vernaculars);
		}

		$d['url'] = _setBasePath() . 'taxon/' . 
			urlencode(ucfirst(str_replace(' ', '_', $row->item->name))) . '/' . 
			safe_http_build_query(_setDetailSearchTerms($service, $i));
		$d['sources'] = $sources;
		$d['commonNames'] = ($d['type'] != 'common' ? _getCommonNames($row, true) : []);
		$output['results'][] = $d;
	}

	// Show all link
	if (in_array('showAll', $options) && $output['total'] > _maxResultsInitial()) {
		$output['showAll'] = _setBasePath() . 'result/taxon/' .
			_setShowAllQuery($output['total'], _getQueryTerms($service));
	}
	// Paginator
	if (in_array('paginator', $options)) {
		$output['paginator'] = 
			_getPaginator('specimen', $output['total'], _getPaginatorOffset($service));
	}
	// Media link
	if (in_array('mediaLink', $options)) {
		$output['mediaLink'] = $data->mediaLink;
	}
	
	_addDebugMessage('Parsing taxa', _getTimer($timer));
	
	return isset($output) ? $output : false;
}

/**
 * Creates 'too many results' warning on result page
 * 
 * @param string $service
 * @param int $total
 * @return string
 */
function _maxResultWarning ($service) {
	return  
		t('The total number of results exceeds the maximum number of results that can be displayed.') . 
		' ' . sprintf(t('You can only browse the first %s records.'), 
		_formatNumber(_getMaxResultsPerPage($service)));
}

/**
 * Determine max results per page for given serviec
 * 
 * @param string $service
 * @return int
 */
function _getMaxResultsPerPage ($service) {
	return strpos($service, '.') !== false ?
		_nbaMaxNumPerScientificNameGroup()[_normaliseServiceName($service)] :
		_nbaMaxResultWindow()[$service];
}

/**
 * Get common names for taxon in result row of taxa query
 * 
 * @param object $row Taxon object
 * @param string $languageCheck Option to only return language-specific names
 * @return boolean|array
 */
function _getCommonNames ($row, $languageCheck = false) {
	global $language;
	foreach ($row->item->taxa as $i => $taxon) {
		if (isset($taxon->vernacularNames)) {
			foreach ($taxon->vernacularNames as $name) {
				// If language is set, only store when language of
				// common name matches that of interface...
				if ($languageCheck && isset($name->language)) {
					if ($name->language == $language->name) {
						$output[$name->name] = $name->language;
					}
				// ... else always return all names
				} else if (isset($name->language)) {
					$output[$name->name] = $name->language;
				}
			}
		}
	}
	return isset($output) ? array_unique($output) : false;
}

/**
 * Get type of hit in result row of taxa query
 * 
 * @param unknown $hits
 * @return string|boolean
 */
function _getResultType ($hits = []) {
	if (empty($hits)) {
		return false;
	}
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

/**
 * Parses multimedia NBA response to PHP array
 * 
 * Offers options to include 'Show all' and 'Media' links, paginator.
 *
 * @param object $data
 * @param array $options
 * @return boolean|array
 */
function _parseMultimedia ($data, $options = []) {
	if (!isset($data->resultSet) || empty($data->resultSet)) {
		return false;
	}
	
	$timer = _setTimer();
	
	$service = 'multimedia';
	$output['total'] = _getTotalRows($data);

	$output['result_warning'] = _exceedsMaxResults($service, $data->totalSize) ?
		 _maxResultWarning($service) : '';
	
//p($data);
	
	foreach ($data->resultSet as $i => $row) {
		$type = isset($row->item->associatedTaxonReference) && 
			!empty($row->item->associatedTaxonReference) ?  'taxon' : 'specimen';
		$d['title'] = $type == 'taxon' && isset($row->item->title) ? 
			$row->item->title : null;
		$d['caption'] = $type == 'taxon' && isset($row->item->caption) ?
			$row->item->caption : null;
		$d['url'] = _setBasePath() . $service . '/' . urlencode($row->item->unitID) . '/' . 
			safe_http_build_query(_setDetailSearchTerms($service, $i));
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
		$d['nameResolutionHits'] = _setNameResolutionHits($service, $hits, $row);
		$d['taxon'] = _getSpecimenScientificNames($service, $row, $hits);
		$d['unitID'] = _getMultimediaSpecimenUnitId($row, $hits);
		$output['results'][] = $d;
	}
	// Show all link
	if (in_array('showAll', $options) && $output['total'] > _maxResultsInitial()) {
		$output['showAll'] = _setBasePath() . 'result/' . $service . '/' .
			_setShowAllQuery($output['total'], _getQueryTerms($service));
	}
	// Paginator
	if (in_array('paginator', $options)) {
		$output['paginator'] = 
			_getPaginator($service, _getTotalRows($data), _getPaginatorOffset($service));
	}
	
//p($output);	
	_addDebugMessage('Parsing multimedia', _getTimer($timer));
	
	return isset($output) ? $output : false;
}


/**
 * Parses specimen multimedia NBA response to PHP array
 * 
 * @param object $data
 * @return boolean|array
 */
function _parseSpecimenMediaDetail ($data) {
	if (!isset($data->id)) {
		return false;
	}
	
	$timer = _setTimer();
//p($data);	
	foreach ((array) $data as $field => $value) {
		if (!is_array($value) && !is_object($value)) {
			$output[$field] = $value;
		}
	}
	$output['source'] = $data->sourceSystem->name;
	$output['names'] = _getSpecimenNames($data->associatedSpecimen->identifications);
	$output['unitID'] = $data->associatedSpecimen->unitID;
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

	_addDebugMessage('Parsing multimedia', _getTimer($timer));
	   		
	return isset($output) ? $output : false;
}

/**
 * Parses specimen detail NBA response to PHP array
 * 
 * @param object $data
 * @return boolean|array
 */
function _parseSpecimenDetail ($data) {
	
	if (!isset($data->id)) {
		return false;
	}
//p($data);

	$timer = _setTimer();
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
	    //'collectionType',
    	//'referrer'
		// etc
	);

	foreach ((array) $data as $field => $value) {
		if (!is_array($value) && !is_object($value) && !in_array($field, $skipFields)) {
			$output[$field] = $value;
		}
	}
	
	$output['assemblageID'] = isset($data->assemblageID) ?
		_formatAssemblageId($data->assemblageID) : null;
	//$output['collectionType'] = $data->collectionType;
	$output['source'] = isset($data->sourceSystem) ? $data->sourceSystem->name : null;
	$output['names'] = _getSpecimenNames($data->identifications);
	$output['typeStatuses'] = _getSpecimenTypeStatuses($data->identifications);
	$output['vernaculars'] = _getSpecimenVernaculars($data->identifications);
	$output['enrichedVernaculars'] = _getSpecimenEnrichedVernaculars($data->identifications);
	$event = _getGatheringEventSpecimens($data->gatheringEvent);
	if (!is_null($event)) {
		$output['gatheringEvent'] = _getGatheringEventSpecimens($data->gatheringEvent);
	}
	//$output['license'] = $data->searchResults[0]->result->license;
	$output['otherSpecimens'] = isset($data->assemblageID) ? _getOtherSpecimens($data) : null;
	$output['multimedia'] = $data->multimedia;
	
//p($output);
	
	_addDebugMessage('Parsing specimen', _getTimer($timer));
	
	return isset($output) ? $output : false;
}

/**
 * Gets vernacular names for specimen from associated taxon
 * 
 * @param array $identifications
 * @return array|NULL
 */
function _getSpecimenEnrichedVernaculars ($identifications = []) {
	foreach ($identifications as $row) {
		if (isset($row->taxonomicEnrichments)) {
			foreach ($row->taxonomicEnrichments as $enrichment) {
				if (isset($enrichment->vernacularNames)) {
					foreach ($enrichment->vernacularNames as $name) {
						$output[$name->name] = isset($name->language) ? 
							$name->language : null;
					}
				}
			}
		}
	}
	return isset($output) ? $output : [];
}

/**
 * Get url for Nth specimen in "collection"/set
 *
 * @param int $i Offset for specimen in searchResults->links
 * @return string|null Url
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
 * Parses taxon multimedia detail NBA response to PHP array
 * 
 * @param object $data
 * @return boolean|array
 */
function _parseTaxonMediaDetail ($data) {
	if (!isset($data->id)) {
		return false;
	}
	
	$timer = _setTimer();
//p($data);	
	foreach ((array) $data as $field => $value) {
		if (!is_array($value) && !is_object($value)) {
			$output[$field] = $value;
		}
	}
	$output['source'] = $data->sourceSystem->name;
	$output['acceptedName'] = _getScientificName($data->associatedTaxon);
	$output['acceptedNameUrl'] = _getTaxonUrl($data->associatedTaxon, false);
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
	
	_addDebugMessage('Parsing multimedia', _getTimer($timer));
	
	return $output;
}

/**
 * Gets scientific name from NBA object
 * 
 * Can be used for specimen and taxon objects
 * 
 * @param object $object
 * @param string $fullScientificName Include authorship and italicize?
 * @return string|NULL
 */
function _getScientificName ($object, $fullScientificName = true) {
	// Can be used to generate a full italicized name (default) or 
	// a simple non-formatted name without authorship
	$elements = $fullScientificName ? 
		_scientificNameElements() : _scientificNameElementsInItalics();
	// Name can be stored in either acceptedName (taxon) or 
	// scientificName (specimen); try both
	foreach (['acceptedName', 'scientificName'] as $path) {
		foreach ($elements as $i => $element) {
			$name[$i] = isset($object->{$path}->{$element}) && 
				!empty(trim($object->{$path}->{$element})) ?
				trim($object->{$path}->{$element}) : null;
			// Subgenus between brackets
			if ($element == 'subgenus' && !empty($name[$i]) && $name[$i][0] != '(' && 
				substr($name[$i], -1) != ')') {
				$name[$i] = '(' . $name[$i] . ')';
			}
			// Italics only for full option
			if (!empty($name[$i]) && $fullScientificName &&
				in_array($element, _scientificNameElementsInItalics())) {
				$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
			}
		}
		// Some specimens don't have a properly formatted name;
		// revert to fullScientificName
		if (isset($object->{$path}) && empty($name[0])) {
			$name[0] = $object->{$path}->fullScientificName;
			unset($name[1], $name[2], $name[3]);
		}
		if (!empty(array_filter($name))) {
			return implode(' ', array_filter($name));
		}
	}
	return null;
}

/**
 * Check if taxon is present in index
 * 
 * If so, return url; if not, return null.
 * Results are cached in session.
 * 
 * @param unknown $object
 * @param string $checkNba
 * @return unknown|NULL|string|NULL
 */
function _getTaxonUrl ($object, $checkNba = true) {
	// Name can be stored in either acceptedName (taxon) or 
	// scientificName (specimen); try both
	foreach (['acceptedName', 'scientificName'] as $path) {
		foreach (_groupByScientificNameElements() as $i => $element) {
			$name[$i] = isset($object->{$path}->{$element}) &&
				!empty(trim($object->{$path}->{$element})) ?
				trim($object->{$path}->{$element}) : null;
		}
		$name = array_filter($name);
		if (!empty($name)) {
			$key = strtolower(implode(' ', $name));
			if (isset($_SESSION['nbaTaxa'][$key])) {
				return $_SESSION['nbaTaxa'][$key];
			}
			$url = null;
			if ($checkNba && _getTaxonFromNba($name, true) || !$checkNba) {
				$url = _setBasePath() . 'taxon/' . implode('_', $name);
			}
			$_SESSION['nbaTaxa'][$key] = $url;
			// Make sure session isn't overloaded by crawlers etc.
			// Cap urls to a maximum. If max is reached, delete oldest entry
			if (count($_SESSION['nbaTaxa']) > _maxSizeTaxonUrlCache()) {
				array_pop($_SESSION['nbaTaxa']);
			}
			return $url;
		}
	}
	return null;
}

/**
 * Sets search terms for detail page in result set
 * 
 * @param unknown $service
 * @param unknown $i Nth result in set, determines offset
 * @return array
 */
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

/**
 * Filter hits pertaining to the name and highlight these
 * 
 * @param string $service
 * @param array $hits
 * @return boolean|array
 */
function _setNonNameHits ($service, $hits = []) {
	if (!empty($hits)) {
		foreach ($hits as $path => $hit) {
			if (in_array($path, _nameHits()[_normaliseServiceName($service)]) ||
				// Name resolution hits 
				strpos($path, 'taxonomicEnrichments') !== false) {
				unset($hits[$path]);
			}
		}
		return _highlightHits($service, $hits);
	}
	return false;
}

/**
 * Filter hits pertaining to name resolution and highlight these
 * 
 * @param string $service
 * @param array $hits
 * @param object $object
 * @return boolean|array
 */
function _setNameResolutionHits ($service, $hits = [], $object) {
	if (!empty($hits)) {
		$paths = _getQueryPaths($service);
		$types = [];
		foreach ($hits as $path => $hit) {
			if (strpos($path, 'taxonomicEnrichments') !== false) {
				// Get taxon id
				$tmp = explode('.', $path);
				$type = $tmp[2];
				$field = $tmp[3];
				$types[] = $type;
				
				if (!isset($object->identifications)) {
					$object->identifications = $object->item->identifications;
				}

				foreach ($object->identifications as $i => $identification) {
					if (isset($identification->taxonomicEnrichments)) {
						foreach ($identification->taxonomicEnrichments as $enrichment) {
							foreach ($enrichment->{$type} as $enrichmentType) {
								if (isset($enrichmentType->{$field}) &&
									$enrichmentType->{$field} == $hit) {
									if ($type == 'vernacularNames') {
										$hit = _highlightMatch($hit, $paths[$path]['values']);
									} else {
										// Elements in regular scientific name elements
										foreach (_scientificNameElements() as $i => $element) {
											$name[$i] = isset($enrichmentType->{$element}) && 
												!empty(trim($enrichmentType->{$element})) ? 
												trim($enrichmentType->{$element}) : '';
											// Highlight (assume always CONTAINS operator for name fields)
											if (!empty($name[$i]) && $element == $field) {
												$name[$i] = _highlightMatch($name[$i], $paths[$path]['values']);
											}
											// Subgenus between brackets
											if ($element == 'subgenus' && !empty($name[$i]) && $name[$i][0] != '(' && 
												substr($name[$i], -1) != ')') {
												$name[$i] = '(' . $name[$i] . ')';
											}
											// Italics
											if (!empty($name[$i]) && in_array($element, _scientificNameElementsInItalics())) {
												$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
											}
										}
										if (!empty($name)) {
											// Could also be a hit in fullScientificName; try highlighting
											if ($field == 'fullScientificName') {
												foreach ($name as $i => $element) {
													// Only add if not highlighted yet
													if (strpos($element, 'class="result-query"') === false) {
														$name[$i] = _highlightMatch($name[$i], $paths[$path]['values']);
													}
												}
											}
											// Only fullScientificName is available; genus, etc are empty
											if (empty($name[0])) {
												$name[0] = $enrichmentType->fullScientificName;
												unset($name[1], $name[2], $name[3]);
												// Try highlighting
												if ($field == 'fullScientificName') {
													$name[0] = _highlightMatch($name[0], $paths[$path]['values']);
												}
											}
											$hit = implode(' ', array_filter($name));
										}
									}
									$d[] = [
										'taxon' => _getTaxonScientificNameById($enrichment->taxonId),
										$type == 'synonyms' ? 'synonym' : 'vernacular' => $hit
									]; 
								}
							}
						}
					}
				}
			}
		}
		if (isset($d)) {
			// We end up with an array that still should be checked for duplicates: BIOPORVTWO-333
			foreach ($d as $i => $hit) {
				$type = array_keys($hit)[1];
				$string = strip_tags($hit[$type]);
				$nrHits = substr_count($hit[$type], 'class="result-query"');
				if (isset($data[$type][$string])) {
					// Check number of hits in string; highest number wins
					// Already exists, has more hits -- delete older entry
					if ($nrHits > $data[$type][$string]['count']) {
						unset($d[$data[$type][$string]['nr']]);
					// Already exists, has fewer hits -- delete this entry
					} else {
						unset($d[$i]);
					}
				}
				$data[$type][$string] = ['nr' => $i, 'count' => $nrHits];
			}
			// Garbage collector
			unset($data);
			return array_map("unserialize", array_unique(array_map("serialize", $d)));
		}
		return false;
	}
}

/**
 * Get vernaculars names for taxon
 * 
 * @param string $service
 * @param object $taxon
 * @param boolean $hitsOnly
 * @return boolean|array
 */
function _getTaxonVernaculars ($service, $taxon, $hitsOnly = false) {
	if (isset($taxon->vernacularNames)) {
		$paths = _getQueryPaths($service);
		foreach ($taxon->vernacularNames as $i => $name) {
			$hit = false;
			$vernacular['name'] = _highlightMatch($name->name, 
				$paths['vernacularNames.name']['values']);
			$vernacular['language'] = isset($name->language) ? $name->language : null;
			if ($vernacular['name'] != $name->name) {
				$hit = true;
			}
			if (!$hitsOnly || $hitsOnly && $hit) {
				$vernaculars[$i] = $vernacular;
			}
		}
		return isset($vernaculars) ? $vernaculars : false;
	}
	return false;
}

/**
 * Get accepted name for taxon
 * 
 * @param string $service
 * @param object $taxon
 * @param array $hits
 * @return boolean|string
 */
function _getTaxonAcceptedName ($service, $taxon, $hits = []) {
	$paths = _getQueryPaths($service);
	$name = [];
	// Elements in regular scientific name elements
	foreach (_scientificNameElements() as $i => $element) {
		$name[$i] = isset($taxon->acceptedName->{$element}) && 
			!empty(trim($taxon->acceptedName->{$element})) ? 
			trim($taxon->acceptedName->{$element}) : '';
		// Highlight (assume always CONTAINS operator for name fields)
		if (isset($hits['acceptedName.' . $element])) {
			$name[$i] = _highlightMatch($taxon->acceptedName->{$element}, 
				$paths['acceptedName.' . $element]['values']);
		}
		// Subgenus between brackets
		if ($element == 'subgenus' && !empty($name[$i]) && $name[$i][0] != '(' && 
			substr($name[$i], -1) != ')') {
			$name[$i] = '(' . $name[$i] . ')';
		}
		// Italics
		if (!empty($name[$i]) && in_array($element, _scientificNameElementsInItalics())) {
			$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
		}
	}
	if (!empty($name)) {
		// Could also be a hit in fullScientificName; try highlighting
		if (isset($paths['acceptedName.fullScientificName'])) {
			foreach ($name as $i => $element) {
				// Only add if not highlighted yet
				if (strpos($element, 'class="result-query"') === false) {
					$name[$i] = _highlightMatch($name[$i], 
						$paths['acceptedName.fullScientificName']['values']);
				}
			}
		}
	}
	
	return !empty($name) ? implode(' ', array_filter($name)) : false;
}

/**
 * Get synonyms for taxon
 * 
 * @param string $service
 * @param object $taxon
 * @param array $hits
 * @param boolean $hitsOnly
 * @return boolean|array
 */
function _getTaxonSynonyms ($service, $taxon, $hits = [], $hitsOnly = false) {
	if (isset($taxon->synonyms)) {
		$paths = _getQueryPaths($service);
		$names = [];
		// Elements in regular scientific name elements
		foreach ($taxon->synonyms as $synonym) {
			$name = [];
			$hit = false;
			foreach (_scientificNameElements() as $i => $element) {
				$name[$i] = isset($synonym->{$element}) && 
					!empty(trim($synonym->{$element})) ? 
					trim($synonym->{$element}) : '';
				// Highlight (assume always CONTAINS operator for name fields)
				if (isset($hits['synonyms.' . $element]) && isset($synonym->{$element})) {
					$name[$i] = _highlightMatch($synonym->{$element}, 
						$paths['synonyms.' . $element]['values']);
					if ($name[$i] != trim($synonym->{$element})) {
						$hit = true;
					}
				}
				// Subgenus between brackets
				if ($element == 'subgenus' && !empty($name[$i]) && $name[$i][0] != '(' && 
					substr($name[$i], -1) != ')') {
					$name[$i] = '(' . $name[$i] . ')';
				}
				// Italics
				if (!empty($name[$i]) && in_array($element, _scientificNameElementsInItalics())) {
					$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
				}
			}
			if (!empty(array_filter($name)) && (!$hitsOnly || $hitsOnly && $hit)) {
				$names[] = implode(' ', array_filter($name));
			}
		}
		return !empty($names) ? array_filter($names) : false;
	}
	return false;
}

/**
 * Format scientific name based on individual name parts
 * 
 * If no genus is set, fullScientificName is used instead. * 
 * 
 * @param object $object
 * @return boolean|string
 */
function _formatScientificName ($object) {
	$name = [];
	// Elements in regular scientific name elements
	foreach (_scientificNameElements() as $i => $element) {
		$name[$i] = isset($object->{$element}) && 
			!empty(trim($object->{$element})) ? 
			trim($object->{$element}) : '';
		// Subgenus between brackets
		if ($element == 'subgenus' && !empty($name[$i]) && $name[$i][0] != '(' && 
			substr($name[$i], -1) != ')') {
			$name[$i] = '(' . $name[$i] . ')';
		}
		// Italics
		if (!empty($name[$i]) && in_array($element, _scientificNameElementsInItalics())) {
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

/**
 * Get scientific name(s) for specimen row in result set
 * 
 * Optionally wrap these in links.
 * 
 * @param string $service
 * @param object $row
 * @param array $hits
 * @param boolean $createLinks
 * @return boolean|string
 */
function _getSpecimenScientificNames ($service, $row, $hits = [], $createLinks = false) {
	$paths = _getQueryPaths($service);
	
	// Sort data by scientific name group first
	$identifications = $row->item->identifications;
	usort ($identifications, function($a, $b) {
	    return strcmp($a->scientificName->genusOrMonomial, $b->scientificName->genusOrMonomial);
	});
	
	foreach ($identifications as $j => $identification) {
		$name = [];
		// Elements in regular scientific name elements
		foreach (_scientificNameElements() as $i => $element) {
			$name[$i] = isset($identification->scientificName->{$element}) && 
				!empty(trim($identification->scientificName->{$element})) ? 
				trim($identification->scientificName->{$element}) : '';
			// Highlight (assume always CONTAINS operator for name fields)
			if (!empty($name[$i]) && isset($hits['identifications.scientificName.' . $element])) {
				$name[$i] = _highlightMatch($identification->scientificName->{$element}, 
					$paths['identifications.scientificName.' . $element]['values']);
			}
			// Subgenus between brackets
			if ($element == 'subgenus' && !empty($name[$i]) && $name[$i][0] != '(' && 
				substr($name[$i], -1) != ')') {
				$name[$i] = '(' . $name[$i] . ')';
			}
			// Italics
			if (!empty($name[$i]) && in_array($element, _scientificNameElementsInItalics())) {
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

/**
 * Get unitId (registration number) of specimen in multimedia result
 * 
 * @param object $row Result row
 * @param array $hits
 * @return string|NULL
 */
function _getMultimediaSpecimenUnitId ($row, $hits = []) {
	if (isset($row->item->associatedSpecimenReference)) {
		$pos = strpos($row->item->associatedSpecimenReference, '@');
		$id = substr($row->item->associatedSpecimenReference, 0, $pos);
		// Highlight
		if (isset($hits['unitID'])) {
			$id = _highlightMatch($id, ['unitID']);
			//$id = str_replace($id, _setUnitId($id), $highlight);
		}
		return $id;
	}
	return null;
}

/**
 * Parses specimen data json searched by name and map to PHP array
 * 
 * Data will be plotted on a map.
 *
 * @param array $data
 * @return array $output
 */
function _parseSpecimensMap ($data) {
//p($data);
	$output['total'] = $data->resultSet[0]->item->specimenCount;
	$d['acceptedNames'] = _getSpecimenAcceptedNames($data->resultSet[0]);

	foreach ($data->resultSet[0]->item->specimens as $i => $specimen) {
		$d['nonAcceptedNames'] = [];
		$d['unitID'] = $specimen->unitID;
		$d['source'] = _getSourceNameBySourceCode($specimen->sourceSystem->code);
		$d['assemblageID'] = _formatAssemblageId($specimen->assemblageID);
		$s['recordBasis'] = isset($specimen->recordBasis) ? $specimen->recordBasis : null;
		$d['kindOfUnit'] = isset($specimen->kindOfUnit) ? $specimen->kindOfUnit : null;
		$d['taxonUrl'] = _getTaxonUrl($specimen);
		$d['url'] = _setBasePath() . 'specimen/' . urlencode($d['unitID']);
		$d['localityText'] = isset($specimen->gatheringEvent->localityText) ?
			$specimen->gatheringEvent->localityText : null;
		$d['date'] = isset($specimen->gatheringEvent->dateTimeBegin) ?
			_dateTimeToDate($specimen->gatheringEvent->dateTimeBegin) : null;
		$d['lat'] = $specimen->gatheringEvent->siteCoordinates[0]->geoShape->coordinates[1];
		$d['lon'] = $specimen->gatheringEvent->siteCoordinates[0]->geoShape->coordinates[0];
		
		if (empty($d['acceptedNames'])) {
			foreach ($specimen->identifications as $id) {
				if (_scientificNameGroupName($id->scientificName) == $data->resultSet[0]->item->name) {
					$d['nonAcceptedNames'][md5(serialize($id->scientificName))] = $id->scientificName;
				}
			}
		}
		
		$output['results'][] = $d;
	}

	$name = _setSpecimenScientificName($d);
	for ($i = 0; $i < count($output['results']); $i++) {
		unset($output['results'][$i]['nonAcceptedNames'], $output['results'][$i]['acceptedNames']);
		$output['results'][$i]['name'] = $name;
	}
	
	if ($output['total'] > _maxResults() && count($output['results']) <= _maxResults()) {
		$terms = _getQueryTerms('names.specimens');
		$terms['size'] = $output['total'];
		$url = _setBasePath() . 'result/specimen/map/' . 
			urlencode($data->resultSet[0]->item->name) . '/' . safe_http_build_query($terms);
		$output['message'] = sprintf(t('The first %s specimens are displayed'), _maxResults()) . 
			'. <a href="' . $url . '">' . sprintf(t('Display all %s specimens'), $output['total']) . ".</a>\n";
	} else if ($output['total'] > 1) {
		$output['message'] = sprintf(
			t('%s specimens are displayed'), 
			count($output['results'])
		) . '.';
	}
	
	return isset($output) ? $output : false;
}

/**
 * Parse scientific name elements from NBA to scientific name group
 * 
 * @param object $elements Object with name elements
 * @return string
 */
function _scientificNameGroupName ($elements) {
	$output[] = isset($elements->genusOrMonomial) && !empty($elements->genusOrMonomial) ?
		strtolower($elements->genusOrMonomial) : '?';
	$output[] = isset($elements->specificEpithet) && !empty($elements->specificEpithet) ?
		strtolower($elements->specificEpithet) : '?';
	$output[] = isset($elements->infraspecificEpithet) && !empty($elements->infraspecificEpithet) ?
		strtolower($elements->infraspecificEpithet) : null;
	return implode(' ', array_filter($output));
}

/**
 * Parses specimens NBA response to PHP array
 * 
 * Offers options to include 'Show all' and 'Media' links, paginator.
 *
 * @param object $data
 * @param array $options
 * @return boolean|array
 */
function _parseSpecimens ($data, $options = []) {
	if (!isset($data->resultSet) || empty($data->resultSet)) {
		return false;
	}
	$timer = _setTimer();
	
	$service = 'specimen';
	
	$output['total'] = $data->totalSize;
	
	$output['result_warning'] = _exceedsMaxResults($service, $data->totalSize) ?
		 _maxResultWarning($service) : '';
	
//p($data);
	
	foreach ($data->resultSet as $i => $row) {
		$d = [];
		//$d['url'] = _setSpecimensAllLink($row);
		$d['source'] = $row->item->sourceSystem->name;

		$d['unitID'] = $row->item->unitID;
		$d['recordBasis'] = isset($row->item->recordBasis) ?
			$row->item->recordBasis : null;
		$d['kindOfUnit'] = isset($row->item->kindOfUnit) ?
			$row->item->kindOfUnit : null;
		$d['preparationType'] = isset($row->item->preparationType) ?
			$row->item->preparationType : null;
		$d['collectionType'] = $row->item->collectionType;
		$d['url'] = _setBasePath() . 'specimen/' . urlencode($row->item->unitID) . '/' . 
			safe_http_build_query(_setDetailSearchTerms($service, $i));
		
		$hits = _getHits($service, $row->item);
		$d['hits'] = _setNonNameHits($service, $hits);
		$d['nameResolutionHits'] = _setNameResolutionHits($service, $hits, $row->item);
		$d['names'] = _getSpecimenScientificNames($service, $row, $hits, true);			
		$output['results'][] = $d;
	}
/*	
	$terms = _getStoredQueryTerms($service);
	$terms['from'] = 0;
*/	
	// Show all link
	if (in_array('showAll', $options) && $output['total'] > _maxResultsInitial()) {
		$output['showAll'] = _setBasePath() . 'result/specimen/' .
			_setShowAllQuery($output['total'], _getQueryTerms($service));
	}
	// Paginator
	if (in_array('paginator', $options)) {
		$output['paginator'] = 
			_getPaginator($service, $output['total'], _getPaginatorOffset($service));
	}
	// Media link
	if (in_array('mediaLink', $options)) {
		$output['mediaLink'] = $data->mediaLink;
	}
	
	
	_addDebugMessage('Parsing specimens', _getTimer($timer));
	
	return $output;
}

/**
 * Get search criteria for previous search
 * 
 * @param string $url
 * @return boolean|array
 */
function _getReferredSearch ($url) {
	safe_parse_str($url, $terms);
	return isset($terms['referrer']) ? _decodeReferrer($terms['referrer']) : false;
}

/**
 * Append score to current path
 * 
 * Except when it is set as 'score'; see _sortOptions().
 * 
 * @param unknown $path
 * @return string
 */
function _setSortUrl ($path) {
	return _resetUrl() . ($path == 'sort=score' ? '' : '&' . $path);
}

/**
 * Get sort criteria from current url
 * 
 * Constructs path and returns this in array
 * 
 * @return boolean|array
 */
function _getCurrentSort () {
	$pathComponents = explode('/', _getCurrentUrl());
	safe_parse_str(array_pop($pathComponents), $terms);	
	if (isset($terms['sort'])) {
		$path = 'sort=' . $terms['sort'] . (isset($terms['sortDirection']) ?
			'&sortDirection=' . $terms['sortDirection'] : '');
	} else if (isset($terms['groupSort'])) {
		$path = 'groupSort=' . $terms['groupSort'];
	} else {
		$path = 'sort=score';
	}
	return isset($path) ? ['path' => $path] : false;
}

/**
 * Rebuild url without most search flags
 * 
 * @return string Url
 */
function _resetUrl () {
	$pathComponents = explode('/', _getCurrentUrl());
	$path = array_pop($pathComponents);
	safe_parse_str($path, $terms);
	foreach (['sort', 'sortDirection', 'service', 'groupSort', 'from'] as $flag) {
		if (isset($terms[$flag])) {
			unset($terms[$flag]);
		}
	}
	$terms['from'] = 0;
	return implode('/', $pathComponents) . '/' . safe_http_build_query($terms);
}

/**
 * Construct taxon id from name elements
 * 
 * Results in Genus_species_infraspecise string.
 * 
 * @param object $object
 * @return string
 */
function _setTaxonId ($object) {
	foreach (_scientificNameElementsInItalics() as $element) {
		$name[] = isset($object->{$element}) && !empty(isset($object->{$element})) ? 
			$object->{$element} : null;
	}
	return ucfirst(implode('_', array_filter($name)));
}

/**
 * Parses specimens grouped by taxon NBA response to PHP array
 * 
 * Offers options to include 'Show all' and 'Media' links, paginator.
 *
 * @param object $data
 * @param array $options
 * @return boolean|array
 */

function _parseSpecimensTaxon ($data, $options = []) {
	if (!isset($data->resultSet) || empty($data->resultSet)) {
		return false;
	}
	$service = 'names.specimens';
	
	$timer = _setTimer();
	
	// Default sort is not score, must be set explicitly!
	$sortExtension = array_key_exists('groupSort', _getQueryTerms($service)) ? 
		'&groupSort=' . _getQueryTerms($service)['groupSort'] : '';
	$output['total'] = $data->totalSize;
	
	$output['result_warning'] = _exceedsMaxResults($service, $data->totalSize) ?
		 _maxResultWarning($service) : '';
	
//_getSpecimenDetails($data);
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
		foreach ($row->item->specimens as $i => $specimen) {
			//$specimen = $sp->specimenDetails;
			$s['unitID'] = $specimen->unitID;
			$s['recordBasis'] = isset($specimen->recordBasis) ? 
				$specimen->recordBasis : null;
			$s['kindOfUnit'] = isset($specimen->kindOfUnit) ? 
				$specimen->kindOfUnit : null;
			$s['preparationType'] = isset($specimen->preparationType) ? 
				$specimen->preparationType : null;
			$s['collectionType'] = $specimen->collectionType;
			$s['url'] = _setBasePath() . 'specimen/' . urlencode($specimen->unitID) . '/' . 
				urlencode($row->item->name) . '/' .
				safe_http_build_query(_setDetailSearchTerms($service, $i)) . $sortExtension;
			$hits = _getHits($service, $specimen);
			$s['hits'] = _setNonNameHits($service, $hits);
			
			$s['nameResolutionHits'] = _setNameResolutionHits($service, $hits, $specimen);
			
//p($s['nameResolutionHits'] );			
			
			$d['nameHits'] = _appendNameHits($d['nameHits'], $hits);
			// Only bother with non-accepted names if no accepted names are available
			if (empty($d['acceptedNames'])) {
				$d['nonAcceptedNames'] = 
					_appendNonAcceptedNames($d['nonAcceptedNames'], $specimen, $row->item->name);
			}
			!isset($specimen->assemblageID) ? $d['specimens'][$i] = $s :
				$d['sets'][_formatAssemblageId($specimen->assemblageID)][$i] = $s;
		}
		$d['fullScientificName'] = _setSpecimenScientificName($d);
		
		$terms = _getQueryTerms($service);
		unset($terms['from'], $terms['size']);
		
		$d['allLink'] = $d['count'] > _maxResultsInitial() ?
			_setBasePath() . 'result/specimen/taxon/' . urlencode($row->item->name) . '/' .
			safe_http_build_query($terms) . $sortExtension : null;
		
		$d['mapUrl'] = null;
		if (_isGeoSearch()) {
			$d['mapUrl'] = _setBasePath() . 'result/specimen/map/' . 
				urlencode($row->item->name) . '/' . safe_http_build_query(_getQueryTerms($service));
		}
		
		// BIOPORVTWO-313: merge sets into specimen array
		if (isset($d['sets'])) {
			foreach ($d['sets'] as $assemblageId => $set) {
				$d['specimens'][key($set)]['set'][$assemblageId] = $d['sets'][$assemblageId];
			}
			ksort($d['specimens']);
		}
		
		// No use for nameHits and sets anymore; discard
		unset($d['nameHits'], $d['sets']);
		
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
	if (in_array('showAll', $options) && $output['total'] > _maxResultsInitial()) {
		$output['showAll'] = _setBasePath() . 'result/specimen/' .
			_setShowAllQuery($output['total'], _getQueryTerms($service)) . 
			$sortExtension;
	}
	// Paginator
	if (in_array('paginator', $options)) {
		$output['paginator'] = 
			_getPaginator($service, $output['paginatorTotal'], $output['from']);
	}
	
	_addDebugMessage('Parsing specimens by taxon', _getTimer($timer));
	
	return $output;
}

/**
 * Convert NBA assemblageID to true Bramhs set id
 * 
 * @param string $id
 * @return string|boolean
 */
function _formatAssemblageId ($id) {
	$parts = explode('@', $id);
	if (count($parts) == 2) {
		return $parts[1] . '-' . $parts[0];
	}
	return false;
}

/**
 * Set highlighted scientific name for a specimen
 * 
 * @param array $data
 * @return string
 */
function _setSpecimenScientificName ($data) {
//p($data);
	$paths = _getQueryPaths('names.specimens');
	$hits = isset($data['nameHits']) ? $data['nameHits'] : [];
	$source = !empty($data['acceptedNames']) ? 
		$data['acceptedNames'] : $data['nonAcceptedNames'];

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
			foreach (_scientificNameElements() as $i => $element) {
				$name[$i] = isset($identification->{$element}) && 
					!empty(trim($identification->{$element})) ? 
					trim($identification->{$element}) : '';
				// Hits can be in both defaultClassification and scientificName
				foreach (['defaultClassification', 'scientificName'] as $category) {
					$hitPath = 'identifications.' . $category . '.' . $element;
					// Highlight (assume always CONTAINS operator for name fields)
					if (!empty($name[$i]) && isset($hits[$hitPath])) {
						$name[$i] = _highlightMatch($identification->{$element}, 
							$paths[$hitPath]['values']);
					}
				}
				// Subgenus between brackets
				if ($element == 'subgenus' && !empty($name[$i]) && $name[$i][0] != '(' && 
					substr($name[$i], -1) != ')') {
					$name[$i] = '(' . $name[$i] . ')';
				}
				// Italics
				if (!empty($name[$i]) && in_array($element, 
					_scientificNameElementsInItalics())) {
					$name[$i] = '<span class="scientific">' . $name[$i] . '</span>';
				}
			}
		// BRAHMS: generate from fullScientificName
		} else {
			// First highlight
			$name[0] = _highlightMatch($identification->fullScientificName, 
				array_unique(array_values($hits)));
			foreach (_scientificNameElementsInItalics() as $element) {
				if (isset($identification->{$element}) && 
					!empty(trim($identification->{$element}))) {
					$name[0] = str_replace($identification->{$element}, 
						'<span class="scientific">' . $identification->{$element} . 
						'</span>', $name[0]);
				}
			}
		}
		
		if (!empty($name)) {
			// Could also be a hit in fullScientificName; try highlighting
			$scientificNamePath = 'identifications.scientificName.fullScientificName';
			if (isset($paths[$scientificNamePath])) {
				foreach ($name as $i => $element) {
					// Only add if not highlighted yet
					if (strpos($element, 'class="result-query"') === false) {
						$name[$i] = _highlightMatch($name[$i], 
							$paths[$scientificNamePath]['values']);
					}
				}
			}
			// Only fullScientificName is available; genus, etc are empty
			if (empty($name[0])) {
				$name[0] = $identification->fullScientificName;
				unset($name[1], $name[2], $name[3]);
				// Try highlighting
				if (isset($paths[$scientificNamePath])) {
					$name[0] = _highlightMatch($name[0], 
						$paths[$scientificNamePath]['values']);
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

/**
 * Append non-accepted names to a previously constructed (or still empty) 
 * array of non-accepted names
 * 
 * @param array $nonAcceptedNames
 * @param object $row Result row
 * @param object $scientificNameGroup
 * @return array
 */
function _appendNonAcceptedNames ($nonAcceptedNames, $row, $scientificNameGroup) {
	foreach ($row->identifications as $identification) {
		if ($scientificNameGroup == $identification->scientificName->scientificNameGroup) {
			$nonAcceptedNames[md5(serialize($identification->scientificName))] = 
				$identification->scientificName;
		}
	}
	return $nonAcceptedNames;
}

/**
 * Extract name hits from hits and append to a previously constructed (or still empty) 
 * array of name hits
 * 
 * @param array $nameHits
 * @param array $hits
 * @return array
 */
function _appendNameHits ($nameHits, $hits = []) {
	if (!empty($hits)) {
		foreach ($hits as $path => $value) {
			if (in_array($path, _nameHits()['specimen'])) {
				$nameHits[$path] = $value;
			}
		}
	}
	return $nameHits;
}

/**
 * Get accepted names from specimen result
 * 
 * @param object $row Result row
 * @return NULL|array
 */
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


/**
 * Get fields in result object matching the search term(s)
 * 
 * @param string $service
 * @param object $result
 * @return array|boolean
 */
function _getHits ($service, $result) {
	// Paths used are stored in session
	$queryPaths = _getQueryPaths($service);
	if (!$queryPaths) {
		return false;
	}
	foreach ($queryPaths as $path => $item) {
		$hits = [];
		// Convert NBA path to object path
		$pathElements = explode('.', $path);
		foreach ($item['values'] as $value) {
			$hit = _getHitInResult($pathElements, $result, $value, $item['operator']);
			if (!empty($hit)) {
				$hits[] = $hit;
			}
		}
		// Store value only once; it will always be the same value found multiple times
		if (!empty($hits)) {
			$output[$path] = trim($hits[0][0]);
		}
	}
	return isset($output) ? $output : false;
}
 
/**
 * Get hit(s) in result object
 * 
 * Recursive function looping over path elements (as in the three elements in
 * acceptedNames.scientificName.genusOrMonomial). First find appropriate element
 * in the result object, next check if there's a match based on the operator used
 * for the search. 
 * 
 * @param array $pathElements 
 * @param object $result
 * @param string $value
 * @param string $operator
 * @return boolean|array Hits
 */
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
				// Objects will not contains results
				if (is_object($result)) {
					return false;
				}
				// Convert array to string if necessary
				if (is_array($result)) {
					$result = array_values($result)[0];
				}
				// Operator determines if we have a hit: 
				// CONTAINS...
				if (($operator == 'CONTAINS' && stripos($result, $value) !== false) ||
				// STARTS_WITH_IC
					($operator == 'STARTS_WITH_IC' && stripos($result, $value) === 0) ||						
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

/**
 * Highlight hits
 * 
 * Highlight and reduces path to last word to facilitate translation
 * 
 * @param unknown $service
 * @param array $hits
 * @return boolean|string
 */
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
 * Experimental highlight function from Linnaeus NG by Maarten Schermer.
 * Modified to use anonymous callback functions.
 *
 * @param string $haystack Input string
 * @param array $needles Matches
 * @return string
 */
function _highlightMatch ($haystack, $needles) {
	// Intermediate set required to prevent highlighting of html;
	// temporarily converted to non-printing characters
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
	// Flip back temporarily replaced terms
	return str_replace($r, $f, $haystack);
}

/**
 * Sets url with size reset to maximum
 * 
 * @param int $total
 * @param array $criteria
 * @return string|NULL
 */
function _setShowAllQuery ($total, $criteria) {
	if ($total > _maxResultsInitial()) {
		$criteria['size'] = _maxResults();
		return safe_http_build_query($criteria);
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

/**
 * Type statuses for a specimen
 * 
 * @param array $identifications
 * @return array
 */
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
 * Translates decimal coordinate pair to DMS
 *
 * Adapted from
 * https://www.dougv.com/2012/03/converting-latitude-and-longitude-coordinates-between-decimal-and-degrees-minutes-seconds/
 *
 * Takes decimal coordinates and return degree, minute, second notation. Original function only
 * accepted single parameter; adapted to take both latitude and longitude immediately.
 *
 * @param Decimal $lat Latitude
 * @param Decimal $lon Longitude
 * @return string Latitude, longitude
 */
function _decimalToDMS ($lat, $lon) {
     $coordinates = array(
        'lat' => $lat,
        'lon' => $lon
     );
     foreach ($coordinates as $type => $decimal) {
        if (!is_numeric($decimal) || abs($decimal) > 180) {
            return false;
        }
        if ($type == 'lat' && $decimal < 0) {
              $direction = t('S');
        } else if ($type == 'lon' && $decimal < 0) {
          $direction = 'W';
        } else if ($type == 'lon') {
          $direction = t('E');
        } else {
          $direction = 'N';
        }
        $d = abs($decimal);
        $degrees = floor($d);
        $seconds = ($d - $degrees) * 3600;
        $minutes = floor($seconds / 60);
        $seconds = floor($seconds - ($minutes * 60));
        $output[$type] = $degrees . '&deg;' . $minutes . "'" . $seconds . '"' . $direction;
     }
     return isset($output) && count($output) == 2 ? implode(', ', $output) : false;
}

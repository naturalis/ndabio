<?php

/* TODO!

	- Pass searchterm as $searchTerm. This is not necessary anymore if the NDA returns the
	search term with the result (as promised by Ayco! ;), but this script will need further modifications
	if this happens.
	- Common names in taxon result are not yet interface dependent. Set $language in getCommonNames.
	- Check formatting and highlighting of scientific name with real world result
	- Wrapper functions t, handleError and translateNdaField should be replaced
	- Get multimedia and species names urls in specimen details (not yet present in mockup)
	
	
	
*/
/*	
	// Taxon
	$file = 'json/group-taxa-by-name.json';
	$json = file_get_contents($file);
	$data = parseTaxa($json);
	printTaxa($data);

	$file = 'json/groupSpecimenBySpecificName.json';
	$json = file_get_contents($file);
	$data = parseSpecimensByTaxon($json);
	printSpecimensByTaxon($data);

	$file = 'json/getSpecimensForOtherSearchTerms.json';
	$json = file_get_contents($file);
	$data = parseSpecimens($json);
	printSpecimens($data);
	
	$file = 'json/getMediaObjects.json';
	$json = file_get_contents($file);
	$data = parseMultimedia($json);
	printMultimedia($data);

	$file = 'json/specimen-detail.json';
	$json = file_get_contents($file);
	$data = parseSpecimenDetail($json);
	printSpecimenDetail($data);

*/	

	$file = 'json/taxon-detail.json';
	$json = file_get_contents($file);
	$data = parseTaxonDetail($json);
	printTaxonDetail($data);





	// Parses taxon detail json response into array
	function parseTaxonDetail ($json) {
		$skipFields = array(
			'objectPublic'
			// etc
		);
		if (!$json || !validJson($json)) {
			handleError('No or invalid json response');
		}
		$data = json_decode($json);
//print_r($data);

		foreach ($data->searchResults as $row) {
			$source = $row->result->sourceSystem->name;
			$output['acceptedNames'][$source] = formatScientificName(
				$row->result->acceptedName->fullScientificName,
				$row->result->acceptedName
			);
			if (!empty($row->result->defaultClassification)) {
				$output['classifications']['default'][$source] = 
					$row->result->defaultClassification;
			}
			if (!empty($row->result->systemClassification)) {
				$output['classifications']['system'][$source] = 
					$row->result->systemClassification;
			}
			if (!empty($row->result->synonyms)) {
				foreach ($row->result->synonyms as $i => $synonym) {
					$output['synonyms'][$source] = formatScientificName(
						$row->result->synonyms[$i]->scientificName->fullScientificName,
						$row->result->synonyms[$i]->scientificName
					);
				}
			}
			if (!empty($row->result->descriptions)) {
				foreach ($row->result->descriptions as $i => $description) {
					$output['descriptions'][$description->language][$source] = 
						$description->description;
				}
			}
			if (!empty($row->result->commonNames)) {
				foreach ($row->result->commonNames as $i => $name) {
					$output['commonNames'][$name->language][$source] = 
						$name->name;
				}
			
			}
		}

print_r($output);


		return $output;
	}


	function printTaxonDetail ($data) {

	}
	
	

	// Parses specimen detail json response into array
	function parseSpecimenDetail ($json) {
		$skipFields = array(
			'objectPublic'
			// etc
		);
		if (!$json || !validJson($json)) {
			handleError('No or invalid json response');
		}
		$data = json_decode($json);
//print_r($data);
		foreach ($data->searchResults[0]->result as $field => $value) {
			if (!is_array($value) && !is_object($value) && 
				!in_array($field, $skipFields) && $value != '') {
				$output[t(translateNdaField($field))] = $value;
			}
		}
		$output['source'] = $data->searchResults[0]->result->sourceSystem->name;
		$output['names'] = getSpecimenTaxonNames($data->searchResults[0]);
		$output['otherSpecimens'] = getOtherSpecimens($data);
		$output['navigation'] = getNavigation($data);
//print_r($output);
		return $output;
	}
	
	
	// Return previous/next links from result set
	function  getNavigation ($data) {
		if (isset($data->links) && !empty($data->links)) {
			foreach ($data->links as $link) {
				if ($link->rel == 'prev' || $link->rel == 'next') {
					$output[$link->rel] = $link->href;
				}
			}
		}
		return isset($output) ? $output : null;
	}


	// Print specimen detail on screen
	function printSpecimenDetail ($data) {
		// Determines order to print field/value;
		// fields not in array are printed at the bottom.
		$fieldOrder = array(
			'unitID',
			'names'
			// etc
		);
		// Reorder input array
		$data = array_merge(array_flip($fieldOrder), $data);
		$output = "<h3>" . t('Specimen details') . "</h3>\n" .
			"<h5 class='source'>" . $data['source'] . "</h5>\n";
		// Navigation
		$output .= printNavigation($data);
		$output .= "<table class='table-property-list'>\n<tbody>\n";
		foreach ($data as $field => $value) {
			if (is_array($value)) {
				// Taxon name
				if ($field == 'names') {
					$output .= printSpecimenDetails($value, 'species');
				}
			} else {
				$output .= printTableRow($field, $value);
			}
		}
		// Other specimens in collection/set are printed in different table
		if (isset($data['otherSpecimens']) && !empty($data['otherSpecimens'])) {
			$output .= "</tbody>\n</table>\n" .
				"<table class='table-property-list'>\n<tbody>\n";
			$output .= printSpecimenDetails($data['otherSpecimens'], 'other');
		}
		echo $output . "</tbody>\n</table>\n";
	}
	
	// Prints navigation on details page
	function printNavigation ($data) {
		$output = "<div class='navigation'>\n";
		if (isset($data['navigation']) && !empty($data['navigation'])) {
			$links = array_merge(array_flip(array('prev', 'next')), $data['navigation']);
			foreach ($links as $direction => $url) {
				$t = "<div class='$direction";
				$t .= !empty($url) ? 
					"'><a href='" . printDrupalLink($url) . "'>" . $direction . "</a></div>\n" : 
					"-disabled'></div>\n";
				$output .= $t;
			}
		}
		return $output . "</div>\n";
	}
	


	// Prints taxon identifications for specimen (used only for non-name search)
	function printSpecimenDetails ($details, $fieldLabel) {
		$output = '';
		foreach ($details as $i => $detail) {
			$t = $detail['name'];
			$t = !empty($detail['url']) ? 
				'<a href="' . printDrupalLink($detail['url']) . '">' . $detail['name'] . '</a>' : $t;
			$output .= printTableRow(($i == 0 ? t($fieldLabel) : ''), $t);
		}
		return !empty($output) ? $output : null;
	}
	


	// Return other specimens for detail page
	function getOtherSpecimens ($row) {
		if (!empty($row->searchResults[0]->result->otherSpecimensInSet)) {
			foreach ($row->searchResults[0]->result->otherSpecimensInSet as $i => $specimen) {
				$s = array();
				$s['name'] = $specimen->unitID;
				//$s['collectionType'] = $specimen->collectionType;
				$s['url'] = getSpecimenInCollectionUrl($row, $i);
				$c[] = $s;
			}
		}
		return isset($c) ? $c : null;
	}
	
	function printTableRow ($field, $value) {
		return "<tr>\n<td>" . ($field != '' ? t(translateNdaField($field)) : '') . "</td>\n<td>" .
			($value != '' ? $value : '') . "</td>\n</tr>\n";
	}

	
	// Parses multimedia json response into array
	function parseMultimedia ($json) {
		if (!$json || !validJson($json)) {
			handleError('No or invalid json response');
		}
		$data = json_decode($json);
//print_r($data);
		$output['searchTerms'] = getSearchTerms($data);
		$output['total'] = getTotalRows($data);
		if (!$output['searchTerms'] || !$output['total']) {	
			handleError('Invalid json response');
		}
		foreach ($data->searchResults as $row) {
			$type = isset($row->result->taxon) ? 'taxon' : 'specimen';
		
			$d['title'] = $row->result->title;
			$d['caption'] = $row->result->caption;
			$d['score'] = $row->score;
			$d['url'] = $row->links[0]->href;
			$d['source'] = $row->result->{$type}->sourceSystem->name;
			$d['imgSrc'] = getImageUrl($row);
			$d['hits'] = getHits($row);
			$output['results'][] = $d;
		}
		return isset($output) ? $output : false;
	}	
	
	
	// Prints multimedia on screen
	function printMultimedia ($data) {
		$output = '<h2>' . t('Your search for') . ' ' . printMatches($data) . 
			' ' . t('returned') . ' ' . $data['total'] . ' ' . t('images') . ".</h2>\n" .
			"<h3 class='results-set-header'>" . t('Multimedia') . "</h3>\n" . 
			"<div class='col-results-set'>\n";
		foreach ($data['results'] as $i => $row) {
			$output .= "<div class='image'>\n" .
				"<a href='" . printDrupalLink($row['url']). "' title='" . $row['title'] . "'>\n" .
				"<img src='" . $row['imgSrc']. "' alt='" . $row['title'] . "' ></a>\n" .
				"<div class='image-title'>\n" . $row['caption'] . "</div>\n" .
				"<div class='image-hits'>\n" . printHits($row) . "</div>\n" .
				"<div class='image-source'>" . $row['source'] . "</div>\n</div>\n";	
		}
		echo $output . "</div>\n";
	}
	
	
	// Prints matches on screen
	function printMatches ($data) {
		$output = '';
		if (isset($data['searchTerms']) && !empty($data['searchTerms'])) {
			foreach ($data['searchTerms'] as $term) {
				$output .= '<span class="result-query">' . $term . '</span>, ';
			}
		}
		return substr($output, 0, -2);
	}
	
	// Returns specimens searched for other fields but taxon
	function parseSpecimens ($json) {
		if (!$json || !validJson($json)) {
			handleError('No or invalid json response');
		}
		$data = json_decode($json);
		$output['searchTerms'] = getSearchTerms($data);
		$output['total'] = getTotalRows($data);
		if (!$output['searchTerms'] || !$output['total']) {	
			handleError('Invalid json response');
		}
		foreach ($data->searchResults as $row) {
			$d = array();
			$d['registrationNumber'] = $row->result->unitID;
			$d['url'] = $row->links[0]->href;
			$d['names'] = getSpecimenTaxonNames($row);
			$d['hits'] = getHits($row);
			$d['source'] = $row->result->sourceSystem->name;
			$d['score'] = $row->score;
			$output['results'][] = $d;
		}
		return isset($output) ? $output : false;
	}
	
	
	
	// Prints specimen result set on screen. 
	function printSpecimens ($data, $p = array('sortColumn' => 0, 'sortDirection' => 'asc')) {
		$headers = array(
			array(
				'label' => t('Specimen'),
				'sort' => 1,
				'icon' => 'icon-sort-by-alphabet',
				'url' => '#'
			),
			array(
				'label' => t('Species'),
				'sort' => 1,
				'icon' => 'icon-sort-by-alphabet',
				'url' => '#'
			),
			array(
				'label' => t('Found in'),
				'sort' => 0
			),
			array(
				'label' => t('Match'),
				'sort' => 1,
				'icon' => 'icon-sort-by-attributes',
				'url' => '#'
			)
		);
		$output = '<h2>' . t('Your search for') . ' ' . printMatches($data) . 
			' ' . t('returned') . ' ' . $data['total'] . ' ' . t('specimens') . ".</h2>\n" .
			"<h3 class='results-set-header'>" . t('Species with specimens') . "</h3>\n" . 
			"<table class='table'>\n<thead>\n" . printHeaders($headers, $p) . 
			"</thead>\n<tbody>\n";
		foreach ($data['results'] as $i => $row) {
			$output .= "<tr>\n";
			// Registration number plus hits
			$output .= "<td><a href='" . printDrupalLink($row['url']) . "'>" . $row['registrationNumber'] . "</a>" . 
				(!empty($row['hits']) ? '</br>' . printHits($row) : '') .
				"</td>\n";
			// Species
			$output .= "<td>" . printSpecimenTaxa($row['names']) . "</td>\n";
			// Source(s)
			$output .= "<td>" . $row['source'] . "</td>\n";
			// Match 
			$output .= "<td>" . decorateScore($row['score']) . "</td>\n";
			$output .= "</tr>\n"; 
		}
		echo $output . "</tbody>\n</table>\n";
	}	
	
	
	// Prints hits as field: hits;
	// replaces default <span> with <span class="highlight">
	function printHits ($row) {
		$output = '';
		if (isset($row['hits']) && !empty($row['hits'])) {
			foreach ($row['hits'] as $field => $hit) {
				$output .= t(translateNdaField($field)) . ': ' . 
					str_replace('<span>', '<span class="highlight">', $hit) . '</br>';
			}
		}
		return !empty($output) ? substr($output, 0, -5) : null;
	}
	
	
	// Prints taxon identifications for specimen (used only for non-name search)
	function printSpecimenTaxa ($names) {
		$output = '';
		foreach ($names as $name) {
			$t = $name['name'];
			$t = !empty($name['url']) ? 
				'<a href="' . printDrupalLink($name['url']) . '">' . $name['name'] . '</a>, ' : 
				$t . ', ';
			$output .= $t;
		}
		return !empty($output) ? substr($output, 0, -2) : null;
	}
	
	
	// Returns taxon names for specimens plus their url found by other fields but name
	// (for specimens found by taxon name only a single name is returned!)
	function getSpecimenTaxonNames ($row) {
		foreach ($row->result->identifications as $i => $id) {
			$output[] = array(
				'name' => formatScientificName(
					$id->scientificName->fullScientificName, 
					$id->scientificName
				),
				'url' => getSpecimenTaxonUrl($row, $i)
			);
		}
		return isset($output) ? $output : false;
	}
	
	
	// Returns url for a taxon associated with the specimen
	function getSpecimenTaxonUrl ($row, $i) {
		if (!empty($row->links)) {
			foreach ($row->links as $link) {
				if ($link->rel == "identifications[{$i}].scientificName.fullScientificName") {
					return $link->href;
				}
			}
		}
		return null;
	}


	
	// Parses specimen json response into array; searched by taxon
	function parseSpecimensByTaxon ($json) {
		if (!$json || !validJson($json)) {
			handleError('No or invalid json response');
		}
		$data = json_decode($json);
//print_r($data);
		$output['searchTerms'] = getSearchTerms($data);
		$output['total'] = getTotalRows($data);
		if (!$output['searchTerms'] || !$output['total']) {	
			handleError('Invalid json response');
		}
		foreach ($data->resultGroups as $row) {
			$d = array();
			$d['name'] = formatScientificName(
				$row->searchResults[0]->matchInfo[0]->value, 
				$row->searchResults[0]->result->identifications[getResultOffset($row)]->scientificName, 
				$output['searchTerms']
			);
			$d['url'] = $row->links[0]->href;
			$d['count'] = count($row->searchResults);
			$d['sources'] = getSources($row);
			$d['score'] = $row->searchResults[0]->score;
			
			// Specimens are stored in a subarray. Brahms may feature "specimen collections" 
			// (or, in other words, a set),  which are virtual entities collecting different parts of the same individual,
			// e.g. leaves, fruits and flowers of the same plant. If the "collection" contains just
			// one specimen (as in CRS), there's only a single specimen in the "collection".
			$c = $s = array();
			// Collection/set
			$c['setId'] = $row->searchResults[0]->result->setID;
			// Specimen(s)
			$s['registrationNumber'] =  $row->searchResults[0]->result->unitID;
			$s['collectionType'] = $row->searchResults[0]->result->collectionType;
			$s['url'] = $row->searchResults[0]->links[0]->href;
			$otherSpecimens = getOtherSpecimens($row);
			$c['specimens'] = !empty($otherSpecimens) ? array_merge(array($s), $otherSpecimens) : array($s);
			$d['set'] = $c;
			$output['results'][] = $d;
		}
		return isset($output) ? $output : false;
	}



	// Returns image properties
	function getImageUrl ($row) {
		$key = key(get_object_vars($row->result->serviceAccessPoints));
		return $row->result->serviceAccessPoints->{$key}->accessUri;
	}
	
	
	// Return the field containing the hit
	function getHits ($row) {
		foreach ($row->matchInfo as $info) {
			$e = explode('.', $info->path);
			$hits[end($e)] = $info->valueHighlighted;
		}
		return isset($hits) ? $hits : array();
	}
	
	
	// Prints specimen result set on screen. 
	function printSpecimensByTaxon ($data, $p = array('sortColumn' => 0, 'sortDirection' => 'asc')) {
		$headers = array(
			array(
				'label' => t('Name'),
				'sort' => 1,
				'icon' => 'icon-sort-by-alphabet',
				'url' => '#'
			),
			array(
				'label' => t('Number'),
				'sort' => 1,
				'icon' => 'icon-sort-by-attributes',
				'url' => '#'
			),
			array(
				'label' => t('Found in'),
				'sort' => 0
			),
			array(
				'label' => t('Match'),
				'sort' => 1,
				'icon' => 'icon-sort-by-attributes',
				'url' => '#'
			)
		);
		$output = '<h2>' . t('Your search for') . ' ' . printMatches($data) . 
			' ' . t('returned') . ' ' . $data['total'] . ' ' . t('specimens') . ".</h2>\n" .
			"<h3 class='results-set-header'>" . t('Species with specimens') . "</h3>\n" . 
			"<table class='table'>\n<thead>\n" . printHeaders($headers, $p) . 
			"</thead>\n<tbody>\n";
		foreach ($data['results'] as $i => $row) {
			$output .= "<tr>\n";
			// Name
			$output .= "<td><a href='" . printDrupalLink($row['url']) . "'>" . $row['name'] . "</a>" . 
				(!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '') .
				"</td>\n";
			// Number (and collection type)
			$output .= "<td>" . $row['count'] . ' ' . ($row['count'] > 1 ? t('specimens') : t('specimen')) . "</td>\n";
			// Source(s)
			$output .= "<td>" . implode('</br>', $row['sources']) . "</td>\n";
			// Match 
			$output .= "<td>" . decorateScore($row['score']) . "</td>\n";
			$output .= "</tr>\n"; 
			$output .= printSpecimenCollection($row);
		}
		echo $output . "</tbody>\n</table>\n";
	}




	// Returns collection/set of specimens or just a specimen if a collection contains a single entry
	function printSpecimenCollection ($row) {
		// Single specimen
		if (empty($row['set']['setId'])) {
			return "<tr>\n<td><a href='" . printDrupalLink($row['set']['specimens'][0]['url']) . "'>" . 
				$row['set']['specimens'][0]['registrationNumber'] . "</a></td>\n" . padTds(3) . "</tr>\n";
		}
		// Specimen collection/set
		$output = "<tr>\n<td>Brahms " . $row['set']['setId'] . "</td>\n" . padTds(3) . "</tr>\n";
		foreach ($row['set']['specimens'] as $specimen) {
			$output .= "<tr>\n<td><a href='" . printDrupalLink($specimen['url']) . "'>" . 
				$specimen['registrationNumber'] . "</a></td>\n" . padTds(1) . "<td>" . 
				t(translateNdaField($specimen['collectionType'])) . "</td>\n" . padTds(1) . "</tr>\n";
		}
		return $output;
	}

	// Shorthand function to pad "filler" tds
	function padTds ($i) {
		if ((int)$i > 0) {
			return str_repeat("<td></td>\n", $i);
		}
	}
	
	// Create Drupal specific link
	function printDrupalLink ($url) {
		return "http://drupal/?nda_request=" . urlencode($url);
	}

	// Return url for specimens in "collection"/set
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
	
	// Prints headers of result table on screen
	function printHeaders ($headers, $p) {
		$output = "<tr>\n";
		foreach ($headers as $i => $header) {
    		$output .= "<th class='col-no-" . ($i + 1) . "'>";
    		if ($header['sort'] == 1) {
    			// Selected header
    			if ($i == $p['sortColumn']) {
    				$header['url'] .= ($p['sortDirection'] == 'asc' ? '&desc' : '&asc');
    				$output .= "<a href='" . printDrupalLink($header['url']) . "'>" . 
    					$header['label'] . "</a>\n" .
    					"<a href='" . printDrupalLink($header['url']) . "'>" .
    					"<span class='sortable glyphicon " . $header['icon'] . 
    					($p['sortDirection'] == 'desc' ? "-alt" : "") . "'></span>\n</a>";
    			// Other headers
    			} else {
    				$header['url'] .= '&desc';
    				$output .= "<a href='" . printDrupalLink($header['url']) . "'>" . 
    					$header['label'] . "</a>\n" .
    					"<a href='" . printDrupalLink($header['url']) . "'>" .
    					"<span class='sortable glyphicon icon-sort'></span>\n</a>";
    			}
    		} else {
    			$output .= $header['label'];
    		}
    		$output .= "</th>\n"; 
		}
		return $output . "</tr>\n";
	}

	// Parses taxon/species json response into array
	function parseTaxa ($json) {
		if (!$json || !validJson($json)) {
			handleError('No or invalid json response');
		}
		$data = json_decode($json);
		$output['total'] = getTotalRows($data);
		$output['searchTerms'] = getSearchTerms($data);
		if (!$output['searchTerms'] || !$output['total']) {	
			handleError('Invalid json response');
		}
		foreach ($data->resultGroups as $row) {
			$d = array();
			// Accepted scientific name, synonym, or common name
			$d['type'] = getResultType($row);
			if ($d['type'] == 'accepted') {
				$d['name'] = formatScientificName(
					$row->searchResults[0]->matchInfo[0]->value, 
					$row->searchResults[0]->result->acceptedName, 
					$output['searchTerms']
				);
			} else if ($d['type'] == 'synonym') {
				$d['name'] = formatScientificName(
					$row->searchResults[0]->matchInfo[0]->value, 		
					$row->searchResults[0]->result->synonyms[getResultOffset($row)]->scientificName, 
					$output['searchTerms']
				);
			} else if ($d['type'] == 'common') {
				$d['name'] = highlightMatch(
					$row->searchResults[0]->matchInfo[0]->value,
					$output['searchTerms']
				);
			}
			$d['acceptedName'] = (
				$d['type'] == 'accepted' ? 
				$d['name'] :
				formatScientificName(
					$row->searchResults[0]->result->acceptedName->fullScientificName,
					$row->searchResults[0]->result->acceptedName
				)
			);
			$d['rank'] = $row->searchResults[0]->result->taxonRank;
			$d['url'] = $row->links[0]->href;
			$d['sources'] = getSources($row);
			$d['commonNames'] = ($d['type'] != 'common' ? getCommonNames($row) : array());
			$d['score'] = $row->searchResults[0]->score;
			$output['results'][] = $d;
		}
		return isset($output) ? $output : false;
	}
	
	
	
	
	/* Prints taxon result set on screen. Parameters $p should contain:
	   'sortColumn', 'sortDirection'
	   
	   TODO: 
	   1. Set truncated (for overview)/non-truncated 
	   2. Pass $p['total'] dynamically
	
	*/
	function printTaxa ($data, $p = array('sortColumn' => 0, 'sortDirection' => 'asc')) {
		$headers = array(
			array(
				'label' => t('Name'),
				'sort' => 1,
				'icon' => 'icon-sort-by-alphabet',
				'url' => '#'
			),
			array(
				'label' => t('Description'),
				'sort' => 0
			),
			array(
				'label' => t('Found in'),
				'sort' => 0
			),
			array(
				'label' => t('Match'),
				'sort' => 1,
				'icon' => 'icon-sort-by-attributes',
				'url' => '#'
			)
		);
		$output = '<h2>' . t('Your search for') . ' ' . printMatches($data) . 
			' ' . t('returned') . ' ' . $data['total'] . ' ' . t('species') . ".</h2>\n" .
			"<h3 class='results-set-header'>" . t('Species names') . "</h3>\n" . 
			"<table class='table'>\n<thead>\n". printHeaders($headers, $p) . 
			"</thead>\n<tbody>\n";
		foreach ($data['results'] as $i => $row) {
			$output .= "<tr>\n";
			// Name
			$output .= "<td><a href='" . printDrupalLink($row['url']) . "'>" . $row['name'] . "</a>" . 
				(!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '') .
				"</td>\n";
			// Description
			$output .= "<td>" . decorateDescription($row) . "</td>\n";
			// Source(s)
			$output .= "<td>" . implode('</br>', $row['sources']) . "</td>\n";
			// Match 
			$output .= "<td>" . decorateScore($row['score']) . "</td>\n";
			$output .= "</tr>\n"; 
		}
		echo $output . "</tbody>\n</table>\n";
	}

	// Validates json string
	function validJson ($string) {
		return is_object(json_decode($string));
	}
	
	// Returns type of result:
	// acceptedName.fullScientificName
	// acceptedName.synonyms[0].scientificName.fullScientificName
	// acceptedName.commonNames[0].name
 	function getResultType ($row) {
 		$path = $row->searchResults[0]->matchInfo[0]->path;
 		return strpos($path, 'synonym') !== false ? 'synonym' :
 			(strpos($path, 'commonName') !== false ? 'common' : 'accepted');
	}
	
	// Returns offset of result; used only for synonyms and common names
	// to determine the array key containing the hit
	// Used for taxon/specimenByTaxon
	function getResultOffset ($row) {
		preg_match('/\[(.*?)\]/', $row->searchResults[0]->matchInfo[0]->path, $m);
		return $m[1];
	}	
	
	// Returns total number of results
	function getTotalRows ($data) {
		if (isset($data->totalSize)) {
			return (int)$data->totalSize;
		}
		return false;
	}
	
	// Returns total number of results
	function getSearchTerms ($data) {
		if (isset($data->searchTerms)) {
			return (array)$data->searchTerms;
		}
		return false;
	}
	
	// Results formatted accepted name with proper use of italics
	function formatScientificName ($scientificname, $nameObject, $searchTerm = false) {
		$output = $scientificname;
		$elements = getScientificNameElements($nameObject);
		foreach ($elements as $e) {
			if (!empty($e)) {
				$output = str_replace($e, '<span class="italic">' . $e . '</span>', $output);
			}
		}
		// Highlight the formatted output
		return $searchTerm ? highlightMatch($output, $searchTerm) : $output;
	}
	
	// Returns scientific name elements from name object
	// Store as keys and flip to avoid duplicates (as in Larus fuscus fuscus)
	function getScientificNameElements ($name) {
		$elements = array(
			$name->genusOrMonomial => 0,
			$name->subgenus => 1,
			$name->specificEpithet => 2,
			$name->infraspecificEpithet => 3
		);
		return array_flip($elements);
	}
	
	// Returns all sources for taxon/specimen
	function getSources ($row) {
		foreach ($row->searchResults as $i => $obj) {
			$output[$obj->result->sourceSystem->name] = $i;
		}
		return isset($output) ? array_flip($output) : false;
	}
		
	// Returns common names for the current interface language;
	// format is array(name => language), so duplicates will be avoided
	function getCommonNames ($row, $language = false) {
		foreach ($row->searchResults as $i => $taxon) {
			if (isset($taxon->result->commonNames)) {			
				foreach ($taxon->result->commonNames as $name) {
					// If language is set, only store when language of
					// common name matches that of interface...
					if ($language) {
						if ($name->language == $language) {
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


	// Decorate description in taxon result table 
	function decorateDescription ($row) {
		return ($row['type'] != 'accepted' ? 
			t(ucfirst($row['type'])) . ($row['type'] == 'common' ? ' ' . t('name') : '') . 
			' ' . t('for') . ' ' :  '') . ($row['type'] == 'accepted' ? t(ucfirst($row['rank'])) : 
			t($row['rank'])) . ' ' . $row['acceptedName'];
	}

	// Decorate score in result table
	function decorateScore ($score) {
    	$score = round($score * 100);
    	return "<div class='score text-hide'>\n<div class='score-bar' style='width: $score%'>".
    		"$score%</div>\n</div>\n";
    }

	// Highlight match
	function highlightMatch($haystack, $needles) {
		foreach ($needles as $needle) {
			if (stripos(strip_tags($haystack), $needle)===false || is_null($needle)) {
				continue;
			}
			$q = str_split($needle);
			$x = ')(\<[^<]*\>)*(';
			$q = str_replace('( )','(\s*)','('.implode($x, $q).')');
			$haystack = preg_replace_callback('/'.$q.'/i','_fsub1', $haystack);
		}
		return $haystack;
	}

	function _fsub1($m) {
		return "<span class='result-query'>".preg_replace_callback('(<(.*?)>)','_fsub2',$m[0])."</span>";
	}
	
	function _fsub2($m) {
		return '</span>'.$m[0]."<span class='result-query'>";
	}


	// Wrapper for Drupal error handler
	function handleError ($message) {
		die($message);
	}
	
	// Should be replaced with Drupal translate function
	function t ($str) {
		return $str;	
	}
	
	// Should be replaced with a function that translates NDS field labels to proper English
	function translateNdaField ($str) {
		return $str;
	} 


?>
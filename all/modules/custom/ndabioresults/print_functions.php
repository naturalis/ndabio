<?php



/**
 * Prints taxon media result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printTaxonMediaDetail ($data) {
//p($data);

    $output  = _wrap( t("Media item")   , "div", "category");
    $output .= _wrap( '', "h2"  );

    $output .= printPreviousNext();

    $altParts = array(
        isset($data['names'][0]['name']) ? strip_tags($data['names'][0]['name']) : '',
        isset($data['caption']) ? strip_tags($data['caption']) : ''
    );
    $alt = implode(' | ', array_filter($altParts));

    // Temp solution to show fullsize images
    $data['imgSrc'] = str_replace('/comping/', '/original/', $data['imgSrc']);

    list($width, $height) = loadPrettyPhoto($data['imgSrc']);
    $img = "<img src='" . $data['imgSrc'] . "' alt='$alt' title='$alt' " .
        "style='width: {$width}px; height: {$height}px;'/>";
    if ($width > 0) {
        $copyright = !empty($data['copyrightText']) ?
            $copyright = '© ' . $data['copyrightText'] : '';
        array_unshift($altParts, $data['sourceInstitutionID'], $copyright);
        $caption = implode('<br/>', array_filter($altParts));
        $img = "<a href='" . $data['imgSrc'] . "' rel='prettyPhoto' title='$caption'>$img</a>\n";
    }






    $output .= $img;

    $output .= "<div class='property-list'>";
    $output .= printNamesWithLinks($data['names'], t('Scientific name'));

	$fields = array(
	    'source',
    	'creator',
	    'license',
        'sourceInstitutionID',
        'collectionType',
	    'description',
        'copyrightText',
    	'locality',
    	'date',
	    'phaseOrStage',
        'sexes'
	);
	foreach ($fields as $field) {
		if ($field == 'source' && !empty($data['sourceUrls'])) {
            $data['source'] = printSource($data, $data['source']);
	    }
	    $output .= printDL(ucfirst(translateNdaField($field)), printValue($data[$field]));
	}

    // Drupal title empty; page title custom
	setTitle(t('Multimedia') . ' | ' . strip_tags($data['acceptedName']));

    return $output . "</div>";
}


/**
 * Prints taxon search result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printTaxa ($data) {
//p($data);
    if (empty($data['results'])) {
        return false;
    }

    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    setTitle($headTitle, $headTitle);

    $headers = array(
    	'acceptedName.fullScientificName' => array(
    		'label' => t('Name'),
    		'sort' => 'ASC',
    		'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
    		'url' => setSortUrl('acceptedName.fullScientificName', 'ASC', $data['self'])
    	),
    	'description' => array(
    		'label' => t('Description')
    	),
    	'foundIn' => array(
    		'label' => t('Found in')
    	),
    	'_score' => array(
    		'label' => t('Match'),
    		'sort' => 'DESC',
    		'icon' => array(
			    'ASC' => 'icon-sort_little_much',
			    'DESC' => 'icon-sort_much_little'
			),
    		'url' => setSortUrl('_score', 'DESC', $data['self'])
    	)
    );

    $explanation = _wrap(t("(matching scientific or common name)"),"span","explanation");

    $output = '<div id="' . taxonService() . '"></div>';
    $output .= sprintf(
        '<h2>%s <span class="count">(%s)</span> %s</h2>',
        t('Species names'),
        _formatNumber($data['total']),
        $explanation
    );
    $output .= sprintf('<table><thead>%s</thead><tbody>', printHeaders($headers, $data['self']));

    foreach ($data['results'] as $i => $row) {
    	$output .= "<tr>";

        // Name
        $output .= "<td>";
        $output .= "<a href='" . printDrupalLink($row['url']) . "'>" . $row['name'] . "</a>";
        $output .= (!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '');
        $output .=	"</td>";

        // Description
        $output .= "<td>" . $row['description'] . "</td>";

        // Source(s)
        $output .= "<td>" . implode('</br>', $row['sources']) . "</td>";

        // Match
        	$output .= "<td>" . decorateScore($row['score']) . "</td>";

        $output .= "</tr>";
    }

    $output .= "</tbody></table>";
    $output = _markUp($output);

    $output .= printShowAll($data);
    $output .= printPaginator($data);

    return $output;
}


/**
 * Prints taxon identifications for specimen (used only for non-name search)
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimenTaxa ($names) {
	$output = '';
	foreach ($names as $name) {
		$t = $name['name'];
		$t = !empty($name['url']) ?
			'<a href="' . printDrupalLink($name['url']) . '">' . $name['name'] . '</a>, ' :
			$t . ', ';
		$output .= $t;
	}
	return !empty($output) ? substr($output, 0, -2) : '-';
}


/**
 * Prints taxon detail result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printTaxonDetail ($data) {
    global $language;

    $output  =   "<div class='category'>".t('Taxon')."</div>";
    $output .=   "<h2>";
    $output .=   "  <span class='scientific-name'>";
    $output .=        $data['acceptedName'];
    $output .=   "  </span>";

    if ( isset($data['commonNames'][$language->language]) ){
        $output .= "  <span class='vernacular-name'>";
        $output .=      implode(', ', $data['commonNames'][$language->language]);
        $output .= "  </span>";
    }

    $output .= "</h2>";

    $output .=
        printCommonNames($data) .
        printSynonyms($data) .
        printDescriptions($data) .
        printClassifications($data);

//p($data);

    $getSpecimenRequest = ndaBaseUrl() . specimenNamesService() .
        '/?' . http_build_query($data['nameElements']) . '&_andOr=AND';
    $getMultimediaRequest = ndaBaseUrl() . multimediaService() .
        '/?' . http_build_query($data['nameElements']) . '&_andOr=AND';

    drupal_add_js(drupal_get_path('module', 'ndabioresults') . "/js/ajax.js", array('weight' => 1));
    drupal_add_js("var getSpecimenRequest = '$getSpecimenRequest'", 'inline');
    drupal_add_js("var getMultimediaRequest = '$getMultimediaRequest' ", 'inline');
    drupal_add_js(
        "jQuery(function() { getNbaData(getSpecimenRequest, setSpecimenPreview, '&_maxResults=5'); });",
        array('type' => 'inline', 'scope' => 'footer')
    );
    drupal_add_js(
        "jQuery(function() { getNbaData(getMultimediaRequest, setMultimediaPreview, '&_maxResults=5'); });",
        array('type' => 'inline', 'scope' => 'footer')
    );

    $output .= '<h3>' . t('Specimens'). '</h3><p class="property-list" id="nba_specimens"></p>';
    $output .= '<h3>' . t('Multimedia'). '</h3><p class="property-list" id="nba_multimedia"></p>';


    // Drupal title empty; page title custom
    setTitle(t('Taxon') . ' | '. strip_tags($data['acceptedName']));

    return $output;
}


/**
 * Prints common names
 *
 * Transposes common names array and prints common names
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */

function printSynonyms ($data) {
//p($data);
	$output = "";

	$header = "<h3>" . t('Synonyms') . "</h3>";

	if (isset($data['synonyms']) && !empty($data['synonyms'])) {
	    foreach ($data['synonyms'] as $source => $synonyms) {
			$output .= "<h4 class='source'>" . printSource($data, $source) . "</h4>
			     <div class='property-list'>\n<p>\n" .
			     implode('<br/>', $synonyms) .
			     "</p>\n</div>\n";
			$oldSource = $source;
		}
	}

	return _wrap(
		$header . (!empty($output) ? $output :
		      "<p class='property-list'>" . t('No synonyms available') . '</p>'),
		"section",
		"result-detail-section"
	);
}



/**
 * Prints specimen name search result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimensByTaxon ($data) {
//p($data);
    if (empty($data['results'])) {
        return false;
    }

    if (isset($data['_showMap'])) {
        return printSpecimensByMap($data);
    }

    if (isset($data['single']) && $data['single']) {
        return printSpecimensBySingleGroup($data);
    }

    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    $nameSortFlag = isGroupService(specimenNamesService()) ?
        'groupName' : 'identifications.scientificName.fullScientificName';
    setTitle($headTitle, $headTitle);

    $headers = array(
		'identifications.scientificName.fullScientificName' => array(
			'label' => t('Name'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl(
                $nameSortFlag,
			    'ASC',
			    $data['self'],
                isGroupService(specimenNamesService())
			)
		),
		'count' => array(
			'label' => ''
		),
        'mapIcon' => array(
			'label' => ''
        ),
		'foundIn' => array(
			'label' => t('Found in')
		),
		'_score' => array(
			'label' => t('Match'),
			'sort' => 'DESC',
			'icon' => array(
			    'ASC' => 'icon-sort_little_much',
			    'DESC' => 'icon-sort_much_little'
			),
			'url' => setSortUrl(
                '_score',
			    'DESC',
			    $data['self'],
			    isGroupService(specimenNamesService())
			)
		)
	);

    $count = _wrap('(' . _formatNumber($data['total']) . ')', "span", "count");

    $output = '<div id="' . specimenNamesService() . '"></div>';
    $output .= sprintf(
        '<h2>%s %s</h2>',
        t('Species with specimens'),
        $count
    );
    $output .= sprintf(
        '<table id="specimensByTaxon"><thead>%s</thead>',
        printHeaders($headers, $data['self'])
    );

    foreach ($data['results'] as $i => $row) {
		$output .= "<tr class='indent-0' id='taxon-$i'>";
		// Name
		$url = printDrupalLink($row['url']);

		$output .= "<td>" . "<a href='" . (!empty($url) ? $url : '#') . "'>" . $row['name'] . "</a>" .
		    (!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '') . "</td>";
		// Number (and collection type)
		$output .= "<td>" . $row['count'] . ' ' . ($row['count'] > 1 ? t('specimens') : t('specimen')) . "</td>";
		// Map icon
		$output .= "<td>" .
		  (isset($_SESSION['ndaSearch']['geoShape']) && !empty($_SESSION['ndaSearch']['geoShape'])
		      && !isset($_GET['noMap']) ?
		      "<a href='" . printDrupalLink(
                specimenNamesService() . '?_geoShape=[session]&' .
		      '&identifications.scientificName.fullScientificName.raw=' .
		      urlencode($row['fullScientificName']) . '&_showMap&_maxResults=100') .
		      "' class='icon-location'></a>" : '') .
		  "</td>";
		// Source(s)
		$output .= "<td>" . implode('</br>', $row['sources']) . "</td>";
		// Match
		$output .= "<td>" . decorateScore($row['score']) . "</td>";
		$output .= "</tr>";
		$output .= printSpecimenCollection($row, $i);
	}

    $output .= "</table>";
    $output = _markUp($output);

    $output .= printShowAll($data);
    $output .= printPaginator($data);

    return $output;
}





// Prints specimen result set on screen.
function printSpecimensBySingleGroup ($data) {
//p($data);
    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    setTitle($headTitle, $headTitle);

    $headers = array(
		'unitID' => array(
			'label' => t('Specimen'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl('unitID', 'ASC', $data['self'])
		),
		'count' => array(
			'label' => ''
		),
        'mapIcon' => array(
			'label' => ''
        ),
		'foundIn' => array(
			'label' => t('Found in')
		),
		'_score' => array(
			'label' => t('Match'),
			'sort' => 'DESC',
			'icon' => array(
			    'ASC' => 'icon-sort_little_much',
			    'DESC' => 'icon-sort_much_little'
			),
			'url' => setSortUrl('_score', 'DESC', $data['self'])
		)
	);

    $count = _wrap('(' . _formatNumber($data['results'][0]['count']) . ')', "span", "count");
    $output = sprintf('<h2>%s %s</h2>', t('Specimens of ' .
        str_replace('result-query', '', $data['results'][0]['name'])), $count);

    $output .= sprintf('<table><thead>%s</thead>', printHeaders($headers, $data['self']));

    foreach ($data['results'] as $i => $row) {
        // Single specimen
        if (isset($row['specimens'])) {
            foreach ($row['specimens'] as $specimen) {
                $info = implode('; ', array_filter(array(
                    ucfirst($specimen['kindOfUnit']),
                    $specimen['preparationType']
                )));
                $output .= "<tr>
                    <td><a href='" . printDrupalLink($specimen['url']) . "'>" . $specimen['unitID'] . "</a></td>
                    <td colspan='2'>$info</td>
                    <td>" . implode('</br>', $data['results'][0]['sources']) . "</td>
                    <td>" . decorateScore($row['score']) . "</td>
                    </tr>";
            }

        // Specimen collection/set
        } else if (isset($row['sets'])) {
            foreach ($row['sets'] as $set => $specimens) {
            	$output .= "<tr><td>" . $set . "</td>" . padTds(4) . "</tr>";
            	foreach ($specimens as $j => $specimen) {
            	    $output .= "<tr class='indent-1'>
            	    <td><a href='" . printDrupalLink($specimen['url']) . "'>"  . $specimen['unitID'] . "</a></td>
            	    <td colspan='2'>" . $specimen['recordBasis'] . "</td>
                    <td>" . implode('</br>', $data['results'][0]['sources']) . "</td>
                    <td>" . decorateScore($row['score']) . "</td>
                    </tr>";
            	}
            }
        }
	}

    $output .= "</table>";
    $output = _markUp($output);

    $output .= printPaginator($data);

    return $output;
}




// Prints specimen result set on screen.
function printSpecimensByMap ($data) {
     // Add Google Maps scripts from ndabio module (REQUIRED!)
    global $base_root, $base_path;

    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    setTitle($headTitle, $headTitle);

    $path = drupal_get_path('module', 'ndabio');
    drupal_add_css($path . "/css/ndabio_style.css");
    drupal_add_js($path . "/js/map.js", array('weight' => 1));
    drupal_add_js($path . "/js/oms.min.js", array('weight' => 1));
    drupal_add_js("https://maps.googleapis.com/maps/api/js?key=" .
        variable_get('ndabio_config_gmapkey', NDABIO_GMAPKEY) . "&libraries=drawing");
    drupal_add_js(
        "jQuery(function() { google.maps.event.addDomListener(window, 'load', initializeSpecimens); });",
        array('type' => 'inline', 'scope' => 'footer')
    );
    drupal_add_js("var str_base_path = '$base_path';", 'inline');
    drupal_add_js("var specimenMarkers = " . json_encode($data['results']) .';', 'inline');
    drupal_add_js("var geoShape = " . $_SESSION['ndaSearch']['geoShape'] .';', 'inline');
    if (isset($_SESSION['ndaSearch']['mapCenter'])) {
        drupal_add_js('var storedMapCenter = "' . $_SESSION['ndaSearch']['mapCenter'] . '";', 'inline');
    }
    if (isset($_SESSION['ndaSearch']['zoomLevel'])) {
        drupal_add_js("var storedZoomLevel = " . $_SESSION['ndaSearch']['zoomLevel'] . ';', 'inline');
    }

//p($data);

    $output = sprintf('<h2>%s %s %s %s</h2>',
        t('Specimens of '),
        $data['results'][0]['name'],
        ' in ',
        (!empty($_SESSION['ndaSearch']['location']) ? $_SESSION['ndaSearch']['location'] :
            t('area drawn on map'))
    );
    $output .= '<div id="map-canvas"></div>';

    return $output;
}



/**
 * Prints specimen search result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimens ($data) {

    if (empty($data['results'])) {
        return false;
    }

    // Drupal title empty; page title custom
    $headTitle = !isset($_SESSION['ndaSearch']['theme']) || empty($_SESSION['ndaSearch']['theme']) ?
        t('Search results') : t('Explore highlights');
    $pageTitle = isset($_GET['theme']) ? '' : $pageTitle;
    setTitle($headTitle, $pageTitle);

    $headers = array(
		'unitID' => array(
			'label' => t('Specimen'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl('unitID', 'ASC', $data['self'])
		),
		'identifications.scientificName.fullScientificName' => array(
			'label' => t('Species'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl('identifications.scientificName.fullScientificName', 'ASC', $data['self'])
		),
		'foundIn' => array(
			'label' => t('Found in')
		),
		'_score' => array(
			'label' => t('Match'),
			'sort' => 'DESC',
			'icon' => array(
			    'ASC' => 'icon-sort_little_much',
			    'DESC' => 'icon-sort_much_little'
			),
			'url' => setSortUrl('_score', 'DESC', $data['self'])
		)
	);

    $output = '<div id="' . specimenService() . '"></div>';
    $output .= sprintf(
        '<h2>%s <span class="count">(%s)</span></h2>',
        t('Specimens'),
        _formatNumber($data['total'])
    );
    $output .= sprintf('<table><thead>%s</thead><tbody>', printHeaders($headers, $data['self']));

  foreach ($data['results'] as $i => $row) {
		$output .= "<tr>";
		// Registration number plus hits
		$output .= "<td><a href='" . printDrupalLink($row['url']) . "'>" . $row['unitID'] . "</a>" .
			(!empty($row['hits']) ? '<br/>' . printHits($row) : '') .
			"</td>";
		// Species
		$output .= "<td>" . printSpecimenTaxa($row['names']) . "</td>";
		// Source(s)
		$output .= "<td>" . $row['source'] . "</td>";
		// Match
		$output .= "<td>" . decorateScore($row['score']) . "</td>";
		$output .= "</tr>";
	}

	$output .= "</tbody></table>";

    $output .= printShowAll($data);
    $output .= printPaginator($data);

    return $output;
}



/**
 * Prints multimedia detail
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimenMediaDetail ($data) {
//p($data);
    drupal_add_js(
        "jQuery(function() { jQuery('#purl').focus().click(function(){ jQuery(this).select(); } ); });",
        array('type' => 'inline', 'scope' => 'footer')
    );

    $output  = _wrap(t("Media item"), "div", "category");
    $output .= _wrap('', "h2");

    $output .= printPreviousNext();

    /* For the time being disable PURL for media
     *
	$purl = '<input id="purl" type="text" value="http://data.biodiversitydata.nl/naturalis/multimedia/' .
	   $data['mediaUnitID'] . '"></input>';
	$helpText = t('Please cite the object described here by using this PURL (Persistent Uniform Resource Locator). Naturalis will try to assure the permanent character of this PURL.');
	$output .= '<div class="property-list">
	   <dl><dt style="cursor: help; width: 100%;" title="' . $helpText . '">'.
	   t("Cite as") . ':</dt><dd></dd></dl><p>' . $purl . '</p>
	   </div>';
    */

    $altParts = array(
        isset($data['unitID']) ? strip_tags($data['unitID']) : '',
        isset($data['names'][0]['name']) ? strip_tags($data['names'][0]['name']) : '',
        isset($data['caption']) ? strip_tags($data['caption']) : ''
    );
    $alt = implode(' | ', array_filter($altParts));

    list($width, $height) = loadPrettyPhoto($data['imgSrc']);
    $img = "<img src='" . $data['imgSrc'] . "' alt='$alt' title='$alt' " .
        "style='width: {$width}px; height: {$height}px;'/>";
    if ($width > 0) {
        $copyright = !empty($data['copyrightText']) ?
            $copyright = '© ' . $data['copyrightText'] : '';
        $institution = $data['sourceInstitutionID'] .
            (!empty($data['sourceID']) ? ' (' . $data['sourceID'] . ')' : '');
        array_unshift($altParts, $institution, $copyright);
        $caption = implode('<br/>', array_filter($altParts));
        $img = "<a href='" . $data['imgSrc'] . "' rel='prettyPhoto' title='$caption'>$img</a>\n";
    }

    if (isMp4($data['imgSrc'])) {
        $output .= '<video src="' . $data['imgSrc'] . '" type="video/mp4" autoplay controls></video>';
    } else {
	   $output .= $img;
    }

	$output .= "<div class='property-list'>";

	if (!empty($data['unitID'])) {
		$output .= printDL(
            ucfirst(translateNdaField('unitID')),
            '<a href="' . printDrupalLink(specimenDetailService() . '?unitID=' .
                unsetUnitId($data['unitID'])) . '">' . $data['unitID'] . '</a>'
		);
	}
	if (!empty($data['names'])) {
		$output .= printNamesWithLinks($data['names'], t('Scientific name'));
	}

	$fields = array(
        'source',
        'creator',
        'license',
        'sourceInstitutionID',
	    'collectionType',
        'description',
        'copyrightText',
    	'locality',
    	'dateTimeBegin',
        'sexes',
	    'specimenTypeStatus',
        'phaseOrStage'
	);

  	foreach ($fields as $field) {
		$output .= printDL(
            ucfirst(translateNdaField($field)),
		    is_array($data[$field]) ? implode(', ', $data[$field]) : printValue($data[$field])
		);
	}

    // Drupal title empty; page title custom
    setTitle(t('Multimedia') . ' | ' . strip_tags($data[names][0]['name']) . ' | '  . $data['unitID']);

	return $output . "</dd>\n</div>\n";
}




// Print specimen detail on screen
function printSpecimenDetail ($data) {

//p($data);

    // Do we have a valid set of coordinates? If so, add Google Map
    $lat = isset($data['gatheringEvent']['siteCoordinates']['lat']) ?
        $data['gatheringEvent']['siteCoordinates']['lat'] : false;
    $lon = isset($data['gatheringEvent']['siteCoordinates']['lon']) ?
        $data['gatheringEvent']['siteCoordinates']['lon'] : false;

    drupal_add_js(
        "jQuery(function() { jQuery('#purl').focus().click(function(){ jQuery(this).select(); } ); });",
        array('type' => 'inline', 'scope' => 'footer')
    );

    if ($lat && $lon) {
        // Add Google Maps scripts from ndabio module (REQUIRED!)
        global $base_root, $base_path;
        $path = drupal_get_path('module', 'ndabio');
        drupal_add_css($path . "/css/ndabio_style.css");
        drupal_add_js($path . "/js/map.js", array('weight' => 1));
        drupal_add_js("https://maps.googleapis.com/maps/api/js?key=" .
            variable_get('ndabio_config_gmapkey', NDABIO_GMAPKEY) . "&libraries=drawing");
        drupal_add_js(
            "jQuery(function() { google.maps.event.addDomListener(window, 'load', initializeSpecimenDetail); });",
            array('type' => 'inline', 'scope' => 'footer')
        );
        drupal_add_js("var str_base_path = '$base_path' ", 'inline');
        drupal_add_js("var specimenMarker = " .
            json_encode(array('lat' => $lat, 'lon' => $lon)), 'inline');
        if (isset($_SESSION['ndaSearch']['mapCenter'])) {
            drupal_add_js('var storedMapCenter = "' .
                $_SESSION['ndaSearch']['mapCenter'] . '";', 'inline');
        }
        if (isset($_SESSION['ndaSearch']['zoomLevel'])) {
            drupal_add_js("var storedZoomLevel = " .
                $_SESSION['ndaSearch']['zoomLevel'] . ';', 'inline');
        }
        // Add mapcode scripts
        $path = drupal_get_path('module', 'ndabioresults');
        drupal_add_js($path . "/js/mapcode/ctrynams.js", array('weight' => 1));
        drupal_add_js($path . "/js/mapcode/mapcode.js", array('weight' => 1));
        drupal_add_js($path . "/js/mapcode/ndata.js", array('weight' => 1));
        drupal_add_js($path . "/js/library.js", array('weight' => 1));
        drupal_add_js(
            "jQuery(function() { setMapcode(); });",
            array('type' => 'inline', 'scope' => 'footer')
        );
    }

	// Determines order to print field/value;
	// fields not in array are printed at the bottom.
	$hideFields = array(
        'vernaculars',
    	'recordURI',
    	'unitGUID',
    	'assemblageID',
    	'notes',
    	'fromCaptivity',
    	'acquiredFrom',
    	'otherSpecimensInAssemblage',
    	'associatedTaxa'
	);
	$fieldOrder = array(
        'names',
        'unitID',
        'source',
        'assemblageID',
        'license',
        'sourceInstitutionID',
	    'collectionType',
        'recordBasis',
        'typeStatus',
        'phaseOrStage',
        'sex',
        'kindOfUnit',
        'preparationType',
        'numberOfSpecimen',
        'gatheringEvent',
        'collectorsFieldNumber'
		// etc
	);
	// Reorder input array
	$data = array_merge(array_flip($fieldOrder), $data);

	$output  = _wrap( t("Specimen")   , "div", "category");
	$output .= _wrap( $data['unitID'] , "h2"  );

	if (!empty($data['unitGUID'])) {
    	$purl = '<input id="purl" type="text" value="' . $data['unitGUID'] . '"></input>';
    	$helpText = t('Please cite the object described here by using this PURL (Persistent Uniform Resource Locator). Naturalis will try to assure the permanent character of this PURL.');
    	$output .= '<div class="property-list">
    	   <dl><dt style="cursor: help; width: 100%;" title="' . $helpText . '">'.
    	   t("Cite as") . ':</dt><dd></dd></dl><p>' . $purl . '</p>
    	   </div>';
	}

	$output .= _wrap( t("Details")    , "h3"  );
	$output .= _wrap( $data['source'] , "h4", "source");

	$output .= "<div class='property-list'>";

	foreach ($data as $field => $value) {
	    if (in_array($field, $hideFields)) {
	        continue;
	    }
		if (is_array($value)) {
			// Taxon name
			if ($field == 'names') {
				$output .= printNamesWithLinks($value, 'Scientific name');
			}
			if ($field == 'vernaculars') {
				$output .= printDL(t('Common name(s)'), implode(', ', $data['vernaculars']));
			}

			// Gathering event
			if ($field == 'gatheringEvent') {
                $output .= printDL(ucfirst(translateNdaField('dateTimeBegin')),
                    printValue(isset($value['dateTimeBegin']) ? $value['dateTimeBegin'] : ''));
			    $output .= printDL(ucfirst(translateNdaField('gatheringAgents')),
			        printValue(isset($value['gatheringAgents']) ? implode(', ', $value['gatheringAgents']) : ''));
			    $output .= printDL(ucfirst(translateNdaField('localityText')),
                    printValue(isset($value['localityText']) ? $value['localityText'] : ''));

			    $coordinates = isset($value['siteCoordinates']) && !empty($value['siteCoordinates']) ?
                    decimalToDMS($value['siteCoordinates']['lat'], $value['siteCoordinates']['lon']) .
                        ' (= ' . $value['siteCoordinates']['lat'] . ', ' .
                        $value['siteCoordinates']['lon'] . ')' :
                        '';

                $output .= printDL(ucfirst(translateNdaField('siteCoordinates')), printValue($coordinates));
                if (!empty($coordinates)) {
                    $output .= '<dl><dt>Mapcode(s)</dt><dd id="mapcode"></dd></dl>';
                }
			}

		} else {
		    $output .= printDL(
                ucfirst(translateNdaField($field)),
		        is_array($value) ? implode(', ', $value) : printValue($value)
		    );
		}
	}
	// Other specimens in collection/set are printed in different table
	if (isset($data['otherSpecimens']) && !empty($data['otherSpecimens'])) {
		$output .= "</div>" .
			"<div class='property-list'>";
		$output .= printNamesWithLinks($data['otherSpecimens'], 'other');
	}
	$output .= "</div>";

	$output .= ($lat && $lon ? "\n<div id='map-canvas' style='margin-bottom: 30px;'></div>" : '');

    $getMultimediaRequest = ndaBaseUrl() . multimediaService() .
        '/?associatedSpecimenReference=' . urlencode(unsetUnitId($data['unitID'])) . '&_andOr=AND';

    drupal_add_js(drupal_get_path('module', 'ndabioresults') . "/js/ajax.js", array('weight' => 1));
    drupal_add_js("var getMultimediaRequest = '$getMultimediaRequest' ", 'inline');
    drupal_add_js(
        "jQuery(function() { getNbaData(getMultimediaRequest, setMultimediaPreview, '&_maxResults=5'); });",
        array('type' => 'inline', 'scope' => 'footer')
    );
    $output .= '<h3>' . t('Multimedia') . '</h3><p id="nba_multimedia"></p>';

    setTitle(t('Specimen') . ' | ' .
        strip_tags($data['names'][0]['name']) . ' | '  . $data['unitID']);

	return $output;
}



/**
 * Prints specimen rows in result table
 *
 * Returns collection/set of specimens or just a specimen if a collection contains a single entry;
 * also provides the Show [x] specimens link if appropriate.
 *
 * @param array $row Parsed json data
 * @param int $i Offset
 * @return string Formatted output
 */
function printSpecimenCollection ($row, $i) {
    $output = '';
	// Single specimen
    if (isset($row['specimens'])) {
        foreach ($row['specimens'] as $specimen) {
            $info = implode('; ', array_filter(array(
                ucfirst($specimen['kindOfUnit']),
                $specimen['preparationType']
            )));
            $output .= "<tr class='indent-1' id='taxon-$i-specimen-0' data-parent='taxon-$i'><td><a href='" .
		    printDrupalLink($specimen['url']) . "'>" . $specimen['unitID'] . "</a></td>" .
            "<td colspan='2'>$info</td><td colspan='2'>" . $specimen['collectionType'] . "</td></tr>";
        }

    // Specimen collection/set
    } else if (isset($row['sets'])) {
        foreach ($row['sets'] as $set => $specimens) {
        	$output .= "<tr class='indent-1' id='taxon-$i-collection' data-parent='taxon-$i'><td>" .
        	   $set . "</td>" . padTds(4) . "</tr>";
        	foreach ($specimens as $j => $specimen) {
        	    $output .= "<tr class='indent-2' id='taxon-$i-specimen-$j' data-parent='taxon-$i-collection'>"
                . "<td><a href='" . printDrupalLink($specimen['url']) . "'>"  . $specimen['unitID'] . "</a></td>" .
                "<td colspan='4'>" . $specimen['recordBasis'] . "</td></tr>";
        	}
        }
    }
    if (!empty($row['allLink'])) {
        $output .= "<tr class='indent-1' id='taxon-$i-specimen-0' data-parent='taxon-$i'><td>" .
        	'<a href="' . printDrupalLink($row['allLink'] . '&_maxResults=100&single') . '">' . t('All') . ' ' .
        	$row['count'] . ' ' . t('specimens') . '...</a></td>' . padTds(4) . "</tr>";
    }
	return $output;
}



/**
 * Prints Show all... link
 *
 * @param array $row Parsed json data
 * @return string Formatted output
 */
function printShowAll ($data) {
    $output = '';
    if (!isset($data['showAll']) || empty($data['showAll'])) {
        return $output;
    }
    $output = '<div class="show-all"><a href="?nba_request=' . $data['showAll'] . '">' .
        '<i class="icon-arrow-right"></i>'.
        t('Show all') . ' ' . _formatNumber($data['total']) . ' '. t('results') . '</a></div>';
    return $output;
}


function printPreviousNext () {
    // Skip navigation if request is empty
    if (!isset($_GET['nba_request'])) {
        return false;
    }
    $searchId = getSearchId($_GET['nba_request']);
    // Skip navigation if searchId is missing or SESSION does not exist
    if (!$searchId || !isset($_SESSION['ndaNavigation'][$searchId])) {
        return false;
    }

    $request = stripNbaBaseUrl($_GET['nba_request']);
    $set = $_SESSION['ndaNavigation'][$searchId]['currentSet'];
    $offset = $_SESSION['ndaNavigation'][$searchId]['offset'];
    $key = array_search(stripNbaBaseUrl($_GET['nba_request']),
        $_SESSION['ndaNavigation'][$searchId]['currentSet']);

    $previousUrl = false;
    // Scroll through set
    if (isset($set[$key - 1])) {
        $previousUrl = urldecode($set[$key - 1]);
    // First item of set reached; check if there's a previousSet.
    } else if (!empty($_SESSION['ndaNavigation'][$searchId]['previousSet'])) {
        $previousSearchId = updatePreviousNext($_SESSION['ndaNavigation'][$searchId]['previousSet']);
        $previousUrl = end($_SESSION['ndaNavigation'][$previousSearchId]['currentSet']);
    }

    $nextUrl = false;
    // Scroll through set
    if (isset($set[$key + 1])) {
        $nextUrl = urldecode($set[$key + 1]);
    // Last item of set reached; check if there's a nextSet.
    } else if (!empty($_SESSION['ndaNavigation'][$searchId]['nextSet'])) {
        $nextSearchId = updatePreviousNext($_SESSION['ndaNavigation'][$searchId]['nextSet']);
        $nextUrl = reset($_SESSION['ndaNavigation'][$nextSearchId]['currentSet']);
    }

    $output = '<div class="fornext-bar"><ul>';

    // Count
    $output .= '<li>' . sprintf(
        t('%d of %d'),
        $offset + $key + 1,
        $_SESSION['ndaNavigation'][$searchId]['total']
    ) . '</li>';

    // Previous
    $output .= "<li>";

    if ($previousUrl) {
        $output .= '<a href="' . printDrupalLink($previousUrl) . '">';
    }
    $output .= '<span class="icon button-icon icon-chevron-up';
    if (!$previousUrl) {
        $output .= ' icon-button-disabled';
    }
    $output .= '"></span>';
    if ($previousUrl) {
        $output .= '</a>';
    }
    $output .="</li>";

    // Next
    $output .= "<li>";
    if ($nextUrl) {
        $output .= '<a href="' . printDrupalLink($nextUrl) . '">';
    }

    $output .= '<span class="icon button-icon icon-chevron-down';

    if (!$nextUrl) {
        $output .= ' icon-button-disabled';
    }

    $output .= '"></span>';


    if ($nextUrl) {
        $output .= '</a>';
    }

    $output .= '</li>';

    // Back
    $output .= '<li><a href="?back"><span class="icon button-icon icon-cross"></span></a></li>';
    $output .= '</ul></div>';

    return $output;
}


/**
 * Prints paginator
 *
 * Data is already formatted in parsed array. This function merely
 * places the output in the proper div.
 *
 * @param array $row Parsed json data
 * @return string Formatted output
 */
function printPaginator ($data) {
    return _wrap($data['paginator'], "div", "paginator-wrapper small-12 columns");
}


/**
 * Prints navigation on details page
 *
 * Currently not in use!
 *
 * @param array $row Parsed json data
 * @return string|void Formatted output
 */
function printNavigation ($data) {
	$output = "<div class='navigation'>";
	if (isset($data['navigation']) && !empty($data['navigation'])) {
		$links = array_merge(array_flip(array('prev', 'next')), $data['navigation']);
		foreach ($links as $direction => $url) {
			$t = "<div class='$direction";
			$t .= !empty($url) ?
				"'><a href='" . printDrupalLink($url) . "'>" . $direction . "</a></div>" :
				"-disabled'></div>";
			$output .= $t;
		}
	}
	return $output . "</div>";
}


/**
 * Prints taxon identifications for specimen (used only for non-name search)
 *
 * Replaces default <span> with <span class="result-query">
 *
 * @param array $row Parsed json data
 * @return string|void Formatted output
 */
function printNamesWithLinks ($details, $fieldLabel) {
	$output = '';
	foreach ($details as $i => $detail) {
		$name = isset($detail['unitID']) ? $detail['unitID'] : $detail['name'];
		$name = !empty($name) ? $name : '&mdash;';
		$t = !empty($detail['url']) ?
			'<a href="' . printDrupalLink($detail['url']) . '">' . $name . '</a>' : $name;
		$output .= printDL(($i == 0 ? t($fieldLabel) : ''), $t);
	}
	return !empty($output) ? $output : null;
}



/**
 * Prints multimedia
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printMultimedia ($data) {

    if (empty($data['results'])) {
        return false;
    }

//p($data);

    // Drupal title empty; page title custom
    $headTitle = !isset($_SESSION['ndaSearch']['theme']) || empty($_SESSION['ndaSearch']['theme']) ?
        t('Search results') : t('Explore highlights');
    $pageTitle = isset($_GET['theme']) ? '' : $pageTitle;
    $searchId = isset($data['searchTerms']) ? setSearchId($data['searchTerms']) : false;

    setTitle($headTitle, $pageTitle);

    $output = '<div id="' . multimediaService() . '"></div>';
    $output .= sprintf(
        '<h2>%s <span class="count">(%s)</span></h2>',
        t('Multimedia'),
        _formatNumber($data['total'])
    );
    $output .= "<div class='multimedia-wrapper'>";

    foreach ($data['results'] as $i => $row) {
    	$w = "240";
        $h = 100 + $i * 50;

        // Reset imgUrl if media is mp4
        if ($row['format'] == 'video/mp4') {
            $row['imgSrc'] = setBasePath() .
                'profiles/naturalis/themes/custom/naturalis_theme/images/naturalis/play.png';
        }

        $mmHit = printMultimediaHit($row);

        // Append searchId as a search term after each url; used for navigation
        $row['url'] .= urlencode('&searchID=' . $searchId);

        $output .=
          "<a class='polaroid' href='" . printDrupalLink($row['url']). "' title='" . $row['title'] . "'>" .
          "  <div class='polaroid-image' style='background-image: url(" . $row['imgSrc']. ");' alt='" . $row['title'] . "'></div>" .
          "  <div class='polaroid-caption'>".
          "    <div class='image-title'>" . (!empty($row['taxon']) ? $row['taxon'] : '&mdash;') .
                    (!empty($row['unitID']) ? '<br>' . $row['unitID'] : '') . "</div>";
         $output .= !empty($row['caption']) ?
           "    <div class='image-hits'>" . $row['caption'] . "</div>" : '';
         $output .= $mmHit ?
           "    <div class='image-hits'>" . $mmHit ."</div>" : '';
         $output .= "  </div>" .
          "</a>";
    }

    $output .=  "</div>";
    $output = _markUp($output);

    $output .= printShowAll($data);
    $output .= printPaginator($data);

  return $output;
}

/**
 * Only prints first hit
 *
 * @param array $row Parsed json
 * @return string|void
 */
function printMultimediaHit ($row) {
	if (isset($row['hits']) && !empty($row['hits'])) {
		foreach ($row['hits'] as $field => $hit) {
		    // Skip hits that are part of the scientific name
		    if (in_array($field,
                array(
                    'genusOrMonomial',
                    'specificEpithet',
                    'infraspecificEpithet',
                    'subgenus',
                    'associatedSpecimenReference',
                    'associatedTaxonReference'
                ))) {
                continue;
		    }
            // Rename field if it doesn't match ABCD term
            $replace = array(
                'name' => t('Common name')
            );
            if (isset($replace[$field])) {
                $field = $replace[$field];
            }
			return ucfirst(translateNdaField($field)) . ': ' .
				str_replace('<span class="search_hit">', '<span class="result-query">', $hit);
		}
	}
	return false;
}


/**
 * Practically identical to printHits()
 *
 * @param array $row Parsed json data
 * @return string Formatted output
 */
function printMatches ($data) {
	$output = '';
	if (isset($data['searchTerms']) && !empty($data['searchTerms'])) {
		foreach ($data['searchTerms'] as $field => $value) {
		    if (!in_array(str_replace('_', '', $field), searchFlags())) {
			    $output .= translateNdaField($field) . ' <span class="result-query">' .
			    $value[0] . '</span>, ';
		    }
		}
	}
	return substr($output, 0, -2);
}



/**
 * Prints hits (matched results) as field: hits
 *
 * Replaces default <span> with <span class="result-query">
 *
 * @param array $row Parsed json data
 * @return string|void Formatted output
 */
function printHits ($row) {
	$output = '';
	if (isset($row['hits']) && !empty($row['hits'])) {
		foreach ($row['hits'] as $field => $hit) {
			$output .= ucfirst(translateNdaField($field)) . ': ' .
				str_replace('<span class="search_hit">', '<span class="result-query">', $hit) . '</br>';
		}
	}
	return !empty($output) ? substr($output, 0, -5) : null;
}



/**
 * Prints headers of result table
 *
 * @param array $headers Parsed json data
 * @param array $self Self link
 * @return string Formatted output
 */
function printHeaders ($headers, $self) {
	$output = "<tr>";

    $i = 0;
    foreach ($headers as $field => $header) {
        $class = "";

        if ( $i == 0)                    { $class="column-first"; }
        if ( $header['label'] == "Match"){ $class="column-match"; }

        $i++;
        $output .= "<th class='$class'>";

        if (isset($header['sort']) && $_SESSION['ndaRequestType'] != 'form') {
			// Selected header
			if ($field == getSort($self)) {
			    $sortDir = getSortDirection($self) == 'DESC' ? 'ASC' : 'DESC';
			     $sortDir = getSortDirection($self);
			    $output .= '<a href="' . printDrupalLink($header['url']) . '">' . $header['label'] . "</a>\n" .
			       '<a href="' . printDrupalLink($header['url']) . '"><span class="' . $header['icon'][$sortDir] .
			       '"></span></a>';
			    // Other headers
			} else {
			    $output .= '<a href="' . printDrupalLink($header['url']) . '">' . $header['label'] . "</a>\n" .
			        '<a href="' . printDrupalLink($header['url']) . '"><span class="icon-sort_sortable"></span></a>';
		    }
		} else {
			$output .= $header['label'];
		}
		$output .= "</th>";
	}
	return $output . "</tr>";
}


/**
 * Prints description(s)
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printDescriptions ($data) {
	global $language;
	$output = '';
	$header = "<h3>" . t('Descriptions') . "</h3>";
	if (isset($data['descriptions']) && !empty($data['descriptions'])) {
		// Transpose first
		foreach ($data['descriptions'] as $lan => $description) {
			$source = key($description);
			$descriptions[$source][$description[$source]] = $lan;
		}
//p($descriptions); p($language);
		foreach ($descriptions as $source => $t) {
			foreach ($t as $description => $lan) {
				if ($lan == $language->name) {
					$output .= "<h4 class='source'>" . printSource($data, $source) .
					   "</h4>\n<p>$description</p>";
				}
			}
		}
	}

	return _wrap(
		$header . (!empty($output) ? $output :
		      "<p class='property-list'>" . t('No descriptions available') . '</p>'),
		"section",
		"result-detail-section"
	);
}



/**
 * Prints common names
 *
 * Transposes common names array and prints common names
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */

function printCommonNames ($data) {
//p($data);
	$output = "";

	$header = "<h3>" . t('Common names') . "</h3>";

	if (isset($data['commonNames']) && !empty($data['commonNames'])) {
	    foreach ($data['commonNames'] as $source => $d) {
			$output .= "<h4 class='source'>" . printSource($data, $source) . "</h4>\n
			     <div class='property-list'>\n";
	        foreach ($d as $lan => $t) {
			    $i = 0;
			    foreach ($t as $name) {
	               $output .= printDL($i == 0 ? t($lan) : '', $name);
			    }
			    $i++;
			}
			$output .= "</div>";
			$oldSource = $source;
		}
	}

	return _wrap(
        $header . (!empty($output) ? $output :
		    "<p class='property-list'>" . t('No common names available') . '</p>'),
		"section",
		"result-detail-section"
	);
}



/**
 * Prints classification(s)
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printClassifications ($data) {
	global $language;
	$output = '';
	$header = "<h3>" . t('Classifications') . "</h3>";
	$printClassifications = array();
	// First merge two separate classification arrays
	foreach ($data['classifications']['default'] as $source => $classification) {
		$classifications[] = array(
			'source' =>  printSource($data, $source),
			'classification' => $classification
		);
	}

	$stored = array();
	foreach ($classifications as $classification) {
	    $serialized = serialize($classification['classification']);
		// Classification does not exist yet; add it
		if (!in_array($serialized, $stored)) {
			$printClassifications[] = array($classification['source'] => $serialized);
			$stored[] = $serialized;
		// Classification does exist; adapt its key
		} else {
		    foreach ($printClassifications as $i => $pC) {
		        foreach ($pC as $s => $c) {
		            if ($serialized == $c) {
                        $printClassifications[$i][$s . ', ' . $classification['source']] = $c;
                        unset($printClassifications[$i][$s]);
                    }
		        }
		    }
		}
	}

	// Finally we can print the lot...
	foreach ($printClassifications as $pC) {
    	foreach ($pC as $source => $sClassification) {
    	    $output .= "<h4 class='source'>$source</h4>" .
    			"<div class='property-list'>";
    		$classification = unserialize($sClassification);
    		foreach ($classification as $rank => $name) {
    			if (!empty($name)) {
    			    if (in_array($rank, array(
        			    'genusOrMonomial',
        			    'genus',
        			    'subgenus',
        			    'specificEpithet',
        			    'infraspecificEpithet'
     			    ))) {
                        $name = '<span class="scientific">' . $name . '</span>';
    			    }
    			    $output .= "<dl><dt>" . ucfirst(translateNdaField($rank)) . "</dt><dd>$name</dd></dl>";
    			}
    		}
    		$output .= "</div>";
    	}
	}


	return _wrap(
    $header . (!empty($output) ? $output :
        "<p class='property-list'>" . t('No classifications available') . '</p>'),
    "section",
    "result-detail-section"
  );
}

/** Prints no result message
 *
 * @return string Translated string with url back to form
 */
function printNoResults () {
    return t('Sorry, no results found') . '. <a href="' . setStartUrl() . '?searchagain=1">' .
        t('Please try again'). '</a>!';
}

/**
 * Shorthand function to pad "filler" tds
 *
 * @param int $i How many tds should be padded?
 * @return string|void
 */
function padTds ($i) {
	if ((int)$i > 0) {
		return "<td colspan='$i'></td>";
	}
	return null;
}


/**
 * Prints description list
 *
 * @param string $field
 * @param string $value
 * @return string
 */
function printDL ($field, $value) {
  return "<dl><dt>$field</dt><dd>$value</dd></dl>";
}

/**
 * Prints table row
 *
 * @param string $field
 * @param string $value
 * @return string
 */
function printTableRow ($field, $value) {
	return "<tr><td>" . ($field != '' ? t(translateNdaField($field)) : '') . "</td><td>" .
		($value != '' ? $value : '') . "</td></tr>";
}



/**
 *
 * Prints value, modifying a few if they meet criteria
 *
 * @param string $license
 * @return string
 */
function printValue ($value) {
    if (strtolower($value) == 'cc0') {
        return '<a href="http://creativecommons.org/about/cc0" target="_blank">' .
            $value . '</a>';
    }
    return $value != '' ? $value : '—';
}

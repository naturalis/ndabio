<?php

/**
 * Prints _sortOptions() for specified service
 * 
 * @param string $service
 * @return string
 */
function _printSortOptions ($service) {
    drupal_add_js(
        "(function($) {
	      $('#sort-options').on('change', function() {
	          var url = $(this).val();
	          if (url) { 
	              window.location = url; 
	          }
	          return false;
	      });
		})(jQuery);",
        ['type' => 'inline', 'scope' => 'footer']
    );
	$output = "<form><select class='form-select' id='sort-options'>\n";
	foreach (_sortOptions()[$service] as $label => $d) {
		$url = _setSortUrl($d['path']);
		$selected = $d == _getCurrentSort() ? ' selected' : '';
		$output .= "<option value='$url'$selected>" . t('Sort by') . " $label</option>\n";
	}
	return  $output . "</select>\n</form>\n";
}

/**
 * Prints taxon detail
 *
 * @param array $data
 * @return string
 */
function _printTaxonDetail ($data) {
    global $language;
    
    $output = _printDebug();
    $output .= "<div class='category'>".t('Taxon')."</div>";
    $output .= "<h2><span class='scientific-name'>";
    $output .= $data['acceptedName'];
    $output .= "</span>";
    if (isset($data['commonNames'][$language->language])){
        $output .= "  <span class='vernacular-name'>";
        $output .=      implode(', ', $data['commonNames'][$language->language]);
        $output .= "  </span>";
    }
    $output .= "</h2>";
    $output .= _printPreviousNext([
    	'total' => $data['totalSize'], 
    	'offset' => $data['offset'], 
    	'previousUrl' => $data['previousUrl'], 
    	'nextUrl' => $data['nextUrl'],
    	'backUrl' => $data['backUrl'],
    ]);

    $output .=
        _printCommonNames($data) .
        _printSynonyms($data) .
        _printDescriptions($data) .
        _printClassifications($data);

	if (!empty($data['specimens'])) {
    	$output .= '<h3>' . t('Specimens') . '</h3><div class="property-list">' .
    		_printSpecimensPreview($data['specimens']) . "</div>\n";
	}
	if (!empty($data['multimedia'])) {
    	$output .= '<h3>' . t('Multimedia') . '</h3><div>' .
    		_printMultimediaPreview($data['multimedia']) . "</div>\n";
	}
    
    // Drupal title empty; page title custom
    _setTitle(t('Taxon') . ' | '. strip_tags($data['acceptedName']));

    return $output;
}

/**
 * Prints taxon results
 * 
 * @param array $data
 * @return boolean|string
 */
function _printTaxa ($data) {
//p($data);

	$service = 'names.taxa';
	
    if (empty($data['results'])) {
        return false;
    }

    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    _setTitle($headTitle, $headTitle);

    $headers = array(
    	'acceptedName.fullScientificName' => [
    		'label' => t('Name'),
     	],
    	'description' => [
    		'label' => t('Description')
    	],
    	'foundIn' => [
    		'label' => t('Found in')
    	],
    );

    $output = '<div id="taxon"></div>';
    
    $formattedTotal = _formatNumber($data['total']);
    if ($data['total'] >= _nbaMaxNumPerScientificNameGroup()[_normaliseServiceName($service)]) {
    	$formattedTotal = '&gt;' . $formattedTotal;
    }
    $explanation = _wrap(t("(matching scientific or common name)"),"span","explanation");
    $output .= sprintf(
        '<h2>%s <span class="count">(%s)</span> %s</h2>',
        t('Species names'), $formattedTotal, $explanation
    );
    
    if (!isset($_GET['form_id'])) {
		$output .= _printMaxResultWarning($data);
    	$output .= "<div class='view-options'>\n" . 
			"<div class='sort-options'>" . _printSortOptions($service) . "</div>\n</div>\n";
    }
    
    $output .= sprintf('<table><thead>%s</thead><tbody>', _printHeaders($headers));

    foreach ($data['results'] as $i => $row) {
    	$output .= "<tr>";

        // Name
        $output .= "<td>";
        $output .= "<a href='" . $row['url'] . "'>" . $row['name'] . "</a>";
        $output .= (!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '');
        $output .=	"</td>";

        // Description
        $output .= "<td>" . $row['description'] . "</td>";

        // Source(s)
        $output .= "<td>" . implode('</br>', $row['sources']) . "</td>";
        $output .= "</tr>\n";
    }

    $output .= "</tbody></table>\n";

    $output .= _printShowAll($data);
    $output .= _printMediaLink($data);
    $output .= _printPaginator($data);

    return $output;
}

/**
 * Print specimen results
 * 
 * @param array $data
 * @return boolean|string
 */
function _printSpecimens ($data) {

	$service = 'specimen';
    if (empty($data['results'])) {
        return false;
    }
    // Drupal title empty; page title custom
    $headTitle = !isset($_SESSION['nbaSearch']['theme']) || empty($_SESSION['nbaSearch']['theme']) ?
        t('Search results') : t('Explore highlights');
    //$pageTitle = isset($_GET['theme']) ? '' : $pageTitle;
    _setTitle($headTitle, '');

    $headers = [
		'unitID' => [
			'label' => t('Specimen'),
		],
		'identifications.scientificName.fullScientificName' => [
			'label' => t('Species'),
		],
		'foundIn' => [
			'label' => t('Found in')
		],
	];
    
    $output = '<div id="specimens"></div>';
    $output .= sprintf(
        '<h2 style="margin-bottom: 0;">%s <span class="count">(%s)</span></h2>',
        t('Specimens'),
        _formatNumber($data['total'])
    );
    
    if (!isset($_GET['form_id']) && !isset($_GET['theme'])) {
		$output .= "<div class='view-options'>\n<div class='specimen-service-select'>" .
			'<a href="' . _resetUrl() . '&service=taxon">' . t('Display by scientific name') . "</a></div>\n";
		$output .= _printMaxResultWarning($data);
		$output .="<div class='sort-options'>" . _printSortOptions('specimen') . "</div>\n</div>\n";
    }
    
    $output .= sprintf('<table style="margin-top: 20px;"><thead>%s</thead><tbody>', _printHeaders($headers));

  	foreach ($data['results'] as $i => $row) {
		$output .= "<tr>";
		// Registration number plus hits
		$output .= "<td><a href='" . $row['url'] . "'>" . _setUnitId($row['unitID']) . "</a>" .
			(!empty($row['hits']) || !empty($row['nameResolutionHits']) ? '<br/>' . _printHits($row) : '') .
			"</td>";
		// Species
		$output .= "<td>" . $row['names'] . "</td>";
		// Source(s)
		$output .= "<td>" . $row['source'] . "</td></tr>\n";
	}

	$output .= "</tbody></table>\n";

    $output .= _printShowAll($data);
    $output .= _printMediaLink($data);
    $output .= _printPaginator($data);

    return $output;
}

/**
 * Print specimen details
 * 
 * @param array $data
 * @return string
 */
function _printSpecimenDetail ($data) {
    drupal_add_js(
        "jQuery(function() { jQuery('#purl').focus().click(function(){ jQuery(this).select(); } ); });",
        array('type' => 'inline', 'scope' => 'footer')
    );

// Do we have a valid set of coordinates? If so, add Google Map 
    $lat = isset($data['gatheringEvent']['siteCoordinates']['lat']) ?
        $data['gatheringEvent']['siteCoordinates']['lat'] : false;
    $lon = isset($data['gatheringEvent']['siteCoordinates']['lon']) ?
        $data['gatheringEvent']['siteCoordinates']['lon'] : false;

    if ($lat && $lon) {
        // Add Google Maps scripts from ndabio module (REQUIRED!)
        //global $base_root, $base_path;
        $path = drupal_get_path('module', 'ndabio');
        drupal_add_css($path . "/css/ndabio_style.css");
        drupal_add_js($path . "/js/map.js", ['weight' => 1]);
        drupal_add_js("https://maps.googleapis.com/maps/api/js?key=" .
            variable_get('ndabio_config_gmapkey', NDABIO_GMAPKEY) . "&libraries=drawing");
        
        /*
        drupal_add_js(
            "jQuery(function() { google.maps.event.addDomListener(window, 'load', initializeSpecimenDetail); });",
            ['type' => 'inline', 'scope' => 'footer']
        );
        */
        drupal_add_js(
            "jQuery(function() { google.maps.event.addDomListener(window, 'load', function() {
  				initializeSpecimenDetail(" . (!is_null($data['geoJson']) ? $data['geoJson'] : '') . ")
			}); });",
            ['type' => 'inline', 'scope' => 'footer']
        );
        
        // (!is_null($data['geoJson']) ? '"' . $data['geoJson'] . '"' : '')
        
        drupal_add_js("var str_base_path = '" . _setBasePath() . "' ", 'inline');
        drupal_add_js("var specimenMarker = " .
            json_encode(['lat' => $lat, 'lon' => $lon]), 'inline');
        if (!empty(_getStoredMapCenter())) {
            drupal_add_js('var storedMapCenter = "' . _getStoredMapCenter() . '";', 'inline');
        }
        if (!empty(_getStoredZoomLevel())) {
            drupal_add_js("var storedZoomLevel = " . _getStoredZoomLevel() . ';', 'inline');
        }
        // Add mapcode scripts
        $path = drupal_get_path('module', 'ndabioresults');
        drupal_add_js($path . "/js/mapcode/ctrynams.js", ['weight' => 1]);
        drupal_add_js($path . "/js/mapcode/mapcode.js", ['weight' => 1]);
        drupal_add_js($path . "/js/mapcode/ndata.js", ['weight' => 1]);
        drupal_add_js($path . "/js/library.js", ['weight' => 1]);
        drupal_add_js(
            "jQuery(function() { setMapcode(); });",
            ['type' => 'inline', 'scope' => 'footer']
        );
    }

	// Determines order to print field/value;
	// fields not in array are printed at the bottom.
	$hideFields = [
        //'vernaculars',
    	'recordURI',
    	'unitGUID',
    	'assemblageID',
    	'notes',
    	'fromCaptivity',
    	'acquiredFrom',
    	'otherSpecimens',
    	'associatedTaxa',
		'id',
		'totalSize',
		'offset',
		'previousUrl', 
    	'nextUrl',
		'backUrl',
		'multimedia',
		'scientificNameGroup',
		'referrer',
		'geoJson',
		'titleNames'
	];
	$fieldOrder = [
        'names',
        'vernaculars',
		'enrichedVernaculars',
		'unitID',
        'source',
        'assemblageID',
        'license',
        'sourceInstitutionID',
	    'collectionType',
        'recordBasis',
        'typeStatuses',
        'phaseOrStage',
        'sex',
        'kindOfUnit',
        'preparationType',
        'numberOfSpecimen',
        'gatheringEvent',
        'collectorsFieldNumber'
		// etc
	];
	// Reorder input array
	$data = _sortArrayByArray($data, $fieldOrder);
	
//p($data);

	$output = _printDebug();
	$output .= _wrap( t("Specimen"), "div", "category");
	$output .= _wrap(_setUnitId($data['unitID']) , "h2"  );
    $output .= _printPreviousNext([
    	'total' => $data['totalSize'], 
    	'offset' => $data['offset'], 
    	'previousUrl' => $data['previousUrl'], 
    	'nextUrl' => $data['nextUrl'],
    	'backUrl' => $data['backUrl'],
    ]);
	
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

	$output .= "<div class='property-list'>\n";

	foreach ($data as $field => $value) {
	    if (in_array($field, $hideFields)) {
	        continue;
	    }
		if (is_array($value)) {
			// Taxon name
			if ($field == 'names') {
				$output .= _printNamesWithLinks($value, 'Scientific name');
			}
			if ($field == 'vernaculars') {
				$output .= _printDL(t('Common name(s)'), implode(', ', $data['vernaculars']));
			}
			if ($field == 'enrichedVernaculars') {
				$vernaculars = '';
				if (!empty($data['enrichedVernaculars'])) {
					foreach ($data['enrichedVernaculars'] as $name => $lan) {
						$vernaculars .= $name . (!empty($lan) ? ' ('. t($lan) . ')' : '') . ', ';
					}
					$vernaculars = substr($vernaculars, 0, -2);
				}
				$output .= _printDL(t('Vernaculars from associated taxon'), _printValue($vernaculars));
			}
			
			if ($field == 'typeStatuses') {
				$output .= _printTypeStatuses($value, 'Type status');
			}
			
			// Gathering event
			if ($field == 'gatheringEvent') {
				$dateTime = _printValue(isset($value['dateTimeBegin']) ? $value['dateTimeBegin'] : '');
				if (isset($value['dateTimeBegin']) && isset($value['dateTimeEnd']) && 
					$value['dateTimeBegin'] != $value['dateTimeEnd']) {
					$dateTime .= ' ' . t('to') . ' ' . $value['dateTimeEnd'];
				}
                $output .= _printDL(ucfirst(_translateNdaField('Date')), $dateTime);
                
			    $output .= _printDL(ucfirst(_translateNdaField('gatheringAgents')),
			        _printValue(isset($value['gatheringAgents']) ? implode(', ', $value['gatheringAgents']) : ''));
			    
			    // BIOPORVTWO-273
			    if (isset($value['localityText']) && !empty($value['localityText']) && 
			    	isset($value['locality']) && !empty($value['locality']) && 
			    	strpos($value['localityText'], $value['locality']) === false) {
			    	$value['localityText'] = $value['locality'] . '; ' . $value['localityText'];
			    }
			    if ((!isset($value['localityText']) || empty($value['localityText'])) && 
			    	(isset($value['locality']) && !empty($value['locality']))) {
			    	$value['localityText'] = $value['locality'];
			    }
			   
			    $output .= _printDL(ucfirst(_translateNdaField('localityText')),
                    _printValue(isset($value['localityText']) ? $value['localityText'] : ''));

			    $coordinates = isset($value['siteCoordinates']) && !empty($value['siteCoordinates']) ?
                    _decimalToDMS($value['siteCoordinates']['lat'], $value['siteCoordinates']['lon']) .
                        ' (= ' . $value['siteCoordinates']['lat'] . ', ' .
                        $value['siteCoordinates']['lon'] . ')' :
                        '';

                $output .= _printDL(ucfirst(_translateNdaField('siteCoordinates')), _printValue($coordinates));
                if (!empty($coordinates)) {
                    $output .= '<dl><dt>Mapcode(s)</dt><dd id="mapcode"></dd></dl>';
                }
			}

		} else {
		    $output .= _printDL(
                ucfirst(_translateNdaField($field)),
		        is_array($value) ? implode(', ', $value) : _printValue($value)
		    );
		}
	}
	// Other specimens in collection/set are printed in different table
	if (isset($data['otherSpecimens']) && !empty($data['otherSpecimens'])) {
 		$output .= "</div>\n<h3>" . t('Other specimens in assemblage') . "</h3>\n<div class='property-list'>\n";
 		foreach ($data['otherSpecimens'] as $i => $specimen) {
			$output .= '<dl><dt><a href="' . $specimen['url'] . '">' . _setUnitId($specimen['unitID']) . '</a></dt>';
			$output .= '<dd>' . $specimen['collectionType'] . "</dd></dl>\n";
		}
	}
	$output .= "</div>\n";
	
	$feedback = "<p style='margin-bottom: 30px;'>" . t('Please report inaccuracies or errors for this specimen to %s.') . "</p>";
	$mailLink = '<a href="%s">collectie@naturalis.nl</a>';
	$mailSubject = 'subject=' . rawurlencode(t('Feedback on specimen') . ' ' . $data['unitID'] . ' (' . $data['collectionType'] . ')');
	$mailBody = 'body=' . rawurlencode(
		t('Registration number') . ': ' . $data['unitID'] . "\n" . 
		t('Scientific name') . ': ' . strip_tags($data['names'][0]['name']) . "\n" . 
		t('Collection name') . ': ' . $data['collectionType'] . "\n" .
		'Url: ' . _getCurrentUrl() . "\n\n" .
		t('Your feedback') . ":\n\n\n"
	);
	$mail = sprintf($mailLink, "mailto:collectie@naturalis.nl?$mailSubject&$mailBody");
	$output .= "<h3>Feedback</h3>\n" . sprintf($feedback, $mail);
	
	$output .= ($lat && $lon ? 
		"<h3>" . t('Map') . "</h3>\n<div id='map-canvas' style='margin-bottom: 3em;'></div>" : '');

	if (!empty($data['multimedia'])) {
    	$output .= '<h3>' . t('Multimedia') . '</h3><p id="nba_multimedia">' .
    		_printMultimediaPreview($data['multimedia']) . "</p>\n";
	}
	
	$title = t('Specimen') . ' | ' . strip_tags($data['names'][0]['name']);
	if (!empty($data['titleNames'])) {
		$title .= ' (' . $data['titleNames'] . ')';
	}
    _setTitle($title . ' | ' . $data['unitID']);

	return $output;
}

/**
 * Print row of five media thumbnails on taxon detail page
 * 
 * @param array $data
 * @return NULL|string
 */
function _printMultimediaPreview ($data) {
	if (isset($data['items']) && !empty($data['items'])) {
		$output = "<div style='overflow: hidden;'>\n";
		foreach ($data['items'] as $i => $media) {
			$src = $media['src'];
			if ($media['format'] == 'video/mp4') {
				$src = _setBasePath() . 'profiles/naturalis/themes/custom/naturalis_theme/images/naturalis/play.png';
			}
			$output .= '<a class="polaroid" href="' . $media['url'] . '">' .
				'<div class="polaroid-image" style="background-image: url(' . $src . ');" alt=""></div>';
			$output .= '<div class="polaroid-caption"><div class="image-title">' .
				$media['caption'] . '</div><div class="image-hits">' . $media['hits'] . "</div>\n</div>\n</a>\n";
		};
		$output .= "\n</div>\n";
	}
	if (!empty($data['showAllLink'])) {
		$output .= '<div><a href="' . $data['showAllLink'] . '">' .
			'<i class="icon-arrow-right"></i>' . t('Show all') . ' ' . $data['totalSize'] . ' ' .
			t('multimedia') . '</a></div>';
	}
	return isset($output) ? $output : null;
}

/**
 * Print list of five specimens on taxon detail page
 * 
 * @param array $data
 * @return NULL|string
 */
function _printSpecimensPreview ($data) {
	if (isset($data->items) && !empty($data->items)) {
		$output = '';
		foreach ($data->items as $i => $specimen) {
			$output .= '<dl><dt><a href="' . $specimen['url'] . '">' . $specimen['unitID'] . '</a></dt>';
			$output .= '<dd>' . $specimen['collectionType'] . '</dd></dl>';
		}
		if ($data->totalSize > 5) {
			$output .= '<div style="margin-top: 12px;"><a href="' . $data->showAllLink . '">' .
				'<i class="icon-arrow-right"></i>' . t('Show all') . ' ' . $data->totalSize . ' ' .
				t('specimens') . '</a></div>';
		}
	}
	return isset($output) ? $output : null;
}

/**
 * Prints names with links plus label
 * 
 * @param array $details
 * @param string $fieldLabel
 * @param string $referrer
 * @return NULL|string
 */
function _printNamesWithLinks ($details, $fieldLabel, $referrer = false) {
	$output = '';
	foreach ($details as $i => $detail) {
		$name = isset($detail['unitID']) ? $detail['unitID'] : $detail['name'];
		$name = !empty($name) ? $name : '&mdash;';
		$t = !empty($detail['url']) ?
			'<a href="' . $detail['url'] . ($referrer ? "?referrer=$referrer" : '') . 
			'">' . $name . '</a>' : $name;
		$output .= _printDL(($i == 0 ? t($fieldLabel) : ''), $t);
	}
	return !empty($output) ? $output : null;
}

/**
 * Prints type statuses for specimen plus label
 * 
 * @param array $details
 * @param string $fieldLabel
 * @return string
 */
function _printTypeStatuses ($details, $fieldLabel) {
	if (count($details) <= 1) {
		return _printDL(t($fieldLabel), 
			_printValue(isset($details[0]['typeStatus']) ? $details[0]['typeStatus'] : null));
	}
	$value = '';
	foreach ($details as $detail) {
		$values[] = $detail['typeStatus'] . ' (' . $detail['name'] . ')';
	}
	return _printDL(t($fieldLabel), implode(', ', $values));
}

/**
 * Prints specimen details
 * 
 * @param array $data
 * @return string
 */
function _printSpecimenMediaDetail ($data) {
//p($data);

	$output = _printDebug();
    $output .= _wrap(t("Media item"), "div", "category");
    $output .= _wrap('', "h2");
    $output .= _printPreviousNext([
    	'total' => $data['totalSize'], 
    	'offset' => $data['offset'], 
    	'previousUrl' => $data['previousUrl'], 
    	'nextUrl' => $data['nextUrl'],
    	'backUrl' => $data['backUrl'],
    ]);

    $altParts = array(
        isset($data['unitID']) ? strip_tags($data['unitID']) : '',
        isset($data['names'][0]['name']) ? strip_tags($data['names'][0]['name']) : ''
    );
    $alt = htmlspecialchars(implode(' | ', array_filter($altParts)));
		
	// Get headers, so we don't have to download image
	$headers = @get_headers($data['imgSrc']);
	if (!$headers || !strpos($headers[0], '200')) {
		$data['imgSrc'] = _setBasePath() . 'profiles/naturalis/themes/custom/naturalis_theme/images/naturalis/image-not-found.jpg';
	}
    
    list($width, $height) = _loadPrettyPhoto($data['imgSrc']);
    $img = "<img src=\"" . $data['imgSrc'] . "\" alt=\"$alt\" title=\"$alt\" " .
        "style='width: {$width}px; height: {$height}px;'/>";
    if ($width > 0) {
        $copyright = !empty($data['copyrightText']) ?
            $copyright = '© ' . $data['copyrightText'] : '';
        array_unshift($altParts, $copyright);
        $caption = implode('<br/>', array_filter($altParts));
        $img = "<a href='" . $data['imgSrc'] . "' rel=\"prettyPhoto\" title=\"$caption\">$img</a>\n";
    }

    if (_isMp4($data['imgSrc'])) {
        $output .= '<video src="' . $data['imgSrc'] . '" type="video/mp4" autoplay controls></video>';
    } else {
	   $output .= $img;

        if (strpos($data['imgSrc'], 'medialib') !== false) {
       	   $output .= 
	    	'<div class="property-list" style="margin-bottom: 1em;">' . 
			 _printDL('<a href="' . str_replace('large', 'master', $data['imgSrc']) . '">
				<i class="icon-arrow-right"></i>' . t('Download master image') . '</a>') . 
    		'</div>';
        }
    }
    
	$output .= "<div class='property-list'>";

	if (!empty($data['unitID'])) {
		$output .= _printDL(
            ucfirst(_translateNdaField('unitID')),
            '<a href="' . _setBasePath() . 'specimen/' . urlencode($data['unitID']) . 
				(isset($data['referrer']) ? '?referrer=' . $data['referrer'] : '') . '">' . 
				_setUnitId($data['unitID']) . '</a>'
		);
	}
	if (!empty($data['names'])) {
		$output .= _printNamesWithLinks($data['names'], t('Scientific name'), $data['referrer']);
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
  		if (isset($data[$field])) {
			$output .= _printDL(
	            ucfirst(_translateNdaField($field)),
			    is_array($data[$field]) ? implode(', ', $data[$field]) : _printValue($data[$field])
			);
  		}
	}

    // Drupal title empty; page title custom
    _setTitle(t('Multimedia') . ' | ' . strip_tags($data['names'][0]['name']) . ' | '  . $data['unitID']);
	
    return $output . "</dd>\n</div>\n";
}

/**
 * Prints taxon media result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function _printTaxonMediaDetail ($data) {
//p($data);

	$output = _printDebug();
    $output .= _wrap( t("Media item")   , "div", "category");
    $output .= _wrap( '', "h2"  );
    $output .= _printPreviousNext([
    	'total' => $data['totalSize'], 
    	'offset' => $data['offset'], 
    	'previousUrl' => $data['previousUrl'], 
    	'nextUrl' => $data['nextUrl'],
    	'backUrl' => $data['backUrl'],
    ]);
    
    $altParts = array(
        isset($data['acceptedName']) ? strip_tags($data['acceptedName']) : '',
        isset($data['caption']) ? strip_tags($data['caption']) : ''
    );
    $alt = htmlspecialchars(implode(' | ', array_filter($altParts)));

    list($width, $height) = _loadPrettyPhoto($data['imgSrc']);
    $img = "<img src='" . $data['imgSrc'] . "' alt=\"$alt\" title=\"$alt\" " .
        "style='width: {$width}px; height: {$height}px;'/>";
    if ($width > 0) {
        $copyright = !empty($data['copyrightText']) ?
            $copyright = '© ' . $data['copyrightText'] : '';
        array_unshift($altParts, $data['sourceInstitutionID'], $copyright);
        $caption = implode('<br/>', array_filter($altParts));
        $img = "<a href='" . $data['imgSrc'] . "' rel=\"prettyPhoto\" title=\"$caption\">$img</a>\n";
    }
    
    $scientificName = !empty($data['acceptedNameUrl']) ?
    	'<a href="' . $data['acceptedNameUrl'] . '">' . $data['acceptedName'] . '</a>' :
    	$data['acceptedName'];

    $output .= $img;
    $output .= "<div class='property-list' style='margin-top: 1em;'>";
    $output .= _printDL(t('Scientific name'), $scientificName);
    
	$fields = [
	    'source',
    	'creator',
	    'license',
        'copyrightText',
		'sourceInstitutionID',
        //'collectionType',
	    'description',
    	'locality',
    	'date',
	    'phaseOrStage',
        'sexes'
	];
	foreach ($fields as $field) {		//if (isset($data[$field])) {
		if ($field == 'source' && !empty($data['sourceUrls'])) {
            $data['source'] = _printSource($data, $data['source']);
	    }
	    $output .= _printDL(ucfirst(_translateNdaField($field)), 
	    	_printValue(isset($data[$field]) ? $data[$field] : ''));
	}
	
    // Drupal title empty; page title custom
	_setTitle(t('Multimedia') . ' | ' . strip_tags($data['acceptedName']));

    return $output . "</div>";
}

/**
 * Prints previous/next block on detail pages
 * 
 * @param array $p Parameters (urls)
 * @return NULL|string
 */
function _printPreviousNext ($p) {
	$previousUrl = isset($p['previousUrl']) ? $p['previousUrl'] : false;
	$nextUrl = isset($p['nextUrl']) ? $p['nextUrl'] : false;
	$backUrl = isset($p['backUrl']) ? $p['backUrl'] : false;

	if (!$backUrl) {
		return null;
	}
	
    $output = '<div class="fornext-bar"><ul>' .
		'<li>' . sprintf(t('%s of %s'), _formatNumber($p['offset']), _formatNumber($p['total'])) . '</li>';

    // Previous
    $output .= "<li>";
    if (!empty($previousUrl)) {
        $output .= '<a href="' . $previousUrl . '">';
    }
    $output .= '<span class="icon button-icon icon-chevron-up';
    if (empty($previousUrl)) {
        $output .= ' icon-button-disabled';
    }
    $output .= '"></span>';
    if (!empty($previousUrl)) {
        $output .= '</a>';
    }
    $output .= "</li>\n";

    // Next
    $output .= "<li>";
    if (!empty($nextUrl)) {
        $output .= '<a href="' . $nextUrl . '">';
    }
    $output .= '<span class="icon button-icon icon-chevron-down';
    if (empty($nextUrl)) {
        $output .= ' icon-button-disabled';
    }
    $output .= '"></span>';
    if (!empty($nextUrl)) {
        $output .= '</a>';
    }
    $output .= "</li>\n";
    
    // Back
    $output .= "<li>";
    if (!empty($backUrl)) {
        $output .= '<a href="' . $backUrl . '">';
    }
    $output .= '<span class="icon button-icon icon-cross';
    if (empty($backUrl)) {
        $output .= ' icon-button-disabled';
    }
    $output .= '"></span>';
    if (!empty($backUrl)) {
        $output .= '</a>';
    }
    $output .= "</li>\n</ul></div>\n";

    return $output;
}

/**
 * Prints multimedia results
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function _printMultimedia ($data) {
	
	if (empty($data['results'])) {
		return false;
	}
	
//p($data);
	
	$service = 'multimedia';
	
	$output = '<div id="multimedia"></div>';
	$output .= sprintf(
		'<h2>%s <span class="count">(%s)</span></h2>',
		t('Multimedia'),
		_formatNumber($data['total'])
	);
	
	if (!isset($_GET['form_id']) && !isset($_GET['theme'])) {
		$output .= _printMaxResultWarning($data);
	}
	
	$output .= "<div class='multimedia-wrapper'>";
	
	$fallbackSrc = _setBasePath() . 'profiles/naturalis/themes/custom/naturalis_theme/images/naturalis/image-not-found.jpg';
	
	foreach ($data['results'] as $i => $row) {
		$w = "240";
		$h = 100 + $i * 50;
		
		// Reset imgUrl if media is mp4
		if ($row['format'] == 'video/mp4') {
			$row['imgSrc'] = _setBasePath() . 'profiles/naturalis/themes/custom/naturalis_theme/images/naturalis/play.png';
		}
/*		
		// Get headers, so we don't have to download image
		$headers = @get_headers($row['imgSrc']);		
		if (!$headers || !strpos($headers[0], '200')) {
			$row['imgSrc'] = _setBasePath() . 'profiles/naturalis/themes/custom/naturalis_theme/images/naturalis/image-not-found.jpg';
		}
*/				
		$mmHit = _printMultimediaHit($row);
		
		$output .= "<a class='polaroid' href='" . $row['url'] . "' title='" . $row['title'] . "'>" .
		//"  <div class='polaroid-image' style='background-image: url(" . $row['imgSrc']. "), url(". $fallbackSrc . ");' alt='" . $row['title'] . "'></div>\n" .
		"  <div class='polaroid-image' style='background-image: url(" . $row['imgSrc']. ");' alt='" . $row['title'] . "'></div>\n" .
		"  <div class='polaroid-caption'>" .
		"    <div class='image-title'>" . (!empty($row['taxon']) ? $row['taxon'] : '&mdash;') .
		(!empty($row['unitID']) ? '<br>' . $row['unitID'] : '') . "</div>\n";
		$output .= !empty($row['caption']) ?
		"    <div class='image-hits'>" . $row['caption'] . "</div>\n" : '';
		$output .= $mmHit ?
		"    <div class='image-hits'>" . $mmHit ."</div>" : '';
		$output .= "  </div>\n" . "</a>";
	}
	
	$output .=  "</div>\n";
	
	$output .= _printShowAll($data);
	$output .= _printPaginator($data);
	
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
function _printSpecimenCollection ($data, $i) {
	$output = '';
//p($data);	
	foreach ($data['specimens'] as $j => $row) {
		// Specimen collection/set
		if (isset($row['set'])) {
				foreach ($row['set'] as $set => $specimens) {
				$output .= "<tr class='indent-1' id='taxon-$i-collection' data-parent='taxon-$i'><td>" .
					$set . "</td>" . _padTds(4) . "</tr>";
				foreach ($specimens as $k => $specimen) {
					$output .= "<tr class='indent-2' id='taxon-$i-specimen-$k' data-parent='taxon-$i-collection'>" . 
						"<td><a href='" . $specimen['url'] . "'>"  . $specimen['unitID'] . "</a></td>" .
						"<td colspan='2'>" . $specimen['recordBasis'] . "</td>" .
						"<td colspan='2'>" . $specimen['collectionType'] . "</td></tr>\n"; 
					if (!empty(_printHits($specimen))) {
						$output .= "<tr class='indent-2' id='taxon-$i-specimen-$k' data-parent='taxon-$i-collection'>\n" .
							"<td colspan='4'>" . _printHits($specimen) . "</td>\n</tr>\n";
					}
				}
			}
		// Single specimen
		} else {
			$info = implode('; ', array_filter([
				ucfirst($row['kindOfUnit']),
				$row['preparationType']
			]));
			$output .= "<tr class='indent-1' id='taxon-$i-specimen-0' data-parent='taxon-$i'>\n" .
				"<td><a href='" . $row['url'] . "'>" . $row['unitID'] . "</a></td>\n" .
				"<td colspan='2'>$info</td><td colspan='2'>" . $row['collectionType'] . "</td>\n" .
				"</tr>\n";
			if (!empty(_printHits($row))) {
				$output .= "<tr class='indent-1' id='taxon-$i-specimen-0' data-parent='taxon-$i'>\n" .
					"<td colspan='4'>" . _printHits($row) . "</td>\n</tr>\n";
			}
		}
	}
	
	if (!empty($data['allLink'])) {
		$output .= "<tr class='indent-1' id='taxon-$i-specimen-0' data-parent='taxon-$i'><td>" .
		'<a href="' . $data['allLink'] . '">' . t('All') . ' ' .
		_formatNumber($data['count']) . ' ' . t('specimens') . '...</a></td>' . _padTds(4) . "</tr>\n";
	}
	return $output;
}

/** Prints no result message
 *
 * @return string Translated string with url back to form
 */
function _printNoResults ($timeOuts = []) {
	if (empty($timeOuts)) {
	    return '<p style="padding-top: 12px;">' . t('Sorry, no results found') . '. <a href="' . _setStartUrl() . '?searchagain=1">' .
	        t('Please modify your search') . '</a>.</p>';
	}
	if (count($timeOuts) == 1) {
		return '<p>' . t('Sorry, the') . ' ' . _normaliseServiceName(key($timeOuts)) . ' ' .  
			t('query timed out after') . ' ' . reset($timeOuts) . 
			'. <a href="' . _setStartUrl() . '?searchagain=1">' . t('Please modify your search') . '</a>.</p>';
	}
	return '<p>' . t('Sorry, multiple queries timed out. There may be a problem with the server.') . '</p>';
}

/**
 * Prints hits (matched results) as field: hits
 *
 * Replaces default <span> with <span class="result-query">
 *
 * @param array $row Parsed json data
 * @return string|void Formatted output
 */
function _printHits ($row) {
	$output = '';
	if (isset($row['hits']) && !empty($row['hits'])) {
		foreach ($row['hits'] as $field => $hit) {
			if (_doNotPrintHit($field, $row['hits'])) {
				continue;
			}
			$output .= ucfirst(_translateNdaField($field)) . ': ' . $hit . '; ';
		}
	} else if (isset($row['nameResolutionHits']) && !empty($row['nameResolutionHits'])) {
		foreach ($row['nameResolutionHits'] as $hit) {
			$type = isset($hit['synonym']) ? 'synonym' : 'vernacular';
			$value = $hit[$type];
			$taxon = $hit['taxon'];
			$output .= $value . ', ' . t($type) . ' ' . t('of') . ' ' . $taxon . '; ';
		}
	}
	return !empty($output) ? substr($output, 0, -2) : null;
}

/**
 * Skip these hits please!
 * 
 * @param string $hit
 * @param array $hits
 * @return boolean
 */
function _doNotPrintHit ($hit, $hits) {
	if (array_key_exists($hit, _doNotPrintHits()) && is_null(_doNotPrintHits()[$hit])) {
		return true;
	}
	if (array_key_exists($hit, _doNotPrintHits()) && 
		array_key_exists(_doNotPrintHits()[$hit], $hits)) {
		return true;
	}
	return false;
}


/**
 * Prints geographic results on map
 * 
 * @param array $data
 * @return string
 */
function _printSpecimensMap ($data) {
    // Add Google Maps scripts from ndabio module (REQUIRED!)
    //global $base_root, $base_path;

//p($data);

     // Drupal title empty; page title custom
    $headTitle = t('Search results');
    _setTitle($headTitle, $headTitle);

    $path = drupal_get_path('module', 'ndabio');
    drupal_add_css($path . "/css/ndabio_style.css");
    drupal_add_js($path . "/js/map.js", ['weight' => 1]);
    drupal_add_js($path . "/js/oms.min.js", ['weight' => 1]);
    drupal_add_js("https://maps.googleapis.com/maps/api/js?key=" .
        variable_get('ndabio_config_gmapkey', NDABIO_GMAPKEY) . "&libraries=drawing");
    drupal_add_js(
        "jQuery(function() { google.maps.event.addDomListener(window, 'load', initializeSpecimens); });",
        ['type' => 'inline', 'scope' => 'footer']
    );
    drupal_add_js("var str_base_path = '" . _setBasePath() . "';", 'inline');
    drupal_add_js("var specimenMarkers = " . json_encode($data['results']) .';', 'inline');
	drupal_add_js("var geoShape = " . $data['geoJson'] .';', 'inline');

    
    if (!empty(_getStoredMapCenter())) {
        drupal_add_js('var storedMapCenter = "' . _getStoredMapCenter() . '";', 'inline');
    }
    if (!empty(_getStoredZoomLevel())) {
        drupal_add_js("var storedZoomLevel = " . _getStoredZoomLevel() . ';', 'inline');
    }

    $output = sprintf('<h2>%s %s %s %s</h2>',
        t('Specimens of '),
        $data['results'][0]['name'],
        ' in ',
        (!empty(_getStoredLocation()) ? _getStoredLocation() : t('area drawn on map'))
    );
    if (!empty($data['message'])) {
    	 $output .= '<p>' . $data['message'] . '</p>';
    }
    $output .= '<div id="map-canvas"></div>';

    return _printDebug() . $output;
}

/**
 * Prints synonyms for taxon
 * 
 * @param array $data
 * @return string
 */
function _printSynonyms ($data) {
//p($data);
	$output = "";
	$header = "<h3>" . t('Synonyms') . "</h3>";

	if (isset($data['synonyms']) && !empty($data['synonyms'])) {
	    foreach ($data['synonyms'] as $source => $synonyms) {
			$output .= "<h4 class='source'>" . _printSource($data, $source) . "</h4>
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
 * Group all specimens under one taxon
 * 
 * @param array $data
 * @return boolean|unknown
 */
function _printSpecimensSingleTaxon ($data) {
//p($data);
	if (empty($data['results'])) {
		return false;
	}
	// Drupal title empty; page title custom
	$headTitle = t('Search results');
	$nameSortFlag = 'identifications.scientificName.fullScientificName';
	_setTitle($headTitle, $headTitle);
	
	$headers = [
		'identifications.scientificName.fullScientificName' => [
			'label' => t('Name'),
		],
		'count' => [
			'label' => ''
		],
		'mapIcon' => [
			'label' => ''
		],
		'foundIn' => [
			'label' => t('Found in')
		],
	];
	
	$output = '<div id="specimen"></div>';
	$output .= sprintf(
		'<h2>%s %s %s</h2>',
		ucfirst(t('specimens of ')),
		str_replace('class="result-query"', '', $data['results'][0]['fullScientificName']),
		_wrap('(' . _formatNumber($data['specimensTotal']) . ')', "span", "count")
	);
	$output .= sprintf(
		'<table id="specimensBySingleTaxon"><thead>%s</thead>', _printHeaders($headers)
	);
	
	foreach ($data['results'] as $i => $result) {
		foreach ($result['specimens'] as $row) {
			// Specimen collection/set
			if (isset($row['set'])) {
				foreach ($row['set'] as $set => $specimens) {
					$output .= "<tr><td>" . $set . "</td>" . _padTds(4) . "</tr>";
					foreach ($specimens as $specimen) {
						$output .= "<tr class='indent'>" . 
							"<td style='padding-left: 3em;'><a href='" . $specimen['url'] . "'>"  . 
							$specimen['unitID'] . "</a></td>" .
							"<td colspan='2'>" . $specimen['recordBasis'] . "</td>" .
							"<td colspan='2'>" . $specimen['collectionType'] . "</td></tr>\n"; 
						if (!empty(_printHits($specimen))) {
							$output .= "<tr class='indent'>\n" .
								"<td style='padding-left: 3em;' colspan='4'>" . 
								_printHits($specimen) . "</td>\n</tr>\n";
						}
					}
				}
			// Single specimen
			} else {
				$info = implode('; ', array_filter([
					ucfirst($row['kindOfUnit']),
					$row['preparationType']
				]));
				$output .= "<tr>\n" .
					"<td><a href='" . $row['url'] . "'>" . $row['unitID'] . "</a></td>\n" .
					"<td colspan='2'>$info</td><td colspan='2'>" . $row['collectionType'] . "</td>\n" .
					"</tr>\n";
				if (!empty(_printHits($row))) {
					$output .= "<tr>\n" .
						"<td colspan='4'>" . _printHits($row) . "</td>\n</tr>\n";
				}
			}
		}
	}
	
	$output .= "</table>";
	$output .= _printPaginator($data);
	
	return $output;
}

/**
 * Prints Show all... link
 *
 * @param array $row Parsed json data
 * @return string Formatted output
 */
function _printShowAll ($data) {
    if (!isset($data['showAll']) || empty($data['showAll'])) {
        return null;
    }
    $output = '<div class="show-all"><a href="' . $data['showAll'] . '">' .
        '<i class="icon-arrow-right"></i>'.
        t('Show all') . ' ' . _formatNumber($data['total']) . ' '. 
    	t('results') . '</a></div>';
    return $output;
}

/**
 * Prints link to Show all media for this query
 * 
 * @param array $data
 * @return NULL|string
 */
function _printMediaLink ($data) {
    if (!isset($data['mediaLink']) || empty($data['mediaLink'])) {
        return null;
    }
    $output = '<div class="show-all"><a href="' . $data['mediaLink']['url'] . '">' .
        '<i class="icon-arrow-right"></i>'.
        t('Show all') . ' ' . _formatNumber($data['mediaLink']['total']) . ' '. 
    	t('media items for this query') . '</a></div>';
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
function _printPaginator ($data) {
	if (isset($data['paginator'])) {
    	return _wrap($data['paginator'], "div", "paginator-wrapper small-12 columns");
	}
	return null;
}

/**
 * Only prints first hit
 *
 * @param array $row Parsed json
 * @return string|void
 */
function _printMultimediaHit ($row) {
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
                    'associatedTaxonReference',
                	'theme'
                ))) {
                continue;
		    }
		    if (_doNotPrintHit($field, $row['hits'])) {
				continue;
			}
            // Rename field if it doesn't match ABCD term
            $replace = ['name' => t('Common name')];
            
            if (isset($replace[$field])) {
                $field = $replace[$field];
            }
			$hits[] = ucfirst(_translateNdaField($field)) . ': ' . $hit;
		}
	} else if (isset($row['nameResolutionHits']) && !empty($row['nameResolutionHits'])) {
		foreach ($row['nameResolutionHits'] as $hit) {
			$type = isset($hit['synonym']) ? 'synonym' : 'vernacular';
			$value = $hit[$type];
			$taxon = $hit['taxon'];
			$hits[] = $value . ', ' . t($type) . ' ' . t('of') . ' ' . $taxon;
		}
	}
	return isset($hits) ? implode('<br>', $hits) : false;
}

/**
 * Prints headers of result table
 *
 * @param array $headers Parsed json data
 * @param array $self Self link
 * @return string Formatted output
 */
function _printHeaders ($headers) {
	$output = "<tr>";

    $i = 0;
    foreach ($headers as $field => $header) {
        $class = "";

        if ( $i == 0)                    { $class="column-first"; }
        if ( $header['label'] == "Match"){ $class="column-match"; }

        $i++;
        $output .= "<th class='$class'>" . $header['label'] . "</th>";
	}
	return $output . "</tr>";
}

/**
 * Prints single source as formatted html
 *
 * @param array $data
 * @param string $source
 * @return string Formatted html
 */
function _printSource ($data, $source) {
    if (isset($data['sourceUrls'][$source])) {
        return '<a href="' . $data['sourceUrls'][$source] . '" target="_blank">' . $source . '</a>';
    }
    return $source;
}

/**
 * Prints description(s)
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function _printDescriptions ($data) {
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
					$output .= "<h4 class='source'>" . _printSource($data, $source) .
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
function _printCommonNames ($data) {
//p($data);
	$output = "";

	$header = "<h3>" . t('Common names') . "</h3>";

	if (isset($data['commonNames']) && !empty($data['commonNames'])) {
	    foreach ($data['commonNames'] as $source => $d) {
			$output .= "<h4 class='source'>" . _printSource($data, $source) . "</h4>\n
			     <div class='property-list'>\n";
	        foreach ($d as $lan => $t) {
			    $i = 0;
			    foreach ($t as $name) {
	               $output .= _printDL($i == 0 ? t($lan) : '', $name);
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
function _printClassifications ($data) {
	global $language;
	$output = '';
	$header = "<h3>" . t('Classifications') . "</h3>";
	$printClassifications = array();
	// First merge two separate classification arrays
	foreach ($data['classifications']['default'] as $source => $classification) {
		$classifications[] = array(
			'source' =>  _printSource($data, $source),
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
    			    $output .= "<dl><dt>" . ucfirst(_translateNdaField($rank)) . "</dt><dd>$name</dd></dl>";
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

/**
 * Print specimens per taxon
 * 
 * @param array $data
 * @return boolean|string
 */
function _printSpecimensTaxon ($data) {
	global $language;
	
	$service = 'names.specimens';
	
//p($data);
	if (empty($data['results'])) {
		return false;
	}
	
 	// Drupal title empty; page title custom
	$headTitle = t('Search results');
	$nameSortFlag = 'identifications.scientificName.fullScientificName';
	_setTitle($headTitle, $headTitle);
	
	$headers = [
		'identifications.scientificName.fullScientificName' => [
			'label' => t('Name'),
		],
		'count' => [
			'label' => ''
		],
		'mapIcon' => [
			'label' => ''
		],
		'foundIn' => [
			'label' => t('Found in')
		],
	];
	
	$output = '<div id="specimen"></div>';
	
    $formattedTotal = _formatNumber($data['total']);
    if ($data['total'] >= _nbaMaxNumPerScientificNameGroup()[_normaliseServiceName($service)]) {
    	$formattedTotal = '&gt;' . $formattedTotal;
    }	
	$output .= sprintf(
		'<h2 style="margin-bottom: 0;">%s %s %s %s</h2>',
		($language->language == 'nl' ? 'Soorten' : 'Species'),
		_wrap('(' .$formattedTotal . ')', "span", "count"),
		t('with specimens'),
		_wrap('(' . _formatNumber($data['specimensTotal']) . ')', "span", "count")
	);
	
	if (!isset($_GET['form_id'])) {
		$output .= "<div class='view-options'>\n<div class='specimen-service-select'>" .
			'<a href="' . _resetUrl() . '&service=specimen' . '">' . t('Display by specimen') . "</a></div>\n"; 
		$output .= _printMaxResultWarning($data);
		$output .= "<div class='sort-options'>" . _printSortOptions($service) . "</div>\n</div>\n";
	}
	
	$output .= sprintf(
		'<table style="margin-top: 20px;" id="specimensByTaxon"><thead>%s</thead>', 
		_printHeaders($headers)
	);
	
	foreach ($data['results'] as $i => $row) {
		$output .= "<tr class='indent-0' id='taxon-$i'>";
		// Name
		
		$output .= "<td>" . "<a href='#''>" . $row['fullScientificName'] . "</a> " .
			(!empty($row['commonNames']) ? '</br>' . 
			implode(', ', array_keys($row['commonNames'])) : '') . "</td>\n";
		// Number (and collection type)
		$output .= "<td>" . _formatNumber($row['count']) . ' ' . 
			($row['count'] > 1 ? t('specimens') : t('specimen')) . "</td>\n";
		// Set map url in parse	
		$output .= "<td>" . (!empty($row['mapUrl']) ? "<a href='" . $row['mapUrl'] . 
			"' class='icon-location'></a>" : '') . "</td>\n";
		
		// Source(s)
		$output .= "<td>" . implode('</br>', $row['sources']) . "</td>\n";
		// Match
		//$output .= "<td>" . decorateScore($row['score']) . "</td>";
		$output .= "</tr>";
		$output .= _printSpecimenCollection($row, $i);
	}
	
	$output .= "</table>";
	//$output = _markUp($output);
	
	$output .= _printShowAll($data);
	$output .= _printPaginator($data);
	
	return $output;
}

/**
 * Prints 'too many results' warning on result page
 * 
 * @param string $service
 * @param int $total
 * @return string
 */
function _printMaxResultWarning ($data) {
	return isset($data['result_warning']) && !empty($data['result_warning']) ?
		"<p class='result-warning'>" . $data['result_warning'] . "</p>\n" : '';
}

/**
 * Shorthand function to pad "filler" tds
 *
 * @param int $i How many tds should be padded?
 * @return string|void
 */
function _padTds ($i) {
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
function _printDL ($field, $value = '') {
	return "<dl><dt>$field</dt><dd>$value</dd></dl>";
}

/**
 * Prints value, modifying a few if they meet criteria
 *
 * @param string $license
 * @return string
 */
function _printValue ($value = '') {
    if (strtolower($value) == 'cc0') {
        return '<a href="http://creativecommons.org/about/cc0" target="_blank">' .
            $value . '</a>';
    } 
    return $value != '' ? str_replace('  ', '&nbsp;&nbsp;', $value) : '—';
}

/**
 * Prints debug stack
 * 
 * @return string
 */
function _printDebug () {
    if ((user_is_logged_in() || _nbaDebug() == 1) && !empty(_getDebug())) {
	    drupal_add_js(
	        "jQuery(function() { 
				jQuery('#nba-debug-link').click(function(){ 
					jQuery('#nba-debug-query').toggle(200); 
					jQuery(this).text((jQuery(this).text() == 'hide') ? 'show' : 'hide');
				}); 
			});",
	        ['type' => 'inline', 'scope' => 'footer']
	    );
    	$output = '<div id="nba-debug" style="padding: 20px; margin-top: 10px; border: 3px solid red;">
			<span style="font-weight:bold;">NBA query</span>
			[<span id="nba-debug-link" style="color: #009ee0; cursor: pointer;">show</span>] 
			<div id="nba-debug-query" style="margin-top: 10px; font-size: 13px; display: none;">';
        foreach  (_getDebug() as $title => $query) {
        	if (strpos($query, '{') !== false) {
	        	$output .= "<div style='font-weight:bold; margin: 10px 0;'>" . ucfirst($title) . ":</div>
					<pre style='overflow: hidden;'>$query</pre>";
        	} else {
        		$output .= "<div style='margin: 10px 0;'><span style='font-weight:bold;'>" . ucfirst($title) . "</span>: 
					<span style='unicode-bidi: embed; font-family: monospace; white-space: pre;'>$query</span></div>";
        	}
        }
        return $output . '</div></div>';
    }
}

/**
 * Prints a fine oops message
 * 
 * If any errors have been set these are printed as well
 * 
 * @return string
 */
function _printOops () {
	$output = '<h1>' .t('Error'). '!</h1><p>';
	if (_getErrorMessage()) {
		$output .= _getErrorMessage() . "</p>\n<p>";
	}
	$output .= t('Oops, something went wrong') . '. ' .
		"<a href='" . _setStartUrl() . "'>" . t('Back to home page') . '</a>.</p>';
	return $output;
}

function _printAdvancedSearchSuggestion ($data) {
		foreach ($data['modified'] as $label => $value) {
			$replacement[] .= '<strong>' . $data['original'][$label] . '</strong> ' 
				. t('with') . ' ' . '<a href="' . $data['url'] . '" class="result-query">' . $value . '</a>';
		}
		$message = '<p style="padding-top: 12px; width: 700px;">' . 
			t('Your query did not produce any results. ' . 
			'This may be due to the fact that the search engine reverts to a ' .
			'"starts with" instead of a "contains" search when a term is longer than ' .
			'%d characters.') . '<p></p>' . 
			t('Retry your search replacing %s or <a href="%s">modify your search</a>.');
		return sprintf($message, _nbaMaxContainsStringSize(), implode(', ', $replacement), 
			_setStartUrl() . '?searchagain=1');
}



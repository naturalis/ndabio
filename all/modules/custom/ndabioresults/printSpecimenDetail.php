<?php

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
        'collectionType',
        'sourceInstitutionID',
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

//p($data);

	$output  = _wrap( t("Specimen")   , "div", "category");
	$output .= _wrap( $data['unitID'] , "h2"  );

	$purl = '<input id="purl" type="text" ' .
	   'value="http://data.biodiversitydata.nl/naturalis/specimen/' .
	   $data['unitID'] . '"></input>';
	$helpText = t('Please cite the object described here by using this PURL (Persistent Uniform Resource Locator). Naturalis will try to assure the permanent character of this PURL.');
	$output .= '<div class="property-list">
	   <dl><dt style="cursor: help; width: 100%;" title="' . $helpText . '">'.
	   t("Cite as") . ':</dt><dd></dd></dl><p>' . $purl . '</p>
	   </div>';

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
                $output .= isset($value['dateTimeBegin']) ?
    			    printDL(ucfirst(translateNdaField('dateTimeBegin')), $value['dateTimeBegin']) :
                    '';
			    $output .= isset($value['gatheringAgents']) ?
    			    printDL(ucfirst(translateNdaField('gatheringAgents')), implode(', ', $value['gatheringAgents'])) :
			          '';
			    $output .= isset($value['localityText']) ?
    			    printDL(ucfirst(translateNdaField('localityText')), $value['localityText']) :
                    '';

			    if (!empty($value['siteCoordinates'])) {
                    $output .= printDL(ucfirst(translateNdaField('siteCoordinates')),
                        decimalToDMS($value['siteCoordinates']['lat'], $value['siteCoordinates']['lon']) .
                        ' (= ' . $value['siteCoordinates']['lat'] . ', ' .
                        $value['siteCoordinates']['lon'] . ')'
                    );
                    // Mapcodes
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
        '/?associatedSpecimenReference=' . urlencode($data['unitID']) . '&_andOr=AND';

    drupal_add_js(drupal_get_path('module', 'ndabioresults') . "/js/ajax.js", array('weight' => 1));
    drupal_add_js("var getMultimediaRequest = '$getMultimediaRequest' ", 'inline');
    drupal_add_js(
        "jQuery(function() { getNbaData(getMultimediaRequest, setMultimediaPreview, '&_maxResults=5'); });",
        array('type' => 'inline', 'scope' => 'footer')
    );
    $output .= '<h3>' . t('Multimedia') . '</h3><p id="nba_multimedia"></p>';

    setTitle(t('Specimen') . ' | ' .
        strip_tags($data[names][0]['name']) . ' | '  . $data['unitID']);

	return $output;
}
?>

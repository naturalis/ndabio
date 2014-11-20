<?php

// Print specimen detail on screen
function printSpecimenDetail ($data) {
//p($data);
    // Do we have a valid set of coordinates? If so, add Google Map
    $lat = isset($data['gatheringEvent']['siteCoordinates']['lat']) ?
        $data['gatheringEvent']['siteCoordinates']['lat'] : false;
    $lon = isset($data['gatheringEvent']['siteCoordinates']['lon']) ?
        $data['gatheringEvent']['siteCoordinates']['lon'] : false;

    if ($lat && $lon) {
        // Add Google Maps scripts from ndabio module (REQUIRED!)
        global $base_root, $base_path;
        $path = drupal_get_path('module', 'ndabio');
        drupal_add_css($path . "/css/ndabio_style.css");
        drupal_add_js($path . "/js/map.js", array('weight' => 1));
        drupal_add_js("https://maps.googleapis.com/maps/api/js?key=" . variable_get('ndabio_config_gmapkey', NDABIO_GMAPKEY) . "&libraries=drawing");
        drupal_add_js("jQuery(document).ready(function() { google.maps.event.addDomListener(window, 'load', initializeSpecimenDetail); });", 'inline');
        drupal_add_js("var str_base_path = '$base_path' ", 'inline');
        drupal_add_js("var specimenMarker = " . json_encode(array('lat' => $lat, 'lon' => $lon)), 'inline');
    }

	// Determines order to print field/value;
	// fields not in array are printed at the bottom.
	$fieldOrder = array(
	   'unitID',
	   'names',
	   'source',
	   'assemblageID',
	   'otherSpecimens'
		// etc
	);
	// Reorder input array
	$data = array_merge(array_flip($fieldOrder), $data);
	$output  = _wrap( t("Specimen")   , "div", "category");
	$output .= _wrap( $data['unitID'] , "h2"  );
	$output .= _wrap( t("Details")    , "h3"  );
	$output .= _wrap( $data['source'] , "h4", "source");

	$output .= "<div class='property-list'>";

	foreach ($data as $field => $value) {
		if (is_array($value)) {

			// Taxon name
			if ($field == 'names') {
				$output .= printNamesWithLinks($value, 'species');
			}

			// Gathering event
			if ($field == 'gatheringEvent') {
                $output .= printDL(translateNdaField('dateTimeBegin'),
                    isset($value['dateTimeBegin']) ? $value['dateTimeBegin'] : '');
                $output .= printDL(translateNdaField('gatheringAgents'),
                    isset($value['gatheringAgents']) ? implode(', ', $value['gatheringAgents']) : '');
			    $output .= printDL(translateNdaField('localityText'),
			        isset($value['localityText']) ? $value['localityText'] : '');
                $output .= printDL(translateNdaField('siteCoordinates'),
                    isset($value['siteCoordinates']) ?
                    '[print on Google Maps: lat ' . $value['siteCoordinates']['lat'] . ', lon ' .
                    $value['siteCoordinates']['lon'] . ']' : '');
			}
		} else {
			$output .= printDL(translateNdaField($field), $value);
		}
	}
	// Other specimens in collection/set are printed in different table
	if (isset($data['otherSpecimens']) && !empty($data['otherSpecimens'])) {
		$output .= "</div>" .
			"<div class='property-list'>";
		$output .= printNamesWithLinks($data['otherSpecimens'], 'other');
	}
	return $output . "</div>" . ($lat && $lon ? "\n<div id='map-canvas'></div>" : '');
}
?>
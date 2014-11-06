<?php

// Print specimen detail on screen
function printSpecimenDetail ($data) {
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
//p($data);
	$output = "<h3>" . t('Specimen details') . "</h3>" .
		"<h4 class='source'>" . $data['source'] . "</h4>";
	
	// Navigation
	// $output .= printNavigation($data);
	
	$output .= "<div class='table-property-list'>";
	
	foreach ($data as $field => $value) {
		if (is_array($value)) {
			
			// Taxon name
			if ($field == 'names') {
				$output .= printNamesWithLinks($value, 'species');
			}
			
			// Gathering event
			if ($field == 'gatheringEvent') {
                $output .= printDL('dateTimeBegin', isset($value['dateTimeBegin']) ?
                    date('Y-m-d', $value['dateTimeBegin'] / 1000) : '');
                $output .= printDL('gatheringAgents', isset($value['gatheringAgents']) ?
                    implode(', ', $value['gatheringAgents']) : '');
			    $output .= printDL('localityText', isset($value['localityText']) ?
                     $value['localityText'] : '');
                $output .= printDL('siteCoordinates', isset($value['siteCoordinates']) ?
                    '[print on Google Maps: lat ' . $value['siteCoordinates']['lat'] . ', lon ' .
                    $value['siteCoordinates']['lon'] . ']' : '');
			}
		} else {
			$output .= printDL($field, $value);
		}
	}
	// Other specimens in collection/set are printed in different table
	if (isset($data['otherSpecimens']) && !empty($data['otherSpecimens'])) {
		$output .= "</div>" .
			"<div class='table-property-list'>";
		$output .= printNamesWithLinks($data['otherSpecimens'], 'other');
	}
	return $output . "</div>";
}



?>
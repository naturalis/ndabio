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
		"<h5 class='source'>" . $data['source'] . "</h5>";
	// Navigation
	$output .= printNavigation($data);
	$output .= "<table class='table-property-list'><tbody>";
	foreach ($data as $field => $value) {
		if (is_array($value)) {
			// Taxon name
			if ($field == 'names') {
				$output .= printNamesWithLinks($value, 'species');
			}
			// Gathering event
			if ($field == 'gatheringEvent') {
                $output .= printTableRow('dateTimeBegin', isset($value['dateTimeBegin']) ?
                    date('Y-m-d', $value['dateTimeBegin'] / 1000) : '');
                $output .= printTableRow('gatheringAgents', isset($value['gatheringAgents']) ?
                    implode(', ', $value['gatheringAgents']) : '');
			    $output .= printTableRow('localityText', isset($value['localityText']) ?
                     $value['localityText'] : '');
                $output .= printTableRow('siteCoordinates', isset($value['siteCoordinates']) ?
                    '[print on Google Maps: lat ' . $value['siteCoordinates']['lat'] . ', lon ' .
                    $value['siteCoordinates']['lon'] . ']' : '');
			}
		} else {
			$output .= printTableRow($field, $value);
		}
	}
	// Other specimens in collection/set are printed in different table
	if (isset($data['otherSpecimens']) && !empty($data['otherSpecimens'])) {
		$output .= "</tbody></table>" .
			"<table class='table-property-list'><tbody>";
		$output .= printNamesWithLinks($data['otherSpecimens'], 'other');
	}
	return $output . "</tbody></table>";
}


?>
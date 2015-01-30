<?php

// Returns collection/set of specimens or just a specimen if a collection contains a single entry
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



?>
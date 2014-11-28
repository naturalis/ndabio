<?php

function printSpecimenMediaDetail ($data) {
//p($data);
	$output = "<h2>" . $data['title'] . "</h2>\n";
	$output .= printNavigation($data);
	$output .= "<img src='" . $data['imgSrc'] . "' alt='" . $data['title'] .
		"' title=''" . $data['title'] . " />\n";
	$output .= "<div class='property-list'>";

	if (!empty($data['unitID'])) {
		$output .= printDL(
            translateNdaField('unitID'),
            '<a href="' . printDrupalLink(specimenDetailService() . '?unitID=' . $data['unitID']) . '">' . $data['unitID'] . '</a>'
		);
	}
	if (!empty($data['names'])) {
		$output .= printNamesWithLinks($data['names'], 'Species');
	}

	$fields = array(
        'source',
    	'creator',
	    'title',
        'caption',
	    'description',
        'copyrightText',
        'phasesOrStages',
        'sexes'
	);
	foreach ($fields as $field) {
		if ($data[$field] != '') {
			$output .= printDL(translateNdaField($field), $data[$field]);
		}
	}
	return $output . "</dd>";
}



?>
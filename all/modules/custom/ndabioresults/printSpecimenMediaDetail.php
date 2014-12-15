<?php

function printSpecimenMediaDetail ($data) {
//p($data);

    $output  = _wrap( t("Media item")   , "div", "category");
    $output .= _wrap( '', "h2"  );
    	//$output .= printNavigation($data);

    if (isMp4($data['imgSrc'])) {
        $output .= '<video src="' . $data['imgSrc'] . '" type="video/mp4" autoplay controls></video>';
    } else {
	   $output .= "<img src='" . $data['imgSrc'] . "' alt='" . $data['title'] .
	       "' title=''" . $data['title'] . " />\n";
    }

	$output .= "<div class='property-list'>";

	if (!empty($data['unitID'])) {
		$output .= printDL(
            ucfirst(translateNdaField('unitID')),
            '<a href="' . printDrupalLink(specimenDetailService() . '?unitID=' .
                $data['unitID']) . '">' . $data['unitID'] . '</a>'
		);
	}
	if (!empty($data['names'])) {
		$output .= printNamesWithLinks($data['names'], t('Scientific name'));
	}

	$fields = array(
        'source',
    	'creator',
	    'title',
	    'description',
        'copyrightText',
        'phasesOrStages',
        'sexes'
	);
	foreach ($fields as $field) {
		if ($data[$field] != '') {
			$output .= printDL(
                ucfirst(translateNdaField($field)),
			    is_array($data[$field]) ? implode(', ', $data[$field]) : $data[$field]
			);
		}
	}
	return $output . "</dd>";
}



?>
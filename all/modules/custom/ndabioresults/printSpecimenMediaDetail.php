<?php
/**
 * Prints multimedia detail
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimenMediaDetail ($data) {
//p($data);

    $output  = _wrap( t("Media item")   , "div", "category");
    $output .= _wrap( '', "h2"  );
    	//$output .= printNavigation($data);

    $altParts = array(
        isset($data['unitID']) ? strip_tags($data['unitID']) : '',
        isset($data['names'][0]['name']) ? strip_tags($data['names'][0]['name']) : '',
        isset($data['caption']) ? strip_tags($data['caption']) : ''
    );
    $alt = implode(' | ', array_filter($altParts));

    $img = "<img src='" . $data['imgSrc'] . "' alt='$alt' title='$alt' />";
    if (loadPrettyPhoto($data['imgSrc'])) {
        $img = "<a href='" . $data['imgSrc'] . "' rel='prettyPhoto'>$img</a>\n";
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

    // Drupal title empty; page title custom
    setTitle(t('Multimedia') . ' | ' . strip_tags($data[names][0]['name']) . ' | '  . $data['unitID']);

	return $output . "</dd>";
}
?>
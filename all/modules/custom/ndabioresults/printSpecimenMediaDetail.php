<?php

/**
 * Prints multimedia detail
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimenMediaDetail ($data) {
//p($data);
    drupal_add_js("jQuery(document).ready(function() { jQuery('#purl').focus().select(); });", 'inline');

    $output  = _wrap(t("Media item"), "div", "category");
    $output .= _wrap('', "h2");

    $output .= printPreviousNext();

	$purl = '<input id="purl" type="text" value="http://data.biodiversitydata.nl/naturalis/multimedia/' .
	   $data['mediaUnitID'] . '"></input>';
	$output .= '<div class="property-list">
	   <dl><dt style="cursor: help; width: 100%;" title="' . t('Help text here') . '">'.
	   t("Cite as") . ':</dt><dd></dd></dl><p>' . $purl . '</p>
	   </div>';

    $altParts = array(
        isset($data['unitID']) ? strip_tags($data['unitID']) : '',
        isset($data['names'][0]['name']) ? strip_tags($data['names'][0]['name']) : '',
        isset($data['caption']) ? strip_tags($data['caption']) : ''
    );
    $alt = implode(' | ', array_filter($altParts));

    $img = "<img src='" . $data['imgSrc'] . "' alt='$alt' title='$alt' />";
    if (loadPrettyPhoto($data['imgSrc'])) {
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
        'description',
        'copyrightText',
    	'localityText',
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

	return $output . "</dd>";
}
?>
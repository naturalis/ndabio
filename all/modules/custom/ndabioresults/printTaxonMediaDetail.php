<?php

/**
 * Prints taxon media result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printTaxonMediaDetail ($data) {
//p($data);

    $output  = _wrap( t("Media item")   , "div", "category");
    $output .= _wrap( '', "h2"  );

    $output .= printMultimediaPreviousNext();

    $altParts = array(
        isset($data['names'][0]['name']) ? strip_tags($data['names'][0]['name']) : '',
        isset($data['caption']) ? strip_tags($data['caption']) : ''
    );
    $alt = implode(' | ', array_filter($altParts));

    // Temp solution to show fullsize images
    $data['imgSrc'] = str_replace('/comping/', '/original/', $data['imgSrc']);

    $img = "<img src='" . $data['imgSrc'] . "' alt='$alt' title='$alt' />";
    if (loadPrettyPhoto($data['imgSrc'])) {
        $copyright = !empty($data['copyrightText']) ?
            $copyright = '© ' . $data['copyrightText'] : '';
        array_unshift($altParts, $data['sourceInstitutionID'], $copyright);
        $caption = implode('<br/>', array_filter($altParts));
        $img = "<a href='" . $data['imgSrc'] . "' rel='prettyPhoto' title='$caption'>$img</a>\n";
    }

    $output .= $img;

    $output .= "<div class='property-list'>";
    $output .= printNamesWithLinks($data['names'], t('Scientific name'));

	$fields = array(
	    'source',
    	'creator',
	    'license',
        'sourceInstitutionID',
	    'description',
        'copyrightText',
    	'locality',
    	'date',
	    'phaseOrStage',
        'sexes'
	);
	foreach ($fields as $field) {
		if ($field == 'source' && !empty($data['sourceUrls'])) {
            $data['source'] = printSource($data, $data['source']);
	    }
	    $output .= printDL(ucfirst(translateNdaField($field)), printValue($data[$field]));
	}

    // Drupal title empty; page title custom
	setTitle(t('Multimedia') . ' | ' . strip_tags($data['acceptedName']));

    return $output . "</div>";
}



?>

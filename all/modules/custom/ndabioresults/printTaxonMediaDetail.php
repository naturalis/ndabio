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

    $output .="<img src='" . $data['imgSrc'] . "' alt='" . $data['title'] .
    	"' title=''" . $data['title'] . ">";

    $output .= "<div class='property-list'>";
    $output .= printNamesWithLinks($data['names'], t('Scientific name'));

	$fields = array(
	    'source',
    	'creator',
    	'license',
	    'title',
	    'description',
        'copyrightText',
	    'phasesOrStages',
        'sexes',
    	'locality',
    	'date'
	);
	foreach ($fields as $field) {
		if ($data[$field] != '') {
		    if ($field == 'source' && !empty($data['sourceUrls'])) {
                $data['source'] = printSource($data, $data['source']);
		    }
		    $output .= printDL(ucfirst(translateNdaField($field)), $data[$field]);
		}
	}

    // Drupal title empty; page title custom
	setTitle(t('Multimedia') . ' | ' . strip_tags($data['acceptedName']));

    return $output . "</div>";
}



?>
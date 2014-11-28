<?php

function printTaxonMediaDetail ($data) {
//p($data);

  $output  = _wrap( t("Media item")   , "div", "category");
  $output .= _wrap( basename(  $data['imgSrc']  ) , "h2"  );

  $output .="<img src='" . $data['imgSrc'] . "' alt='" . $data['title'] .
		"' title=''" . $data['title'] . ">";

  $output .= "<div class='property-list'>";
  $output .= printNamesWithLinks($data['names'], 'Species');

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

	return $output . "</div>";
}



?>
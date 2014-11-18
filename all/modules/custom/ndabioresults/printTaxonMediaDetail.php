<?php

function printTaxonMediaDetail ($data) {

  $output  = _wrap( t("Media item")   , "div", "category");
  $output .= _wrap( basename(  $data['imgSrc']  ) , "h2"  );

  $output .="<img src='" . $data['imgSrc'] . "' alt='" . $data['title'] .
		"' title=''" . $data['title'] . ">";

  $output .= "<div class='property-list'>";


	$fields = array(
        'acceptedName',
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
			$output .= printDL($field, $data[$field]);
		}
	}

	return $output . "</div>";
}



?>
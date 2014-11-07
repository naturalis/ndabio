<?php

function printTaxonMediaDetail ($data) {

  $output = "<h2>" . $data['title'] . "</h2>";
	$output .= printNavigation($data);
	$output .="<img src='" . $data['imgSrc'] . "' alt='" . $data['title'] .
		"' title=''" . $data['title'] . ">";
	$output .= "<dd class='table-property-list'>";

  foreach (array('acceptedName', 'source', 'title', 'caption') as $field) {
		$output .= printDL($field, $data[$field]);
	}

	return $output . "</dd>";
}



?>
<?php

function printTaxonMediaDetail ($data) {

  $output = "<h2>" . $data['title'] . "</h2>";
	$output .= printNavigation($data);
	$output .="<img src='" . $data['imgSrc'] . "' alt='" . $data['title'] .
		"' title=''" . $data['title'] . ">";
	$output .= "<table class='table-property-list'><tbody>";

  foreach (array('acceptedName', 'source', 'title', 'caption') as $field) {
		$output .= printTableRow($field, $data[$field]);
	}

	return $output . "</tbody></table>";
}



?>
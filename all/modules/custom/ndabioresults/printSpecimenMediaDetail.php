<?php

function printSpecimenMediaDetail ($data) {
	$output = "<h2>" . $data['title'] . "</h2>\n";
	$output .= printNavigation($data);
	$output .="<img scr='" . $data['imgSrc'] . "' alt='" . $data['title'] .
		"' title=''" . $data['title'] . ">\n";
	$output .= "<table class='table-property-list'>\n<tbody>\n";
	$fields = array('source', 'title', 'caption');
	if (isset($data['acceptedName'])) {
		array_unshift($fields, 'acceptedName');
	} else if (isset($data['names'])) {
		$output .= printNamesWithLinks($data['names'], 'species');
	}
	foreach ($fields as $field) {
		if ($data[$field] != '') {
			$output .= printTableRow($field, $data[$field]);
		}
	}
	return $output . "</tbody>\n</table>\n";
}



?>
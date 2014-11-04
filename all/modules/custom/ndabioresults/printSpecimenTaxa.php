<?php

// Prints taxon identifications for specimen (used only for non-name search)
function printSpecimenTaxa ($names) {
	$output = '';
	foreach ($names as $name) {
		$t = $name['name'];
		$t = !empty($name['url']) ?
			'<a href="' . printDrupalLink($name['url']) . '">' . $name['name'] . '</a>, ' :
			$t . ', ';
		$output .= $t;
	}
	return !empty($output) ? substr($output, 0, -2) : '-';
}


?>
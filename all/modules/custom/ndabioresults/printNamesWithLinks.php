<?php

// Prints taxon identifications for specimen (used only for non-name search)
function printNamesWithLinks ($details, $fieldLabel) {
	$output = '';
	foreach ($details as $i => $detail) {
		$name = isset($detail['unitID']) ? $detail['unitID'] : $detail['name'];
		$name = !empty($name) ? $name : '&mdash;';
		$t = !empty($detail['url']) ?
			'<a href="' . printDrupalLink($detail['url']) . '">' . $name . '</a>' : $name;
		$output .= printDL(($i == 0 ? t($fieldLabel) : ''), $t);
	}
	return !empty($output) ? $output : null;
}
?>
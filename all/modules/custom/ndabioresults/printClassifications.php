<?php

function printClassifications ($data) {
	global $language;
	$output = '';
	$header = "<h3>" . t('Classifications') . "</h3>";
	$printClassifications = array();
	// First merge two separate classification arrays
	foreach ($data['classifications']['default'] as $source => $classification) {
		$classifications[] =array(
			'source' => $source,
			'classification' => $classification
		);
	}
	foreach ($data['classifications']['system'] as $source => $classification) {
		$classifications[] = array(
			'source' => $source,
			'classification' => $classification
		);
	}
	// Check for duplicates; change key if necessary
	foreach ($classifications as $classification) {
		// Classification does not exist yet; add it
		if (!in_array(serialize($classification['classification']), $printClassifications)) {
			$printClassifications[$classification['source']] = serialize($classification['classification']);
		// Classification does exist; adapt its key
		} else {
			$printSource = array_search(serialize($classification['classification']), $printClassifications);
			$newSource = $printSource . ', ' . $classification['source'];
			$printClassifications[$newSource] = serialize($classification['classification']);
			unset($printClassifications[$printSource]);
		}
	}
	// Finally we can print the lot...
	foreach ($printClassifications as $source => $sClassification) {
		$output .= "<h4 class='source'>$source</h4>" .
			"<table class='property-list'><tbody>";
		$classification = unserialize($sClassification);
		foreach ($classification as $rank => $name) {
			$output .= "<tr><td>" . t($rank) . "</td><td>$name</td></tr>";
		}
		$output .= "</tbody></table>";
	}
	return $header . (!empty($output) ? $output : t('No classifications available'));
}


?>
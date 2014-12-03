<?php

// Transposes common names array and prints common names
function printCommonNames ($data) {
    p($data);
	$output = "";

	$header = "<h3>" . t('Common names') . "</h3>";

	if (isset($data['commonNames']) && !empty($data['commonNames'])) {
	    foreach ($data['commonNames'] as $source => $d) {
			$output .= "<h4 class='source'>$source</h4>\n<div class='property-list'>\n";
	        foreach ($d as $lan => $t) {
			    $i = 0;
			    foreach ($t as $name) {
	               $output .= printDL($i == 0 ? t($lan) : '', $name);
			    }
			    $i++;
			}
			$output .= "</div>";
			$oldSource = $source;
		}
	}

	return _wrap(
		$header . (!empty($output) ? $output : t('No common names available')),
		"section",
		"result-detail-section"
	);
}


?>
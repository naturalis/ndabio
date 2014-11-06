<?php

// Transposes common names array and prints common names
function printCommonNames ($data) {
	$output = "";
	
	$header = "<h3>" . t('Common names') . "</h3>";
	
	if (isset($data['commonNames']) && !empty($data['commonNames'])) {
		// Transpose first
		foreach ($data['commonNames'] as $lan => $name) {
			$source = key($name);
			$names[$source][$name[$source]] = $lan;
		}
		foreach ($names as $source => $t) {
			$output .= "<h4 class='source'>$source</h4>" .
				"<table class='property-list'><tbody>";
			foreach ($t as $name => $lan) {
				$output .= "<tr><td>" . t($lan) . "</td><td>$name</td></tr>";
			}
			$output .= "</tbody></table>";
		}
	}

	return _wrap(
		$header . (!empty($output) ? $output : t('No common names available')),
		"section",
		"result-detail-section"
	);
}


?>
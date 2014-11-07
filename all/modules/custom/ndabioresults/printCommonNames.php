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
				"<div class='property-list'>";
			foreach ($t as $name => $lan) {
				$output .= printDL( t($lan) , $name);
			}
			$output .= "</div>";
		}
	}

	return _wrap(
		$header . (!empty($output) ? $output : t('No common names available')),
		"section",
		"result-detail-section"
	);
}


?>
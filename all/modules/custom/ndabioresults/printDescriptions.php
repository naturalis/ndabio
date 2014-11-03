<?php

function printDescriptions ($data) {
	global $language;
	$output = '';
	$header = "<h3>" . t('Descriptions') . "</h3>";
	if (isset($data['descriptions']) && !empty($data['descriptions'])) {
		// Transpose first
		foreach ($data['descriptions'] as $lan => $description) {
			$source = key($description);
			$descriptions[$source][$description[$source]] = $lan;
		}
		foreach ($descriptions as $source => $t) {
			foreach ($t as $description => $lan) {
				if ($lan == $language->language) {
					$output .= "<p>$description</p>";
				}
			}
		}
	}
	return $header . (!empty($output) ? $output : t('No descriptions available'));
}


?>
<?php
/**
 * Prints description(s)
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
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
//p($descriptions); p($language);
		foreach ($descriptions as $source => $t) {
			foreach ($t as $description => $lan) {
				if ($lan == $language->name) {
					$output .= "<h4 class='source'>" . printSource($data, $source) .
					   "</h4>\n<p>$description</p>";
				}
			}
		}
	}

	return _wrap(
		$header . (!empty($output) ? $output : t('No descriptions available')),
		"section",
		"result-detail-section"
	);
}


?>
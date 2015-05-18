<?php
/**
 * Prints common names
 *
 * Transposes common names array and prints common names
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */

function printSynonyms ($data) {
//p($data);
	$output = "";

	$header = "<h3>" . t('Synonyms') . "</h3>";

	if (isset($data['synonyms']) && !empty($data['synonyms'])) {
	    foreach ($data['synonyms'] as $source => $synonyms) {
			$output .= "<h4 class='source'>" . printSource($data, $source) . "</h4>
			     <div class='property-list'>\n<p>\n" .
			     implode('<br/>', $synonyms) .
			     "</p>\n</div>\n";
			$oldSource = $source;
		}
	}

	return _wrap(
		$header . (!empty($output) ? $output :
		      "<p class='property-list'>" . t('No synonyms available') . '</p>'),
		"section",
		"result-detail-section"
	);
}


?>
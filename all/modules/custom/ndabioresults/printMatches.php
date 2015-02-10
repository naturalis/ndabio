<?php
/**
 * Practically identical to printHits()
 *
 * @param array $row Parsed json data
 * @return string Formatted output
 */
function printMatches ($data) {
	$output = '';
	if (isset($data['searchTerms']) && !empty($data['searchTerms'])) {
		foreach ($data['searchTerms'] as $field => $value) {
		    if (!in_array(str_replace('_', '', $field), searchFlags())) {
			    $output .= translateNdaField($field) . ' <span class="result-query">' .
			    $value[0] . '</span>, ';
		    }
		}
	}
	return substr($output, 0, -2);
}


?>
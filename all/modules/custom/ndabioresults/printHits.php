<?php
/**
 * Prints hits (matched results) as field: hits
 *
 * Replaces default <span> with <span class="result-query">
 *
 * @param array $row Parsed json data
 * @return string|void Formatted output
 */
function printHits ($row) {
	$output = '';
	if (isset($row['hits']) && !empty($row['hits'])) {
		foreach ($row['hits'] as $field => $hit) {
			$output .= ucfirst(translateNdaField($field)) . ': ' .
				str_replace('<span class="search_hit">', '<span class="result-query">', $hit) . '</br>';
		}
	}
	return !empty($output) ? substr($output, 0, -5) : null;
}
?>
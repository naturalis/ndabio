<?php

// Prints hits as field: hits;
// replaces default <span> with <span class="result-query">
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
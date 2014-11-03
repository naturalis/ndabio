<?php

// Prints matches on screen
function printMatches ($data) {
	$output = '';
	if (isset($data['searchTerms']) && !empty($data['searchTerms'])) {
		foreach ($data['searchTerms'] as $term) {
			$output .= '<span class="result-query">' . $term . '</span>, ';
		}
	}
	return substr($output, 0, -2);
}


?>
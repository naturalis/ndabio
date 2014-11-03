<?php

// Prints navigation on details page
function printNavigation ($data) {
	$output = "<div class='navigation'>";
	if (isset($data['navigation']) && !empty($data['navigation'])) {
		$links = array_merge(array_flip(array('prev', 'next')), $data['navigation']);
		foreach ($links as $direction => $url) {
			$t = "<div class='$direction";
			$t .= !empty($url) ?
				"'><a href='" . printDrupalLink($url) . "'>" . $direction . "</a></div>" :
				"-disabled'></div>";
			$output .= $t;
		}
	}
	return $output . "</div>";
}


?>
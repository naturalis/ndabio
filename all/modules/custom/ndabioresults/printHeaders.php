<?php

// Prints headers of result table on screen
function printHeaders ($headers, $p) {
	$output = "<tr>";

  foreach ($headers as $i => $header) {
		$class = "";

    if ( $i == 0)                    { $class="column-first"; }
    if ( $header['label'] == "Match"){ $class="column-match"; }

    $output .= "<th class='$class'>";

    if ($header['sort'] == 1) {
			// Selected header
			if ($i == $p['sortColumn']) {
				$header['url'] .= ($p['sortDirection'] == 'asc' ? '&desc' : '&asc');
				$output .= "<a href='" . printDrupalLink($header['url']) . "'>" .
					$header['label'] . "</a>" .
					"<a href='" . printDrupalLink($header['url']) . "'>" .
					"<span class='sortable glyphicon " . $header['icon'] .
					($p['sortDirection'] == 'desc' ? "-alt" : "") . "'></span></a>";
			// Other headers
			} else {
				$header['url'] .= '&desc';
				$output .= "<a href='" . printDrupalLink($header['url']) . "'>" .
					$header['label'] . "</a>" .
					"<a href='" . printDrupalLink($header['url']) . "'>" .
					"<span class='sortable glyphicon icon-sort'></span></a>";
			}
		} else {
			$output .= $header['label'];
		}
		$output .= "</th>";
	}
	return $output . "</tr>";
}


?>
<?php

// Prints headers of result table on screen
function printHeaders ($headers, $self) {
	$output = "<tr>";

    $i = 0;
    foreach ($headers as $field => $header) {
        $class = "";

        if ( $i == 0)                    { $class="column-first"; }
        if ( $header['label'] == "Match"){ $class="column-match"; }

        $i++;
        $output .= "<th class='$class'>";

        if ($header['sort'] == 1 && $_SESSION['ndaRequestType'] != 'form') {
			// Selected header
			if ($field == getSortDirection($self)) {
				//$header['url'] .= ($p['sortDirection'] == 'asc' ? '&desc' : '&asc');
				$output .= "<a href='" . printDrupalLink($header['url']) . "'>" .
					$header['label'] . "</a>" .
					"<a href='" . printDrupalLink($header['url']) . "'>" .
					"<span class='sortable glyphicon " . $header['icon'] .
					(getSortDirection($self) == 'DESC' ? "-alt" : "") . "'></span></a>";
			// Other headers
			} else {
				//$header['url'] .= '&desc';
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
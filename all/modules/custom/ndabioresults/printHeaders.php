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

        if (isset($header['sort']) && $_SESSION['ndaRequestType'] != 'form') {
			// Selected header
			if ($field == getSort($self)) {
			    $sortDir = getSortDirection($self) == 'DESC' ? 'ASC' : 'DESC';
			     $sortDir = getSortDirection($self);
			    $output .= '<a href="' . printDrupalLink($header['url']) . '">' . $header['label'] . "</a>\n" .
			       '<a href="' . printDrupalLink($header['url']) . '"><span class="' . $header['icon'][$sortDir] .
			       '"></span></a>';
			    // Other headers
			} else {
			    $output .= '<a href="' . printDrupalLink($header['url']) . '">' . $header['label'] . "</a>\n" .
			        '<a href="' . printDrupalLink($header['url']) . '"><span class="icon-sort_sortable"></span></a>';
		    }
		} else {
			$output .= $header['label'];
		}
		$output .= "</th>";
	}
	return $output . "</tr>";
}


?>
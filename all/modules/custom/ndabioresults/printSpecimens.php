<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

// Prints specimen result set on screen.
function printSpecimens ($data, $p = array('sortColumn' => 0, 'sortDirection' => 'asc')) {
	$headers = array(
		array(
			'label' => t('Specimen'),
			'sort' => 1,
			'icon' => 'icon-sort-by-alphabet',
			'url' => '#'
		),
		array(
			'label' => t('Species'),
			'sort' => 1,
			'icon' => 'icon-sort-by-alphabet',
			'url' => '#'
		),
		array(
			'label' => t('Found in'),
			'sort' => 0
		),
		array(
			'label' => t('Match'),
			'sort' => 1,
			'icon' => 'icon-sort-by-attributes',
			'url' => '#'
		)
	);

  $output  = sprintf('<h2>%s <span class="count">(%d)</span></h2>', t('Specimens'), $data['total'] );
  $output .= sprintf('<table><thead>%s</thead><tbody>', printHeaders($headers, $p) );

  foreach ($data['results'] as $i => $row) {
		$output .= "<tr>";
		// Registration number plus hits
		$output .= "<td><a href='" . printDrupalLink($row['url']) . "'>" . $row['unitID'] . "</a>" .
			(!empty($row['hits']) ? '</br>' . printHits($row) : '') .
			"</td>";
		// Species
		$output .= "<td>" . printSpecimenTaxa($row['names']) . "</td>";
		// Source(s)
		$output .= "<td>" . $row['source'] . "</td>";
		// Match
		$output .= "<td>" . decorateScore($row['score']) . "</td>";
		$output .= "</tr>";
	}

	$output .= "</tbody></table>";

    $output .= printShowAll($data);
    $output .= printPaginator($data);

    return $output;
}


?>
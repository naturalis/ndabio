<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

// Prints specimen result set on screen.
function printSpecimens ($data) {

    if (empty($data['results'])) {
        return false;
    }

    $headers = array(
		'unitID' => array(
			'label' => t('Specimen'),
			'sort' => 1,
			'icon' => 'icon-sort-by-alphabet',
			'url' => setSortUrl('unitID', 'ASC', $data['self'])
		),
		'fullScientificname' => array(
			'label' => t('Species'),
			'sort' => 1,
			'icon' => 'icon-sort-by-alphabet',
			'url' => setSortUrl('fullScientificname', 'ASC', $data['self'])
		),
		'foundIn' => array(
			'label' => t('Found in'),
			'sort' => 0
		),
		'_score' => array(
			'label' => t('Match'),
			'sort' => 1,
			'icon' => 'icon-sort-by-attributes',
			'url' => setSortUrl('_score', 'DESC', $data['self'])
		)
	);

  $output  = sprintf('<h2>%s <span class="count">(%d)</span></h2>', t('Specimens'), $data['total'] );
  $output .= sprintf('<table><thead>%s</thead><tbody>', printHeaders($headers, $data['self']));

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
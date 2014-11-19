<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';


// Prints specimen result set on screen.
function printSpecimensByTaxon ($data) {

    if (empty($data['results'])) {
        return false;
    }

    if (isset($data['showMap'])) {
        return printSpecimensByMap($data);
    }

    $headers = array(
		'identifyingEpithets' => array(
			'label' => t('Name'),
			'sort' => 1,
			'icon' => 'icon-sort_a_z',
			'url' => setSortUrl('identifyingEpithets', 'ASC', $data['self'])
		),
		'count' => array(
			'label' => '',
			'sort' => 0,
			'url' => setSortUrl('count', 'ASC', $data['self'])
		),
        'mapIcon' => array(
			'label' => '',
			'sort' => 0
        ),
		'foundIn' => array(
			'label' => t('Found in'),
			'sort' => 0
		),
		'_score' => array(
			'label' => t('Match'),
			'sort' => 1,
			'icon' => 'icon-sort_much_little',
			'url' => setSortUrl('_score', 'DESC', $data['self'])
		)
	);

//p($data);

    $term  = _wrap(  implode( $data['searchTerms']['_search']   , ",") , "span", "term"  );
    $expl  = _wrap(  t('(occurring in the species&apos; name)')        , "span", "explanation");
    $count = _wrap(  $data['total']                                    , "span", "count");


    $output  = sprintf('<h2>%s %s %s %s</h2>', t('Specimens with'), $term, $expl, $count );
    $output .= sprintf('<table id="specimensByTaxon"><thead>%s</thead>', printHeaders($headers, $data['self']));

    foreach ($data['results'] as $i => $row) {
		$output .= "<tr class='indent-0' id='taxon-$i'>";
		// Name
		$output .= "<td><a href='" . printDrupalLink($row['url']) . "'>" . $row['name'] . "</a>" .
			(!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '') .
			"</td>";
		// Number (and collection type)
		$output .= "<td>" . $row['count'] . ' ' . ($row['count'] > 1 ? t('specimens') : t('specimen')) . "</td>";
		// Map icon
		$output .= "<td>" .
		  (isset($_SESSION['ndaSearch']['geoShape']) && !empty($_SESSION['ndaSearch']['geoShape']) ?
		      "<a href='" . printDrupalLink(geoShapeToSession($data['self'], true) . '&showMap' .
		      '&fullScientificName=' . urlencode($row['fullScientificName'])) .
		      "' class='icon-location'></a>" : '') .
		  "</td>";
		// Source(s)
		$output .= "<td>" . implode('</br>', $row['sources']) . "</td>";
		// Match
		$output .= "<td>" . decorateScore($row['score']) . "</td>";
		$output .= "</tr>";
		$output .= printSpecimenCollection($row, $i);
	}

    $output .= "</table>";
    $output = _markUp($output);

    $output .= printShowAll($data);
    $output .= printPaginator($data);

    return $output;
}


?>
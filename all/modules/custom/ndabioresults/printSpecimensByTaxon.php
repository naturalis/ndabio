<?php

require_once 'printShowAll.php';
require_once 'printNavigator.php';


// Prints specimen result set on screen.
function printSpecimensByTaxon ($data, $p = array('sortColumn' => 0, 'sortDirection' => 'asc')) {
	$headers = array(
		array(
			'label' => t('Name'),
			'sort' => 1,
			'icon' => 'icon-sort-by-alphabet',
			'url' => '#'
		),
		array(
			'label' => t('Number'),
			'sort' => 1,
			'icon' => 'icon-sort-by-attributes',
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

  // $output = '<h2>' . t('Your search for') . ' ' . printMatches($data) .
	// 	' ' . t('returned') . ' ' . $data['total'] . ' ' . t('specimens') . ".</h2>\n" .
	// 	"<h3 class='results-set-header'>" . t('Species with specimens') . "</h3>\n" .
	// 	"<table class='table'><thead>" . printHeaders($headers, $p) .
	// 	"</thead><tbody>";

  if (!isset($data['results']) || empty($data['results'])) {
        return sprintf('<h2>%s %s %s</h2><p>%s</p>',
            t('Specimens with'),
            t('search term'),
            t('occurring in the species&apos; name'),
            t('No results'));
  }


  $output  = sprintf('<h2>%s %s %s <span class="count">(%d)</span></h2>', t('Specimens with'), printMatches($data), t(' occurring in the species&apos; name'),$data['total'] );
  $output .= sprintf('<table id="specimensByTaxon"><thead>%s</thead>', printHeaders($headers, $p) );

  foreach ($data['results'] as $i => $row) {
		$output .= "<tr class='indent-0' id='taxon-$i'>";
		// Name
		$output .= "<td><a href='" . printDrupalLink($row['url']) . "'>" . $row['name'] . "</a>" .
			(!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '') .
			"</td>";
		// Number (and collection type)
		$output .= "<td>" . $row['count'] . ' ' . ($row['count'] > 1 ? t('specimens') : t('specimen')) . "</td>";
		// Source(s)
		$output .= "<td>" . implode('</br>', $row['sources']) . "</td>";
		// Match
		$output .= "<td>" . decorateScore($row['score']) . "</td>";
		$output .= "</tr>";
		$output .= printSpecimenCollection($row, $i);
	}

  $output .= "</table>";
  $output .= printShowAll($data);
  $output .= printNavigator($data);

  return _markUp($output);
}


?>
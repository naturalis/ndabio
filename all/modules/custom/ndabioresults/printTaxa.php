<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

/* Prints taxon result set on screen. Parameters $p should contain:
   'sortColumn', 'sortDirection'

   TODO:
   1. Set truncated (for overview)/non-truncated
   2. Pass $p['total'] dynamically

*/
function printTaxa ($data, $p = array('sortColumn' => 0, 'sortDirection' => 'asc')) {
	$headers = array(
		array(
			'label' => t('Name'),
			'sort' => 1,
			'icon' => 'icon-sort-by-alphabet',
			'url' => '#'
		),
		array(
			'label' => t('Description'),
			'sort' => 0
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

  $explanation = _wrap("(matching scientific or common name)","span","explanation");
  $output  = sprintf('<h2>%s <span class="count">(%d)</span> %s</h2>', t('Species names'), $data['total'], $explanation );
  $output .= sprintf('<table><thead>%s</thead><tbody>', printHeaders($headers, $p) );

  foreach ($data['results'] as $i => $row) {
		$output .= "<tr>";

    // Name
		$output .= "<td>";
    $output .= "<a href='" . printDrupalLink($row['url']) . "'>" . $row['name'] . "</a>";
		$output .= (!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '');
		$output .=	"</td>";

    // Description
    $output .= "<td>" . decorateDescription($row) . "</td>";

    // Source(s)
    $output .= "<td>" . implode('</br>', $row['sources']) . "</td>";

    // Match
		$output .= "<td>" . decorateScore($row['score']) . "</td>";

    $output .= "</tr>";
	}

    $output .= "</tbody></table>";
    $output = _markUp($output);

    $output .= printShowAll($data);
    $output .= printPaginator($data);

	return $output;
}


?>
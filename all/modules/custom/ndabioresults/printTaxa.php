<?php

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

  $output  = sprintf('<h2>%s <span class="count">(%d)</span></h2>', t('Species names'), $data['total'] );
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

    if (isset($data['moreUrl']) && !empty($data['moreUrl'])) {
        $output .= '<p class="more"><a href="' . $data['moreUrl'] . '">' .
            t('Show all...') . '</a></p>';
    }

	return $output;
}


?>
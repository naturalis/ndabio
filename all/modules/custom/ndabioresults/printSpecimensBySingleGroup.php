<?php

require_once 'printPaginator.php';


// Prints specimen result set on screen.
function printSpecimensBySingleGroup ($data) {
//p($data);
    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    setTitle($headTitle, $headTitle);

    $headers = array(
		'unitID' => array(
			'label' => t('Specimen'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl('unitID', 'ASC', $data['self'])
		),
		'count' => array(
			'label' => ''
		),
        'mapIcon' => array(
			'label' => ''
        ),
		'foundIn' => array(
			'label' => t('Found in')
		),
		'_score' => array(
			'label' => t('Match'),
			'sort' => 'DESC',
			'icon' => array(
			    'ASC' => 'icon-sort_little_much',
			    'DESC' => 'icon-sort_much_little'
			),
			'url' => setSortUrl('_score', 'DESC', $data['self'])
		)
	);

    $count = _wrap('(' . _formatNumber($data['results'][0]['count']) . ')', "span", "count");
    $output = sprintf('<h2>%s %s</h2>', t('Specimens of ' .
        str_replace('result-query', '', $data['results'][0]['name'])), $count);

    $output .= sprintf('<table><thead>%s</thead>', printHeaders($headers, $data['self']));

    foreach ($data['results'] as $i => $row) {
        // Single specimen
        if (isset($row['specimens'])) {
            foreach ($row['specimens'] as $specimen) {
                $info = implode('; ', array_filter(array(
                    ucfirst($specimen['kindOfUnit']),
                    $specimen['preparationType']
                )));
                $output .= "<tr>
                    <td><a href='" . printDrupalLink($specimen['url']) . "'>" . $specimen['unitID'] . "</a></td>
                    <td colspan='2'>$info</td>
                    <td>" . implode('</br>', $data['results'][0]['sources']) . "</td>
                    <td>" . decorateScore($row['score']) . "</td>
                    </tr>";
            }

        // Specimen collection/set
        } else if (isset($row['sets'])) {
            foreach ($row['sets'] as $set => $specimens) {
            	$output .= "<tr><td>" . $set . "</td>" . padTds(4) . "</tr>";
            	foreach ($specimens as $j => $specimen) {
            	    $output .= "<tr class='indent-1'>
            	    <td><a href='" . printDrupalLink($specimen['url']) . "'>"  . $specimen['unitID'] . "</a></td>
            	    <td colspan='2'>" . $specimen['recordBasis'] . "</td>
                    <td>" . implode('</br>', $data['results'][0]['sources']) . "</td>
                    <td>" . decorateScore($row['score']) . "</td>
                    </tr>";
            	}
            }
        }
	}

    $output .= "</table>";
    $output = _markUp($output);

    $output .= printPaginator($data);

    return $output;
}


?>
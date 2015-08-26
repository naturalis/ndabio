<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

/**
 * Prints specimen search result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimens ($data) {

    if (empty($data['results'])) {
        return false;
    }

    // Drupal title empty; page title custom
    $headTitle = !isset($_SESSION['ndaSearch']['theme']) || empty($_SESSION['ndaSearch']['theme']) ?
        t('Search results') : t('Explore highlights');
    $pageTitle = isset($_GET['theme']) ? '' : $pageTitle;
    setTitle($headTitle, $pageTitle);

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
		'identifications.scientificName.fullScientificName' => array(
			'label' => t('Species'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl('identifications.scientificName.fullScientificName', 'ASC', $data['self'])
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

    $output = '<div id="' . specimenService() . '"></div>';
    $output .= sprintf(
        '<h2>%s <span class="count">(%s)</span></h2>',
        t('Specimens'),
        _formatNumber($data['total'])
    );
    $output .= sprintf('<table><thead>%s</thead><tbody>', printHeaders($headers, $data['self']));

  foreach ($data['results'] as $i => $row) {
		$output .= "<tr>";
		// Registration number plus hits
		$output .= "<td><a href='" . printDrupalLink($row['url']) . "'>" . $row['unitID'] . "</a>" .
			(!empty($row['hits']) ? '<br/>' . printHits($row) : '') .
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
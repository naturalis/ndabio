<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

/**
 * Prints taxon search result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printTaxa ($data) {
//p($data);
    if (empty($data['results'])) {
        return false;
    }

    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    setTitle($headTitle, $headTitle);

    $headers = array(
    	'acceptedName.fullScientificName' => array(
    		'label' => t('Name'),
    		'sort' => 'ASC',
    		'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
    		'url' => setSortUrl('acceptedName.fullScientificName', 'ASC', $data['self'])
    	),
    	'description' => array(
    		'label' => t('Description')
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

    $explanation = _wrap(t("(matching scientific or common name)"),"span","explanation");

    $output = '<div id="' . taxonService() . '"></div>';
    $output .= sprintf(
        '<h2>%s <span class="count">(%s)</span> %s</h2>',
        t('Species names'),
        _formatNumber($data['total']),
        $explanation
    );
    $output .= sprintf('<table><thead>%s</thead><tbody>', printHeaders($headers, $data['self']));

    foreach ($data['results'] as $i => $row) {
    	$output .= "<tr>";

        // Name
        $output .= "<td>";
        $output .= "<a href='" . printDrupalLink($row['url']) . "'>" . $row['name'] . "</a>";
        $output .= (!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '');
        $output .=	"</td>";

        // Description
        $output .= "<td>" . $row['description'] . "</td>";

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

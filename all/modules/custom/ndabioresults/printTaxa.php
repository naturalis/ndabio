<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

/* Prints taxon result set on screen. Parameters $p should contain:
   'sortColumn', 'sortDirection'

   TODO:
   1. Set truncated (for overview)/non-truncated
   2. Pass $p['total'] dynamically

*/
function printTaxa ($data) {
//p($data);
    if (empty($data['results'])) {
        return false;
    }

    // Drupal title empty; page title custom
    $headTitle = !isset($_SESSION['ndaSearch']['theme']) || empty($_SESSION['ndaSearch']['theme']) ?
        t('Search results') : t('Explore highlights');
    $pageTitle = isset($_GET['theme']) || isset($_GET['back']) && !empty($_SESSION['ndaSearch']['theme']) ?
        '' : $pageTitle;
    setTitle($headTitle, $pageTitle);

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

    $explanation = _wrap("(matching scientific or common name)","span","explanation");
    $output  = sprintf('<h2>%s <span class="count">(%s)</span> %s</h2>',
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
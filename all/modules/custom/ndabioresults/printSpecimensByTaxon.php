<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';
require_once 'printSpecimensBySingleGroup.php';

/**
 * Prints specimen name search result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimensByTaxon ($data) {
//p($data);
    if (empty($data['results'])) {
        return false;
    }

    if (isset($data['_showMap'])) {
        return printSpecimensByMap($data);
    }

    if (isset($data['single']) && $data['single']) {
        return printSpecimensBySingleGroup($data);
    }

    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    setTitle($headTitle, $headTitle);

    $headers = array(
		'identifications.scientificName.fullScientificName' => array(
			'label' => t('Name'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl(
                'groupName',
			    'ASC',
			    $data['self'],
			    true
			)
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
			'url' => setSortUrl(
                '_score',
			    'DESC',
			    $data['self'],
			    true
			)
		)
	);

    /*
    if (isset($data['searchTerms']['_search'])  ){

      $term  = _wrap(  implode( $data['searchTerms']['_search']   , ",") , "span", "term"  );
      $expl  = _wrap(  t('(occurring in the species&apos; name)')        , "span", "explanation");
      $count = _wrap(  '(' ._formatNumber($data['total']) . ')', "span", "count");
      $output  = sprintf('<h2>%s %s %s %s</h2>', t('Specimens with'), $term, $count, $expl );
    } else {
      $count = _wrap(  "(" . _formatNumber($data['total']) . ")", "span", "count");

      $expl  = _wrap(  t('(grouped by species name)')        , "span", "explanation");
      $output  = sprintf('<h2>%s %s %s</h2>', t('Specimens'), $count, $expl );
    }
    */

    $count = _wrap('(' . _formatNumber($data['total']) . ')', "span", "count");
    $output = sprintf('<h2>%s %s</h2>', t('Species with specimens'), $count);

    $output .= sprintf('<table id="specimensByTaxon"><thead>%s</thead>', printHeaders($headers, $data['self']));

    foreach ($data['results'] as $i => $row) {
		$output .= "<tr class='indent-0' id='taxon-$i'>";
		// Name
		$url = printDrupalLink($row['url']);

		$output .= "<td>" . "<a href='" . (!empty($url) ? $url : '#') . "'>" . $row['name'] . "</a>" .
		    (!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '') . "</td>";
		// Number (and collection type)
		$output .= "<td>" . $row['count'] . ' ' . ($row['count'] > 1 ? t('specimens') : t('specimen')) . "</td>";
		// Map icon
		$output .= "<td>" .
		  (isset($_SESSION['ndaSearch']['geoShape']) && !empty($_SESSION['ndaSearch']['geoShape'])
		      && !isset($_GET['noMap']) ?
		      "<a href='" . printDrupalLink(
                specimenNamesService() . '?_geoShape=[session]&' .
		      '&identifications.scientificName.fullScientificName.raw=' .
		      urlencode(urlencode($row['fullScientificName'])) . '&_showMap&_maxResults=100') .
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
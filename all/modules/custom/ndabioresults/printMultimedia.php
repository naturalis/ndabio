<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

/**
 * Prints multimedia
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printMultimedia ($data) {

    if (empty($data['results'])) {
        return false;
    }

    // Drupal title empty; page title custom
    $headTitle = !isset($_SESSION['ndaSearch']['theme']) || empty($_SESSION['ndaSearch']['theme']) ?
        t('Search results') : t('Explore highlights');
    $pageTitle = isset($_GET['theme']) ? '' : $pageTitle;
    $searchId = isset($data['searchTerms']) ? setSearchId($data['searchTerms']) : false;

    setTitle($headTitle, $pageTitle);

    $output = '<div id="' . multimediaService() . '"></div>';
    $output .= sprintf(
        '<h2>%s <span class="count">(%s)</span></h2>',
        t('Multimedia'),
        _formatNumber($data['total'])
    );
    $output .= "<div class='multimedia-wrapper'>";

    foreach ($data['results'] as $i => $row) {
    	$w = "240";
        $h = 100 + $i * 50;

        // Reset imgUrl if media is mp4
        if ($row['format'] == 'video/mp4') {
            $row['imgSrc'] = setBasePath() .
                'profiles/naturalis/themes/custom/naturalis_theme/images/naturalis/play.png';
        }

        $mmHit = printMultimediaHit($row);

        // Append searchId as a search term after each url; used for navigation
        $row['url'] .= urlencode('&searchID=' . $searchId);

        $output .=
          "<a class='polaroid' href='" . printDrupalLink($row['url']). "' title='" . $row['title'] . "'>" .
          "  <div class='polaroid-image' style='background-image: url(" . $row['imgSrc']. ");' alt='" . $row['title'] . "'></div>" .
          "  <div class='polaroid-caption'>".
          "    <div class='image-title'>" . (!empty($row['taxon']) ? $row['taxon'] : '&mdash;') .
                    (!empty($row['unitID']) ? '<br>' . $row['unitID'] : '') . "</div>";
         $output .= (strpos($row['unitID'], $row['caption']) === false) ?
           "    <div class='image-hits'>" . $row['caption'] . "</div>" : '';
         $output .= $mmHit ?
           "    <div class='image-hits'>" . $mmHit ."</div>" : '';
         $output .= "  </div>" .
          "</a>";
    }

    $output .=  "</div>";
    $output = _markUp($output);

    $output .= printShowAll($data);
    $output .= printPaginator($data);

  return $output;
}

/**
 * Only prints first hit
 *
 * @param array $row Parsed json
 * @return string|void
 */
function printMultimediaHit ($row) {
	if (isset($row['hits']) && !empty($row['hits'])) {
		foreach ($row['hits'] as $field => $hit) {
		    // Skip hits that are part of the scientific name
		    if (in_array($field,
                array(
                    'genusOrMonomial',
                    'specificEpithet',
                    'infraspecificEpithet',
                    'subgenus',
                    'associatedSpecimenReference',
                    'associatedTaxonReference'
                ))) {
                continue;
		    }
            // Rename field if it doesn't match ABCD term
            $replace = array(
                'name' => t('Common name')
            );
            if (isset($replace[$field])) {
                $field = $replace[$field];
            }
			return ucfirst(translateNdaField($field)) . ': ' .
				str_replace('<span class="search_hit">', '<span class="result-query">', $hit);
		}
	}
	return false;
}
?>

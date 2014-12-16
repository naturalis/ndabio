<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

// Prints multimedia on screen
function printMultimedia ($data) {

    if (empty($data['results'])) {
        return false;
    }
//p($data);

    // Drupal title empty; page title custom
    $headTitle = !isset($_SESSION['ndaSearch']['theme']) || empty($_SESSION['ndaSearch']['theme']) ?
        t('Search results') : t('Explore highlights');
    $pageTitle = isset($_GET['theme']) ? '' : $pageTitle;
    setTitle($headTitle, $pageTitle);

    $output  = sprintf('<h2>%s <span class="count">(%s)</span></h2>',
        t('Multimedia'),
        _formatNumber($data['total'])
    );
    $output  .= "<div class='multimedia-wrapper'>";

    foreach ($data['results'] as $i => $row) {
    	$w = "240";
        $h = 100 + $i * 50;

        // Reset imgUrl if media is mp4
        if ($row['format'] == 'video/mp4') {
            $row['imgSrc'] = setBasePath() .
                'profiles/naturalis/themes/custom/naturalis_theme/images/naturalis/play.png';
        }

        $mmHit = printMultimediaHit($row);

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



?>
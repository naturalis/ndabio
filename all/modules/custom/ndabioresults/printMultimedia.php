<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

// Prints multimedia on screen
function printMultimedia ($data) {

    if (empty($data['results'])) {
        return false;
    }
//p($data);
    $output  = sprintf('<h2>%s <span class="count">(%d)</span></h2>', t('Multimedia'), $data['total'] );
    $output  .= "<div class='multimedia-wrapper'>";

    foreach ($data['results'] as $i => $row) {
    	$w = "240";
        $h = 100 + $i * 50;

        // @todo temp fix for medialib
        $row['imgSrc'] = str_replace('file://', '', $row['imgSrc']);

        // kpr($row);

        // Build a nice caption.
        $caption = '';
        if ( !empty( $row['hits']['genusOrMonomial']) ){
            $caption .=  $row['hits']['genusOrMonomial'];
        }

        $output .=
          "<a class='polaroid' href='" . printDrupalLink($row['url']). "' title='" . $row['title'] . "'>" .
          "  <div class='polaroid-image' style='background-image: url(" . $row['imgSrc']. ");' alt='" . $row['title'] . "'></div>" .
          "  <div class='polaroid-caption'>".
          "    <div class='image-title'>" . $row['taxon'] . (!empty($row['unitID']) ? '<br>' . $row['unitID'] : '') . "</div>".
          // "    <div class='image-title'>" . $row['caption'] . "</div>".
          // "    <div class='image-hits'>" . printHits($row) .  "</div>".
        		"    <div class='image-hits'>" . $row['caption'] .  "</div>".
        	  // "    <div class='image-source'>" . $row['source'] . "</div>".
          "  </div>".
          "</a>";
    }

    $output .=  "</div>";
    $output = _markUp($output);

    $output .= printShowAll($data);
    $output .= printPaginator($data);

  return $output;
}



?>
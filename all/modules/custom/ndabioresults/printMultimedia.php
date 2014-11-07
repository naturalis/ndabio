<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';

// Prints multimedia on screen
function printMultimedia ($data) {

  // $output = '<h2>' . t('Your search for') . ' ' . printMatches($data) .
	// 	' ' . t('returned') . ' ' . $data['total'] . ' ' . t('images') . ".</h2>\n" .
	// 	"<h3 class='results-set-header'>" . t('Multimedia') . "</h3>\n" .
	// 	"<div class='col-results-set'>\n";

  $output  = sprintf('<h2>%s <span class="count">(%d)</span></h2>', t('Multimedia'), $data['total'] );
  $output  .= "<div class='multimedia-wrapper'>";

//echo '<pre>'; print_r($data); echo '</pre>';

  foreach ($data['results'] as $i => $row) {
		$w = "240";
    $h = 100 + $i * 50;

    // @todo temp fix for medialib
    $row['imgSrc'] = str_replace('file://', '', $row['imgSrc']);

    $output .=
      "<a class='polaroid' href='" . printDrupalLink($row['url']). "' title='" . $row['title'] . "'>" .
      "  <div class='polaroid-image' style='background-image: url(" . $row['imgSrc']. ");' alt='" . $row['title'] . "'></div>" .
      "  <div class='polaroid-caption'>".
      "    <div class='image-title'>" . $row['caption'] . "</div>" .
			"    <div class='image-hits'>" . printHits($row) . "</div>" .
		    "    <div class='image-source'>" . $row['source'] . "</div>".
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
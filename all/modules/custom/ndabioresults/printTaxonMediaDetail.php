<?php

function printTaxonMediaDetail ($data) {
  
  $output  = _wrap( t("Media item")   , "div", "category");
  $output .= _wrap( basename(  $data['imgSrc']  ) , "h2"  );

  $output .="<img src='" . $data['imgSrc'] . "' alt='" . $data['title'] .
		"' title=''" . $data['title'] . ">";
	
  $output .= "<div class='property-list'>";

  foreach (array('acceptedName', 'source', 'title', 'caption') as $field) {
		$output .= printDL($field, $data[$field]);
	}

	return $output . "</div>";
}



?>
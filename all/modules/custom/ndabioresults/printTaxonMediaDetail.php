<?php

function printTaxonMediaDetail ($data) {
  
  $output  = _wrap( t("Media item")   , "div", "category");
  $output .= _wrap( basename(  $data['imgSrc']  ) , "h2"  );

  dpr($data);
	
  $output .="<img src='" . $data['imgSrc'] . "' alt='" . $data['title'] .
		"' title=''" . $data['title'] . ">";
	
  $output .= "<dd class='table-property-list'>";

  foreach (array('acceptedName', 'source', 'title', 'caption') as $field) {
		$output .= printDL($field, $data[$field]);
	}

	return $output . "</dd>";
}



?>
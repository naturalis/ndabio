<?php

function printTaxonDetail ($data) {
  global $language;

//  p($data);


  $output .=   "<h2>";
  $output .=   "  <span class='scientific-name'>";
  $output .=        $data['acceptedName'];
  $output .=   "  </span>";

  if ( isset($data['commonNames'][$language->language]) ){
    $output .= "  <span class='vernacular-name'>";
    $output .= implode(', ', $data['commonNames'][$language->language]);
    $output .= "  </span>";
  }

  $output .=
		printCommonNames($data) .
		printDescriptions($data) .
		printClassifications($data);

  // $output .= printNavigation($data); --> MOVE TO BLOCK


  return $output;
}


?>
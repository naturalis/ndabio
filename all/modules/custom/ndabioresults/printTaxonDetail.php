<?php



function printTaxonDetail ($data) {
  global $language;

  $output  =   "<div class='category'>".t('Taxon name')."</div>";
  $output .=   "<h2>";
  $output .=   "  <span class='scientific-name'>";
  $output .=        $data['acceptedName'];
  $output .=   "  </span>";

  if ( isset($data['commonNames'][$language->language]) ){
    $output .= "  <span class='vernacular-name'>";
    $output .= implode(', ', $data['commonNames'][$language->language]);
    $output .= "  </span>";
  }

  $output .= "</h2>";

  $output .=
		printCommonNames($data) .
		printDescriptions($data) .
		printClassifications($data);

  // $output .= printNavigation($data); --> MOVE TO BLOCK


  return $output;
}


?>
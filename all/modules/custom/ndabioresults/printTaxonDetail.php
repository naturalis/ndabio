<?php
function printTaxonDetail ($data) {
    global $language;

    $output  =   "<div class='category'>".t('Taxon')."</div>";
    $output .=   "<h2>";
    $output .=   "  <span class='scientific-name'>";
    $output .=        $data['acceptedName'];
    $output .=   "  </span>";

    if ( isset($data['commonNames'][$language->language]) ){
    $output .= "  <span class='vernacular-name'>";
    $output .=      implode(', ', $data['commonNames'][$language->language]);
    $output .= "  </span>";
    }

    $output .= "</h2>";

    $output .=
        printCommonNames($data) .
        printDescriptions($data) .
        printClassifications($data);

//p($data);

    $getSpecimenRequest = ndaBaseUrl() . specimenNamesService() .
        '/?' . http_build_query($data['nameElements']) . '&_andOr=AND';
    $getMultimediaRequest = ndaBaseUrl() . multimediaService() .
        '/?' . http_build_query($data['nameElements']) . '&_andOr=AND';

    drupal_add_js(drupal_get_path('module', 'ndabioresults') . "/js/ajax.js", array('weight' => 1));
    drupal_add_js("var getSpecimenRequest = '$getSpecimenRequest'", 'inline');
    drupal_add_js("var getMultimediaRequest = '$getMultimediaRequest' ", 'inline');
    drupal_add_js("jQuery(document).ready(function() { getTotal(getSpecimenRequest, setTaxonSpecimenLink); });", 'inline');
    drupal_add_js("jQuery(document).ready(function() { getTotal(getMultimediaRequest, setTaxonMultimediaLink); });", 'inline');

    $output .= '<h3>' . t('Specimens'). '</h3><p id="taxon_specimens"></p>';
    $output .= '<h3>' . t('Multimedia'). '</h3><p id="taxon_multimedia"</p>';

    // Drupal title empty; page title custom
    setTitle($_SESSION['ndaSearch']['pageTitle'] = t('Taxon') . ' | '. strip_tags($data['acceptedName']));

    return $output;
}


?>
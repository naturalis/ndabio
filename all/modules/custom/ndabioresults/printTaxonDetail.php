<?php
/**
 * Prints taxon detail result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
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
        printSynonyms($data) .
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
    drupal_add_js(
        "jQuery(function() { getNbaData(getSpecimenRequest, setSpecimenPreview, '&_maxResults=5'); });",
        array('type' => 'inline', 'scope' => 'footer')
    );
    drupal_add_js(
        "jQuery(function() { getNbaData(getMultimediaRequest, setMultimediaPreview, '&_maxResults=5'); });",
        array('type' => 'inline', 'scope' => 'footer')
    );

    $output .= '<h3>' . t('Specimens'). '</h3><p class="property-list" id="nba_specimens"></p>';
    $output .= '<h3>' . t('Multimedia'). '</h3><p class="property-list" id="nba_multimedia"></p>';


    // Drupal title empty; page title custom
    setTitle(t('Taxon') . ' | '. strip_tags($data['acceptedName']));

    return $output;
}


?>
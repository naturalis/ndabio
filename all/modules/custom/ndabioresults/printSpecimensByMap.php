<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';


// Prints specimen result set on screen.
function printSpecimensByMap ($data) {

    // Add Google Maps scripts from ndabio module (REQUIRED!)
    global $base_root, $base_path;
    $path = drupal_get_path('module', 'ndabio');
    drupal_add_css($path . "/css/ndabio_style.css");
    drupal_add_js($path . "/js/map.js", array('weight' => 1));
    drupal_add_js("https://maps.googleapis.com/maps/api/js?key=" . variable_get('ndabio_config_gmapkey', NDABIO_GMAPKEY) . "&libraries=drawing");
    drupal_add_js("jQuery(document).ready(function() { google.maps.event.addDomListener(window, 'load', initializeSpecimenMap); });", 'inline');
    drupal_add_js("var str_base_path = '$base_path' ", 'inline');
    drupal_add_js("var specimenMarkers = " . json_encode($data['results']), 'inline');
    drupal_add_js("var geoShape = " . $_SESSION['ndaSearch']['geoShape'], 'inline');


//p($data);

//    echo $_SESSION['ndaSearch']['geoShape'];
//    p(json_encode($data['results']));
    $output = '<div id="map-canvas"></div>';

    return $output;
}


?>
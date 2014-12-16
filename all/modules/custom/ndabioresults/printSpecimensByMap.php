<?php

require_once 'printShowAll.php';
require_once 'printPaginator.php';


// Prints specimen result set on screen.
function printSpecimensByMap ($data) {
    // Add Google Maps scripts from ndabio module (REQUIRED!)
    global $base_root, $base_path;

    // Drupal title empty; page title custom
    $pageTitle = !isset($_SESSION['ndaSearch']['theme']) || empty($_SESSION['ndaSearch']['theme']) ?
        t('Search results') : t('Explore highlights');
    setTitle($pageTitle, isset($_GET['theme']) ? '' : $pageTitle);

    $path = drupal_get_path('module', 'ndabio');
    drupal_add_css($path . "/css/ndabio_style.css");
    drupal_add_js($path . "/js/map.js", array('weight' => 1));
    drupal_add_js("https://maps.googleapis.com/maps/api/js?key=" . variable_get('ndabio_config_gmapkey', NDABIO_GMAPKEY) . "&libraries=drawing");
    drupal_add_js("jQuery(document).ready(function() { google.maps.event.addDomListener(window, 'load', initializeSpecimens); });", 'inline');
    drupal_add_js("var str_base_path = '$base_path';", 'inline');
    drupal_add_js("var specimenMarkers = " . json_encode($data['results']) .';', 'inline');
    drupal_add_js("var geoShape = " . $_SESSION['ndaSearch']['geoShape'] .';', 'inline');
    if (isset($_SESSION['ndaSearch']['mapCenter'])) {
        drupal_add_js('var storedMapCenter = "' . $_SESSION['ndaSearch']['mapCenter'] . '";', 'inline');
    }
    if (isset($_SESSION['ndaSearch']['zoomLevel'])) {
        drupal_add_js("var storedZoomLevel = " . $_SESSION['ndaSearch']['zoomLevel'] . ';', 'inline');
    }

//p($data);

    $output = sprintf('<h2>%s %s %s %s</h2>',
        t('Specimens of '),
        $data['results'][0]['name'],
        ' in ',
        (!empty($_SESSION['ndaSearch']['location']) ? $_SESSION['ndaSearch']['location'] :
            t('area drawn on map'))
    );
    $output .= '<div id="map-canvas"></div>';

    return $output;
}


?>
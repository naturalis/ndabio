<?php
// Make module config globally available
require_once 'ndabioresults.config.inc';

// Initialize BioPortal client
// Can't get autoloader to work, problem with namespaces in Drupal 7?
$clientPath = DRUPAL_ROOT . '/library/bioportal-client/lib/nl/naturalis/bioportal/';
require_once $clientPath . 'AbstractClass.php';
require_once $clientPath . 'Client.php';
require_once $clientPath . 'QuerySpec.php';
require_once $clientPath . 'Condition.php';

use nl\naturalis\bioportal\Client as Client;

function initBioPortalClient() {
    $client = new Client();
    $client->setNbaUrl(ndaBaseUrl());
    return $client;
}

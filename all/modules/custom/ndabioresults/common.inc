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


function initBioPortalClient () {
    $client = new Client();
    $client->setNbaUrl(ndaBaseUrl());
    return $client;
}

function nbaFieldTypes () {
    $nbaFieldTypes = &drupal_static(__FUNCTION__);
    if (!$nbaFieldTypes) {
        $cacheId = 'nbaFieldTypes';
        $cache = cache_get($cacheId, 'cache');
        if ($cache && !empty($cache->data)) {
            $nbaFieldTypes = $cache->data;
            return $nbaFieldTypes;
        }
        $client = initBioPortalClient();
        $r = $client->all()->getMapping();
        foreach ($r as $service => $json) {
            $nbaFieldTypes[$service] = getMappingProperties(json_decode($json, true));
        }
        unset($client);
        cache_set($cacheId, $nbaFieldTypes);
    }
    return $nbaFieldTypes;
}

function getMappingProperties ($mapping, $prefix = '') {
    $r = [];
    foreach ($mapping['properties'] as $k => $v) {
        if (isset($v['properties'])) {
            $r = $r + getMappingProperties($v, $prefix . $k . '.');
        } else {
            $operator = '';
            if (isset($v['fields']['like'])) {
                $operator = 'LIKE';
            } else if (isset($v['fields']['analyzed'])) {
                $operator = 'MATCHES';
            } else if (isset($v['fields']['ignoreCase'])) {
                $operator = 'EQUALS_IC';
            } else {
                $operator = 'EQUALS';
            }
            $r[$prefix . $k] = $v['type'] . ($operator != '' ? " | $operator" : '');
        }
    }
    return $r;
}

function getDistinctValues ($service, $nbaPath) {
    $client = initBioPortalClient();
    $d = $client->{$service}()->getDistinctValues($nbaPath);
    unset($client);
    $values = array_keys(json_decode($d, true));
    sort($values);
    return $values;
}

/**
 * Converts timestamp in milliseconds to year-month-day
 *
 * @param string $v
 * @return string
 */
function timeStampToDate ($v) {
    if (!empty($v)) {
        return date('Y-m-d', $v / 1000);
    }
    return null;
}

/**
 * Shorthand function for print_r()
 */
 function p ($a) {
   echo '<pre>'; print_r($a); echo "</pre>\n\n";
}





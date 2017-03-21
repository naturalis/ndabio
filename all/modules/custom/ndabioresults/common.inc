<?php
// @TODO: restore caching of NBA field map!




// Make module config globally available
require_once 'ndabioresults.config.inc';

// Initialize BioPortal client
// Can't get autoloader to work, problem with namespaces in Drupal 7?
$clientPath = DRUPAL_ROOT . '/library/bioportal-client/lib/nl/naturalis/bioportal/';
require_once $clientPath . 'Common.php';
require_once $clientPath . 'Client.php';
require_once $clientPath . 'QuerySpec.php';
require_once $clientPath . 'NameGroupQuerySpec.php';
require_once $clientPath . 'Condition.php';

use nl\naturalis\bioportal\Client as Client;


function initBioPortalClient () {
    $client = new Client();
    $client->setNbaUrl(NBABASEURL());
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
        $r = $client->all()->getFieldInfo();
        foreach ($r as $service => $json) {
            $nbaFieldTypes[$service] = getOptimalOperators(json_decode($json));
        }
        unset($client);
        cache_set($cacheId, $nbaFieldTypes);
    }
    return $nbaFieldTypes;
}

/* Meer dan geo_shape en keyword hebben we voorlopig niet */
function getOptimalOperators ($fields) {
	foreach ($fields as $path => $field) {
		if ($field->type == 'geo_shape') {
			$r[$path] = $field->type . ' | IN';
		}
		if ($field->type == 'keyword') {
			foreach (['LIKE', 'MATCHES', 'EQUALS_IC', 'EQUALS'] as $operator) {
				if (in_array($operator, $field->allowedOperators)) {
					$r[$path] = $field->type . ' | ' . $operator;
					break;
				}
			}
		}
	}
	return isset($r) ? $r : false;
}

/* Defunct for older NBA method */
function getMappingProperties ($mapping, $prefix = '') {
    $r = [];
    foreach ($mapping['properties'] as $k => $v) {
        if (isset($v['properties'])) {
            $r = $r + getMappingProperties($v, $prefix . $k . '.');
        } else {
            $operator = '';
            // Text, type of analyzer determines operator
            if ($v['type'] == 'keyword') {
                if (isset($v['fields']['like'])) {
                    $operator = 'LIKE';
                } else if (isset($v['fields']['analyzed'])) {
                    $operator = 'MATCHES';
                } else if (isset($v['fields']['ignoreCase'])) {
                    $operator = 'EQUALS_IC';
                } else {
                    $operator = 'EQUALS';
                }
            // Geo
            } else if ($v['type'] == 'geo_shape') {
                $operator = 'IN';
            // Other types (date etc) may go here, but currently not in use
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


/**
 * Helper function that parses query string into array
 *
 * Alternate function for parse_url that preserves periods and other special
 * characters in parameter names
 *
 * @param array $target Output
 * @param string $source Input
 * @return array
 */
function safe_parse_str ($source, &$target) {
	if (!$source) {
		return;
	}
	$keys = $target = array();
	$source = preg_replace_callback(
		'/
        # Match at start of string or &
        (?:^|(?<=&))
        # Exclude cases where the period is in brackets, e.g. foo[bar.blarg]
        [^=&\[]*
        # Affected cases: periods and spaces
        (?:\.|%20)
        # Keep matching until assignment, next variable, end of string or
        # start of an array
        [^=&\[]*
        /x',
		function ($key) use (&$keys) {
			$keys[] = $key = base64_encode(urldecode($key[0]));
			return urlencode($key);
		},
		$source
	);
	parse_str($source, $data);
	foreach ($data as $key => $val) {
		// Only unprocess encoded keys
		if (!in_array($key, $keys)) {
			$target[$key] = $val;
			continue;
		}

		$key = base64_decode($key);
		$target[$key] = $val;

		if ($keep) {
			// Keep a copy in the underscore key version
			$key = preg_replace('/(\.| )/', '_', $key);
			$target[$key] = $val;
		}
	}
}




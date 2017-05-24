<?php
// @TODO: restore caching of NBA field map!



include("ndabioresults.block.inc");


// Make module config globally available
require_once 'ndabioresults.config.inc';

// Initialize BioPortal client
// Can't get autoloader to work, problem with namespaces in Drupal 7?
$clientPath = DRUPAL_ROOT . '/library/bioportal-client/lib/nl/naturalis/bioportal/';
require_once $clientPath . 'Loader.php';

use nl\naturalis\bioportal\Client as Client;


function _initBioPortalClient () {
    $client = new Client();
    $client
    	->setNbaUrl(nbaBaseUrl())
    	->setNbaTimeout(10);
    return $client;
}

function _setClientService (&$client, $service) {
	if (strpos($service, '.') !== false) {
		$service = substr($service, 0, strpos($service, '.'));
	}
	return $client->{$service}();
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
        $client = _initBioPortalClient();
        $r = $client->all()->getFieldInfo();
        foreach ($r as $service => $json) {
            $nbaFieldTypes[$service] = _getOptimalOperators(json_decode($json));
        }
        unset($client);
        cache_set($cacheId, $nbaFieldTypes);
    }
    return $nbaFieldTypes;
}

/* Meer dan geo_shape en keyword hebben we voorlopig niet */
function _getOptimalOperators ($fields) {
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


function _getDistinctValues ($service, $nbaPath) {
    $client = _initBioPortalClient();
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
function _timeStampToDate ($v) {
    if (!empty($v)) {
        return date('Y-m-d', $v / 1000);
    }
    return null;
}


/**
 * Converts timestamp in milliseconds to year-month-day
 *
 * @param string $v
 * @return string
 */
function _dateTimeToDate ($v) {
    if (!empty($v)) {
        return date('Y-m-d', strtotime($v));
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


/**
 * Formats string between tags and optionally appends class
 *
 * @param string $input
 * @param string $tag
 * @param string $class
 * @return string
 */
function _wrap ($input, $tag = "div", $class = ""){
	$class = ($class == "" ? "": " class='$class'" );
	return "<$tag$class>$input</$tag>";
}

function _arrayColumnRecursive (array $haystack, $needle) {
    $found = [];
    array_walk_recursive($haystack, function($value, $key) use (&$found, $needle) {
        if ($key == $needle)
            $found[] = $value;
    });
    return $found;
}


function _prettyJson ($json) {
	return json_encode(json_decode($json), JSON_PRETTY_PRINT);
}

function _initDebug () {
	$_SESSION['nbaDebug'] = null;
}

function _addDebugMessage ($title = false, $message = false) {
	if ($title && $message) {
		// QuerySpec/Client is passed; use ->getQuerySpec()
		if (is_object($message) && method_exists($message, 'getQuerySpec')) {
			if (nbaDebugEncoded() == 1) {
				$message = $message->getQuerySpec(true);
			} else {
				$message = _prettyJson($message->getQuerySpec());
			}
		}
		// String is passed
		$_SESSION['nbaDebug'][$title] = $message;
	}
}

function _getDebug () {
	return $_SESSION['nbaDebug'];
}



/**
 * Sorts associative array based on another associative array
 *
 * From http://stackoverflow.com/questions/348410/sort-an-array-by-keys-based-on-another-array
 *
 * @param array $array
 * @param array $orderArray
 * @return array
 */
function _sortArrayByArray ($array, $orderArray) {
    $ordered = array();
    foreach ($orderArray as $key) {
        if (array_key_exists($key, $array)) {
            $ordered[$key] = $array[$key];
            unset($array[$key]);
        }
    }
    return $ordered + $array;
}


/**
 * Validates json
 *
 * @param boolean Valid?
 */
function _isValidJson ($string) {
	return is_object(json_decode($string));
}


/**
 * Formats number to English/Dutch systems
 *
 * Customized internationalisation to format number that only works for EN/NL
 *
 * @param int/string $n Input number
 * @return string Formatted number
 */
function _formatNumber ($n) {
	global $language;
	if ($language->language == 'nl') {
		return number_format($n, 0, ',', '.');
	}
	return number_format($n);
}


function _printOops () {
	return '<h1>' .t('Error'). '!</h1>' . _wrap(t('Oops, something went wrong') . '. ' .
		"<a href='" . setStartUrl() . "'>" . t('Back to home page') . '</a>.', 'p');
}

/**
 * Beautifies source output
 *
 * @param string $string
 * @return string
 */
function _markUp ($string){
	$result = $string;
	$result = preg_replace('/^\s+|\n|\r|\s+$/m', '', $result);
	
	$result = str_replace(
		array("    <h2",  "<table",        "<thead",      "<tbody",      "<tr",        "<td",        "<th ",   "<a class='polaroid'"),
		array("\n\n<h2","\n\n<table","\n\n\t<thead","\n\n\t<tbody","\n\t\t<tr","\n\t\t\t<td","\n\t\t\t<th ", "\n<a class='polaroid' "),
		$result
	);
	
	$result = str_replace(
		array(  "</table",    "</thead",    "</tbody",     "</tr",        "</td",        "</th>"),
		array("\n</table","\n\t</thead","\n\t</tbody","\n\t\t</tr","\n\t\t\t</td","\n\t\t\t</th>"),
		$result
	);
	
	return $result;
}


function _setArrayKeyFromValue ($array) {
	foreach ($array as $k => $v) {
		$output[$v] = $v;
	}
	return isset($output) ? $output : array();
}



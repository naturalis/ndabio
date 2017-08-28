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
    	->setNbaTimeout(nbaTimeout());
    return $client;
}

function _setClient ($service) {
	$client = _initBioPortalClient();
	$service = _normaliseServiceName($service);
	return $client->{$service}();
}

function _normaliseServiceName ($service) {
	if (strpos($service, '.') !== false) {
		return array_values(array_slice(explode('.', $service), -1))[0] == 'taxa' ? 
			'taxon' : 'specimen';
	}
	return $service;
}

function _getTimer ($start, $round = 2) {
	$time = round((microtime(true) - $start), $round);
	$time = $time == 0 ? '<0.01' : $time;
	return $time . 's';
}

function _setTimer () {
	return microtime(true);
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
			foreach (['CONTAINS', 'STARTS_WITH_IC', 'MATCHES', 'EQUALS_IC', 'EQUALS'] as $operator) {
				if (in_array($operator, $field->allowedOperators)) {
					$r[$path] = $field->type . ' | ' . $operator;
					break;
				}
			}
		}
	}
	return isset($r) ? $r : false;
}


function _stringToElements ($value) {
	return $value != '' ?
		array_map('trim', array_unique(array_filter(explode(' ', trim($value))))) : [null];	
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
function safe_parse_str ($source, &$target, $keep = false) {
	if (!$source) {
		return;
	}
	$keys = $target = [];
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
        if ($key == $needle) {
            $found[] = $value;
        }
    });
    return $found;
}


function _prettyJson ($json) {
	return json_encode(json_decode($json), JSON_PRETTY_PRINT);
}

function _init () {
	unset($_SESSION['nbaDebug']);
	$_SESSION['nbaDebug']['server'] = nbaBaseUrl();
	$_SESSION['nbaNameResolutionTaxa'] = null;
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



function _checkNbaVersion () {
	if (isset($_SESSION['nbaVersionCheck']) && $_SESSION['nbaVersionCheck'] == 'OK') {
		return true;
	}
	// Use checks here that are incompatible in older versions of the NBA
	$client = _initBioPortalClient();
	$settings = json_decode($client->getSettings());
	if (isset($settings->{'operator.CONTAINS.min_term_length'})) {
		$_SESSION['nbaVersionCheck'] = 'OK';
		return true;
	}
	echo '<p style="color: red; font-weight: bold;">Invalid version of NBA used! Use NBA v2.9 or higher. 
		<a href="##overlay=admin/config/naturalis/ndaresult">Modify the NBA base URL setting</a>.</p>';
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
        } else {
        	$ordered[$key] = null;
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


function _printOops ($message) {
	$output = '<h1>' .t('Error'). '!</h1>' . _wrap(t('Oops, something went wrong') . '. ' .
		"<a href='" . setStartUrl() . "'>" . t('Back to home page') . '</a>.', 'p');
	return $output;
}


function _getSourceNameBySourceCode ($code) {
	
//p(advancedSelects()); die();
	foreach (['t', 's', 'm'] as $prefix) {
		if (isset(advancedSelects()[$prefix . '_sourceSystem'][$code])) {
			return advancedSelects()[$prefix . '_sourceSystem'][$code];
		}
	}
	return false;
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


function _encodeReferrer ($data) {
	if (is_array($data)) {
		$data = http_build_query($data);
	}
 	return rtrim(strtr(base64_encode($data), '+/', '-_'), '='); 
} 

function _decodeReferrer ($data) { 
	return base64_decode(str_pad(strtr($data, '-_', '+/'), strlen($data) % 4, '=', STR_PAD_RIGHT)); 
} 

function _getCurrentUrl () {
	return ((isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] !== 'off') ? "https" : "http") . 
		"://$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]"; 
}

<?php
/**
 * Helper methods used by both BP modules
 */

// Make block and module config globally available
require_once "ndabioresults.block.inc";
require_once 'ndabioresults.config.inc';

// Initialize BioPortal client
require_once DRUPAL_ROOT . '/library/bioportal-client/lib/nl/naturalis/bioportal/Loader.php';

use nl\naturalis\bioportal\Client as Client;

/**
 * Set language
 */
function _setLanguage () {
    $langs = language_list(); // Note: No argument
    $langcode = isset($_GET["language"]) && !empty($_GET["language"]) ? $_GET["language"] : '';
    if (!empty($langcode)) {
        variable_set('language_default', $langs[$langcode]);
    }
}

/**
 * Initialise PHP client
 * 
 * @return \nl\naturalis\bioportal\Client
 */
function _initNbaClient () {
    $client = new Client();
    $client
    	->setNbaUrl(_nbaBaseUrl())
    	->setNbaTimeout(_nbaTimeout());
    return $client;
}


/**
 * Initialise PHP client with service (specimen, taxon, or multimedia)
 * 
 * @param string $service
 * @return \nl\naturalis\bioportal\Client
 */
function _setNbaClient ($service) {
	$client = _initNbaClient();
	$service = _normaliseServiceName($service);
	// Validate service name
	if (!in_array($service, $client::$nbaClients)) {
		_setErrorMessage($service . ' is not a valid NBA service!');
		return false;
	}
	return $client->{$service}();
}

/**
 * Normalise service name
 * 
 * Changes names.* service to valid NBA service name
 *   
 * @param unknown $service
 * @return string
 */
function _normaliseServiceName ($service) {
	if (strpos($service, '.') !== false) {
		return array_values(array_slice(explode('.', $service), -1))[0] == 'taxa' ? 
			'taxon' : 'specimen';
	}
	return $service;
}

/**
 * Start timer
 * 
 * @return float
 */
function _setTimer () {
	return microtime(true);
}

/**
 * End timer and get parsed time in seconds
 * 
 * @param float $start Unix timestamp with microseconds
 * @param number $round precision
 * @return string
 */
function _getTimer ($start, $round = 2) {
	$time = round((microtime(true) - $start), $round);
	$time = $time == 0 ? '<0.01' : $time;
	return $time . 's';
}

/**
 * Valid NBA paths per service, including "optimal operator" per path
 * 
 * Dynamically fetched (and cached) valid query paths in the NBA. The so-called
 * "optimal operator" is set for each path. This is the operator that fetches most
 * results, so CONTAINS > STARTS_WITH > MATCHES > EQUALS
 * 
 * @return array
 */
function _nbaFieldTypes () {
    $nbaFieldTypes = &drupal_static(__FUNCTION__);
    if (!$nbaFieldTypes) {
        $cacheId = 'nbaFieldTypes';
        $cache = cache_get($cacheId, 'cache'); 
        if ($cache && !empty($cache->data)) {
            $nbaFieldTypes = $cache->data;
            return $nbaFieldTypes;
        }
        $client = _initNbaClient();
        $r = $client->all()->getFieldInfo();
        foreach ($r as $service => $json) {
            $nbaFieldTypes[$service] = _getOptimalOperators(json_decode($json));
        }
        unset($client);
        cache_set($cacheId, $nbaFieldTypes);
    }
    return $nbaFieldTypes;
}

/**
 * Determines optimal operators for an NBA service based on NBA field type info
 * 
 * @param array $fields
 * @return array|boolean
 */
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

/**
 * Split string by space
 * 
 * Cleans up empty values and trims chunks
 * 
 * @param string $value
 * @return array|NULL[]
 */
function _stringToElements ($value, $stringSizeThreshold = false) {
	if ($value == '') {
		return [null];
	}
	$elements = array_map('trim', array_unique(array_filter(explode(' ', trim($value)))));
	if ($stringSizeThreshold) {
		foreach ($elements as $i => $element) {
			if (strlen($element) < (int)$stringSizeThreshold) {
				unset($elements[$i]);
			}
		}
	}
	return $elements;
}

/**
 * Gets distinct values for NBA query path
 * 
 * @param string $service
 * @param string $nbaPath
 * @return array
 */
function _getDistinctValues ($service, $nbaPath) {
    $client = _setNbaClient($service);
    try {
	    $values = array_keys(json_decode($client->getDistinctValues($nbaPath), true));
	    sort($values);
	    unset($client);
	    return $values;
    } catch (Exception $e) {
    	_setErrorMessage($e->getMessage());
    	return false;
    }
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
 * Converts datetime to year-month-day
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

/**
 * array_column() for a multi-dimensional array
 * 
 * @param array $haystack
 * @param string $needle
 * @return array
 */
function _arrayColumnRecursive (array $haystack, $needle) {
    $found = [];
    array_walk_recursive($haystack, function($value, $key) use (&$found, $needle) {
        if ($key == $needle) {
            $found[] = $value;
        }
    });
    return $found;
}

/**
 * Prettify json output
 * 
 * @param string $json
 * @return string
 */
function _prettyJson ($json) {
	return json_encode(json_decode($json), JSON_PRETTY_PRINT);
}

/**
 * Add debug message to stack
 * 
 * Input can be either simple message string or PHP client or query object. 
 * In case of the latter, the querySpec is extracted and printed as prettified
 * json or url-encoded string (can be set in module config).
 * 
 * @param string $title
 * @param string|object $message
 */
function _addDebugMessage ($title = false, $message = false) {
	if ($title && $message) {
		// QuerySpec/Client is passed; use ->getQuerySpec()
		if (is_object($message) && method_exists($message, 'getQuerySpec')) {
			if (_nbaDebugEncoded() == 1) {
				$message = $message->getQuerySpec(true);
			} else {
				$message = _prettyJson($message->getQuerySpec());
			}
		}
		// String is passed
		$_SESSION['nbaDebug'][$title] = $message;
	}
}

/**
 * Get debug messages
 * 
 * @return array Debug stack
 */
function _getDebug () {
	return $_SESSION['nbaDebug'];
}

/**
 * Checks if NBA version can be used
 * 
 * This method should contain the NBA statement(s) that are required for the current version
 * (in this case 'operator.contains.min_term_length', which previously was 
 * 'operator.LIKE.min_term_length'; the latter would return an error).
 * 
 * @return boolean|string String in case wrong version is used
 */
function _checkNbaVersion () {
	if (isset($_SESSION['nbaVersionCheck']) && $_SESSION['nbaVersionCheck'] == 'OK') {
		return true;
	}
	// Use checks here that are incompatible in older versions of the NBA
	if (isset(_nbaMaxResultWindow()['taxon'])) {
		$_SESSION['nbaVersionCheck'] = 'OK';
		return true;
	}
	echo '<p style="color: red; font-weight: bold;">Invalid version of NBA used! Use NBA v2.11 or higher. 
		<a href="#overlay=admin/config/naturalis/ndaresult">Modify the NBA base URL setting</a>.</p>';
}

/**
 * Ping NBA to set _nbaIsUp()
 */
function _checkIfNbaIsUp () {
	$client = _initNbaClient();
	if (!$client->ping()) {
		// echo down;
	}
}

/**
 * Sorts associative array based on another associative array
 *
 * Adapted from http://stackoverflow.com/questions/348410/sort-an-array-by-keys-based-on-another-array
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

/**
 * Prints a fine oops message
 * 
 * If any errors have been set these are printed as well
 * 
 * @return string
 */
function _printOops () {
	$output = '<h1>' .t('Error'). '!</h1><p>';
	if (_getErrorMessage()) {
		$output .= _getErrorMessage() . "</p>\n<p>";
	}
	$output .= t('Oops, something went wrong') . '. ' .
		"<a href='" . _setStartUrl() . "'>" . t('Back to home page') . '</a>.</p>';
	return $output;
}

/**
 * Gets NBA source.name for associated source.code
 * 
 * Uses the advanced form that has been set already, very economical!
 * 
 * @param unknown $code
 * @return string|boolean
 */
function _getSourceNameBySourceCode ($code) {
	
//p(_advancedSelects()); die();
	foreach (['t', 's', 'm'] as $prefix) {
		if (isset(_advancedSelects()[$prefix . '_sourceSystem'][$code])) {
			return _advancedSelects()[$prefix . '_sourceSystem'][$code];
		}
	}
	return false;
}

/**
 * Get error message from stack
 * 
 * @return boolean|string
 */
function _getErrorMessage () {
	return isset($_SESSION['nbaErrorMessage']) ? $_SESSION['nbaErrorMessage'] : false;
}

/**
 * Add error message to stack
 */
function _setErrorMessage ($message) {
	$_SESSION['nbaErrorMessage'] = $message;
}

/**
 * Beautifies source output
 * 
 * If it makes Maarten van der Velde happy, why not?
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

/**
 * Encode terms in url safe string
 * 
 * @param string|array $terms
 * @return string
 */
function _encodeReferrer ($terms) {
	if (is_array($terms)) {
		$terms = safe_http_build_query($terms);
	}
 	return rtrim(strtr(base64_encode($terms), '+/', '-_'), '='); 
} 

/**
 * Decode string encoded with _encodeReferrer()
 * 
 * @param string $referrer
 * @return string
 */
function _decodeReferrer ($referrer) { 
	return base64_decode(str_pad(strtr($referrer, '-_', '+/'), strlen($referrer) % 4, '=', STR_PAD_RIGHT)); 
} 

/**
 * Gets current url
 * 
 * @return string
 */
function _getCurrentUrl () {
	return ((isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] !== 'off') ? "https" : "http") . 
		"://$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]"; 
}

/**
 * Check if a string is valid JSON
 * 
 * @param string
 * @return boolean
 */
function _isJson ($string) {
  json_decode($string);
  return (json_last_error() == JSON_ERROR_NONE);
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
 * Helper alternative to http_build_query that allows for null values
 * 
 * http_build_query discards parameters with null values, which is not what we want!
 * 
 * @param array $args
 * @return string
 */
function safe_http_build_query ($args) {
	foreach ($args as $k => $v) {
		if (is_null($v)) {
			$args[$k] = '';
		}
	}
	return http_build_query($args);
}

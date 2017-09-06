<?php 









/**
 * Distributes search parameter of the simple search to appropiate services and returns
 * formatted output
 *
 * Retrieves search parameters from SESSION set by ndabioresults_pass, set to
 * the appropriate channels and returns formatted result
 *
 * @return string Formatted output
 */
function nbaSimpleSearch () {

    return 'Not so fast...';

    $pageHeader = '';
    $p['_search'] = $_SESSION['nbaSearch']['term'];

    // Taxon search does not include geoShape and should not be invoked when coming from geo form
    // when a search are has been entered
    if (!isset($_SESSION['nbaSearch']['gid']) || empty($_SESSION['nbaSearch']['gid']) &&
        empty($_SESSION['nbaSearch']['geoShape'])) {
        $services[taxonService()] = $p;
    }

    // Other searches do include geoShape if entered
    if (isset($_SESSION['nbaSearch']['geoShape']) && !empty($_SESSION['nbaSearch']['geoShape'])) {
        $p['_geoShape'] = $_SESSION['nbaSearch']['geoShape'];

        $area =  (!empty($_SESSION['nbaSearch']['location']) ? $_SESSION['nbaSearch']['location'] :
            t('area drawn on map'));

        $pageHeader =
            _wrap(
                _wrap(
                    t("Showing only results in")
                   . " "
                   . _wrap($area, "span", "term"),
                   "h1"
                ), "div", "panel"
            );
    };

    $pageHeader .= _wrap(t('Search results for') . ' ' .
        _wrap($_SESSION['nbaSearch']['term'], "span", "term"), "H1");

    $services[specimenNamesService()] = $p;
    $services[multimediaService()] = $p;
    $services[specimenService()] = $p;

    // Set session with NBA query type;
    // used to determine if show all should be printed
    unset($_SESSION['nbaFilters']);
    $_SESSION['nbaRequestType'] = 'form';
    $_SESSION['nbaPageDetail'] = 'result from simple form';

    $pageBody = performNdaRequest(setChannels($services));

    return $pageHeader . (!empty($pageBody) ? $pageBody : '<p>' . printNoResults() . '</p>');
}








/* The old stuff */




/**
 * Mapping function: distributes parameters to appropriate specimen service
 *
 * Distributes specimens search parameters between specimen and specimen name
 * services. Important: list of parameters should be complete!
 *
 * @param array $sP Search parameters
 * @param string $type Service type
 *
 * @return array Reduced array of search criteria for the service of choice
 */
function setSpecimenParameters (array $sP, $type) {
    $parameters = array(
        specimenService() => array(
            'collectingStartDate',
            'collectionFieldNumber',
            'collectorsFieldNumber',
            'gatheringAgent',
            'localityText',
            'phaseOrStage',
            'unitID',
            'sex',
            'taxonomicStatus',
            'typeStatus',
            'sourceSystem',
            'collectionType',
            '_geoShape'
        ),
        specimenNamesService() => array(
            'className',
            'family',
            'genusOrMonomial',
            'kingdom',
            'order',
            'phylum',
            'specificEpithet',
            'infraspecificEpithet',
            'vernacularName',
            '_geoShape',
            '_showMap',
            'scientificName'
        )
    );
    foreach ($parameters[$type] as $p) {
        if (isset($sP[$p]) && (!empty($sP[$p]) || is_numeric($sP[$p]))) {
            $d[$p] = $sP[$p];
        }
    }
    // If any parameters are found, append andOr and geoShape (if applicable)
    if (isset($d)) {
        $d['_andOr'] = $sP['_andOr'];
        if (!empty($sP['geoShape'])) {
            $d['_geoShape'] = $sP['geoShape'];
        }
    }
    return isset($d) ? $d : null;
}

/**
 * Accepts search form data and returns formatted result
 *
 * The main function that actually processes the incoming POST data, stores the
 * POST data in a SESSION, distributes the search to the appropriate channels
 * and returns the formatted output.
 *
 * Headers were added to avoid problems with "Webpage has expired" in IE after
 * hitting back button
 *
 * @return string The formatted output

function ndabioresults_pass ($args = "") {
    global $base_path;
    $langs = language_list(); // Note: No argument
    $langcode = isset($_GET["language"]) && !empty($_GET["language"]) ? $_GET["language"] : '';
    if (!empty($langcode)) {
        variable_set('language_default', $langs[$langcode]);
    }

    // SESSION variables that have to be reset for each request
    unset($_SESSION['nbaPageTitle']);

    // Keep track of NBA search history
    if (isset($_GET['nba_request']) || isset($_GET['form_id']) || isset($_GET['back'])
        || isset($_GET['theme'])) {
        // Add direct requests to history if they are search service requests...
        if (isset($_GET['nba_request']) && isSearchService(urldecode($_GET['nba_request']))) {
             $_SESSION['nbaHistory'][] = $_GET['nba_request'];
        // ... or from the search form of course
        } else if (isset($_GET['form_id'])) {
            $_SESSION['nbaHistory'][] = 'form';
        // ... or from a menu link to a theme
        } else if (isset($_GET['theme'])) {
            $_SESSION['nbaHistory'][] = 'theme';
            // If coming from a back link itself, remove the link from history
        } else if (isset($_GET['back']) && isSearchService($_SESSION['nbaCurrentService'])) {
            array_pop($_SESSION['nbaHistory']);
        }
    }

    drupal_add_http_header('Expires', 'Sat, 01 Jan 2000 00:00:00 GMT');
    drupal_add_http_header('Last-Modified', gmdate("D, d M Y H:i:s") . ' GMT');
    drupal_add_http_header('Cache-Control', 'post-check=0, pre-check=0');
    session_cache_limiter("must-revalidate");
    drupal_add_js("var str_base_path = '$base_path' ", 'inline');

    // Thematic search
    if (isset($_GET['theme']) && !empty($_GET['theme'])) {
        unset($_SESSION['nbaSearch']);
        $_SESSION['nbaSearch']['theme'] = $_GET['theme'];
        return ndaThematicSearch();
    }

    // Back link clicked. Check search history to see if user comes from search form
    // or from paginated result set. If the latter, use history to navigate; else
    // proceed as if POST data was received but retrieve this from SESSION
    if (isset($_GET['back']) && isset($_SESSION['nbaSearch']) && !empty($_SESSION['nbaSearch'])) {
       drupal_set_title(t("Search results"));

       $lastSearch = isset($_SESSION['nbaHistory']) && !empty($_SESSION['nbaHistory']) ?
            end($_SESSION['nbaHistory']) : false;
       if ($lastSearch && $lastSearch != 'form' && $lastSearch != 'theme') {
            return ndaDirectRequest(end($_SESSION['nbaHistory']));
        } else if (!empty($_SESSION['nbaSearch']['term'])) {
            return ndaSimpleSearch();
        } else if (!empty($_SESSION['nbaSearch']['theme'])) {
            return ndaThematicSearch();
        } else {
            return ndaAdvancedSearch();
        }
    }

    // POST data from the search form?
    // If so, add to SESSION or replace existing SESSION data
    if (isset($_GET['form_id']) && $_GET['form_id'] == 'ndabio_advanced_taxonomysearch') {
        drupal_set_title(t("Search results"));

        $_SESSION['nbaSearch'] = $_GET;
        logSearch();
        return empty($_SESSION['nbaSearch']['term']) ? ndaAdvancedSearch() : ndaSimpleSearch();
    }

    // GET data from within NDA response?
    // Forward directly to appropriate service
    else if (isset($_GET['nba_request'])) {
        // @todo: check direct url for injection?
        return ndaDirectRequest(urldecode($_GET['nba_request']));
    }

    // If both POST and SESSION are empty we have a problem...
    else {
        // Probably best to redirect gracefully to search page?
        handleError('No POST data received! Form validation should trap this.
            Redirect to home if this occurs?');
        drupal_goto('');
    }
}
*/
    
    

/**
 * Distributes search parameter of the simple search to appropiate services and returns
 * formatted output
 *
 * Retrieves search parameters from SESSION set by ndabioresults_pass, set to
 * the appropriate channels and returns formatted result
 *
 * @return string Formatted output

function ndaSimpleSearch () {

    $pageHeader = '';
    $p['_search'] = $_SESSION['nbaSearch']['term'];

    // Taxon search does not include geoShape and should not be invoked when coming from geo form
    // when a search are has been entered
    if (!isset($_SESSION['nbaSearch']['gid']) || empty($_SESSION['nbaSearch']['gid']) &&
        empty($_SESSION['nbaSearch']['geoShape'])) {
        $services[taxonService()] = $p;
    }

    // Other searches do include geoShape if entered
    if (isset($_SESSION['nbaSearch']['geoShape']) && !empty($_SESSION['nbaSearch']['geoShape'])) {
        $p['_geoShape'] = $_SESSION['nbaSearch']['geoShape'];

        $area =  (!empty($_SESSION['nbaSearch']['location']) ? $_SESSION['nbaSearch']['location'] :
            t('area drawn on map'));

        $pageHeader =
            _wrap(
                _wrap(
                    t("Showing only results in")
                   . " "
                   . _wrap($area, "span", "term"),
                   "h1"
                ), "div", "panel"
            );
    };

    $pageHeader .= _wrap(t('Search results for') . ' ' .
        _wrap($_SESSION['nbaSearch']['term'], "span", "term"), "H1");

    $services[specimenNamesService()] = $p;
    $services[multimediaService()] = $p;
    $services[specimenService()] = $p;

    // Set session with NBA query type;
    // used to determine if show all should be printed
    unset($_SESSION['nbaFilters']);
    $_SESSION['nbaRequestType'] = 'form';
    $_SESSION['nbaPageDetail'] = 'result from simple form';

    $pageBody = performNdaRequest(setChannels($services));

    return $pageHeader . (!empty($pageBody) ? $pageBody : '<p>' . printNoResults() . '</p>');
}
*/

/**
 * Distributes search parameters of the advanced search to appropiate services and returns
 * formatted output
 *
 * Retrieves search parameters from SESSION set by ndabioresults_pass, set to
 * the appropriate channels and returns formatted result
 *
 * @return string Formatted output

function ndaAdvancedSearch () {

    $pageHeader = '';

    unset($_SESSION['nbaFilters']);
    $services[multimediaService()] = _setSectionParameters($_SESSION['nbaSearch'], 'm_');
    $services[taxonService()] = _setSectionParameters($_SESSION['nbaSearch'], 't_');
    $services[specimenService()] = _setSectionParameters($_SESSION['nbaSearch'], 's_');
    $services[specimenNamesService()] = _setSectionParameters($_SESSION['nbaSearch'], 'n_');

    // Special case for specimen/search: unset this service if only geoShape is present;
    // results of specimen/name-search and specimen/search will then be identical
    if (!serviceUsed($services[specimenService()])) {
        unset($services[specimenService()]);
    }

    // Another check: specimen/search is used but specimen/name-search is not
    if (isset($services[specimenService()]) && !serviceUsed($services[specimenNamesService()])) {
        unset($services[specimenNamesService()]);
    }

    // Now check if either multimedia or specimen has search parameters
    // If so, unset the "empty" service; if not, pass both
    if (!serviceUsed($services[specimenNamesService()]) && serviceUsed($services[multimediaService()])) {
        unset($services[specimenNamesService()]);
    } else if (serviceUsed($services[specimenNamesService()]) && !serviceUsed($services[multimediaService()])) {
        unset($services[multimediaService()]);
    }

    if (isset($_SESSION['nbaSearch']['geoShape']) && !empty($_SESSION['nbaSearch']['geoShape'])) {
        $area =  (!empty($_SESSION['nbaSearch']['location']) ?
            $_SESSION['nbaSearch']['location'] : t('area drawn on map'));

        $pageHeader =
            _wrap(
                _wrap(
                    t("Showing only results in")
                   . " "
                   . _wrap($area, "span", "term"),
                   "h1"
            ), "div", "panel"
        );
    }
    $pageHeader .= _wrap(t('Search results'),"H1");


    // Test if anything has been posted; if not return with error message
    if (!dataPosted($services)) {
        return $pageHeader. _wrap(t('Oops, something went wrong') . '. ' .
            "<a href='" . setStartUrl() . "'>" . t('Back to home page') . '</a>.', 'p');
    }

    // Set session with NBA query type;
    // used to determine if show all should be printed
    $_SESSION['nbaRequestType'] = 'form';
    $_SESSION['nbaPageDetail'] = 'result from advanced form';

    $pageBody = performNdaRequest(setChannels($services));

    return $pageHeader . (!empty($pageBody) ? $pageBody : '<p>' . printNoResults() . '</p>');
}
*/

/**
 * Sets url to search form
 *
 * Used to create links back to search form; differentiates between home and
 * geographic search page
 *
 * @return string Url to last used form
 */
function setStartUrl () {
    if (isset($_SESSION['nbaSearch']['geoShape'])) {
        return setBasePath() . "geographic-search/";
    }
    return setBasePath();
}

/**
 * Sets base url
 *
 * Sometimes Drupal home is not accessible at the site root; this function returns the
 * base of of the Drupal installation
 *
 * @return string Url to Drupal root
 */
function setBasePath () {
    global $base_root, $base_path;
    return $base_root . $base_path;
}
    
/**
 * Performs thematic search
 *
 * For thematic search, two services are called: multimedia and specimen.
 * Currenty this service simply returns the search results. However, it is
 * already more or less ready to be used as an additional filter to the search form
 *
 * @return string Formatted result page
 */
function ndaThematicSearch () {

    unset($_SESSION['nbaFilters']);
    $services[multimediaService()] = _setSectionParameters($_SESSION['nbaSearch'], 'm_');
    $services[specimenService()] = _setSectionParameters($_SESSION['nbaSearch'], 's_');

    $services[multimediaService()]['theme'] = $_SESSION['nbaSearch']['theme'];
    // Sort multimedia by specimen name
    $services[multimediaService()]['_sort'] = 'identifications.scientificName.fullScientificName';
    $services[multimediaService()]['_sortDirection'] = 'ASC';

    $services[specimenService()]['theme'] = $_SESSION['nbaSearch']['theme'];
    // Sort specimens by registration number
    $services[specimenService()]['_sort'] = 'unitID';
    $services[specimenService()]['_sortDirection'] = 'ASC';

    $pageHeader = '';
    ctools_class_add(array('thematic-search'));

    // Test if anything has been posted; if not return with error message
    if (!dataPosted($services)) {
        return $pageHeader. _wrap(t('Oops, something went wrong') . '. ' .
            "<a href='" . setStartUrl() . "'>" . t('Back to home page') . '</a>.', 'p');
    }

    // Set session with NBA query type;
    // used to determine if show all should be printed
    $_SESSION['nbaRequestType'] = 'form';
    $_SESSION['nbaPageDetail'] = 'result from thematic search';

    // We have to override the default sort and sort direction for thematic search
    // Add true flag to setChannels()
    $pageBody = performNdaRequest(setChannels($services, true));

    return $pageHeader . (!empty($pageBody) ? $pageBody : '<p>' . printNoResults() . '</p>');
}

/**
 * Performs direct request
 *
 * Takes request from url as input, redirects this to the appropriate
 * service and returns formatted html.
 *
 * @param string $r Request url
 * @return string|void (empty array) Formatted output
 */
function ndaDirectRequest ($r) {
    foreach (serviceToFunctions() as $service => $d) {
        if (strpos($r, $service) !== false) {
            $url = parse_url($r);
            //parse_str($url['query'], $q);
            safe_parse_str($url['query'], $q);

            // Cap maxResults to max
            if (!isset($q['_maxResults']) || $q['_maxResults'] > maxResults()) {
                $q['_maxResults'] = isGroupService($service) ? maxGroupResults() : maxResults();
            }

            // Special case for specimens on map: remove _sort and _offset
            if (isset($q['_showMap'])) {
                unset($q['_sort'], $q['_offset']);
            }

            // Set geoShape from SESSION if geoShape is part of the request
            if (isset($q['_geoShape']) && $q['_geoShape'] == '[session]' &&
                isset($_SESSION['nbaStoredGeoShape'])) {
                $q['_geoShape'] = $_SESSION['nbaStoredGeoShape'];
            }

            $channels[0]['request'] = $service;
            $channels[0]['url'] = nbaBaseUrl() . $service;
    		$channels[0]['method'] = $d['method'];
    		// If ES request parameter contains dots, these should be replaced with @ and reverted to
    		// dots at this point
    		$channels[0]['postfields'] = http_build_query($q);
    		// Set session variable with last used service;
            // used to determine current detail page
            $_SESSION['nbaCurrentService'] = $service;
            // Set session with NBA query type;
            // used to determine if show all should be printed
            $_SESSION['nbaRequestType'] = 'url';
            // Set session with info about current page;
            // used to set appropriate blocks
            $_SESSION['nbaPageDetail'] = $d['info'];

            return performNdaRequest($channels);
        }
    }
    return array();
}

/**
 * Dedicated service to use for Ajax request
 *
 * Takes request url, redirects to the appropriate service and returns
 * unformatted NBA json
 *
 * @param string $r Request url
 * @param string $maxResults Optional max results
 * @return json|void
 */
function ndaAjaxRequest ($r, $maxResults = false) {
    foreach (serviceToFunctions() as $service => $d) {
        if (strpos($r, $service) !== false) {
            $url = parse_url($r);
            safe_parse_str($url['query'], $q);

            if ($maxResults && is_int($maxResults) && $maxResults <= maxResults()) {
                $q['_maxResults'] = $maxResults;
            }

            $channels[0]['request'] = $service;
    		$channels[0]['url'] = nbaBaseUrl() . $service;
    		$channels[0]['method'] = $d['method'];
    		$channels[0]['postfields'] = str_replace('%40', '.', http_build_query($q));
            return queryNda($channels);
        }
    }
    return null;
}



/**
 * Sets curl channels
 *
 * Sets request and url parameters for curl channels
 *
 * @param array Service array (service name => search parameters)
 * @return array|void Channels for curl
 */
function setChannels (array $services, $overrideDefault = false) {
    $i = 0;
    $serviceSettings = serviceToFunctions();
	foreach ($services as $s => $p) {
	    if (!empty($p)) {
	        $p = array_filter($p, 'strlen');

	        // Append default search parameters for form
	        $p['_maxResults'] = maxResultsInitial();
	        // Allow override for default sort and sort direction
	        // for special cases (thematic search)
	        if (!$overrideDefault) {
    	        $p['_sort'] = defaultSort();
    	        $p['_sortDirection'] = defaultSortDirection();
	        }

	        $channels[$i]['request'] = $s;
    		$channels[$i]['url'] = nbaBaseUrl() . $s;
    		$channels[$i]['method'] = $serviceSettings[$s]['method'];
    		$channels[$i]['postfields'] =  http_build_query($p);
    		$i++;
	    }
	}
	return isset($channels) ? $channels : array();
}



/**
 * Performs curl requests and formats results
 *
 * Performs curl queries through multicurl. For each channel, resulting json is
 * parsed to an array by one function and subsequently printed by another.
 *
 * @param array $channels Service channels
 * @return string|void
 */
function performNdaRequest (array $channels = array()) {
	if (empty($channels)) {
		handleError('Cannot set curl channels');
	}
	// Get json response(s) with curl
	$remoteData = queryNda($channels);
	// Reorder responses in print order if more than one response
	if (count($remoteData) > 1) {
	   $remoteData = sortArrayByArray($remoteData, resultOrder());
	}
	// Map functions to each channel result:
	// parses and prints data
	$output = '';
	$serviceToFunctions = serviceToFunctions();
	foreach ($remoteData as $service => $json) {
		if (!isset($serviceToFunctions[$service]) || empty($json)) {
			continue;
		}
		$parseFunction = isset($serviceToFunctions[$service]['parse']) ?
		    $serviceToFunctions[$service]['parse'] : false;
		$printFunction = isset($serviceToFunctions[$service]['print']) ?
		    $serviceToFunctions[$service]['print'] : false;
		if (!empty($parseFunction) && !empty($printFunction)) {
		    $output .= $printFunction($parseFunction($json));
		}
	}

    // Debug: print queries
    if (DEBUG_CHANNELS == 1) {
        p($channels);
    }

	return $output;
}

/**
 * Performs multicurl queries
 *
 * Core function for multicurl requests
 *
 * @param unknown $channels Service channels
 * @param integer $timeout Optional timeout
 *
 * @return array Results as key => value pairs for each channel
 */
function queryNda ($channels = array(), $timeout = false) {
    $mh = curl_multi_init();
    for ($i = 0; $i < count($channels); $i++) {
        $ch[$i] = curl_init();

        if ($channels[$i]['method'] == 'post') {
            curl_setopt($ch[$i], CURLOPT_URL, $channels[$i]['url']);
            curl_setopt($ch[$i], CURLOPT_POST, true);
			curl_setopt($ch[$i], CURLOPT_HTTPHEADER, array('Expect:'));
            curl_setopt($ch[$i], CURLOPT_POSTFIELDS, $channels[$i]['postfields']);
        } else if ($channels[$i]['method'] == 'get') {
            $channels[$i]['url'] .= '/?'  . $channels[$i]['postfields'];
            curl_setopt($ch[$i], CURLOPT_URL, $channels[$i]['url']);
        }

        curl_setopt($ch[$i], CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch[$i], CURLOPT_HEADER, false);
        if ($timeout) {
       		curl_setopt($ch[$i], CURLOPT_TIMEOUT, $timeout);
        }
        curl_multi_add_handle($mh, $ch[$i]);
    }
    // While we're still active, execute curl
	do {
		$mrc = curl_multi_exec($mh, $active);
	} while ($mrc == CURLM_CALL_MULTI_PERFORM);

    while ($active && $mrc == CURLM_OK) {
        // Wait for activity on any curl-connection
        if (curl_multi_select($mh) == -1) {
            usleep(1);
        }
        // Continue to exec until curl is ready to
        // give us more data
        do {
            $mrc = curl_multi_exec($mh, $active);
        } while ($mrc == CURLM_CALL_MULTI_PERFORM);
    }
    // Place results in results array and close handlers
    for ($i = 0; $i < count($channels); $i++) {
        $remoteData[$channels[$i]['request']] = curl_multi_getcontent($ch[$i]);
        curl_multi_remove_handle($mh, $ch[$i]);
    }
    curl_multi_close($mh);
    return $remoteData;
}



/**
 * NSR id of a taxon
 *
 * @param array $data NBA json response
 * @return int|void ID of NRS taxon record
 */
function getTaxonId ($data) {
    foreach ($data->searchResults as $row) {
        if ($row->result->sourceSystem->code == 'NSR') {
            return $row->result->sourceSystemId;
        }
    }
    return null;
}


/**
 * Strips base url from string
 *
 * @param string $url
 * @return string $url Stripped url
 */
function stripBaseUrl ($url) {
    return str_replace(urlencode(nbaBaseUrl()), '', $url);
}


/**
 * Reverses setUnitId()
 *
 * @param string $string Unit id to "decode"
 * @return string $string
 */
function unsetUnitId ($string) {
    return str_replace('&nbsp;', ' ', $string);
}



/**
 * Gets sort direction
 *
 * Gets sort direction parameter from self link or, if self link is not provided,
 * returns default value
 *
 * @param string $self Self link
 * @param boolean $groupResult Service has grouped results?
 * @return string Result from self link or default value if self link is not provided
 */
function getSortDirection ($self, $groupResult = false) {
    $p = $groupResult ? '_groupSortDirection' : '_sortDirection';
    if (!empty($self)) {
        $value = getUrlParValue(urldecode($self), $p);
        if (!empty($value)) {
            return $value;
        }
    }
    return $groupResult ? defaultGroupSortDirection() : defaultSortDirection();
}

/**
 * Sets sort url
 *
 * @param string $column Field to sort on
 * @param string $dir Default sort direction for column
 * @param string $self Self link
 * @param boolean $groupResult Service has grouped results?
 * @return string Url
 */
function setSortUrl ($column, $dir, $self, $groupResult = false) {

    // Set parameters differently for default or grouped results
    $offset = $groupResult ? '_groupOffset' : '_offset';
    $sort = $groupResult ? '_groupSort' : '_sort';
    $sortDirection = $groupResult ? '_groupSortDirection' : '_sortDirection';

    // Column currently selected; only switch sort direction
    if ($column == getSort($self, $groupResult)) {
        return setUrlPars(
            geoShapeToSession($self, true),
            array(
                $sortDirection => getSortDirection($self, $groupResult) == 'DESC' ? 'ASC' : 'DESC',
                $offset => 0
            ),
            true
        );
    }
    // Other column is currently selected; set to current column in default direction
    return setUrlPars(
        geoShapeToSession($self, true),
        array(
            $sort => $column,
            $sortDirection => $dir,
            $offset => 0
        ),
        true
    );
}

/**
 * Paginator
 *
 * Returns html-formatted paginator based on json input. $groupResult is used to
 * differentiate between regular or grouped services.
 *
 * @param unknown $data Parsed json
 * @param boolean $groupResult Regular or grouped service?
 * @return Html-formatted paginator | void
 */
function getPaginator ($data) {
    if (isset($_SESSION['nbaRequestType']) && $_SESSION['nbaRequestType'] != 'form') {
        $paginator = new Paginator(
            getTotalRows($data),
            setPaginatorItemsPerPage($groupResult),
            setPaginatorCurrentPage($data, $groupResult),
            setPaginatorUrl($data, $groupResult)
        );
        return $paginator->toHtml();
    }
    return null;
}

/**
 * Special case: paginator used for results within grouped results
 *
 * A modified function for getPaginator for results within a grouped result. The problem
 * was that the $groupedResult flag in that function cannot be used, because getTotalRows
 * would need to differentiate to accept the results of a group or within a group
 * (for services that returned grouped results). Instead of introducing a potentialy
 * confusing third parameter, this special case function handles the paginator for results
 * within a grouped result.
 *
 * @param array $data Json
 * @return Formatted html|void
 */
function getPaginatorWithinGroup ($data) {
    if (isset($_SESSION['nbaRequestType']) && $_SESSION['nbaRequestType'] != 'form') {
        $paginator = new Paginator(
            getTotalRowsWithinGroup($data),
            setPaginatorItemsPerPage(),
            setPaginatorCurrentPage($data),
            setPaginatorUrl($data)
        );
        return $paginator->toHtml();
    }
    return null;
}

/**
 * Sets maximum number of results per page for paginator
 *
 * @param boolean $groupResult Regular or grouped service?
 * @return int Maximum number of results per page dependent of grouped or not
 */
function setPaginatorItemsPerPage ($groupResult = false) {
    return $groupResult ? maxGroupResults() : maxResults();
}

/**
 * Sets current page number for paginator
 *
 * @param boolean $groupResult Regular or grouped service?
 * @return int Current page number dependent of grouped or not
 */
function setPaginatorCurrentPage ($data, $groupResult = false) {
    return $groupResult ?
        getGroupOffset($data) / maxGroupResults() + 1 :
        getOffset($data) / maxResults() + 1;
}

/**
 *
 * Sets url for paginator
 *
 * Strips offset from self link and replaces this with placeholder for paginator
 *
 * @param array $data Json
 * @param boolean $groupResult
 * @return string Url
 */
function setPaginatorUrl ($data, $groupResult = false) {
    $offset = $groupResult ? 'groupOffset' : 'offset';
    return printDrupalLink(
        stripOffsetFromUrl(geoShapeToSession(urldecode(getSelfLink($data)))) . '&_' . $offset . '='
    ) . '(:num)';
}

/**
 * Adds or replaces parameters in url with new parameters
 *
 * @param string $url Input url
 * @param array $newValues New values as key => value pairs
 * @param boolean $decodeEncode Decode url before replacement?
 * @return string $url Output string
 */
function setUrlPars ($url, array $newValues, $decodeEncode = false) {
    if ($decodeEncode) {
        $url = urldecode($url);
    }
    $parts = parse_url($url);
    safe_parse_str($parts['query'], $q);
    foreach ($newValues as $p => $v) {
        $q[$p] = $v;
    }
    $parts['query'] = http_build_query($q);
    $url = reverse_parse_url($parts);
    return $decodeEncode ? urlencode($url) : $url;
}

/**
 *  Replaces the value of the _geoShape parameter from any NBA-created url with [session].
 *  Stores the value in a session parameter, which should be retrieved when creating the NBA request.
 *
 * @param string $url
 * @return string, session parameter
 */
function geoShapeToSession ($url, $decodeEncode = false) {
    if ($decodeEncode) {
        $url = urldecode($url);
    }
    $parts = parse_url($url);
    safe_parse_str($parts['query'], $q);
    if (isset($q['_geoShape'])) {
        $_SESSION['nbaStoredGeoShape'] = $q['_geoShape'];
        $q['_geoShape'] = '[session]';

        $parts['query'] = http_build_query($q);
        $url = reverse_parse_url($parts);
    }
    return $decodeEncode ? urlencode($url) : $url;
}

/**
 * Strips _offset and _groupOffset from url
 *
 * @param string $url Input url
 * @param string $decodeEncode Decode url before replacement?
 * @return string $url Output url
 */
function stripOffsetFromUrl ($url, $decodeEncode = false) {
    if ($decodeEncode) {
        $url = urldecode($url);
    }
    $parts = parse_url($url);
    safe_parse_str($parts['query'], $q);
    foreach (array('_offset', '_groupOffset') as $p) {
        if (isset($q[$p])) {
            unset($q[$p]);
        }
    }
    $parts['query'] = http_build_query($q);
    $url = reverse_parse_url($parts);
    return $decodeEncode ? urlencode($url) : $url;
}

/**
 * Gets value for specified parameter in url
 *
 * @param string $url Input utl
 * @param string $par Parameter to get value for
 * @return string|void Value
 */
function getUrlParValue ($url, $par) {
    if ($url != '' && $par != '') {
        $parts = parse_url($url);
        if (!empty($parts)) {
            safe_parse_str($parts['query'], $q);
            foreach ($q as $p => $v) {
                if ($p == $par) {
                    return $v;
                }
            }
        }
    }
    return false;
}

/**
 * Gets self link for current request
 *
 * Rather straightforward if the result is from a GET request. If the result is from
 * a POST request, the self link has to be reconstructed from the search terms in
 * the request.
 *
 * @param array $data Json
 * @return string|void Self link
 *
 */function getSelfLink ($data) {
    if (isset($data->links) && !empty($data->links)) {
        foreach ($data->links as $link) {
            if ($link->rel == '_self') {
                $self = $link->href;
                break;
            }
        }
    }
    if (!isset($self) || empty($self)) {
        return false;
    }
    // If data is returned from a POST request, we have to recompile the
    // self link from the search terms...
    $post = strpos(urldecode($self), '?') === false ? true : false;
    if ($post) {
        $p = '/?';
        foreach (getSearchTerms($data) as $k => $v) {
            $p .= $k . '=' . $v[0] . '&';
        }
        return $self . urlencode(substr($p, 0, -1));
    }
    return $self;
}



/**
 * Reassembles parsed url
 *
 * Function from php.net to reverse parse_url:
 * http://php.net/manual/en/function.parse-url.php#106731
 * Replacement for http_build_url() because that function requires PECL.
 *
 * @param array $parsed_url Url components
 * @return string Reassembled url
 */
function reverse_parse_url ($parsed_url) {
    $scheme = isset($parsed_url['scheme']) ? $parsed_url['scheme'] . '://' : '';
    $host = isset($parsed_url['host']) ? $parsed_url['host'] : '';
    $port = isset($parsed_url['port']) ? ':' . $parsed_url['port'] : '';
    $user = isset($parsed_url['user']) ? $parsed_url['user'] : '';
    $pass = isset($parsed_url['pass']) ? ':' . $parsed_url['pass']  : '';
    $pass = ($user || $pass) ? "$pass@" : '';
    $path = isset($parsed_url['path']) ? $parsed_url['path'] : '';
    $query = isset($parsed_url['query']) ? '?' . $parsed_url['query'] : '';
    $fragment = isset($parsed_url['fragment']) ? '#' . $parsed_url['fragment'] : '';
    return "$scheme$user$pass$host$port$path$query$fragment";
}




/**
 * Validates json
 *
 * @param boolean Valid?
 */
function validJson ($string) {
	return is_object(json_decode($string));
}



/**
 * Creates properly formatted scientific name
 *
 * @param string $scientificname
 * @param object $nameObject Parsed json with individual name components
 * @param string $searchTerms Optional highlighting
 * @return string
 */
function formatScientificName ($scientificname, $nameObject, $searchTerms = false) {
	$output = $scientificname;
	$elements = getScientificNameElements($nameObject);
    $f = array(chr(4), chr(7));
	$r = array('<span class="scientific">', '</span>');

	foreach ($elements as $e) {
		if (!empty($e)) {
			$output = str_replace($e, chr(4) . $e . chr(7), $output);
		}
	}
	$output = str_replace($f, $r, $output);

	// Highlight the formatted output
	return $searchTerms ? highlightSearchTerms($output, $searchTerms) : $output;
}

/**
 * Highlight search terms
 *
 * @param string $string
 * @param array $searchTerms
 * @return string $string
 *
 */function highlightSearchTerms ($string, $searchTerms) {
    foreach ($searchTerms as $field => $value) {
        // Do not highlight search flags
         if (!in_array(str_replace('_', '', $field), searchFlags())) {
            $term = is_array($value) ? $value[0] : $value;
            // Split terms on space if necessary
            $t = explode(' ', $term);
            // Store as array keys to eliminate duplicates
            foreach ($t as $i => $v) {
                $terms[$v] = $field . $i;
            }
        }
    }
    if (isset($terms)) {
        $string = highlightMatch($string, array_flip($terms));
    }
    return $string;
}

/**
 * Extracts scientific name components from json name object
 *
 * Returns scientific name elements from name object. Stores as keys and
 * flips to avoid duplicates (as in Larus fuscus fuscus)
 *
 * @param object $name Name object from json
 * @return array
 */
function getScientificNameElements ($name) {
	$elements = array(
		$name->genusOrMonomial => 'genusOrMonomial',
		$name->subgenus => 'subgenus',
		$name->specificEpithet => 'specificEpithet',
		$name->infraspecificEpithet => 'infraspecificEpithet'
	);
	return array_flip($elements);
}

/**
 * Extracts scientific name components from json name object, but unlike
 * getScientificNameElements() does not filter out duplicates
 *
 * Returns scientific name elements from name object.
 *
 * @param object $name Name object from json
 * @return array
 */
function getScientificNameElementsWithDuplicates ($name) {
	return array(
		'genusOrMonomial' => $name->genusOrMonomial,
		'subgenus' => $name->subgenus,
		'specificEpithet' => $name->specificEpithet,
		'infraspecificEpithet' => $name->infraspecificEpithet
	);
}



/**
 * Translates decimal coordinate pair to DMS
 *
 * Adapted from
 * https://www.dougv.com/2012/03/converting-latitude-and-longitude-coordinates-between-decimal-and-degrees-minutes-seconds/
 *
 * Takes decimal coordinates and return degree, minute, second notation. Original function only
 * accepted single parameter; adapted to take both latitude and longitude immediately
 *
 * @param Decimal $lat Latitude
 * @param Decimal $lon Longitude
 * @return string Latitude, longitude
 */
function decimalToDMS ($lat, $lon) {
     $coordinates = array(
        'lat' => $lat,
        'lon' => $lon
     );
     foreach ($coordinates as $type => $decimal) {
        if (!is_numeric($decimal) || abs($decimal) > 180) {
            return false;
        }
        if ($type == 'lat' && $decimal < 0) {
              $direction = t('S');
        } else if ($type == 'lon' && $decimal < 0) {
          $direction = 'W';
        } else if ($type == 'lon') {
          $direction = t('E');
        } else {
          $direction = 'N';
        }
        $d = abs($decimal);
        $degrees = floor($d);
        $seconds = ($d - $degrees) * 3600;
        $minutes = floor($seconds / 60);
        $seconds = floor($seconds - ($minutes * 60));
        $output[$type] = $degrees . '&deg;' . $minutes . "'" . $seconds . '"' . $direction;
     }
     return isset($output) && count($output) == 2 ? implode(', ', $output) : false;
}

/**
 * Sets head and (optionally) page title
 *
 * @param string $head Head title
 * @param string $page Page title
 */
function setTitle ($head, $page = '') {
    $_SESSION['nbaPageTitle'] = $head;
    drupal_set_title($page);
}




/**
 * Determines if service is a search service (contrary to detail service)
 *
 * @param unknown $r Request
 * @return boolean true/false
 */
function isSearchService ($r) {
    foreach (searchServices() as $service) {
        if (strpos($r, $service) !== false) {
            return true;
        }
    }
    return false;
}

/**
 * Sets navigation SESSION for previous/next links in multimedia
 *
 * Returns the searchId, which can be usedfor background updating of
 * the navigation SESSION.
 *
 * @param array $data Parsed json
 * @return string $searchId
*/
function setNavigation ($data) {
    $terms = getSearchTerms($data);
    $searchId = setSearchId($terms);

    // Search has already been stored previously
    if (isset($_SESSION['nbaNavigation'][$searchId])) {
        return $searchId;
    }

    $_SESSION['nbaNavigation'][$searchId]['offset'] =
        array_key_exists('_offset', $terms) ? $terms['_offset'][0] : 0;
    $_SESSION['nbaNavigation'][$searchId]['total'] = $data->totalSize;
    // Previous/next set links
    $navigation = getNavigationPreviousNextSets($data, multimediaService());
    $_SESSION['nbaNavigation'][$searchId]['nextSet'] = $navigation['next'];
    $_SESSION['nbaNavigation'][$searchId]['previousSet'] = $navigation['previous'];
    // Links within results
    $_SESSION['nbaNavigation'][$searchId]['currentSet'] = array();
    foreach ($data->searchResults as $row) {
        $_SESSION['nbaNavigation'][$searchId]['currentSet'][] =
            stripNBABASEURL(getMultimediaDetailLink($row)) . '&searchID=' . $searchId;
    }

    return $searchId;
}

/**
 * Sets the urls for the previous/next result sets
 *
 * This should be pretty straightforward, as the NBA returns these links in the
 * response. However, this is not the case for POST requests! These have to
 * created from the search terms.
 *
 * @param array $data Parsed json data
 * @param string $service Service, required to determine GET/POST request
 * @return array $d Array with next and previous links
 */
function getNavigationPreviousNextSets ($data, $service) {
    // POST or GET service?
    $config = serviceToFunctions();
    foreach ($data->links as $i => $link) {
        $links[$link->rel] = $link->href;
    }
    // For GET determining the sets is easy
    if (strtolower($config[$service]['method']) == 'get') {
        $d['next'] = $links['_self'] != $links['_nextPage'] ?
            $links['_nextPage'] : false;
        $d['previous'] = $links['_self'] != $links['_prevPage'] ?
            $links['_prevPage'] : false;
    // For POST we need to parse the queryParameters
    } else {
        $d['next'] = setNavigationSetLink($data, 'next');
        $d['previous'] = setNavigationSetLink($data, 'previous');
    }
    return $d;
}

/**
 * Creates links for previous next result sets for POST request
 *
 * If GET request is used, the NBA returns correct links for previous and next
 * results sets. For POST however, these have to be reconstructed using the
 * queryParameters.
 *
 * @param array $data Parsed json data
 * @param string $direction previous/next
 * @return boolean|string
 */
function setNavigationSetLink ($data, $direction) {
    foreach ($data->links as $i => $link) {
        $links[$link->rel] = $link->href;
    }
    $terms = getSearchTerms($data);
    // Append _offset if this has not been set yet
    if (!array_key_exists('_offset', $terms)) {
        $terms['_offset'] = array(0, $data->totalSize - 1);
    }
    $p = '';
    foreach ($terms as $k => $v) {
        if ($k == '_offset') {
            if ($direction == 'previous' && ($v[0] - $terms['_maxResults'][0] >= 0)) {
                $p .= $k . '=' . ($v[0] - $terms['_maxResults'][0])  . '&';
            } else if ($direction == 'next' &&
                ($v[0] + $terms['_maxResults'][0] < $data->totalSize - 1)) {
                 $p .= $k . '=' . ($v[0] + $terms['_maxResults'][0])  . '&';
            } else {
                return false;
            }
        } else {
            $p .= $k . '=' . $v[0] . '&';
        }
    }
    return $links['_self'] . urlencode('?' . substr($p, 0, -1));
}


/**
 * Background reset of the navigation SESSION
 *
 * Called when the user arrives at the first or last item in the navigation set.
 * The next/previous NBA request is called in the background and the SESSION is
 * reset. In this special case, the SESSION should not be reset again when the
 * new page loads. This is handled by setting reset = 0.
 *
 * @param string $r NBA request
 * @return string Updated $searchId

 function updatePreviousNext ($r) {
    $json = file_get_contents(setBasePath() . 'nba/ajax?nba_request=' . $r);
    if (!empty($json)) {
        // Set new SESSION and return new searchId
        return setNavigation(json_decode($json));
    }
}
*/

/**
 *  Sets unique id for search terms
 *
 *  Creates a hash based on the search terms. Used for navigation purpose.
 *
 * @param array $terms Search terms
 */
function setSearchId ($terms) {
    ksort($terms);
    return md5(serialize($terms));
}

/**
 *  Get search id from NBA request
 *
 * @param string $r NBA request
 * @return string|false
 */
function getSearchId ($r) {
    safe_parse_str(urldecode($r), $q);
    return isset($q['searchID']) ? $q['searchID'] : false;
}

function stripNBABASEURL ($url) {
    $url = str_replace(nbaBaseUrl(), '', urldecode($url));
    if ($url[0] == '/') {
        $url = substr($url, 1);
    }
    return $url;
}

function setAnchor ($a) {
    return str_replace('/', '_', $a);
}




/**
 * Decorates score in result table
 *
 * @param int $score Percentage from NBA response
 * @return string Formatted html
 */
function decorateScore ($score) {
    // Reset score so always one square is filled
    $score = $score < 20 ? 20 : $score;
	$roundScore = round( $score / 20 );
    $result = "<span class='score' title='$score %'>";

    for ($i = 1; $i <= 5; $i++){
        if ($i <= $roundScore){
            $result.= "<i class='icon-square_full'></i>";
        } else {
            $result.= "<i class='icon-square_empty'></i>";
        }
    }

    return $result .= "</span>";
}




/**
 * Wrapper for logging
 *
 * Currently log to watchdog and print error on screen. Can be adapted to
 * instantantly die() etc.
 *
 * @param string $message
 */
function handleError ($message) {
    //Log to the drupal error log
    watchdog("ndabioresults", $message, NULL, WATCHDOG_ERROR);
    //Log to the screen?
    drupal_set_message("Bioportal: " . $message);
}

/**
 * Translates NBA fields (usually ABCD/DC) to proper English
 *
 * Uses Drupal nba2text Taxonomy for translation
 *
 * @param string $str Input string
 * @return string Translated string
 */
function translateNdaField ($str) {
    $machine_name = "nba2text";
    $myvalue = taxonomy_get_term_by_name($str, $machine_name);
    if (is_array($myvalue)) {
        $myvalues = array_shift($myvalue);
        if(!empty($myvalues)) {
            return t($myvalues->description);
        }
    }
    return t($str);
}




/**
 * Recreates NBA request url for Drupal
 *
 * Enriches the NBA request url by appending the basic search parameters
 * to the base url and path to this module.
 *
 * @param string $url NBA search parameters
 * @return string Drupal url
 */
function printDrupalLink ($url) {
    return setBasePath() . 'nba/result?nba_request=' . urlencode($url);
}













/**
 * Parses specimen media detail json to PHP array
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseSpecimenMediaDetail ($json) {
    if (!$json || !validJson($json)) {
		handleError('parseSpecimenMediaDetail: no or invalid json response');
	}
	$data = json_decode($json);
//p($data);
	$row = $data->searchResults[0];

	foreach ($row->result as $field => $value) {
		if (!is_array($value) && !is_object($value)) {
			$output[$field] = $value;
		}
	}

	$output['source'] = $row->result->associatedSpecimen->sourceSystem->name;
	//$output['navigation'] = getNavigation($data);
	$output['names'] = getSpecimenNames($row, array('idBlock' => 'associatedSpecimens'));
	$output['unitID'] = setUnitId($row->result->associatedSpecimen->unitID);
	$output['mediaUnitID'] = $row->result->unitID;
	$output['imgSrc'] = getImageUrl($row);
	$output['phaseOrStage'] = !empty($row->result->phasesOrStages) ?
	   $row->result->phasesOrStages :
	   $row->result->associatedSpecimen->phaseOrStage;
	$output['locality'] = !empty($row->result->gatheringEvents[0]->localityText) ?
	   $row->result->gatheringEvents[0]->localityText :
	   $row->result->associatedSpecimen->gatheringEvent->localityText;
	$output['dateTimeBegin'] = !empty($row->result->gatheringEvents[0]->dateTimeBegin) ?
	   timeStampToDate($row->result->gatheringEvents[0]->dateTimeBegin) :
	   timeStampToDate($row->result->associatedSpecimen->gatheringEvent->dateTimeBegin);

	return $output;
}





/**
 * Parses taxon detail json to PHP array
 *
 * Optional: adds fields to exclude to $skipFields array
 *
 * @todo Descriptions are hard-coded for NSR and CoL
 * @param string $json NBA response
 * @return array $output
 */
function parseTaxonDetail ($json) {
	$skipFields = array(
		'objectPublic'
		// etc
	);
	if (!$json || !validJson($json)) {
		handleError('parseTaxonDetail: no or invalid json response');
	}
	$data = json_decode($json);

	$output['acceptedName'] = formatScientificName(
		$data->searchResults[0]->result->acceptedName->fullScientificName,
		$data->searchResults[0]->result->acceptedName
	);
	$output['taxonID'] = getTaxonId($data);
	$output['nameElements'] =
	   getScientificNameElementsWithDuplicates($data->searchResults[0]->result->acceptedName);
	$output['sourceUrls'] = getSourceUrls($data);
	foreach ($data->searchResults as $row) {
		$source = $row->result->sourceSystem->name;

		if (!empty($row->result->defaultClassification)) {
			$output['classifications']['default'][$source] =
				parseClassification($row->result->defaultClassification);
		}
		if (!empty($row->result->synonyms)) {
			foreach ($row->result->synonyms as $i => $synonym) {
				$output['synonyms'][$source][] = formatScientificName(
					$row->result->synonyms[$i]->fullScientificName,
					$row->result->synonyms[$i]
				);
			}
		}
		if (!empty($row->result->descriptions)) {
		    // @todo: hard coded for NSR and CoL
		    foreach ($row->result->descriptions as $i => $description) {
		        // NSR Dutch
		        if (strtolower($description->category) == 'algemeen') {
                    $output['descriptions']['Dutch'][$source] =
					   $description->description;
		        }
		        // NSR English
		        if (strtolower($description->category) == 'summary') {
                    $output['descriptions']['English'][$source] =
					   $description->description;
		        }
		        // CoL English
		        if (empty($description->category) && !empty($description->description)) {
                    $output['descriptions']['English'][$source] =
					   $description->description;
		        }
		    }
		}
		if (!empty($row->result->vernacularNames)) {
			foreach ($row->result->vernacularNames as $i => $name) {
				$output['commonNames'][$source][$name->language][] = $name->name;
			}

		}
	}
	return $output;
}



/**
 * Parses specimen detail json to PHP array
 *
 * Optional: adds fields to exclude to $skipFields array
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseSpecimenDetail ($json) {

    $skipFields = array(
        'objectPublic',
	    'sourceSystemId',
        'sourceID',
	    'owner',
	    'title',
	    'multiMediaPublic',
	    'licenseType',
	    'license',
	    'assemblyID',
	    'collectionType'
		// etc
	);
	if (!$json || !validJson($json)) {
		handleError('parseSpecimenDetail : no or invalid json response');
	}
	$data = json_decode($json);

	foreach ($data->searchResults[0]->result as $field => $value) {
		if (!is_array($value) && !is_object($value) && !in_array($field, $skipFields)) {
			$output[$field] = setUnitId($value, $field);
		}
	}
	$output['assemblageID'] = $data->searchResults[0]->result->assemblageID;
	$output['collectionType'] = $data->searchResults[0]->result->collectionType;
	$output['source'] = isset($data->searchResults[0]->result->sourceSystem) ?
	   $data->searchResults[0]->result->sourceSystem->name : '';
	$output['names'] = getSpecimenNames($data->searchResults[0], array('links' => $data->links));
	$output['vernaculars'] = getSpecimenVernaculars($data->searchResults[0]);
	$output['gatheringEvent'] = getGatheringEventSpecimens($data);
	$output['license'] = $data->searchResults[0]->result->license;
	$output['otherSpecimens'] = getOtherSpecimens($data);
	// $output['navigation'] = getNavigation($data);

	return $output;
}






/**
 * Get previous/next links from NBA response
 *
 * @param array $data NBA response
 * @return array|void Array with previous and next links
 */
function getNavigation ($data) {
	if (isset($data->links) && !empty($data->links)) {
		foreach ($data->links as $link) {
			if ($link->rel == 'prev' || $link->rel == 'next') {
				$output[$link->rel] = $link->href;
			}
		}
	}
	return isset($output) ? $output : null;
}



/**
 * Returns url for a taxon associated with the specimen
 *
 * Quite a complicated way to find the appropriate url for a taxon. The entire
 * links object is passed and matched against the name components of the scientific
 * name. Only when a match is complete the link is considered matching
 *
 * @param object $links
 * @param array $scientificName
 * @return string|void Url to the name
 */
function getTaxonUrl ($links, $scientificName) {
	if (!empty($links)) {
		foreach ($links as $link) {
			if ($link->rel == '_taxon') {
			    // All parts in query should be present in $scientificName object
			    $parts = parse_url(urldecode($link->href));
                safe_parse_str($parts['query'], $q);
                $diff = array_diff($q, (array)$scientificName);
                if (empty($diff)) {
                    return $link->href;
                }
			}
		}
	}
	return false;
}




/**
 * Urls for data sources
 *
 * @param array $data NBA json response
 * @return array|void $output Array with key source name, value url
 */
function getSourceUrls ($data) {
    foreach ($data->searchResults as $row) {
        $urls[$row->result->sourceSystem->name] = $row->result->recordURI;
    }
    return isset($urls) ? $urls : null;
}


/**
 * Parses multimedia json to PHP array
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseMultimedia ($json) {
	if (!$json || !validJson($json)) {
		handleError('parseMultimedia: no or invalid json response');
	}
	$data = json_decode($json);

    // @TODO: disabled navigation for the time being
// unset($_SESSION['nbaNavigation']);
// setNavigation($data);

	$output['searchTerms'] = getSearchTerms($data);
	$output['total'] = getTotalRows($data);

	if (!$output['searchTerms']) {
		handleError('parseMultimedia: invalid json response');
	}
	if ($output['total'] == 0) {
	    $output['results'] = array();
        return $output;
	}
	foreach ($data->searchResults as $row) {
		$type = !empty($row->result->associatedTaxon) ? 'associatedTaxon' :
            'associatedSpecimen';
		$d['title'] = $type == 'associatedTaxon' ? $row->result->title : '';
		$d['caption'] = $type == 'associatedTaxon' ? $row->result->caption : '';
		$d['score'] = $row->percentage;
		$d['url'] = getMultimediaDetailLink($row);
		$d['source'] = !empty($row->result->{$type}->sourceSystem) ?
            $row->result->{$type}->sourceSystem->name : '';
		list($d['imgSrc'], $d['format']) = getImageData($row);
		// Reset image url if this is stored in MediaLib;
		// use medium format to speed up loading times
		if (strpos($d['imgSrc'], 'medialib') !== false) {
            $d['imgSrc'] = str_replace('format/large', 'format/medium', $d['imgSrc']);
		}
		$d['hits'] = getHits($row, false);
		$d['taxon'] = getMultimediaTaxon($row, $output['searchTerms']);
		$d['unitID'] = getMultimediaUnitId($row, $output['searchTerms']);
		$output['results'][] = $d;
	}

	$output['self'] = getSelfLink($data);
	$output['showAll'] = getShowAll($data);
	$output['paginator'] = getPaginator($data);

	// Only set filter when performing initial search
	if ($output['searchTerms']['_maxResults'][0] == maxResultsInitial()) {
	    $_SESSION['nbaFilters']['multimedia'] = $output['showAll'];
	}

	return isset($output) ? $output : false;
}

/**
 * Gets url to multimedia detail
 *
 * @param array $row NBA response
 * @return string Url
 */
function getMultimediaDetailLink ($row) {
    foreach ($row->links as $link) {
        if ($link->rel == '_multimedia') {
            return $link->href;
        }
    }
}



/**
 * Gets unit id associated with multimedia
 *
 * @param array $row Json data
 * @param array $searchTerms Optional parameter so search terms can be highlighted
 * @return string|void Registration number (= unit id)
 */
function getMultimediaUnitId ($row, $searchTerms = false) {
    if (isset($row->result->associatedSpecimen->unitID)) {
        $output = setUnitId($row->result->associatedSpecimen->unitID);
        return $searchTerms ? highlightSearchTerms($output, $searchTerms) : $output;
    }
    return null;
}

/**
 * Gets scientific name associated with multimedia
 *
 * @param array $row Json data
 * @param array $searchTerms Optional parameter so search terms can be highlighted
 * @return string|void Scientific name
 */
function getMultimediaTaxon ($row, $searchTerms = false) {
    if (isset($row->result->associatedTaxon->acceptedName) &&
        !empty($row->result->associatedTaxon->acceptedName)) {
        return formatScientificName(
    		$row->result->associatedTaxon->acceptedName->fullScientificName,
    		$row->result->associatedTaxon->acceptedName,
            $searchTerms
	    );
    }
    if (isset($row->result->associatedSpecimen->identifications) &&
        !empty($row->result->associatedSpecimen->identifications)) {
        return formatScientificName(
    		$row->result->associatedSpecimen->identifications[0]->scientificName->fullScientificName,
    		$row->result->associatedSpecimen->identifications[0]->scientificName,
            $searchTerms
	    );
    }
    return null;
}

/**
 * Parses specimen data json searched by name to PHP array
 *
 * Unlike the other parse functions, this one may forward to json to "specialised"
 * function: parseSpecimensByMap(). Additionally,this function differentiates between
 * grouped results and results per single taxon.
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseSpecimensByTaxon ($json) {
	if (!$json || !validJson($json)) {
		handleError('parseSpecimensByTaxon: no or invalid json response');
	}
	$data = json_decode($json);
//p($data);
	$output['searchTerms'] = getSearchTerms($data);

	$output['total'] = getTotalRows($data);
	if (!$output['searchTerms']) {
		handleError('parseSpecimensByTaxon: invalid json response');
	}

    // If showMap parameter has been set, parsing and printing should be redirected
    // to parse-/printSpecimensByMap
    if (isset($output['searchTerms']['_showMap'])) {
        return parseSpecimensByMap($data);
    }

	if ($output['total'] == 0) {
	    $output['results'] = array();
        return $output;
	}

    // Parameter that determines if results are for group or single taxon
    $single = isset($output['searchTerms']['single']) ? true : false;
    $maxResults = isGroupService(specimenNamesService()) ?
        maxGroupResults() : maxResults();

    foreach ($data->resultGroups as $row) {
		$d = array();
		$d['name'] = formatScientificName(
			$row->sharedValue,
			$row->searchResults[0]->result->identifications[0]->scientificName,
    		$output['searchTerms']
		);
		$d['url'] = getTaxonUrl($row->searchResults[0]->links,
		    $row->searchResults[0]->result->identifications[0]->scientificName);
		$d['fullScientificName'] = $row->sharedValue;
		$d['count'] = isGroupService(specimenNamesService()) ?
            $row->totalSize : count($row->searchResults);
		$d['sources'] = getSources($row);
		$d['score'] = $row->searchResults[0]->percentage;
		foreach ($row->searchResults as $i => $sp) {
    		$assemblageID = $sp->result->assemblageID;
    		$s['unitID'] = setUnitId($sp->result->unitID);
    		$s['recordBasis'] = $sp->result->recordBasis;
    		$s['kindOfUnit'] = $sp->result->kindOfUnit;
    		$s['preparationType'] = $sp->result->preparationType;
    		$s['collectionType'] = $sp->result->collectionType;
    		$s['url'] = $sp->links[0]->href;
    		$s['score'] = $sp->score;
            empty($assemblageID) ? $d['specimens'][] = $s :
                $d['sets'][$assemblageID][] = $s;
		}
		$d['allLink'] = $d['count'] > $maxResults ?
            specimenNamesService() . '/?identifications.scientificName.fullScientificName.raw=' .
            urlencode($row->sharedValue) . '&_sort=unitID&_sortDirection=ASC' : '';
		$output['results'][] = $d;
	}

	$output['self'] = getSelfLink($data);
	$output['showAll'] = getShowAll($data, isGroupService(specimenNamesService()));
	$output['paginator'] = $single ?
	   getPaginatorWithinGroup($data) :
	   getPaginator($data, isGroupService(specimenNamesService()));
	$output['single'] = $single;

	// Only set filter when performing initial search
	if ($output['searchTerms']['_maxResults'][0] == maxResultsInitial()) {
	    $_SESSION['nbaFilters']['specimenName'] = $output['showAll'];
	}

	return isset($output) ? $output : false;
}



/**
 * Gets scientific names for taxon media detail response
 *
 * @param array $row search results section of json response
 * @return array|void Array with formatted names and their links
 */
function getTaxonMultimediaNames ($row) {
	if (!empty($row->result->associatedTaxon->acceptedName)) {
	    $output[] = array(
    		'name' => formatScientificName(
    			$row->result->associatedTaxon->acceptedName->fullScientificName,
    			$row->result->associatedTaxon->acceptedName
    		),
    		'url' => getTaxonUrl($row->links, $row->result->associatedTaxon->acceptedName)
    	);
	}
	return isset($output) ? $output : false;
}



/**
 * Parses specimen data json to PHP array
 *
 * @param string $json NBA response
 * @return array $output
 */
function parseSpecimens ($json) {
	if (!$json || !validJson($json)) {
		handleError('parseSpecimens: no or invalid json response');
	}
	$data = json_decode($json);

	$output['searchTerms'] = getSearchTerms($data);
	$output['total'] = getTotalRows($data);
	if (!$output['searchTerms']) {
		handleError('parseSpecimens: invalid json response');
	}
	if ($output['total'] == 0) {
	    $output['results'] = array();
        return $output;
	}
	foreach ($data->searchResults as $row) {
		$d = array();
		$d['unitID'] = setUnitId($row->result->unitID);
		$d['url'] = $row->links[0]->href;
		$d['hits'] = getHits($row, false);
		$d['source'] = $row->result->sourceSystem->name;
		$d['score'] = $row->percentage;
		$d['names'] = getSpecimenNames($row);
		$output['results'][] = $d;
	}

	$output['self'] = getSelfLink($data);
	$output['showAll'] = getShowAll($data);
	$output['paginator'] = getPaginator($data);

	// Only set filter when performing initial search
	if ($output['searchTerms']['_maxResults'][0] == maxResultsInitial()) {
	    $_SESSION['nbaFilters']['specimen'] = $output['showAll'];
	}

	return isset($output) ? $output : false;
}


/**
 * Parses specimen data json searched by name and map to PHP array
 *
 * As the data arrives to this function through parseSpecimensByTaxon(),
 * json parsing and validation can be skipped.
 *
 * @param array $data Parsed json from parseSpecimensByTaxon()
 * @return array $output
 */
function parseSpecimensByMap ($data) {

	$output['searchTerms'] = getSearchTerms($data);
	$output['total'] = getTotalRows($data);	$output['_showMap'] = true;

	foreach ($data->resultGroups as $row) {
		$d = array();
		$name = formatScientificName(
			$row->sharedValue,
		    // @todo
			//$row->searchResults[0]->result->identifications[getResultOffset($row)]->scientificName,
			$row->searchResults[0]->result->identifications[0]->scientificName,
		    getHits($row->searchResults[0])
		);
		$sources = getSources($row);
		foreach ($row->searchResults as $i => $sp) {
    		$d['name'] = $name;
    		$d['taxonUrl'] = getTaxonUrl($row->searchResults[0]->links,
		        $row->searchResults[0]->result->identifications[0]->scientificName);
    		$d['url'] = $sp->links[0]->href;
    		$d['source'] = implode(', ', $sources);
    		$d['assemblageID'] = $sp->result->assemblageID;
    		$d['unitID'] = setUnitId($sp->result->unitID);
    		$gatheringEvent = getGatheringEventSpecimens($row, $i);
    		$d['localityText'] = $gatheringEvent['localityText'];
    		$d['date'] = $gatheringEvent['dateTimeBegin'];
    		$d['lat'] = $gatheringEvent['siteCoordinates']['lat'];
    		$d['lon'] = $gatheringEvent['siteCoordinates']['lon'];
    		$output['results'][] = $d;
		}
	}

	$output['self'] = getSelfLink($data);
	return isset($output) ? $output : false;
}


/**
 * Gets _groupOffset from json
 *
 * @param array $data Json
 * @return int Group offset
 */
function getGroupOffset ($data) {
    if (isset($data->queryParameters->_groupOffset[0])) {
        return $data->queryParameters->_groupOffset[0];
    }
    return 0;
}

/**
 * Gets image url from json
 *
 * @param array $row Json
 * @return string|void Url
 */
function getImageUrl ($row) {
    if (!empty($row->result->serviceAccessPoints)) {
    	$key = key(get_object_vars($row->result->serviceAccessPoints));
    	return $row->result->serviceAccessPoints->{$key}->accessUri;
    }
    return null;
}

/**
 * Gets image url plus format from json
 *
 * @param array $row Json
 * @return array|void Array with url and format
 */
function getImageData ($row) {
    if (!empty($row->result->serviceAccessPoints)) {
    	$key = key(get_object_vars($row->result->serviceAccessPoints));
    	return array(
    	   $row->result->serviceAccessPoints->{$key}->accessUri,
    	   $row->result->serviceAccessPoints->{$key}->format
    	);
    }
    return null;
}

/**
 * Gets the fields containing data matching the search term(s)
 *
 * @param array $row Parsed json
 * @param boolean $stripTags Should html tags be removed?
 * @return array Array with field => value pairs
 */
function getHits ($row, $stripTags = true) {
    // Exclude matches in these fields
    $noHits = array(
        'fullScientificName',
        'theme',
        'raw'
    );
	foreach ($row->matchInfo as $info) {
		// Extract field from path.to.field; field is the last part
		$e = explode('.', $info->path);
		$field = end($e);
		if (!in_array($field, $noHits)) {
            $hits[$field] = $stripTags ? strip_tags($info->valueHighlighted) :
                $info->valueHighlighted;
		}
	}
	return isset($hits) ? $hits : array();
}




/**
 * Total size
 *
 * Number of results in json response
 *
 * @param array $data Parsed json
 * @return number|boolean
 */
function getTotalRows ($data, $groupResult = false) {
	if (isset($data->totalSize)) {
		return (int)$data->totalSize;
	}
	return false;
}

/**
 * Special case function for number of results in json response within a grouped result
 *
 * @param array $data Parsed json
 * @return number|boolean
 */
function getTotalRowsWithinGroup ($data) {
	if (isset($data->resultGroups[0]->totalSize)) {
		return (int)$data->resultGroups[0]->totalSize;
	}
	return false;
}

/**
 * Gets query parameters
 *
 * @param array $data Parsed json
 * @return array|void Parameters
*/
function getSearchTerms ($data) {
	if (isset($data->queryParameters)) {
		return (array)$data->queryParameters;
	}
	return false;
}



/**
 * Parses taxon json to PHP array
 *
 * @param string $json
 * @return array $output
 */
function parseTaxa ($json) {
    global $language;
	if (!$json || !validJson($json)) {
		handleError('parseTaxon: no or invalid json response');
	}
	$data = json_decode($json);

	$output['total'] = getTotalRows($data);
	$output['searchTerms'] = getQueryTerms('taxon');

	if (!$output['searchTerms']) {
		handleError('parseTaxon: invalid json response');
	}
	if ($output['total'] == 0 || empty($data->resultSet)) {
	    $output['results'] = array();
        return $output;
	}
	foreach ($data->resultSet as $row) {
		$d = array();
		// Accepted scientific name, synonym, or common name
		$d['type'] = getResultType($row);
		$d['rank'] = $row->searchResults[0]->result->taxonRank;
		$d['name'] = formatScientificName(
			strip_tags($row->searchResults[0]->result->acceptedName->fullScientificName),
			$row->searchResults[0]->result->acceptedName,
			$output['searchTerms']
		);
		if ($d['type'] == 'accepted') {
			$d['description'] = t(ucfirst($d['rank']));
		} else if ($d['type'] == 'synonym') {
            $offset = getTaxonSynonymOffset($row);
			$d['description'] = t('Synonym') . ': ' .
                formatScientificName(
    				strip_tags($row->searchResults[0]->result->synonyms[$offset]->fullScientificName),
    				$row->searchResults[0]->result->synonyms[$offset],
    				$output['searchTerms']
    			);
		} else if ($d['type'] == 'common') {
			$d['description'] = t('Common name(s)') . ': ';

			foreach ($row->searchResults[0]->matchInfo as $i => $info) {
                $vernaculars[] = highlightSearchTerms(
    				strip_tags($info->valueHighlighted),
    				$output['searchTerms']
    		    );
			}
			$d['description'] .= implode(', ', $vernaculars);
			/*
            foreach ($row->searchResults[0]->matchInfo as $i => $info) {
                $hits = explode('<span class="search_hit">', $info->valueHighlighted);
                foreach ($hits as $hit) {
                    $vernaculars[] = highlightSearchTerms(
            			trim(strip_tags($hit)),
            			$output['searchTerms']
            	    );
                }
            }
            $d['description'] .= implode(', ', array_filter($vernaculars));
            */
			unset($vernaculars);
		}

		$d['url'] = urldecode($row->searchResults[0]->links[0]->href);
		$d['sources'] = getSources($row);
		$d['commonNames'] = ($d['type'] != 'common' ? getCommonNames($row, true) : array());
		$d['score'] = $row->searchResults[0]->percentage;
		$output['results'][] = $d;
	}

	$output['self'] = getSelfLink($data);
	$output['showAll'] = getShowAll($data);
	$output['paginator'] = getPaginator($data);

	// Only set filter when performing initial search
	if ($output['searchTerms']['_maxResults'][0] == maxResultsInitial()) {
	    $_SESSION['nbaFilters']['taxon'] = $output['showAll'];
	}

	return isset($output) ? $output : false;
}

/**
 *
 * Gets offset for synonym/common name in taxon response
 *
 * Returns offset of result; used only for synonyms and common names to
 * determine the array key containing the hit
 *
 * NOTE: currently not in use because final NBA response does not match
 * mock object for which this function was developed...
 *
 * @param array $row Parsed json
 * @return unknown
 */
function getResultOffset ($row) {
	preg_match('/\[(.*?)\]/', $row->searchResults[0]->matchInfo[0]->path, $m);
	return $m[1];
}

/**
 * Gets result type (accepted/synonym/common) for taxon
 *
 * Returns type of result:
 * acceptedName.fullScientificName
 * acceptedName.synonyms[0].scientificName.fullScientificName
 * acceptedName.commonNames[0].name
 *
 * @param array $row Parsed json
 * @return string accepted/synonym/common

function getResultType ($row) {
	$path = $row->searchResults[0]->matchInfo[0]->path;
	return strpos($path, 'synonym') !== false ? 'synonym' :
		(strpos($path, 'vernacularNames') !== false ? 'common' : 'accepted');
}
 */

function getResultType ($row) {
	$path = $row->searchResults[0]->matchInfo[0]->path;
	return strpos($path, 'synonym') !== false ? 'synonym' :
		(strpos($path, 'vernacularNames') !== false ? 'common' : 'accepted');
}


/** Gets offset of matched synonym in taxon response
 *
 * Indirect way to determine the offset of the matched synonym: check match
 * against value of field in synonyms and return offset of first hit
 *
 * @param array $row Parsed json
 * @return int|void $i
 */
function getTaxonSynonymOffset ($row) {
/*
    $path = $row->searchResults[0]->matchInfo[0]->path;
    $field = str_replace('synonyms.', '', $path);
    foreach ($row->searchResults[0]->result->synonyms as $i => $synonyms) {
        if ($synonyms->$field ==
            strip_tags($row->searchResults[0]->matchInfo[0]->valueHighlighted)) {
            return $i;
        }
    }
    return false;
*/
    $fields = $hits = array();
    // Determine offset of search results in synonyms
    // First create array with field => hit
    foreach ($row->searchResults[0]->matchInfo as $i => $info) {
        // Path should start with synonym.
        if (strpos($info->path, 'synonym') === 0) {
            // Possible hits are all listed in a single row, as such:
            // <span class="search_hit">HIT</span>
            $hightlights = explode('</span><span class="search_hit">', $info->valueHighlighted);
            $fields[str_replace('synonyms.', '', $info->path)] =
                array_unique(array_map('strip_tags', $hightlights));
        }
    }
    foreach ($row->searchResults[0]->result->synonyms as $i => $synonym) {
        foreach ($fields as $field => $matches) {
            foreach ($matches as $match) {
                if ($synonym->$field == $match) {
                    $hits[$i][] = $match;
                }
            }
        }
    }
    $hits = array_map('count', $hits);
    return array_search(max($hits), $hits);
}



/**
 * Returns all sources for taxon/specimen
 *
 * @param array $row Parsed json
 * @return array|void
 */
function getSources ($row) {
	foreach ($row->searchResults as $i => $obj) {
		$output[$obj->result->sourceSystem->name] = $i;
	}
	return isset($output) ? array_flip($output) : false;
}

/**
 * Gets common names for taxon
 *
 * Return format is array(name => language), so duplicates will be avoided.
 * Language check is optional. If selected, only common names for the
 * current interface language will be returned.
 *
 * @param array $row Parsed json
 * @param boolean $languageCheck
 * @return array|void
 */
function getCommonNames ($row, $languageCheck = false) {
	global $language;
	foreach ($row->searchResults as $i => $taxon) {
		if (isset($taxon->result->vernacularNames)) {
			foreach ($taxon->result->vernacularNames as $name) {
				// If language is set, only store when language of
				// common name matches that of interface...
				if ($languageCheck) {
					if ($name->language == $language->name) {
						$output[$name->name] = $name->language;
					}
					// ... else always return all names
				} else {
					$output[$name->name] = $name->language;
				}
			}
		}
	}
	return isset($output) ? $output : false;
}


/**
 * Decorates description in taxon result table
 *
 * @param array $row Parsed json
 * @return string
 */
function decorateDescription ($row) {
	return ($row['type'] != 'accepted' ?
		t(ucfirst($row['type'])) . ($row['type'] == 'common' ? ' ' . t('name') : '') .
		' ' . t('for') . ' ' :  '') . ($row['type'] == 'accepted' ? t(ucfirst($row['rank'])) :
		t($row['rank']));
}

/**
 * Gets Show all... link
 *
 * Show all link is shown only when the user does not come from a form and
 * when the number of results exceeds the maximum number of initial results.
 * The latter setting depends on the fact if it's a service that has regulr or grouped
 * results.
 *
 * @param array $data Parsed json
 * @param boolean $groupResult Service has grouped results?
 * @return string|void Url
 */
function getShowAll ($data, $groupResult = false) {
	if (isset($_SESSION['nbaRequestType']) && $_SESSION['nbaRequestType'] == 'form' &&
	    getTotalRows($data) > maxResultsInitial()) {
	    $self = getSelfLink($data);
	    if (!empty($self)) {
            return setUrlPars(
                geoShapeToSession($self, true),
                array('_maxResults' => $groupResult ? maxGroupResults() : maxResults()),
                true
            );
	    }
	}
	return null;
}




/**
 * Gets sort parameter
 *
 * Gets sort parameter from self link or, if self link is not provided,
 * returns default value
 *
 * @param string $self Self link
 * @param boolean $groupResult Service has grouped results?
 * @return string Result from self link or default value if self link is not provided
 */
function getSort ($self, $groupResult = false) {
    $p = $groupResult ? '_groupSort' : '_sort';
    if (!empty($self)) {
        $value = getUrlParValue(urldecode($self), $p);
        if (!empty($value)) {
            return $value;
        }
    }
    return $groupResult ? defaultGroupSort() : defaultSort();
}




/**
 * Scientific names and their urls for a specimen
 *
 * @param array $row Individual record in NBA response
 * @param array $p: options
 *    links => links to species (optional)
 *    idBLock => alternate id block (optional)
 * @return array|void Array of names and their urls
 */
function getSpecimenNames ($row, $p) {
    $links = isset($p['links']) ? $p['links'] : $row->links;
    $idBlock = isset($p['idBlock']) ?
        $row->result->associatedSpecimen->identifications :
        $row->result->identifications;

    if (empty($idBlock)) {
        return array();
    }

    foreach ($idBlock as $i => $id) {
		$output[] = array(
			'name' => formatScientificName(
				$id->scientificName->fullScientificName,
				$id->scientificName
			),
			'url' => getTaxonUrl($links, $id->scientificName),
		    'preferred' => $id->preferred ? 1 : 0
		);
	}

	if (isset($output)) {
    	usort($output, function($a, $b) {
            return $b['preferred'] - $a['preferred'];
        });
	    return $output;
	}
	return array();
}























/**
 * Prints taxon search result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printTaxa ($data) {
//p($data);
    if (empty($data['results'])) {
        return false;
    }

    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    setTitle($headTitle, $headTitle);

    $headers = array(
    	'acceptedName.fullScientificName' => array(
    		'label' => t('Name'),
    		'sort' => 'ASC',
    		'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
    		'url' => setSortUrl('acceptedName.fullScientificName', 'ASC', $data['self'])
    	),
    	'description' => array(
    		'label' => t('Description')
    	),
    	'foundIn' => array(
    		'label' => t('Found in')
    	),
    	'_score' => array(
    		'label' => t('Match'),
    		'sort' => 'DESC',
    		'icon' => array(
			    'ASC' => 'icon-sort_little_much',
			    'DESC' => 'icon-sort_much_little'
			),
    		'url' => setSortUrl('_score', 'DESC', $data['self'])
    	)
    );

    $explanation = _wrap(t("(matching scientific or common name)"),"span","explanation");

    $output = '<div id="' . taxonService() . '"></div>';
    $output .= sprintf(
        '<h2>%s <span class="count">(%s)</span> %s</h2>',
        t('Species names'),
        _formatNumber($data['total']),
        $explanation
    );
    $output .= sprintf('<table><thead>%s</thead><tbody>', printHeaders($headers, $data['self']));

    foreach ($data['results'] as $i => $row) {
    	$output .= "<tr>";

        // Name
        $output .= "<td>";
        $output .= "<a href='" . printDrupalLink($row['url']) . "'>" . $row['name'] . "</a>";
        $output .= (!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '');
        $output .=	"</td>";

        // Description
        $output .= "<td>" . $row['description'] . "</td>";

        // Source(s)
        $output .= "<td>" . implode('</br>', $row['sources']) . "</td>";

        // Match
        	$output .= "<td>" . decorateScore($row['score']) . "</td>";

        $output .= "</tr>";
    }

    $output .= "</tbody></table>";
    $output = _markUp($output);

    $output .= printShowAll($data);
    $output .= printPaginator($data);

    return $output;
}


/**
 * Prints taxon identifications for specimen (used only for non-name search)
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimenTaxa ($names) {
	$output = '';
	foreach ($names as $name) {
		$t = $name['name'];
		$t = !empty($name['url']) ?
			'<a href="' . printDrupalLink($name['url']) . '">' . $name['name'] . '</a>, ' :
			$t . ', ';
		$output .= $t;
	}
	return !empty($output) ? substr($output, 0, -2) : '-';
}


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

    $getSpecimenRequest = nbaBaseUrl() . specimenNamesService() .
        '/?' . safe_http_build_query($data['nameElements']) . '&_andOr=AND';
    $getMultimediaRequest = nbaBaseUrl() . multimediaService() .
        '/?' . safe_http_build_query($data['nameElements']) . '&_andOr=AND';

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



/**
 * Prints specimen name search result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimensByTaxon ($data) {
//p($data);
    if (empty($data['results'])) {
        return false;
    }

    if (isset($data['_showMap'])) {
        return printSpecimensByMap($data);
    }

    if (isset($data['single']) && $data['single']) {
        return printSpecimensBySingleGroup($data);
    }

    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    $nameSortFlag = isGroupService(specimenNamesService()) ?
        'groupName' : 'identifications.scientificName.fullScientificName';
    setTitle($headTitle, $headTitle);

    $headers = array(
		'identifications.scientificName.fullScientificName' => array(
			'label' => t('Name'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl(
                $nameSortFlag,
			    'ASC',
			    $data['self'],
                isGroupService(specimenNamesService())
			)
		),
		'count' => array(
			'label' => ''
		),
        'mapIcon' => array(
			'label' => ''
        ),
		'foundIn' => array(
			'label' => t('Found in')
		),
		'_score' => array(
			'label' => t('Match'),
			'sort' => 'DESC',
			'icon' => array(
			    'ASC' => 'icon-sort_little_much',
			    'DESC' => 'icon-sort_much_little'
			),
			'url' => setSortUrl(
                '_score',
			    'DESC',
			    $data['self'],
			    isGroupService(specimenNamesService())
			)
		)
	);

    $count = _wrap('(' . _formatNumber($data['total']) . ')', "span", "count");

    $output = '<div id="' . specimenNamesService() . '"></div>';
    $output .= sprintf(
        '<h2>%s %s</h2>',
        t('Species with specimens'),
        $count
    );
    $output .= sprintf(
        '<table id="specimensByTaxon"><thead>%s</thead>',
        printHeaders($headers, $data['self'])
    );

    foreach ($data['results'] as $i => $row) {
		$output .= "<tr class='indent-0' id='taxon-$i'>";
		// Name
		$url = printDrupalLink($row['url']);

		$output .= "<td>" . "<a href='" . (!empty($url) ? $url : '#') . "'>" . $row['name'] . "</a>" .
		    (!empty($row['commonNames']) ? '</br>' . implode(', ', array_keys($row['commonNames'])) : '') . "</td>";
		// Number (and collection type)
		$output .= "<td>" . $row['count'] . ' ' . ($row['count'] > 1 ? t('specimens') : t('specimen')) . "</td>";
		// Map icon
		$output .= "<td>" .
		  (isset($_SESSION['nbaSearch']['geoShape']) && !empty($_SESSION['nbaSearch']['geoShape'])
		      && !isset($_GET['noMap']) ?
		      "<a href='" . printDrupalLink(
                specimenNamesService() . '?_geoShape=[session]&' .
		      '&identifications.scientificName.fullScientificName.raw=' .
		      urlencode($row['fullScientificName']) . '&_showMap&_maxResults=100') .
		      "' class='icon-location'></a>" : '') .
		  "</td>";
		// Source(s)
		$output .= "<td>" . implode('</br>', $row['sources']) . "</td>";
		// Match
		$output .= "<td>" . decorateScore($row['score']) . "</td>";
		$output .= "</tr>";
		$output .= printSpecimenCollection($row, $i);
	}

    $output .= "</table>";
    $output = _markUp($output);

    $output .= printShowAll($data);
    $output .= printPaginator($data);

    return $output;
}



function _printSpecimensTaxon ($data) {
	global $language;
	
//p($data);
	if (empty($data['results'])) {
		return false;
	}
	
 	// Drupal title empty; page title custom
	$headTitle = t('Search results');
	$nameSortFlag = 'identifications.scientificName.fullScientificName';
	setTitle($headTitle, $headTitle);
	
	$headers = [
		'identifications.scientificName.fullScientificName' => [
			'label' => t('Name'),
		],
		'count' => [
			'label' => ''
		],
		'mapIcon' => [
			'label' => ''
		],
		'foundIn' => [
			'label' => t('Found in')
		],
	];
	
	$output = '<div id="specimen"></div>';
	$output .= sprintf(
		'<h2 style="margin-bottom: 0;">%s %s %s %s</h2>',
		($language->language == 'nl' ? 'Soorten' : 'Species'),
		_wrap('(' . _formatNumber($data['total']) . ')', "span", "count"),
		t('with specimens'),
		_wrap('(' . _formatNumber($data['specimensTotal']) . ')', "span", "count")
	);
	if (!isset($_GET['form_id'])) {
		$output .= "<div class='view-options'>\n<div class='specimen-service-select'>" .
			'<a href="' . _resetUrl() . '&service=specimen' . '">' . t('Display by specimen') . "</a></div>\n" . 
			"<div class='sort-options'>" . _printSortOptions('names.specimens') . "</div>\n</div>\n";
	}
	
	$output .= sprintf(
		'<table style="margin-top: 20px;" id="specimensByTaxon"><thead>%s</thead>', 
		_printHeaders($headers)
	);
	
	foreach ($data['results'] as $i => $row) {
		$output .= "<tr class='indent-0' id='taxon-$i'>";
		// Name
		
		$output .= "<td>" . "<a href='#''>" . $row['fullScientificName'] . "</a> " .
			(!empty($row['commonNames']) ? '</br>' . 
			implode(', ', array_keys($row['commonNames'])) : '') . "</td>\n";
		// Number (and collection type)
		$output .= "<td>" . _formatNumber($row['count']) . ' ' . 
			($row['count'] > 1 ? t('specimens') : t('specimen')) . "</td>\n";
		// Map icon
		
/*
		$output .= "<td>" .
			(isset($_SESSION['nbaSearch']['geoShape']) && !empty($_SESSION['nbaSearch']['geoShape']) && 
				!isset($_GET['noMap']) ?
			"<a href='" . printDrupalLink(
				specimenNamesService() . '?_geoShape=[session]&' .
				'&identifications.scientificName.fullScientificName.raw=' .
				urlencode($row['fullScientificName']) . '&_showMap&_maxResults=100') .
			"' class='icon-location'></a>" : '') .
			"</td>";
*/			
		// Set map url in parse	
		$output .= "<td>" . (!empty($row['mapUrl']) ? "<a href='" . $row['mapUrl'] . 
			"' class='icon-location'></a>" : '') . "</td>\n";
		
		// Source(s)
		$output .= "<td>" . implode('</br>', $row['sources']) . "</td>\n";
		// Match
		//$output .= "<td>" . decorateScore($row['score']) . "</td>";
		$output .= "</tr>";
		$output .= _printSpecimenCollection($row, $i);
	}
	
	$output .= "</table>";
	//$output = _markUp($output);
	
	$output .= _printShowAll($data);
	$output .= _printPaginator($data);
	
	return $output;
}




// Prints specimen result set on screen.
function printSpecimensBySingleGroup ($data) {
//p($data);
    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    setTitle($headTitle, $headTitle);

    $headers = array(
		'unitID' => array(
			'label' => t('Specimen'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl('unitID', 'ASC', $data['self'])
		),
		'count' => array(
			'label' => ''
		),
        'mapIcon' => array(
			'label' => ''
        ),
		'foundIn' => array(
			'label' => t('Found in')
		),
		'_score' => array(
			'label' => t('Match'),
			'sort' => 'DESC',
			'icon' => array(
			    'ASC' => 'icon-sort_little_much',
			    'DESC' => 'icon-sort_much_little'
			),
			'url' => setSortUrl('_score', 'DESC', $data['self'])
		)
	);

    $count = _wrap('(' . _formatNumber($data['results'][0]['count']) . ')', "span", "count");
    $output = sprintf('<h2>%s %s</h2>', t('Specimens of ' .
        str_replace('result-query', '', $data['results'][0]['name'])), $count);

    $output .= sprintf('<table><thead>%s</thead>', printHeaders($headers, $data['self']));

    foreach ($data['results'] as $i => $row) {
        // Single specimen
        if (isset($row['specimens'])) {
            foreach ($row['specimens'] as $specimen) {
                $info = implode('; ', array_filter(array(
                    ucfirst($specimen['kindOfUnit']),
                    $specimen['preparationType']
                )));
                $output .= "<tr>
                    <td><a href='" . printDrupalLink($specimen['url']) . "'>" . $specimen['unitID'] . "</a></td>
                    <td colspan='2'>$info</td>
                    <td>" . implode('</br>', $data['results'][0]['sources']) . "</td>
                    <td>" . decorateScore($row['score']) . "</td>
                    </tr>";
            }

        // Specimen collection/set
        } else if (isset($row['sets'])) {
            foreach ($row['sets'] as $set => $specimens) {
            	$output .= "<tr><td>" . $set . "</td>" . _padTds(4) . "</tr>";
            	foreach ($specimens as $j => $specimen) {
            	    $output .= "<tr class='indent-1'>
            	    <td><a href='" . printDrupalLink($specimen['url']) . "'>"  . $specimen['unitID'] . "</a></td>
            	    <td colspan='2'>" . $specimen['recordBasis'] . "</td>
                    <td>" . implode('</br>', $data['results'][0]['sources']) . "</td>
                    <td>" . decorateScore($row['score']) . "</td>
                    </tr>";
            	}
            }
        }
	}

    $output .= "</table>";
    $output = _markUp($output);

    $output .= printPaginator($data);

    return $output;
}









// Prints specimen result set on screen.
function printSpecimensByMap ($data) {
     // Add Google Maps scripts from ndabio module (REQUIRED!)
    global $base_root, $base_path;

    // Drupal title empty; page title custom
    $headTitle = t('Search results');
    setTitle($headTitle, $headTitle);

    $path = drupal_get_path('module', 'ndabio');
    drupal_add_css($path . "/css/ndabio_style.css");
    drupal_add_js($path . "/js/map.js", array('weight' => 1));
    drupal_add_js($path . "/js/oms.min.js", array('weight' => 1));
    drupal_add_js("https://maps.googleapis.com/maps/api/js?key=" .
        variable_get('ndabio_config_gmapkey', NDABIO_GMAPKEY) . "&libraries=drawing");
    drupal_add_js(
        "jQuery(function() { google.maps.event.addDomListener(window, 'load', initializeSpecimens); });",
        array('type' => 'inline', 'scope' => 'footer')
    );
    drupal_add_js("var str_base_path = '$base_path';", 'inline');
    drupal_add_js("var specimenMarkers = " . json_encode($data['results']) .';', 'inline');
    drupal_add_js("var geoShape = " . $_SESSION['nbaSearch']['geoShape'] .';', 'inline');
    if (isset($_SESSION['nbaSearch']['mapCenter'])) {
        drupal_add_js('var storedMapCenter = "' . $_SESSION['nbaSearch']['mapCenter'] . '";', 'inline');
    }
    if (isset($_SESSION['nbaSearch']['zoomLevel'])) {
        drupal_add_js("var storedZoomLevel = " . $_SESSION['nbaSearch']['zoomLevel'] . ';', 'inline');
    }

    $output = sprintf('<h2>%s %s %s %s</h2>',
        t('Specimens of '),
        $data['results'][0]['name'],
        ' in ',
        (!empty($_SESSION['nbaSearch']['location']) ? $_SESSION['nbaSearch']['location'] :
            t('area drawn on map'))
    );
    $output .= '<div id="map-canvas"></div>';

    return $output;
}



/**
 * Prints specimen search result
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimens ($data) {

    if (empty($data['results'])) {
        return false;
    }

    // Drupal title empty; page title custom
    $headTitle = !isset($_SESSION['nbaSearch']['theme']) || empty($_SESSION['nbaSearch']['theme']) ?
        t('Search results') : t('Explore highlights');
    $pageTitle = isset($_GET['theme']) ? '' : $pageTitle;
    setTitle($headTitle, $pageTitle);

    $headers = array(
		'unitID' => array(
			'label' => t('Specimen'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl('unitID', 'ASC', $data['self'])
		),
		'identifications.scientificName.fullScientificName' => array(
			'label' => t('Species'),
			'sort' => 'ASC',
			'icon' => array(
			    'ASC' => 'icon-sort_a_z',
			    'DESC' => 'icon-sort_z_a'
			),
			'url' => setSortUrl('identifications.scientificName.fullScientificName', 'ASC', $data['self'])
		),
		'foundIn' => array(
			'label' => t('Found in')
		),
		'_score' => array(
			'label' => t('Match'),
			'sort' => 'DESC',
			'icon' => array(
			    'ASC' => 'icon-sort_little_much',
			    'DESC' => 'icon-sort_much_little'
			),
			'url' => setSortUrl('_score', 'DESC', $data['self'])
		)
	);

    $output = '<div id="' . specimenService() . '"></div>';
    $output .= sprintf(
        '<h2>%s <span class="count">(%s)</span></h2>',
        t('Specimens'),
        _formatNumber($data['total'])
    );
    $output .= sprintf('<table><thead>%s</thead><tbody>', printHeaders($headers, $data['self']));

  foreach ($data['results'] as $i => $row) {
		$output .= "<tr>";
		// Registration number plus hits
		$output .= "<td><a href='" . printDrupalLink($row['url']) . "'>" . $row['unitID'] . "</a>" .
			(!empty($row['hits']) ? '<br/>' . printHits($row) : '') .
			"</td>";
		// Species
		$output .= "<td>" . printSpecimenTaxa($row['names']) . "</td>";
		// Source(s)
		$output .= "<td>" . $row['source'] . "</td>";
		// Match
		$output .= "<td>" . decorateScore($row['score']) . "</td>";
		$output .= "</tr>";
	}

	$output .= "</tbody></table>";

    $output .= printShowAll($data);
    $output .= printPaginator($data);

    return $output;
}



/**
 * Prints multimedia detail
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printSpecimenMediaDetail ($data) {
//p($data);
    drupal_add_js(
        "jQuery(function() { jQuery('#purl').focus().click(function(){ jQuery(this).select(); } ); });",
        array('type' => 'inline', 'scope' => 'footer')
    );

    $output  = _wrap(t("Media item"), "div", "category");
    $output .= _wrap('', "h2");

    $output .= printPreviousNext();

    /* For the time being disable PURL for media
     *
	$purl = '<input id="purl" type="text" value="http://data.biodiversitydata.nl/naturalis/multimedia/' .
	   $data['mediaUnitID'] . '"></input>';
	$helpText = t('Please cite the object described here by using this PURL (Persistent Uniform Resource Locator). Naturalis will try to assure the permanent character of this PURL.');
	$output .= '<div class="property-list">
	   <dl><dt style="cursor: help; width: 100%;" title="' . $helpText . '">'.
	   t("Cite as") . ':</dt><dd></dd></dl><p>' . $purl . '</p>
	   </div>';
    */

    $altParts = array(
        isset($data['unitID']) ? strip_tags($data['unitID']) : '',
        isset($data['names'][0]['name']) ? strip_tags($data['names'][0]['name']) : '',
        isset($data['caption']) ? strip_tags($data['caption']) : ''
    );
    $alt = implode(' | ', array_filter($altParts));

    list($width, $height) = loadPrettyPhoto($data['imgSrc']);
    $img = "<img src='" . $data['imgSrc'] . "' alt='$alt' title='$alt' " .
        "style='width: {$width}px; height: {$height}px;'/>";
    if ($width > 0) {
        $copyright = !empty($data['copyrightText']) ?
            $copyright = '© ' . $data['copyrightText'] : '';
        $institution = $data['sourceInstitutionID'] .
            (!empty($data['sourceID']) ? ' (' . $data['sourceID'] . ')' : '');
        array_unshift($altParts, $institution, $copyright);
        $caption = implode('<br/>', array_filter($altParts));
        $img = "<a href='" . $data['imgSrc'] . "' rel='prettyPhoto' title='$caption'>$img</a>\n";
    }

    if (isMp4($data['imgSrc'])) {
        $output .= '<video src="' . $data['imgSrc'] . '" type="video/mp4" autoplay controls></video>';
    } else {
	   $output .= $img;
    }

	$output .= "<div class='property-list'>";

	if (!empty($data['unitID'])) {
		$output .= printDL(
            ucfirst(translateNdaField('unitID')),
            '<a href="' . printDrupalLink(specimenDetailService() . '?unitID=' .
                unsetUnitId($data['unitID'])) . '">' . $data['unitID'] . '</a>'
		);
	}
	if (!empty($data['names'])) {
		$output .= printNamesWithLinks($data['names'], t('Scientific name'));
	}

	$fields = array(
        'source',
        'creator',
        'license',
        'sourceInstitutionID',
	    'collectionType',
        'description',
        'copyrightText',
    	'locality',
    	'dateTimeBegin',
        'sexes',
	    'specimenTypeStatus',
        'phaseOrStage'
	);

  	foreach ($fields as $field) {
		$output .= printDL(
            ucfirst(translateNdaField($field)),
		    is_array($data[$field]) ? implode(', ', $data[$field]) : printValue($data[$field])
		);
	}

    // Drupal title empty; page title custom
    setTitle(t('Multimedia') . ' | ' . strip_tags($data[names][0]['name']) . ' | '  . $data['unitID']);

	return $output . "</dd>\n</div>\n";
}




/**
 * Prints navigation on details page
 *
 * Currently not in use!
 *
 * @param array $row Parsed json data
 * @return string|void Formatted output
 */
function printNavigation ($data) {
	$output = "<div class='navigation'>";
	if (isset($data['navigation']) && !empty($data['navigation'])) {
		$links = array_merge(array_flip(array('prev', 'next')), $data['navigation']);
		foreach ($links as $direction => $url) {
			$t = "<div class='$direction";
			$t .= !empty($url) ?
				"'><a href='" . printDrupalLink($url) . "'>" . $direction . "</a></div>" :
				"-disabled'></div>";
			$output .= $t;
		}
	}
	return $output . "</div>";
}



/**
 * Practically identical to printHits()
 *
 * @param array $row Parsed json data
 * @return string Formatted output
 */
function printMatches ($data) {
	$output = '';
	if (isset($data['searchTerms']) && !empty($data['searchTerms'])) {
		foreach ($data['searchTerms'] as $field => $value) {
		    if (!in_array(str_replace('_', '', $field), searchFlags())) {
			    $output .= translateNdaField($field) . ' <span class="result-query">' .
			    $value[0] . '</span>, ';
		    }
		}
	}
	return substr($output, 0, -2);
}



/**
 * Prints hits (matched results) as field: hits
 *
 * Replaces default <span> with <span class="result-query">
 *
 * @param array $row Parsed json data
 * @return string|void Formatted output
 */
function printHits ($row) {
	$output = '';
	if (isset($row['hits']) && !empty($row['hits'])) {
		foreach ($row['hits'] as $field => $hit) {
			$output .= ucfirst(translateNdaField($field)) . ': ' .
				str_replace('<span class="search_hit">', '<span class="result-query">', $hit) . '</br>';
		}
	}
	return !empty($output) ? substr($output, 0, -5) : null;
}


/** Prints no result message
 *
 * @return string Translated string with url back to form
 */
function printNoResults () {
    return t('Sorry, no results found') . '. <a href="' . setStartUrl() . '?searchagain=1">' .
        t('Please try again'). '</a>!';
}



/**
 * Prints description list
 *
 * @param string $field
 * @param string $value
 * @return string
 */
function printDL ($field, $value) {
  return "<dl><dt>$field</dt><dd>$value</dd></dl>";
}

/**
 * Prints table row
 *
 * @param string $field
 * @param string $value
 * @return string
 */
function printTableRow ($field, $value) {
	return "<tr><td>" . ($field != '' ? t(translateNdaField($field)) : '') . "</td><td>" .
		($value != '' ? $value : '') . "</td></tr>";
}



/**
 *
 * Prints value, modifying a few if they meet criteria
 *
 * @param string $license
 * @return string
 */
function printValue ($value) {
    if (strtolower($value) == 'cc0') {
        return '<a href="http://creativecommons.org/about/cc0" target="_blank">' .
            $value . '</a>';
    }
    return $value != '' ? $value : '—';
}



function printPreviousNext () {
    // Skip navigation if request is empty
    if (!isset($_GET['nba_request'])) {
        return false;
    }
    $searchId = getSearchId($_GET['nba_request']);
    // Skip navigation if searchId is missing or SESSION does not exist
    if (!$searchId || !isset($_SESSION['nbaNavigation'][$searchId])) {
        return false;
    }

    $request = stripNBABASEURL($_GET['nba_request']);
    $set = $_SESSION['nbaNavigation'][$searchId]['currentSet'];
    $offset = $_SESSION['nbaNavigation'][$searchId]['offset'];
    $key = array_search(stripNBABASEURL($_GET['nba_request']),
        $_SESSION['nbaNavigation'][$searchId]['currentSet']);

    $previousUrl = false;
    // Scroll through set
    if (isset($set[$key - 1])) {
        $previousUrl = urldecode($set[$key - 1]);
    // First item of set reached; check if there's a previousSet.
    } else if (!empty($_SESSION['nbaNavigation'][$searchId]['previousSet'])) {
        $previousSearchId = updatePreviousNext($_SESSION['nbaNavigation'][$searchId]['previousSet']);
        $previousUrl = end($_SESSION['nbaNavigation'][$previousSearchId]['currentSet']);
    }

    $nextUrl = false;
    // Scroll through set
    if (isset($set[$key + 1])) {
        $nextUrl = urldecode($set[$key + 1]);
    // Last item of set reached; check if there's a nextSet.
    } else if (!empty($_SESSION['nbaNavigation'][$searchId]['nextSet'])) {
        $nextSearchId = updatePreviousNext($_SESSION['nbaNavigation'][$searchId]['nextSet']);
        $nextUrl = reset($_SESSION['nbaNavigation'][$nextSearchId]['currentSet']);
    }

    $output = '<div class="fornext-bar"><ul>';

    // Count
    $output .= '<li>' . sprintf(
        t('%d of %d'),
        $offset + $key + 1,
        $_SESSION['nbaNavigation'][$searchId]['total']
    ) . '</li>';

    // Previous
    $output .= "<li>";

    if ($previousUrl) {
        $output .= '<a href="' . printDrupalLink($previousUrl) . '">';
    }
    $output .= '<span class="icon button-icon icon-chevron-up';
    if (!$previousUrl) {
        $output .= ' icon-button-disabled';
    }
    $output .= '"></span>';
    if ($previousUrl) {
        $output .= '</a>';
    }
    $output .="</li>";

    // Next
    $output .= "<li>";
    if ($nextUrl) {
        $output .= '<a href="' . printDrupalLink($nextUrl) . '">';
    }

    $output .= '<span class="icon button-icon icon-chevron-down';

    if (!$nextUrl) {
        $output .= ' icon-button-disabled';
    }

    $output .= '"></span>';


    if ($nextUrl) {
        $output .= '</a>';
    }

    $output .= '</li>';

    // Back
    $output .= '<li><a href="?back"><span class="icon button-icon icon-cross"></span></a></li>';
    $output .= '</ul></div>';

    return $output;
}

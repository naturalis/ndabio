<?php

function printClassifications ($data) {
	global $language;
	$output = '';
	$header = "<h3>" . t('Classifications') . "</h3>";
	$printClassifications = array();
	// First merge two separate classification arrays
	foreach ($data['classifications']['default'] as $source => $classification) {
		$classifications[] = array(
			'source' => $source,
			'classification' => $classification
		);
	}

	$stored = array();
	foreach ($classifications as $classification) {
	    $serialized = serialize($classification['classification']);
		// Classification does not exist yet; add it
		if (!in_array($serialized, $stored)) {
			$printClassifications[] = array($classification['source'] => $serialized);
			$stored[] = $serialized;
		// Classification does exist; adapt its key
		} else {
		    foreach ($printClassifications as $i => $pC) {
		        foreach ($pC as $s => $c) {
		            if ($serialized == $c) {
                        $printClassifications[$i][$s . ', ' . $classification['source']] = $c;
                        unset($printClassifications[$i][$s]);
                    }
		        }
		    }
		}
	}

	// Finally we can print the lot...
	foreach ($printClassifications as $pC) {
    	foreach ($pC as $source => $sClassification) {
    	    $output .= "<h4 class='source'>$source</h4>" .
    			"<div class='property-list'>";
    		$classification = unserialize($sClassification);
    		foreach ($classification as $rank => $name) {
    			if (!empty($name)) {
    			    $output .= "<dl><dt>" . t($rank) . "</dt><dd>$name</dd></dl>";
    			}
    		}
    		$output .= "</div>";
    	}
	}


	return _wrap(
    $header . (!empty($output) ? $output : t('No classifications available')),
    "section",
    "result-detail-section"
  );
}


?>
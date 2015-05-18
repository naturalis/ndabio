<?php
/**
 * Prints classification(s)
 *
 * @param array $data Parsed json data
 * @return string Formatted output
 */
function printClassifications ($data) {
	global $language;
	$output = '';
	$header = "<h3>" . t('Classifications') . "</h3>";
	$printClassifications = array();
	// First merge two separate classification arrays
	foreach ($data['classifications']['default'] as $source => $classification) {
		$classifications[] = array(
			'source' =>  printSource($data, $source),
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
    			    if (in_array($rank, array(
        			    'genusOrMonomial',
        			    'genus',
        			    'subgenus',
        			    'specificEpithet',
        			    'infraspecificEpithet'
     			    ))) {
                        $name = '<span class="scientific">' . $name . '</span>';
    			    }
    			    $output .= "<dl><dt>" . ucfirst(translateNdaField($rank)) . "</dt><dd>$name</dd></dl>";
    			}
    		}
    		$output .= "</div>";
    	}
	}


	return _wrap(
    $header . (!empty($output) ? $output :
        "<p class='property-list'>" . t('No classifications available') . '</p>'),
    "section",
    "result-detail-section"
  );
}


?>
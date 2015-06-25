/**
 * Fetch the total number of results for NBA request
 *
 * Ajax call to fetch data for the given NBA request.
 * The result is passed on to a callback function printing the data.
 *
 * @param request The NBA request
 * @param callback The callback function
 *
 */function getTotal (request, callback) {
	jQuery.ajax({
		url: str_base_path + 'nba/ajax',
		type: "GET",
		dataType: "text",
		data: ({
			getTotal: 1,
			nba_request: request
		}),
		success: function (totalSize) {
			callback(request, totalSize);
		}
	});
}

function setTaxonSpecimenLink (request, total) {
	total = parseInt(total);
	if (total > 0) {
		var label = total == 1 ? Drupal.t('Specimen') : Drupal.t('Specimens');
		jQuery('#taxon_specimens').html('<a href="?nba_request=' + encodeURIComponent(request) + '&noMap">' + label + ' (' + total + ')</a>');
	} else {
		jQuery('#taxon_specimens').html(Drupal.t('No specimens available'));
	}
}


function setTaxonMultimediaLink (request, total) {
	total = parseInt(total);
	if (total > 0) {
		jQuery('#taxon_multimedia').html('<a href="?nba_request=' + encodeURIComponent(request) + '&noMap">Multimedia (' + total + ')</a>');
	} else {
		jQuery('#taxon_multimedia').html(Drupal.t('No multimedia available'));
	}
}


function setSpecimenMultimediaLink (request, total) {
	total = parseInt(total);
	if (total > 0) {
		jQuery('#specimen_multimedia').html('<a href="?nba_request=' + encodeURIComponent(request) + '&noMap">Multimedia (' + total + ')</a>');
	} else {
		jQuery('#specimen_multimedia').html(Drupal.t('No multimedia'));
	}
}


/**
 * Fetch data from NBA request for preview in detail pages
 *
 * Ajax call to fetch data for the given NBA request.
 * The results are passed on to a callback function printing the data.
 *
 * @param request The NBA request
 * @param callback The callback function
*/
function getPreview (request, callback) {
	jQuery.ajax({
		url: str_base_path + 'nba/ajax',
		type: "GET",
		dataType: "json",
		data: ({
			nba_request: request + '&_maxResults=5'
		}),
		success: function (response) {
			callback(request, response);
		}
	});
}


function setTaxonSpecimenPreview (request, data) {
	if (parseInt(data.totalSize) > 0) {
		jQuery('#taxon_specimens').html(printSpecimenPreview(request, data));
	} else {
		jQuery('#taxon_specimens').html(Drupal.t('No specimens available'));
	}
}


function setTaxonMultimediaPreview (request, data) {
	if (parseInt(data.totalSize) > 0) {
		jQuery('#taxon_multimedia').html(printMultimediaPreview(request, data));
	} else {
		jQuery('#taxon_multimedia').html(Drupal.t('No multimedia available'));
	}
}

function setSpecimenMultimediaPreview (request) {
	total = parseInt(total);
	if (total > 0) {
		jQuery('#specimen_multimedia').html('<a href="?nba_request=' + encodeURIComponent(request) + '&noMap">Multimedia (' + total + ')</a>');
	} else {
		jQuery('#specimen_multimedia').html(Drupal.t('No multimedia availabl'));
	}
}



/**
 * Generates "film strip" of first five multimedia results
 *
 * @param request The original NBA query to fetch the data
 * @param data The data themselves (complete response)
 * @returns {String} Formatted output
 */

function printMultimediaPreview (request, data) {
	var output = '<div class=​"multimedia-wrapper">​';
	for (i = 0; i < data.searchResults.length; i++) {
		var src = data.searchResults[i].result.serviceAccessPoints['MEDIUM_QUALITY'].accessUri;
		for (j = 0; j < data.searchResults[i].links.length; j++) {
			if (data.searchResults[i].links[j].rel == '_multimedia') {
				var url = data.searchResults[i].links[j].href;
			}
		}
		var source = data.searchResults[i].result.sourceSystem.name;
		var creator = data.searchResults[i].result.creator;
		output += '<a class="polaroid" href="?nba_request=' + encodeURIComponent(url) + '&noMap">' +
			'<div class="polaroid-image" style="background-image: url(' + src + ');" alt=""></div>';
		output += '<div class="polaroid-caption"><div class="image-title">' +
			source + '</div><div class="image-hits">' + creator + '</div></div></a>';
	};
	if (parseInt(data.totalSize) > 5) {
		output += '<a href="?nba_request=' + encodeURIComponent(request) + '&noMap">' +
			'<i class="icon-arrow-right"></i>' + Drupal.t('Show all') + ' ' + data.totalSize + ' ' +
			Drupal.t('multimedia') + '</a></div>';
	}
	return output;
}

/**
 * Generates list of first five specimen results
 *
 * @param request The original NBA query to fetch the data
 * @param data The data themselves (complete response)
 * @returns {String} Formatted output
 */

function printSpecimenPreview (request, data) {
	var output = '';
	for (i = 0; i < data.resultGroups.length; i++) {
		for (j = 0; j < data.resultGroups[i].searchResults.length; j++) {
			var unitID = data.resultGroups[i].searchResults[j].result.unitID;
			var collectionType = data.resultGroups[i].searchResults[j].result.collectionType;
			for (k = 0; k < data.resultGroups[i].searchResults[j].links.length; k++) {
				if (data.resultGroups[i].searchResults[j].links[k].rel == '_specimen') {
					var url = data.resultGroups[i].searchResults[j].links[k].href;
				}
			}
			output += '<dl><dt><a href="?nba_request=' +
				encodeURIComponent(url) + '&noMap">' + unitID + '</a></dt>';
			output += '<dd>' + collectionType + '</dd></dl>';
		}
	};
	if (parseInt(data.totalSize) > 5) {
		output += '<div style="margin-top: 12px;"><a href="?nba_request=' + encodeURIComponent(request) + '&noMap">' +
			'<i class="icon-arrow-right"></i>' + Drupal.t('Show all') + ' ' + data.totalSize + ' ' +
			Drupal.t('specimens') + '</a></div>';
	}
	return output;
}


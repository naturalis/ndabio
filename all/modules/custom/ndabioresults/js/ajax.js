// test comment
function getTotal (request, callback) {
	jQuery.ajax({
		url: str_base_path + 'nba/ajax',
		type: "GET",
		dataType: "text",
		data: ({
			nba_request: request,
			getTotal: 1
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
		jQuery('#taxon_specimens').html(Drupal.t('No specimens'));
	}
}


function setTaxonMultimediaLink (request, total) {
	total = parseInt(total);
	if (total > 0) {
		jQuery('#taxon_multimedia').html('<a href="?nba_request=' + encodeURIComponent(request) + '&noMap">Multimedia (' + total + ')</a>');
	} else {
		jQuery('#taxon_multimedia').html(Drupal.t('No multimedia'));
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

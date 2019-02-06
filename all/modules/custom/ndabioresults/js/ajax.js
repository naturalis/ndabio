function getBhlReferences (term) {
	// Separate NBA request from what is passed on to callback function
	jQuery.ajax({
		url: str_base_path + 'ajax',
		type: "GET",
		dataType: "json",
		data: ({
			term: term,
			source: 'bhl'
		}),
		success: function (data) {
			printBhlReferences(data, term);
		}
	});
}

function printBhlReferences (data, term) {
	var output = '';
	for (let i = 0; i < data.references.length; i++) {
		output += '<p><a href="' + data.references[i].url + '" target="_blank">' + data.references[i].title + '</a></p>';
	};
	if (output == '') {
		output += '<p>' + Drupal.t('No results for BHL catalogue search') + '</p>';
	}
	output += '<div style="margin-top: 12px;"><a href="https://www.biodiversitylibrary.org/search?searchTerm=' +
		term + '&stype=F" target="_blank">' + '<i class="icon-arrow-right"></i>' +
		Drupal.t('BHL full-text search') + '</a></div>';
	jQuery('#literature').html(output);
}

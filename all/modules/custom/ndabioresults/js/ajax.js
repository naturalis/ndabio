function getReferences (term) {
	var sources = {
		'wc': 'WorldCat',
		'bhl': 'Biodiversity Heritage Library'
	};
	jQuery.each(sources, function(source, name) {
		jQuery.ajax({
			url: str_base_path + 'ajax',
			type: "GET",
			dataType: "json",
			data: ({
				term: term,
				source: source
			}),
			success: function (data) {
				printReference(data, term, source, name);
			}
		});
	});
}

function printReference (data, term, source, name) {
	var output = '';
	for (let i = 0; i < data.references.length; i++) {
		output += '<p style="margin: 10px 0;"><a href="' + data.references[i].url + '" target="_blank">' + data.references[i].title + '</a></p>';
	};
	if (output == '') {
		output += '<p>' + Drupal.t('No results for ' + name) + '</p>';
	} else {
		output = '<p><strong>References found in ' + name + '</strong>:</p>' + output +
			'<div style="margin: 12px 0 30px 0;"><a href="' + data.source_url + '" target="_blank">' +
			'<i class="icon-arrow-right"></i>' + Drupal.t('Show all results for') + ' ' + name + '</a></div>';
	}
	jQuery('#' + source).html(output);
}

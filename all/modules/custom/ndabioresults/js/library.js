var mapcodeUrl = 'http://www.mapcode.com/getcoords.html?mapcode=';

function getMapcodes (y, x) {
	var results = [];
	for (var ct = 0; ct < MAX_CCODE; ct++) {
		var data = master_encode(y, x, ct);
		if (data.length) {
			for (var i = 0; i < data.length; i++) {
				results.push({
					mapcode: data[i][0],
					country: fullname(ct),
					iso: ccode2iso(ct)
				});
			}
		}
	}
	return results;
}

function setMapcode () {
	(function ($) {
		if (!specimenMarker) {
			return false;
		}
		var codes = getMapcodes(specimenMarker.lat, specimenMarker.lon);
		var str = printCountryMapcode(codes) + printInternationalMapcode(codes);
		$("dd#mapcode").html(str);
	}(jQuery));
}

function printInternationalMapcode (codes) {
	for (var i = 0; i < codes.length; i++) {
		if (codes[i].country == 'International') {
			return '<a target="_blank" href="' + mapcodeUrl + codes[i].iso + '%20' +
				codes[i].mapcode + '">' + codes[i].mapcode + '</a> (International)';
		}
	}
	return '';
}

function printCountryMapcode (codes) {
	var str = '';
	if (countCountries(codes) == 1) {
		for (var i = 0; i < codes.length; i++) {
			if (codes[i].country != 'International') {
				str += '<a target="_blank" href="' + mapcodeUrl + codes[i].iso + '%20' + codes[i].mapcode + '">' +
					codes[i].mapcode + '</a> (' + codes[i].country + ')<br>';
			}
		}
	};
	return str;
}

function countCountries (codes) {
	var j = 0;
	var previousCountry = '';
	var previousCode = '';
	for (var i = 0; i < codes.length; i++) {
		if (codes[i].country != 'International' && codes[i].country != previousCountry) {
			j++;
		}
		previousCountry = codes[i].country;
		previousCode = codes[i].mapcode;
	}
	return j;
}




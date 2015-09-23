var map, feature, geometry, drawingManager, selectedShape;
var markers = [];
var mapStyle = {
	fillColor: '#fff',
	fillOpacity: 0.2,
	strokeWeight: 2,
	strokeColor: '#fff',
	clickable: false,
	editable: false,
	zIndex: 1
}

var pin = {
    path: 'M18.2,11l-4.7,10.1C13.2,21.6,12.6,22,12,22c-0.6,0-1.2-0.4-1.5-0.9L5.8,11c-0.3-0.7-0.4-1.5-0.4-2.3 C5.3,5,8.3,2,12,2c3.7,0,6.7,3,6.7,6.7C18.7,9.5,18.6,10.3,18.2,11z M12,5.3c-1.8,0-3.3,1.5-3.3,3.3c0,1.8,1.5,3.3,3.3,3.3 c1.8,0,3.3-1.5,3.3-3.3C15.3,6.8,13.8,5.3,12,5.3z',
    fillColor: '#542e08',
    fillOpacity: 1,
    scale: 1,
    strokeColor: 'white',
    strokeWeight: 1,
    size: new google.maps.Size(14, 20),
    origin: new google.maps.Point(0, 0),
    anchor: new google.maps.Point(7, 20)
};

var overlapPin = {
    path: pin.path,
    fillColor: '#009ee0',
    fillOpacity: pin.fillOpacity,
    scale: pin.scale,
    strokeColor: 'black',
    strokeWeight: pin.strokeWeight,
    size: pin.size,
    origin: pin.origin,
    anchor: pin.anchor
};

function getShapeGeometry() {
	if (selectedShape.type == 'polygon') {
		return getPolygonGeometry();
	}
	return getRectangleGeometry();
}

function getPolygonGeometry() {
	var vertices = selectedShape.getPath();
	geometry = '{"type":"Polygon","coordinates":[[';

	// Iterate over the vertices.
	for (var i = 0; i < vertices.getLength(); i++) {
		var xy = vertices.getAt(i);
		if (i == 0) {
			var firstXy = xy;
		}
		geometry += '[' + xy.lng() + ',' + xy.lat() + '],'
	}
	// Add first lon/lat to complete the shape
	geometry += '[' + firstXy.lng() + ',' + firstXy.lat() + ']]]}';
	return geometry;
}


function getRectangleGeometry() {
	var bounds = selectedShape.getBounds();
	var NE = bounds.getNorthEast();
	var SW = bounds.getSouthWest();

	return '{"type":"Polygon","coordinates":[[' +
		'[' + SW.lng() + ',' + NE.lat() + '],' +
		'[' + NE.lng() + ',' + NE.lat() + '],' +
		'[' + NE.lng() + ',' + SW.lat() + '],' +
		'[' + SW.lng() + ',' + SW.lat() + '],' +
		'[' + SW.lng() + ',' + NE.lat() + ']]]}';
}

function initialize() {

	var mapOptions = {
		center: new google.maps.LatLng(setMapCenterLat(), setMapCenterLon()),
		mapTypeId: 'satellite',
		streetViewControl: false,
		zoom: setZoomLevel()
	};
	map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);

  drawingManager = new google.maps.drawing.DrawingManager({
    drawingtrol: true,
    drawingControlOptions: {
      position: google.maps.ControlPosition.TOP_CENTER,
      drawingModes: [
        google.maps.drawing.OverlayType.POLYGON,
        google.maps.drawing.OverlayType.RECTANGLE
      ]
    },
    polygonOptions: mapStyle,
    rectangleOptions: mapStyle
  });
  drawingManager.setMap(map);

  google.maps.event.addListener(drawingManager, 'overlaycomplete', function(e) {
     if (e.type != google.maps.drawing.OverlayType.MARKER) {
        // Switch back to non-drawing mode after drawing a shape.
        drawingManager.setDrawingMode(null);
		// Add an event listener that selects the newly-drawn shape when the user
        // mouses down on it.
        var newShape = e.overlay;
        newShape.type = e.type;
        google.maps.event.addListener(newShape, 'click', function() {
          setSelection(newShape);
        });
        setSelection(newShape);
      }
    });

 	google.maps.event.addListener(drawingManager, 'drawingmode_changed', clearMap);

 	if (storedGeoShape != -1) {
		feature = {
			type: "Feature",
			geometry: JSON.parse(storedGeoShape)
		};
		map.data.addGeoJson(feature);
		map.data.setStyle(mapStyle);
		zoom(map, false);
 	} else if (storedGid != -1) {
 		plotMapArea(storedGid, false);
 	}
}

/*
function initializeSpecimens() {
	var mapOptions = {
		  center: new google.maps.LatLng(setMapCenterLat(), setMapCenterLon()),
		  mapTypeId: 'satellite',
		  zoom: setZoomLevel()
		};
	map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);

	feature = {
		type: "Feature",
		geometry: geoShape
	};
	map.data.addGeoJson(feature);
	map.data.setStyle(mapStyle);
	zoom(map);

	var previousInfowindow = false;

	jQuery.each(specimenMarkers, function() {
		var myLatlng = new google.maps.LatLng(this.lat, this.lon);
		var marker = new google.maps.Marker({
	      position     : myLatlng,
	      name         : this.name,
	      icon         : pin,
	      assemblageID : this.assemblageID,
	      source       : this.source,
	      unitID       : this.unitID,
	      localityText : this.localityText,
	      date         : this.date,
	      taxonUrl     : this.taxonUrl,
	      url		   : this.url
		});

		var infowindow = new google.maps.InfoWindow({
		    content: createInfoText(marker),
		    maxWidth: 350
		});

		google.maps.event.addListener(marker, 'click', function() {
			if (previousInfowindow) {
				previousInfowindow.close();
		    }
			previousInfowindow = infowindow;
			infowindow.open(map, marker);
		});

		marker.setMap(map);
		markers.push(marker);
	});
}
*/

function initializeSpecimens() {
	var mapOptions = {
		  center: new google.maps.LatLng(setMapCenterLat(), setMapCenterLon()),
		  mapTypeId: 'satellite',
		  streetViewControl: false,
		  zoom: setZoomLevel()
		};
	map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);

	feature = {
		type: "Feature",
		geometry: geoShape
	};
	map.data.addGeoJson(feature);
	map.data.setStyle(mapStyle);
	zoom(map);

	var oms = new OverlappingMarkerSpiderfier(map, {
		markersWontMove: true,
		markersWontHide: true,
		legWeight: 1.2
	});
	oms.legColors.highlighted[google.maps.MapTypeId.SATELLITE] = '#c30041';
	var infowindow = new google.maps.InfoWindow({
	    maxWidth: 350
	});

	oms.addListener('click', function(marker, event) {
		infowindow.setContent(createInfoText(marker));
		infowindow.open(map, marker);
	});
    oms.addListener('spiderfy', function(markers) {
        for (var i = 0; i < markers.length; i++) {
        	markers[i].setIcon(overlapPin);
        }
        infowindow.close();
      });
      oms.addListener('unspiderfy', function(markers) {
        for (var i = 0; i < markers.length; i++) {
          markers[i].setIcon(pin);
        }
      });

	jQuery.each(specimenMarkers, function() {
		var myLatlng = new google.maps.LatLng(this.lat, this.lon);
		var marker = new google.maps.Marker({
	      position: myLatlng,
	      name: this.name,
	      icon: pin,
	      assemblageID: this.assemblageID,
	      source: this.source,
	      unitID: this.unitID,
	      localityText: this.localityText,
	      date: this.date,
	      taxonUrl: this.taxonUrl,
	      url: this.url
		});

		marker.setMap(map);
		oms.addMarker(marker);
		markers.push(marker);
	});
}

function initializeSpecimenDetail() {

	var myLatlng = new google.maps.LatLng(specimenMarker.lat, specimenMarker.lon);

	var mapOptions = {
		center: myLatlng,
		mapTypeId: 'satellite',
		zoom: 7
	};
	map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);

	var marker = new google.maps.Marker({
		position: myLatlng,
		icon: pin,
	});

	marker.setMap(map);
}


function createInfoText(marker) {
	var taxon = marker.taxonUrl == '' ? marker.name :
		'<a href="?nba_request=' + marker.taxonUrl + '">' + marker.name + '</a>';
	return '<div class="map-infoWindow">' +
		'<div class="marker-name" style="color:#000;">' + taxon + '</div>' +
		'<div class="marker-unitID">' + '<a href="?nba_request=' +
			marker.url + '">' + marker.unitID + '</a>' + '</div>' +
		'<div class="marker-source">' + marker.source + '</div>' +
		'<div class="marker-localityText">' +
			(marker.localityText != null ? marker.localityText : '-') + '</div>' +
		'<div class="marker-date">' +
			(marker.date != null ? marker.date : '-') + '</div>' +
		'</div>';
}


function clearSelection() {
    if (selectedShape) {
      selectedShape.setEditable(false);
      selectedShape = null;
    }
}

function setSelection(shape) {
    clearSelection();
    selectedShape = shape;
    shape.setEditable(true);
}


function plotMapArea(gid, fit) {

	if (!gid || typeof str_base_path == 'undefined') {
		return;
	}

	if (typeof fit == 'undefined') {
		var fit = true;
	}

	jQuery.ajax({
		url: str_base_path + 'naturalis/ajax',
		type: "GET",
		dataType: "json",
		data: ( {nid: gid} ),
		success: function (json) {
			clearMap();
			if (json) {
				geometry = json.geometry;
				feature = {
					type: "Feature",
					locality: json.locality,
					source: json.source,
					geometry: geometry
				};

				map.data.addGeoJson(feature);
				map.data.setStyle(mapStyle);
				zoom(map, fit);
				jQuery('.geo-search-area-name').html(json.locality);
			} else {
				alert('Failed to retrieve area data.');
			}

		}
	});
}

function clearMapSessionData () {
	jQuery.ajax({
		url: str_base_path + 'naturalis/clear_map_data',
		type: "GET",
		dataType: "text",
		success: function (result) {
			//console.log(result);
		}
	});
}

function getZoom() {
	return map.getZoom();
}

// Gets map center, formatted at lat,lon
function getMapCenter() {
	var c = map.getCenter();
	return c.lat() + ','  + c.lng();
}

function setMapCenterLat () {
	if (typeof storedMapCenter == "undefined" || storedMapCenter == "") {
		return 52.175010314147784;
	}
	return parseFloat(storedMapCenter.split(',')[0]);
}

function setMapCenterLon () {
	if (typeof storedMapCenter == "undefined" || storedMapCenter == "") {
		return 5.273959999999988;
	}
	return parseFloat(storedMapCenter.split(',')[1]);
}

function setZoomLevel () {
	if (typeof storedZoomLevel == "undefined" || storedZoomLevel == -1) {
		return 7;
	}
	return storedZoomLevel;
}


/*
function setDrawingMode(mode) {
	drawingManager.setDrawingMode(mode);
}
*/

function clearMap() {
	jQuery('.geo-search-area-name').html('');
    clearMapSessionData();
	map.data.forEach(function(_feature) {
		map.data.remove(_feature);
	});
    if (selectedShape) {
      selectedShape.setMap(null);
    }
    selectedShape = null;
}

/**
 * Update a map's viewport to fit each geometry in a dataset
 * @param {google.maps.Map} map The map to adjust
 */
function zoom (map, fit) {
	if (typeof fit == 'undefined') {
		fit = true;
	}
	var bounds = new google.maps.LatLngBounds();
	map.data.forEach(function(feature) {
		processPoints(feature.getGeometry(), bounds.extend, bounds);
	});
	// Fit map to boundaries of geo shape
	// Alternative is to keep stored zoom level and map center
	if (fit || typeof storedZoomLevel == 'undefined' || storedZoomLevel == -1 ||
		typeof storedMapCenter == 'undefined' || storedMapCenter == '') {
		map.fitBounds(bounds);
	}
}

/**
 * Process each point in a Geometry, regardless of how deep the points may lie.
 * @param {google.maps.Data.Geometry} geometry The structure to process
 * @param {function(google.maps.LatLng)} callback A function to call on each
 *     LatLng point encountered (e.g. Array.push)
 * @param {Object} thisArg The value of 'this' as provided to 'callback' (e.g.
 *     myArray)
 */
function processPoints (geometry, callback, thisArg) {
  if (geometry instanceof google.maps.LatLng) {
    callback.call(thisArg, geometry);
  } else if (geometry instanceof google.maps.Data.Point) {
    callback.call(thisArg, geometry.get());
  } else {
    geometry.getArray().forEach(function(g) {
      processPoints(g, callback, thisArg);
    });
  }
}



//Sets the map on all markers in the array.
function setAllMap(map) {
	for (var i = 0; i < markers.length; i++) {
		markers[i].setMap(map);
	}
}

//Removes the markers from the map, but keeps them in the array.
function clearMarkers() {
	setAllMap(null);
}

//Shows any markers currently in the array.
function showMarkers() {
	setAllMap(map);
}

//Deletes all markers in the array by removing references to them.
function deleteMarkers() {
	clearMarkers();
	markers = [];
}



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
	for (var i =0; i < vertices.getLength(); i++) {
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
	  center: new google.maps.LatLng(52.1, 5),
	  mapTypeId: 'satellite',
	  zoom: 8
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
		zoom(map);
 	} else if (storedGid != -1) {
 		plotMapArea(storedGid, str_base_path);
 	}
}

function initializeSpecimens() {
	var mapOptions = {
		center: new google.maps.LatLng(52.1, 5),
		mapTypeId: 'satellite',
		zoom: 8
	};
	map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);

	feature = {
		type: "Feature",
		geometry: geoShape
	};
	map.data.addGeoJson(feature);
	map.data.setStyle(mapStyle);
	zoom(map);

  var obj_pin = {
    path         : 'M18.2,11l-4.7,10.1C13.2,21.6,12.6,22,12,22c-0.6,0-1.2-0.4-1.5-0.9L5.8,11c-0.3-0.7-0.4-1.5-0.4-2.3 C5.3,5,8.3,2,12,2c3.7,0,6.7,3,6.7,6.7C18.7,9.5,18.6,10.3,18.2,11z M12,5.3c-1.8,0-3.3,1.5-3.3,3.3c0,1.8,1.5,3.3,3.3,3.3 c1.8,0,3.3-1.5,3.3-3.3C15.3,6.8,13.8,5.3,12,5.3z',
    fillColor    : '#542e08',
    fillOpacity  : 1,
    scale        : 1,
    strokeColor  : 'white',
    strokeWeight : 1
  };


	jQuery.each(specimenMarkers, function() {
		var myLatlng = new google.maps.LatLng(this.lat, this.lon);
		var marker = new google.maps.Marker({
      position     : myLatlng,
      name         : this.name,
      icon         : obj_pin,
      assemblageID : this.assemblageID,
      unitID       : this.unitID,
      localityText : this.localityText,
      date         : this.date,
		});

		var infowindow = new google.maps.InfoWindow({
		    content: createInfoText(marker),
        maxWidth: 400
		});

		google.maps.event.addListener(marker, 'click', function() {
		    infowindow.open(map, marker);
		});

		marker.setMap(map);
		markers.push(marker);
	});
}

function initializeSpecimenDetail() {

	var myLatlng = new google.maps.LatLng(specimenMarker.lat, specimenMarker.lon);

	var mapOptions = {
		center: myLatlng,
		mapTypeId: 'satellite',
		zoom: 8
	};
	map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);

	var marker = new google.maps.Marker({
		position: myLatlng,
	});

	marker.setMap(map);
}


function createInfoText(marker) {
	return '<div class="map-infoWindow">' +
		'<div class="marker-name">' + marker.name + '</div>' +
		'<div class="marker-unitID">' + marker.unitID + '</div>' +
		'<div class="marker-source">' + marker.source + '</div>' +
		'<div class="marker-localityText">' + marker.localityText + '</div>' +
		'<div class="marker-date">' + (marker.date != null ? marker.date : '-') + '</div>' +
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


function plotMapArea(gid, baseurl) {

	if (!gid) return;

	jQuery.ajax({
		url: baseurl + 'naturalis/ajax',
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
				zoom(map);
			} else {
				alert('Failed to retrieve area data.');
			}

		}
	});
}

/*
function setDrawingMode(mode) {
	drawingManager.setDrawingMode(mode);
}
*/

function clearMap() {
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
function zoom(map) {
  var bounds = new google.maps.LatLngBounds();
  map.data.forEach(function(feature) {
    processPoints(feature.getGeometry(), bounds.extend, bounds);
  });
  map.fitBounds(bounds);
}

/**
 * Process each point in a Geometry, regardless of how deep the points may lie.
 * @param {google.maps.Data.Geometry} geometry The structure to process
 * @param {function(google.maps.LatLng)} callback A function to call on each
 *     LatLng point encountered (e.g. Array.push)
 * @param {Object} thisArg The value of 'this' as provided to 'callback' (e.g.
 *     myArray)
 */
function processPoints(geometry, callback, thisArg) {
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

  // ---------------------------------------------------------
  // Load VIEWS via AJAX upon click into #search-areas-list
  // ---------------------------------------------------------

(function ($, Drupal) { Drupal.behaviors.ndabio = { attach: function(context, settings) {

	$_geo_filter          = $("#search-areas-filter"); // input for filtering areas
	$_search_areas_target = $("#search-areas-target"); // target div for list of areas


	// Load VIEWS with areas upon click on area-type
	$("a[data-rel='ajax']").click(function(){ str_url = $(this).attr("href");

		var $_active_link = $(this);

		$_geo_filter.val("");

		$_active_link.css( 'cursor', 'wait' );
		$("a[data-rel='ajax']").parent().removeClass("active");
		$_active_link.parent().addClass("active");

		// AJAX
		$.get( str_url, function( data ) {

			$_active_link.css( 'cursor', 'pointer' );

			$_search_areas_target.html( data );

			// Handle click on area
			$_search_areas_target.find('.row-area a').click(function() {

				$(".row-area a").removeClass("active");
				$(this).addClass("active");
				$('.geo-search-area-name').html( $(this).html()  );
				plotMapArea(this.id.substr(4),str_base_path);
				return false;

			});

		});

		return false;
	})

	// Simulate click on first area-type
	$("a[data-rel='ajax']")
		.first()
			.trigger("click");


	// Filter results when typing
	$_geo_filter.on("keyup", function(){

		var str_value = $(this).val();

				// Search through alphabetic groups
				$_search_areas_target.find("ul").each(function() {
						str_titel = $(this).text();

						if (str_titel.toLowerCase().search(str_value.toLowerCase()) > -1) {
								$(this).parent().show();
						}
						else {
								$(this).parent().hide();
						}
				});

				// Search through individual text items
				$_search_areas_target.find("li a").each(function() {
            str_titel = $(this).text();

						if (str_titel.toLowerCase().search(str_value.toLowerCase()) > -1) {
                $(this).parent().show();
            }
            else {
                $(this).parent().hide();
            }
        });
	});

	// Add labels to the omnibox
	// A bit dirty, but where else to put it?
	$("#edit-term")
		.attr("placeholder","« " + Drupal.t('All records') + " »");

	$(".fieldset-omnisearch.form-wrapper .large-offset-2")
		.removeClass("large-offset-2")
		.before("<div class='small-2 large-2 columns geo-search-label'>" + Drupal.t('Search') + ":</div>");

	$(".fieldset-omnisearch.form-wrapper .fieldset-wrapper")
		.append("<div class='row collapse'><div class='small-2 large-2 columns geo-search-label'>" + Drupal.t('Within') + ":</div><div class='geo-search-area-name'></div></div");




} }; })(jQuery, Drupal);


(function ($) {
	$(function() {
		$("#ndabio-advanced-taxonomysearch").submit(function(e) {
			var gid = '';
			var location = '';
			var geoShape = '';
			// Rectangle/polygon
			if (selectedShape) {
				var geoShape = getShapeGeometry();
			// Selected area
			} else if (feature) {
				var a = $("#search-areas-target a.active");
				var gid = a.attr("id").substr(4) ;
				var location = a.text();
				var geoShape = JSON.stringify(geometry);
			}
			$(this).append("<input name='gid' value='" + gid + "' type='hidden'>");
			$(this).append("<input name='location' value='" + location + "' type='hidden'>");
			$(this).append("<input name='geoShape' value='" + geoShape + "' type='hidden'>");
			return true;
		});
	});
})(jQuery);

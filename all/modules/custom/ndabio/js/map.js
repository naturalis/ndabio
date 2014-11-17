
var map, feature, geometry, drawingManager, selectedShape;
var mapStyle = {
	fillColor: '#fff',
	fillOpacity: 0.25,
	strokeWeight: 2,
	strokeColor: '#fff',
	clickable: false,
	editable: false,
	zIndex: 1
}

function postShape() {
	if (selectedShape) {
		alert(getShapeGeometry());
	} else if (feature) {
		//var g = $("#search-areas-target").find("a.active");
		alert(JSON.stringify(geometry));
	}
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
    //google.maps.event.addListener(map, 'click', clearMap);
    //google.maps.event.addDomListener(document.getElementById('delete-button'), 'click', clearMap);
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

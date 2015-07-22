(function ($, Drupal) { Drupal.behaviors.validate = { attach: function(context, settings) {

  // ---------------------------------------------------------
  // SEARCH FORM: form validation
  // ---------------------------------------------------------

  $("#ndabio-advanced-taxonomysearch").submit(function(){

    var $_omnibox              = $("#edit-term");

    int_valid = 0;



      // If there's more then one textfield with containing more
      // then three characters:
      $(this).find('input[type=text], select').each(function(){
        str_val = $(this).val();
        if( str_val != "" && str_val.length > 2) {
          int_valid += 1;
        }
      });

      // 'select boxes' also count as valid choices, ofcourse
      $(this).find('select').each(function(){
        str_val = $(this).val();
        if( str_val != "" ) {
          int_valid += 1;
        }
      });

      // If the simple search is entered, but too short:
      str_val = $($_omnibox).val();
      if( str_val != "" && str_val.length < 2){
        int_valid = 0;
      }

      // If we're on the geo-search page
      if ( $("body").hasClass("page-geographic-search") ){

    	  if (selectedShape) {
    		  int_valid = 1;
    	  }
    	  map.data.forEach(function() {
    		  int_valid = 1;
    	  });
      }



    // Done validating, let's face the consquences:

    if (int_valid < 1){

      if ( $("body").hasClass("page-geographic-search") ){

        alert(
          Drupal.t(
            "Please, select an area or draw one on the map."
          )
        );

      } else {

        alert(
          Drupal.t(
            "Please, make sure that you complete " +
            "at least one field and that it contains more " +
            "then three characters."
          )
        );

      }

      return false;

    } else {

      preloader();

    }

  });
} }; })(jQuery, Drupal);


(function ($) {
	$(function() {
		$("#ndabio-advanced-taxonomysearch").submit(function(e) {
			var gid = '';
			var location = '';
			var geoShape = '';
			var category = '';

			// From form, drawn area
			if (selectedShape) {
				geoShape = getShapeGeometry();
			// From selected area or previous search
			} else if (feature) {
				// From previous search, drawn area
				if (feature.geometry.type == 'Polygon') {
					geoShape = JSON.stringify(feature.geometry);
				} else {
					var target = $("#search-areas-target a.active").first();
					// From form, selected area
					if (target.length > 0) {
						gid = target.attr("id").substr(4) ;
						location = target.text();
						$("#search-areas-types ul li").each(function(i){
							if ($(this).hasClass('active')) {
								category = i;
							}
						});
					// From previous search, selected area
					} else {
						gid = storedGid;
					}
					geoShape = JSON.stringify(geometry);
				}
			}

			$(this).append("<input name='gid' value='" + gid + "' type='hidden'>");
			$(this).append("<input name='location' value='" + location + "' type='hidden'>");
			$(this).append("<input name='category' value='" + category + "' type='hidden'>");
			$(this).append("<input name='geoShape' value='" + geoShape + "' type='hidden'>");
			$(this).append("<input name='mapCenter' value='" + getMapCenter() + "' type='hidden'>");
			$(this).append("<input name='zoomLevel' value='" + getZoom() + "' type='hidden'>");

			return true;
		});
	});
})(jQuery);

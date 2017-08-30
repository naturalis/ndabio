(function ($, Drupal) { Drupal.behaviors.validate = { attach: function(context, settings) {

  // ---------------------------------------------------------
  // SEARCH FORM: form validation
  // ---------------------------------------------------------
	
	/*

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



    // Done validating, let's face the consequences:

    if (int_valid < 1){

      if ( $("body").hasClass("page-geographic-search") ){

        alert(
          Drupal.t("Please, select an area or draw one on the map. This can be combined with a text search.")
        );

      } else {

        alert(
          Drupal.t("Please, make sure that you complete at least one field containing at least three characters.")
        );

      }

      return false;

    } else {

      preloader();

    }

  });
} }; })(jQuery, Drupal);

*/
	
	// Rewritten
	
	 $("#ndabio-advanced-taxonomysearch").submit(function(){

    var $_omnibox              = $("#edit-term");

    var isValid = false;
    var dataEntered = false;
    var minStringLength = 3;
    var searchTerm = '';

    // BIOPORVTWO-299: skip test for advanced search
    // Adapted for multiselects; parse these in separate loop
      $(this).find('input[type=text], select').not('select[multiple]').each(function() {
    	  searchTerm = $(this).val().trim();
    	  if (searchTerm != "") {
    		  dataEntered = true;
    		  isValid = true;
    	  }
      });
      
      // Multiselects
      $(this).find('select[multiple]').each(function() {
    	  searchTerm = $(this).val();
    	  if (searchTerm != null) {
    		  dataEntered = true;
    		  isValid = true;
    	  }
      });

      // If the simple search is entered, but too short:
      searchTerm = $($_omnibox).val().trim();
      if (searchTerm != "") {
    	  dataEntered = true;
    	  if (searchTerm.length < minStringLength) {
    		  isValid = false;
    	  }
      }

      // If we're on the geo-search page
      if ( $("body").hasClass("page-geographic-search") ){
    	  if (selectedShape || feature) {
     		  dataEntered = true;
    		  isValid = true;
    	  }
      }
      
//alert(searchTerm);
      
    // Done validating, let's face the consequences:
    if (!isValid || !dataEntered) {

      if ( $("body").hasClass("page-geographic-search") ){

        alert(
        	Drupal.t("Please, select an area or draw one on the map. This can be combined with a text search.")
        );

      } else if (!dataEntered) {

        alert(
        	Drupal.t("Please make sure that you enter at least one search field.")
        );

      } else {
    	  
    	  alert(
              Drupal.t("Search field should contain at least " + minStringLength + " characters.")
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
			
			if ($("body").hasClass("page-geographic-search")) {
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
							gid = target.attr("id");
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
						geoShape = '';
					}
				}
				
				$(this).append("<input name='gid' value='" + gid + "' type='hidden'>");
				$(this).append("<input name='location' value='" + location + "' type='hidden'>");
				$(this).append("<input name='category' value='" + category + "' type='hidden'>");
				$(this).append("<input name='geoShape' value='" + geoShape + "' type='hidden'>");
				$(this).append("<input name='mapCenter' value='" + getMapCenter() + "' type='hidden'>");
				$(this).append("<input name='zoomLevel' value='" + getZoom() + "' type='hidden'>");

			}

			return true;
		});
	});
})(jQuery);

function clearForm () {
	// Reset entire form
	jQuery('#ndabio-advanced-taxonomysearch').trigger('reset');
	// Force all selects to default (was missed by reset above...)
	jQuery('select').val('');
	// Uncheck all radio buttons
	jQuery('input[type=radio]').prop('checked', false);
	// Check all 'Or' options
	jQuery('#edit-s-andor-0').prop("checked", true)
	jQuery('#edit-m-andor-0').prop("checked", true)
	jQuery('#edit-t-andor-0').prop("checked", true);
}




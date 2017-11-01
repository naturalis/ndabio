(function ($, Drupal) { Drupal.behaviors.validate = { attach: function(context, settings) {

  // ---------------------------------------------------------
  // SEARCH FORM: form validation
  // ---------------------------------------------------------

	
$("#ndabio-advanced-taxonomysearch").submit(function(event){

    var $_omnibox              = $("#edit-term");
    var simpleSearchTerm = $($_omnibox).val().trim();
    
    var nrSimpleTermsElements = 0;
    var nrSimpleTermsElementsTooShort = 0;

    var isValid = false;
    var dataEntered = false;
    var minStringLength = 3;
    var maxMultiSelectValues = 5;
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
    	  if ($($_omnibox).val().trim() == '' && searchTerm != null && searchTerm.length > maxMultiSelectValues) {
    		  
    		  var message = Drupal.t("You have selected [nr] values, the maximum is [max] per field.");
    		  alert(message.replace("[nr]", searchTerm.length).replace("[max]", maxMultiSelectValues));
    		  event.preventDefault();
    		  exit;
    		  
    	  } else if (searchTerm != null) {
    		  
    		  dataEntered = true;
    		  isValid = true;
    		  
    	  } 

      });
      
      // Simple search
      if (simpleSearchTerm != "") {
    	  
	      // Entire search string is too short
	      if (simpleSearchTerm.length < minStringLength) {
	    	  isValid = false;
	    		
		  // Total simple search string is long enough, but check individual element of simple search term.
	      // At least one element should be longer than minimum length!
	      } else {
	    	  
		      $.each(simpleSearchTerm.split(" "), function(index, searchTerm) {
		          if (searchTerm.trim() != "") {
		        	  dataEntered = true;
		        	  nrSimpleTermsElements++;
		        	  if (searchTerm.trim().length < minStringLength) {
		        		  nrSimpleTermsElementsTooShort++;
		        	  }
		          }
		      });
		      
		      if (nrSimpleTermsElements > 1 && nrSimpleTermsElements == nrSimpleTermsElementsTooShort) {
				  isValid = false;
		      }
	      }
      }
 
      // If we're on the geo-search page
      if ( $("body").hasClass("page-geographic-search") ){
    	  if (selectedShape || feature) {
     		  dataEntered = true;
    		  isValid = true;
    	  }
      }
      
      
    // Done validating, let's face the consequences:
    if (!isValid || !dataEntered) {

      if ($("body").hasClass("page-geographic-search")){
        
    	alert(
        	Drupal.t("Please, select an area or draw one on the map. This can be combined with a text search.")
        );
 
      } else if (!dataEntered) {

        alert(
        	Drupal.t("Please make sure that you enter at least one search field.")
        );

  	  // Entire simple search term is too short
      } else if (simpleSearchTerm != "" && simpleSearchTerm.length < minStringLength) {
    	  
    	  var message = Drupal.t("Your search term should contain at least [nr] characters.") + 
    	  	  " " + Drupal.t("This limitation does not apply to advanced search!");
 		  alert(message.replace("[nr]", minStringLength));
   	          	  
 	  // Entire simple search term is long enough but all individuel element are too short
      } else if (simpleSearchTerm != "" && nrSimpleTermsElements == nrSimpleTermsElementsTooShort) {
    	  
    	  var message = Drupal.t("All elements in your search term are too short. At least one element should contain at least [nr] characters. ") +
		     Drupal.t("This limitation does not apply to advanced search!");
 		  alert(message.replace("[nr]", minStringLength));
    	  
      }
	 
      event.preventDefault();

    } else {

      //preloader();

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
					// From form, selected area
					var target = $("#search-areas-target a.active").first();
					if (target.length > 0) {
						gid = target.attr("id");
						location = target.text();
						$("#search-areas-types ul li").each(function(i){
							if ($(this).hasClass('active')) {
								category = i;
							}
						});
					// From previous search, selected area
					} else if (storedGid != -1) {
						gid = storedGid;
					// From previous search, drawn area
					} else if (feature.geometry.type == 'Polygon') {
						geoShape = JSON.stringify(feature.geometry);
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
	
	// Map
	if (typeof clearMap === 'function') {
		clearMap();
	}
}




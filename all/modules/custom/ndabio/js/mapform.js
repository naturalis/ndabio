// ---------------------------------------------------------
// Load VIEWS via AJAX upon click into #search-areas-list
// ---------------------------------------------------------

(function ($, Drupal) { Drupal.behaviors.ndabio = { attach: function(context, settings) {

	$_geo_filter          = $("#search-areas-filter"); // input for filtering areas
	$_search_areas_target = $("#search-areas-target"); // target div for list of areas


    // Make the geographic search area behave as dropdown

    // - Add Drop Down button to  'within' field
    $("<div class='ndabio-toggle-area icon-triangle-down' />")
        .insertAfter( '#geo-search-area-name' )
        .click(function(){
            $("#area").slideToggle("expanded");

            $(".ndabio-toggle-area")
                .toggleClass("icon-triangle-down")
                .toggleClass("icon-triangle-up");

            $("#area-wrapper")
                .toggleClass("background-ghost");
        });

    $("#geo-search-area-name").click(function(){
        $(".ndabio-toggle-area")
            .trigger("click");
        return false; // prevent default behaviour
    });

    $("#area").slideUp(1000);


	// Load VIEWS with areas upon click on area-type
	$("a[data-rel='ajax']").click(function(){

		str_url = $(this).attr("href");

		var $_active_link = $(this);

		$_geo_filter.val("");

		$_active_link.css( 'cursor', 'wait' );
		$("a[data-rel='ajax']").parent().removeClass("active");
		$_active_link.parent().addClass("active");

		// AJAX
		$.get( str_url, function( data ) {

			$_active_link.css( 'cursor', 'pointer' );

			$_search_areas_target.html( data );

			// Select appropriate name if coming from modify search
			if (storedGid != -1) {
				var target = $_search_areas_target.find('.row-area a#gid_' + storedGid);
				if (target.length > 0) {
					target.addClass('active');
					$_search_areas_target.scrollTo(target);
				} else {
					$_search_areas_target.scrollTo(0);
				}
			}

			// Handle click on area-name
			$_search_areas_target.find('.row-area a').click(function() {
                $("#geo-search-area-name").val( $(this).html() );
                $(".row-area a").removeClass("active");
                $(this).addClass("active");
                plotMapArea(this.id.substr(4));
                return false;

			});

		});

		return false;
	})

	// Simulate click on first area-type
	if (typeof storedCategory != "undefined" && storedCategory == -1) {
		$("a[data-rel='ajax']").first().trigger("click");
	// User returns from modify search
	} else {
		// Select appropriate search-areas-type and -target
		$("a[data-rel='ajax']").eq(storedCategory).trigger("click");
	}

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

} }; })(jQuery, Drupal);


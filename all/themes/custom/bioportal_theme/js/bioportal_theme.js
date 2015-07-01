(function ($, Drupal) { Drupal.behaviors.bioportal_theme = { attach: function(context, settings) {

    var is_front = $("body").hasClass("front");


  // ---------------------------------------------------------
  // auto fit height of MAIN CONTAINER
  // ---------------------------------------------------------

    var h = $(window).height();
    var w = $(window).width();

    if (  $("body").hasClass("front") && w >= 640 ){
      $("main").css("min-height",h - 170 - 160);
    } else {
      $("main").css("min-height",h - 170);
    }


  // ---------------------------------------------------------



  // ---------------------------------------------------------
  // RESPONSIVE MAGIC
  // ---------------------------------------------------------

    // If were're viewing our site on a mobile device…
    if ( w < 640 ){

      // set auto-height of main container
      $("main").css("min-height",h - 170 );

      // Turn word 'search' into magnifier class

      if (is_front){
          $("#edit-submit-top")
              .html("<span class='icon-search'></span>");
      }

      //Re-phrase language names
      $("#language-menu [href*='language=en']").html("English");
      $("#language-menu [href*='language=nl']").html("Nederlands");

      // Geogrpahical search needs some serious re-work.
      // - Hide the map

      $("<a>Watch or draw on map</a>").prependTo("#geographical-search")

      $("#geographical-search")
      .hide();
    }

  // ---------------------------------------------------------


  // ---------------------------------------------------------
  // HEADER IMAGES
  // ---------------------------------------------------------

    // (We use jQuery for repositioning, to keep the CSS clean)

    if (    $('#naturalis-header').length ) {

      rl_margin =  (  $(".page").outerWidth() - $("main").outerWidth()  ) / 2;

      // If the page is wide enough:
      // - Move the header image to the root of the DOM
      // - Move the language menu to the root of the DOM
      // - Move the help icon to the root of the DOM

      if ( w >= 1024 ){

        // Move image in the DOM and re-position
        $("#header-image img")
          .appendTo(".page")
          .removeAttr('width')
          .removeAttr('height')
          .css({position: "absolute", top: 0, right: rl_margin  , width: 320, maxWidth: "27%", height: "auto", zIndex: 600, });

        $("#language-menu")
          .appendTo(".page")
          .css({zIndex:601, listStyle: "none inside none", position: "fixed", top: 10, right: (rl_margin + 50) });

        $("#help")
          .appendTo(".page")
          .css({zIndex:602, position: "fixed", height: "auto", width: "auto", margin: 0, padding: 0, right: rl_margin, top: 0, listStyle: "none inside none"})
            .find('span')
              .css({color: '#fff', border: 0, position: "relative"});

      } else {
        // Else, remove the header image
        $("#header-image img").remove();

      }

    }
  // ---------------------------------------------------------



  // ---------------------------------------------------------
  // INTRO (read more)
  // ---------------------------------------------------------

  if ( $("body").hasClass("front") ){
    var $_header          = $("#naturalis-header");
    var $_intro_more_link = $(".intro-more", $_header);
    var $_intro_less_link = $(".intro-less", $_header);
    var $_intro_block     = $(".intro-block", $_header);
    var $_title_slogan    = $("#title-and-slogan", $_header);
    var display = false;

    $_intro_more_link
      .show();

    $_title_slogan
      .click(function(){
        $_header
          .toggleClass("background-purple")
          .toggleClass("background-gray-9");
        if ($_intro_less_link.css('display') == 'none') {
        	$_intro_less_link.show();
      	}
        $_intro_less_link
	    	.click(function() {
	    		$(this).hide();
	    	})
        $_title_slogan.toggleClass("off-canvas");
      });

  }

  // ---------------------------------------------------------


  // ---------------------------------------------------------
  // SEARCH FORM: hide/show advanced search
  // ---------------------------------------------------------

  var $_advanced_search_form = $("#edit-extended");

  if ( $_advanced_search_form.length ){

    var $_omnibox              = $("#edit-term");
    var $_submit               = $("#edit-submit-top");
    var $_fieldset_omnisearch  = $(".fieldset-omnisearch");
    var $_bottom_submit        = $("#edit-submit-bottom");
    var int_x                  = $_bottom_submit.offset().left;
    var int_y                  = $_bottom_submit.offset().top;

    // -- search form: hide advanced search
    $_advanced_search_form.slideUp(0);

    // -- search form: add dropdown button to omni-search box
    $_omnibox.wrap("<div class='ndabio-omnibox-wrapper'></div>");

    // -- search form: behaviour for dropdown button
    $_omnibox.removeAttr("disabled");
    $_submit.removeAttr("disabled");

    $("<div class='ndabio-toggle-advanced icon-triangle-down' />")
      .insertAfter( $_omnibox )
      .click(function(){
        $_fieldset_omnisearch.toggleClass("disabled");
        $_omnibox.toggleAttr("disabled").toggleClass("disabled");

            if ( is_front) $_submit.toggleAttr("disabled").toggleClass("disabled");


        $(this).toggleClass("icon-triangle-down").toggleClass("icon-triangle-up");


                $_bottom_submit.css("opacity","0");

                $_advanced_search_form
                    .slideToggle(400, function(){
                        int_x = $_bottom_submit.offset().left;
                        int_y = $_bottom_submit.offset().top;

                        $(window).trigger('scroll');

                        if ( is_front ) $_bottom_submit.css("opacity", "1");

                    });



        // Exchange value with placeholder value
        if ($_omnibox.val() !== ""){
          $_omnibox.attr("placeholder", $_omnibox.val()  );
          $_omnibox.val("");
        } else {
          $_omnibox.val( $_omnibox.attr("placeholder") );
          $_omnibox.removeAttr("placeholder");
        }

      })
  }

  // ---------------------------------------------------------



  // ---------------------------------------------------------
  // SEARCH FORM: prevent submit button from scrolling of the page
  // ---------------------------------------------------------

  if ( $_advanced_search_form.length  && $("body").hasClass("front") ){
    $(window).scroll(function(){

        var objectTop = $_bottom_submit.position().top;
        var objectHeight = $_bottom_submit.outerHeight();
        var windowScrollTop = $(window).scrollTop();
        var windowHeight = $(window).height();

        if ( ( int_y - windowHeight  )  > (windowScrollTop - objectHeight) && w >= 1024 ){
          $_bottom_submit.css({position:"fixed", bottom: "0px", left: int_x})
        } else {
          $_bottom_submit.removeAttr("style");
          int_y = $_bottom_submit.offset().top;
        }
    });
  }

  // ---------------------------------------------------------


  // ---------------------------------------------------------
  // SEARCH FORM: clear text fields
  // ---------------------------------------------------------

  // Create the clear icon
  $("<div class='ndabio-clear-textfield icon-cross hidden' />")
    .insertAfter("input[data-clear]")
    .click(function(){
      $(this)
        .addClass("hidden")
        .prev()
          .val("");
    })
    .parent()
    .addClass("input-clearable")

  // Toggle visibility of the clear icon depending on whether or
  // not the field has content
  $("input[data-clear]")
    .each(function(){
      $_me = $(this);

      if ($_me.val() != ""){
        $_me.next().removeClass("hidden");
      }

    })
    .on('keyup',function(e){

      $_me = $(this);

      if ($_me.val() != ""){
        $_me.next().removeClass("hidden");
      } else {
        $_me.next().addClass("hidden");
      }


      // submit form on enter
      if (e.keyCode == 13) {
        $("#ndabio-advanced-taxonomysearch").submit();
      }

    });

  // ---------------------------------------------------------
  // SEARCH FORM: reset button
  // ---------------------------------------------------------

  // We clear the fields instead of reloaden - this is faster

  $("#edit-reset").click(function(){

    $("input[type='text']").removeAttr("value");
    $("input[value='0']").attr("checked","checked");
    $("select option:first").attr('selected','selected');
    $("fieldset fieldset.collapsible:not(.collapsed) a").trigger("click");

  });

    // ---------------------------------------------------------




  // ---------------------------------------------------------
  // SEARCH FORM: explode expanded search
  // ---------------------------------------------------------

  	if (typeof expandAdvanced != 'undefined' && expandAdvanced == 1) {
  		$(".icon-triangle-down").trigger("click");
  	}
    // ---------------------------------------------------------



  // ---------------------------------------------------------
  // SEARCH FORM: IMPLODE/EXPLODE RESULTS TABLE
  // ---------------------------------------------------------

  // For each species name...
  $("#specimensByTaxon .indent-0 td:first-child")

    .each(function(){
      // Add a triangle to species-name
      $(this).find("a").first().prepend("<i class='icon-triangle-right'></i>");
    })

    .click( function(){

      $_me = $(this).parent();
      str_id = $_me.attr('id');

      $_me.
        toggleClass("expanded");

      // toggle trianlge class
      $_me.find("i")
        .toggleClass("icon-triangle-right")
        .toggleClass("icon-triangle-down");

      // show / hide specimens and specimen-collections
      $("[data-parent='"+ str_id +"']")
        .toggleClass("hidden");

      $("[data-parent='"+ str_id +"-collection']")
        .toggleClass("hidden");

      return false;
    });

  $(".indent-1, .indent-2","#specimensByTaxon").addClass("hidden");

  // Simulate click on first element, to expand it again:
  $("#specimensByTaxon .indent-0 a")
    .first()
      .trigger("click");

  // ---------------------------------------------------------



  // ---------------------------------------------------------
  // HELP: Quick 'n' Dirty solution for linking to help items
  // ---------------------------------------------------------


  if ( $_advanced_search_form.length ){

    var $_fieldset = $("#edit-extended > div > fieldset[id^='edit']");
    var lang = "en";
    if ( $('body').hasClass( "lang-nl" ) ) {
      lang = "nl";
    }


    $_fieldset.each(function(){
      $_me = $(this);

      str_anchor = $_me.attr("id");

      str_anchor = str_anchor.substring(5);

      str_anchor = "/" + lang + "/help#" + str_anchor + "?language=" + lang;

      $_me
        .children(":first")
          .children(":first")
            .wrap("<a class='to-help' target='_blank' href='"+str_anchor+"'></a>");

    })

  }
  // ---------------------------------------------------------

} }; })(jQuery, Drupal);


jQuery.fn.toggleAttr = function(a, b) {
    var c = (b === undefined);
    return this.each(function() {
        if((c && !jQuery(this).is("["+a+"]")) || (!c && b)) jQuery(this).attr(a,a);
        else jQuery(this).removeAttr(a);
    });
};

  // ---------------------------------------------------------
  // PRELOADER: remove upon clicking browser back-button
  // ---------------------------------------------------------


//http://stackoverflow.com/a/18120786/960592
Element.prototype.remove = function() {
    this.parentElement.removeChild(this);
}

NodeList.prototype.remove = HTMLCollection.prototype.remove = function() {
    for(var i = 0, len = this.length; i < len; i++) {
        if(this[i] && this[i].parentElement) {
            this[i].parentElement.removeChild(this[i]);
        }
    }
}

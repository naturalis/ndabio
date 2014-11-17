(function ($, Drupal) { Drupal.behaviors.bioportal_theme = { attach: function(context, settings) {


  // ---------------------------------------------------------
  // auto fit height of MAIN CONTAINER
  // ---------------------------------------------------------

    h = $(window).height();
    $("main").css("min-height",h - 315); // Magic number,...
  
  // ---------------------------------------------------------


 
  // ---------------------------------------------------------
  // HEADER IMAGES
  // ---------------------------------------------------------

    // (We use jQuery for repositioning, to keep the CSS clean)

    if (    $('#naturalis-header').length ) {
      rl_margin =  (  $(".page").outerWidth() - $("main").outerWidth()  ) / 2;

      // Move image in the DOM and re-position
      $("#header-image img")
        .appendTo(".page")
        .removeAttr('width')
        .removeAttr('height')
        .css({
          position: "absolute",
          top: 0, // magic number...?
          right: rl_margin  ,
          width: 320,
          maxWidth: "27%", 
          height: "auto",
          zIndex: 600,
      });

      
      $("#language-menu")
        .appendTo(".page")
        .css({
          zIndex:601,
          listStyle: "none inside none",
          position: "fixed",
          top: 10,
          right: (rl_margin + 50)
        })

      
      $("#help")
        .appendTo(".page")
        .css({
          zIndex:602,
          position: "fixed",
          height: "auto",
          width: "auto",
          margin: 0,
          padding: 0,
          right: rl_margin,
          top: 0,
          listStyle: "none inside none"
        })
          .find('span')
            .css({
              color: '#fff',
              border: 0,
              // right: -5,
              position: "relative"
            })
    }
  // ---------------------------------------------------------



  // ---------------------------------------------------------
  // INTRO (more)
  // ---------------------------------------------------------

  if ( $("body").hasClass("front") ){
    var $_header          = $("#naturalis-header");
    var $_intro_more_link = $(".intro-more", $_header);
    var $_intro_less_link = $(".intro-less", $_header);
    var $_intro_block     = $(".intro-block", $_header);
    var $_title_slogan    = $("#title-and-slogan", $_header);

    $_intro_more_link
      .show()

    $_title_slogan
      .click(function(){
        $_header
          .toggleClass("background-purple")
          .toggleClass("background-gray-9")
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
        $_submit.toggleAttr("disabled").toggleClass("disabled");
        
        $(this).toggleClass("icon-triangle-down").toggleClass("icon-triangle-up");
        
        $_bottom_submit.css("opacity","0")

        $_advanced_search_form
          .slideToggle(400, function(){
            int_x = $_bottom_submit.offset().left;
            int_y = $_bottom_submit.offset().top;

            $(window).trigger('scroll');

            $_bottom_submit.css("opacity","1")
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

  if ( $_advanced_search_form.length ){
    $(window).scroll(function(){

        var objectTop = $_bottom_submit.position().top;
        var objectHeight = $_bottom_submit.outerHeight();
        var windowScrollTop = $(window).scrollTop();
        var windowHeight = $(window).height();

        if ( ( int_y - windowHeight  )  > (windowScrollTop - objectHeight) ){
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
  // PRELOADER
  // ---------------------------------------------------------
  

  // $( window ).unload(function() {}); // For the moment, we'll leave this function here


  function preloader(){
    $("body").addClass("fading");

    $_overlay = $("<div id='preloader'></div>")
      .appendTo("body")
      .css({ 
        width            : "200px",
        height           : "200px",
        backgroundColor  : "#444433",
        borderRadius     : "5px",
        position         : "absolute",
        top              : "50%",
        left             : "50%",
        marginLeft       : "-100px",
        zIndex           : 1000
      });

    $_canvas = $("<div id='canvas' />")
      .appendTo($_overlay)
      .css({ 
        width            : "10px",
        height           : "10px",
        position         : "absolute",
        left             : "50%",
        top              : "50%",
        overflow         : "show"
      })

      var b = 0.306349;

      var $_kernel = [];

      for (var n=0; n<63; n++){

        $_kernel[n] = $("<div class='kernel' />")
          .appendTo($_canvas)
          .css({
            width        : "10px",
            height       : "10px",
            background   : "white",
            position     : "absolute",
            borderRadius : "5px",
            left         : 0,
            top          : 0
          })
      }

    var t=-63;
    var go_up = true;

    window.setInterval(function() {
      if (go_up ){
        t += 0.2;
        if ( t> 0 ) go_up = false;
      } else {
        t -= 0.2;
        if ( t < -63 ) go_up = true;
      }

      for (var n=0; n<63; n++){
        k = t + n;
        if (k>0){
          var teta  = k * 2.3998277;
          var omega = n * 2.3998277;
          var r     = Math.round( 7 * Math.sqrt(k) );
          var num_x = Math.round( r * Math.cos(omega ) );
          var num_y = Math.round(r * Math.sin(omega  ));

          $_kernel[n].css({
            left         : num_x,
            top          : num_y
          });
        }

      }
    }, 25);


  }
  // ---------------------------------------------------------


  // ---------------------------------------------------------
  // SEARCH FORM: IMPLODE/EXPLODE RESULTS TABLE
  // ---------------------------------------------------------

  // For each species name...
  $("#specimensByTaxon .indent-0")
    
    .each(function(){
      // Add a triangle to species-name
      $(this).find("a").first().prepend("<i class='icon-triangle-right'></i>");
    })
    
    .click( function(){

      $_me = $(this);
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


} }; })(jQuery, Drupal);


jQuery.fn.toggleAttr = function(a, b) {
    var c = (b === undefined);
    return this.each(function() {
        if((c && !jQuery(this).is("["+a+"]")) || (!c && b)) jQuery(this).attr(a,a);
        else jQuery(this).removeAttr(a);
    });
};

jQuery.fn.swapValAndPlaceholder = function(a, b) {
    var c = (b === undefined);
    return this.each(function() {
        if((c && !jQuery(this).is("["+a+"]")) || (!c && b)) jQuery(this).attr(a,a);
        else jQuery(this).removeAttr(a);
    });
};

(function ($, Drupal) { Drupal.behaviors.bioportal_theme = { attach: function(context, settings) {

  // ---------------------------------------------------------
  // auto fit height of MAIN CONTAINER
    h = $(window).height();
    $("main").css("min-height",h-150);
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

  if ( $("body").hasClass("front")  ){
    var $_advanced_search_form = $("#edit-extended");
    var $_omnibox              = $("#edit-term");
    var $_submit               = $("#edit-submit");
    var $_fieldset_omnisearch  = $(".fieldset-omnisearch");
    var $_bottom_submit        = $("#edit-submit--2");
    var int_x                  = $_bottom_submit.offset().left;
    var int_y                  = $_bottom_submit.offset().top;

    // console.log($_advanced_search_form.length);
    // console.log($_omnibox             .length);
    // console.log($_submit              .length);
    // console.log($_fieldset_omnisearch .length);
    // console.log($_bottom_submit       .length);


    // -- search form: hide advanced search
    $_advanced_search_form.slideUp(0);

    // -- search form: add dropdown button to omni-search box
    $_omnibox.wrap("<div class='ndabio-omnibox-wrapper>'</div>");

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
      })
  }

    // $(".ndabio-toggle-advanced").trigger("click");

  // ---------------------------------------------------------



  // ---------------------------------------------------------
  // SEARCH FORM: prevent submit button from scrolling of the page
  // ---------------------------------------------------------

  //  $_bottom_submit --> see above

  if ( $("body").hasClass("front") ){

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
    .on('keypress',function(){

      $_me = $(this);

      if ($_me.val() != ""){
        $_me.next().removeClass("hidden");
      } else {
        $_me.next().addClass("hidden");
      }
  });
  // ---------------------------------------------------------


  // ---------------------------------------------------------
  // PRELOADER
  //preloader();

  function preloader(){
    $_overlay = $("<div id='preloader'></div>")
      .appendTo("body")
      .css({ width: "100%", height: "100%", backgroundColor: "rgba(0,0,0,0.5)", position: "absolute", top: 0, left: 0, zIndex: 1000 } );

    $_canvas = $("<div id='canvas' />")
      .appendTo($_overlay)
      .css({ width: "10px", height: "10px", position: "absolute", left: "50%", top: "50%", overflow: "show" })

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
    window.setInterval(function() {
      for (var n=0; n<63; n++){
        k = t + n;
        t+= 0.002;
        if (k>0){
          var teta  = k * 2.3998277;
          var r     = 10 * Math.sqrt(k);
          var num_x = r * Math.cos(teta);
          var num_y = r * Math.sin(teta);

          $_kernel[n].css({
            left         : num_x,
            top          : num_y
          });
        }

      }
    }, 100);


  }
  // ---------------------------------------------------------


  // ---------------------------------------------------------
  // SEARCH FORM: IMPLODE/EXPLODE RESULTS TABLE
  // ---------------------------------------------------------

  $("#specimensByTaxon .indent-0")
    .each(function(){
      $(this).find("a").first().prepend("<i class='icon-triangle-right'></i>");
    })
    .click( function(){
      $_me = $(this);
      str_id = $_me.attr('id');

      $_me.find("i")
        .toggleClass("icon-triangle-right")
        .toggleClass("icon-triangle-down");
      
      $("[data-parent='"+ str_id +"']")
        .toggleClass("hidden");

      $("[data-parent='"+ str_id +"-collection']")
        .toggleClass("hidden");

      return false;
    });
  
  $(".indent-1, .indent-2","#specimensByTaxon").addClass("hidden");

} }; })(jQuery, Drupal);

jQuery.fn.toggleAttr = function(a, b) {
    var c = (b === undefined);
    return this.each(function() {
        if((c && !jQuery(this).is("["+a+"]")) || (!c && b)) jQuery(this).attr(a,a);
        else jQuery(this).removeAttr(a);
    });
};

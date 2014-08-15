(function ($, Drupal) { Drupal.behaviors.bioportal_theme = { attach: function(context, settings) {

  // ---------------------------------------------------------
  // auto fit height of MAIN CONTAINER
    h = $(window).height();
    $("main").css("min-height",h-150);
  // ---------------------------------------------------------

  // ---------------------------------------------------------
  // INTRO (more)

  var $_header          = $("#naturalis-header");
  var $_intro_more_link = $(".intro-more", $_header);
  var $_intro_block     = $(".intro-block", $_header);
  var $_title_slogan    = $("#title-and-slogan", $_header);

  $_intro_more_link
    .show()
    .click(function(){
      $_header
        .toggleClass("background-purple")
        .toggleClass("background-gray-9")
        $_title_slogan.toggleClass("off-canvas");
    })


  // ---------------------------------------------------------


  // ---------------------------------------------------------
  // SEARCH FORM: hide/show advanced search

    var $_advanced_search_form = $("#ndabio-advanced-search");
    var $_omnibox              = $("#edit-ndabio-adv");

    // -- search form: hide advanced search
    $_advanced_search_form.slideUp(0);

    // -- search form: add dropdown button to omni-search box
    $_omnibox.wrap("<div class='ndabio-omnibox-wrapper>'</div>");

    // -- search form: behaviour for dropdown button

    $_omnibox.removeAttr("disabled");

    $("#edit-submit").removeAttr("disabled");

    $("<div class='ndabio-toggle-advanced icon-triangle-down' />")
      .insertAfter( $_omnibox )
      .click(function(){
        $("#edit-omnisearch").toggleClass("disabled");
        $_omnibox.toggleAttr("disabled").toggleClass("disabled");
        $("#edit-submit").toggleAttr("disabled").toggleClass("disabled");
        $(this).toggleClass("icon-triangle-down").toggleClass("icon-triangle-up");
        $_advanced_search_form.slideToggle();
      })

  // ---------------------------------------------------------


  // ---------------------------------------------------------
  // PRELOADER
  // preloader();

  function preloader(){
    $_overlay = $("<div id='preloader'></div>")
      .appendTo("body")
      .css({ width: "100%", height: "100%", backgroundColor: "rgba(0,0,0,0.5)", position: "absolute", top: 0, left: 0, zIndex: 1000 } );

    $_canvas = $("<div id='canvas' />")
      .appendTo($_overlay)
      .css({ width: "10px", height: "10px", position: "absolute", left: "50%", top: "50%", overflow: "show" })

      var b = 0.306349;

      for (var n=0; n<63; n++){
        var teta  = n * 2.3998277;
        var r     = 10 * Math.sqrt(n)
        var num_x = r * Math.cos(teta);
        var num_y = r * Math.sin(teta);

        $_kernel = $("<div class='kernel' />")
          .appendTo($_canvas)
          .css({
            width: "10px",
            height: "10px",
            background: "white",
            position: "absolute",
            borderRadius: "5px",
            left: num_x + "px",
            top: num_y + "px"
          })

      }

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

(function ($, Drupal) { Drupal.behaviors.bioportal_theme = { attach: function(context, settings) {

  // Auto fit height of main container
  h = $(window).height();
  $("main").css("min-height",h-150);

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


} }; })(jQuery, Drupal);

jQuery.fn.toggleAttr = function(a, b) {
    var c = (b === undefined);
    return this.each(function() {
        if((c && !jQuery(this).is("["+a+"]")) || (!c && b)) jQuery(this).attr(a,a);
        else jQuery(this).removeAttr(a);
    });
};

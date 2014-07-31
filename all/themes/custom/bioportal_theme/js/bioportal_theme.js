(function ($, Drupal) {

  Drupal.behaviors.bioportal_theme = {
    attach: function(context, settings) {
      h = $(window).height();
      $("main").css("min-height",h-150);
    }
  };

})(jQuery, Drupal);

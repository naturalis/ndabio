(function ($, Drupal) { Drupal.behaviors.validate = { attach: function(context, settings) {

  // ---------------------------------------------------------
  // SEARCH FORM: form validation
  // ---------------------------------------------------------

  $("#ndabio-advanced-taxonomysearch").submit(function(){
    
    var $_omnibox              = $("#edit-term");

    int_valid = 0;
    
    // If we're on the geo-search page
    if ( $("body").hasClass("page-geographic-search") ){

      int_valid = 1;
      
    } else {
    // If we're not on the geo-searh page
      

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
    }

    // Done validating, let's face the consquences:

    if (int_valid < 1){
      
      alert(
        "Please, make sure that you complete \n" +
        "at least one field and that it contains more\n" +
        "then three characters.\n" 
      );

      return false;

    } else {
      
      //preloader();

    }

  });
} }; })(jQuery, Drupal);

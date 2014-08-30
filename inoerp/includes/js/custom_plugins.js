(function($) {
//form get sub inventory
 $.fn.getSubInventoryFromOrg = function(options) {

  var defaults = {
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   subinventory_class: '.subinventory_id',
  };
  var settings = $.extend({}, defaults, options);
  var methods = {
   jsonSubinventory: function() {
    var org_id = $(this).val();
    $.ajax({
     url: settings.json_url,
     data: {org_id: org_id,
      find_all_subinventory: 1},
     type: 'get',
     beforeSend: function() {
      $('.show_loading_small').show();
     },
     complete: function() {
      $('.show_loading_small').hide();
     }
    }).done(function(result) {
     var div = $(result).filter('div#json_subinventory_find_all').html();
     $('#content').find(settings.subinventory_class).empty().append(div);
     return div;
    }).fail(function() {
     alert("org name loading failed");
    }).always(function() {
     $('#loading').hide();
    });
    $(".form_table .from_subinventory_id").attr("disabled", false);
   },
  };

  return this.each(function() {
   $(this).on('change', methods.jsonSubinventory);
  });
 };

 //form get locator from sub inventory -- Not working
 $.fn.getLocatorFromSubInventory = function(options) {
  var defaults = {
   json_url: 'modules/inv/locator/json_locator.php',
   subinventory_type: 'subinventory',
  };
  var settings = $.extend({}, defaults, options);
  var methods = {
   jsonLocator: function() {
    var subinventory_id = $(this).val();
    var trClass = '.' + $(this).closest('tr').attr('class');
    $.ajax({
     url: settings.json_url,
     data: {
      subinventory_id: subinventory_id,
      find_all_locator: 1},
     type: 'get',
     beforeSend: function() {
      $('.show_loading_small').show();
     },
     complete: function() {
      $('.show_loading_small').hide();
     }
    }).done(function(result) {
     var div = $(result).filter('div#json_locator_find_all').html();
     switch (settings.subinventory_type) {
      case 'from_subinventory':
       alert(trClass);
       $(trClass + " .from_locator_id").find('option').remove();
       $(trClass + " .from_locator_id").empty().append(div);
       break;

      case 'to_subinventory':
       $(trClass + " .to_locator_id").find('option').remove();
       $(trClass + " .to_locator_id").empty().append(div);
       break;

      case 'oneSubinventory':
       $('#content').find(".locator_id").find('option').remove();
       $('#content').find(".locator_id").empty().append(div);
       break;

      case 'subinventory':
      case 'default':
       $('#content').find(".locator_id").find('option').remove();
       $('#content').find(".locator_id").empty().append(div);
       break;
     }
     $('#loading').hide();
    }).fail(function() {
     alert("Locator name loading failed");
     $('#loading').hide();
    });
    $(".form_table .from_locator_id").attr("disabled", false);
   },
  };

//  methods.jsonLocator.prototype.init = function() {
//   // Place initialization logic here
//   // You already have access to the DOM element and
//   // the options via the instance, e.g. this.element 
//   // and this.options
//   methods.jsonLocator;
//  };

// $(this).on('change', methods.jsonLocator);
  return this.each(function($this) {

    $(this).on('change', methods.jsonLocator);
   $this = $(this);
   $('#content').on('change', '.subinventory_id', function(){
    $(this).methods.jsonLocator();
   });
   return $this;
  });

 };

 //form amount validations
 $.fn.validateAmount = function(options) {
  var defaults = {
   header_amount_id: '#header_amount',
   line_amount_class: '.amount',
   remaining_amount_class: '.remaining_amount',
  };
  var methods = {
   checkHeaderAmount: function() {
    var totalAmount = 0;
    var header_amount = +$(defaults.header_amount_id).val();
    $(defaults.line_amount_class).each(function() {
     totalAmount += (+$(this).val());
    });
    if (totalAmount > header_amount) {
     $(defaults.header_amount_id).val('');
     alert('Sum of line amounts ' + totalAmount + ' is more than header amount ' + header_amount + '\n Re-enter Header Amount!');
    }
   },
   checkRemainingAmount: function() {
    var remainong_amount = +$(defaults.remaining_amount_class).val();
    var trClass = '.' + $(this).closest('tr').prop('class');
    if (remainong_amount < 0) {
     alert('Entered amount is more than remaining amount' + '\n Re-enter the amount!');
     $(this).val('');
     $('#form_line').find(trClass).find(defaults.line_amount_class).val('');
    }

   },
   hide: function( ) {
   },
  };

  return this.each(function() {
   var settings = $.extend({}, $.fn.validateAmount.defaults, options);
   $(this).on('blur', defaults.header_amount_id, methods.checkHeaderAmount);
   $(this).on('change', defaults.line_amount_class, methods.checkHeaderAmount);
   $(this).on('blur', defaults.remaining_amount_class, methods.checkRemainingAmount);
  });
 };
}(jQuery));
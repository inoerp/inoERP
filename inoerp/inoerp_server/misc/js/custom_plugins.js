(function ($) {
//form get sub inventory
 $.fn.getSubInventoryFromOrg = function (options) {

  var defaults = {
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   subinventory_class: '.subinventory_id',
  };
  var settings = $.extend({}, defaults, options);
  var methods = {
   jsonSubinventory: function () {
    var org_id = $(this).val();
    $.ajax({
     url: settings.json_url,
     data: {org_id: org_id,
      find_all_subinventory: 1},
     type: 'get',
     beforeSend: function () {
      $('.show_loading_small').show();
     },
     complete: function () {
      $('.show_loading_small').hide();
     }
    }).done(function (result) {
     var div = $(result).filter('div#json_subinventory_find_all').html();
     $('#content').find(settings.subinventory_class).empty().append(div);
     return div;
    }).fail(function () {
     alert("org name loading failed");
    }).always(function () {
     $('#loading').hide();
    });
    $(".form_table .from_subinventory_id").attr("disabled", false);
   },
  };

  return this.each(function () {
   $(this).on('change', methods.jsonSubinventory);
  });
 };

 //form get locator from sub inventory -- Not working
 $.fn.getLocatorFromSubInventory = function (options) {
  var defaults = {
   json_url: 'modules/inv/locator/json_locator.php',
   subinventory_type: 'subinventory',
  };
  var settings = $.extend({}, defaults, options);
  var methods = {
   jsonLocator: function () {
    var subinventory_id = $(this).val();
    var trClass = '.' + $(this).closest('tr').attr('class');
    $.ajax({
     url: settings.json_url,
     data: {
      subinventory_id: subinventory_id,
      find_all_locator: 1},
     type: 'get',
     beforeSend: function () {
      $('.show_loading_small').show();
     },
     complete: function () {
      $('.show_loading_small').hide();
     }
    }).done(function (result) {
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
    }).fail(function () {
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
  return this.each(function ($this) {

   $(this).on('change', methods.jsonLocator);
   $this = $(this);
   $('#content').on('change', '.subinventory_id', function () {
    $(this).methods.jsonLocator();
   });
   return $this;
  });

 };

 //form amount validations
 $.fn.validateAmount = function (options) {
  var defaults = {
   header_amount_id: '#header_amount',
   line_amount_class: '.amount',
   remaining_amount_class: '.remaining_amount',
  };
  var settings = $.extend({}, $.fn.validateAmount.defaults, options);
  var methods = {
   checkHeaderAmount: function () {
    var totalAmount = 0;
    var header_amount = +$(settings.header_amount_id).val();
    $(settings.line_amount_class).each(function () {
     totalAmount += (+$(this).val());
    });
    if (totalAmount > header_amount) {
     $(settings.header_amount_id).val('');
     alert('Sum of line amounts ' + totalAmount + ' is more than header amount ' + header_amount + '\n Re-enter Header Amount!');
    }
   },
   checkRemainingAmount: function () {
    var remainong_amount = +$(settings.remaining_amount_class).val();
    var trClass = '.' + $(this).closest('tr').prop('class');
    if (remainong_amount < 0) {
     alert('Entered amount is more than remaining amount' + '\n Re-enter the amount!');
     $(this).val('');
     $('#form_line').find(trClass).find(settings.line_amount_class).val('');
    }

   },
   hide: function ( ) {
   },
  };

  return this.each(function () {
   $(this).on('blur', settings.header_amount_id, methods.checkHeaderAmount);
   $(this).on('change', settings.line_amount_class, methods.checkHeaderAmount);
   $(this).on('blur', settings.remaining_amount_class, methods.checkRemainingAmount);
  });
 };

 //form amount validations
 $.fn.getAddressDetails = function (options) {
  var this_e = $(this);
  var defaults = {
   address_id: this_e.val()
  };
  var settings = $.extend({}, $.fn.getAddressDetails.defaults, options);

  return $.ajax({
   url: 'modules/org/address/json_address.php',
   data: {
    address_id: settings.address_id,
    find_address_details: 1},
   type: 'get',
   beforeSend: function () {
    $('.show_loading_small').show();
   },
   complete: function () {
    $('.show_loading_small').hide();
   },
   success: function (result) {
    $.each(result, function (key, value) {
     switch (key) {
      default :
       var className = '.' + key.replace(/\s+/g, '.');
       this_e.parent().parent().find(className).val(value);
       break;
     }
    });
    $('.show_loading_small').hide();
   },
   error: function (request, errorType, errorMessage) {
    alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
   }
  });
 };

 $.fn.inoAutoCompleteElement = function (options) {
  var this_e = $(this);
  var defaults = {
   min_length: 2,
   form_id: 'form_line',
   hidden_field_param: true,
   set_value_for_one_field: false
  };
  var settings = $.extend({}, defaults, options);
  var form_id_h = '#' + settings.form_id;
//  settings.select_class = $(this).attr('class').replace(/\s+/g, '.');

  var methods = {
   jsonAutoComplete: function () {
    if (settings.select_class === 'undefined') {
     settings.select_class = 'select' + settings.field_name;
    }

    if (!$(this).data("autocomplete")) {
     var auto_element = $(this);
     var auto_element_class = $(this).prop('class');
     var elemenType = $(this).parent().prop('tagName');
     var auto_element_class_d = '.' + auto_element_class.replace(/\s+/g, '.');
     if ($(this).attr('data-val_field') && $(this).attr('data-val_value')) {
      var val_field = $(this).data('val_field');
      var val_value = $(this).data('val_value');
     } else {
      var val_value = val_field = null;
     }

     if ($(this).attr('data-ac_type')) {
      var ac_type = $(this).data('ac_type');
     } else {
      var ac_type = null;
     }

     if ($(this).attr('data-ac_type')) {
      var ac_type = $(this).data('ac_type');
     } else {
      var ac_type = null;
     }

     var dependent_fields = {};
     if ($(auto_element).data('dependent_field')) {
      var dependent_field_a = $('.project_task_number').data('dependent_field').split(' ');
      if (elemenType === 'TD') {
       $(dependent_field_a).each(function (d_k, d_v) {
        var d_v_class = '.' + d_v;
        if ($(auto_element).closest('tr').find(d_v_class).val()) {
         dependent_fields[d_v] = $(auto_element).closest('tr').find(d_v_class).val();
        }
       });
      } else if (elemenType === 'LI') {
       $(dependent_field_a).each(function (d_k, d_v) {
        if ($('#content').find('#' + d_v).val()) {
         dependent_fields[d_v] = $('#content').find('#' + d_v).val();
        }
       });
      }
     }

     var hidden_fields = {};
     if (settings.hidden_field_param) {
      $(auto_element).siblings('input:hidden').each(function (hidden_k, hidden_v) {
       if (hidden_v) {
        var f_name = $(this).prop('name').replace(/\[]+/g, '');
        hidden_fields[f_name] = $(this).val();
       }
      });
     }

     var primary_column1_h = '#' + settings.primary_column1;
     if ($(primary_column1_h).val()) {
      var primary_column1_v = $(primary_column1_h).val();
     } else if ($(auto_element).closest("tr").attr('class')) {
      var trClass = '.' + $(auto_element).closest("tr").attr('class').replace(/\s+/g, '.');
      var primary_column1_d = '.' + settings.primary_column1;
      var primary_column1_v = $(form_id_h).find(trClass).find(primary_column1_d).val();
     }

     $(this).autocomplete({
      source: function (request, response) {
       $.ajax({
        url: settings.json_url,
        dataType: "json",
        data: {
         action: 'search',
         field_name: settings.field_name,
         primary_column1: primary_column1_v,
         primary_column2: settings.primary_column2,
         hidden_fields: hidden_fields,
         term: request.term,
         other_options: settings.other_options,
         ino_auto_complete: true,
         ac_type: ac_type,
         val_value: val_value,
         val_field: val_field,
         dependent_fields: dependent_fields
        },
        success: function (data) {
         response(data);
        },
        error: function (request, errorType, errorMessage) {
         alert("Error : " + errorType + ' with message ' + errorMessage);
         $(this).autocomplete("close");
        }
       });
      },
      autoFocus: true,
      response: function (event, ui) {
       if (ui.content.length === 1)
       {
        $(this).val(ui.content[0].value);
        $.each(ui.content[0], function (key, value) {
         var v_d = '.' + key;
         if (elemenType === 'LI') {
          if (key.substr(-3) === '_cb' && (value == 1)) {
           $(auto_element).closest("form").find(v_d).prop('checked', true);
          } else {
           if (settings.set_value_for_one_field === true) {
            $(auto_element_class_d).parent().find(v_d).val(value);
           } else {
            $(auto_element).closest("form").find(v_d).val(value);
           }
          }
         } else if (elemenType === 'TD') {
          var trClass = '.' + $(auto_element).closest("tr").attr('class').replace(/\s+/g, '.');
          if (key.substr(-3) === '_cb' && (value == 1)) {
           $(form_id_h).find(trClass).find(trClass).prop('checked', true);
          } else {
           if (settings.set_value_for_one_field === true) {
            $(auto_element_class_d).parent().find(v_d).val(value);
           } else {
            $(form_id_h).find(trClass).find(v_d).val(value);
           }

          }
         }
        });
        //close the auto complete
        $(this).autocomplete("close");
       } else if (ui.content.length === 0) {
        alert('No Data Found');
        this_e.attr('value', '').prop('value', '');
        //close the auto complete
        $(this).autocomplete("close");
       } else if (ui.content == 'false' || ui.content == false) {
        alert('No Data Found');
        this_e.attr('value', '').prop('value', '');
       }
      },
      //select
      select: function (event, ui) {
       $(this).val(ui.item.value);
       var elemenType = $(this).parent().prop('tagName');
       $.each(ui, function (key2, value) {
        $.each(value, function (value_k, value_v) {
         var v_d = '.' + value_k;
         if (elemenType === 'LI') {
          if (value_k.substr(-3) === '_cb' && (value_v == 1)) {
           $(auto_element).closest("form").find(v_d).prop('checked', true);
          } else {
           if (settings.set_value_for_one_field === true) {
            $(auto_element_class_d).parent().find(v_d).val(value_v);
           } else {
            $(auto_element).closest("form").find(v_d).val(value_v);
           }
          }
         } else if (elemenType === 'TD') {
          var trClass = '.' + $(auto_element).closest("tr").attr('class').replace(/\s+/g, '.');
          if (value_k.substr(-3) === '_cb' && (value_v == 1)) {
           $(form_id_h).find(trClass).find(v_d).prop('checked', true);
          } else {
           if (settings.set_value_for_one_field === true) {
            $(auto_element_class_d).parent().find(v_d).val(value_v);
           } else {
            $(form_id_h).find(trClass).find(v_d).val(value_v);
           }

          }
         }
        });
       });

       //close the auto complete
       $(this).autocomplete("close");
      },
      minLength: settings.min_length
     });
    }

   }
  };

  return this.each(function () {
   var select_class_d = '.' + $(this).attr('class').replace(/\s+/g, '.');
   $('body').on("focus.nsAutoComplete", select_class_d, methods.jsonAutoComplete);
  });
 };

 $.fn.getCompensationElementTemplate = function (options) {
  var defaults = {
   min_length: 3,
   form_id: 'form_line',
   json_url: 'modules/hr/element_entry/tpl/json_element_entry_tpl.php'
  };
  var settings = $.extend({}, defaults, options);
  var thisElement = $(this);
//  var trClass =  $(this).closest('tr').attr('class');
  var methods = {
   jsonValue: function () {
    $.ajax({
     url: settings.json_url,
     type: 'get',
     dataType: 'json',
     data: {
      find_element_entry_tpl: 1
     },
     success: function (result) {
      if (result) {
       var select_class_d = '.' + $(thisElement).attr('class').replace(/\s+/g, '.');
       if (settings.trDivId) {
        var select_stmt = '<select id="hr_element_entry_tpl_header_id" class="select hr_element_entry_tpl_header_id" name="hr_element_entry_tpl_header_id[]" style="max-width:95%;">';
       } else {
        var select_stmt = '<select class="select hr_element_entry_tpl_header_id" name="hr_element_entry_tpl_header_id[]" style="max-width:95%;">';
       }
       $.each(result, function (f_key, f_name) {
        select_stmt += '<option value="' + f_name.hr_element_entry_tpl_header_id + '">' + f_name.template_name + '</option>';
       });
       select_stmt += '</select>';
       if (settings.trDivId) {
        $('#hr_element_entry_tpl_header_id').replaceWith(select_stmt);
//        var trclass_d = '.' + trClass;
       } else {
        $(select_class_d).replaceWith(select_stmt);
       }
      }
     },
     complete: function () {
      $('.show_loading_small').hide();
     },
     beforeSend: function () {
      $('.show_loading_small').show();
     },
     error: function (request, errorType, errorMessage) {
      alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
     }
    });
   }
  };

  if ($(thisElement).length > 2) {
   var select_class_d = '.' + $(this).attr('class').replace(/\s+/g, '.');
   $('body').on("blur", select_class_d, methods.jsonValue).one();
  }
//  return this;
  return $(this);

 };
 
 $.fn.inoSerialLotDetails = function (options) {
 var this_e = $(this);
 var defaults = {
  min_length: 2,
  form_id: 'form_line',
  hidden_field_param: true,
  set_value_for_one_field: false
 };
 var settings = $.extend({}, defaults, options);
 var form_id_h = '#' + settings.form_id;
//  settings.select_class = $(this).attr('class').replace(/\s+/g, '.');

 var methods = {
  jsonAutoComplete: function () {
   var trClass = '.' + this_e.closest('tr').attr('class');
   var item_id_m = $('#content').find(trClass).find('.item_id_m').val();
   var from_org_id = $('#from_org_id').val();
   var from_subinventory_id = $('#content').find(trClass).find('.from_subinventory_id').val();
   if (item_id_m && from_org_id && from_subinventory_id) {
    getOnhandDetails({
     item_id_m: item_id_m,
     org_id: from_org_id,
     subinventory_id: from_subinventory_id,
     locator_id: $('#form_line').find(trClass).find('.from_locator_id').val(),
     trClass: trClass,
     fieldClass: 'from_current_onhand',
    });
   }


   /*Serial number details*/
   var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
   var trClass_d = '.' + trClass;
   var generation_type = $('#content').find(trClass_d).find('.serial_generation').val();
   if (!generation_type) {
    var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
    $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
    $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
//   alert('Item is not serial controlled.\nNo serial information \'ll be saved in database');
    return;
   }
   var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
   if (!itemIdM) {
    return;
   }

   getSerialNumber({
    'org_id': $('#from_org_id').val(),
    'status': 'IN_STORE',
    'item_id_m': itemIdM,
    'trclass': trClass,
    'current_subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
    'current_locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
   });


   /*Lot Details*/

   var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
   var trClass_d = '.' + trClass;
   var generation_type = $('#content').find(trClass_d).find('.lot_generation').val();

   if (!generation_type) {
    var field_stmt = '<input class="textfield lot_number" type="text" size="25" readonly name="lot_number[]" >';
    $('#content').find(trClass_d).find('.inv_lot_number_id').replaceWith(field_stmt);
    $('#content').find(trClass_d).find('.lot_number').replaceWith(field_stmt);
//   alert('Item is not lot controlled.\nNo lot information \'ll be saved in database');
    return;
   }
   var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
   if (!itemIdM) {
    return;
   }

   getlotNumber({
    'org_id': $('#from_org_id').val(),
    'status': 'ACTIVE',
    'item_id_m': itemIdM,
    'trclass': trClass,
    'subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
    'locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
   });


  }
 };

 return this.each(function () {
  var select_class_d = '.' + $(this).attr('class').replace(/\s+/g, '.');
  $('body').on("focus.nsAutoComplete", select_class_d, methods.jsonAutoComplete);
 });
};

}(jQuery));





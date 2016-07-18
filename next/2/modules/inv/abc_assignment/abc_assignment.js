//function setValFromSelectPage(inv_abc_assignment_header_id, item_id_m, item_number, item_description, uom_id,
//        inv_abc_valuation_id, valuation_name, scope_org_id) {
// this.inv_abc_assignment_header_id = inv_abc_assignment_header_id;
// this.item_id_m = item_id_m;
// this.item_number = item_number;
// this.item_description = item_description;
// this.uom_id = uom_id;
// this.inv_abc_valuation_id = inv_abc_valuation_id;
// this.valuation_name = valuation_name;
// this.scope_org_id = scope_org_id;
//}
//
//setValFromSelectPage.prototype.setVal = function () {
// var inv_abc_assignment_header_id = this.inv_abc_assignment_header_id;
// var item_id_m = this.item_id_m;
// var item_number = this.item_number;
// var item_description = this.item_description;
// var uom_id = this.uom_id;
//
// var rowClass = '.' + localStorage.getItem("row_class");
// var fieldClass = '.' + localStorage.getItem("field_class");
//
//
// if (inv_abc_assignment_header_id) {
//  $("#inv_abc_assignment_header_id").val(inv_abc_assignment_header_id);
// }
//
// var inv_abc_valuation_id = this.inv_abc_valuation_id;
// var valuation_name = this.valuation_name;
// var scope_org_id = this.scope_org_id;
//
// if (inv_abc_valuation_id) {
//  $("#inv_abc_valuation_id").val(inv_abc_valuation_id);
// }
// if (valuation_name) {
//  $("#valuation_name").val(valuation_name);
// }
// if (scope_org_id) {
//  $("#org_id").val(scope_org_id);
// }
//
// rowClass = rowClass.replace(/\s+/g, '.');
// fieldClass = fieldClass.replace(/\s+/g, '.');
// if (item_id_m) {
//  $('#content').find(rowClass).find('.item_id_m').val(item_id_m);
// }
// if (item_number) {
//  $('#content').find(rowClass).find('.item_number').val(item_number);
// }
// if (item_description) {
//  $('#content').find(rowClass).find('.item_description').val(item_description);
// }
// if (uom_id) {
//  $('#content').find(rowClass).find('.uom_id').val(uom_id);
// }
//
// localStorage.removeItem("row_class");
// localStorage.removeItem("field_class");
//
//};

function invValuationDetails(rowClass, element_type, element_value, inv_abc_valuation_id, json_url) {
 json_url = (typeof json_url !== 'undefined') ? json_url : 'modules/inv/abc_valuation/json_abc_valuation.php';
 inv_abc_valuation_id = (typeof inv_abc_valuation_id !== 'undefined') ? inv_abc_valuation_id : $('#inv_abc_valuation_id').val();
 $.ajax({
  url: json_url,
  type: 'get',
  dataType: 'json',
  data: {
   inv_abc_valuation_id: inv_abc_valuation_id,
   find_valuation_details: 1,
   element_type: element_type,
   element_value: element_value
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'seq_number':
       var className = '.assign_' + key;
       $('#content').find(rowClass).find(className).val(value);
       var item_percentage = +((value) / (+$('#total_no_of_items').val())) * 100;
       $('#content').find(rowClass).find('.assign_item_percentage').val(item_percentage);
       break;

      case 'cum_value':
       $('#content').find(rowClass).find('.assign_value').val(value);
       var val_percentage = +((value) / (+$('#total_value').val())) * 100;
       $('#content').find(rowClass).find('.assign_value_percentage').val(val_percentage);
       break;
     }
    });
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

$(document).ready(function () {

//  var Mandatory_Fields = ["#org_id", "First Select Org Name", "#item_number", "First Select Item Number"];
// select_mandatory_fields(Mandatory_Fields);
//
// $('body').off("click", '#form_line').on("click", '#form_line', function () {
//  if (!$('#inv_abc_assignment_header_id').val()) {
//   alert('No header Id : First enter/save header details');
//  } else {
//   var headerId = $('#inv_abc_assignment_header_id').val();
//   if (!$(this).find('.inv_abc_assignment_header_id').val()) {
//    $(this).find('.inv_abc_assignment_header_id').val(headerId);
//   }
//  }
//
// });

 //Popup for selecting 
// $(".inv_abc_assignment_header_id.select_popup").on("click", function () {
//  void window.open('select.php?class_name=inv_abc_assignment_header', '_blank',
//          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });
//
// //Popup for selecting
// $(".inv_abc_valuation_id.select_popup, #valuation_name").on("click", function () {
//  void window.open('select.php?class_name=inv_abc_valuation', '_blank',
//          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });

 $('#form_header').off('blur', '.assign_seq_number')
         .on('blur', '.assign_seq_number', function () {
          if ($(this).val() > +$('#total_no_of_items').val()) {
           alert('Wrong sequence number');
           $('#form_header').find('.assign_seq_number').not(':last').closest('tr').find((":input:not([readonly])")).val('');
           return false;
          }
          $(this).closest('tr').nextAll().not(':last').closest('tr').find((":input:not([readonly])")).val('');
          var thisValue = $(this).val();
          var doAjax = true;
          var trClass = $(this).closest('tr').prop('class');
          var trClass_d = '.' + trClass;

          $(trClass_d).closest('tbody').find('tr').each(function () {
           if ($(this).attr('class') === trClass) {
            return false;
           } else {
            if (+$(this).find('.assign_seq_number').val() > thisValue) {
             alert('Wrong sequence number');
             $('#form_header').find('.assign_seq_number').not(':last').closest('tr').find((":input:not([readonly])")).val('');
             doAjax = false;
             return;
            }
           }
          });

          if (doAjax) {
           invValuationDetails(trClass_d, 'seq_number', +$(this).val());
          }
         });

 $('#form_header').off('blur', '.assign_item_percentage')
         .on('blur', '.assign_item_percentage', function () {
          if ($(this).val() > 100) {
           alert('Invalid Percentage -  Value should be <= 100');
           $('#form_header').find('.assign_item_percentage').not(':last').closest('tr').find((":input:not([readonly])")).val('');
           return false;
          }
          $(this).closest('tr').nextAll().not(':last').closest('tr').find((":input:not([readonly])")).val('');
          var thisValue = $(this).val();
          var doAjax = true;
          var trClass = $(this).closest('tr').prop('class');
          var trClass_d = '.' + trClass;

          $(trClass_d).closest('tbody').find('tr').each(function () {
           if ($(this).attr('class') === trClass) {
            return false;
           } else {
            if (+$(this).find('.assign_item_percentage').val() > thisValue) {
             alert('Wrong percentage');
             $('#form_header').find('.assign_item_percentage').not(':last').closest('tr').find((":input:not([readonly])")).val('');
             doAjax = false;
             return;
            }
           }
          });

          if (doAjax) {
           var seq_value = parseInt((+$(this).val()) * (+$('#total_no_of_items').val()) / 100);
           seq_value = (seq_value == 0) ? 1 : seq_value;
           invValuationDetails(trClass_d, 'seq_number', seq_value);
          }
         });

 $('#form_header').off('blur', '.assign_value, .assign_value_percentage')
         .on('blur', '.assign_value, .assign_value_percentage', function () {
          if ($(this).hasClass('assign_value_percentage')) {
           var thisClass = 'assign_value_percentage';
           var element_value = parseInt((+$(this).val()) * (+$('#total_value').val()) / 100);
          } else {
           var thisClass = 'assign_value';
           var element_value = parseInt((+$(this).val()));
          }
          var thisClass_d = '.' + 'assign_value';
          //validate value is less than max mavue
          if (($(this).val() > 100) && ($(this).hasClass('assign_value_percentage') > 100)) {
           alert('Invalid Percentage -  Value should be <= 100');
           $('#form_header').find('.assign_item_percentage').not(':last').closest('tr').find((":input:not([readonly])")).val('');
           return false;
          } else if (($(this).val() > $('#total_value').val()) && ($(this).hasClass('assign_value') > 100)) {
           alert('Invalid Value');
           $('#form_header').find('.assign_item_percentage').not(':last').closest('tr').find((":input:not([readonly])")).val('');
           return false;
          }
          //
          $(this).closest('tr').nextAll().not(':last').closest('tr').find((":input:not([readonly])")).val('');
          var doAjax = true;
          var trClass = $(this).closest('tr').prop('class');
          var trClass_d = '.' + trClass;

          $(trClass_d).closest('tbody').find('tr').each(function () {
           if ($(this).attr('class') === trClass) {
            return false;
           } else {
            if (+$(this).find(thisClass_d).val() > element_value) {
             alert('Invalid Data ' + $(this).find(thisClass_d).val() + ' : ' + element_value);
             $('#form_header').find(thisClass_d).not(':last').closest('tr').find((":input:not([readonly])")).val('');
             doAjax = false;
             return;
            }
           }
          });

          if (doAjax) {
           element_value = (element_value == 0) ? 1 : element_value;
           invValuationDetails(trClass_d, 'cum_value', element_value);
          }
         });

});





function setValFromSelectPage(inv_count_header_id, item_id_m, item_number, item_description, uom_id,
 inv_abc_assignment_header_id, abc_assignment_name, org_id) {
 this.inv_count_header_id = inv_count_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.inv_abc_assignment_header_id = inv_abc_assignment_header_id;
 this.abc_assignment_name = abc_assignment_name;
 this.org_id = org_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var inv_count_header_id = this.inv_count_header_id;
 var inv_abc_assignment_header_id = this.inv_abc_assignment_header_id;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;

 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");


 if (inv_count_header_id) {
  $("#inv_count_header_id").val(inv_count_header_id);
 }

 var inv_abc_valuation_id = this.inv_abc_valuation_id;
 var abc_assignment_name = this.abc_assignment_name;
 var org_id = this.org_id;

 if (inv_abc_assignment_header_id) {
  $("#inv_abc_assignment_header_id").val(inv_abc_assignment_header_id);
 }
 if (abc_assignment_name) {
  $("#abc_assignment_name").val(abc_assignment_name);
 }
 if (org_id) {
  $("#org_id").val(org_id);
 }

 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (item_id_m) {
  $('#content').find(rowClass).find('.item_id_m').val(item_id_m);
 }
 if (item_number) {
  $('#content').find(rowClass).find('.item_number').val(item_number);
 }
 if (item_description) {
  $('#content').find(rowClass).find('.item_description').val(item_description);
 }
 if (uom_id) {
  $('#content').find(rowClass).find('.uom_id').val(uom_id);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");

};

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
  success: function(result) {
   if (result) {
    $.each(result, function(key, value) {
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
  complete: function() {
   $('.show_loading_small').hide();
  },
  beforeSend: function() {
   $('.show_loading_small').show();
  },
  error: function(request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

$(document).ready(function() {

 //Popup for selecting 
 $(".inv_count_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=inv_count_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".inv_abc_assignment_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=inv_abc_assignment_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

$('body').off('change','.subinventory_id').on('change','.subinventory_id', function(){
  	var trClass = '.' + $(this).closest('tr').attr('class');
	var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', trClass);

});


});





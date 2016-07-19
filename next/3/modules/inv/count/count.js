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

 $('body').on('change', '.subinventory_id', function () {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', trClass);

 });

 $('body').on('change', '#org_id', function () {
  $('.org_id').val($(this).val());
 });


});
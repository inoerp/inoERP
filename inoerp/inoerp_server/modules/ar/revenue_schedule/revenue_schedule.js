$(document).ready(function () {

 $('body').off('click', 'a.ar_revenue_schedule_id').on('click', 'a.ar_revenue_schedule_id', function (e) {
  e.preventDefault();
  var adjustment_type = $('#adjustment_type').val();
  var ar_transaction_header_id = $('#ar_transaction_header_id').val();
  var org_id = $('#org_id').val();
  var transaction_number = $('#transaction_number').val();
  var link = '&adjustment_type=' + adjustment_type;
  if (ar_transaction_header_id) {
   link += '&ar_transaction_header_id=' + ar_transaction_header_id;
  } else if (transaction_number) {
   link += '&transaction_number=' + transaction_number;
  }
  link += '&org_id=' + org_id;
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + link;
  getFormDetails(formUrl);
 }).one();


 $('body').off('blur', '.transaction_line_seq').on('blur', '.transaction_line_seq', function () {
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  if ($(this).find('option:selected').val() == 'undefined' || $(this).find('option:selected').val() == "") {
   $(trClass).find('.ar_transaction_line_id,.ar_transaction_header_id,.line_number,.item_id_m, .item_description, .inv_line_quantity .line_type.line_description').val('');
   return false;
  } else {
   var selected = $(this).find('option:selected');
   $(trClass).find('.ar_transaction_header_id').val($(selected).data('ar_transaction_header_id'));
   $(trClass).find('.line_number').val($(selected).data('line_number'));
   $(trClass).find('.item_id_m').val($(selected).data('item_id_m'));
   $(trClass).find('.item_description').val($(selected).data('item_description'));
   $(trClass).find('.inv_line_quantity').val($(selected).data('inv_line_quantity'));
   $(trClass).find('.inv_line_price').val($(selected).data('inv_line_price'));
   $(trClass).find('.inv_unit_price').val($(selected).data('inv_unit_price'));
   $(trClass).find('.line_type').val($(selected).data('line_type'));
   $(trClass).find('.ar_transaction_line_id').val($(selected).val());
   $(trClass).find('.line_description').val($(selected).data('line_description'));
   $(trClass).find('.exchange_rate').val(+$('#trnx_exchange_rate').val());
  }

 });
 
 $('body').off('blur', '.adjustment_quantity, .adjustment_amount, .exchange_rate').on('blur', '.adjustment_quantity, .adjustment_amount, .exchange_rate' , function(){
  var trClass =  '.' + $(this).closest('tr').attr('class').replace(/\s+/g,'.');
  var adjustment_quantity = +$(trClass).find('.adjustment_quantity').val();
  var adjustment_amount = +$(trClass).find('.adjustment_amount').val();
  var adjustment_amount_up = +$(trClass).find('.inv_unit_price').val()*adjustment_quantity;
  var exchange_rate = +$(trClass).find('.exchange_rate').val();
  
  if(!adjustment_amount){
    $(trClass).find('.adjustment_amount').val(adjustment_amount_up);
    adjustment_amount = adjustment_amount_up;
  }
  $(trClass).find('.gl_adjustment_amount').val(exchange_rate*adjustment_amount);
  
});

});
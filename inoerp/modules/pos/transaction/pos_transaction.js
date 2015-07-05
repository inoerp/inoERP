function setValFromSelectPage(pos_transaction_header_id) {
 this.pos_transaction_header_id = pos_transaction_header_id;
}

setValFromSelectPage.prototype.setVal = function () {

 if (this.pos_transaction_header_id) {
  $("#pos_transaction_header_id").val(this.pos_transaction_header_id);
 }

};



$(document).ready(function () {
 //Popup for selecting option type
 $(".pos_transaction_header_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=pos_transaction_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('#content').off('blur', '.item_number').on('blur', '.item_number', function () {
  if (!$(this).val()) {
   return true;
  }
  $(this).closest('tr').find('.quantity').val('1');
 });


//Calculate Line Amounts
 $('body').on('calPOSLineAmount', '.line_amount', function () {
  var line_amount_e = $(this);
  if ((!line_amount_e.closest('tr').find('.unit_price').val()) || (!line_amount_e.closest('tr').find('.unit_price').val())) {
   return true;
  }
  var unit_price = +line_amount_e.closest('tr').find('.unit_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var quantity = +line_amount_e.closest('tr').find('.quantity').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  if (line_amount_e.closest('tr').find('.discount_amount').val()) {
   var discount_amount = +line_amount_e.closest('tr').find('.discount_amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  } else {
   var discount_amount = 0;
  }
  var line_amount = (unit_price * quantity);
  var amount_after_discount = line_amount - discount_amount;
  line_amount_e.val(line_amount);
  $(this).closest('tr').find('.amount_after_discount').val(amount_after_discount);
 });

 $('#content').off('blur', '.unit_price, .quantity, .discount_amount').on('blur', '.unit_price, .quantity, .discount_amount', function () {
  $(this).closest('tr').find('.line_amount').trigger('calPOSLineAmount');
 });

 $('#content').off('blur', '.discount_code').on('blur', '.discount_code', function () {
  if (!$(this).val() || (isNaN($(this).val()))) {
   return true;
  }
  var discount_amount_per = +$(this).closest('tr').find('.discount_code').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var line_amount = +$(this).closest('tr').find('.line_amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var dicount_amount = (discount_amount_per * line_amount) / 100;
  $(this).closest('tr').find('.discount_amount').val(dicount_amount);
  $(this).closest('tr').find('.line_amount').trigger('calPOSLineAmount');
 });


 //Calculate Header Amounts
 $('body').on('calPOSHeaderAmount', '#total_amount', function () {
  var total_amount_e = $(this);
  var line_amount_sum = 0;
  var discount_amount_sum = 0;
  $('#form_line').find('.line_amount').each(function () {
   line_amount_sum += +$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  });

  $('#form_line').find('.discount_amount').each(function () {
   discount_amount_sum += +$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  });

  var total_amount = line_amount_sum - discount_amount_sum;
  total_amount_e.val(total_amount);
  $('#header_amount').val(line_amount_sum);
  $('#discount_amount').val(discount_amount_sum);
 });

 $('#content').off('blur', '.unit_price, .quantity, .discount_amount, .line_amount').on('blur', '.unit_price, .quantity, .discount_amount, .line_amount', function () {
  $('#total_amount').trigger('calPOSHeaderAmount');
 });


//Re calculate header amount on removing lines
$('#content').off('click', '.remove_row_img').on('click', '.remove_row_img', function () {
 if (($(this).closest('form').find('tbody').first().children().filter('tr').length) > 1) {
  $(this).closest("tr").remove();
 }else{
  return;
 }
 var headerClassName = $('ul#js_saving_data').find('.headerClassName').data('headerclassname');
 if (headerClassName && headerClassName !== 'undefined' && headerClassName === 'pos_transaction_header') {
  $('#total_amount').trigger('calPOSHeaderAmount');
 }
});

});
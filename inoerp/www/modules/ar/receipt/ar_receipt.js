$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'ar_receipt_header_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "ledger_id"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Ledger Id"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 //set the line price
 $('#content').validateAmount();
 $('#content').on('change', '.amount, .invoice_amount', function () {
  var remaining_amount = (+$(this).closest('tr').find('.invoice_amount').val()) -
          ((+$(this).closest('tr').find('.amount').val()) + (+$(this).closest('tr').find('.receipt_amount').val()));
  $(this).closest('tr').find('.remaining_amount').val(remaining_amount);
  $(this).closest('tr').find('.remaining_amount').prop('readonly', true);
  $(this).closest('tr').find('.invoice_amount').prop('readonly', true);
  $(this).closest('tr').find('.receipt_amount').prop('readonly', true);
  var trClass = '.' + $(this).closest('tr').prop('class');
  if (remaining_amount < 0) {
   alert('Entered amount is more than remaining amount' + '\n Re-enter the amount!');
   $('#form_line').find(trClass).find('.remaining_amount').val('');
   $('#form_line').find(trClass).find('.amount').val('');
  }
 });

//get ar_customer details
 get_customer_detail_for_bu();


 $('#ar_receipt_header').off("change", "#ar_customer_site_id").on("change", "#ar_customer_site_id", function () {
  var ar_customer_site_id = $("#ar_customer_site_id").val();
  if (ar_customer_site_id) {
   getCustomerSiteDetails('modules/ar/customer/json_customer.php', ar_customer_site_id);
  }
 });


 //selecting Header Id
 $(".ar_receipt_header_id.select_popup").on("click", function () {
  var link = 'select.php?class_name=ar_receipt_header';
  void window.open(link, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //popu for selecting AR Transaction
 $('body').off('click', '.select_transaction_number.select_popup').on('click', '.select_transaction_number.select_popup', function () {
  if ($(this).closest('tr').find('.ar_receipt_line_id').first().val()) {
   alert('You are not allowed to select a new transaction\nCancell or Viod the payment if required');
   return;
  }
  var rowClass = $(this).closest('tr').prop('class');
  var fieldClass = $(this).closest('td').find('.select_transaction_number').prop('class');
  localStorage.setItem("row_class", rowClass);
  localStorage.setItem("field_class", fieldClass);
  var openUrl = 'select.php?class_name=ar_unpaid_transaction_v';
  openUrl += '&ar_customer_id=' + $('#ar_customer_id').val();
  localStorage.setItem("reset_link_ofSelect", openUrl);
  void window.open(openUrl, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('body').off('change', '#action').on('change', '#action', function () {
  var selected_value = $(this).val();
  switch (selected_value) {
   case 'CREATE_ACCOUNT' :
    create_accounting();
    break;

   case 'CANCEL' :
    if (confirm('Do you really want to cancel this receipt?')) {
     $('#form_line :input').prop('disabled', true);
     $(this).prop('readonly', true);
    }
    break;

   case 'REVERSE' :
    if (confirm("Do you really want to reverse Receipt# ?\n" + $('#receipt_number').val())) {
     $(".error").append('Reversing Receipt');
     var headerData = $('#ar_receipt_header').serializeArray();
     saveHeader('form.php?class_name=ar_receipt_header', headerData, '#ar_receipt_header_id', '', true, 'ar_receipt_header');
     $(".error").append('Reversing complete. Refresh the page to see the changes');
    }
    break;

   default :
    break;
  }
 });

 $('#bu_org_id').on('change', function () {
  getBUDetails($(this).val());
  get_ar_receipt_source_details($(this).val());
 });

 if ($('#bu_org_id').val() && (!$('#ar_receipt_header_id').val()) && ($('#bu_org_id').attr('disabled') != 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

 $('#ar_receipt_line').off('blur', '.amount, .exchange_rate').on('blur', '.amount, .exchange_rate', function () {
  var rate = +$(this).closest('tr').find('.exchange_rate').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var gl_amount = (+$(this).closest('tr').find('.amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1")) * rate;
  $(this).closest('tr').find('.gl_amount').val(gl_amount);
 });

//total header & tax amount
 $('body').on('cash_calculateHeaderAmount', function () {
  var header_amount = 0;
  $('#form_line').find('.amount ').each(function () {
   header_amount += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#header_amount').val(header_amount);
 });

//total header & tax amount
 $('body').off('blur', '.amount').on('blur', '.amount', function () {
  $('body').trigger('cash_calculateHeaderAmount');
 });

 $('body').off('change', '.line_type').on('change', '.line_type', function () {
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  var lineType = $(this).val();
  ar_receipt_setLineType(trClass, lineType);
 });


 $('body').find('.line_type').each(function () {
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  var lineType = $(this).val();
  ar_receipt_setLineType(trClass, lineType);
 });

 $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('#receipt_number, .status, .receipt_status').val('');
 });

});

//all actions
//Popup for selecting match 
function create_accounting() {
 var ar_receipt_header_id = $("#ar_receipt_header_id").val();
 if (ar_receipt_header_id) {
  var link = 'multi_select.php?window_type=popup&class_name=ar_receipt_header&action=CREATE_ACCOUNT&mode=9&action_class_name=ar_receipt_header&ar_receipt_header_id=' + ar_receipt_header_id;
  localStorage.removeItem("reset_link");
  localStorage.setItem("reset_link", link);
  localStorage.removeItem("jsfile");
  localStorage.setItem("jsfile", "modules/ar/receipt/extra_ar_receipt.js");
  void window.open(link, '_blank',
          'width=' + $(window).width() + ',height=' + $(window).height() + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 } else {
  alert('No Transaction Header ID/nEnter or Save The Header Details ');
 }
}

function ar_receipt_setLineType(trClass, lineType) {
 switch (lineType) {
  case 'WF':
  case 'REFUND':
   $(trClass).find('.transaction_number,.g_select_ar_transaction_number').addClass('readonly');
   $(trClass).find('.ar_receivable_activity_id').removeClass('readonly');
   break;

  default :
   $(trClass).find('.ar_receivable_activity_id').addClass('readonly');
   $(trClass).find('.transaction_number , .g_select_ar_transaction_number').removeClass('readonly');
   break;
 }
} 
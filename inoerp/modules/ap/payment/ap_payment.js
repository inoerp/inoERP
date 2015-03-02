function setValFromSelectPage(ap_payment_header_id, ap_transaction_header_id, transaction_number,
        header_amount, supplier_id, supplier_number, supplier_name, paid_amount, supplier_site_id, exchange_rate) {
 this.ap_payment_header_id = ap_payment_header_id;
 this.ap_transaction_header_id = ap_transaction_header_id;
 this.header_amount = header_amount;
 this.paid_amount = paid_amount;
 this.transaction_number = transaction_number;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.supplier_site_id = supplier_site_id;
 this.exchange_rate = exchange_rate;
}

setValFromSelectPage.prototype.setVal = function () {
 var ap_payment_header_id = this.ap_payment_header_id;
 var header_amount = this.header_amount;
 var paid_amount = this.paid_amount;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var ap_transaction_header_id = this.ap_transaction_header_id;
 var transaction_number = this.transaction_number;

 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (ap_payment_header_id) {
  $("#ap_payment_header_id").val(ap_payment_header_id);
 }
 if (supplier_id) {
  $("#supplier_id").val(supplier_id);
  if (this.supplier_site_id) {
   $('#supplier_site_id').val(supplier_site_id);
  }
 }
 if (supplier_number) {
  $("#supplier_number").val(supplier_number);
 }
 if (supplier_name) {
  $("#supplier_name").val(supplier_name);
 }
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (ap_transaction_header_id) {
  $('#content').find(rowClass).find(fieldClass).val(transaction_number);
  $('#content').find(rowClass).find('.ap_transaction_header_id').first().val(ap_transaction_header_id);
  $('#content').find(rowClass).find('.invoice_amount').first().val(header_amount);
  $('#content').find(rowClass).find('.paid_amount').first().val(paid_amount);
  $('#content').find(rowClass).find('.exchange_rate').first().val(this.exchange_rate);
 }
 localStorage.removeItem("row_class");
 localStorage.removeItem("row_class");
  if (this.ap_payment_header_id) {
  $('a.show.ap_payment_header_id').trigger('click');
 }
};

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'ap_payment_header_id';
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
 $('#content').on('change', '.amount, .invoice_amount', function () {
  var remaining_amount = (+$(this).closest('tr').find('.invoice_amount').val()) -
          ((+$(this).closest('tr').find('.amount').val()) + (+$(this).closest('tr').find('.paid_amount').val()));
  $(this).closest('tr').find('.remaining_amount').val(remaining_amount);
  $(this).closest('tr').find('.remaining_amount').prop('readonly', true);
  $(this).closest('tr').find('.invoice_amount').prop('readonly', true);
  $(this).closest('tr').find('.paid_amount').prop('readonly', true);
 });

 $('#content').on('change', '.remaining_amount, .amount', function () {
  var payment_type = $('#payment_type').val();
  if ($('#payment_type').val() === 'REFUND') {
   return;
  } else if (+$(this).closest('tr').find('.remaining_amount').first().val() < 0) {
   alert('Negative value not allowed! for ' + payment_type + ' ' + $(this).prop('class'));
   $(this).val('');
   $(this).closest('tr').find('.remaining_amount').first().val('');
  }
 });

//get supplier details
 $("#supplier_id, #supplier_name, #supplier_number").on("focusout", function () {
  if (($("#bu_org_id").val()) && ($('#supplier_id').val())) {
   var bu_org_id = $("#bu_org_id").val();
   getSupplierDetails('modules/ap/supplier/json_supplier.php', bu_org_id);
  }
 });

 $("#content").on("change", "#supplier_site_id", function () {
  var supplier_site_id = $("#supplier_site_id").val();
  if (supplier_site_id) {
   getSupplierSiteDetails('modules/ap/supplier/json_supplier.php', supplier_site_id);
  }
 });

$('body').on('click','.invoice_amount,.paid_amount,.remaining_amount', function(){
$(this).prop('readonly', true).css('background','none repeat scroll 0 0 rgba(243, 243, 210, 1)');
alert('Readonly Field!');  
})
 //selecting Header Id
 $(".ap_payment_header_id.select_popup").on("click", function () {
  var link = 'select.php?class_name=ap_payment_header';
  void window.open(link, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//selecting supplier
 $(".find_popup.supplierId").on("click", function () {
  localStorage.idValue = "";
  void window.open('select.php?class_name=supplier', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//popu for selecting select_transaction_number
 $('#content').off('click', '.select_ap_transaction_number.select_popup').on('click', '.select_ap_transaction_number.select_popup', function () {
  if ($(this).closest('tr').find('.ap_payment_line_id').first().val()) {
   alert('You are not allowed to select a new transaction\nCancell or Viod the payment if required');
   return;
  }
  var rowClass = $(this).closest('tr').prop('class');
  var fieldClass = $(this).closest('td').find('.select_transaction_number').prop('class');
  localStorage.setItem("row_class", rowClass);
  localStorage.setItem("field_class", fieldClass);
  var openUrl = 'select.php?class_name=ap_payment_trnx_v';
  openUrl += '&supplier_id=' + $('#supplier_id').val();
  openUrl += '&supplier_site_id=' + $('#supplier_site_id').val();
  void window.open(openUrl, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


//remove po lines
 $("#remove_row").click(function () {
  $('input[name="ap_payment_line_id_cb"]:checked').each(function () {
   $(this).closest('tr').remove();
  });
 });

 //total header & tax amount
 $('#content').on('blur', '#header_amount, .amount', function () {

  var header_amount = 0;
  $('#form_line').find('.amount').each(function () {
   header_amount += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#header_amount').val(header_amount);
 });


 $('#bu_org_id').on('change', function() {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && ($('#bu_org_id').attr('disabled') != 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

 $('#content').off('blur', '#currency, #doc_currency, #exchange_rate_type, #exchange_rate')
         .on('blur', '#currency, #doc_currency, #exchange_rate_type, #exchange_rate', function () {
  getExchangeRate();
 });


$('body').on('blur','.amount', function(){
var rate = +$(this).closest('tr').find('.exchange_rate').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
var gl_amount =  ( +$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1")) *   rate;
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
 $('body').off('cash_calculateHeaderAmount').on('cash_calculateHeaderAmount', function () {
  var header_amount = 0;
  $('#form_line').find('.amount ').each(function () {
   header_amount += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#header_amount').val(header_amount);
 });

//all actions

 $('#payment_action').on('change', function () {
  var selected_value = $(this).val();
  switch (selected_value) {
   case 'CREATE_ACCOUNT' :
    create_accounting();
    break;

   case 'MATCH' :
    match_transaction();
    break;

   default :
    break;
  }
 });


});

//Popup for selecting match 
 function match_transaction() {
  var ap_payment_header_id = $("#ap_payment_header_id").val();
  if (ap_payment_header_id) {
   var link = 'multi_select.php?class_name=po_all_v&action=match_transaction&mode=9&action_class_name=ap_payment_line&po_status=APPROVED&ap_payment_header_id=' + ap_payment_header_id;
   var po_header_id = $("#po_header_id").val();
   var po_number = $("#po_number").val();
   if (po_header_id) {
    link += '&po_header_id=' + po_header_id;
   } else if (po_number) {
    link += '&po_number=' + po_number;
   } else {
    var supplier_id = $("#supplier_id").val();
    link += '&supplier_id=' + supplier_id;
   }
   localStorage.removeItem("reset_link");
   localStorage.setItem("reset_link", link);
   localStorage.removeItem("jsfile");
   localStorage.setItem("jsfile", "modules/ap/ap_payment/extra_ap_payment.js");
   void window.open(link, '_blank',
           'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
   return false;
  } else {
   alert('No Transaction Header ID/nEnter or Save The Header Details ');
  }
 }

 function create_accounting() {
  var ap_payment_header_id = $("#ap_payment_header_id").val();
  if (ap_payment_header_id) {
   var link = 'multi_select.php?class_name=ap_payment_header&action=create_accounting&mode=9&action_class_name=ap_payment_header&ap_payment_header_id=' + ap_payment_header_id;
   localStorage.removeItem("reset_link");
   localStorage.setItem("reset_link", link);
   localStorage.removeItem("jsfile");
   localStorage.setItem("jsfile", "modules/ap/ap_payment/extra_ap_payment.js");
   void window.open(link, '_blank',
           'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
   return false;
  } else {
   alert('No Transaction Header ID/nEnter or Save The Header Details ');
  }
 }
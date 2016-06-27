function setValFromSelectPage(ar_transaction_header_id, combination, ar_customer_id, customer_number, customer_name,
        item_id_m, item_number, item_description, uom_id, address_id, address_name, address,
        country, postal_code) {
 this.ar_transaction_header_id = ar_transaction_header_id;
 this.combination = combination;
 this.ar_customer_id = ar_customer_id;
 this.customer_number = customer_number;
 this.customer_name = customer_name;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.address_id = address_id;
 this.address_name = address_name;
 this.address = address;
 this.country = country;
 this.postal_code = postal_code;
}

setValFromSelectPage.prototype.setVal = function () {
 var ar_transaction_header_id = this.ar_transaction_header_id;
 var ar_customer_id = this.ar_customer_id;
 var customer_number = this.customer_number;
 var customer_name = this.customer_name;
 var combination = this.combination;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 var address_id = this.address_id;
 var address_name = this.address_name;
 var address = this.address;
 var country = this.country;
 var postal_code = this.postal_code;

 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 var addressPopupDivClass = '.' + localStorage.getItem("addressPopupDivClass");
 addressPopupDivClass = addressPopupDivClass.replace(/\s+/g, '.');

 if (address_id) {
  $('#form_header').find(addressPopupDivClass).find('.address_id').val(address_id);
 }
 if (address_name) {
  $('#form_header').find(addressPopupDivClass).find('.address_name').val(address_name);
 }
 if (address) {
  $('#form_header').find(addressPopupDivClass).find('.address').val(address);
 }

 if (ar_transaction_header_id) {
  $("#ar_transaction_header_id").val(ar_transaction_header_id);
 }
 if (ar_customer_id) {
  $("#ar_customer_id").val(ar_customer_id);
 }
 if (customer_number) {
  $("#customer_number").val(customer_number);
 }
 if (customer_name) {
  $("#customer_name").val(customer_name);
 }
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
  $('#content').find(rowClass).find(fieldClass).val(combination);
 }
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
 localStorage.removeItem("row_class");

 if (this.ar_transaction_header_id) {
  $('a.show.ar_transaction_header_id').trigger('click');
 }

};

function header_amount() {
 var header_amount = 0;
 $('#form_line').find('.inv_line_price').each(function () {
  header_amount += (+$(this).val());
  $('#header_amount').val(header_amount);
 });

 var total_tax = 0;
 $('#form_line').find('.tax_amount').each(function () {
  total_tax += (+$(this).val());
  $('#tax_amount').val(total_tax);
 });
}

function beforeSave() {
 header_amount();
}

function match_transaction() {
 var ar_transaction_header_id = $("#ar_transaction_header_id").val();
 if (ar_transaction_header_id) {
  var link = 'multi_select.php?class_name=om_so_all_v&action=match_transaction&mode=9&action_class_name=ar_transaction_line&om_so_status=APPROVED&ar_transaction_header_id=' + ar_transaction_header_id;
  var om_so_header_id = $("#om_so_header_id").val();
  var om_so_number = $("#om_so_number").val();
  if (om_so_header_id) {
   link += '&om_so_header_id=' + om_so_header_id;
  } else if (om_so_number) {
   link += '&om_so_number=' + om_so_number;
  } else {
   var ar_customer_id = $("#ar_customer_id").val();
   link += '&ar_customer_id=' + ar_customer_id;
  }
  localStorage.removeItem("reset_link");
  localStorage.setItem("reset_link", link);
  localStorage.removeItem("jsfile");
  localStorage.setItem("jsfile", "modules/ar/ar_transaction/extra_ar_transaction.js");
  void window.open(link, '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 } else {
  alert('No Transaction Header ID/nEnter or Save The Header Details ');
 }
}

function create_accounting() {
 var ar_transaction_header_id = $("#ar_transaction_header_id").val();
 if (ar_transaction_header_id) {
  var link = 'multi_select.php?window_type=popup&class_name=ar_transaction_header&action=create_accounting&mode=9&action_class_name=ar_transaction_header&ar_transaction_header_id=' + ar_transaction_header_id;
  localStorage.removeItem("reset_link");
  localStorage.setItem("reset_link", link);
  localStorage.removeItem("jsfile");
  localStorage.setItem("jsfile", "modules/ar/ar_transaction/extra_ar_transaction.js");
  void window.open(link, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 } else {
  alert('No Transaction Header ID/nEnter or Save The Header Details ');
 }
}

function create_receipt() {
 var ar_transaction_header_id = $("#ar_transaction_header_id").val();
 if (ar_transaction_header_id) {
  var link = 'form.php?window_type=popup&class_name=ar_receipt_header&action=create_receipt&mode=9'
  link += '&ar_transaction_header_id=' + ar_transaction_header_id;
  void window.open(link, '_blank',
          'width=1300,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 } else {
  alert('No Transaction Header ID/nEnter or Save The Header Details ');
 }
}

$(document).ready(function () {

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.detail_number:first').val())) {
  $('.detail_number:first').val('1');
 }

// $('.need_by_date:first').datepicker("setDate", new Date());
// $('.promise_date:first').datepicker("setDate", new Date());


 //default quantity
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function () {
  var lineQuantity = $(this).closest('tr').find('.inv_line_quantity:first').val();
  if (!$(this).closest("td").find(".quantity:first").val())
  {
   $(this).closest("td").find(".quantity:first").val(lineQuantity);
  }
 });


//get customer details
 get_customer_detail_for_bu();

 
   $('#hd_service_contract_header').off("change", "#ar_customer_site_id").on("change", "#ar_customer_site_id", function () {
  var ar_customer_site_id = $("#ar_customer_site_id").val();
  if (ar_customer_site_id) {
   getCustomerSiteDetails('modules/ar/customer/json_customer.php', ar_customer_site_id);
  }
 });

// //selecting PO Header Id
 $(".ar_transaction_header_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=ar_transaction_header', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 copy_line_to_details();


//remove po lines
 $("#remove_row").click(function () {
  $('input[name="ar_transaction_line_id_cb"]:checked').each(function () {
   $(this).closest('tr').remove();
  });
 });

 //all actions
//Popup for selecting match 
 $('#transaction_action').on('change', function () {
  var selected_value = $(this).val();
  switch (selected_value) {
   case 'CREATE_ACCOUNT' :
    create_accounting();
    break;

   case 'MATCH' :
    match_transaction();
    break;

   case 'CREATE_RECEIPT' :
    create_receipt();
    break;

   default :
    break;
  }
 });

 $('#bu_org_id').on('change', function () {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && (!$('#ar_transaction_header_id').val()) && ($('#bu_org_id').attr('disabled') != 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

 $('#transaction_type').on('change', function () {
  $('#content').find('.transaction_type').val($(this).val());
  getARTransactionTypeDetails($(this).val());
 });


 /*Same for AR TRansaction / AP Transaction. need to be moved to be gloabl*/
 $('body').off('blur', '.inv_line_quantity, .inv_unit_price, .inv_line_price, .tax_amount,.tax_code_id')
         .on('blur', '.inv_line_quantity, .inv_unit_price, .inv_line_price, .tax_amount, .tax_code_id', function () {
          var trClass = '.' + $(this).closest('tr').prop('class').replace(/\s+/g, '.');
          $('body').trigger('inv_calculateLineAmount', [trClass]);
          $('body').trigger('inv_calculateTax', [trClass]);
          $('body').trigger('inv_getGlPrice', [trClass]);
          $('body').trigger('inv_calculateHeaderAmount');
         });

//calculate line amount
 $('body').off('inv_calculateLineAmount').on('inv_calculateLineAmount', function (e, trClass) {
  if ($('#form_line').find(trClass).find('.inv_unit_price').length < 1) {
   return;
  }
  var unitPrice = +($('#form_line').find(trClass).find('.inv_unit_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  var lineQuantity = +($('#form_line').find(trClass).find('.inv_line_quantity').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  var linePrice = unitPrice * lineQuantity;
  $(this).closest('#form_line').find(trClass).find('.inv_line_price').val(linePrice);
 });

 //calculate the tax amount
 $('body').off('inv_calculateTax').on('inv_calculateTax', function (e, trClass) {
  var linePrice = +$('#content').find(trClass).find('.inv_line_price').val();
  var taxAmount = 0;
  var taxPercentage = 0;
  var taxValue = 0;

  if ($('#content').find(trClass).find('.tax_code_id').val()) {
   taxPercentage = $('#content').find(trClass).find('.tax_code_id').find('option:selected').data('percentage');
   taxAmount = $('#content').find(trClass).find('.tax_code_id').find('option:selected').data('amount');
  }
  if (taxPercentage) {
   taxValue = ((taxPercentage * linePrice) / 100).toFixed(5);
  } else if (taxAmount) {
   taxValue = taxAmount.toFixed(5);
  }

  $('#content').find(trClass).find('.tax_amount').val(taxValue);
 });

//total header & tax amount
 $('body').off('inv_calculateHeaderAmount').on('inv_calculateHeaderAmount', function () {
  var total_tax = 0;
  $('#form_line').find('.tax_amount').each(function () {
   total_tax += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#tax_amount').val(total_tax);

  var header_amount = 0;
  $('#form_line').find('.inv_line_price').each(function () {
   header_amount += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#header_amount').val(header_amount);
 });


 //get GL Price form line price & exchage rate
 $('body').off('inv_getGlPrice').on('inv_getGlPrice', function (e, trClass) {
  if ($('#exchange_rate').val()) {
   var exch_rate = +$('#exchange_rate').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  } else {
   exch_rate = 1;
  }
  if ($('#form_line').find(trClass).find('.inv_line_price').val()) {
   var gl_line_price_val = (+$('#form_line').find(trClass).find('.inv_line_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1")) * exch_rate;
  } else {
   var gl_line_price_val = 0;
  }
  gl_line_price_val = gl_line_price_val.toFixed(5);
  $('#form_line').find(trClass).find('.gl_inv_line_price').val(gl_line_price_val);

  if ($('#form_line').find(trClass).find('.tax_amount').val()) {
   var gl_tax_amount_val = (+$('#form_line').find(trClass).find('.tax_amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1")) * exch_rate;
  } else {
   var gl_tax_amount_val = 0;
  }
  gl_tax_amount_val = gl_tax_amount_val.toFixed(5);
  $('#form_line').find(trClass).find('.gl_tax_amount').val(gl_tax_amount_val);

 });


//New Functions
 $('body').off('change', '#category').on('change', '#category', function () {
contractLineType();
 });
contractLineType();

 $('body').off('blur', '#hd_service_contract_header .start_date, #hd_service_contract_header .end_date')
         .on('blur', '#hd_service_contract_header .start_date, #hd_service_contract_header .end_date', function () {
          if ($('#hd_service_contract_header .start_date').val() && $('#hd_service_contract_header .end_date').val()) {
           var endDate = $('#hd_service_contract_header .end_date').val();
           var startDate = $('#hd_service_contract_header .start_date').val();
           var daysDiff = +daysBetweenDates(endDate, startDate);
           $('#duration').val(daysDiff);
           $('#duration_uom_id').val('42');
          }
         });
 $('body').off('click', '#duration, #duration_uom_id').on('click', '#duration, #duration_uom_id', function () {
  if ($('#hd_service_contract_header .start_date').val() && $('#hd_service_contract_header .end_date').val()) {
   var endDate = $('#hd_service_contract_header .end_date').val();
   var startDate = $('#hd_service_contract_header .start_date').val();
   var daysDiff = +daysBetweenDates(endDate, startDate);
   $('#duration').val(daysDiff);
   $('#duration_uom_id').val('42');
  }
 });

});

function contractLineType() {
 if ($('#category').val() === 'WARRANTY') {
  var optionArray = ['SERVICE', 'USAGE', 'SUBSCRIPTION'];
  changeContractLineType(optionArray);
 } else  if ($('#category').val() === 'SERVICE'){
  var optionArray = ['WARENTY', 'EXTND_WARENTY'];
  changeContractLineType(optionArray);
 }
}

function changeContractLineType(optionArrayToBeDisabled) {
 $('.line_type option').removeAttr('disabled');
 $(optionArrayToBeDisabled).each(function (i, curVal) {
  $('.line_type option[value="' + curVal + '"]').prop('disabled', 'disabled');
 });
}

//function to coply line to details
function copy_line_to_details() {
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function () {
  var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
  if (detailExists === 0) {
   var lineQuantity = $(this).closest('tr').find('.inv_line_quantity').val();
   $(this).closest("td").find(".quantity:first").val(lineQuantity);
  }
 });
}
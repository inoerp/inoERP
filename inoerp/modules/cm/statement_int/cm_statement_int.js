
function beforeContextMenu() {
 $('.line_status').val('');
 $('.picked_quantity').val('');
 $('.shipped_quantity').val('');
 $('.schedule_ship_date').val('');
 $('#so_number').val('');
 return true;
}

$(document).ready(function () {


//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.shipment_number:first').val())) {
  $('.shipment_number:first').val('1');
 }

if($('#bu_org_id').val()){
 $('#document_type, .line_type').find('option').attr('disabled', true);
$('#document_type, .line_type').find("[data-bu_org_id_r='" + $('#bu_org_id').val() + "']").removeAttr('disabled');
}

 $('body').off('change', '#cm_statement_header #bu_org_id').on('change', '#cm_statement_header #bu_org_id', function () {
  getBUDetails($(this).val());
  $('#document_type, .line_type').find('option').attr('disabled', true);
  $('#document_type, .line_type').find("[data-bu_org_id_r='" + $(this).val() + "']").removeAttr('disabled');
 });

 if ($('#bu_org_id').val() && (!$('#cm_statement_header_id').val()) && ($('#bu_org_id').attr('disabled') !== 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

 get_customer_detail_for_bu();

 $('#cm_statement_header').off("change", "#ar_customer_site_id").on("change", "#ar_customer_site_id", function () {
  var ar_customer_site_id = $("#ar_customer_site_id").val();
  if (ar_customer_site_id) {
   $.when(getCustomerSiteDetails('modules/ar/customer/json_customer.php', ar_customer_site_id)).then(function () {
    getExchangeRate();
   });
  }
 });


 $("#content").off("focusout", '.ship_to_inventory').on("focusout", '.ship_to_inventory', function () {
  var ship_to_inventory = $(this).val();
  var rowTrClass = $(this).closest("tr").attr("class");
  var classValue = "tr." + rowTrClass;
  var classValue1 = classValue.replace(/ /g, '.');
  getAllInventoryAccounts('modules/org/inventory/json_inventory.php', ship_to_inventory, classValue1);
 });

 //exhhnge rate
 $('body').on('change', '#doc_currency', function () {
  if ($(this).val() !== $('#currency').val()) {
   $('#exchange_rate').prop('required', true).css('background', 'rgba(233, 209, 234, 0.61)');
  }
 });

 if ($('#currency').val() && $('#doc_currency').val() && ($('#currency').val() != $('#doc_currency').val())) {
  getExchangeRate();
 }

 $('body').off('change', '#currency, #doc_currency, #exchange_rate_type')
         .on('change', '#currency, #doc_currency, #exchange_rate_type', function () {
          getExchangeRate();
         });
 $('#currency').val()
//get tax code
 $('#content').off('change', '.shipping_org_id').on('change', '.shipping_org_id', function () {
  var org_id = $(this).val();
  var trClass = '.' + $(this).closest('tr').prop('class');
  getTaxCodes('modules/mdm/tax_code/json_tax_code.php', org_id, 'OUT', trClass);
 });

 //selecting PO Header Id
 $('body').off("click", '.cm_statement_header_id.select_popup').on("click", '.cm_statement_header_id.select_popup', function () {
  void window.open('select.php?class_name=cm_statement_header', '_blank',
          'width=1100,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//default data from document type
 $('body').off('change', '#document_type').on('change', '#document_type', function () {
  var document_type_id = $(this).val();
  getDocumentTypeDetails(document_type_id);
 })


 //default quantity
 $("#content").off("click", "table.form_line_data_table .add_detail_values_img")
         .on("click", "table.form_line_data_table .add_detail_values_img", function () {
          var lineQuantity = $(this).closest('tr').find('.line_quantity:first').val();
          if (!$(this).closest("td").find(".quantity:first").val())
          {
           $(this).closest("td").find(".quantity:first").val(lineQuantity);
          }
         });

//price from price list
 $('#form_line').off('change', '.item_id_m, .item_number, .price_list_header_id, .price_date')
         .on('change', '.item_id_m, .item_number, .price_list_header_id, .price_date', function () {
          var rowClass = '.' + $(this).closest('tr').prop('class');
          var item_id_m = $(this).closest('.tabContainer').find(rowClass).find('.item_id_m').val();
          var price_date = $(this).closest('.tabContainer').find(rowClass).find('.price_date').val();
          var price_list_header_id = $(this).closest('#form_line').find(rowClass).find('.price_list_headerId').val();
          $.when(getPriceDetails({
           rowClass: rowClass,
           item_id_m: item_id_m,
           price_date: price_date,
           price_list_header_id: price_list_header_id})).then(function () {
           $('body').trigger('setLinePrice', [rowClass]);
           $('body').trigger('calculateTax', [rowClass]);
           $('body').trigger('getGlPrice', [rowClass]);
           $('body').trigger('calculateHeaderAmount');
          });
         });

//set the line price
 $('body').on('setLinePrice', function (e, trClass) {
  var unitPrice = +($('#form_line').find(trClass).find('.unit_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  var lineQuantity = +($('#form_line').find(trClass).find('.line_quantity').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  var linePrice = unitPrice * lineQuantity;
  $('#form_line').find(trClass).find('.line_price').val(linePrice);
 });

//calculate the tax amount
 $('body').on('calculateTax', function (e, trClass) {
  var linePrice = +$('#content').find(trClass).find('.line_price').val();
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
 $('body').on('calculateHeaderAmount', function () {
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

 //calculate the tax amount, line prices & header amount
 $('body').off('blur', '.line_quantity, .unit_price, .line_price, .tax_code_id')
         .on('blur', '.line_quantity, .unit_price, .line_price, .tax_code_id', function () {
          var trClass = '.' + $(this).closest('tr').prop('class');
          $('body').trigger('setLinePrice', [trClass]);
          $('body').trigger('calculateTax', [trClass]);
          $('body').trigger('getGlPrice', [trClass]);
          $('body').trigger('calculateHeaderAmount');
         });


//get GL Price form line price & exchage rate
 $('body').on('getGlPrice', function (e, trClass) {
  if ($('#exchange_rate').val()) {
   var exch_rate = +$('#exchange_rate').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  } else {
   exch_rate = 1;
  }
  if ($('#form_line').find(trClass).find('.line_price').val()) {
   var gl_line_price_val = (+$('#form_line').find(trClass).find('.line_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1")) * exch_rate;
  } else {
   var gl_line_price_val = 0;
  }
  gl_line_price_val = gl_line_price_val.toFixed(5);
  $('#form_line').find(trClass).find('.gl_line_price').val(gl_line_price_val);

  if ($('#form_line').find(trClass).find('.tax_amount').val()) {
   var gl_tax_amount_val = (+$('#form_line').find(trClass).find('.tax_amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1")) * exch_rate;
  } else {
   var gl_tax_amount_val = 0;
  }
  gl_tax_amount_val = gl_tax_amount_val.toFixed(5);
  $('#form_line').find(trClass).find('.gl_tax_amount').val(gl_tax_amount_val);

 });

 $('body').off('click', '.popup.view-item-config').on('click', '.popup.view-item-config', function (e) {
  e.preventDefault();
  localStorage.removeItem("row_class_b");
  var openUrl = $(this).prop('href') + '&reference_key_name=cm_statement_line';
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  if ($('#form_line').find(trClass).find('input.cm_statement_line_id').val()) {
   openUrl += '&reference_key_value=' + $('#form_line').find(trClass).find('.cm_statement_line_id').val();
  } else {
   if ($('#form_line').find(trClass).find('.shipping_org_id').val()) {
    openUrl += '&org_id=' + $('#form_line').find(trClass).find('.shipping_org_id').val();
   }
   if ($('#form_line').find(trClass).find('.item_id_m').val()) {
    openUrl += '&item_id_m=' + $('#form_line').find(trClass).find('.item_id_m').val();
   }
  }
  if ($('#form_line').find(trClass).find('.line_quantity').val()) {
   openUrl += '&quantity=' + $('#form_line').find(trClass).find('.quantity').val();
  }
  var rowClass = $(this).closest('tr').prop('class');
  localStorage.setItem("row_class_b", rowClass);
  void window.open(openUrl, '_blank',
          'width=1200,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('.line_status, #so_status').val('ENTERED');
  $('.picked_quantity, .shipped_quantity, .schedule_ship_date, .invoiced_quantity, .ar_transaction_header_id, .ar_transaction_line_id, .ar_transaction_number').val('');
 });

});
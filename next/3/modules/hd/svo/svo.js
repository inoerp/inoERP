function beforeContextMenu() {
 $('.line_status').val('');
 $('.picked_quantity').val('');
 $('.shipped_quantity').val('');
 $('.schedule_ship_date').val('');
 $('#so_number').val('');
 return true;
}

$(document).ready(function () {
 //add new lines
 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'hd_svo_estimates';
  addNewRow.tbodyClass = 'form_data_line_tbody2';
  addNewRow.noOfTabs = 2;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

$('body').off('change','#action').on('change','#action', function(){
  if($(this).val() == 'PROCESS_ACTUALS'){
    $('#add_to_order').prop('disabled', false);
  }else{
    $('#add_to_order').prop('disabled', true);
  }
});

 $('body').off('change', '#bu_org_id').on('change', '#bu_org_id', function () {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && (!$('#sd_so_header_id').val()) && ($('#bu_org_id').attr('disabled') !== 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

 get_customer_detail_for_bu();

    $('#hd_svo_header').off("change", "#ar_customer_site_id").on("change", "#ar_customer_site_id", function () {
  var ar_customer_site_id = $("#ar_customer_site_id").val();
  if (ar_customer_site_id) {
   getCustomerSiteDetails('modules/ar/customer/json_customer.php', ar_customer_site_id);
  }
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

});
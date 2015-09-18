$(document).ready(function () {

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.shipment_number:first').val())) {
  $('.shipment_number:first').val('1');
 }

//price from price list
 $('#form_line').off('blur', '.item_id_m, .item_number, .line_quantity, .uom_id')
         .on('blur', '.item_id_m, .item_number, .line_quantity, .uom_id', function () {
          var rowClass = '.' + $(this).closest('tr').prop('class');
          var item_id_m = $(this).closest('.tabContainer').find(rowClass).find('.item_id_m').val();
          var line_quantity = $(this).closest('.tabContainer').find(rowClass).find('.line_quantity').val();
          var uom_id = $(this).closest('.tabContainer').find(rowClass).find('.uom_id').val();
          var price_list_header_id = $(this).closest('#form_line').find(rowClass).find('.price_list_headerId').val();
          if(!item_id_m){
           return false;
          }
          $.when(getPriceDetails({
           rowClass: rowClass,
           item_id_m: item_id_m,
           quantity: line_quantity,
           uom_id: uom_id,
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

 $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('.line_status, #so_status').val('ENTERED');
  $('.picked_quantity, .shipped_quantity, .schedule_ship_date, .invoiced_quantity, .ar_transaction_header_id, .ar_transaction_line_id, .ar_transaction_number').val('');
 });


//copy line type
$('body').on('click','.add_detail_values_img', function(){
  var line_type = $(this).closest('tr').find('.line_type').val();
  $(this).parent().find('.line_type').each(function(){
    if(!$(this).val(line_type)){
  $(this).val(line_type);  
    }
  }
);

});
});
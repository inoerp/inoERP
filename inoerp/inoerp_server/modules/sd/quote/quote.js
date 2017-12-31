function setValFromSelectPage(sd_quote_header_id, combination, ar_customer_id, customer_number, customer_name,
        item_id_m, item_number, item_description, uom_id, address_id, address_name, hr_employee_id, first_name, last_name) {
 this.sd_quote_header_id = sd_quote_header_id;
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
 this.hr_empoyee_id = hr_employee_id;
 this.first_name = first_name;
 this.last_name = last_name;
}

setValFromSelectPage.prototype.setVal = function () {
 var sd_quote_header_id = this.sd_quote_header_id;
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

 if (this.first_name) {
  var name = this.first_name + ' ' + this.last_name;
 }

 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (this.address_name) {
  $('body').find(fieldClass).parent().find('.address_name').val(this.address_name);
  $('body').find(fieldClass).val(this.address_id);
 }

 if (sd_quote_header_id) {
  $("#sd_quote_header_id").val(sd_quote_header_id);
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

 if (this.hr_employee_id) {
  $("#sales_person_employee_id").val(this.hr_employee_id);
 }
 if (name) {
  $("#sales_person_employee_name").val(name);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");
 localStorage.removeItem("addressPopupDivId");
 if (this.sd_quote_header_id) {
  $('a.show.sd_quote_header_id').trigger('click');
 }
};

//context menu
function beforeContextMenu() {
 $('.line_status').val('');
 $('.picked_quantity').val('');
 $('.shipped_quantity').val('');
 $('.schedule_ship_date').val('');
 $('#quote_number').val('');
 return true;
}


$(document).ready(function () {
//mandatory and field sequence

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.shipment_number:first').val())) {
  $('.shipment_number:first').val('1');
 }
 
 $('body').off('change','#action').on('change','#action', function(){
  if($(this).val() == 'CONVERT_SO'){
   $('#bu_org_id').prop('disabled', false).prop('required', true);
  }
 });

 //get tax code
 $('#content').off('change', '.shipping_org_id').on('change', '.shipping_org_id', function () {
  var org_id = $(this).val();
  var trClass = '.' + $(this).closest('tr').prop('class');
  getTaxCodes('modules/mdm/tax_code/json_tax_code.php', org_id, 'OUT', trClass);
 });

 //selecting PO Header Id
 $(".sd_quote_header_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=sd_quote_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Popup for selecting address 
 $(".address_popup").click(function () {
  var addressPopupDivClass = $(this).closest('div').prop('class');
  localStorage.setItem("addressPopupDivClass", addressPopupDivClass);
  void window.open('select.php?class_name=address', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

////default data from document type
// $('#document_type').on('change', function () {
//  var document_type_id = $(this).val();
//  getDocumentTypeDetails(document_type_id);
// })

 //price from price list
 $('#content').off('change', '.item_id_m, .item_number, .price_list_header_id, .price_date')
         .on('change', '.item_id_m, .item_number, .price_list_header_id, .price_date', function () {
          var rowClass = '.' + $(this).closest('tr').prop('class');
          var item_id_m = $(this).closest('.tabContainer').find(rowClass).find('.item_id_m').val();
          var price_date = $(this).closest('.tabContainer').find(rowClass).find('.price_date').val();
          var price_list_header_id = $(this).closest('#form_line').find(rowClass).find('.price_list_headerId').val();
          getPriceDetails({
           rowClass: rowClass,
           item_id_m: item_id_m,
           price_date: price_date,
           price_list_header_id: price_list_header_id});
         });

//set the line price
 $('#content').off('blur', '.unit_price,.line_quantity')
         .on('blur', '.unit_price,.line_quantity', function () {
          var trClass = '.' + $(this).closest('tr').attr('class');
          var unitPrice = +($(this).closest('#form_line').find(trClass).find('.unit_price').val());
          var lineQuantity = +($(this).closest('#form_line').find(trClass).find('.line_quantity').val());
          var linePrice = unitPrice * lineQuantity;
          $(this).closest('tr').find('.line_price').val(linePrice);
         });

//calculate the tax amount
 $('#content').off('blur', '.line_quantity, .unit_price, .line_price')
         .on('blur', '.line_quantity, .unit_price, .line_price', function () {
          var trClass = '.' + $(this).closest('tr').prop('class');
          var linePrice = +$('#content').find(trClass).find('.line_price').val();
          var taxCodeVal = 0;
          if ($('#content').find(trClass).find('.tax_code_value').val()) {
           taxCodeVal = $('#content').find(trClass).find('.tax_code_value').val();
          } else if ($('#content').find(trClass).find('.output_tax').find('option:selected').prop('class')) {
           taxCodeVal = $('#content').find(trClass).find('.output_tax').find('option:selected').prop('class');
          }

          if (taxCodeVal.length >= 3) {
           var taxCodeVal_a = taxCodeVal.split('_');
          } else {
           return;
          }
          var taxAmount = 0;
          var taxPercentage = 0;
          if (taxCodeVal_a[0] === 'p') {
           taxPercentage = +taxCodeVal_a[1];
          } else if (taxCodeVal_a[0] === 'a') {
           taxAmount = +taxCodeVal_a[1];
          }
          var taxValue = 0;
          if (taxPercentage) {
           taxValue = ((taxPercentage * linePrice) / 100).toFixed(5);
          } else if (taxAmount) {
           taxValue = taxAmount.toFixed(5);
          }

          $('#content').find(trClass).find('.tax_amount').val(taxValue);
         });

//total header & tax amount
 $('#content').off('blur', '.inv_line_quantity, .inv_unit_price, .inv_line_price')
         .on('blur', '.inv_line_quantity, .inv_unit_price, .inv_line_price', function () {
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

});
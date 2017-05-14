function setValFromSelectPage(pos_barcode_list_header_id, item_id_m, item_number, item_description, uom_id) {
 this.pos_barcode_list_header_id = pos_barcode_list_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var pos_barcode_list_header_id = this.pos_barcode_list_header_id;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 
 
  if (pos_barcode_list_header_id) {
	$("#pos_barcode_list_header_id").val(pos_barcode_list_header_id);
 }
 
  rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
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
 localStorage.removeItem("field_class");
 
};

 //Check the option_id while entering the option line code
 function copy_pos_barcode_list_header_id() {
	$(".pos_barcode_list_line_code").blur(function()
	{
	 if ($("#pos_barcode_list_header_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".pos_barcode_list_line_code").val("");
	 } else {
		$(".pos_barcode_list_header_id").val($("#pos_barcode_list_header_id").val());
	 }
	});
 }
 

$(document).ready(function() {
 //Popup for selecting option type
 $(".pos_barcode_list_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=pos_barcode_list_header', '_blank',
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
//  line_amount_e.val(line_amount);
  $(line_amount_e).closest('tr').find('.line_amount').val(line_amount);
  $(line_amount_e).closest('tr').find('.amount_after_discount').val(amount_after_discount);
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  $('#pos_transaction_line_cust_view').find(trClass).find('.amount_after_discount').val(amount_after_discount);
 });

 $('#content').off('blur', '.unit_price, .quantity, .discount_amount').on('blur', '.unit_price, .quantity, .discount_amount', function () {
  $(this).closest('tr').find('.line_amount').trigger('calPOSLineAmount');
 });

 $('body').off('blur', '.discount_code').on('blur', '.discount_code', function () {
  if (!$(this).val() || (isNaN($(this).val()))) {
   return true;
  }
  var discount_amount_per = +$(this).closest('tr').find('.discount_code').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var line_amount = +$(this).closest('tr').find('.line_amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var dicount_amount = (discount_amount_per * line_amount) / 100;
//  alert(line_amount +  ' : ' + dicount_amount)
  $(this).closest('tr').find('.discount_amount').val(dicount_amount);
  $(this).closest('tr').find('.line_amount').trigger('calPOSLineAmount');
 });

});


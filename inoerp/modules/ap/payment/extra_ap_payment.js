$(document).ready(function() {
//add default values on line
 $('#form_line').on('click', '.line_id_cb', function() {
	if ($(this).prop('checked')) {
	 var trclass = '.' + $(this).closest('tr').prop('class');
	 var quantity = (+$(this).closest('tr').find('.line_quantity').val()) - (+$(this).closest('.tabContainer').find(trclass).find('.invoiced_quantity').val());
	 $(this).closest('tr').find('.inv_line_quantity').val(quantity);
	 var unit_prices = $(this).closest('.tabContainer').find(trclass).find('.unit_price').val();
	 $(this).closest('tr').find('.inv_unit_price').val(unit_prices);
	 var inv_line_type = "<select id='account_type' class=' select account_type ' name='account_type[]'>";
	 inv_line_type += "<option value=''></option>";
	 inv_line_type += "<option selected value='ITEM'>Item</option>";
	 inv_line_type += "<option value='TAX'>Tax</option>";
	 inv_line_type += "<option value='MISC'>Miscellaneous</option>";
	 inv_line_type += "<option value='FREIGHT'>Freight</option>";
	 inv_line_type += "</selction>";
	 $(this).closest('tr').find('.inv_line_type').replaceWith(inv_line_type);
	} else {
	 $(this).closest('tr').find('.inv_line_quantity').val('');
	 $(this).closest('tr').find('.inv_unit_price').val('');
	 $(this).closest('tr').find('.inv_line_type').val('');
	 $(this).closest('tr').find('.inv_line_price').val('');
	}
 });

 $('#form_line').on('blur', '.inv_line_quantity, .inv_unit_price, .inv_line_price ', function() {
	var quantity = +$(this).closest('tr').find('.inv_line_quantity').val();
	var unit_prices = +$(this).closest('tr').find('.inv_unit_price').val();
	$(this).closest('tr').find('.inv_line_price').val(quantity * unit_prices);
 });




});

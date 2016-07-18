$(document).ready(function() {

//Name Value
 $('#form_line').on('focusout', '.country_code, .city, .state', function() {
	var tax_region_name = '';
	tax_region_name += $(this).closest('tr').find('.country_code').val();
	tax_region_name += '-'+$(this).closest('tr').find('.state').val();
	tax_region_name += '-'+$(this).closest('tr').find('.city').val();
	$(this).closest('tr').find('.tax_region_name').val(tax_region_name);
 });

$('#content').on('focusin', '.line_data', function() {
	$(this).prop('disabled', true);
 });

 });  
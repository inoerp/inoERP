$(document).ready(function() {
// var Mandatory_Fields = ["#country_code", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').off('focusout', '.country_code, .city, .state, .street').on('focusout', '.country_code, .city, .state ,.street', function() {
	var sales_region_name = '';
	sales_region_name += $(this).closest('tr').find('.country_code').val();
	sales_region_name += '-'+$(this).closest('tr').find('.state').val();
	sales_region_name += '-'+$(this).closest('tr').find('.city').val();
  sales_region_name += '-'+$(this).closest('tr').find('.street').val();
	$(this).closest('tr').find('.sales_region_name').val(sales_region_name);
 });

$('#content').on('focusin', '.line_data', function() {
	$(this).prop('disabled', true);
 });

 });  
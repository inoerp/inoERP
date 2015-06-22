$(document).ready(function() {
// var Mandatory_Fields = ["#country_code", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

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
// deleteData('json_tax_region.php');
 deleteData('form.php?class_name=mdm_tax_region&line_class_name=mdm_tax_region');

 });  
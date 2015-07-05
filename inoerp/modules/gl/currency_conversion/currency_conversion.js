$(document).ready(function() {
// var Mandatory_Fields = ["#currency_conversion_type", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').on('focusout', '.currency_conversion_type, .city, .state', function() {
	var tax_region_name = '';
	tax_region_name += $(this).closest('tr').find('.currency_conversion_type').val();
	tax_region_name += '-'+$(this).closest('tr').find('.state').val();
	tax_region_name += '-'+$(this).closest('tr').find('.city').val();
	$(this).closest('tr').find('.tax_region_name').val(tax_region_name);
 });

////Get the tax_region_id on find button click
// $('a.show.gl_currency_conversion').click(function() {
//	var headerId = $('#currency_conversion_type').val();
//	$(this).prop('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class_name=gl_currency_conversion&currency_conversion_type=' + headerId);
// });

// onClick_add_new_row('tr.currency_conversion_line', 'tbody.currency_conversion_values', '2', 'currency_conversion_type');

 $('#content').on('focusin', '.line_data', function() {
	$(this).prop('disabled', true);
 });

 //context menu
// var classContextMenu = new contextMenuMain();
// classContextMenu.docLineId = 'gl_currency_conversion_id';
// classContextMenu.btn2DivId = 'form_line';
// classContextMenu.trClass = 'currency_conversion_line';
// classContextMenu.tbodyClass = 'form_data_line_tbody';
// classContextMenu.noOfTabbs = 2;
//// classContextMenu.contextMenu();
//
// var tax_regionSave = new saveMainClass();
// tax_regionSave.json_url = 'form.php?class_name=gl_currency_conversion';
// tax_regionSave.single_line = false;
// tax_regionSave.line_key_field = 'rate';
// tax_regionSave.form_line_id = 'gl_currency_conversion';
// tax_regionSave.saveMain();

});  
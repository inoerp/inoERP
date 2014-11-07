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

//Get the tax_region_id on find button click
 $('a.show.mdm_tax_region').click(function() {
	var headerId = $('#country_code').val();
	$(this).prop('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class=mdm_tax_region&country_code=' + headerId);
 });

 onClick_add_new_row('tr.tax_region_line0', 'tbody.tax_region_values', '2', 'country_code');
// $("body table").on("click", ".add_row_img", function() {
//	var addNewRow = new add_new_rowMain();
//	addNewRow.trClass = 'tr.tax_region_line0';
//	addNewRow.tbodyClass = 'tbody.tax_region_values';
//	addNewRow.noOfTabs = '2';
//	addNewRow.removeDefault = false;
//	addNewRow.divClassNotToBeCopied = 'dontCopy';
//	addNewRow.add_new_row();
// });

 $('#content').on('focusin', '.line_data', function() {
	$(this).prop('disabled', true);
 });
// deleteData('json_tax_region.php');
 deleteData('form.php?class_name=mdm_tax_region&line_class_name=mdm_tax_region');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docLineId = 'mdm_tax_region_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'tax_region_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
// classContextMenu.contextMenu();

 var tax_regionSave = new saveMainClass();
 tax_regionSave.json_url = 'form.php?class_name=mdm_tax_region';
 tax_regionSave.single_line = false;
 tax_regionSave.line_key_field = 'tax_region_name';
 tax_regionSave.form_line_id = 'mdm_tax_region';
 tax_regionSave.saveMain();

});  
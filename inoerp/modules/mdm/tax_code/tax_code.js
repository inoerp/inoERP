function setValFromSelectPage( combination) {
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
// var Mandatory_Fields = ["#org_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').on('focusout', '.year', function() {
	var name = '';
	name += $(this).closest('tr').find('.name_prefix').val();
	name += '-' + $(this).val();
	$(this).closest('tr').find('.name').val(name);
 });

//Get the tax_code_id on find button click
 $('a.show.mdm_tax_code').click(function() {
	var headerId = $('#org_id').val();
	$(this).prop('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class_name=mdm_tax_code&org_id=' + headerId);
 });

 onClick_add_new_row('tr.tax_code_line0', 'tbody.tax_code_values', 3);
// deleteData('json_tax_code.php');
deleteData('form.php?class_name=mdm_tax_code&line_class_name=mdm_tax_code');

 //context menu
 var classContextMenu = new contextMenuMain();
  classContextMenu.docLineId = 'mdm_tax_code_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'tax_code_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
// classContextMenu.contextMenu();
 
 var tax_codeSave = new saveMainClass();
 tax_codeSave.json_url = 'form.php?class_name=mdm_tax_code';
 tax_codeSave.single_line = false;
 tax_codeSave.line_key_field = 'tax_code';
 tax_codeSave.form_line_id = 'mdm_tax_code';
 tax_codeSave.saveMain();

});  
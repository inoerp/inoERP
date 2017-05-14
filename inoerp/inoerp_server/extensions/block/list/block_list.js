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


 onClick_add_new_row('tr.block_line', 'tbody.form_data_line_tbody', 1);


 //context menu
 var classContextMenu = new contextMenuMain();
  classContextMenu.docLineId = 'block_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'block_number';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 1;
// classContextMenu.contextMenu();
 
 var tax_codeSave = new saveMainClass();
 tax_codeSave.json_url = 'form.php?class_name=block';
 tax_codeSave.single_line = false;
 tax_codeSave.line_key_field = 'title';
 tax_codeSave.lineClassName = 'block';
 tax_codeSave.saveMain();

});  
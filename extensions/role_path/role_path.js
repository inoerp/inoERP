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

 $('a.show.role_id').click(function(e) {
	var role_id = $('#role_id').val();
	$(this).attr('href', modepath() + 'role_id=' + role_id);
 });


// deleteData('json_role_path.php');
deleteData('form.php?class_name=role_path&line_class_name=role_path');

 //context menu
 var classContextMenu = new contextMenuMain();
  classContextMenu.docLineId = 'role_path_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'role_path_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 1;
// classContextMenu.contextMenu();
 
 var role_pathSave = new saveMainClass();
 role_pathSave.json_url = 'form.php?class_name=role_path';
 role_pathSave.single_line = false;
 role_pathSave.line_key_field = 'role_path';
 role_pathSave.form_line_id = 'role_path';
 role_pathSave.saveMain();

});  
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

 $('a.show.role_code').click(function(e) {
	var role_code = $('#role_code').val();
		$(this).prop('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class_name=role_access&role_code=' + role_code);
 });

onClick_add_new_row('tr.role_access_line0', 'tbody.role_access_values', '1', 'role_code');
// deleteData('json_role_access.php');
deleteData('form.php?class_name=role_access&line_class_name=role_access');

 //context menu
 var classContextMenu = new contextMenuMain();
  classContextMenu.docLineId = 'role_access_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'role_access_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 1;
// classContextMenu.contextMenu();
 
 var role_accessSave = new saveMainClass();
 role_accessSave.json_url = 'form.php?class_name=role_access';
 role_accessSave.single_line = false;
 role_accessSave.line_key_field = 'obj_class_name';
 role_accessSave.form_line_id = 'role_access';
 role_accessSave.saveMain();

});  
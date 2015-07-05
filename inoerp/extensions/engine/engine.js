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
$('#content').on('click', '.uninstall_cb', function(){
if(!$(this).prop('checked')){
return;
}
var trClass = '.'+$(this).closest('tr').prop('class');
var installStatus = $('#form_line').find(trClass).find('.installed_cb').prop('checked');
var enableStatus = $('#form_line').find(trClass).find('.enabled_cb').prop('checked');
if( installStatus === true && enableStatus === false){
alert('System \'ll remove all data & drop all the tables in this module!');
alert('Uninstall is disabled due to security reasons');
}else{
alert('You can only uninstall a module that is installed but disabled!');
$(this).prop('checked', false);
}
});



 //context menu
// var classContextMenu = new contextMenuMain();
//  classContextMenu.docLineId = 'engine_id';
// classContextMenu.btn2DivId = 'form_line';
// classContextMenu.trClass = 'engine_line';
// classContextMenu.tbodyClass = 'form_data_line_tbody';
// classContextMenu.noOfTabbs = 2;
//// classContextMenu.contextMenu();
// 
// var engineSave = new saveMainClass();
// engineSave.json_url = 'form.php?class_name=engine';
// engineSave.single_line = false;
// engineSave.line_key_field = 'obj_class_name';
// engineSave.form_line_id = 'engine_line';
// engineSave.saveMain();

});  
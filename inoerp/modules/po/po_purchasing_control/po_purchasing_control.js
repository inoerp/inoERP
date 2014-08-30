function setValFromSelectPage(address_name) {
 this.address_name = address_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var address_name = this.address_name;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (address_name) {
	$("#content").find(fieldClass).val(address_name);
 }
};


$(document).ready(function() {

 //Get the po_purchasing_control_id on find button click
 $('a.show.org_id').click(function() {
	var org_id = $('#org_id').val();
	$(this).attr('href', modepath() + 'org_id=' + org_id);
 });


 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'po_purchasing_control_id';
 classContextMenu.btn1DivId = 'po_purchasing_control_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=po_purchasing_control';
 classSave.form_header_id = 'po_purchasing_control';
 classSave.primary_column_id = 'po_purchasing_control_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'po_purchasing_control';
 classSave.saveMain();


});


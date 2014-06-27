function setValFromSelectPage(sd_document_type_id) {
 this.sd_document_type_id = sd_document_type_id;
 }

setValFromSelectPage.prototype.setVal = function() {
 var sd_document_type_id = this.sd_document_type_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (sd_document_type_id) {
	$("#sd_document_type_id").val(sd_document_type_id);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".sd_document_type_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sd_document_type', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the sd_document_type_id on find button click
 $('a.show.sd_document_type_id').click(function() {
	var sd_document_type_id = $('#sd_document_type_id').val();
	$(this).attr('href', modepath() + 'sd_document_type_id=' + sd_document_type_id);
 });

//context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'sd_document_type_id';
 classContextMenu.btn1DivId = 'sd_document_type_id';
 classContextMenu.contextMenu();

//save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=sd_document_type';
 classSave.form_header_id = 'sd_document_type_form';
 classSave.primary_column_id = 'sd_document_type_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'sd_document_type';
 classSave.saveMain();


});
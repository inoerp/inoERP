function setValFromSelectPage(supplier_bu_id, combination) {
 this.supplier_bu_id = supplier_bu_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 var supplier_bu_id = this.supplier_bu_id;
 if (supplier_bu_id) {
	$("#supplier_bu_id").val(supplier_bu_id);
 }
 if(combination){
$('#content').find(fieldClass).val(combination);
 localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
//selecting supplier
 $(".select.header_id_popup").click(function() {
	void window.open('select.php?class_name=supplier_bu', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the supplier_id on refresh button click
 $('a.show.supplier_bu_id').click(function() {
	var supplier_bu_id = $('#supplier_bu_id').val();
	$(this).attr('href', modepath() + 'supplier_bu_id=' + supplier_bu_id);
 });

 //popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
//	var coa_id = $('#coa_id').val();
	var fieldClass = $(this).closest('li').find('.select_account').prop('class');
	localStorage.setItem("field_class", fieldClass);
	var openUrl = 'select.php?class_name=coa_combination';
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'gl_journal_header_id';
 classContextMenu.docLineId = 'gl_journal_line_id';
 classContextMenu.btn1DivId = 'gl_journal_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'gl_journal_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
// classContextMenu.contextMenu();

 var fu = new fileUploadMain();
 fu.json_url = 'extensions/file/upload.php';
 fu.module_name = 'ap';
 fu.class_name = 'supplier_bu';
 fu.document_type = 'supplier_bu';
 fu.directory = 'ap/supplier';
 fu.fileUpload();
 

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=supplier_bu';
 classSave.form_header_id = 'supplier_bu';
 classSave.primary_column_id = 'supplier_bu_id';
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = 'supplier_bu';
 classSave.saveMain();
});

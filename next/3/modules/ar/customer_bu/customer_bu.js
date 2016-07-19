function setValFromSelectPage(customer_bu_id, combination) {
 this.customer_bu_id = customer_bu_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 var customer_bu_id = this.customer_bu_id;
 if (customer_bu_id) {
	$("#customer_bu_id").val(customer_bu_id);
 }
 if(combination){
$('#content').find(fieldClass).val(combination);
 localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
//selecting customer
 $(".select.header_id_popup").click(function() {
	void window.open('select.php?class_name=customer_bu', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the customer_id on refresh button click
 $('a.show.ar_customer_bu_id').click(function() {
	var ar_customer_bu_id = $('#ar_customer_bu_id').val();
	$(this).attr('href', modepath() + 'ar_customer_bu_id=' + ar_customer_bu_id);
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
 classContextMenu.docHedaderId = 'ar_customer_bu_id';
 classContextMenu.docLineId = 'ar_customer_bu_line_id';
 classContextMenu.btn1DivId = 'ar_customer_bu';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'ar_customer_bu_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 1;
// classContextMenu.contextMenu();

 var fu = new fileUploadMain();
 fu.json_url = 'extensions/file/upload.php';
 fu.module_name = 'ar';
 fu.class_name = 'customer_bu';
 fu.document_type = 'customer_bu';
 fu.directory = 'ar/customer';
 fu.fileUpload();
 

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=customer_bu';
 classSave.form_header_id = 'customer_bu';
 classSave.primary_column_id = 'customer_bu_id';
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = 'ar_customer_bu';
 classSave.saveMain();
});

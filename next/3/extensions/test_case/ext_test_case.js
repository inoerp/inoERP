function setValFromSelectPage(ext_test_case_header_id ) {
 this.ext_test_case_header_id = ext_test_case_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var ext_test_case_header_id = this.ext_test_case_header_id;
 if (ext_test_case_header_id) {
	$('#ext_test_case_header_id').val(ext_test_case_header_id);
 }
};

$(document).ready(function() {

//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'ext_test_case_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "receipt_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Receipt Type"];
// mandatoryCheck.mandatoryField();

 //selecting Header Id
 $(".ext_test_case_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=ext_test_case_header&status=AWAITING_SHIPPING', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 //Get the receipt_id on find button click
 $('a.show.ext_test_case_header').click(function() {
	var receiptId = $('#ext_test_case_header_id').val();
	$(this).attr('href', modepath() + 'ext_test_case_header_id=' + receiptId);
 });

 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'ext_test_case_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'ext_test_case_header_id';
 classContextMenu.docLineId = 'ext_test_case_line_id';
 classContextMenu.btn1DivId = 'ext_test_case_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'receipt_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 5;
 classContextMenu.contextMenu();


 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=ext_test_case_header';
 classSave.form_header_id = 'ext_test_case_header';
 classSave.primary_column_id = 'ext_test_case_header_id';
 classSave.line_key_field = 'step_action';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'ext_test_case_header';
 classSave.lineClassName = 'ext_test_case_line';
 classSave.enable_select = true;
 classSave.saveMain();

});

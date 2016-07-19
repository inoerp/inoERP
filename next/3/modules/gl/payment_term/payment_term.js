$(document).ready(function() {
 var mandatoryCheck = new mandatoryFieldMain();
  mandatoryCheck.mandatoryHeader();
  
 $("#content tbody.form_data_line_tbody2").off("click", ".add_row_img").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'payment_term_discount';
	addNewRow.tbodyClass = 'form_data_line_tbody2';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });


});

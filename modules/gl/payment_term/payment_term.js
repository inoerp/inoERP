 function setValFromSelectPage(payment_term_id){
	this.payment_term_id = payment_term_id;
 }
 
setValFromSelectPage.prototype.setVal = function(){
 payment_term_id = this.payment_term_id;
 $("#payment_term_id").val(payment_term_id);
};

$(document).ready(function() {
//selecting payment_term
 $(".payment_term_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=payment_term', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('a.show.payment_term_headerId').on('click',function() {
	var headerId = $('#payment_term_id').val();
	$(this).attr('href', modepath() + 'payment_term_id=' + headerId);
 });
//add new lines
 $("#content tbody.form_data_line_tbody").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'payment_term_schedule';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'payment_term_discount';
	addNewRow.tbodyClass = 'form_data_line_tbody2';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=payment_term';
 classSave.form_header_id = 'payment_term_header';
 classSave.primary_column_id = 'payment_term_id';
 classSave.line_key_field = 'item_description';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.enable_select = true;
 classSave.headerClassName = 'payment_term_header';
 classSave.lineClassName = 'payment_term_schedule';
 classSave.lineClassName2 = 'payment_term_discount';
 classSave.saveMain();

});

function setValFromSelectPage(transaction_type_id, combination) {
 this.transaction_type_id = transaction_type_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var transaction_type_id = this.transaction_type_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (transaction_type_id) {
	$("#transaction_type_id").val(transaction_type_id);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};


$(document).ready(function() {
 //selecting Id
 $(".transaction_type_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=transaction_type', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the transaction_type_id on find button click
 $('a.show.transaction_type_id').click(function() {
	var transaction_type_id = $('#transaction_type_id').val();
	$(this).attr('href', modepath() + 'transaction_type_id=' + transaction_type_id);
 });

 //popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
	var fieldClass = $(this).closest('li').find('.select_account').prop('class');
	localStorage.setItem("field_class", fieldClass);
	var openUrl = 'select.php?class_name=coa_combination';
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'transaction_type_id';
 classContextMenu.btn1DivId = 'transaction_type_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=transaction_type';
 classSave.form_header_id = 'transaction_type_form';
 classSave.primary_column_id = 'transaction_type_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'transaction_type';
 classSave.saveMain();


});


function setValFromSelectPage(subinventory_id, combination) {
 this.subinventory_id = subinventory_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var subinventory_id = this.subinventory_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (subinventory_id) {
	$("#subinventory_id").val(subinventory_id);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};


$(document).ready(function() {
 //selecting Id
 $(".subinventory_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=subinventory', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the subinventory_id on find button click
 $('a.show.subinventory_id').click(function() {
	var subinventory_id = $('#subinventory_id').val();
	$(this).attr('href', modepath() + 'subinventory_id=' + subinventory_id);
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
 classContextMenu.docHedaderId = 'subinventory_id';
 classContextMenu.btn1DivId = 'subinventory_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=subinventory';
 classSave.form_header_id = 'subinventory';
 classSave.primary_column_id = 'subinventory_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'subinventory';
 classSave.saveMain();


});


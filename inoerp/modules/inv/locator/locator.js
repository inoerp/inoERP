function setValFromSelectPage(locator_id, combination) {
 this.locator_id = locator_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var locator_id = this.locator_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (locator_id) {
	$("#locator_id").val(locator_id);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};


$(document).ready(function() {
 //selecting Id
 $(".locator_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=locator', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the locator_id on find button click
 $('a.show.locator_id').click(function() {
	var locator_id = $('#locator_id').val();
	$(this).attr('href', modepath() + 'locator_id=' + locator_id);
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
 classContextMenu.docHedaderId = 'locator_id';
 classContextMenu.btn1DivId = 'locator_id';
 classContextMenu.contextMenu();

 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=locator';
 classSave.form_header_id = 'locator';
 classSave.primary_column_id = 'locator_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'locator';
 classSave.saveMain();


});


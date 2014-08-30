function setValFromSelectPage(inventory_id, combination) {
 this.inventory_id = inventory_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var inventory_id = this.inventory_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (inventory_id) {
	$("#inventory_id").val(inventory_id);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};


$(document).ready(function() {
 //selecting Id
 $(".inventory_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=inventory', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the inventory_id on find button click
 $('a.show.inventory_id').click(function() {
	var inventory_id = $('#inventory_id').val();
	$(this).attr('href', modepath() + 'inventory_id=' + inventory_id);
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
 classContextMenu.docHedaderId = 'inventory_id';
 classContextMenu.btn1DivId = 'inventory_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=inventory';
 classSave.form_header_id = 'inventory';
 classSave.primary_column_id = 'inventory_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'inventory';
 classSave.saveMain();


});


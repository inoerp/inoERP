function setValFromSelectPage(bom_header_id) {
 this.bom_header_id = bom_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bom_header_id = this.bom_header_id;
 $("#bom_header_id").val(bom_header_id);
};

$(document).ready(function() {
 var Mandatory_Fields = ["#org_id", "First Select BU Name", "#item_number", "First enter item number"];
 select_mandatory_fields_all('#bom_divId', Mandatory_Fields);

 //dont allow line entry with out bom_header id
 $('#form_line').on("click", function() {
	if (!$('#bom_header_id').val()) {
	 alert('No header Id : First enter/save header details');
	} else {
	 var PO_ID = $('#bom_header_id').val();
	 if (!$(this).find('.bom_header_id').val()) {
		$(this).find('.bom_header_id').val(PO_ID);
	 }
	}
 });

 //Popup for selecting bom
 $("a.popup.bom_header_id").click(function() {
	void window.open('../../select.php?class_name=bom_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the bom_id on find button click
 $('#form_header a.show.bom_header_id').click(function() {
	var headerId = $('#bom_header_id').val();
	$(this).attr('href', modepath() + 'bom_header_id=' + headerId);
 });

 //add a new row
 $("#content").on("click", ".add_row_img", function() {
	add_new_row('tr.bom_line0', 'tbody.form_data_line_tbody', 3);
 });

//auto complete
 itemNumber_autoComplete('../inv/item/item_search.php');

 //get subinventories on selecting org
 $('#content').on('blur', '#org_id', function() {
	var org_id = $(this).val();
	getSubInventory('../inv/subinventory/json.subinventory.php', org_id);
 });

 //get locators on changing sub inventory
 $('#content').on('blur', '.subinventory_id', function() {
	var trClass = '.' + $(this).closest('tr').attr('class');
	var subinventory_id = $(this).val();
	getLocator('../inv/locator/json.locator.php', subinventory_id, 'subinventory', trClass);
 });


//--------------------------------------------------------------
//right click menu
 var menuContent = "<div><ul>";
 menuContent += "<li id='menu_button1'>Export BOM Header</li>";
 menuContent += "<li id='menu_button2'>Export BOM Line </li>";
 menuContent += "<li id='menu_button3'>Print</li>";
 menuContent += "<li id='menu_button4'>Copy Line</li>";
 menuContent += "<div><ul>";
 rightClickMenu(menuContent);

 $("#content").on('click', '#menu_button1', function() {
	var classDnldExcel = new exportToExcelMain();
	classDnldExcel.containerType = 'div';
	classDnldExcel.divId = 'bom_header';
	classDnldExcel.exportToExcel();
 });

 $("#content").on('click', '#menu_button3', function() {
	window.print();
 });

 $("#content").on('click', '#menu_button2', function() {
	var classDnldExcel = new exportToExcelMain();
	classDnldExcel.containerType = 'table';
	classDnldExcel.divId = 'bom_line';
	classDnldExcel.numberOfTabs = 3;
	classDnldExcel.exportToExcel();
 });

 $("#content").on('click', '#menu_button4', function() {
	trclass = '.' + $("#form_line tr:last").prop('class');
	add_new_row_withDefault(trclass, 'tbody.form_data_line_tbody', 3, '.bom_line_id');
 });



//down load to excel
 $("#indentedBom_divId .export_to_excel").on('click', function(e) {
	exportToExcel_fromDivId('#indentedBom_divId #form_line', 3);
	e.preventDefault();
 });

 $("#bom_divId .export_to_excel").on('click', function(e) {
	exportToExcel_fromDivId('#bom_divId #form_line', 3);
	e.preventDefault();
 });

//remove bom lines
 $("#remove_row").click(function() {
	$('input[name="bom_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//get the attachement form
 deleteData('json.bom.php');
// save('json.bom.php', '#bom_header', 'line_id_cb', 'component_item_id', '#bom_header_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'bom.php';
 classSave.form_header_id = 'bom_header';
 classSave.primary_column_id = 'bom_header_id';
 classSave.line_key_field = 'item_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'bom_header';
 classSave.lineClassName = 'bom_line';
 classSave.saveMain();
});

function setValFromSelectPage(bom_header_id, item_id, item_number, item_description, uom_id) {
 this.bom_header_id = bom_header_id;
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bom_header_id = this.bom_header_id;
 $("#bom_header_id").val(bom_header_id);
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');

 var item_obj = [{id: 'component_item_id', data: this.item_id},
	{id: 'component_item_number', data: this.item_number},
	{id: 'component_description', data: this.item_description},
	{id: 'uom', data: this.uom_id}
 ];

 $(item_obj).each(function(i, value) {
	if (value.data) {
	 var fieldClass = '.' + value.id;
	 $('#content').find(rowClass).find(fieldClass).val(value.data);
	}
 });

};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

 //setting the first line number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('10');
 }


 //Popup for selecting bom
 $(".bom_header_id.select_popup").click(function() {
	void window.open('select.php?class_name=bom_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the bom_id on find button click
 $('#form_header a.show.bom_header_id').click(function() {
	var headerId = $('#bom_header_id').val();
	$(this).attr('href', modepath() + 'bom_header_id=' + headerId);
 });

 //add a new row
// onClick_add_new_row('tr.bom_line0', 'tbody.form_data_line_tbody', 3);
 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'bom_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 3;
	addNewRow.lineNumberIncrementValue = 10;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

////auto complete
// itemNumber_autoComplete('../inv/item/item_search.php');

 //get subinventories on selecting org
 $('#content').on('blur', '#org_id', function() {
	var org_id = $(this).val();
	getSubInventory('modules/inv/subinventory/json_subinventory.php', org_id);
 });

 //get locators on changing sub inventory
 $('#content').on('blur', '.subinventory_id', function() {
	var trClass = '.' + $(this).closest('tr').attr('class');
	var subinventory_id = $(this).val();
	getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', trClass);
 });

//popu for selecting items
 $('#content').on('click', '.select_item_number.select_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	localStorage.removeItem("row_class", rowClass);
	localStorage.setItem("row_class", rowClass);
	var openUrl = 'select.php?class_name=item';
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'bom_header_id';
 classContextMenu.docLineId = 'bom_line_id';
 classContextMenu.btn1DivId = 'bom_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'bom_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();

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
 classSave.json_url = 'form.php?class_name=bom_header';
 classSave.form_header_id = 'bom_header';
 classSave.primary_column_id = 'bom_header_id';
 classSave.line_key_field = 'item_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'bom_header';
 classSave.lineClassName = 'bom_line';
 classSave.saveMain();
});

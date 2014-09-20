function setValFromSelectPage(item_id_m, item_number, item_description, uom_id, bom_routing_header_id) {
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.bom_routing_header_id = bom_routing_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bom_routing_header_id = this.bom_routing_header_id;

 var item_obj = [{id: 'item_id_m', data: this.item_id_m},
	{id: 'item_number', data: this.item_number},
	{id: 'item_description', data: this.item_description},
	{id: 'uom_id', data: this.uom_id}
 ];

 $(item_obj).each(function(i, value) {
	if (value.data) {
	 var fieldId = '#' + value.id;
	 $('#content').find(fieldId).val(value.data);
	}
 });

 if (bom_routing_header_id) {
	$('#bom_routing_header_id').val(bom_routing_header_id);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");
};


$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_routing_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('10');
 }

 if (!($('.detail_number:first').val())) {
	$('.detail_number:first').val('10');
 }

 //selecting Header Id
 $(".bom_routing_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=bom_routing_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".item_id_m.select_popup").on("click", function() {
	void window.open('select.php?class_name=item', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the bom_routing_id on find button click
 $('#form_header a.show').click(function() {
	var bom_routing_header_id = $('#bom_routing_header_id').val();
	$(this).attr('href', modepath() + 'bom_routing_header_id=' + bom_routing_header_id);
 });

//add or show linw details
 addOrShow_lineDetails('tr.bom_routing_line0');

 //function to coply line to details
 function copy_line_to_details() {
	$("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
	 var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
	 if (detailExists === 0) {
		var lineQuantity = $(this).closest('tr').find('.inv_line_quantity').val();
		$(this).closest("td").find(".quantity:first").val(lineQuantity);
	 }
	});
 }

 copy_line_to_details();

 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'bom_routing_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 3;
	addNewRow.lineNumberIncrementValue = 10;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
	$(".tabsDetail").tabs();
 });

 onClick_addDetailLine( 2);

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'bom_routing_header_id';
 classContextMenu.docLineId = 'bom_routing_line_id';
 classContextMenu.btn1DivId = 'bom_routing_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'bom_routing_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=bom_routing_header';
 classSave.form_header_id = 'bom_routing_header';
 classSave.primary_column_id = 'bom_routing_header_id';
 classSave.line_key_field = 'routing_sequence';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'bom_routing_header';
 classSave.lineClassName = 'bom_routing_line';
 classSave.detailClassName = 'bom_routing_detail';
 classSave.enable_select = true;
 classSave.saveMain();

 deleteData('json.bom_routing.php');
// save('json.bom_routing.php', '#bom_routing_header', 'line_id_cb', 'item_description', '#bom_routing_header_id', '', '#bom_routing_number');

});

function setValFromSelectPage(po_requisition_header_id, combination, supplier_id, supplier_number, supplier_name,
				item_id, item_number, item_description, uom_id) {
 this.po_requisition_header_id = po_requisition_header_id;
 this.combination = combination;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;

}

setValFromSelectPage.prototype.setVal = function() {
 var po_requisition_header_id = this.po_requisition_header_id;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var combination = this.combination;
 var item_id = this.item_id;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (po_requisition_header_id) {
	$("#po_requisition_header_id").val(po_requisition_header_id);
 }
 if (supplier_id) {
	$("#supplier_id").val(supplier_id);
 }
 if (supplier_number) {
	$("#supplier_number").val(supplier_number);
 }
 if (supplier_name) {
	$("#supplier_name").val(supplier_name);
 }
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
  if(combination){
 $('#content').find(rowClass).find(fieldClass).val(combination);
 }
 if(item_id){
 $('#content').find(rowClass).find('.item_id').val(item_id);
 }
 if(item_number){
 $('#content').find(rowClass).find('.item_number').val(item_number);
 }
 if(item_description){
 $('#content').find(rowClass).find('.item_description').val(item_description);
 }
 if(uom_id){
 $('#content').find(rowClass).find('.uom_id').val(uom_id);
 }
 
 localStorage.removeItem("row_class");
 localStorage.removeItem("row_class");

};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'po_requisition_header_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "po_requisition_type"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No PO Type"];
 mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('1');
 }

 if (!($('.shipment_number:first').val())) {
	$('.shipment_number:first').val('1');
 }

// $('.need_by_date:first').datepicker("setDate", new Date());
// $('.promise_date:first').datepicker("setDate", new Date());


 //default quantity
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
	var lineQuantity = $(this).closest('tr').find('.line_quantity:first').val();
	if (!$(this).closest("td").find(".quantity:first").val())
	{
	 $(this).closest("td").find(".quantity:first").val(lineQuantity);
	}
 });

//set the line price
 $('#content').on('focusout', '.unit_price,.line_quantity', function() {
	var unitPrice = $(this).val();
	var trClass = '.' + $(this).closest('tr').attr('class');
	var lineQuantity = ($(this).closest('.tabContainer').find(trClass).find('.line_quantity').val());
	var linePrice = unitPrice * lineQuantity;
	$(this).closest('tr').find('.line_price').val(linePrice);
 });

//get supplier details
 $("#supplier_id, #supplier_name, #supplier_number").on("focusout", function() {
	if (($("#bu_org_id").val()) && ($('#supplier_id').val())) {
	 var bu_org_id = $("#bu_org_id").val();
	 getSupplierDetails('modules/ap/supplier/json_supplier.php', bu_org_id);
	}
 });

 $("#content").on("change", "#supplier_site_id", function() {
	var supplier_site_id = $("#supplier_site_id").val();
	if (supplier_site_id) {
	 getSupplierSiteDetails('modules/ap/supplier/json_supplier.php', supplier_site_id);
	}
 });
 
  $("#content").on("focusout", '.ship_to_inventory', function() {
	var ship_to_inventory = $(this).val();
	var rowTrClass = $(this).closest("tr").attr("class");
	var classValue = "tr." + rowTrClass;
	var classValue1 = classValue.replace(/ /g, '.');
	getAllInventoryAccounts('modules/org/inventory/json_inventory.php', ship_to_inventory, classValue1);
 });


//item number auto complete and po_requisitionpulate the other details
// itemNumber_autoComplete('modules/inv/item/item_search.php');

 //Coa auto complete
 var coaCombination = new autoCompleteMain();
 var coa_id = $('#coa_id').val();
 coaCombination.json_url = 'modules/gl/coa_combination/coa_search.php';
 coaCombination.primary_column1 = coa_id;
 coaCombination.select_class = 'select_account';
 coaCombination.min_length = 4;
 coaCombination.autoComplete();
 
 
 //selecting PO Header Id
 $(".po_requisition_header_id.select_po_requisitionpup").on("click", function() {
	void window.open('select.php?class_name=po_requisition_all_v', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//po_requisitionpu for selecting accounts
 $('#content').on('click', '.account_po_requisitionpup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	var fieldClass = $(this).closest('td').find('.select_account').prop('class');
	localStorage.setItem("row_class", rowClass);
	localStorage.setItem("field_class", fieldClass);
	void window.open('select.php?class_name=coa_combination', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//selecting supplier
 $(".supplier_id").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=supplier', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//po_requisitionpu for selecting items
 $('#content').on('click', '.select_item_number.select_po_requisitionpup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	var fieldClass = $(this).closest('td').find('.select_item_number').prop('class');
	localStorage.setItem("row_class", rowClass);
	localStorage.setItem("field_class", fieldClass);
	var openUrl = 'select.php?class_name=item';
	if ($(this).siblings('.code_combination_id').val()) {
	 openUrl += '&item_number=' + $(this).siblings('.item_number').val();
	}
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Popup for selecting address 
 $(".address_po_requisitionpup").click(function() {
	localStorage.addressPopupDivId = $(this).parent().siblings().first().attr("id");
	;
	void window.open('../../select.php?class_name=address', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the supplier_id on refresh button click
 $('a.show.po_requisition_header_id').click(function() {
	var po_requisition_header_id = $('#po_requisition_header_id').val();
	$(this).attr('href', modepath() + 'po_requisition_header_id=' + po_requisition_header_id);

 });


 $('a.show.supplier_number').click(function() {
	var supplier_number = $('#supplier_number').val();
	if ($('#org_id').val().length > 0) {
	 var org_id = $('#org_id').val();
	 $(this).attr('href', modepath() + 'supplier_number=' + supplier_number + '&org_id=' + org_id);
	} else {
	 alert("Query Error!!! \n Select the query mode by pressing Ctrl + Q \n Select the organization name");
	}
 });

 $('a.show.supplier_site_id').click(function() {
	var supplier_id = $('#headerId').val();
	var supplier_site_id = $('#supplier_site_id').val();
	$(this).attr('href', '?supplier_id=' + supplier_id + '&supplier_site_id=' + supplier_site_id);
 });

 $("#supplier_site_name").on("change", function() {
	if ($(this).val() == 'newentry') {
	 if (confirm("Do you want to create a new supplier site?")) {
		$(this).replaceWith('<input id="supplier_site_name" class="textfield supplier_site_name" type="text" size="25" maxlength="50" name="supplier_site_name[]">');
		$(".show.supplier_site_id").hide();
		$("#supplier_site_id").val("");
		$("#supplier_site_number").val("");
	 }

	}
 });


//add or show linw details
 addOrShow_lineDetails('tr.po_requisition_line0');

 //function to coply line to details
 function copy_line_to_details() {
	$("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
	 var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
	 if (detailExists === 0) {
		var lineQuantity = $(this).closest('tr').find('.line_quantity').val();
		$(this).closest("td").find(".quantity:first").val(lineQuantity);
	 }
	});
 }

 copy_line_to_details();



 //Get the po_requisition_id on find button click
 $('#form_box a.show').click(function() {
	var po_requisitionId = $('#po_requisition_header_id').val();
//$(this).prop('href','po_requisition.php?po_requisition_header_id=' + po_requisitionId);
	$(this).attr('href', 'po_requisition.php?po_requisition_header_id=' + po_requisitionId);
 });



 $("#content").on("click", ".add_row_img", function() {
//	add_new_row('tr.po_requisition_line0', 'tbody.form_data_line_tbody', 3);
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'po_requisition_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 3;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
	$(".tabsDetail").tabs();
 });

 onClick_addDetailLine('tr.po_requisition_detail0-0', 'tbody.form_data_detail_tbody', 4);

//remove po_requisition lines
 $("#remove_row").click(function() {
	$('input[name="po_requisition_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'po_requisition_header_id';
 classContextMenu.docLineId = 'po_requisition_line_id';
 classContextMenu.docDetailId = 'po_requisition_detail_id';
 classContextMenu.btn1DivId = 'po_requisition_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'po_requisition_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();

//get the attachement form
// get_attachment_form('../../extensions/file/json.file.php');
// deleteData('json.po_requisition.php');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=po_requisition_header';
 classSave.form_header_id = 'po_requisition_header';
 classSave.primary_column_id = 'po_requisition_header_id';
 classSave.line_key_field = 'item_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'po_requisition_header';
 classSave.lineClassName = 'po_requisition_line';
 classSave.detailClassName = 'po_requisition_detail';
 classSave.saveMain();
});

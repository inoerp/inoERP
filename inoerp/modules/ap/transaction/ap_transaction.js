function setValFromSelectPage(ap_transaction_header_id, combination, supplier_id, supplier_number, supplier_name,
				item_id_m, item_number, item_description, uom_id) {
 this.ap_transaction_header_id = ap_transaction_header_id;
 this.combination = combination;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;

}

setValFromSelectPage.prototype.setVal = function() {
 var ap_transaction_header_id = this.ap_transaction_header_id;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var combination = this.combination;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (ap_transaction_header_id) {
	$("#ap_transaction_header_id").val(ap_transaction_header_id);
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
 if (combination) {
	$('#content').find(rowClass).find(fieldClass).val(combination);
 }
 if (item_id_m) {
	$('#content').find(rowClass).find('.item_id_m').val(item_id_m);
 }
 if (item_number) {
	$('#content').find(rowClass).find('.item_number').val(item_number);
 }
 if (item_description) {
	$('#content').find(rowClass).find('.item_description').val(item_description);
 }
 if (uom_id) {
	$('#content').find(rowClass).find('.uom_id').val(uom_id);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("row_class");

};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'ap_transaction_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "po_type"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No PO Type"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('1');
 }

 if (!($('.detail_number:first').val())) {
	$('.detail_number:first').val('1');
 }

 $('#bu_org_id').on('change', function() {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && ($('#bu_org_id').attr('disabled') != 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }


 //default quantity
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
	var lineQuantity = $(this).closest('tr').find('.inv_line_quantity:first').val();
	if (!$(this).closest("td").find(".quantity:first").val())
	{
	 $(this).closest("td").find(".quantity:first").val(lineQuantity);
	}
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


 //selecting PO Header Id
 $(".ap_transaction_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=ap_transaction_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


//selecting supplier
 $(".find_popup.supplierId").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=supplier', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //Get the ap_transaction_header_id on refresh button click
 $('a.show.ap_transaction_header_id').click(function() {
	var ap_transaction_header_id = $('#ap_transaction_header_id').val();
	$(this).attr('href', modepath() + 'ap_transaction_header_id=' + ap_transaction_header_id);

 });

//add or show linw details
 addOrShow_lineDetails('tr.ap_transaction_line0');

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



// //Get the po_id on find button click
// $('#form_box a.show').click(function() {
//	var poId = $('#ap_transaction_header_id').val();
////$(this).prop('href','po.php?ap_transaction_header_id=' + poId);
//	$(this).attr('href', 'po.php?ap_transaction_header_id=' + poId);
// });



 $("#content").on("click", ".add_row_img", function() {
//	add_new_row('tr.ap_transaction_line0', 'tbody.form_data_line_tbody', 3);
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'ap_transaction_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 3;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
	$(".tabsDetail").tabs();
 });

 onClick_addDetailLine('tr.ap_transaction_detail0-0', 'tbody.form_data_detail_tbody', 2);

//remove po lines
 $("#remove_row").click(function() {
	$('input[name="ap_transaction_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'ap_transaction_header_id';
 classContextMenu.docLineId = 'ap_transaction_line_id';
 classContextMenu.btn1DivId = 'ap_transaction_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'ap_transaction_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();

//get the attachement form
// get_attachment_form('../../extensions/file/json.file.php');
// deleteData('json.po.php');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=ap_transaction_header';
 classSave.form_header_id = 'ap_transaction_header';
 classSave.primary_column_id = 'ap_transaction_header_id';
 classSave.line_key_field = 'item_description';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'ap_transaction_header';
 classSave.lineClassName = 'ap_transaction_line';
 classSave.detailClassName = 'ap_transaction_detail';
 classSave.enable_select = true;
 classSave.saveMain();



//all actions
//Popup for selecting match 
 function match_transaction() {
	var ap_transaction_header_id = $("#ap_transaction_header_id").val();
	if (ap_transaction_header_id) {
	 var link = 'multi_select.php?class_name=po_all_v&action=match_transaction&mode=9&action_class_name=ap_transaction_line&po_status=APPROVED&ap_transaction_header_id=' + ap_transaction_header_id;
	 var po_header_id = $("#po_header_id").val();
	 var po_number = $("#po_number").val();
	 if (po_header_id) {
		link += '&po_header_id=' + po_header_id;
	 } else if (po_number) {
		link += '&po_number=' + po_number;
	 } else {
		var supplier_id = $("#supplier_id").val();
		link += '&supplier_id=' + supplier_id;
	 }
	 localStorage.removeItem("reset_link");
	 localStorage.setItem("reset_link", link);
	 localStorage.removeItem("jsfile");
	 localStorage.setItem("jsfile", "modules/ap/ap_transaction/extra_ap_transaction.js");
	 void window.open(link, '_blank',
					 'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	 return false;
	} else {
	 alert('No Transaction Header ID/nEnter or Save The Header Details ');
	}
 }

 function create_accounting() {
	var ap_transaction_header_id = $("#ap_transaction_header_id").val();
	if (ap_transaction_header_id) {
	 var link = 'multi_select.php?class_name=ap_transaction_header&action=create_accounting&mode=9&action_class_name=ap_transaction_header&ap_transaction_header_id=' + ap_transaction_header_id;
	 localStorage.removeItem("reset_link");
	 localStorage.setItem("reset_link", link);
	 localStorage.removeItem("jsfile");
	 localStorage.setItem("jsfile", "modules/ap/ap_transaction/extra_ap_transaction.js");
	 void window.open(link, '_blank',
					 'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	 return false;
	} else {
	 alert('No Transaction Header ID/nEnter or Save The Header Details ');
	}
 }

 $('#transaction_action').on('change', function() {
	var selected_value = $(this).val();
	switch (selected_value) {
	 case 'CREATE_ACCOUNT' :
		create_accounting();
		break;

	 case 'MATCH' :
		match_transaction();
		break;

	 default :
		break;
	}
 });


});


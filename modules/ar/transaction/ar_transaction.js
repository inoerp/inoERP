function setValFromSelectPage(ar_transaction_header_id, combination, ar_customer_id, customer_number, customer_name,
				item_id, item_number, item_description, uom_id) {
 this.ar_transaction_header_id = ar_transaction_header_id;
 this.combination = combination;
 this.ar_customer_id = ar_customer_id;
 this.customer_number = customer_number;
 this.customer_name = customer_name;
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;

}

setValFromSelectPage.prototype.setVal = function() {
 var ar_transaction_header_id = this.ar_transaction_header_id;
 var ar_customer_id = this.ar_customer_id;
 var customer_number = this.customer_number;
 var customer_name = this.customer_name;
 var combination = this.combination;
 var item_id = this.item_id;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (ar_transaction_header_id) {
	$("#ar_transaction_header_id").val(ar_transaction_header_id);
 }
 if (ar_customer_id) {
	$("#ar_customer_id").val(ar_customer_id);
 }
 if (customer_number) {
	$("#customer_number").val(customer_number);
 }
 if (customer_name) {
	$("#customer_name").val(customer_name);
 }
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(rowClass).find(fieldClass).val(combination);
 }
 if (item_id) {
	$('#content').find(rowClass).find('.item_id').val(item_id);
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
 mandatoryCheck.header_id = 'ar_transaction_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "om_so_type"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No PO Type"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('1');
 }

 if (!($('.detail_number:first').val())) {
	$('.detail_number:first').val('1');
 }

// $('.need_by_date:first').datepicker("setDate", new Date());
// $('.promise_date:first').datepicker("setDate", new Date());


 //default quantity
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
	var lineQuantity = $(this).closest('tr').find('.inv_line_quantity:first').val();
	if (!$(this).closest("td").find(".quantity:first").val())
	{
	 $(this).closest("td").find(".quantity:first").val(lineQuantity);
	}
 });

//get customer details
//get customer details
 $("#ar_customer_id, #customer_name, #customer_number").on("focusout", function() {
	if (($("#bu_org_id").val()) && ($('#ar_customer_id').val())) {
	 var bu_org_id = $("#bu_org_id").val();
	 getCustomerDetails('modules/ar/customer/json_customer.php', bu_org_id);
	}
 });

$("#content").on("change", '#ar_customer_site_id',function() {
var customer_site_id = $("#ar_customer_site_id").val();
if (customer_site_id) {
 getCustomerSiteDetails('modules/ar/customer/json_customer.php', customer_site_id);
}
});


 $("#content").on("focusout", '.ship_to_inventory', function() {
	var ship_to_inventory = $(this).val();
	var rowTrClass = $(this).closest("tr").attr("class");
	var classValue = "tr." + rowTrClass;
	var classValue1 = classValue.replace(/ /g, '.');
	getAllInventoryAccounts('modules/org/inventory/json_inventory.php', ship_to_inventory, classValue1);
 });


//item number auto complete and populate the other details
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
 $(".ar_transaction_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=ar_transaction_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	var fieldClass = $(this).closest('td').find('.select_account').prop('class');
	localStorage.setItem("row_class", rowClass);
	localStorage.setItem("field_class", fieldClass);
	void window.open('select.php?class_name=coa_combination', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//selecting customer
//selecting customer
 $(".ar_customer_id.select_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=ar_customer', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//popu for selecting items
 $('#content').on('click', '.select_item_number.select_popup', function() {
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

 //Get the ar_transaction_header_id on refresh button click
 $('a.show.ar_transaction_header_id').click(function() {
	var ar_transaction_header_id = $('#ar_transaction_header_id').val();
	$(this).attr('href', modepath() + 'ar_transaction_header_id=' + ar_transaction_header_id);

 });


 $('a.show.bu_org_id').click(function() {
	var bu_org_id = $('#bu_org_id').val();
	if (bu_org_id) {
	 $(this).attr('href', modepath() + 'bu_org_id=' + bu_org_id);
	}
 });

 $('a.show.customer_site_id').click(function() {
	var ar_customer_id = $('#headerId').val();
	var customer_site_id = $('#customer_site_id').val();
	$(this).attr('href', '?ar_customer_id=' + ar_customer_id + '&customer_site_id=' + customer_site_id);
 });

 $("#customer_site_name").on("change", function() {
	if ($(this).val() == 'newentry') {
	 if (confirm("Do you want to create a new customer site?")) {
		$(this).replaceWith('<input id="customer_site_name" class="textfield customer_site_name" type="text" size="25" maxlength="50" name="customer_site_name[]">');
		$(".show.customer_site_id").hide();
		$("#customer_site_id").val("");
		$("#customer_site_number").val("");
	 }

	}
 });


//add or show linw details
 addOrShow_lineDetails('tr.ar_transaction_line0');

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



 //Get the om_so_id on find button click
 $('#form_box a.show').click(function() {
	var poId = $('#ar_transaction_header_id').val();
//$(this).prop('href','po.php?ar_transaction_header_id=' + poId);
	$(this).attr('href', 'po.php?ar_transaction_header_id=' + poId);
 });



 $("#content").on("click", ".add_row_img", function() {
//	add_new_row('tr.ar_transaction_line0', 'tbody.form_data_line_tbody', 3);
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'ar_transaction_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 3;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
	$(".tabsDetail").tabs();
 });

 onClick_addDetailLine('tr.ar_transaction_detail0-0', 'tbody.form_data_detail_tbody', 2);

//remove po lines
 $("#remove_row").click(function() {
	$('input[name="ar_transaction_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'ar_transaction_header_id';
 classContextMenu.docLineId = 'ar_transaction_line_id';
 classContextMenu.btn1DivId = 'ar_transaction_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'ar_transaction_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();

//get the attachement form
// get_attachment_form('../../extensions/file/json.file.php');
// deleteData('json.po.php');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=ar_transaction_header';
 classSave.form_header_id = 'ar_transaction_header';
 classSave.primary_column_id = 'ar_transaction_header_id';
 classSave.line_key_field = 'item_description';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'ar_transaction_header';
 classSave.lineClassName = 'ar_transaction_line';
 classSave.detailClassName = 'ar_transaction_detail';
 classSave.enable_select = true;
 classSave.saveMain();


//module specific validations
//add default values on line
// $('#form_line').on('click', '.line_id_cb', function() {
//	if ($(this).prop('checked')) {
//	 var trclass = '.' + $(this).closest('tr').prop('class');
//	 var quantity = (+$(this).closest('tr').find('.inv_line_quantity').val()) - (+$(this).closest('.tabContainer').find(trclass).find('.invoiced_quantity').val());
//	 $(this).closest('tr').find('.inv_inv_line_quantity').val(quantity);
//	 var inv_unit_prices = $(this).closest('.tabContainer').find(trclass).find('.inv_unit_price').val();
//	 $(this).closest('tr').find('.inv_inv_unit_price').val(inv_unit_prices);
//	 var inv_line_type = "<select id='account_type' class=' select account_type ' name='account_type[]'>";
//	 inv_line_type += "<option value=''></option>";
//	 inv_line_type += "<option selected value='ITEM'>Item</option>";
//	 inv_line_type += "<option value='TAX'>Tax</option>";
//	 inv_line_type += "<option value='MISC'>Miscellaneous</option>";
//	 inv_line_type += "<option value='FREIGHT'>Freight</option>";
//	 inv_line_type += "</selction>";
//	 $(this).closest('tr').find('.inv_line_type').replaceWith(inv_line_type);
//	} else {
//	 $(this).closest('tr').find('.inv_inv_line_quantity').val('');
//	 $(this).closest('tr').find('.inv_inv_unit_price').val('');
//	 $(this).closest('tr').find('.inv_line_type').val('');
//	 $(this).closest('tr').find('.inv_inv_line_price').val('');
//	}
// });
//
// $('#form_line').on('blur', '.inv_inv_line_quantity, .inv_inv_unit_price, .inv_inv_line_price ', function() {
//	var quantity = +$(this).closest('tr').find('.inv_inv_line_quantity').val();
//	var inv_unit_prices = +$(this).closest('tr').find('.inv_inv_unit_price').val();
//	$(this).closest('tr').find('.inv_inv_line_price').val(quantity * inv_unit_prices);
// });


//all actions
//Popup for selecting match 
 function match_transaction() {
	var ar_transaction_header_id = $("#ar_transaction_header_id").val();
	if (ar_transaction_header_id) {
	 var link = 'multi_select.php?class_name=om_so_all_v&action=match_transaction&mode=9&action_class_name=ar_transaction_line&om_so_status=APPROVED&ar_transaction_header_id=' + ar_transaction_header_id;
	 var om_so_header_id = $("#om_so_header_id").val();
	 var om_so_number = $("#om_so_number").val();
	 if (om_so_header_id) {
		link += '&om_so_header_id=' + om_so_header_id;
	 } else if (om_so_number) {
		link += '&om_so_number=' + om_so_number;
	 } else {
		var ar_customer_id = $("#ar_customer_id").val();
		link += '&ar_customer_id=' + ar_customer_id;
	 }
	 localStorage.removeItem("reset_link");
	 localStorage.setItem("reset_link", link);
	 localStorage.removeItem("jsfile");
	 localStorage.setItem("jsfile", "modules/ar/ar_transaction/extra_ar_transaction.js");
	 void window.open(link, '_blank',
					 'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	 return false;
	} else {
	 alert('No Transaction Header ID/nEnter or Save The Header Details ');
	}
 }

 function create_accounting() {
	var ar_transaction_header_id = $("#ar_transaction_header_id").val();
	if (ar_transaction_header_id) {
	 var link = 'multi_select.php?class_name=ar_transaction_header&action=create_accounting&mode=9&action_class_name=ar_transaction_header&ar_transaction_header_id=' + ar_transaction_header_id;
	 localStorage.removeItem("reset_link");
	 localStorage.setItem("reset_link", link);
	 localStorage.removeItem("jsfile");
	 localStorage.setItem("jsfile", "modules/ar/ar_transaction/extra_ar_transaction.js");
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
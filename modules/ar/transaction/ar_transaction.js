function setValFromSelectPage(ar_transaction_header_id, combination, ar_customer_id, customer_number, customer_name,
				item_id_m, item_number, item_description, uom_id, address_id, address_name, address,
				country, postal_code) {
 this.ar_transaction_header_id = ar_transaction_header_id;
 this.combination = combination;
 this.ar_customer_id = ar_customer_id;
 this.customer_number = customer_number;
 this.customer_name = customer_name;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.address_id = address_id;
 this.address_name = address_name;
 this.address = address;
 this.country = country;
 this.postal_code = postal_code;
}

setValFromSelectPage.prototype.setVal = function() {
 var ar_transaction_header_id = this.ar_transaction_header_id;
 var ar_customer_id = this.ar_customer_id;
 var customer_number = this.customer_number;
 var customer_name = this.customer_name;
 var combination = this.combination;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
  var address_id = this.address_id;
 var address_name = this.address_name;
 var address = this.address;
 var country = this.country;
 var postal_code = this.postal_code;
 
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
  if (address_id) {
	$('#form_header').find(addressPopupDivClass).find('.address_id').val(address_id);
 }
 if (address_name) {
	$('#form_header').find(addressPopupDivClass).find('.address_name').val(address_name);
 }
 if (address) {
	$('#form_header').find(addressPopupDivClass).find('.address').val(address);
 }
 
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

function header_amount(){
 	var header_amount = 0;
	$('#form_line').find('.inv_line_price').each(function() {
	 header_amount += (+$(this).val());
	 $('#header_amount').val(header_amount);
	});
	
	var total_tax = 0;
	$('#form_line').find('.tax_amount').each(function() {
	 total_tax += (+$(this).val());
	 $('#tax_amount').val(total_tax);
	});
}

function beforeSave(){
 header_amount();
}

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

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'ar_transaction_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "transaction_type"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Transaction Type"];
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
get_customer_detail_for_bu();

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
 classContextMenu.noOfTabbs = 4;
 classContextMenu.contextMenu();

deleteData('form.php?class_name=ar_transaction_header&line_class_name=ar_transaction_line&detail_class_name=ar_transaction_detail');
 
 //save
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=ar_transaction_header';
 classSave.form_header_id = 'ar_transaction_header';
 classSave.primary_column_id = 'ar_transaction_header_id';
// classSave.primary_column_id2 = 'transaction_number';
 classSave.line_key_field = 'item_description';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'ar_transaction_header';
 classSave.lineClassName = 'ar_transaction_line';
 classSave.detailClassName = 'ar_transaction_detail';
 classSave.enable_select = true;
 classSave.saveMain(beforeSave);

//all actions
//Popup for selecting match 
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

$('#bu_org_id').on('change', function(){
 getBUDetails($(this).val());
});

if($('#bu_org_id').val()){
 getBUDetails($('#bu_org_id').val());
}

$('#transaction_type').on('change', function(){
 $('#content').find('.transaction_type').val($(this).val());
 getARTransactionTypeDetails($(this).val());
});

//set the line price
 $('#content').on('change', '.inv_unit_price, .inv_line_quantity', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	var unitPrice = +($('#form_line').find(trClass).find('.inv_unit_price').val());
	var lineQuantity = +($('#form_line').find(trClass).find('.inv_line_quantity').val());
	var linePrice = unitPrice * lineQuantity;
	$('#form_line').find(trClass).find('.inv_line_price').val(linePrice);
 });

//calculate the tax amount
 $('#content').on('change', '.inv_line_quantity, .inv_unit_price, .inv_line_price, .tax_code_id ', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	var linePrice = +$('#content').find(trClass).find('.inv_line_price').val();
	var taxAmount = 0;
	var taxPercentage = 0;
	var taxValue = 0;

	if ($('#content').find(trClass).find('.tax_code_id').val()) {
	 taxPercentage = $('#content').find(trClass).find('.tax_code_id').find('option:selected').data('percentage');
	 taxAmount = $('#content').find(trClass).find('.tax_code_id').find('option:selected').data('amount');
	} 
	if (taxPercentage) {
	 taxValue = ((taxPercentage * linePrice) / 100).toFixed(5);
	} else if (taxAmount) {
	 taxValue = taxAmount.toFixed(5);
	}

	$('#content').find(trClass).find('.tax_amount').val(taxValue);
 });

//total header & tax amount
 $('#content').on('blur', '.inv_line_quantity, .inv_unit_price, .inv_line_price, .tax_amount, .tax_code_id', function() {
header_amount();
 });


});
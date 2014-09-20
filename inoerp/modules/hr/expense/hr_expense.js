function setValFromSelectPage(sd_so_header_id, combination, ar_customer_id, customer_number, customer_name,
				item_id_m, item_number, item_description, uom_id, address_id, address_name, address,
				country, postal_code) {
 this.sd_so_header_id = sd_so_header_id;
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
 var sd_so_header_id = this.sd_so_header_id;
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
 var addressPopupDivClass = '.' + localStorage.getItem("addressPopupDivClass");
 addressPopupDivClass = addressPopupDivClass.replace(/\s+/g, '.');
 if (address_id) {
	$('#form_header').find(addressPopupDivClass).find('.address_id').val(address_id);
 }
 if (address_name) {
	$('#form_header').find(addressPopupDivClass).find('.address_name').val(address_name);
 }
 if (address) {
	$('#form_header').find(addressPopupDivClass).find('.address').val(address);
 }
 if (country) {
	$('#form_header').find(addressPopupDivClass).find('.country').val(country);
 }
 if (postal_code) {
	$('#form_header').find(addressPopupDivClass).find('.postal_code').val(postal_code);
 }
 if (sd_so_header_id) {
	$("#sd_so_header_id").val(sd_so_header_id);
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
 localStorage.removeItem("field_class");
 localStorage.removeItem("addressPopupDivId");

};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'so_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "so_type"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No PO Type"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('1');
 }

 if (!($('.shipment_number:first').val())) {
	$('.shipment_number:first').val('1');
 }

get_customer_detail_for_bu();

 $("#content").on("change", '#ar_customer_site_id', function() {
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


//get tax code
 $('#content').on('change', '.shipping_org_id', function() {
	var org_id = $(this).val();
	var trClass = '.' + $(this).closest('tr').prop('class');
	getTaxCodes('modules/mdm/tax_code/json_tax_code.php', org_id, 'OUT', trClass);
 });

// $('#content').on('change', 'input', function() {
//	var trClass = '.' + $(this).closest('tr').prop('class');
//	$('#content').find(trClass).find('input[name="line_id_cb"]').prop('checked', true);
// });

 //Coa auto complete
 var coaCombination = new autoCompleteMain();
 var coa_id = $('#coa_id').val();
 coaCombination.json_url = 'modules/gl/coa_combination/coa_search.php';
 coaCombination.primary_column1 = coa_id;
 coaCombination.select_class = 'select_account';
 coaCombination.min_length = 4;
 coaCombination.autoComplete();


 //selecting PO Header Id
 $(".sd_so_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sd_so_header', '_blank',
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


 //Popup for selecting address 
 $(".address_popup").click(function() {
	var addressPopupDivClass = $(this).closest('div').prop('class');
	localStorage.setItem("addressPopupDivClass", addressPopupDivClass);
	void window.open('select.php?class_name=address', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the customer_id on refresh button click
 $('a.show.sd_so_header_id').click(function() {
	var sd_so_header_id = $('#sd_so_header_id').val();
	$(this).attr('href', modepath() + 'sd_so_header_id=' + sd_so_header_id);

 });

 $('a.show.customer_number').click(function() {
	var customer_number = $('#customer_number').val();
	if ($('#org_id').val().length > 0) {
	 var org_id = $('#org_id').val();
	 $(this).attr('href', modepath() + 'customer_number=' + customer_number + '&org_id=' + org_id);
	} else {
	 alert("Query Error!!! \n Select the query mode by pressing Ctrl + Q \n Select the organization name");
	}
 });

 $('a.show.customer_site_id').click(function() {
	var customer_id = $('#headerId').val();
	var customer_site_id = $('#customer_site_id').val();
	$(this).attr('href', '?customer_id=' + customer_id + '&customer_site_id=' + customer_site_id);
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

//default data from document type
 $('#document_type').on('change', function() {
	var document_type_id = $(this).val();
	getDocumentTypeDetails(document_type_id);
 })

//add or show linw details
 addOrShow_lineDetails('tr.so_line0');

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

 $("#content").on("click", ".add_row_img", function() {
//	add_new_row('tr.so_line0', 'tbody.form_data_line_tbody', 3);
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'so_line';
	addNewRow.divClassToBeCopied = 'copyValue';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 5;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
	$(".tabsDetail").tabs();
 });

 onClick_addDetailLine(4);

//remove po lines
 $("#remove_row").click(function() {
	$('input[name="so_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

 //context menu
 function beforeContextMenu() {
	$('.line_status').val('');
	$('.picked_quantity').val('');
	$('.shipped_quantity').val('');
	$('.schedule_ship_date').val('');
	$('#so_number').val('');
	return true;
 }

 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'sd_so_header_id';
 classContextMenu.docLineId = 'sd_so_line_id';
 classContextMenu.btn1DivId = 'so_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'so_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.beforeCopy = beforeContextMenu;
 classContextMenu.noOfTabbs = 5;
 classContextMenu.contextMenu();

 deleteData('form.php?class_name=sd_so_header&line_class_name=sd_so_line');

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=sd_so_header';
 classSave.form_header_id = 'so_header';
 classSave.primary_column_id = 'sd_so_header_id';
 classSave.line_key_field = 'item_description';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.enable_select = true;
 classSave.headerClassName = 'sd_so_header';
 classSave.lineClassName = 'sd_so_line';
 classSave.saveMain();

 //default quantity
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
	var lineQuantity = $(this).closest('tr').find('.line_quantity:first').val();
	if (!$(this).closest("td").find(".quantity:first").val())
	{
	 $(this).closest("td").find(".quantity:first").val(lineQuantity);
	}
 });

//price from price list
 $('#content').on('change', '.item_id_m, .item_number, .price_list_header_id, .price_date', function() {
	var rowClass = '.' + $(this).closest('tr').prop('class');
	var item_id_m = $(this).closest('.tabContainer').find(rowClass).find('.item_id_m').val();
	var price_date = $(this).closest('.tabContainer').find(rowClass).find('.price_date').val();
	var price_list_header_id = $(this).closest('#form_line').find(rowClass).find('.price_list_headerId').val();
	getPriceDetails({
 rowClass : rowClass, 
 item_id_m : item_id_m, 
 price_date : price_date, 
 price_list_header_id : price_list_header_id});
 });

//set the line price
 $('#content').on('blur', '.unit_price,.line_quantity', function() {
	var trClass = '.' + $(this).closest('tr').attr('class');
	var unitPrice = +($(this).closest('#form_line').find(trClass).find('.unit_price').val());
	var lineQuantity = +($(this).closest('#form_line').find(trClass).find('.line_quantity').val());
	var linePrice = unitPrice * lineQuantity;
	$(this).closest('tr').find('.line_price').val(linePrice);
 });

//calculate the tax amount
 $('#content').on('blur', '.line_quantity, .unit_price, .line_price', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	var linePrice = +$('#content').find(trClass).find('.line_price').val();
	var taxCodeVal = 0;
	if ($('#content').find(trClass).find('.tax_code_value').val()) {
	 taxCodeVal = $('#content').find(trClass).find('.tax_code_value').val();
	} else if ($('#content').find(trClass).find('.output_tax').find('option:selected').prop('class')) {
	 taxCodeVal = $('#content').find(trClass).find('.output_tax').find('option:selected').prop('class');
	}

	if (taxCodeVal.length >= 3) {
	 var taxCodeVal_a = taxCodeVal.split('_');
	} else {
	 return;
	}
	var taxAmount = 0;
	var taxPercentage = 0;
	if (taxCodeVal_a[0] === 'p') {
	 taxPercentage = +taxCodeVal_a[1];
	} else if (taxCodeVal_a[0] === 'a') {
	 taxAmount = +taxCodeVal_a[1];
	}
	var taxValue = 0;
	if (taxPercentage) {
	 taxValue = ((taxPercentage * linePrice) / 100).toFixed(5);
	} else if (taxAmount) {
	 taxValue = taxAmount.toFixed(5);
	}

	$('#content').find(trClass).find('.tax_amount').val(taxValue);
 });

//total header & tax amount
 $('#content').on('change', '.line_quantity, .unit_price, .line_price, .tax_amount', function() {
	var total_tax = 0;
	$('#form_line').find('.tax_amount').each(function() {
	 total_tax += (+$(this).val());
	 $('#tax_amount').val(total_tax);
	});

	var header_amount = 0;
	$('#form_line').find('.line_price').each(function() {
	 header_amount += (+$(this).val());
	 $('#header_amount').val(header_amount);
	});
 });

});
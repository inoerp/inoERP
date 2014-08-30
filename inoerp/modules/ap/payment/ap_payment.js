function setValFromSelectPage(ap_payment_header_id, ap_transaction_header_id, transaction_number,
				header_amount, supplier_id, supplier_number, supplier_name, paid_amount) {
 this.ap_payment_header_id = ap_payment_header_id;
 this.ap_transaction_header_id = ap_transaction_header_id;
 this.header_amount = header_amount;
 this.paid_amount = paid_amount;
 this.transaction_number = transaction_number;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var ap_payment_header_id = this.ap_payment_header_id;
 var header_amount = this.header_amount;
 var paid_amount = this.paid_amount;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var ap_transaction_header_id = this.ap_transaction_header_id;
 var transaction_number = this.transaction_number;

 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (ap_payment_header_id) {
	$("#ap_payment_header_id").val(ap_payment_header_id);
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
 if (ap_transaction_header_id) {
	$('#content').find(rowClass).find(fieldClass).val(transaction_number);
	$('#content').find(rowClass).find('.ap_transaction_header_id').first().val(ap_transaction_header_id);
	$('#content').find(rowClass).find('.invoice_amount').first().val(header_amount);
	$('#content').find(rowClass).find('.paid_amount').first().val(paid_amount);
 }
 localStorage.removeItem("row_class");
 localStorage.removeItem("row_class");
};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'ap_payment_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "ledger_id"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Ledger Id"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('1');
 }

//set the line price
 $('#content').on('change', '.amount, .invoice_amount', function() {
	var remaining_amount = (+$(this).closest('tr').find('.invoice_amount').val()) -
					((+$(this).closest('tr').find('.amount').val()) + (+$(this).closest('tr').find('.paid_amount').val()));
	$(this).closest('tr').find('.remaining_amount').val(remaining_amount);
	$(this).closest('tr').find('.remaining_amount').prop('readonly', true);
	$(this).closest('tr').find('.invoice_amount').prop('readonly', true);
	$(this).closest('tr').find('.paid_amount').prop('readonly', true);
 });
 
  $('#content').on('change', '.remaining_amount, .amount', function() {
	 var payment_type = $('#payment_type').val();
	 	 if($('#payment_type').val() === 'REFUND'){
		return;
	 }else if(+$(this).closest('tr').find('.remaining_amount').first().val() < 0){
	 alert('Negative value not allowed! for ' + payment_type + ' ' +  $(this).prop('class'));
	 $(this).val('');
	 $(this).closest('tr').find('.remaining_amount').first().val('');
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


 //selecting Header Id
 $(".ap_transaction_header_id.select_popup").on("click", function() {
	var link= 'select.php?class_name=ap_transaction_header' ;
	localStorage.setItem("reset_link_ofSelect", link);
	void window.open(link, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//selecting supplier
 $(".find_popup.supplierId").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=supplier', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//popu for selecting items
 $('#content').on('click', '.select_transaction_number.select_popup', function() {
	if($(this).closest('tr').find('.ap_payment_line_id').first().val()){
	 alert('You are not allowed to select a new transaction\nCancell or Viod the payment if required');
	 return;
	}
	var rowClass = $(this).closest('tr').prop('class');
	var fieldClass = $(this).closest('td').find('.select_transaction_number').prop('class');
	localStorage.setItem("row_class", rowClass);
	localStorage.setItem("field_class", fieldClass);
	var openUrl = 'select.php?class_name=ap_transaction_header&approval_status=APPROVED';
	openUrl += '&supplier_id=' + $('#supplier_id').val();
	localStorage.setItem("reset_link_ofSelect", openUrl);
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the ap_payment_header_id on refresh button click
 $('a.show.ap_payment_header_id').click(function() {
	var ap_payment_header_id = $('#ap_payment_header_id').val();
	$(this).attr('href', modepath() + 'ap_payment_header_id=' + ap_payment_header_id);

 });


 $('a.show.bu_org_id').click(function() {
	var bu_org_id = $('#bu_org_id').val();
	if (bu_org_id) {
	 $(this).attr('href', modepath() + 'bu_org_id=' + bu_org_id);
	}
 });

 $('a.show.supplier_site_id').click(function() {
	var supplier_id = $('#headerId').val();
	var supplier_site_id = $('#supplier_site_id').val();
	$(this).attr('href', '?supplier_id=' + supplier_id + '&supplier_site_id=' + supplier_site_id);
 });


 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'ap_payment_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 3;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
	$(".tabsDetail").tabs();
 });


//remove po lines
 $("#remove_row").click(function() {
	$('input[name="ap_payment_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'ap_payment_header_id';
 classContextMenu.docLineId = 'ap_payment_line_id';
 classContextMenu.btn1DivId = 'ap_payment_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'ap_payment_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 //classContextMenu.contextMenu();

// deleteData('json.po.php');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=ap_payment_header';
 classSave.form_header_id = 'ap_payment_header';
 classSave.primary_column_id = 'ap_payment_header_id';
 classSave.line_key_field = 'amount';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'ap_payment_header';
 classSave.lineClassName = 'ap_payment_line';
 classSave.enable_select = true;
 classSave.saveMain();


//all actions
//Popup for selecting match 
 function match_transaction() {
	var ap_payment_header_id = $("#ap_payment_header_id").val();
	if (ap_payment_header_id) {
	 var link = 'multi_select.php?class_name=po_all_v&action=match_transaction&mode=9&action_class_name=ap_payment_line&po_status=APPROVED&ap_payment_header_id=' + ap_payment_header_id;
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
	 localStorage.setItem("jsfile", "modules/ap/ap_payment/extra_ap_payment.js");
	 void window.open(link, '_blank',
					 'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	 return false;
	} else {
	 alert('No Transaction Header ID/nEnter or Save The Header Details ');
	}
 }

 function create_accounting() {
	var ap_payment_header_id = $("#ap_payment_header_id").val();
	if (ap_payment_header_id) {
	 var link = 'multi_select.php?class_name=ap_payment_header&action=create_accounting&mode=9&action_class_name=ap_payment_header&ap_payment_header_id=' + ap_payment_header_id;
	 localStorage.removeItem("reset_link");
	 localStorage.setItem("reset_link", link);
	 localStorage.removeItem("jsfile");
	 localStorage.setItem("jsfile", "modules/ap/ap_payment/extra_ap_payment.js");
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

function setValFromSelectPage(ar_receipt_header_id, ar_transaction_header_id, transaction_number,
				header_amount, ar_customer_id, customer_number, customer_name, receipt_amount) {
 this.ar_receipt_header_id = ar_receipt_header_id;
 this.ar_transaction_header_id = ar_transaction_header_id;
 this.header_amount = header_amount;
 this.receipt_amount = receipt_amount;
 this.transaction_number = transaction_number;
 this.ar_customer_id = ar_customer_id;
 this.customer_number = customer_number;
 this.customer_name = customer_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var ar_receipt_header_id = this.ar_receipt_header_id;
 var header_amount = this.header_amount;
 var receipt_amount = this.receipt_amount;
 var ar_customer_id = this.ar_customer_id;
 var customer_number = this.customer_number;
 var customer_name = this.customer_name;
 var ar_transaction_header_id = this.ar_transaction_header_id;
 var transaction_number = this.transaction_number;

 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (ar_receipt_header_id) {
	$("#ar_receipt_header_id").val(ar_receipt_header_id);
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
 if (ar_transaction_header_id) {
	$('#content').find(rowClass).find(fieldClass).val(transaction_number);
	$('#content').find(rowClass).find('.ar_transaction_header_id').first().val(ar_transaction_header_id);
	$('#content').find(rowClass).find('.invoice_amount').first().val(header_amount);
	$('#content').find(rowClass).find('.receipt_amount').first().val(receipt_amount);
 }
 localStorage.removeItem("row_class");
 localStorage.removeItem("row_class");
};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'ar_receipt_header_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "ledger_id"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Ledger Id"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('1');
 }

 //set the line price
 $('#content').validateAmount();
 $('#content').on('change', '.amount, .invoice_amount', function() {
	var remaining_amount = (+$(this).closest('tr').find('.invoice_amount').val()) -
					((+$(this).closest('tr').find('.amount').val()) + (+$(this).closest('tr').find('.receipt_amount').val()));
	$(this).closest('tr').find('.remaining_amount').val(remaining_amount);
	$(this).closest('tr').find('.remaining_amount').prop('readonly', true);
	$(this).closest('tr').find('.invoice_amount').prop('readonly', true);
	$(this).closest('tr').find('.receipt_amount').prop('readonly', true);
	var trClass = '.' + $(this).closest('tr').prop('class');
	if (remaining_amount < 0) {
	 alert('Entered amount is more than remaining amount' + '\n Re-enter the amount!');
	 $('#form_line').find(trClass).find('.remaining_amount').val('');
	 $('#form_line').find(trClass).find('.amount').val('');
	}
 });

//get ar_customer details
get_customer_detail_for_bu();


 $("#content").on("change", "#ar_customer_site_id", function() {
	var ar_customer_site_id = $("#ar_customer_site_id").val();
	if (ar_customer_site_id) {
	 getCustomerSiteDetails('modules/ar/customer/json_customer.php', ar_customer_site_id);
	}
 });


 //selecting Header Id
 $(".ar_receipt_header_id.select_popup").on("click", function() {
	var link = 'select.php?class_name=ar_receipt_header';
	void window.open(link, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

////selecting ar_customer
// $(".ar_customer_id.select_popup").on("click", function() {
//	localStorage.idValue = "";
//	void window.open('select.php?class_name=ar_customer', '_blank',
//					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });




 deleteData('form.php?class_name=ar_receipt_header&line_class_name=ar_receipt_line&detail_class_name=ar_receipt_detail');

//all actions
//Popup for selecting match 
 function create_accounting() {
	var ar_receipt_header_id = $("#ar_receipt_header_id").val();
	if (ar_receipt_header_id) {
	 var link = 'multi_select.php?class_name=ar_receipt_header&action=create_accounting&mode=9&action_class_name=ar_receipt_header&ar_receipt_header_id=' + ar_receipt_header_id;
	 localStorage.removeItem("reset_link");
	 localStorage.setItem("reset_link", link);
	 localStorage.removeItem("jsfile");
	 localStorage.setItem("jsfile", "modules/ar/receipt/extra_ar_receipt.js");
	 void window.open(link, '_blank',
					 'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	 return false;
	} else {
	 alert('No Transaction Header ID/nEnter or Save The Header Details ');
	}
 }

 $('#receipt_action').on('change', function() {
	var selected_value = $(this).val();
	switch (selected_value) {
	 case 'CREATE_ACCOUNT' :
		create_accounting();
		break;

	 case 'REVERSE' :
		if (confirm("Do you really want to reverse Receipt# ?\n" + $('#receipt_number').val())) {
		 $(".error").append('Reversing Receipt');
		 var headerData = $('#ar_receipt_header').serializeArray();
		 saveHeader('form.php?class_name=ar_receipt_header', headerData, '#ar_receipt_header_id', '', true, 'ar_receipt_header');
		$(".error").append('Reversing complete. Refresh the page to see the changes');
		}
		break;

	 default :
		break;
	}
 });

 $('#bu_org_id').on('change', function() {
	getBUDetails($(this).val());
	get_ar_receipt_source_details($(this).val());
 });
});
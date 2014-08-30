function setValFromSelectPage(mdm_bank_account_id, combination, ar_customer_id, customer_number, customer_name,
				supplier_id, supplier_number, supplier_name,
				mdm_bank_header_id, mdm_bank_site_id, bank_name, branch_name,account_number) {
 this.mdm_bank_account_id = mdm_bank_account_id;
 this.combination = combination;
 this.ar_customer_id = ar_customer_id;
 this.customer_number = customer_number;
 this.customer_name = customer_name;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.mdm_bank_header_id = mdm_bank_header_id;
 this.mdm_bank_site_id = mdm_bank_site_id;
 this.bank_name = bank_name;
 this.branch_name = branch_name;
 this.account_number = account_number;
}

setValFromSelectPage.prototype.setVal = function() {
 var mdm_bank_account_id = this.mdm_bank_account_id;
 var combination = this.combination;
 var ar_customer_id = this.ar_customer_id;
 var customer_number = this.customer_number;
 var customer_name = this.customer_name;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var branch_name = this.branch_name;
 var mdm_bank_header_id = this.mdm_bank_header_id;
 var mdm_bank_site_id = this.mdm_bank_site_id;
 var account_number = this.account_number;
 var bank_name = this.bank_name;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (mdm_bank_account_id) {
	$("#mdm_bank_account_id").val(mdm_bank_account_id);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
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
 if (supplier_id) {
	$("#supplier_id").val(supplier_id);
 }
 if (supplier_number) {
	$("#supplier_number").val(supplier_number);
 }
 if (supplier_name) {
	$("#supplier_name").val(supplier_name);
 }
  if (branch_name) {
	$("#branch_name").val(branch_name);
 }
 if (bank_name) {
	$("#bank_name").val(bank_name);
 }
 if (mdm_bank_site_id) {
	$("#mdm_bank_site_id").val(mdm_bank_site_id);
 }
 if (mdm_bank_header_id) {
	$("#mdm_bank_header_id").val(mdm_bank_header_id);
 }
  if (account_number) {
	$("#account_number").val(account_number);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".mdm_bank_account_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=mdm_bank_account', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".mdm_bank_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=mdm_bank_v', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 $(".mdm_bank_site_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=mdm_bank_v', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the mdm_bank_account_id on find button click
 $('a.show.mdm_bank_account_id').click(function() {
	var mdm_bank_account_id = $('#mdm_bank_account_id').val();
	$(this).attr('href', modepath() + 'mdm_bank_account_id=' + mdm_bank_account_id);
 });

 //popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
	var fieldClass = $(this).closest('li').find('.select_account').prop('class');
	localStorage.setItem("field_class", fieldClass);
	var openUrl = 'select.php?class_name=coa_combination';
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//get customer details
 get_customer_detail_for_bu(true);

 //get supplier details
 get_supplier_detail_for_bu(true);
});

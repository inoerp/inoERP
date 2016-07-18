function setValFromSelectPage(hr_payroll_payment_method_id, mdm_bank_account_id, combination, 
				mdm_bank_header_id, mdm_bank_site_id, bank_name, branch_name,account_number) {
 this.hr_payroll_payment_method_id = hr_payroll_payment_method_id;
  this.mdm_bank_account_id = mdm_bank_account_id;
 this.combination = combination;
 this.mdm_bank_header_id = mdm_bank_header_id;
 this.mdm_bank_site_id = mdm_bank_site_id;
 this.bank_name = bank_name;
 this.branch_name = branch_name;
 this.account_number = account_number;
}


setValFromSelectPage.prototype.setVal = function() {
 var hr_payroll_payment_method_id = this.hr_payroll_payment_method_id;
  var mdm_bank_account_id = this.mdm_bank_account_id;
 var combination = this.combination;
 var branch_name = this.branch_name;
 var mdm_bank_header_id = this.mdm_bank_header_id;
 var mdm_bank_site_id = this.mdm_bank_site_id;
 var account_number = this.account_number;
 var bank_name = this.bank_name;
 
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (hr_payroll_payment_method_id) {
  $("#hr_payroll_payment_method_id").val(hr_payroll_payment_method_id);
 }
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
  $('#content').find(fieldClass).val(combination);
  localStorage.removeItem("field_class");
 }
 
 if (mdm_bank_account_id) {
	$("#bank_account_id").val(mdm_bank_account_id);
 }
  if (branch_name) {
	$("#branch_name").val(branch_name);
 }
 if (bank_name) {
	$("#bank_name").val(bank_name);
 }
 if (mdm_bank_site_id) {
	$("#bank_site_id").val(mdm_bank_site_id);
 }
 if (mdm_bank_header_id) {
	$("#bank_header_id").val(mdm_bank_header_id);
 }
  if (account_number) {
	$("#account_number").val(account_number);
 }
 
};

$(document).ready(function() {
 //selecting Id
 $(".hr_payroll_payment_method_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=hr_payroll_payment_method', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".mdm_bank_account_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=mdm_bank_account', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

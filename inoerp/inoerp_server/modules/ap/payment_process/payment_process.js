function setValFromSelectPage(ap_payment_process_id, combination, mdm_bank_account_id, mdm_bank_header_id, mdm_bank_site_id,
				bank_name, branch_name, account_number) {
 this.ap_payment_process_id = ap_payment_process_id;
 this.combination = combination;
 this.mdm_bank_account_id = mdm_bank_account_id;
 this.mdm_bank_header_id = mdm_bank_header_id;
 this.mdm_bank_site_id = mdm_bank_site_id;
 this.bank_name = bank_name;
 this.branch_name = branch_name;
 this.account_number = account_number;
}


setValFromSelectPage.prototype.setVal = function() {
 var ap_payment_process_id = this.ap_payment_process_id;
 var mdm_bank_account_id = this.mdm_bank_account_id;
 var account_number = this.account_number;
 
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (ap_payment_process_id) {
	$("#ap_payment_process_id").val(ap_payment_process_id);
 }
  if (mdm_bank_account_id) {
	$("#bank_account_id").val(mdm_bank_account_id);
 }
  if (account_number) {
	$("#account_number").val(account_number);
 }
 
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
 //selecting Id
 $(".ap_payment_process_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=ap_payment_process', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


//
// //Get the ap_payment_process_id on find button click
// $('a.show.ap_payment_process_id').click(function() {
//	var ap_payment_process_id = $('#ap_payment_process_id').val();
//	$(this).attr('href', modepath() + 'ap_payment_process_id=' + ap_payment_process_id);
// });

});

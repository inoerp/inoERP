function setValFromSelectPage(ar_receipt_source_id, combination, mdm_bank_account_id, mdm_bank_header_id, mdm_bank_site_id,
				bank_name, branch_name, account_number) {
 this.ar_receipt_source_id = ar_receipt_source_id;
 this.combination = combination;
 this.mdm_bank_account_id = mdm_bank_account_id;
 this.mdm_bank_header_id = mdm_bank_header_id;
 this.mdm_bank_site_id = mdm_bank_site_id;
 this.bank_name = bank_name;
 this.branch_name = branch_name;
 this.account_number = account_number;
}


setValFromSelectPage.prototype.setVal = function() {
 var ar_receipt_source_id = this.ar_receipt_source_id;
 var mdm_bank_account_id = this.mdm_bank_account_id;
 var account_number = this.account_number;
 
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (ar_receipt_source_id) {
	$("#ar_receipt_source_id").val(ar_receipt_source_id);
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
 $(".ar_receipt_source_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=ar_receipt_source', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


//
// //Get the ar_receipt_source_id on find button click
// $('a.show.ar_receipt_source_id').click(function() {
//	var ar_receipt_source_id = $('#ar_receipt_source_id').val();
//	$(this).attr('href', modepath() + 'ar_receipt_source_id=' + ar_receipt_source_id);
// });

});

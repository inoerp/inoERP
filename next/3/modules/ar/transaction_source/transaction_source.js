function setValFromSelectPage(ar_transaction_source_id, combination) {
 this.ar_transaction_source_id = ar_transaction_source_id;
 this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var ar_transaction_source_id = this.ar_transaction_source_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (ar_transaction_source_id) {
	$("#ar_transaction_source_id").val(ar_transaction_source_id);
 }
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
//  if(this.ar_transaction_source_id){
//  $('a.show.ar_transaction_source_id').trigger('click');
// }
};

$(document).ready(function() {
 //selecting Id
 $(".ar_transaction_source_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=ar_transaction_source', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

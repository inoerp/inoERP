function setValFromSelectPage(transaction_type_id, combination) {
 this.transaction_type_id = transaction_type_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var transaction_type_id = this.transaction_type_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (transaction_type_id) {
	$("#transaction_type_id").val(transaction_type_id);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};


$(document).ready(function() {
 //selecting Id
 $(".transaction_type_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=transaction_type', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
});


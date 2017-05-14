function setValFromSelectPage(subinventory_id, combination) {
 this.subinventory_id = subinventory_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var subinventory_id = this.subinventory_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (subinventory_id) {
	$("#subinventory_id").val(subinventory_id);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};


$(document).ready(function() {
 //selecting Id
 $(".subinventory_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=subinventory', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});


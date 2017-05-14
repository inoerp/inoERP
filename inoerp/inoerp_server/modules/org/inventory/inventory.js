function setValFromSelectPage(inventory_id, combination) {
 this.inventory_id = inventory_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var inventory_id = this.inventory_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (inventory_id) {
	$("#inventory_id").val(inventory_id);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};


$(document).ready(function() {
 //selecting Id
 $(".inventory_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=inventory', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});


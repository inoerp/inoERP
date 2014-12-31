function setValFromSelectPage(locator_id, combination) {
 this.locator_id = locator_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var locator_id = this.locator_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (locator_id) {
	$("#locator_id").val(locator_id);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};


$(document).ready(function() {
 //selecting Id
 $(".locator_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=locator', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
});


function setValFromSelectPage(hr_approval_object_id, combination) {
 this.hr_approval_object_id = hr_approval_object_id;
 this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var hr_approval_object_id = this.hr_approval_object_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (hr_approval_object_id) {
	$("#hr_approval_object_id").val(hr_approval_object_id);
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
 $(".hr_approval_object_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_approval_object', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});
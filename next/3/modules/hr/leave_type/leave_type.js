function setValFromSelectPage(hr_leave_type_id, combination) {
 this.hr_leave_type_id = hr_leave_type_id;
 this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var hr_leave_type_id = this.hr_leave_type_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (hr_leave_type_id) {
	$("#hr_leave_type_id").val(hr_leave_type_id);
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
 $(".hr_leave_type_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_leave_type', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

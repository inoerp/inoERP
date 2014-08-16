function setValFromSelectPage(hr_employee_termination_id, combination) {
 this.hr_employee_termination_id = hr_employee_termination_id;
 this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var hr_employee_termination_id = this.hr_employee_termination_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (hr_employee_termination_id) {
	$("#hr_employee_termination_id").val(hr_employee_termination_id);
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
 $(".hr_employee_termination_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_employee_termination', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the hr_employee_termination_id on find button click
 $('a.show.hr_employee_termination_id').click(function() {
	var hr_employee_termination_id = $('#hr_employee_termination_id').val();
	$(this).attr('href', modepath() + 'hr_employee_termination_id=' + hr_employee_termination_id);
 });

});

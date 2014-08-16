function setValFromSelectPage(hr_employee_id, combination) {
 this.hr_employee_id = hr_employee_id;
 this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var hr_employee_id = this.hr_employee_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (hr_employee_id) {
	$("#hr_employee_id").val(hr_employee_id);
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
 $(".hr_employee_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_employee', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the hr_employee_id on find button click
 $('a.show.hr_employee_id').click(function() {
	var hr_employee_id = $('#hr_employee_id').val();
	$(this).attr('href', modepath() + 'hr_employee_id=' + hr_employee_id);
 });

$('.employee_education_values').on('change', 'input', function(){
  var trClass = '.' + $(this).closest('tr').attr('class');
$(this).closest('tbody').find(trClass).find('.education_line_id_cb').val('1');
});

$('.employee_experience_values').on('change', 'input', function(){
  var trClass = '.' + $(this).closest('tr').attr('class');
$(this).closest('tbody').find(trClass).find('.experience_line_id_cb').val('1');
});

//onClick_add_new_row('tr.employee_education_line0', 'tbody.employee_education_values', 2);

  $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function() {
//   onClick_add_new_row('tr.employee_experience_line0', 'tbody.employee_experience_values', 2);
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'employee_experience_line';
	addNewRow.tbodyClass = 'form_data_line_tbody2';
	addNewRow.noOfTabs = 2;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 $("#content tbody.form_data_line_tbody").on("click", ".add_row_img", function() {
//  onClick_add_new_row('tr.employee_education_line0', 'tbody.employee_education_values', 2);
	var addNewRow2 = new add_new_rowMain();
	addNewRow2.trClass = 'employee_education_line';
	addNewRow2.tbodyClass = 'form_data_line_tbody';
	addNewRow2.noOfTabs = 2;
	addNewRow2.removeDefault = true;
	addNewRow2.add_new_row();
 });
});

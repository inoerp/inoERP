function setValFromSelectPage(hr_employee_id, combination, first_name, last_name, identification_id) {
 this.hr_employee_id = hr_employee_id;
 this.combination = combination;
 this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
}


setValFromSelectPage.prototype.setVal = function() {
 var hr_employee_id = this.hr_employee_id;
 var name = this.first_name + ' ' + this.last_name;
 var identification_id = this.identification_id;
 var user_type = localStorage.getItem("user_type");
 if (hr_employee_id) {
  if (user_type === 'supervisor') {
   $("#supervisor_employee_id").val(hr_employee_id);
   $("#supervisor_employee_name").val(name);
   
  } else {
   $("#hr_employee_id").val(hr_employee_id);
   $("#identification_id").val(identification_id);
   $("#first_name").val( this.first_name);
   $("#last_name").val(this.last_name);
  }
 }
 localStorage.removeItem("user_type");
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
  localStorage.setItem('user_type', 'employee');
  void window.open('select.php?class_name=hr_employee', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".supervisor_employee_id.select_popup").on("click", function() {
  localStorage.setItem('user_type', 'supervisor');
  void window.open('select.php?class_name=hr_employee', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

// //Get the hr_employee_id on find button click
// $('a.show.hr_employee_id').click(function() {
//  var hr_employee_id = $('#hr_employee_id').val();
//  $(this).attr('href', modepath() + 'hr_employee_id=' + hr_employee_id);
// });

 $('.employee_education_values').on('change', 'input', function() {
  var trClass = '.' + $(this).closest('tr').attr('class');
  $(this).closest('tbody').find(trClass).find('.education_line_id_cb').val('1');
 });

 $('.employee_experience_values').on('change', 'input', function() {
  var trClass = '.' + $(this).closest('tr').attr('class');
  $(this).closest('tbody').find(trClass).find('.experience_line_id_cb').val('1');
 });

//onClick_add_new_row('tr.employee_education_line0', 'tbody.employee_education_values', 2);

 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img1", function() {
//   onClick_add_new_row('tr.employee_experience_line0', 'tbody.employee_experience_values', 2);
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'employee_experience_line';
  addNewRow.tbodyClass = 'form_data_line_tbody2';
  addNewRow.noOfTabs = 2;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

 $("#content tbody.form_data_line_tbody").on("click", ".add_row_img1", function() {
//  onClick_add_new_row('tr.employee_education_line0', 'tbody.employee_education_values', 2);
  var addNewRow2 = new add_new_rowMain();
  addNewRow2.trClass = 'employee_education_line';
  addNewRow2.tbodyClass = 'form_data_line_tbody';
  addNewRow2.noOfTabs = 2;
  addNewRow2.removeDefault = true;
  addNewRow2.add_new_row();
 });
});

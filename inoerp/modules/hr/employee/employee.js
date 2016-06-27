
$(document).ready(function () {
 $('.employee_education_values').on('change', 'input', function () {
  var trClass = '.' + $(this).closest('tr').attr('class');
  $(this).closest('tbody').find(trClass).find('.education_line_id_cb').val('1');
 });

 $('.employee_experience_values').on('change', 'input', function () {
  var trClass = '.' + $(this).closest('tr').attr('class');
  $(this).closest('tbody').find(trClass).find('.experience_line_id_cb').val('1');
 });

//onClick_add_new_row('tr.employee_education_line0', 'tbody.employee_education_values', 2);

 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img1", function () {
//   onClick_add_new_row('tr.employee_experience_line0', 'tbody.employee_experience_values', 2);
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'employee_experience_line';
  addNewRow.tbodyClass = 'form_data_line_tbody2';
  addNewRow.noOfTabs = 2;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

 $("#content tbody.form_data_line_tbody").on("click", ".add_row_img1", function () {
//  onClick_add_new_row('tr.employee_education_line0', 'tbody.employee_education_values', 2);
  var addNewRow2 = new add_new_rowMain();
  addNewRow2.trClass = 'employee_education_line';
  addNewRow2.tbodyClass = 'form_data_line_tbody';
  addNewRow2.noOfTabs = 2;
  addNewRow2.removeDefault = true;
  addNewRow2.add_new_row();
 });

 $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('.hr_employee_education_id,.hr_employee_experience_id,.employee_id').val('');
  });
});

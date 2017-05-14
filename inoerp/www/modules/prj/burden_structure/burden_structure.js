$(document).ready(function () {
 //add new lines
 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'prj_burden_struct_exptype';
  addNewRow.tbodyClass = 'form_data_line_tbody2';
  addNewRow.noOfTabs = 1;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

$('body').on('change', '#labor_expendituretype_type', function(){
  if($(this).val() === 'SCHEDULE'){
  $('#l_revenue_burden_id, #l_invoice_burdern_id').prop('disabled','disabled');
  $('#employee_schedule_id, #job_schedule_id').removeAttr('disabled');
  }else{
    $('#l_revenue_burden_id, #l_invoice_burdern_id').removeAttr('disabled');
  $('#employee_schedule_id, #job_schedule_id').prop('disabled','disabled');
  }
});

});
function beforeContextMenu() {
 $('.line_status').val('');
 $('.picked_quantity').val('');
 $('.shipped_quantity').val('');
 $('.schedule_ship_date').val('');
 $('#so_number').val('');
 return true;
}

$(document).ready(function () {
 //add new lines
 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'pm_batch_ingredient';
  addNewRow.tbodyClass = 'form_data_line_tbody2';
  addNewRow.noOfTabs = 1;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

 //add new lines
 $("#content tbody.form_data_line_tbody3").on("click", ".add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'pm_batch_byproduct';
  addNewRow.tbodyClass = 'form_data_line_tbody3';
  addNewRow.noOfTabs = 1;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 $('#pm_batch_line, #pm_batch_ingredient, #pm_batch_byproduct').on('click', ':input', function () {
  if (!$('#pm_batch_header_id').val()) {
   alert('No header details in database : Enter/Save header data');
  }
 });

 $('body').off('change', '#action').on('change', '#action', function () {
  if ($(this).val() == 'PROCESS_ACTUALS') {
   $('#add_to_order').prop('disabled', false);
  } else {
   $('#add_to_order').prop('disabled', true);
  }
 });



});
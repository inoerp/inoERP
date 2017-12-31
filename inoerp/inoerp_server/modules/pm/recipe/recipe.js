$(document).ready(function () {
 //add new lines
 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'pm_recipe_customer';
  addNewRow.tbodyClass = 'form_data_line_tbody2';
  addNewRow.noOfTabs = 1;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });


//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }
 

});
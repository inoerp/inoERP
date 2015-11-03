$(document).ready(function () {
 //add new lines
 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'qa_collection_element_action';
  addNewRow.tbodyClass = 'form_data_line_tbody2';
  addNewRow.noOfTabs = 1;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

 });
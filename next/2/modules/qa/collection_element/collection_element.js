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


$('#form_line2').off('change', '.comparison').on('change', '.comparison', function(){
var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g,'.');
  switch($(this).val()){
    case 'VALUE':
      $(trClass).find('.value_from, .value_to').removeAttr('readonly').removeClass('readonly');
      $(trClass).find('.spec_value').prop('readonly', true).addClass('readonly');
      break;
      
    case 'SPEC_LIMIT':
      $(trClass).find('.spec_value').removeAttr('readonly').removeClass('readonly');
      $(trClass).find('.value_from, .value_to').prop('readonly', true).addClass('readonly');
      break;  
  
    default : 
      $(trClass).find('.value_from, .value_to, .spec_value').prop('readonly', true).addClass('readonly');
      break;
  }
  

});

 });
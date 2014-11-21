function setValFromSelectPage(hr_element_entry_tpl_header_id) {
 this.hr_element_entry_tpl_header_id = hr_element_entry_tpl_header_id;
}

setValFromSelectPage.prototype.setVal = function () {
 if (this.hr_element_entry_tpl_header_id) {
  $("#hr_element_entry_tpl_header_id").val(this.hr_element_entry_tpl_header_id);
 }
};

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.tpl_header_id = 'hr_element_entry_tpl_header_id';
// mandatoryCheck.mandatorytpl_header();
 mandatoryCheck.form_area = 'form_tpl_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

 //setting the first tpl_line number
 if (!($('.tpl_lines_number:first').val())) {
  $('.tpl_lines_number:first').val('10');
 }


 //selecting Id
 //Popup for selecting bom
 $(".hr_element_entry_tpl_header_id.select_popup").click(function () {
  void window.open('select.php?class_name=hr_element_entry_tpl_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

  //Get the po header id on refresh button click
 $('a.show.hr_element_entry_tpl_header_id').click(function(e) {
  var header_id = $('#hr_element_entry_tpl_header_id').val();
  $(this).attr('href', modepath() + 'hr_element_entry_tpl_header_id=' + header_id);

 });

 //add a new row
// onClick_add_new_row('tr.hr_element_entry_tpl_line0', 'tbody.form_data_tpl_line_tbody', 3);
 $("#content").on("click", ".add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'hr_element_entry_tpl_line';
  addNewRow.tbodyClass = 'form_data_line_tbody';
  addNewRow.noOfTabs = 1;
  addNewRow.tpl_lineNumberIncrementValue = 10;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

//get the attachement form
 deleteData('form.php?class_name=hr_element_entry_tpl_header&tpl_line_class_name=hr_element_entry_tpl_line');


});

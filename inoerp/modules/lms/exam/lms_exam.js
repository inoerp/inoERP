function setValFromSelectPage(hr_element_entry_tpl_header_id) {
 this.hr_element_entry_tpl_header_id = hr_element_entry_tpl_header_id;
}

setValFromSelectPage.prototype.setVal = function () {
 if (this.hr_element_entry_tpl_header_id) {
  $("#hr_element_entry_tpl_header_id").val(this.hr_element_entry_tpl_header_id);
 }
};

$(document).ready(function () {
 
   var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'hr_element_entry_tpl_header_id';
 mandatoryCheck.mandatoryHeader();
 
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

//get the attachement form
 deleteData('form.php?class_name=hr_element_entry_tpl_header&tpl_line_class_name=hr_element_entry_tpl_line');

});

function setValFromSelectPage(hr_element_entry_tpl_header_id) {
 this.hr_element_entry_tpl_header_id = hr_element_entry_tpl_header_id;
}

setValFromSelectPage.prototype.setVal = function () {
 if (this.hr_element_entry_tpl_header_id) {
  $("#hr_element_entry_tpl_header_id").val(this.hr_element_entry_tpl_header_id);
 }
};

$(document).ready(function () {
 
 //Popup for selecting bom
 $(".hr_element_entry_tpl_header_id.select_popup").click(function () {
  void window.open('select.php?class_name=hr_element_entry_tpl_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });


});
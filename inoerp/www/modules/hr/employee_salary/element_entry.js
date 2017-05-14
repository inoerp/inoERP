function setValFromSelectPage(hr_element_entry_header_id, hr_employee_id, first_name, last_name, identification_id) {
 this.hr_element_entry_header_id = hr_element_entry_header_id;
 this.hr_empoyee_id = hr_employee_id;
 this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var hr_element_entry_header_id = this.hr_element_entry_header_id;
 var name = this.first_name + ' ' + this.last_name;
 var identification_id = this.identification_id;
 $("#hr_element_entry_header_id").val(hr_element_entry_header_id);
 var hr_employee_id = this.hr_employee_id;
 
 if (hr_employee_id) {
  $("#employee_id").val(hr_employee_id);
 }
  if (name) {
  $("#employee_name").val(name);
 }
  if (identification_id) {
  $("#identification_id").val(identification_id);
 }
};

$(document).ready(function() {
 //selecting Id
 $(".hr_employee_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=hr_employee', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Popup for selecting bom
 $(".hr_element_entry_header_id.select_popup").click(function() {
  void window.open('select.php?class_name=hr_element_entry_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });


});

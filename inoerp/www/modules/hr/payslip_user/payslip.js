function setValFromSelectPage(hr_payslip_header_id, hr_employee_id, first_name, last_name, identification_id) {
 this.hr_payslip_header_id = hr_payslip_header_id;
 this.hr_empoyee_id = hr_employee_id;
 this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var hr_payslip_header_id = this.hr_payslip_header_id;
 var name = this.first_name + ' ' + this.last_name;
 var identification_id = this.identification_id;
 $("#hr_payslip_header_id").val(hr_payslip_header_id);
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
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'hr_payslip_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

 //setting the first line number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('10');
 }


 //selecting Id
 $(".hr_employee_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=hr_employee', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Popup for selecting bom
 $(".hr_payslip_header_id.select_popup").click(function() {
  void window.open('select.php?class_name=hr_payslip_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 

  //Get the bom_id on find button click
 $('a.show.period_name_id').click(function() {
  var headerId = $('#employee_id').val();
  $(this).attr('href', modepath() + 'employee_id=' + headerId + '&period_name_id=' + $('#period_name_id').val());
 });
 
   //Get the bom_id on find button click
 $('a.show.hr_payslip_header_id').click(function() {
  var headerId = $('#hr_payslip_header_id').val();
  $(this).attr('href', modepath() + 'hr_payslip_header_id=' + headerId);
 });

 //add a new row

 onClick_add_new_row('payslip_line_line0','form_data_line_tbody',1);


});
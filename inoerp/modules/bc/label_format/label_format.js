function setValFromSelectPage(bc_label_format_header_id, hr_employee_id, first_name, last_name, identification_id) {
 this.bc_label_format_header_id = bc_label_format_header_id;
 this.hr_empoyee_id = hr_employee_id;
 this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bc_label_format_header_id = this.bc_label_format_header_id;
 var name = this.first_name + ' ' + this.last_name;
 var identification_id = this.identification_id;
 $("#bc_label_format_header_id").val(bc_label_format_header_id);
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
 mandatoryCheck.header_id = 'bc_label_format_header_id';
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
 $(".bc_label_format_header_id.select_popup").click(function() {
  void window.open('select.php?class_name=bc_label_format_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

 //Get the bom_id on find button click
 $('#form_header a.show.bc_label_format_header_id').click(function() {
  var headerId = $('#bc_label_format_header_id').val();
  $(this).attr('href', modepath() + 'bc_label_format_header_id=' + headerId);
 });
 
  //Get the bom_id on find button click
 $('#form_header a.show.hr_employee_id').click(function() {
  var headerId = $('#hr_employee_id').val();
  $(this).attr('href', modepath() + 'hr_employee_id=' + headerId);
 });

 //add a new row
 onClick_add_new_row('tr.bc_label_format_line0', 'tbody.form_data_line_tbody', 2);
// $("#content").on("click", ".add_row_img", function() {
//  var addNewRow = new add_new_rowMain();
//  addNewRow.trClass = 'bc_label_format_line';
//  addNewRow.tbodyClass = 'form_data_line_tbody';
//  addNewRow.noOfTabs = 2;
//  addNewRow.removeDefault = true;
//  addNewRow.add_new_row();
// });

//get the attachement form
 deleteData('form.php?class_name=bc_label_format_header&line_class_name=bc_label_format_line');

 $("#content").on("blur", '.field_name', function() {
  if ($(this).val() === 'newentry') {
   if (confirm("Do you want to create a field not part of item master ?")) {
    $(this).replaceWith('<input class="textfield field_name" type="text" size="25" maxlength="50" name="field_name[]">');
   }
  }
 });
});

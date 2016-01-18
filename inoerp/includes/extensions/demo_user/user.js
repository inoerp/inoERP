function setValFromSelectPage(user_id, address_id, hr_employee_id, first_name, last_name, identification_id) {
 this.user_id = user_id;
 this.address_id = address_id;
  this.hr_empoyee_id = hr_employee_id;
 this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var user_id = this.user_id;
 var address_id = this.address_id;
 if (user_id) {
	$("#user_id").val(user_id);
 }
  if (address_id) {
	$("#address_id").val(address_id);
 }

 var name = this.first_name + ' ' + this.last_name;
 var identification_id = this.identification_id;
 var hr_employee_id = this.hr_employee_id;

 if (hr_employee_id) {
  $("#hr_employee_id").val(hr_employee_id);
 }
  if (name) {
  $("#employee_name").val(name);
 }
  if (identification_id) {
  $("#identification_id").val(identification_id);
 }
 
  if (user_id) {
	$('a.show.user_id').trigger('click');
 }
};

$(document).ready(function() {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'user_id';
 mandatoryCheck.mandatoryHeader();
// mandatoryCheck.form_area = 'form_header';
// mandatoryCheck.mandatory_fields = ["username", "username"];
// mandatoryCheck.mandatory_messages = ["First Enter User Name", "No Password"];
//// mandatoryCheck.mandatoryField();

 //selecting Id
 $(".hr_employee_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=hr_employee', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
 $('#erp_form_area .header_field').find('input[type="password"]').val('');
 
 //Popup for selecting user
 $(".user_id.select_popup").click(function() {
		var link = 'select.php?class_name=user';
	void window.open(link, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

$("#enteredRePassword").on('focusout', function() {
var enteredPassword = $("#enteredPassword").val();
if ($(this).val() !== enteredPassword)
{
$(this).val('');
   $("#enteredPassword").val('');
   $("#enteredPassword").focus();
alert('Two different passwords entered.\nRe-enter passwords');
}
});

  $("#content tbody.form_data_line_tbody2").off("click", ".add_row_img").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'user_group';
	addNewRow.tbodyClass = 'form_data_line_tbody2';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });


});


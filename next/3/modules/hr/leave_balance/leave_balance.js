function setValFromSelectPage(hr_employee_id,first_name, last_name, identification_id) {
 this.hr_employee_id = hr_employee_id;
  this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
 }


setValFromSelectPage.prototype.setVal = function() {
 var hr_employee_id = this.hr_employee_id;
  var name = this.first_name + ' ' + this.last_name;
 var identification_id = this.identification_id;


   if (name) {
  $("#employee_name").val(name);
 }
  if (identification_id) {
  $("#identification_id").val(identification_id);
 }
 
  if (hr_employee_id) {
	$("#employee_id").val(hr_employee_id);
  $('a.show.employee_id').trigger('click');
 }
};

$(document).ready(function() {
// var Mandatory_Fields = ["#org_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').on('focusout', '.year', function() {
	var name = '';
	name += $(this).closest('tr').find('.name_prefix').val();
	name += '-' + $(this).val();
	$(this).closest('tr').find('.name').val(name);
 });
 
  $(".employee_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_employee', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});  
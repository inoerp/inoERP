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
// var Mandatory_Fields = ["#org_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').on('focusout', '.year', function() {
	var name = '';
	name += $(this).closest('tr').find('.name_prefix').val();
	name += '-' + $(this).val();
	$(this).closest('tr').find('.name').val(name);
 });
 
  $(".hr_employee_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_employee', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


//Get the leave_balance_id on find button click
 $('a.show.hr_leave_balance').click(function() {
	var headerId = $('#employee_id').val();
	$(this).prop('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class_name=hr_leave_balance&employee_id=' + headerId);
 });

 onClick_add_new_row('tr.leave_balance_line0', 'tbody.leave_balance_values', 1);
// deleteData('json_leave_balance.php');
deleteData('form.php?class_name=hr_leave_balance&line_class_name=hr_leave_balance');

 //context menu
 var classContextMenu = new contextMenuMain();
  classContextMenu.docLineId = 'hr_leave_balance_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'leave_balance_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
// classContextMenu.contextMenu();
 
 var leave_balanceSave = new saveMainClass();
 leave_balanceSave.json_url = 'form.php?class_name=hr_leave_balance';
 leave_balanceSave.single_line = false;
 leave_balanceSave.line_key_field = 'leave_balance';
 leave_balanceSave.form_line_id = 'hr_leave_balance';
 leave_balanceSave.saveMain();

});  
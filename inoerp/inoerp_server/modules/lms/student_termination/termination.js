function setValFromSelectPage(hr_employee_id, hr_employee_termination_id, first_name, last_name, identification_id) {
 this.hr_employee_id = hr_employee_id;
 this.hr_employee_termination_id = hr_employee_termination_id;
 this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
}


setValFromSelectPage.prototype.setVal = function () {
 var name = this.first_name + ' ' + this.last_name;
 if (this.hr_employee_id) {
  $("#employee_id").val(this.hr_employee_id);
  $("#employee_name").val(name);
  $("#identification_id").val(this.identification_id);
 }

 if (this.hr_employee_termination_id) {
  $("#hr_employee_termination_id").val(this.hr_employee_termination_id);
 }
};

$(document).ready(function () {
 //selecting Id
 $(".hr_employee_termination_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=hr_employee_termination', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".hr_employee_id.select_popup").on("click", function () {
  localStorage.setItem('user_type', 'employee');
  void window.open('select.php?class_name=hr_employee', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the hr_employee_termination_id on find button click
// $('a.show.hr_employee_termination_id').click(function() {
//	var hr_employee_termination_id = $('#hr_employee_termination_id').val();
//	$(this).attr('href', modepath() + 'hr_employee_termination_id=' + hr_employee_termination_id);
// });

});

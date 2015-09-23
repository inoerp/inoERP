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
 //setting the first line number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('10');
 }

$("#content").on('change', '.object_name', function() {
  var tableName = $(this).val();
  var parentClass = $(this).closest('tr').attr("class");
   getFieldNames({
    tableName : tableName,
    parentClass :parentClass,
     fieldClass : 'sys_field_name'
   } );
 });


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

 
 $("#content").on("blur", '.field_name', function() {
  if ($(this).val() === 'newentry') {
   if (confirm("Do you want to create a field not part of item master ?")) {
    $(this).replaceWith('<input class="textfield field_name" type="text" size="25" maxlength="50" name="field_name[]">');
   }
  }
 });
 
 
});

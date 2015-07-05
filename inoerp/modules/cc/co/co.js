function setValFromSelectPage(cc_co_header_id, hr_employee_id, first_name, last_name, identification_id) {
 this.cc_co_header_id = cc_co_header_id;
 this.hr_empoyee_id = hr_employee_id;
 this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var cc_co_header_id = this.cc_co_header_id;
 var name = this.first_name + ' ' + this.last_name;
 var identification_id = this.identification_id;
 $("#cc_co_header_id").val(cc_co_header_id);
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

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'cc_co_header_id';
 mandatoryCheck.mandatoryHeader();

 //setting the first line number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('10');
 }

 $('.select_item_number_all_fm2').inoAutoCompleteElement({
  json_url: 'modules/inv/item/json_item.php',
  primary_column1: 'org_id',
  form_id : 'form_line2'
 });


 //selecting Id
 $(".hr_employee_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=hr_employee', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Popup for selecting bom
 $(".cc_co_header_id.select_popup").click(function () {
  void window.open('select.php?class_name=cc_co_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

  $('#template_id').on('change', function () {
  if ($('#cc_co_header_id').val()) {
   alert('You can\'t chage the template for this change order.');
   $(this).attr('disabled', true);
  } else if ($(this).val()) {
   var templateId = $('#template_id').val();
   window.location = modepath() + 'template_id=' + templateId;
  }
 });




});

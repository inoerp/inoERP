function setValFromSelectPage(hr_team_header_id, hr_employee_id, first_name, last_name, identification_id) {
 this.hr_team_header_id = hr_team_header_id;
 this.hr_empoyee_id = hr_employee_id;
 this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var hr_team_header_id = this.hr_team_header_id;
 var name = this.first_name + ' ' + this.last_name;
 if (localStorage.getItem("row_class") && localStorage.getItem("row_class") !== 'null') {
  var rowClass = '.' + localStorage.getItem("row_class");
  rowClass = rowClass.replace(/\s+/g, '.');
 }

if(this.hr_team_header_id){
 $("#hr_team_header_id").val(hr_team_header_id);
}

 if (rowClass) {
  if (this.hr_employee_id) {
   $('#content').find(rowClass).find('.member_employee_id').val(this.hr_employee_id);
  }
  if (name) {
   $('#content').find(rowClass).find('.member_employee_name').val(name);
  }
 } else {
   if (this.hr_employee_id) {
   $("#team_lead_employee_id").val(this.hr_employee_id);
  }
  if (name) {
   $("#lead_employee_name").val(name);
  }
 }


 localStorage.removeItem("row_class");
};

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'hr_team_header_id';
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
// $(".hr_employee_id.select_popup").on("click", function() {
//  void window.open('select.php?class_name=hr_employee', '_blank',
//   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });


 //Popup for selecting bom
 $(".hr_team_header_id.select_popup").click(function () {
  void window.open('select.php?class_name=hr_team_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

 //Get the bom_id on find button click
 $('#form_header a.show.hr_team_header_id').click(function () {
  var headerId = $('#hr_team_header_id').val();
  $(this).attr('href', modepath() + 'hr_team_header_id=' + headerId);
 });

 //Get the bom_id on find button click
 $('#form_header a.show.hr_employee_id').click(function () {
  var headerId = $('#hr_employee_id').val();
  $(this).attr('href', modepath() + 'hr_employee_id=' + headerId);
 });

 //add a new row
// onClick_add_new_row('tr.hr_team_line0', 'tbody.form_data_line_tbody', 3);
 $("#content").on("click", ".add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'hr_team_line';
  addNewRow.tbodyClass = 'form_data_line_tbody';
  addNewRow.noOfTabs = 1;
  addNewRow.lineNumberIncrementValue = 10;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

//get the attachement form
 deleteData('form.php?class_name=hr_team_header&line_class_name=hr_team_line');


});



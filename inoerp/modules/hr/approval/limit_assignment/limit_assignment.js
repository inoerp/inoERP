function setValFromSelectPage(combination) {
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function () {
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
  $('#content').find(fieldClass).val(combination);
  localStorage.removeItem("field_class");
 }
};

//function getFormDetails_ala() {
// var position_id_v = $('#position_id').val();
// var job_id_v = $('#job_id').val();
// var bu_org_id_v = $('#bu_org_id').val();
// e.preventDefault();
// var urlLink = $(this).attr('href');
// var urlLink_a = urlLink.split('?');
// var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&position_id=' + position_id_v + '&job_id=' + job_id_v + '&bu_org_id=' + bu_org_id_v;
// getFormDetails(formUrl);
// $('body').off('click', 'a.hr_approval_limit_assignment_id', getFormDetails_ala);
//}
//
//
//$('body').on('click', 'a.hr_approval_limit_assignment_id', getFormDetails_ala).one();

$(document).ready(function () {
// var Mandatory_Fields = ["#employee_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').on('focusout', '.year', function () {
  var name = '';
  name += $(this).closest('tr').find('.name_prefix').val();
  name += '-' + $(this).val();
  $(this).closest('tr').find('.name').val(name);
 });

//Get the approval_limit_assignment_id on find button click
 $('a.show.hr_approval_limit_assignment').click(function () {
  var link = 'pageno=1&per_page=10&submit_search=Search&search_class_name=hr_approval_limit_assignment';
  if ($('#bu_org_id').val()) {
   link += '&bu_org_id=' + $('#bu_org_id').val();
  }
  if ($('#position_id').val()) {
   link += '&position_id=' + $('#position_id').val();
  } else {
   if ($('#job_id').val()) {
    link += '&job_id=' + $('#job_id').val();
   }
  }
  $(this).prop('href', modepath() + link);
 });


// onClick_add_new_row('tr.approval_limit_assignment_line0', 'tbody.approval_limit_assignment_values', 2);

//context menu
// var classContextMenu = new contextMenuMain();
// classContextMenu.docLineId = 'hr_approval_limit_assignment_id';
// classContextMenu.btn2DivId = 'form_line';
// classContextMenu.trClass = 'approval_limit_assignment_line';
// classContextMenu.tbodyClass = 'form_data_line_tbody';
// classContextMenu.noOfTabbs = 2;
//// classContextMenu.contextMenu();
//
// var approval_limit_assignmentSave = new saveMainClass();
// approval_limit_assignmentSave.json_url = 'form.php?class_name=hr_approval_limit_assignment';
// approval_limit_assignmentSave.single_line = false;
// approval_limit_assignmentSave.line_key_field = 'hr_approval_limit_header_id';
// approval_limit_assignmentSave.form_line_id = 'hr_approval_limit_assignment';
// approval_limit_assignmentSave.saveMain();

});  
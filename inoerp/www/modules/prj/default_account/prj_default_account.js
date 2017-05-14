
$(document).ready(function () {
//Get the approval_limit_assignment_id on find button click
 $('body').off('click', 'a.show2.prj_default_account_id').on('click', 'a.show2.prj_default_account_id', function (e) {
  e.preventDefault();
  var link = $(this).prop('href');
  if ($('#prj_project_type_header_id').val()) {
   link += '&prj_project_type_header_id=' + $('#prj_project_type_header_id').val();
  }
  if ($('#accounting_group').val()) {
   link += '&accounting_group=' + $('#accounting_group').val();
  }
  $(this).prop('href', modepath() + link);
  getFormDetails(link);
 });

});  
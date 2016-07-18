function endeField_asPerResourceType(resourceType, trClass) {
 $('#prj_resource_list_line').find('tr' + trClass).find('td .resource_type_control').prop('disabled', false).removeAttr('readonly');
 switch (resourceType) {
  case 'HR_EMPLOYEE':
   $('#prj_resource_list_line').find('tr' + trClass).find('td .resource_type_control').not('.employee').prop('readonly', 'readonly').prop('disabled', true);
   break;

  case 'ORG':
   $('#prj_resource_list_line').find('tr' + trClass).find('td .resource_type_control').not('.bu_org_id').prop('readonly', 'readonly').prop('disabled', true);
   break;

  case 'HR_JOB':
   $('#prj_resource_list_line').find('tr' + trClass).find('td .resource_type_control').not('.job_id').prop('readonly', 'readonly').prop('disabled', true);
   break;

  case 'PRJ_EXPENDITURE_TYPE':
   $('#prj_resource_list_line').find('tr' + trClass).find('td .resource_type_control').not('.prj_expenditure_type_header_id').prop('readonly', 'readonly').prop('disabled', true);
   break;

  case 'REVENUE_CATEGORY':
   $('#prj_resource_list_line').find('tr' + trClass).find('td .resource_type_control').not('.revenue_category').prop('readonly', 'readonly').prop('disabled', true);
   break;

  case 'EXPENDITURE_CATEGORY':
   $('#prj_resource_list_line').find('tr' + trClass).find('td .resource_type_control').not('.expenditure_category').prop('readonly', 'readonly').prop('disabled', true);
   break;


  default:

   break;

 }
}

function prj_budget_enableDisbale_fields(type) {
 if (type === 'C') {
  $('.revenue_quantity,.revenue_amount').addClass('always_readonly').val('');
  $('.quantity,.raw_cost,.burden_cost').removeClass('always_readonly').removeAttr('readonly');
 } else if (type === 'R') {
  $('.quantity,.raw_cost,.burden_cost').addClass('always_readonly').val('');
  $('.revenue_quantity,.revenue_amount').removeClass('always_readonly').removeAttr('readonly');
 }
}

$(document).ready(function () {
 $('body').off('change', '.resource_type').on('change', '.resource_type', function () {
  var trClass = '.' + $(this).closest('tr').prop('class').replace(/\s+/g, '.');
  endeField_asPerResourceType($(this).val(), trClass);
 });

 $('#tabsLine-1 tbody').find('tr').each(function () {
  var trClass = '.' + $(this).prop('class').replace(/\s+/g, '.');
  endeField_asPerResourceType($(this).find('.resource_type').val(), trClass);
 });

 $('body').off('change', '#project_number').on('change', '#project_number', function () {
  $('#form_line').find('.prj_project_header_id').val($('#prj_project_header_id').val());
 });


 $('body').off('change', '#budget_type').on('change', '#budget_type', function () {
  var type = $(this).find('option:selected').data('mapper1');
  prj_budget_enableDisbale_fields(type);
 });

 var type_ori = $('#budget_type').find('option:selected').data('mapper1');
 prj_budget_enableDisbale_fields(type_ori);

});
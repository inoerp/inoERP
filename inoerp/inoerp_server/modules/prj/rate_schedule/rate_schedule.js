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
   $('#prj_resource_list_line').find('tr' + trClass).find('td .resource_type_control').not('.prj_expenditure_type_id').prop('readonly', 'readonly').prop('disabled', true);
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

$(document).ready(function () {
 $('body').off('change', '.resource_type').on('change', '.resource_type', function () {
  var trClass = '.' + $(this).closest('tr').prop('class').replace(/\s+/g, '.');
  endeField_asPerResourceType($(this).val(), trClass);
 });

 $('#tabsLine-1 tbody').find('tr').each(function () {
  var trClass = '.' + $(this).prop('class').replace(/\s+/g, '.');
  endeField_asPerResourceType($(this).find('.resource_type').val(), trClass);
 });
 
 $('body').off('change' , '.prj_expenditure_type_header_id') .on('change' , '.prj_expenditure_type_header_id' , function(){
  var uom = $(this).find('option:selected').data('uom_id');
  var trClass = '.' + $(this).closest('tr').attr('class').replace('/\s+/g','.');
  $(trClass).find('.uom_id').val(uom);
 });
});
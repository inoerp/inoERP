$(document).ready(function () {

 $('body').off('click', 'a.pm_resource_transaction_id').on('click', 'a.pm_resource_transaction_id', function (e) {
  e.preventDefault();
  var transaction_type = $('#transaction_type').val();
  var pm_batch_header_id = $('#pm_batch_header_id').val();
  var org_id = $('#org_id').val();
  var batch_name = $('#batch_name').val();
  var link = '&transaction_type=' + transaction_type;
  if (pm_batch_header_id) {
   link += '&pm_batch_header_id=' + pm_batch_header_id;
  } else if (batch_name) {
   link += '&batch_name=' + batch_name;
  }
  link += '&org_id=' + org_id;
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + link;
  getFormDetails(formUrl);
 }).one();


 $('body').off('blur', '.bom_sequence').on('blur', '.bom_sequence', function () {
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  if ($(this).find('option:selected').val() == 'undefined' || $(this).find('option:selected').val() == "") {
   $(trClass).find('.pm_batch_operation_detail_id,.resource_sequence,.resource_usage,.batch_quantity, .step_no, .pm_batch_operation_line_id .pm_process_routing_header_id.activity_code,.activity_factror').val('');
   return false;
  } else {
   var selected = $(this).find('option:selected');
   $(trClass).find('.pm_batch_operation_detail_id').val($(selected).data('pm_batch_operation_detail_id'));
   $(trClass).find('.resource_sequence').val($(selected).data('resource_sequence'));
   $(trClass).find('.resource_usage').val($(selected).data('resource_usage'));
   $(trClass).find('.process_quantity').val($(selected).data('process_quantity'));
   $(trClass).find('.step_no').val($(selected).data('step_no'));
   $(trClass).find('.pm_batch_operation_line_id').val($(selected).data('pm_batch_operation_line_id'));
   $(trClass).find('.pm_process_routing_header_id').val($(selected).data('pm_process_routing_header_id'));
   $(trClass).find('.pm_batch_operation_detail_id').val($(selected).val());
   $(trClass).find('.activity_code').val($(selected).data('activity_code'));
   $(trClass).find('.activity_factror').val($(selected).data('activity_factror'));

  }

 });

});
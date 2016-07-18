$(document).ready(function () {
 $('body').off('change', '#org_id').on('change', '#org_id', function () {
  var org_id = $(this).val();
  $('form#pm_process_routing_line .pm_operion_header_id').find('option').remove();
  $('form#pm_process_routing_line .pm_operion_header_id').append($('#pm_operion_header_id').html());
  $('form#pm_process_routing_line').find('.pm_operion_header_id').each(function (i, op_obj) {
   $(op_obj).find('option').each(function (i, opt) {
    if ($(opt).data('org_id') != org_id) {
     $(this).remove();
    }
   });
  });
 });

});
$(document).ready(function() {
 
  //Get the primary_id on refresh button click
 $('body').off('click', 'a.wip_resource_transaction_id').on('click', 'a.wip_resource_transaction_id', function (e) {
  e.preventDefault();
  var transaction_type = $('#transaction_type').val();
  var wip_wo_header_id = $('#wip_wo_header_id').val();
  var wo_number = $('#wo_number').val();
  var link = '&transaction_type=' + transaction_type;
  if (wip_wo_header_id) {
   link += '&wip_wo_header_id=' + wip_wo_header_id;
  } else if (wo_number) {
   link += '&wo_number=' + wo_number;
  }
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + link;
  getFormDetails(formUrl);
 }).one();

});
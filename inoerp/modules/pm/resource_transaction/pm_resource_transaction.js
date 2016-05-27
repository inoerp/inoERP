$(document).ready(function() {
 
  $('body').off('click', 'a.pm_resource_transaction_id').on('click', 'a.pm_resource_transaction_id', function (e) {
  e.preventDefault();
  var transaction_type_id = $('#transaction_type_id').val();
  var pm_batch_header_id = $('#pm_batch_header_id').val();
  var org_id = $('#org_id').val();
  var batch_name = $('#batch_name').val();
  var link = '&transaction_type_id=' + transaction_type_id;
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

});
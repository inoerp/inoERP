$(document).ready(function () {

 $('body').off('change', '#bu_org_id').on('change', '#bu_org_id', function () {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && (!$('#sd_so_header_id').val()) && ($('#bu_org_id').attr('disabled') !== 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

 get_customer_detail_for_bu();

 $("#content").off("change", '#ar_customer_site_id').on("change", '#ar_customer_site_id', function () {
  var customer_site_id = $("#ar_customer_site_id").val();
  if (customer_site_id) {
   $.when(getCustomerSiteDetails('modules/ar/customer/json_customer.php', customer_site_id)).then(function () {
    getExchangeRate();
   });
  }
 });

 //exhhnge rate
 $('body').on('change', '#doc_currency', function () {
  if ($(this).val() !== $('#currency').val()) {
   $('#exchange_rate').prop('required', true).css('background', 'rgba(233, 209, 234, 0.61)');
  }
 });

 if ($('#currency').val() && $('#doc_currency').val() && ($('#currency').val() != $('#doc_currency').val())) {
  getExchangeRate();
 }

 $('body').off('change', '#currency, #doc_currency, #exchange_rate_type')
         .on('change', '#currency, #doc_currency, #exchange_rate_type', function () {
          getExchangeRate();
         });
 $('#currency').val();
});
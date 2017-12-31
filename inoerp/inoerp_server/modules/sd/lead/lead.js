$(document).ready(function () {
 //selecting Id
 $(".sd_lead_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=sd_lead', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('#sd_lead').off("change", "#ar_customer_site_id").on("change", "#ar_customer_site_id", function () {
  var ar_customer_site_id = $("#ar_customer_site_id").val();
  if (ar_customer_site_id) {
   getCustomerSiteDetails('modules/ar/customer/json_customer.php', ar_customer_site_id);
  }
 });

 get_customer_detail_for_bu(true);

 $('body').off('click', '#menu_button4').on('click', '#menu_button4', function () {
  $('#status').val('ENTERED');
  $('#sd_lead_id, #lead_number').val('');
 });

});
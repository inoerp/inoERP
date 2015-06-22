$(document).ready(function () {
 //selecting Id
 $(".sd_lead_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=sd_lead', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $("#content").off("change", '#ar_customer_site_id').on("change", '#ar_customer_site_id', function () {
  var customer_site_id = $("#ar_customer_site_id").val();
  if (customer_site_id) {
   getCustomerSiteDetails('modules/ar/customer/json_customer.php', customer_site_id);
  }
 });

 get_customer_detail_for_bu();

});
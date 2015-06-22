$(document).ready(function () {

 $("#customer_site_name").on("change", function () {
  if ($(this).val() === 'newentry') {
   if (confirm("Do you want to create a new customer site?")) {
    $(this).replaceWith('<input id="customer_site_name" class="textfield customer_site_name" type="text" size="25" maxlength="50" name="customer_site_name[]">');
    $(".show.ar_customer_site_id").hide();
    $("#ar_customer_site_id").val("");
    $("#customer_site_number").val("");
   }

  }
 });
});
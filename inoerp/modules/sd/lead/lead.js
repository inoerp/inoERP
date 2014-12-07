function setValFromSelectPage(sd_lead_id, extn_contact_id, contact_name, address_id) {
 this.sd_lead_id = sd_lead_id;
   this.extn_contact_id = extn_contact_id;
 this.contact_name = contact_name;
 this.address_id = address_id;
}


setValFromSelectPage.prototype.setVal = function () {
 var contact_field_class = '.' + localStorage.getItem("contact_field_class");
 if (this.sd_lead_id) {
  $("#sd_lead_id").val(this.sd_lead_id);
 }
  if (this.extn_contact_id) {
  $('#content').find(contact_field_class).find('.extn_contact_id_new').val(this.extn_contact_id);
 }
 if (this.contact_name) {
  $('#content').find(contact_field_class).find('.contact_name_new').val(this.contact_name);
 }
 
  if (this.address_id) {
  $("#address_id").val(this.address_id);
 }

 localStorage.removeItem("contact_field_class");
};

$(document).ready(function () {
 //selecting Id
 $(".sd_lead_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sd_lead', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the sd_lead_id on find button click
 $('a.show.sd_lead_id').click(function () {
  var sd_lead_id = $('#sd_lead_id').val();
  $(this).attr('href', modepath() + 'sd_lead_id=' + sd_lead_id);
 });
 
  $("#content").on("change", '#ar_customer_site_id', function() {
	var customer_site_id = $("#ar_customer_site_id").val();
	if (customer_site_id) {
	 getCustomerSiteDetails('modules/ar/customer/json_customer.php', customer_site_id);
	}
 });

});
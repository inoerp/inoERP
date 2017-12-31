function setValFromSelectPage(sd_store_id, address_id, extn_contact_id, contact_name) {
 this.sd_store_id = sd_store_id;
 this.address_id = address_id;
  this.extn_contact_id = extn_contact_id;
 this.contact_name = contact_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var sd_store_id = this.sd_store_id;
 var address_id = this.address_id;
 var contact_field_class = '.' + localStorage.getItem("contact_field_class");
 if (sd_store_id) {
  $("#sd_store_id").val(sd_store_id);
 }
 if (address_id) {
  $("#address_id").val(address_id);
 }
 
 if (this.extn_contact_id) {
  $('#content').find(contact_field_class).find('.extn_contact_id_new').val(this.extn_contact_id);
 }
 if (this.contact_name) {
  $('#content').find(contact_field_class).find('.contact_name_new').val(this.contact_name);
 }

 localStorage.removeItem("contact_field_class");
 };
 


$(document).ready(function() {

 $(".sd_store_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=sd_store', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 $('body').off("change", '#org_id').on("change", '#org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $(this).val()
  });
 });
 
 });
function setValFromSelectPage(supplier_id, supplier_number, supplier_name,
        address_id, address_name, address, country, postal_code, extn_contact_id, contact_name) {
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.address_id = address_id;
 this.address_name = address_name;
 this.address = address;
 this.country = country;
 this.postal_code = postal_code;
 this.extn_contact_id = extn_contact_id;
 this.contact_name = contact_name;
}

setValFromSelectPage.prototype.setVal = function () {
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var address_id = this.address_id;
 var address_name = this.address_name;
 var address = this.address;
 var country = this.country;
 var postal_code = this.postal_code;
 var addressPopupDivClass = '.' + localStorage.getItem("addressPopupDivClass");
 var contact_field_class = '.' + localStorage.getItem("contact_field_class");
 addressPopupDivClass = addressPopupDivClass.replace(/\s+/g, '.');
 if (address_id) {
  $('#content').find(addressPopupDivClass).find('.address_id').val(address_id);
 }
 if (address_name) {
  $('#content').find(addressPopupDivClass).find('.address_name').val(address_name);
 }
 if (address) {
  $('#content').find(addressPopupDivClass).find('.address').val(address);
 }
 if (country) {
  $('#content').find(addressPopupDivClass).find('.country').val(country);
 }
 if (postal_code) {
  $('#content').find(addressPopupDivClass).find('.postal_code').val(postal_code);
 }


 if (supplier_id) {
  $("#supplier_id").val(supplier_id);
 }
 if (supplier_number) {
  $("#supplier_number").val(supplier_number);
 }
 if (supplier_name) {
  $("#supplier_name").val(supplier_name);
 }

 if (this.extn_contact_id) {
  $('#content').find(contact_field_class).find('.extn_contact_id_new').val(this.extn_contact_id);
 }
 if (this.contact_name) {
  $('#content').find(contact_field_class).find('.contact_name_new').val(this.contact_name);
 }

 localStorage.removeItem("contact_field_class");
 localStorage.removeItem("addressPopupDivClass");

};


$(document).ready(function () {
//selecting supplier
 $(".supplier_id_popup").click(function () {
  void window.open('select.php?class_name=supplier', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

 $("#supplier_site_name").on("change", function () {
  if ($(this).val() == 'newentry') {
   if (confirm("Do you want to create a new supplier site?")) {
    $(this).replaceWith('<input id="supplier_site_name" class="textfield supplier_site_name" type="text" size="25" maxlength="50" name="supplier_site_name[]">');
    $(".show.supplier_site_id").hide();
    $("#supplier_site_id").val("");
    $("#supplier_site_number").val("");
   }

  }
 });


});



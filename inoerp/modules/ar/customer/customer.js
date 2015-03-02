function setValFromSelectPage(ar_customer_id, customer_number, customer_name,
        address_id, address_name, address, country, postal_code, extn_contact_id, contact_name) {
 this.ar_customer_id = ar_customer_id;
 this.customer_number = customer_number;
 this.customer_name = customer_name;
 this.address_id = address_id;
 this.address_name = address_name;
 this.address = address;
 this.country = country;
 this.postal_code = postal_code;
 this.extn_contact_id = extn_contact_id;
 this.contact_name = contact_name;
}

setValFromSelectPage.prototype.setVal = function () {
 var ar_customer_id = this.ar_customer_id;
 var customer_number = this.customer_number;
 var customer_name = this.customer_name;
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

 if (ar_customer_id) {
  $("#ar_customer_id").val(ar_customer_id);
 }
 if (customer_number) {
  $("#customer_number").val(customer_number);
 }
 if (customer_name) {
  $("#customer_name").val(customer_name);
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
 
  $(".ar_customer_id.select_popup").click(function () {
  void window.open('select.php?class_name=ar_customer', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });
 
  //Popup for selecting address
 $('body').off('click','.address_popup').on('click','.address_popup',function (e) {
  e.preventDefault();
  var rowClass = $(this).closest('div').prop('class');
  localStorage.setItem("addressPopupDivClass", rowClass);
  void window.open('form.php?class_name=address&mode=9&window_type=popup', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

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



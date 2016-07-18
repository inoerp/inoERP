function setValFromSelectPage(mdm_bank_header_id, bank_number, bank_name,
        address_id, address_name, address, country, postal_code, extn_contact_id, contact_name) {
 this.mdm_bank_header_id = mdm_bank_header_id;
 this.bank_number = bank_number;
 this.bank_name = bank_name;
 this.address_id = address_id;
 this.address_name = address_name;
 this.address = address;
 this.country = country;
 this.postal_code = postal_code;
 this.extn_contact_id = extn_contact_id;
 this.contact_name = contact_name;
}

setValFromSelectPage.prototype.setVal = function () {
 var mdm_bank_header_id = this.mdm_bank_header_id;
 var bank_number = this.bank_number;
 var bank_name = this.bank_name;
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


 if (mdm_bank_header_id) {
  $("#mdm_bank_header_id").val(mdm_bank_header_id);
 }
 if (bank_number) {
  $("#bank_number").val(bank_number);
 }
 if (bank_name) {
  $("#bank_name").val(bank_name);
 }


 if (this.extn_contact_id) {
  $('#content').find(contact_field_class).find('.extn_contact_id_new').val(this.extn_contact_id);
 }
 if (this.contact_name) {
  $('#content').find(contact_field_class).find('.contact_name_new').val(this.contact_name);
 }

 localStorage.removeItem("contact_field_class");

};


$(document).ready(function () {
//selecting supplier
 $(".mdm_bank_header_id_popup").click(function () {
  void window.open('select.php?class_name=mdm_bank_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

// //Get the mdm_bank_header_id on refresh button click
// $('a.show.mdm_bank_header_id').click(function () {
//  var mdm_bank_header_id = $('#mdm_bank_header_id').val();
//  $(this).attr('href', modepath() + 'mdm_bank_header_id=' + mdm_bank_header_id);
//
// });
//
// //Popup for selecting address 
// $(".address_popup").click(function () {
//  var addressPopupDivClass = $(this).closest('div').prop('class');
//  localStorage.setItem("addressPopupDivClass", addressPopupDivClass);
//  void window.open('select.php?class_name=address', '_blank',
//          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
//  return false;
// });
//
//
// $('a.show.mdm_bank_site_id').click(function () {
//  var mdm_bank_header_id = $('#mdm_bank_header_id').val();
//  var mdm_bank_site_id = $('#mdm_bank_site_id').val();
//  $(this).attr('href', modepath() + 'mdm_bank_header_id=' + mdm_bank_header_id + '&mdm_bank_site_id=' + mdm_bank_site_id);
// });

deleteReferences();
});

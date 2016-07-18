//function setValFromSelectPage(sd_opportunity_id, extn_contact_id, contact_name, address_id, 
//address_name, hr_employee_id, first_name, last_name) {
// this.sd_opportunity_id = sd_opportunity_id;
// this.extn_contact_id = extn_contact_id;
// this.contact_name = contact_name;
// this.address_id = address_id;
// this.address_name = address_name;
// this.hr_empoyee_id = hr_employee_id;
// this.first_name = first_name;
// this.last_name = last_name;
//}
//
//
//setValFromSelectPage.prototype.setVal = function () {
// var contact_field_class = '.' + localStorage.getItem("contact_field_class");
// 
// if(this.first_name){
// var name = this.first_name + ' ' + this.last_name;
//}
//
// if (this.sd_opportunity_id) {
//  $("#sd_opportunity_id").val(this.sd_opportunity_id);
// }
// if (this.extn_contact_id) {
//  $('#content').find(contact_field_class).find('.extn_contact_id_new').val(this.extn_contact_id);
// }
// if (this.contact_name) {
//  $('#content').find(contact_field_class).find('.contact_name_new').val(this.contact_name);
// }
//
// if (this.address_id) {
//  $("#address_id").val(this.address_id);
// }
//
// if (this.address_name) {
//  $("#address_name").val(this.address_name);
// }
// if (this.hr_employee_id) {
//  $("#sales_person_employee_id").val(this.hr_employee_id);
// }
// if (name) {
//  $("#sales_person_employee_name").val(name);
// }
//
// localStorage.removeItem("contact_field_class");
// localStorage.removeItem("row_class");
//  if(this.sd_opportunity_id){
//  $('a.show.sd_opportunity_id').trigger('click');
// }
//};

$(document).ready(function () {
// //selecting Id
// $(".sd_opportunity_id.select_popup").on("click", function () {
//  void window.open('select.php?class_name=sd_opportunity', '_blank',
//          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });


  $('#sd_opportunity').off("change", "#ar_customer_site_id").on("change", "#ar_customer_site_id", function () {
  var ar_customer_site_id = $("#ar_customer_site_id").val();
  if (ar_customer_site_id) {
   getCustomerSiteDetails('modules/ar/customer/json_customer.php', ar_customer_site_id);
  }
 });

 get_customer_detail_for_bu();

});
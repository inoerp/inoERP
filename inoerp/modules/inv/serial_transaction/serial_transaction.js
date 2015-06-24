function setValFromSelectPage(inv_serial_number_id, serial_number) {
 this.inv_serial_number_id = inv_serial_number_id;
 this.serial_number = serial_number;
}

setValFromSelectPage.prototype.setVal = function() {
 if (this.inv_serial_number_id) {
  $("#inv_serial_number_id").val(this.inv_serial_number_id);
 }
 
  if (this.serial_number) {
  $("#serial_number").val(this.serial_number);
 }
 
};
$(document).ready(function() {

 //Popup for selecting 
 $(".inv_serial_transaction_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=inv_serial_number', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});
function setValFromSelectPage(inv_lot_number_id, lot_number) {
 this.inv_lot_number_id = inv_lot_number_id;
 this.lot_number = lot_number;
}

setValFromSelectPage.prototype.setVal = function() {
 if (this.inv_lot_number_id) {
  $("#inv_lot_number_id").val(this.inv_lot_number_id);
 }
 
  if (this.lot_number) {
  $("#lot_number").val(this.lot_number);
 }
 
};
$(document).ready(function() {

 //Popup for selecting 
 $(".inv_lot_transaction_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=inv_lot_number', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});
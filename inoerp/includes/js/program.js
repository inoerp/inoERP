function setValFromSelectPage(inv_serial_number_id, item_id, item_number, item_description ) {
 this.inv_serial_number_id = inv_serial_number_id;
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
}


setValFromSelectPage.prototype.setVal = function() {
 var li_divId = '#' + localStorage.getItem("li_divId");
 var inv_serial_number_id = this.inv_serial_number_id;
 if (inv_serial_number_id) {
	$("#inv_serial_number_id").val(inv_serial_number_id);
 }
 if ( this.item_id ) {
	$("#item_id").val( this.item_id );
 }
  if ( this.item_number ) {
	$("#item_number").val( this.item_number );
  $(li_divId).val( this.item_number );
 }
  if ( this.item_description ) {
	$("#item_description").val( this.item_description );
  $("#item_description").val( this.item_description );
 }
 localStorage.removeItem("li_divId");
};


//end of global functions
$(document).ready(function() {

});









function setValFromSelectPage(inv_serial_number_id, serial_number) {
 this.inv_serial_number_id = inv_serial_number_id;
 this.serial_number = serial_number;
}

setValFromSelectPage.prototype.setVal = function() {
 if (this.inv_serial_number_id) {
  $("#inv_serial_number_id_h").val(this.inv_serial_number_id);
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


 //Get the option_id on find button click
 $('a.show.inv_serial_number_id').click(function() {
  var headerId = $('#inv_serial_number_id_h').val();
  var link = 'class_name=inv_serial_transaction_v&mode=2&search_order_by[]=inv_serial_transaction_id&search_asc_desc[]=desc&per_page=10&search_class_name=inv_serial_transaction_v&submit_search=Search&inv_serial_number_id[]=%3D' + headerId;
  $(this).prop('href', modepath() + link);
 });



 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docLineId = 'inv_count_entries_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'inv_count_entries';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();

});
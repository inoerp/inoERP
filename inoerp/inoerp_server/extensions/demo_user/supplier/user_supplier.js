function setValFromSelectPage(user_id, first_name, last_name, username) {
 this.user_id = user_id;
 this.username = username;
 this.first_name = first_name;
 this.last_name = last_name;

}

setValFromSelectPage.prototype.setVal = function() {
 if (this.user_id) {
  $("#user_id").val(this.user_id);
 }

 if (this.username) {
  $("#username").val(this.username);
 }
 if (this.first_name) {
  $("#first_name").val(this.first_name);
 }
 if (this.last_name) {
  $("#last_name").val(this.last_name);
 }
};

$(document).ready(function() {
// var Mandatory_Fields = ["#employee_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

// $('#content').on('changeHeader', '.document_header_id', function() {
//  var lineId = $(this).find('option:selected').data('ref_po_line_id');
//  $(this).closest('tr').find('.document_line_id').val(lineId);
// });


 //Popup for selecting user
 $(".user_id.select_popup").click(function() {
  var link = 'select.php?class_name=user';
  void window.open(link, '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//Get the user_supplier_id on find button click
 $('a.show.user_id').click(function() {
  var headerId = $('#user_id').val();
  $(this).attr('href', modepath() + 'user_id=' + headerId);
 });


 onClick_add_new_row('tr.user_supplier_line0', 'tbody.user_supplier_values', 2);

// deleteData('json_user_supplier.php');
 deleteData('form.php?class_name=user_supplier&line_class_name=user_supplier');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docLineId = 'user_supplier_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'user_supplier_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
// classContextMenu.contextMenu();

 var user_supplierSave = new saveMainClass();
 user_supplierSave.json_url = 'form.php?class_name=user_supplier';
 user_supplierSave.single_line = false;
 user_supplierSave.line_key_field = 'employee_id';
 user_supplierSave.form_line_id = 'user_supplier';
 user_supplierSave.saveMain();

 $("#content").on("change", '.supplier_name, .supplier_id', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
  if (($(this).closest('tr').find('.supplier_id').val())) {
   var supplier_id = $(this).closest('tr').find('.supplier_id').val();
   getSupplierDetails('modules/ap/supplier/json_supplier.php', '', supplier_id, trClass);
  }
 });

});  
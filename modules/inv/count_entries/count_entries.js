function setValFromSelectPage(inv_count_header_id, item_id_m, item_number, item_description, uom_id,
 count_name, org_id) {
 this.inv_count_header_id = inv_count_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.count_name = count_name;
 this.org_id = org_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var inv_count_header_id = this.inv_count_header_id;
 var count_name = this.count_name;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;

 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");


 if (inv_count_header_id) {
  $("#inv_count_header_id").val(inv_count_header_id);
 }
 var org_id = this.org_id;

 if (count_name) {
  $("#count_name").val(count_name);
 }
 if (org_id) {
  $("#org_id").val(org_id);
 }

 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (item_id_m) {
  $('#content').find(rowClass).find('.item_id_m').val(item_id_m);
 }
 if (item_number) {
  $('#content').find(rowClass).find('.item_number').val(item_number);
 }
 if (item_description) {
  $('#content').find(rowClass).find('.item_description').val(item_description);
 }
 if (uom_id) {
  $('#content').find(rowClass).find('.uom_id').val(uom_id);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");

};
 function default_counted_by(counted_by) {
  $('#form_line').find('.counted_by').each(function() {
   if ($(this).val().length < 1) {
    $(this).val(counted_by);
   }
  });
 }

$(document).ready(function() {

//  var Mandatory_Fields = ["#org_id", "First Select Org Name", "#item_number", "First Select Item Number"];
// select_mandatory_fields(Mandatory_Fields);
//
// $('#form_line').on("click", function() {
//  if (!$('#inv_count_header_id').val()) {
//   alert('No header Id : First enter/save header details');
//  } else {
//   var headerId = $('#inv_count_header_id').val();
//   if (!$(this).find('.inv_count_header_id').val()) {
//    $(this).find('.inv_count_header_id').val(headerId);
//   }
//  }
//
// });


 //Popup for selecting 
 $(".inv_count_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=inv_count_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".inv_abc_assignment_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=inv_abc_assignment_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the option_id on find button click
 $('a.show.inv_count_header_id').click(function() {
  var headerId = $('#inv_count_header_id').val();
  var count_date = $('.count_date').first().val();
  var link = 'class_name=inv_count_entries&search_order_by[]=inv_count_schedule_id&search_asc_desc[]=desc&per_page=10&search_class_name=inv_count_schedule&submit_search=Search&inv_count_header_id[]=' + headerId;
  link += '&schedule_date[]=%3C' + count_date + '&status[]=%3DUNCOUNTED';
  $(this).prop('href', modepath() + link);
 });

 $('#form_line').on('change', '.subinventory_id', function() {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', trClass);

 });

 onClick_add_new_row('tr.inv_count_entries0', 'tbody.inv_count_entries_values', 3);

 // deleteData('json_tax_code.php');
 deleteData('form.php?class_name=inv_count_entries&line_class_name=inv_count_entries');

 //defalut values to line
 $('#adjustment_ac_id').on('blur', function() {
  var acvalue = $(this).val();
  $('#form_line').find('.adjustment_ac_id').each(function() {
   if ($(this).val().length < 5) {
    $(this).val(acvalue);
   }

  });
 });
 var counted_by = $('#counted_by').val();
 default_counted_by(counted_by);
 $('#counted_by').on('blur', function() {
  var counted_by = $(this).val();
  default_counted_by(counted_by);
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docLineId = 'inv_count_entries_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'inv_count_entries';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();

 var formSave = new saveMainClass();
 formSave.json_url = 'form.php?class_name=inv_count_entries';
 formSave.single_line = false;
 formSave.line_key_field = 'item_id_m';
 formSave.form_line_id = 'inv_count_entries';
 formSave.enable_select = true;
 formSave.saveMain();
});
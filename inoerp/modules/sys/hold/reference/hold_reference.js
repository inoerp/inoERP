function setValFromSelectPage(sys_hold_reference_id, reference_table, reference_id) {
 this.sys_hold_reference_id = sys_hold_reference_id;
 this.reference_table = reference_table;
 this.reference_id = reference_id;
}

setValFromSelectPage.prototype.setVal = function() {
 if (this.sys_hold_reference_id) {
  $('#sys_hold_reference_id').val(this.sys_hold_reference_id);
 }
  if (this.reference_table) {
  $('#reference_table').val(this.reference_table);
 }
  if (this.reference_id) {
  $('#reference_id').val(this.reference_id);
 }
};

$(document).ready(function() {
// var Mandatory_Fields = ["#employee_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

// $('#content').on('changeHeader', '.document_header_id', function() {
//  var lineId = $(this).find('option:selected').data('ref_po_line_id');
//  $(this).closest('tr').find('.document_line_id').val(lineId);
// });

 $('#content').on('change', '.document_type', function() {
  if ($('#bu_org_id').val() && $('#supplier_site_id').val() && $('#item_id_m').val()) {
   getBPAList({
    'bu_org_id': $('#bu_org_id').val(),
    'supplier_site_id': $('#supplier_site_id').val(),
    'item_id_m': $('#item_id_m').val(),
    'field_name': 'document_line_id',
    'replacing_field': 'document_line_id',
    'trclass': $(this).closest('tr').attr('class'),
   });
  }
 });

 $(".sys_hold_reference_id.select_popup").click(function() {
	void window.open('select.php?class_name=sys_hold_reference', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

//Get the hold_reference_id on find button click
 $('a.show.sys_hold_reference').click(function() {
  var headerId = $('#sys_hold_reference_id').val();
  $(this).attr('href', modepath() + 'sys_hold_reference_id=' + headerId);
 });
 
  $('a.show.sys_hold_reference_docId').click(function() {
  var reference_table = $('#reference_table').val();
  var reference_id = $('#reference_id').val();
  $(this).attr('href', modepath() + 'reference_table=' + reference_table + '&reference_id=' + reference_id);
 });



 onClick_add_new_row('tr.hold_reference_line0', 'tbody.hold_reference_values', 2);

// deleteData('json_hold_reference.php');
 deleteData('form.php?class_name=sys_hold_reference&line_class_name=sys_hold_reference');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docLineId = 'sys_hold_reference_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'hold_reference_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
// classContextMenu.contextMenu();

 var hold_referenceSave = new saveMainClass();
 hold_referenceSave.json_url = 'form.php?class_name=sys_hold_reference';
 hold_referenceSave.single_line = false;
 hold_referenceSave.line_key_field = 'employee_id';
 hold_referenceSave.form_line_id = 'sys_hold_reference';
 hold_referenceSave.saveMain();

});  
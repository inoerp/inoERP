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

//  $('a.show.sys_hold_reference_doc_id').click(function() {
//  var reference_table = $('#reference_table').val();
//  var reference_id = $('#reference_id').val();
//  $(this).attr('href', modepath() + 'reference_table=' + reference_table + '&reference_id=' + reference_id);
// });


 });  
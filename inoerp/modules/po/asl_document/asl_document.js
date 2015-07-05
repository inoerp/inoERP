function setValFromSelectPage(po_asl_line_id) {
 this.po_asl_line_id = po_asl_line_id;
}

setValFromSelectPage.prototype.setVal = function() {
 if (this.po_asl_line_id) {
  $('#po_asl_line_id').val(this.po_asl_line_id);
 }
};

$(document).ready(function() {

 $('body').off('change', '#content').on('change', '#content' , '.document_type', function() {
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

 $(".po_asl_line_id.select_popup").click(function() {
	void window.open('select.php?class_name=po_asl_line', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });


});  
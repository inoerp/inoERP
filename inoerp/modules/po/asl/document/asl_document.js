function setValFromSelectPage(combination) {
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
  $('#content').find(fieldClass).val(combination);
  localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
// var Mandatory_Fields = ["#employee_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

 $('#content').on('changeHeader', '.document_header_id', function() {
  var lineId = $(this).find('option:selected').data('ref_po_line_id');
  $(this).closest('tr').find('.document_line_id').val(lineId);
 });

 $('#content').on('change', '.document_type', function() {
  alert ($('#bu_org_id').val()  + ' : ' + $('#supplier_site_id').val()  + ' : ' + $('#item_id_m').val());
  if ($('#bu_org_id').val() && $('#supplier_site_id').val() && $('#item_id_m').val()) {
   getBPAList({
    'bu_org_id': $('#bu_org_id').val(),
    'supplier_site_id': $('#supplier_site_id').val(),
    'item_id_m': $('#item_id_m').val(),
    'field_name': 'document_header_id',
    'replacing_field': 'document_header_id',
    'trclass': $(this).closest('tr').attr('class'),
   });
  }
 });

 $(".po_asl_line_id.select_popup").click(function() {
	void window.open('select.php?class_name=po_asl_line', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

//Get the asl_document_id on find button click
 $('a.show.po_asl_document').click(function() {
  var headerId = $('#po_asl_line_id').val();
  $(this).attr('href', modepath() + 'po_asl_line_id=' + headerId);
 });


 onClick_add_new_row('tr.asl_document_line0', 'tbody.asl_document_values', 2);

// deleteData('json_asl_document.php');
 deleteData('form.php?class_name=po_asl_document&line_class_name=po_asl_document');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docLineId = 'po_asl_document_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'asl_document_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
// classContextMenu.contextMenu();

 var asl_documentSave = new saveMainClass();
 asl_documentSave.json_url = 'form.php?class_name=po_asl_document';
 asl_documentSave.single_line = false;
 asl_documentSave.line_key_field = 'employee_id';
 asl_documentSave.form_line_id = 'po_asl_document';
 asl_documentSave.saveMain();

});  
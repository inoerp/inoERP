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

//Name Value
 $('#form_line').on('focusout', '.year', function() {
  var name = '';
  name += $(this).closest('tr').find('.name_prefix').val();
  name += '-' + $(this).val();
  $(this).closest('tr').find('.name').val(name);
 });

//Get the document_sequence_id on find button click
 $('a.show.sys_document_sequence').click(function() {
  var link = 'pageno=1&per_page=10&submit_search=Search&search_class_name=sys_document_sequence';
  if ($('#bu_org_id').val()) {
    link += '&bu_org_id=' + $('#bu_org_id').val();
   }
  
  $(this).prop('href', modepath() + link);
 });


 onClick_add_new_row('tr.document_sequence_line0', 'tbody.document_sequence_values', 2);

// deleteData('json_document_sequence.php');
 deleteData('form.php?class_name=sys_document_sequence&line_class_name=sys_document_sequence');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docLineId = 'sys_document_sequence_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'document_sequence_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
// classContextMenu.contextMenu();

 var document_sequenceSave = new saveMainClass();
 document_sequenceSave.json_url = 'form.php?class_name=sys_document_sequence';
 document_sequenceSave.single_line = false;
 document_sequenceSave.line_key_field = 'document_type';
 document_sequenceSave.form_line_id = 'sys_document_sequence';
 document_sequenceSave.saveMain();

});  
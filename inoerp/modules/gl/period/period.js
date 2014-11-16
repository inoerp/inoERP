$(document).ready(function() {
// var Mandatory_Fields = ["#option_line_code", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').on('focusout', '.year', function() {
	var name = '';
	name += $(this).closest('tr').find('.name_prefix').val();
	name += '-' + $(this).val();
	$(this).closest('tr').find('.name').val(name);
 });

//Get the calendar_id on find button click
 $('a.show.ledger_id').click(function() {
	var headerId = $('#ledger_id').val();
	$(this).prop('href', modepath() + 'pageno=1&per_page=10&submit_search=Search\n\
 &search_order_by[]=year&search_asc_desc[]=desc&search_order_by[]=number&search_class_name=gl_calendar&ledger_id=' + headerId);
 });

 onClick_add_new_row('tr.calendar_line0', 'tbody.calendar_values', 2);
 deleteData('json_calendar.php');
// save('json_calendar.php', '#calendar_line', 'line_id_cb', 'name', '#gl_period_id');

 //context menu
 var classContextMenu = new contextMenuMain();
  classContextMenu.docLineId = 'gl_period_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'calendar_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
// classContextMenu.contextMenu();

 var periodSave = new saveMainClass();
 periodSave.json_url = 'form.php?class_name=gl_period';
 periodSave.single_line = false;
 periodSave.line_key_field = 'gl_period_id';
 periodSave.lineClassName = 'gl_period';
 periodSave.onlyOneLineAtATime = true;
 periodSave.saveMain();

 $('#open_next_period').on('click', function() {
	if ($('#new_gl_calendar_id').val()) {
	 var period_name = $('#new_gl_calendar_id option:selected').text();
	 if (confirm("Open " + period_name + " Period ?\n")) {
		$('#status').val('OPEN');
		var form_header_id = '#gl_period';
		var headerData = $(form_header_id).serializeArray();
		saveHeader('form.php?class_name=gl_period', headerData, '#gl_period_id', '', true, 'gl_period');
	 }
	} else {
	 alert('No period avaibale to open');
	}
 });
});  
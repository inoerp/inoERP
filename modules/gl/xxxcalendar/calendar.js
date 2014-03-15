$(document).ready(function() {
  var Mandatory_Fields = ["#option_line_code", "First Select Calendar Name"];
 select_mandatory_fields(Mandatory_Fields);

//Name Value
$('#form_line').on('focusout', '.year', function() {
var name = '';
name +=$(this).closest('tr').find('.name_prefix').val();
name += '-'+ $(this).val();
$(this).closest('tr').find('.name').val(name);
});

//Get the calendar_id on find button click
 $('a.show.gl_calendar').click(function() {
	var headerId = $('#option_line_code').val();
	$(this).attr('href', '?pageno=1&per_page=10&submit_search=Search&search_class=gl_calendar&option_line_code=' + headerId);
 });

 onClick_add_new_row('tr.calendar_line0', 'tbody.calendar_values', 2);
 deleteData('json_calendar.php');
 save('json_calendar.php', '#calendar_line', 'line_id_cb', 'name', '#gl_calendar_id');

});  
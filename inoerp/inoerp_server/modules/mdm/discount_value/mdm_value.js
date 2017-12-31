$(document).ready(function() {

//Name Value
 $('#form_line').on('focusout', '.year', function() {
	var name = '';
	name += $(this).closest('tr').find('.name_prefix').val();
	name += '-' + $(this).val();
	$(this).closest('tr').find('.name').val(name);
 });


});  


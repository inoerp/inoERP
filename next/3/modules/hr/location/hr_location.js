$(document).ready(function() {

//COA combination
 $('body').on('focusout', '#hr_location_line .field_values', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	var coaCombination = '';
	$(this).closest('tr').find('.field_values').each(function() {
	 coaCombination += $(this).val() + '-';
	});
	coaCombination = coaCombination.slice(0, -1);
	$(this).closest('#hr_location_line').find(trClass).find('.combination').val(coaCombination);
 });
 
//COA Decsription
$('body').on('focusout', '#hr_location_line .field_values', function() {
var trClass = '.' + $(this).closest('tr').prop('class');
var coaDesc = '';
$(this).closest('tr').find('.field_values').each(function() {
 coaDesc += $(this).children("option:selected").text().split(' | ').pop()+ '|';
});
coaDesc = coaDesc.slice(0, -1);
$(this).closest('#hr_location_line').find(trClass).find('.description').val(coaDesc);
});


$('body').on('change', '#form_line .ac.field_values', function(){
  var ac_type = $(this).find('option:selected').data('account_qualifier');
var trClass = '.'+$(this).closest('tr').attr('class').replace(/\s+/g, '.');
$(trClass).find('.ac_type').val(ac_type);
});

});  
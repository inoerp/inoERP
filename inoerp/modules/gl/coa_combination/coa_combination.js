$(document).ready(function() {
////Show the segments after coa_structure_id is selected
// $("#coa_segment_values #coa_id").focusout(function() {
//	$('#loading').show();
//	var coaId = $("#coa_segment_values #coa_structure_id").val();
//
//	$.ajax({
//	 url: '../../system/option/json.option.php?',
//	 data: {option_id_l: coaId},
//	 type: 'get'
//	}).done(function(data) {
//	 var div = $('#coa_json', $(data)).html();
//	 $("#coa_segment_values #coa_segments").html(div);
//	 $('#loading').hide();
//	}).fail(function() {
//	 alert("failed");
//	 $('#loading').hide();
//	});
//
// });
 
//COA combination
 $('#coa_combination_line').on('focusout', '.field_values', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	var coaCombination = '';
	$(this).closest('tr').find('.field_values').each(function() {
	 coaCombination += $(this).val() + '-';
	});
	coaCombination = coaCombination.slice(0, -1);
	$(this).closest('#coa_combination_line').find(trClass).find('.combination').val(coaCombination);
 });
//COA Decsription
$('#coa_combination_line').on('focusout', '.field_values', function() {
var trClass = '.' + $(this).closest('tr').prop('class');
var coaDesc = '';
$(this).closest('tr').find('.field_values').each(function() {
 coaDesc += $(this).children("option:selected").text().split(' - ').pop()+ '-';
});
coaDesc = coaDesc.slice(0, -1);
$(this).closest('#coa_combination_line').find(trClass).find('.description').val(coaDesc);
});

});  
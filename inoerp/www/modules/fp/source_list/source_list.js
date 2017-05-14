

function lineListTypeValues(source_list_line_type, trClass) {
	var source_list_line_type = source_list_line_type;
	$('#loading').show();
	$.ajax({
	 url: 'modules/fp/source_list/json_source_list.php',
	 type: 'get',
	 dataType: 'json',
	 data: {
		source_list_line_type: source_list_line_type,
		find_source_list_line_type: 1,
    org_id: $('#org_id').val()
	 },
	 success: function(result) {
		var items = [];
		var option_stmt = '<option value=""></option>';
		$.each(result, function(key, val) {
		 option_stmt += '<option value="' + val.id + '">' + val.name + '</option>';
		 items.push("<li id='" + key + "'>" + val.name + "</li>");
		});
		$('#content').find(trClass).find('.source_list_id').removeAttr('disabled');
		$('#content').find(trClass).find('.source_list_id').empty().append(option_stmt);
	 },
	 complete: function() {
		$('.show_loading_small').hide();
	 },
	 beforeSend: function() {
		$('.show_loading_small').show();
	 },
	 error: function(request, errorType, errorMessage) {
		var msg = 'No Data Found! \n';
		msg += 'Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage;
		alert(msg);
	 }
	});
 }

$(document).ready(function() {
//mandatory and field sequence
// var mandatoryCheck = new mandatoryFieldMain();
// mandatoryCheck.mandatoryHeader();


//set the default bucket type if its empty
 if (!$('#fp_source_list_header_divId #form_line').find('.bucket_type').first().val()) {
	$('#fp_source_list_header_divId #form_line').find('.bucket_type').first().val('WEEKLY');
 }

 $('#fp_source_list_header_divId #form_line' ).off('blur', '.source_list_line_type').on('blur', '.source_list_line_type', function() {
	var trClass = '.' + $(this).closest('tr').attr('class');
//	lineListTypeValues($(this).val(), trClass);
 });

 function afterAddNewRow() {
	$('#form_line').find('.bucket_type').last().val('WEEKLY');
//	adjust_date();
 }
 
  //Popup for selecting source list
 $('#fp_source_list_header_divId').off('click','.fp_source_list_header_id.select_popup')
         .on('click','.fp_source_list_header_id.select_popup',function() {
	void window.open('select.php?class_name=fp_source_list_header', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

});
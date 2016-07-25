
 function afterAddNewRow() {
	$('#form_line').find('.bucket_type').last().val('WEEKLY');
//	adjust_date();
 }

$(document).ready(function() {


//set the default bucket type if its empty
 if (!$('#fp_forecast_header_divId #form_line').find('.bucket_type').first().val()) {
	$('#fp_forecast_header_divId #form_line').find('.bucket_type').first().val('WEEKLY');
 }

 $('#fp_forecast_header_divId').off('blur', '.start_date, .end_date, .bucket_type')
         .on('blur', '.start_date, .end_date, .bucket_type', function() {
	var noOfBucket = 1;
	var bucketSize = 1;
	if ($(this).closest('tr').find('.end_date').val()) {
	 var date1 = new Date($(this).closest('tr').find('.start_date').val()).getTime();
	 var date2 = new Date($(this).closest('tr').find('.end_date').val()).getTime();
	 var diff = (date2 - date1);
	 	 if (diff < 0) {
		alert('Start date cant be before end date');
		$(this).val('');
		return ;
	 }
	 var days = diff / (24 * 3600 * 1000);
	 if ($(this).closest('tr').find('.bucket_type').val() == 'WEEKLY') {
		bucketSize = 7;
	 }
	 noOfBucket = Math.ceil(days / bucketSize);
	}
	$(this).closest('tr').find('.no_of_bucket').val(noOfBucket);
 });

 //quantity
 $('#fp_forecast_header_divId').off('change', '.current, .original, .no_of_bucket')
         .on('change', '.current, .original, .no_of_bucket', function() {
	var noOfBucket = 1;
	var trClass = '.'+$(this).closest('tr').attr('class');
	if ($(this).closest('.tabContainer').find(trClass).find('.no_of_bucket').val()) {
	 noOfBucket = +$(this).closest('.tabContainer').find(trClass).find('.no_of_bucket').val();
	}
	$(this).closest('tr').find('.total_current').val(+(noOfBucket * (+$(this).closest('tr').find('.current').val())));
	$(this).closest('tr').find('.total_original').val(+(noOfBucket * (+$(this).closest('tr').find('.original').val())));
 });

 //Popup for selecting forecast
 $('#fp_forecast_header_divId').off('click','.fp_forecast_header_id.select_popup')
         .on('click','.fp_forecast_header_id.select_popup',function() {
	void window.open('select.php?class_name=fp_forecast_header', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

});
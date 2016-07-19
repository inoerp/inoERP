function setValFromSelectPage(fp_forecast_header_id, forecast, item_id_m, item_number, item_description,
uom_id) {
 this.fp_forecast_header_id = fp_forecast_header_id;
 this.forecast = forecast;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
  this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var supplier_site_id = this.supplier_site_id;
 var forecast = this.forecast;
 var fp_forecast_header_id = this.fp_forecast_header_id;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;


 if (forecast) {
	$('#content').find('#forecast').val(forecast);
 }
  var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');

 if (item_id_m) {
	$('#content').find(rowClass).find('.item_id_m').val(item_id_m);
 }
 if (item_number) {
	$('#content').find(rowClass).find('.item_number').val(item_number);
 }
 if (item_description) {
	$('#content').find(rowClass).find('.item_description').val(item_description);
 }
 if (uom_id) {
	$('#content').find(rowClass).find('.uom_id').val(uom_id);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("row_class");
 
  if (fp_forecast_header_id) {
	$('#fp_forecast_header_id').val(fp_forecast_header_id);
  $('a.show.fp_forecast_header_id').trigger('click');
 }

};

 function afterAddNewRow() {
	$('#form_line').find('.bucket_type').last().val('WEEKLY');
//	adjust_date();
 }

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'forecast_header_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

//set the default bucket type if its empty
 if (!$('#fp_forecast_header_divId #form_line').find('.bucket_type').first().val()) {
	$('#fp_forecast_header_divId #form_line').find('.bucket_type').first().val('WEEKLY');
 }

 $('#fp_forecast_header_divId').off('change', '.start_date, .end_date, .bucket_type')
         .on('change', '.start_date, .end_date, .bucket_type', function() {
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
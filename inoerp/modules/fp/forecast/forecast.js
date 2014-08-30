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

 if (fp_forecast_header_id) {
	$('#content').find('#fp_forecast_header_id').val(fp_forecast_header_id);
 }
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

};

 function afterAddNewRow() {
	$('#form_line').find('.bucket_type').last().val('WEEKLY');
//	adjust_date();
 }

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'forecast_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

//set the default bucket type if its empty
 if (!$('#form_line').find('.bucket_type').first().val()) {
	$('#form_line').find('.bucket_type').first().val('WEEKLY');
 }

//existing dates
//function adjust_date(){
//var currentDate = new Date();
// $('#content').find('.start_date, .end_date').each(function() {
//	if ($(this).closest('tr').find('.bucket_type').val() === 'WEEKLY') {
//	 $(this).datepicker({
//		defaultDate: 0,
//		changeMonth: true,
//		changeYear: true,
//		dateFormat: "yy-mm-dd",
//		beforeShowDay: function(date) {
//		 return [date.getDay() == 1, ""]
//		},
//		setDate: currentDate
//	 });
//	} else {
//	 $(this).datepicker({
//		defaultDate: 0,
//		changeMonth: true,
//		changeYear: true,
//		dateFormat: "yy-mm-dd",
//		setDate: currentDate
//	 });
//	}
// });
// alert('in date');
//}
//
//adjust_date();


 $('#form_line').on('change', '.start_date, .end_date, .bucket_type', function() {
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
 $('#form_line').on('change', '.current, .original, .no_of_bucket', function() {
	var noOfBucket = 1;
	var trClass = '.'+$(this).closest('tr').attr('class');
	if ($(this).closest('.tabContainer').find(trClass).find('.no_of_bucket').val()) {
	 noOfBucket = +$(this).closest('.tabContainer').find(trClass).find('.no_of_bucket').val();
	}
	$(this).closest('tr').find('.total_current').val(+(noOfBucket * (+$(this).closest('tr').find('.current').val())));
	$(this).closest('tr').find('.total_original').val(+(noOfBucket * (+$(this).closest('tr').find('.original').val())));
 });

 //Popup for selecting forecast
 $(".forecast_header_id.select_popup").click(function() {
	void window.open('select.php?class_name=fp_forecast_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the forecast_id on find button click
 $('a.show.fp_forecast_header_id').click(function() {
	var headerId = $('#fp_forecast_header_id').val();
	$(this).attr('href', modepath() + 'fp_forecast_header_id=' + headerId);
 });

 $("#content").on("change", '.supplier_name, .supplier_id', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	function afterFunction(result) {
	 var supplier_sites = $(result).find('div#json_supplierSites_find_all').html();
	 $('#content').find(trClass).find('.supplier_site_id').replaceWith(supplier_sites);
	 $('#content').find(trClass).find('.supplier_site_id').removeAttr('id');
	 trClass = null;
	}
	if (($(this).closest('tr').find('.supplier_id').val())) {
	 var supplier_id = $(this).closest('tr').find('.supplier_id').val();
	 getSupplierDetails('modules/ap/supplier/json_supplier.php', '', supplier_id, afterFunction);
	}
 });

 //selecting supplier
 $("#content").on("click", '.select_supplier_name.select_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	localStorage.setItem("row_class", rowClass);
	void window.open('select.php?class_name=supplier_all_v', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //add a new row
// onClick_add_new_row('forecast_line', 'form_data_line_tbody', 1)
 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'forecast_line0';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.divClassToBeCopied = 'bucket_type';
	addNewRow.noOfTabs = 2;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row(afterAddNewRow);
 });

 deleteData('form.php?class_name=fp_forecast_header&line_class_name=fp_forecast_line');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'fp_ourcing_rule_header_id';
 classContextMenu.docLineId = 'fp_forecast_line_id';
 classContextMenu.btn1DivId = 'forecast_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'fp_forecast_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';

 classContextMenu.noOfTabbs = 1;
 classContextMenu.contextMenu();

//remove forecast lines
 $("#remove_row").click(function() {
	$('input[name="forecast_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//get the attachement form
 deleteData('form.php?class_name=fp_forecast_header&line_class_name=fp_forecast_line');

// save('json.forecast.php', '#forecast_header', 'line_id_cb', 'component_item_id_m', '#forecast_header_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=fp_forecast_header';
 classSave.form_header_id = 'forecast_header';
 classSave.primary_column_id = 'fp_forecast_header_id';
 classSave.line_key_field = 'item_id_m';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'fp_forecast_header';
 classSave.lineClassName = 'fp_forecast_line';
 classSave.saveMain();

});

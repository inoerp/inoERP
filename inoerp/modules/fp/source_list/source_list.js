function setValFromSelectPage(fp_source_list_header_id, source_list, supplier_id, supplier_number, supplier_name,
				supplier_site_id, supplier_site_name) {
 this.fp_source_list_header_id = fp_source_list_header_id;
 this.source_list = source_list;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.supplier_site_id = supplier_site_id;
 this.supplier_site_name = supplier_site_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var supplier_site_id = this.supplier_site_id;
 var source_list = this.source_list;
 var fp_source_list_header_id = this.fp_source_list_header_id;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var supplier_site_name = this.supplier_site_name;
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');

 if (fp_source_list_header_id) {
	$('#content').find('#fp_source_list_header_id').val(fp_source_list_header_id);
 }
 if (source_list) {
	$('#content').find('#source_list').val(source_list);
 }
 if (supplier_id) {
	$('#content').find(rowClass).find(".supplier_id").val(supplier_id);
 }
 if (supplier_site_id) {
	$('#content').find(rowClass).find(".supplier_site_id").val(supplier_site_id);
 }
 if (supplier_number) {
	$('#content').find(rowClass).find(".supplier_number").val(supplier_number);
 }

 if (supplier_site_name) {
	$('#content').find(rowClass).find(".supplier_site_name").val(supplier_site_name);
 }

 if (supplier_name) {
	$('#content').find(rowClass).find(".supplier_name").val(supplier_name);
	$('#content').find(rowClass).find(".select_supplier_name").val(supplier_name);
 }

 localStorage.removeItem("row_class");

};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'source_list_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

//set the default bucket type if its empty
 if (!$('#form_line').find('.bucket_type').first().val()) {
	$('#form_line').find('.bucket_type').first().val('WEEKLY');
 }

 function lineListTypeValues(source_list_line_type, trClass) {
	var source_list_line_type = source_list_line_type;
	$('#loading').show();
	$.ajax({
	 url: 'modules/fp/source_list/json_source_list.php',
	 type: 'get',
	 dataType: 'json',
	 data: {
		source_list_line_type: source_list_line_type,
		find_source_list_line_type: 1
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

 $('#content').on('change', '.source_list_line_type', function() {
	var trClass = '.' + $(this).closest('tr').attr('class');
	lineListTypeValues($(this).val(), trClass);
 });

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
 function afterAddNewRow() {
	$('#form_line').find('.bucket_type').last().val('WEEKLY');
//	adjust_date();
 }

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
		return;
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
	var trClass = '.' + $(this).closest('tr').attr('class');
	if ($(this).closest('.tabContainer').find(trClass).find('.no_of_bucket').val()) {
	 noOfBucket = +$(this).closest('.tabContainer').find(trClass).find('.no_of_bucket').val();
	}
	$(this).closest('tr').find('.total_current').val(+(noOfBucket * (+$(this).closest('tr').find('.current').val())));
	$(this).closest('tr').find('.total_original').val(+(noOfBucket * (+$(this).closest('tr').find('.original').val())));
 });

 //Popup for selecting source_list
 $(".source_list_header_id.select_popup").click(function() {
	void window.open('select.php?class_name=fp_source_list_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the source_list_id on find button click
 $('a.show.fp_source_list_header_id').click(function() {
	var headerId = $('#fp_source_list_header_id').val();
	$(this).attr('href', modepath() + 'fp_source_list_header_id=' + headerId);
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
// onClick_add_new_row('source_list_line', 'form_data_line_tbody', 1)
 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'source_list_line0';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.divClassToBeCopied = 'bucket_type';
	addNewRow.noOfTabs = 2;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row(afterAddNewRow);
 });

 

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'fp_ourcing_rule_header_id';
 classContextMenu.docLineId = 'fp_source_list_line_id';
 classContextMenu.btn1DivId = 'source_list_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'fp_source_list_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';

 classContextMenu.noOfTabbs = 1;
 classContextMenu.contextMenu();

//remove source_list lines
 $("#remove_row").click(function() {
	$('input[name="source_list_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//get the attachement form
 deleteData('form.php?class_name=fp_source_list_header&line_class_name=fp_source_list_line');

// save('json.source_list.php', '#source_list_header', 'line_id_cb', 'component_item_id', '#source_list_header_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=fp_source_list_header';
 classSave.form_header_id = 'source_list_header';
 classSave.primary_column_id = 'fp_source_list_header_id';
 classSave.line_key_field = 'source_list_line_type';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'fp_source_list_header';
 classSave.lineClassName = 'fp_source_list_line';
 classSave.saveMain();

});

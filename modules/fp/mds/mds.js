function setValFromSelectPage(fp_mds_header_id, mds) {
 this.fp_mds_header_id = fp_mds_header_id;
 this.mds = mds;
}

setValFromSelectPage.prototype.setVal = function() {
  var mds = this.mds;
 var fp_mds_header_id = this.fp_mds_header_id;
 
 if (fp_mds_header_id) {
	$('#content').find('#fp_mds_header_id').val(fp_mds_header_id);
 }
 if (mds) {
	$('#content').find('#mds').val(mds);
 }
 };

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'mds_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

//set the default bucket type if its empty
 if (!$('#form_line').find('.bucket_type').first().val()) {
	$('#form_line').find('.bucket_type').first().val('WEEKLY');
 }

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

 //Popup for selecting mds
 $(".mds_header_id.select_popup").click(function() {
	void window.open('select.php?class_name=fp_mds_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the mds_id on find button click
 $('a.show.fp_mds_header_id').click(function() {
	var headerId = $('#fp_mds_header_id').val();
	$(this).attr('href', modepath() + 'fp_mds_header_id=' + headerId);
 });

 //selecting supplier
 $("#content").on("click", '.select_supplier_name.select_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	localStorage.setItem("row_class", rowClass);
	void window.open('select.php?class_name=supplier_all_v', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //add a new row
// onClick_add_new_row('mds_line', 'form_data_line_tbody', 1)
 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'mds_line0';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.divClassToBeCopied = 'bucket_type';
	addNewRow.noOfTabs = 2;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row(afterAddNewRow);
 });

 deleteData('form.php?class_name=fp_mds_header&line_class_name=fp_mds_line');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'fp_ourcing_rule_header_id';
 classContextMenu.docLineId = 'fp_mds_line_id';
 classContextMenu.btn1DivId = 'mds_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'fp_mds_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 1;
 classContextMenu.contextMenu();

//remove mds lines
 $("#remove_row").click(function() {
	$('input[name="mds_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//get the attachement form
 deleteData('form.php?class_name=fp_mds_header&line_class_name=fp_mds_line');

// save('json.mds.php', '#mds_header', 'line_id_cb', 'component_item_id', '#mds_header_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=fp_mds_header';
 classSave.form_header_id = 'mds_header';
 classSave.primary_column_id = 'fp_mds_header_id';
 classSave.line_key_field = 'item_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'fp_mds_header';
 classSave.lineClassName = 'fp_mds_line';
 classSave.saveMain();

});

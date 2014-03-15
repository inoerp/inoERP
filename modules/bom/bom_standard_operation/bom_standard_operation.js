$(document).ready(function() {
//mandatory fields
 var Mandatory_Fields = ["#org_id", "First Select Inventory", "#department_id", "First Select Department"];
 select_mandatory_fields(Mandatory_Fields);

 $('#form_line').on("click", function() {
	if (!$('#bom_standard_operation_id').val()) {
	 alert('No header Id : First enter/save header details');
	} else {
	 var HEADER_ID = $('#bom_standard_operation_id').val();
	 if (!$(this).find('.bom_standard_operation_id').val()) {
		$(this).find('.bom_standard_operation_id').val(HEADER_ID);
	 }
	}

 });

 //selecting data
 $(".bom_standard_operation_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('find_bom_standard_operation.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 function setParnetWindowValues(bom_standard_operation_id, bom_standard_operation, orgId)
 {
	if ((typeof localStorage.idValue !== 'undefined') && (localStorage.idValue.length > 0)) {
	 var RowDivId = 'tr#' + localStorage.idValue;
	 window.opener.$(RowDivId).find(".bom_standard_operation_id").val(bom_standard_operation_id);
	 window.opener.$(RowDivId).find(".bom_standard_operation").val(bom_standard_operation);
	 window.opener.$(RowDivId).find(".org_id").val(orgId);
	} else {
	 window.opener.$(".bom_standard_operation_id").val(bom_standard_operation_id);
	 window.opener.$(".bom_standard_operation").val(bom_standard_operation);
	 window.opener.$(".org_id").val(orgId);
	}
 }

 $(".quick_select").on("click", function() {
	var bom_standard_operation_id = $(this).val();
	var bom_standard_operation = $(this).closest("td").siblings("td.bom_standard_operation").html();
	var orgId = $(this).closest("td").siblings("td.org_id").html();
	setParnetWindowValues(bom_standard_operation_id, bom_standard_operation, orgId);
	window.close();
 });

 //add new lines
 $("#content tbody.bom_standard_operation_resource_assignment_values").on("click", ".add_row_img", function() {
	add_new_row('tr.bom_standard_operation_resource_assignment0', 'tbody.bom_standard_operation_resource_assignment_values', 1);
 });

 //Get the bom_standard_operation_id on refresh button click
 $('a.show.bom_standard_operation_id_show').click(function() {
	var bom_standard_operation_id = $('#bom_standard_operation_id').val();
	$(this).attr('href', '?bom_standard_operation_id=' + bom_standard_operation_id);
 });

 //right click menu
 var menuContent = "<div><ul>";
 menuContent += "<li id='menu_button1'>Export Department</li>";
 menuContent += "<li id='menu_button2'>Export Resource Assigment</li>";
 menuContent += "<li id='menu_button3'>Copy Line</li>";
 menuContent += "<div><ul>";

//rightClickMenu(menuContent);

 $("#content").on('click', '#menu_button1', function() {
	exportToExcel_fromDivId('#bom_standard_operation_resource_assignment_line', 3);
 });

 $("#content").on('click', '#menu_button2', function() {
	exportToExcel_fromDivId('#bom_standard_operation_rate_assignment_line', 3);
 });
 
 //Save record
 save('json.bom_standard_operation.php', '#bom_standard_operation', 'line_id_cb', 'resource_sequence', '#bom_standard_operation_id', '');
 
//delete line
 deleteData('json.bom_standard_operation.php');

});
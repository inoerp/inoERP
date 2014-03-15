$(document).ready(function() {
 
  var Mandatory_Fields = ["#org_id", "First Select Inventory", "#overhead", "First enter overhead"];
 select_mandatory_fields_all('#bom_overhead_divId',Mandatory_Fields);
 
 //dont allow line entry with out bom_header id
  $('#form_line').on("click", function() {
	if (!$('#bom_overhead_id').val()) {
	 alert('No header Id : First enter/save header details');
	} else {
	 var headerIdValue = $('#bom_overhead_id').val();
	 if (!$(this).find('.bom_overhead_id').val()) {
		$(this).find('.bom_overhead_id').val(headerIdValue);
	 }
	}
 });
 

 //selecting data
 $(".bom_overhead_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('find_bom_overhead.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 function setParnetWindowValues(bom_overhead_id, bom_overhead, orgId)
 {
	if ((typeof localStorage.idValue !== 'undefined') && (localStorage.idValue.length > 0)) {
	 var RowDivId = 'tr#' + localStorage.idValue;
	 window.opener.$(RowDivId).find(".bom_overhead_id").val(bom_overhead_id);
	 window.opener.$(RowDivId).find(".bom_overhead").val(bom_overhead);
	 window.opener.$(RowDivId).find(".org_id").val(orgId);
	} else {
	 window.opener.$(".bom_overhead_id").val(bom_overhead_id);
	 window.opener.$(".bom_overhead").val(bom_overhead);
	 window.opener.$(".org_id").val(orgId);
	}
 }

 $(".quick_select").on("click", function() {
	var bom_overhead_id = $(this).val();
	var bom_overhead = $(this).closest("td").siblings("td.bom_overhead").html();
	var orgId = $(this).closest("td").siblings("td.org_id").html();
	setParnetWindowValues(bom_overhead_id, bom_overhead, orgId);
	window.close();
 });

 //add new lines
 $("#content tbody.bom_overhead_resource_assignment_values").on("click", ".add_row_img", function() {
	add_new_row('tr.bom_overhead_resource_assignment0', 'tbody.bom_overhead_resource_assignment_values', 1);
 });

 $("#content tbody.bom_overhead_rate_assignment_values").on("click", ".add_row_img", function() {
	add_new_row('tr.bom_overhead_rate_assignment0', 'tbody.bom_overhead_rate_assignment_values', 1);
 });

 //Get the bom_overhead_id on refresh button click
 $('a.show.bom_overhead_id_show').click(function() {
	var bom_overhead_id = $('#bom_overhead_id').val();
	$(this).attr('href', '?bom_overhead_id=' + bom_overhead_id);
 });

 //right click menu
 var menuContent = "<div><ul>";
 menuContent += "<li id='menu_button1'>Export Resource Assigment</li>";
 menuContent += "<li id='menu_button2'>Export Rate Assigment</li>";
 menuContent += "<li id='menu_button3'>Copy Line</li>";
 menuContent += "<div><ul>";

rightClickMenu(menuContent);

 $("#content").on('click', '#menu_button1', function() {
	exportToExcel_fromDivId('#bom_overhead_resource_assignment_line', 3);
 });

 $("#content").on('click', '#menu_button2', function() {
	exportToExcel_fromDivId('#bom_overhead_rate_assignment_line', 3);
 });
 
 //Save record
 save('json.bom_overhead.php', '#bom_overhead', '', 'bom_overhead', '#bom_overhead_id', '');

//delete line
 deleteData('json.bom_overhead.php');

});



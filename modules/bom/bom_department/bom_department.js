function setValFromSelectPage(bom_department_id) {
 this.bom_department_id = bom_department_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bom_department_id = this.bom_department_id;
 $("#bom_department_id").val(bom_department_id);
};

$(document).ready(function() {

 var Mandatory_Fields = ["#org_id", "First Select BU Name", "#department", "First enter department"];
 select_mandatory_fields_all('#bom_department_divId', Mandatory_Fields);

 //dont allow line entry with out bom_header id
 $('#form_line').on("click", function() {
	if (!$('#bom_department_id').val()) {
	 alert('No header Id : First enter/save header details');
	} else {
	 var headerIdValue = $('#bom_department_id').val();
	 if (!$(this).find('.bom_department_id').val()) {
		$(this).find('.bom_department_id').val(headerIdValue);
	 }
	}
 });

 //selecting data
 $(".bom_department_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('../../../select.php?class_name=bom_department', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

// function setParnetWindowValues(bom_department_id, bom_department, orgId)
// {
//	if ((typeof localStorage.idValue !== 'undefined') && (localStorage.idValue.length > 0)) {
//	 var RowDivId = 'tr#' + localStorage.idValue;
//	 window.opener.$(RowDivId).find(".bom_department_id").val(bom_department_id);
//	 window.opener.$(RowDivId).find(".bom_department").val(bom_department);
//	 window.opener.$(RowDivId).find(".org_id").val(orgId);
//	} else {
//	 window.opener.$(".bom_department_id").val(bom_department_id);
//	 window.opener.$(".bom_department").val(bom_department);
//	 window.opener.$(".org_id").val(orgId);
//	}
// }
//
// $(".quick_select").on("click", function() {
//	var bom_department_id = $(this).val();
//	var bom_department = $(this).closest("td").siblings("td.bom_department").html();
//	var orgId = $(this).closest("td").siblings("td.org_id").html();
//	setParnetWindowValues(bom_department_id, bom_department, orgId);
//	window.close();
// });

 //add new lines
 $("#content tbody.bom_department_resource_assignment_values").on("click", ".add_row_img", function() {
	add_new_row('tr.bom_department_resource_assignment0', 'tbody.bom_department_resource_assignment_values', 1);
 });

 //Get the bom_department_id on refresh button click
 $('a.show.bom_department_id_show').click(function() {
	var bom_department_id = $('#bom_department_id').val();
	$(this).attr('href', modepath() + 'bom_department_id=' + bom_department_id);
 });

 //right click menu
 var menuContent = "<ul id='level1'>";
 menuContent += "<li id='menu_button1' class='export_excel'>Export Header</li>";
 menuContent += "<li id='menu_button2' class='end_li_type export_excel'>Export Line";
 menuContent += "<ul>";
 menuContent += "<li id='menu_button2_1' class='end_li_type export_excel'>Second Line Form</li>";
 menuContent += "</ul></li>";
 menuContent += "<li id='menu_button3' class='end_li_type print'>Print Document</li>";
 menuContent += "<li id='menu_button4' class='copy_doc'>Copy Header";
 menuContent += "<ul>";
 menuContent += "<li id='menu_button4_1' class='copy_doc'>Copy & Save Header</li>";
 menuContent += "<li id='menu_button4_2' class='copy_doc'>Copy Document";
 menuContent += "<ul>";
 menuContent += "<li id='menu_button4_1_1'>Copy & Save Document</li>";
 menuContent += "</ul></li>";
 menuContent += "</ul></li>";
 menuContent += "<li id='menu_button5' class='end_li_type copy_line'>Copy Line</li>";
 menuContent += "<li id='menu_button6' class='preference'>Preferences</li>";
 menuContent += "<li id='menu_button7' class='help help'>Help</li>";
 menuContent += "<li id='menu_button8' class='doc_history'>Document History</li>";
 menuContent += "<li id='menu_button9' class='end_li_type custom_code'>Custom Code";
 menuContent += "<ul>";
 menuContent += "<li id='menu_button9_1' class='end_li_type'>Disable</li>";
 menuContent += "<li id='menu_button9_2' class='end_li_type'>Enable</li>";
 menuContent += "<li id='menu_button9_3' class='end_li_type'>View & Update</li>";
 menuContent += "</ul></li>";
 menuContent += "<li id='menu_button10' class='about'>About inoERP</li>";
 menuContent += "<ul>";
 rightClickMenu(menuContent);

 $("#content").on('click', '#menu_button1', function() {
	var classDnldExcel = new exportToExcelMain();
	classDnldExcel.containerType = 'div';
	classDnldExcel.divId = 'bom_department';
	classDnldExcel.exportToExcel();
 });

 $("#content").on('click', '#menu_button2', function() {
	var classDnldExcel = new exportToExcelMain();
	classDnldExcel.containerType = 'table';
	classDnldExcel.divId = 'bom_department_resource_assignment_line';
	classDnldExcel.numberOfTabs = 1;
	classDnldExcel.exportToExcel();
 });

 $("#content").on('click', '#menu_button4_1_1', function() {
	alert('menu_button4_1_1 clicked')
 });

 $("#content").on('click', '#menu_button3', function() {
	window.print();
 });
 
 $("#content").on('click', '#menu_button4', function() {
	copy_document('#bom_department_id');
 });

 $("#content").on('click', '#menu_button4.1', function() {
	copy_document('#bom_department_id');
	$('#save').trigger('click');
 });


 $("#content").on('click', '#menu_button5', function() {
	trclass = '.' + $("#form_line tr:last").prop('class');
	add_new_row_withDefault(trclass, 'tbody.bom_department_resource_assignment_values', 1, '.bom_department_resource_assignment_line_id');
 });


 //Save record
// save('json.bom_department.php', '#bom_department', '', 'bom_department', '#bom_department_id', '');

 var classSave = new saveMainClass();
 classSave.json_url = 'bom_department.php';
 classSave.form_header_id = 'bom_department';
 classSave.primary_column_id = 'bom_department_id';
 classSave.line_key_field = 'resource_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'bom_department';
 classSave.lineClassName = 'bom_department_resource_assignment';
 classSave.saveMain();

//delete line
 deleteData('json.bom_department.php');

});





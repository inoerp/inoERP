function setValFromSelectPage(sys_process_flow_header_id) {
 this.sys_process_flow_header_id = sys_process_flow_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var sys_process_flow_header_id = this.sys_process_flow_header_id;
 if (sys_process_flow_header_id) {
	$('#content').find('#sys_process_flow_header_id').val(sys_process_flow_header_id);
 }
};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'process_flow_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

 //Popup for selecting process_flow
 $(".process_flow_header_id.select_popup").click(function() {
	void window.open('select.php?class_name=sys_process_flow_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the process_flow_id on find button click
 $('a.show.sys_process_flow_header_id').click(function() {
	var headerId = $('#sys_process_flow_header_id').val();
	$(this).attr('href', modepath() + 'sys_process_flow_header_id=' + headerId);
 });

 //add a new row
// onClick_add_new_row('process_flow_line', 'form_data_line_tbody', 1)
 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'process_flow_line0';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 3;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 deleteData('form.php?class_name=sys_process_flow_header&line_class_name=sys_process_flow_line');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'sys_process_flow_header_id';
 classContextMenu.docLineId = 'sys_process_flow_line_id';
 classContextMenu.btn1DivId = 'process_flow_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'sys_process_flow_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();

//get the attachement form
 deleteData('form.php?class_name=sys_process_flow_header&line_class_name=sys_process_flow_line');

// save('json.process_flow.php', '#process_flow_header', 'line_id_cb', 'component_item_id', '#process_flow_header_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=sys_process_flow_header';
 classSave.form_header_id = 'process_flow_header';
 classSave.primary_column_id = 'sys_process_flow_header_id';
 classSave.line_key_field = 'line_name';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'sys_process_flow_header';
 classSave.lineClassName = 'sys_process_flow_line';
 classSave.saveMain();
});

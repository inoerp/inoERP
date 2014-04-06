function setValFromSelectPage(bom_standard_operation_id, standard_operation) {
 this.standard_operation = standard_operation;
 this.bom_standard_operation_id = bom_standard_operation_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var standard_operation = this.standard_operation;
 var bom_standard_operation_id = this.bom_standard_operation_id;
 
 if(bom_standard_operation_id){
	$("#bom_standard_operation_id").val(bom_standard_operation_id);
 }
  if(standard_operation){
	$("#standard_operation").val(standard_operation);
 }
};

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
 $(".bom_standard_operation_id.select_popup").on("click", function() {
		void window.open('select.php?class_name=bom_standard_operation', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//add new lines
 $("#content tbody.form_data_line_tbody").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'bom_standard_operation_resource_assignment';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });
 
  //Get the bom_standard_operation_id on refresh button click
 $('a.show.bom_standard_operation_id_show').click(function() {
	var bom_standard_operation_id = $('#bom_standard_operation_id').val();
	$(this).attr('href', modepath() + 'bom_standard_operation_id=' + bom_standard_operation_id);
 });

 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'bom_standard_operation_id';
 classContextMenu.docLineId = 'bom_standard_operation';
 classContextMenu.btn1DivId = 'ar_transaction_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'bom_standard_operation';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
 classContextMenu.contextMenu();
 
 
  var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=bom_standard_operation';
 classSave.form_header_id = 'bom_standard_operation';
 classSave.primary_column_id = 'bom_standard_operation_id';
 classSave.line_key_field = 'resource_sequence';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'bom_standard_operation';
 classSave.lineClassName = 'bom_standard_operation_resource_assignment';
 classSave.enable_select = true;
 classSave.saveMain();


//Save record
// save('json.bom_standard_operation.php', '#bom_standard_operation', 'line_id_cb', 'resource_sequence', '#bom_standard_operation_id', '');

//delete line
 deleteData('json.bom_standard_operation.php');

});
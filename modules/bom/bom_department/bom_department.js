function setValFromSelectPage(bom_department_id) {
 this.bom_department_id = bom_department_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bom_department_id = this.bom_department_id;
 $("#bom_department_id").val(bom_department_id);
};

$(document).ready(function() {

 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_department_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "department"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No department"];
// mandatoryCheck.mandatoryField();

 //selecting data
 $(".bom_department_id.select_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=bom_department', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //add new lines
 $("#content tbody.form_data_line_tbody").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'bom_department_resource_assignment';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 //Get the bom_department_id on refresh button click
 $('a.show.bom_department_id_show').click(function() {
	var bom_department_id = $('#bom_department_id').val();
	$(this).attr('href', modepath() + 'bom_department_id=' + bom_department_id);
 });


 //Save record

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=bom_department';
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





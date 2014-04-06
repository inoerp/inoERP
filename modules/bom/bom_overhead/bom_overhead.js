function setValFromSelectPage(org_id, bom_overhead_id, overhead, combination) {
 this.org_id = org_id;
 this.bom_overhead_id = bom_overhead_id;
 this.overhead = overhead;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var org_id = this.org_id;
 var overhead = this.overhead;
 var bom_overhead_id = this.bom_overhead_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');

 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }

 if (org_id) {
	$("#org_id").val(org_id);
 }
 if (bom_overhead_id) {
	$("#bom_overhead_id").val(bom_overhead_id);
 }
 if (overhead) {
	$("#overhead").val(overhead);
 }
};

$(document).ready(function() {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_overhead_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "overhead"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Overhead"];
// mandatoryCheck.mandatoryField();

//selecting data
 $(".bom_overhead_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=bom_overhead', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//add new lines
 $("#content tbody.form_data_line_tbody").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'bom_overhead_resource_assignment';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'bom_overhead_rate_assignment';
	addNewRow.tbodyClass = 'form_data_line_tbody2';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 //Get the bom_overhead_id on refresh button click
 $('a.show.bom_overhead_id_show').click(function() {
	var bom_overhead_id = $('#bom_overhead_id').val();
	$(this).attr('href', modepath() + 'bom_overhead_id=' + bom_overhead_id);
 });

//Save record
// save('json.bom_overhead.php', '#bom_overhead', '', 'bom_overhead', '#bom_overhead_id', '');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=bom_overhead';
 classSave.form_header_id = 'bom_overhead';
 classSave.primary_column_id = 'bom_overhead_id';
 classSave.line_key_field = 'resource_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'bom_overhead';
 classSave.lineClassName = 'bom_overhead_resource_assignment';
 classSave.lineClassName2 = 'bom_overhead_rate_assignment';
 classSave.enable_select = true;
 classSave.saveMain();


//delete line
 deleteData('json.bom_overhead.php');

});



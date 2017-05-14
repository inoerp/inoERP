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
    if (this.bom_overhead_id) {
  $('a.show.bom_overhead_id').trigger('click');
 }

};

$(document).ready(function() {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_overhead_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "overhead"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Overhead"];
// mandatoryCheck.mandatoryField();

//selecting data
 $(".bom_overhead_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=bom_overhead', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 
  $("#content tbody.form_data_line_tbody2").off("click", ".add_row_img").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'bom_oh_rate_assignment';
	addNewRow.tbodyClass = 'form_data_line_tbody2';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

});
function setValFromSelectPage(bom_department_id) {
 this.bom_department_id = bom_department_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bom_department_id = this.bom_department_id;
 $("#bom_department_id").val(bom_department_id);
 
     if (this.bom_department_id) {
  $('a.show.bom_department_id').trigger('click');
 }
};

$(document).ready(function() {

 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_department_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "department"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No department"];
// mandatoryCheck.mandatoryField();

 //selecting data
 $(".bom_department_id.select_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=bom_department', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});





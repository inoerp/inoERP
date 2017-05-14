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
     if (this.bom_standard_operation_id) {
  $('a.show.bom_standard_operation_id').trigger('click');
 }
};

$(document).ready(function() {
  var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_standard_operation_id';
 mandatoryCheck.mandatoryHeader();
 
 //selecting data
 $(".bom_standard_operation_id.select_popup").on("click", function() {
		void window.open('select.php?class_name=bom_standard_operation', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});
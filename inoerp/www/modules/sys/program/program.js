function setValFromSelectPage(sys_program_id) {
 this.sys_program_id = sys_program_id;
 }

setValFromSelectPage.prototype.setVal = function() {
  if (this.sys_program_id) {
	$("#sys_program_id").val(this.sys_program_id);
 }
 };

$(document).ready(function() {
 //controlling program type values - what can be entered
  $(".program_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sys_program', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


});
function setValFromSelectPage(program_id) {
 this.program_id = program_id;
 }

setValFromSelectPage.prototype.setVal = function() {
 var program_id = this.program_id;
 if (program_id) {
	$("#program_id").val(program_id);
 }
 };

$(document).ready(function() {
 //controlling program type values - what can be entered
  $(".program_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=program', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the program_id on find button click
 $('a.show.program_id').click(function(e) {
	var program_id = $('#program_id').val();
	$(this).attr('href', modepath() + 'program_id=' + program_id);
 });


 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'program_id';
 classContextMenu.btn1DivId = 'program_id';
 classContextMenu.contextMenu();

});
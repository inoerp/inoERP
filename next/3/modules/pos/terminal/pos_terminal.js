function setValFromSelectPage(pos_terminal_id) {
 this.pos_terminal_id = pos_terminal_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var pos_terminal_id = this.pos_terminal_id;
 if (pos_terminal_id) {
	$("#pos_terminal_id").val(pos_terminal_id);
 }
};

$(document).ready(function() {

 //selecting Id
 $("#pos_terminal_divId").off("click", '.pos_terminal.select_popup')
         .on("click", '.pos_terminal.select_popup' , function() {
	void window.open('select.php?class_name=pos_terminal', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
});


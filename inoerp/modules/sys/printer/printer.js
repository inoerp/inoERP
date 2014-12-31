function setValFromSelectPage(sys_printer_id) {
 this.sys_printer_id = sys_printer_id;
}


setValFromSelectPage.prototype.setVal = function() {
 if (this.sys_printer_id) {
	$("#sys_printer_id").val(this.sys_printer_id);
 }
};

$(document).ready(function() {
 //selecting Id
 $(".sys_printer_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sys_printer', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

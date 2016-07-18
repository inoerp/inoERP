function setValFromSelectPage(bc_label_request_id) {
 this.bc_label_request_id = bc_label_request_id;
}


setValFromSelectPage.prototype.setVal = function() {
 if (this.bc_label_request_id) {
	$("#bc_label_request_id").val(this.bc_label_request_id);
 }
};

$(document).ready(function() {
 //selecting Id
 $(".bc_label_request_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=bc_label_request', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
});

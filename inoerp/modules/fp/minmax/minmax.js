function setValFromSelectPage(fp_minmax_header_id) {
 this.fp_minmax_header_id = fp_minmax_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var fp_minmax_header_id = this.fp_minmax_header_id;
 if (fp_minmax_header_id) {
	$("#fp_minmax_header_id").val(fp_minmax_header_id);
 }
};

$(document).ready(function() {

 //selecting Id
 $("#fp_minmax_header_divId").off("click", '.fp_minmax_header.select_popup')
         .on("click", '.fp_minmax_header.select_popup' , function() {
	void window.open('select.php?class_name=fp_minmax_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
});


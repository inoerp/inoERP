function setValFromSelectPage(fp_mrp_header_id) {
 this.fp_mrp_header_id = fp_mrp_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var fp_mrp_header_id = this.fp_mrp_header_id;
 if (fp_mrp_header_id) {
	$("#fp_mrp_header_id").val(fp_mrp_header_id);
 }
};

$(document).ready(function() {

 //selecting Id
 $("#fp_mrp_header_divId").off("click", '.fp_mrp_header.select_popup')
         .on("click", '.fp_mrp_header.select_popup' , function() {
	void window.open('select.php?class_name=fp_mrp_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 });


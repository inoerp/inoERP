function setValFromSelectPage(fp_minmax_header_id) {
 this.fp_minmax_header_id = fp_minmax_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var fp_minmax_header_id = this.fp_minmax_header_id;
 if (fp_minmax_header_id) {
	$("#fp_minmax_header_id").val(fp_minmax_header_id);
  $('a.show.fp_minmax_header_id').trigger('click');
 }
};

$(document).ready(function() {

 //selecting Id
 $("#fp_minmax_header_divId").off("click", '.fp_minmax_header_id.select_popup')
         .on("click", '.fp_minmax_header_id.select_popup' , function() {
	void window.open('select.php?class_name=fp_minmax_header', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
});


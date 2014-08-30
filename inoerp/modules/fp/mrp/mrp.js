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
 $(".fp_mrp_header.select_popup").on("click", function() {
	void window.open('select.php?class_name=fp_mrp_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
  //Get the header id on find button click
  $('a.show.fp_mrp_header_id').click(function() {
    var fp_mrp_header_id = $('#fp_mrp_header_id').val();
    $(this).attr('href', modepath() + 'fp_mrp_header_id=' + fp_mrp_header_id);
  });
	
	 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'fp_mrp_header_id';
 classContextMenu.btn1DivId = 'fp_mrp_header_id';
 classContextMenu.contextMenu();


 
 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=fp_mrp_header';
 classSave.form_header_id = 'fp_mrp_header';
 classSave.primary_column_id = 'fp_mrp_header_id';
  classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = 'fp_mrp_header';
 classSave.saveMain();

});


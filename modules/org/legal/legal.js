function setValFromSelectPage(legal_id) {
 this.legal_id = legal_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var legal_id = this.legal_id;
 if (legal_id) {
	$("#legal_id").val(legal_id);
 }
};

$(document).ready(function() {
 
  //selecting Id
 $(".legal.select_popup").on("click", function() {
	void window.open('select.php?class_name=legal', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
  //Get the business_id on find button click
  $('#form_header a.show').click(function() {
    var business_id = $('#business_id').val();
    $(this).attr('href', modepath() + 'business_id=' + business_id);
  });

 //Get the legal_id on find button click
  $('#form_header a.show').click(function() {
    var legalId = $('#legal_id').val();
    $(this).attr('href', modepath() + 'legal_id=' + legalId );
  });

	 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'legal_id';
 classContextMenu.btn1DivId = 'legal_id';
 classContextMenu.contextMenu();


 
 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=legal';
 classSave.form_header_id = 'legal';
 classSave.primary_column_id = 'legal_id';
  classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = 'legal';
 classSave.saveMain();

});


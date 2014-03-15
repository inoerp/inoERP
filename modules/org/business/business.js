function setValFromSelectPage(business_id) {
 this.business_id = business_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var business_id = this.business_id;
 if (business_id) {
	$("#business_id").val(business_id);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".business.select_popup").on("click", function() {
	void window.open('select.php?class_name=business', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the business_id on find button click
  $('#form_header a.show').click(function() {
    var business_id = $('#business_id').val();
    $(this).attr('href', modepath() + 'business_id=' + business_id);
  });

	 	 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'business_id';
 classContextMenu.btn1DivId = 'business_id';
 classContextMenu.contextMenu();


 
 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=business';
 classSave.form_header_id = 'business';
 classSave.primary_column_id = 'business_id';
  classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = 'business';
 classSave.saveMain();


});


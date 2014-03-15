function setValFromSelectPage(address_id) {
 this.address_id = address_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var address_id = this.address_id;
 if (address_id) {
	$("#address_id").val(address_id);
 }
};

$(document).ready(function() {

 //selecting Id
 $(".address.select_popup").on("click", function() {
	void window.open('select.php?class_name=address', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
  //Get the header id on find button click
  $('a.show.address_id').click(function() {
    var address_id = $('#address_id').val();
    $(this).attr('href', modepath() + 'address_id=' + address_id);
  });
	
	 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'address_id';
 classContextMenu.btn1DivId = 'address_id';
 classContextMenu.contextMenu();


 
 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=address';
 classSave.form_header_id = 'address';
 classSave.primary_column_id = 'address_id';
  classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = 'address';
 classSave.saveMain();

});


function setValFromSelectPage(address_id, tax_region_name) {
 this.address_id = address_id;
 this.tax_region_name = tax_region_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var address_id = this.address_id;
 var tax_region_name = this.tax_region_name;
 
 if (tax_region_name) {
	$("#tax_region_name").val(tax_region_name);
 }
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

 //Tax Region Id
 $(".tax_region_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=mdm_tax_region', '_blank',
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


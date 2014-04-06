function setValFromSelectPage(org_id, bom_resource_id, bom_resource, combination) {
 this.org_id = org_id;
 this.bom_resource_id = bom_resource_id;
 this.combination = combination;
 this.bom_resource = bom_resource;
}

setValFromSelectPage.prototype.setVal = function() {
 var org_id = this.org_id;
 var bom_resource = this.bom_resource;
 var address_id = this.address_id;
 
 if (org_id) {
	$("#org_id").val(org_id);
 }
 if (bom_resource_id) {
	$("#bom_resource_id").val(bom_resource_id);
 }
  if (bom_resource) {
	$("#bom_resource").val(bom_resource);
 }
};


$(document).ready(function() {
 //selecting data
 $(".bom_resource_id.select_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=bom_resource', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //Get the bom_resource_id on refresh button click
 $('a.show.bom_resource_id_show').click(function() {
	var bom_resource_id = $('#bom_resource_id').val();
	$(this).attr('href', modepath() + 'bom_resource_id=' + bom_resource_id);
	 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'bom_resource_id';
 classContextMenu.btn1DivId = 'bom_resource_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=bom_resource';
 classSave.form_header_id = 'bom_resource';
 classSave.primary_column_id = 'bom_resource_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'bom_resource';
 classSave.saveMain();

});



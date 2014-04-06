function setValFromSelectPage(org_id, bom_material_element_id, material_element) {
 this.org_id = org_id;
 this.bom_material_element_id = bom_material_element_id;
 this.material_element = material_element;
}

setValFromSelectPage.prototype.setVal = function() {
 var org_id = this.org_id;
 var material_element = this.material_element;
 var bom_material_element_id = this.bom_material_element_id;
 
 if (org_id) {
	$("#org_id").val(org_id);
 }
 if (bom_material_element_id) {
	$("#bom_material_element_id").val(bom_material_element_id);
 }
  if (material_element) {
	$("#material_element").val(material_element);
 }
};


$(document).ready(function() {
 //selecting data
 $(".bom_material_element_id.select_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=bom_material_element', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //Get the bom_material_element_id on refresh button click
 $('a.show.bom_material_element_id_show').click(function() {
	var bom_material_element_id = $('#bom_material_element_id').val();
	$(this).attr('href', modepath() + 'bom_material_element_id=' + bom_material_element_id);
	 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'bom_material_element_id';
 classContextMenu.btn1DivId = 'bom_material_element_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=bom_material_element';
 classSave.form_header_id = 'bom_material_element';
 classSave.primary_column_id = 'bom_material_element_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'bom_material_element';
 classSave.saveMain();

});



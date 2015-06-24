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
   if (this.bom_material_element_id) {
  $('a.show.bom_material_element_id').trigger('click');
 }
};


$(document).ready(function() {
 
   var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_resource_id';
 mandatoryCheck.mandatoryHeader();
 
 //selecting data
 $(".bom_material_element_id.select_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=bom_material_element', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

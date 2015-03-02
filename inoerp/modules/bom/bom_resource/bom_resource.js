function setValFromSelectPage(org_id, bom_resource_id, bom_resource, combination) {
 this.org_id = org_id;
 this.bom_resource_id = bom_resource_id;
 this.combination = combination;
 this.bom_resource = bom_resource;
}

setValFromSelectPage.prototype.setVal = function() {
 if (this.org_id) {
  $("#org_id").val(this.org_id);
 }
 if (this.bom_resource_id) {
  $("#bom_resource_id").val(this.bom_resource_id);
 }
 if (this.bom_resource) {
  $("#bom_resource").val(this.bom_resource);
 }
 if (this.combination) {
  var fieldClass = '.' + localStorage.getItem("field_class").replace(/\s+/g, '.')
  $('#content').find(fieldClass).val(this.combination);
  localStorage.removeItem("field_class");
 }
  if (this.bom_resource_id) {
  $('a.show.bom_resource_id').trigger('click');
 }
 
};


$(document).ready(function() {
 
  var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_resource_id';
 mandatoryCheck.mandatoryHeader();


 //selecting data
 $(".bom_resource_id.select_popup").on("click", function() {
  localStorage.idValue = "";
  void window.open('select.php?class_name=bom_resource', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});
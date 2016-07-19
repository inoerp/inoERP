function setValFromSelectPage(address_name) {
 this.address_name = address_name;
}

setValFromSelectPage.prototype.setVal = function () {
 var address_name = this.address_name;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (address_name) {
  $("#content").find(fieldClass).val(address_name);
 }
};


$(document).ready(function () {

 //Get the sd_shipping_control_id on find button click
 $('a.show.org_id').click(function () {
  var org_id = $('#org_id').val();
  $(this).attr('href', modepath() + 'org_id=' + org_id);
 });

 //get subinventories on selecting org
 $('#content').on('blur', '#org_id', function () {
  var org_id = $(this).val();
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: org_id
  });
 });

 $('#content').on('blur', '.subinventory_id', function () {
  var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', '.form_line');
 });


 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'sd_shipping_control_id';
 classContextMenu.btn1DivId = 'sd_shipping_control_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=sd_shipping_control';
 classSave.form_header_id = 'sd_shipping_control';
 classSave.primary_column_id = 'sd_shipping_control_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'sd_shipping_control';
 classSave.saveMain();


});


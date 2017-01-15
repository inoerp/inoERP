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

 //get subinventories on selecting org
 $('#content').off('blur', '#legal_org_id').on('blur', '#legal_org_id', function () {
  var legal_org_id = $(this).val();
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   legal_org_id: legal_org_id
  });
 });

 $('#content').off('blur', '.subinventory_id').on('blur', '.subinventory_id', function () {
  var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', '.form_line');
 });

});
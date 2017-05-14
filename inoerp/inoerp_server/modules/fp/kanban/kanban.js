
$(document).ready(function () {
  //get Subinventory Name
 $('#org_id').getSubInventoryFromOrg({
  subinventory_class: '.subinventory_id'
 });

 $('#from_org_id').getSubInventoryFromOrg({
  subinventory_class: '.from_subinventory_id'
 });
 
  $('body').off('blur', '#kanban_subinventory_id').on("change", "#kanban_subinventory_id", function () {
  getLocator('modules/inv/locator/json_locator.php', $(this).val(), 'oneToOneSubinventory', '.locator_id.kanban_subinventory_id');
 });
 
   $('body').off('blur', '#from_subinventory_id').on("change", "#from_subinventory_id", function () {
    getLocator('modules/inv/locator/json_locator.php', $(this).val(), 'oneToOneSubinventory', '.locator_id.from_subinventory_id');
 });

get_supplier_detail_for_bu(true);

});


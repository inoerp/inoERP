$(document).ready(function () {

//
 $('body').off('change', '#org_id').on('change', '#org_id', function () {
  $('#current_org_id').val($(this).val());
 });

 //get Subinventory Name
 $('body').off('change', '#scope_org_id').on("change", '#scope_org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: val($("#scope_org_id").val())
  });
 });

});

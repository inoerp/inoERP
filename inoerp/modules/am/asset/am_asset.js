function setValFromSelectPage(am_asset_id, asset_number, item_id_m, item_number, item_description) {
 this.am_asset_id = am_asset_id;
 this.asset_number = asset_number;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
}

setValFromSelectPage.prototype.setVal = function () {
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');

 if (this.am_asset_id) {
  $("#am_asset_id").val(this.am_asset_id);
 }
 if (this.asset_number) {
  $("#asset_number").val(this.asset_number);
 }

 var item_obj = [{id: 'item_id_m', data: this.item_id_m},
  {id: 'item_number', data: this.item_number},
  {id: 'item_description', data: this.item_description},
  {id: 'uom', data: this.uom_id},
  {id: 'processing_lt', data: this.processing_lt}
 ];


 localStorage.removeItem("row_class");

};



$(document).ready(function () {

 //selecting Id
 $(".am_asset_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=am_asset', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 var select_item_number_am_asset_item_options = {'am_asset_type': 'ASSET_ITEM'};
 $('.select_item_number_am_asset_item').inoAutoCompleteElement({
  json_url: 'modules/inv/item/json_item.php',
  primary_column1: 'org_id',
  other_options: select_item_number_am_asset_item_options
 });

 //get Subinventory Name
 $('body').off("change", '#org_id').on("change", '#org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $("#org_id").val()
  });
 });


 //get locatot on Subinventory change in form header
 $('body').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var subInventoryId = $(this).val();
  if (subInventoryId > 0) {
   getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'oneSubinventory', '');
  }
 });

});


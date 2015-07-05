function setValFromSelectPage(item_id_m, item_number, address_id, address_name, address) {
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.address_id = address_id;
 this.address_name = address_name;
 this.address = address;
}

setValFromSelectPage.prototype.setVal = function () {
 var rowClass = '.' + localStorage.getItem("row_class").replace(/\s+/g, '.')
 if (this.item_id_m) {
  $('#content').find(rowClass).find('.item_id_m').val(this.item_id_m);
 }
 if (this.item_number) {
  $('#content').find(rowClass).find('.item_number').val(this.item_number);
 }

 var addressPopupDivClass = '.' + localStorage.getItem("addressPopupDivClass");
 addressPopupDivClass = addressPopupDivClass.replace(/\s+/g, '.');
 if (this.address_id) {
  $('#form_header').find(addressPopupDivClass).find('.address_id').val(this.address_id);
 }
 if (this.address_name) {
  $('#form_header').find(addressPopupDivClass).find('.address_name').val(this.address_name);
 }
 if (this.address) {
  $('#form_header').find(addressPopupDivClass).find('.address').val(this.address);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("addressPopupDivClass");
};

$(document).ready(function () {
//get locators on changing sub inventory
 $('body').off('change', '.subinventory_id')
         .on('change', '.subinventory_id', function () {
          var trClass = '.' + $(this).closest('tr').attr('class');
          var subinventory_value = $(this).val();
          getLocator('modules/inv/locator/json_locator.php', subinventory_value, 'subinventory', trClass);
         });

//get Subinventory Name
 $('body').off("change", '#org_id').on("change", '#org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $(this).val()
  });
 });

 });  
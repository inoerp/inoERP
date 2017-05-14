function beforeSave() {
 var showWarning = false;
 $('.demand_quantity').each(function () {
  rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  if (!($(rowClass_d).find('.reservable_onhand') > $(this).val())) {
   alert('Noe enough onhand available for reservation');
   returrn - 90;
  }
 });
}

$(document).ready(function () {

 $('body').off('change', '.locator_id').on('change', '.locator_id', function () {
  rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  $(rowClass_d).find('.current_locator_id').val($(this).val());
 });

 $('body').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  $(rowClass_d).find('.current_subinventory_id').val($(this).val());
 });

 $('body').off('blur', '.item_number').on('blur', '.item_number', function () {
  rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  var item_id_m = $(rowClass_d).find('.item_id_m').val();
  $(rowClass_d).find('.item_id_m').val(item_id_m);
 });

 $('body').off('blur', '.so_number').on('blur', '.so_number', function () {
  rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  var sd_so_header_id = $(rowClass_d).find('.sd_so_header_id').val();
  $(rowClass_d).find('.sd_so_header_id_popup').val(sd_so_header_id);
 });

 //get Subinventory Name
 $('body').off("change", '.org_id_primary').on("change", '.org_id_primary', function () {
  rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $(this).val(),
   rowClass_d: rowClass_d
  });
  $(rowClass_d).find('.org_id').val($(this).val());
 });


 //get locatot on Subinventory change in form header
 $('#form_line').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var subInventoryId = $(this).val();
  if (subInventoryId > 0) {
   rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
   getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'subinventory', rowClass_d);
  }
 });

//reservation
$('#form_line').off("blur", '.serial_number').on("blur", '.serial_number', function () {
  if($(this).val()){
       rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g,'.');
       $(rowClass_d).find('.demand_quantity').val(1);
     
  }
});


//get onhand
 $('body').off('change', '.subinventory_id, .locator_id')
         .on('change', '.subinventory_id, .locator_id', function () {
          rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
          getOnhandDetails({
           item_id_m: $(rowClass_d).find('.item_id_m').val(),
           org_id: $(rowClass_d).find('.org_id').val(),
           subinventory_id: $(rowClass_d).find('.subinventory_id').val(),
           locator_id: $(rowClass_d).find('.locator_id').val(),
           trClass: rowClass_d
          });
         });
});




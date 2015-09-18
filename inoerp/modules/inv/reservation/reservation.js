function beforeSave() {
 if ($('#reservable_onhand').val() > $('#demand_quantity').val()) {
  return 1;
 } else {
  alert('Noe enough onhand available for reservation');
  return -90;
 }
}

$(document).ready(function () {

 $('body').off('blur', '#item_number').on('blur', '#item_number', function () {
  $('.item_id_m').val($('#item_id_m').val());
 });

 $('body').off('change', '#locator_id').on('change', '#locator_id', function () {
  $('.current_locator_id').val($('#locator_id').val());
 });
 
  $('body').off('change', '#subinventory_id').on('change', '#subinventory_id', function () {
  $('.current_subinventory_id').val($('#subinventory_id').val());
 });

 $('body').off('blur', '#so_number').on('blur', '#so_number', function () {
  $('.sd_so_header_id_popup').val($('#sd_so_header_id').val());
 });

 //get Subinventory Name
 $('body').off("change", '#org_id').on("change", '#org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $("#org_id").val()
  });
  $('.org_id').val($(this).val());
 });

 //get locatot on Subinventory change in form header
 $('#form_line').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var subInventoryId = $(this).val();
  if (subInventoryId > 0) {
   getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'oneSubinventory', '');
  }
 });

$('#form_line').off("blur", '#serial_number').on("blur", '#serial_number', function () {
  if($(this).val()){
       $('#demand_quantity').val(1);
     
  }
});

//get onhand
 $('body').off('change', '#subinventory_id, #locator_id')
         .on('change', '#subinventory_id, #locator_id', function () {
          getOnhandDetails({
           item_id_m: $('#item_id_m').val(),
           org_id: $('#org_id').val(),
           subinventory_id: $('#subinventory_id').val(),
           locator_id: $('#locator_id').val()
          });
         });
});




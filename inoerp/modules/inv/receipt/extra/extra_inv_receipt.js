function beforeSave() {
 return lotSerial_quantityValidation({
  quantity_divClass: '.transaction_quantity'
 });
}

$(document).ready(function () {

$('#searchForm.po_all_v').find('#org_id').attr('required', true).css('background-color', 'pink');

 var org_id = $('.org_id').first().val();
 var subinvetory_field = $('<select class="select subinventory_id" name="subinventory_id[]"></select>');
 $('.subinventory_id').replaceWith(subinvetory_field);
 getSubInventory({
  json_url: 'modules/inv/subinventory/json_subinventory.php',
  org_id: org_id
 });

 //get locators on changing sub inventory
 $('#content').on('change', '.subinventory_id', function () {
  var locator_field = $('<select class="select locator_id" name="locator_id[]">');
  $(this).closest('tr').find('.locator_id').replaceWith(locator_field);
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', trClass);
 });

 $('#multi_select').on('click', '.subinventory_id', function () {
  if ($(this).find('option').length < 1) {
   var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
   getSubInventory({
    json_url: 'modules/inv/subinventory/json_subinventory.php',
    org_id: $('#multi_select').find(trClass).find('.receving_org_id').val(),
    rowClass_d: trClass
   });
  }
 });

 addOrShow_lineDetails('tr.multi_select_value_line0');
 onClick_addDetailLine(2, '.add_row_detail_img1');
 onClick_addDetailLine(1, '.add_row_detail_img0');

//add default values on line
 $('#form_line').on('click', '.line_id_cb', function () {
  if ($(this).prop('checked')) {
   var trclass = '.' + $(this).closest('tr').prop('class');
   var quantity = (+$(this).closest('tr').find('.line_quantity').val()) - (+$(this).closest('.tabContainer').find(trclass).find('.invoiced_quantity').val());
   $(this).closest('tr').find('.inv_line_quantity').val(quantity);
   var unit_prices = $(this).closest('.tabContainer').find(trclass).find('.unit_price').val();
   $(this).closest('tr').find('.inv_unit_price').val(unit_prices);
   var inv_line_type = "<select id='account_type' class=' select account_type ' name='account_type[]'>";
   inv_line_type += "<option value=''></option>";
   inv_line_type += "<option selected value='ITEM'>Item</option>";
   inv_line_type += "<option value='TAX'>Tax</option>";
   inv_line_type += "<option value='MISC'>Miscellaneous</option>";
   inv_line_type += "<option value='FREIGHT'>Freight</option>";
   inv_line_type += "</selction>";
   $(this).closest('tr').find('.inv_line_type').replaceWith(inv_line_type);
  } else {
   $(this).closest('tr').find('.inv_line_quantity').val('');
   $(this).closest('tr').find('.inv_unit_price').val('');
   $(this).closest('tr').find('.inv_line_type').val('');
   $(this).closest('tr').find('.inv_line_price').val('');
  }
 });

 $('#form_line').on('blur', '.inv_line_quantity, .inv_unit_price, .inv_line_price ', function () {
  var quantity = +$(this).closest('tr').find('.inv_line_quantity').val();
  var unit_prices = +$(this).closest('tr').find('.inv_unit_price').val();
  $(this).closest('tr').find('.inv_line_price').val(quantity * unit_prices);
 });

$('#content').find('tr').each(function(){
var serial_generation_v = $(this).find('.serial_generation').first().val();
var lot_generation_v = $(this).find('.lot_generation').first().val();
  if(serial_generation_v){
  var trClass = '.' + $(this).attr('class').replace(/\+g/,'.');
   $('#content').find(trClass).find('.serial_generation').val(serial_generation_v);
  }
  
    if(lot_generation_v){
  var trClass = '.' + $(this).attr('class').replace(/\+g/,'.');
   $('#content').find(trClass).find('.lot_generation').val(lot_generation_v);
  }
});

 $('#content').on('blur', '.subinventory_id, .locator_id', function () {
  var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
  var trClass_d = '.' + trClass;
  var generation_type = $('#content').find(trClass_d).find('.serial_generation').val();

  if (!generation_type) {
   var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
   $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
   $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
//   alert('Item is not serial controlled.\nNo serial informatio \'ll be saved in database');
   return;
  } else if (generation_type != 'PRE_DEFINED') {
   var field_stmt = '<input class="textfield serial_number" type="text" size="25" name="serial_number[]" >';
   $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
   $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
  }
  var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
  if (!itemIdM) {
   return;
  }

  if (generation_type === 'PRE_DEFINED') {
   getSerialNumber({
    'org_id': $('#org_id').val(),
    'status': 'DEFINED',
    'item_id_m': itemIdM,
    'trclass': trClass
   });
  }

 });

 $('#content').on('blur', '.subinventory_id, .locator_id', function () {
  var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
  var trClass_d = '.' + trClass;
  var generation_type = $('#content').find(trClass_d).find('.lot_generation').val();

  if (!generation_type) {
   var field_stmt = '<input class="textfield lot_number" type="text" size="25" readonly name="lot_number[]" >';
   $('#content').find(trClass_d).find('.inv_lot_number_id').replaceWith(field_stmt);
   $('#content').find(trClass_d).find('.lot_number').replaceWith(field_stmt);
//   alert('Item is not lot controlled.\nNo lot information \'ll be saved in database');
   return;
  }
  var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
  if (!itemIdM) {
   return;
  }

  switch ($('#transaction_type_id').val()) {
   case '5' :
    if (generation_type === 'PRE_DEFINED') {
     $.when(getlotNumber({
      'org_id': $('#org_id').val(),
      'status': 'ACTIVE',
      'item_id_m': itemIdM,
      'trclass': trClass
     })).then(function (data, textStatus, jqXHR) {
      if ($.trim(data) == 'false' || $.trim(data) == 'undefined') {
       alert('No lot Number Found!\nCheck the subinventory, locator and item number');
      }
     });
    }
    break;

   case '21' :
    var subinventory_id = $('#content').find(trClass_d).find('.subinventory_id').val();
    if (!subinventory_id) {
     alert('No from subinventory');
     return;
    }
    $.when(getlotNumber({
     'org_id': $('#org_id').val(),
     'status': 'ACTIVE',
     'item_id_m': itemIdM,
     'trclass': trClass,
     'subinventory_id': subinventory_id,
     'locator_id': $('#content').find(trClass_d).find('.locator_id').val(),
    })).then(function (data, textStatus, jqXHR) {
     if ($.trim(data) == 'false' || $.trim(data) == 'undefined') {
      alert('No lot Number Found!\nCheck the subinventory, locator and item number');
     }
    });
    break;

   case 'undefined' :
   case '' :
    alert('Enter the transaction type');
    break;
  }
  $('#content').find(trClass_d).find('.lot_number, .inv_lot_number_id').attr('required', true).css('background-color', 'pink');
 });

});

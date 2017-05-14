

function beforeSave() {
 return lotSerial_quantityValidation();
}

//Popup for adding interorg_transfer lines
function add_interorg_transfer_lines() {
 var inv_interorg_transfer_header_id = $("#inv_interorg_transfer_header_id").val();
 if (inv_interorg_transfer_header_id) {
  var link = 'multi_select.php?class_name=po_all_v&action=multi_interorg_transfer&mode=9&action_class_name=inv_interorg_transfer_line&';
  link += 'po_status=APPROVED&inv_interorg_transfer_header_id=' + inv_interorg_transfer_header_id + '&org_id=' + $('#org_id').val();
  localStorage.removeItem("reset_link");
  localStorage.setItem("reset_link", link);
  localStorage.removeItem("jsfile");
  localStorage.setItem("jsfile", "modules/inv/interorg_transfer/extra/extra_inv_interorg_transfer.js");
  void window.open(link, '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 } else {
  alert('No interorg_transfer Header ID/nEnter or Save The Header Details ');
 }
}

$(document).ready(function () {
//tr readonly
$("[data-line_status='RECEIVED']").find(':input').prop('readonly', 'readonly').addClass('readonly');

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }
//update line action
 $('body').off('change', '#action').on('change', '#action', function () {
  if ($('#form_line').find("input[name='line_id_cb']:checked").length > 0) {
   var trClass = '.' + $('#form_line').find("input[name='line_id_cb']:checked").closest('tr').prop('class').replace(/\s+/g, '.');
   $('#form_line').find(trClass).find('.action').val($(this).val());
  }
 });

//verify entered qty is less than open quantity
 $('body').off('change', '.received_quantity').on('change', '.received_quantity', function () {
  var newQty = $(this).val();
  var shipmentQty = $(this).closest('tr').find('.quantity').val();
  var poReceivedQty = $(this).closest('tr').find('.po_received_quantity').val();
  if ((+poReceivedQty + +newQty) > shipmentQty) {
   alert('Entered quantity is more than open quantity!');
   $(this).val('');
   $(this).focus();
  }
 });

//Default header values to line
 $('body').off('change', '.transaction_quantity').on('change', '.transaction_quantity', function () {
  var trClass = '.' + $(this).closest('tr').prop('class');
  trClass = trClass.replace(/\s+/g, '.');
  $(this).closest('.tabContainer').find(trClass).find('.transaction_type_id').val($('#transaction_type_id').val());
  $(this).closest('.tabContainer').find(trClass).find('.org_id').val($('#org_id').val());
  $(this).closest('.tabContainer').find(trClass).find('.inv_interorg_transfer_header_id').val($('#inv_interorg_transfer_header_id').val());
 });


// //get locators on changing sub inventory
 $('body').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_id = $(this).val();
  var subinventory = 'subinventory_id';
  if ($(this).hasClass('from_subinventory_id')) {
   subinventory = 'from_subinventory_id';
  } else if ($(this).hasClass('to_subinventory_id')) {
   subinventory = 'to_subinventory_id';
  }
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory, trClass);
 });


//get Subinventory Name
 $('#from_org_id').getSubInventoryFromOrg({
  subinventory_class: '.from_subinventory_id',
 });

 $('#to_org_id').getSubInventoryFromOrg({
  subinventory_class: '.to_subinventory_id',
 });

 //selecting Header Id
 $(".inv_interorg_transfer_header_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=inv_interorg_transfer_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 //Get the interorg_transfer_id on find button click
// $('a.show.inv_interorg_transfer_header').click(function() {
//  var interorg_transferId = $('#inv_interorg_transfer_header_id').val();
//  $(this).attr('href', modepath() + 'inv_interorg_transfer_header_id=' + interorg_transferId);
// });

//get onhand
 $('body').off('change', '.item_id_m, .from_subinventory_id, .from_locator_id')
         .on('change', '.item_id_m, .from_subinventory_id, .from_locator_id', function () {
          var trClass = '.' + $(this).closest('tr').attr('class');
          var item_id_m = $('#form_line').find(trClass).find('.item_id_m').val();
          var from_org_id = $('#from_org_id').val();
          var from_subinventory_id = $('#form_line').find(trClass).find('.from_subinventory_id').val();
          if (item_id_m && from_org_id && from_subinventory_id) {
           getOnhandDetails({
            item_id_m: item_id_m,
            org_id: from_org_id,
            subinventory_id: from_subinventory_id,
            locator_id: $('#form_line').find(trClass).find('.from_locator_id').val(),
            trClass: trClass,
            fieldClass: 'from_current_onhand',
           });
          }


          /*Serial number details*/
          var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
          var trClass_d = '.' + trClass;
          var generation_type = $('#content').find(trClass_d).find('.serial_generation').val();
          if (!generation_type) {
           var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
           $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
           $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
//   alert('Item is not serial controlled.\nNo serial information \'ll be saved in database');
           return;
          }
          var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
          if (!itemIdM) {
           return;
          }

          getSerialNumber({
           'org_id': $('#from_org_id').val(),
           'status': 'IN_STORE',
           'item_id_m': itemIdM,
           'trclass': trClass,
           'current_subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
           'current_locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
          });


          /*Lot Details*/

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

          getlotNumber({
           'org_id': $('#from_org_id').val(),
           'status': 'ACTIVE',
           'item_id_m': itemIdM,
           'trclass': trClass,
           'subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
           'locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
          });

         });

 $('body').off('change', '.item_id_m, .to_subinventory_id, .to_locator_id')
         .on('change', '.item_id_m, .to_subinventory_id, .to_locator_id', function () {
          var trClass = '.' + $(this).closest('tr').attr('class');
          var item_id_m = $('#form_line').find(trClass).find('.item_id_m').val();
          var to_org_id = $('#to_org_id').val();
          var to_subinventory_id = $('#form_line').find(trClass).find('.to_subinventory_id').val();
          if (item_id_m && to_org_id && to_subinventory_id) {
           getOnhandDetails({
            item_id_m: item_id_m,
            org_id: to_org_id,
            subinventory_id: to_subinventory_id,
            locator_id: $('#form_line').find(trClass).find('.to_locator_id').val(),
            trClass: trClass,
            fieldClass: 'to_current_onhand',
           });
          }
         });

 $('body').off('change', '.transaction_quantity, .from_current_onhand, .to_current_onhand')
         .on('change', '.transaction_quantity, .from_current_onhand, .to_current_onhand', function () {
          var from_future_onhand = +($(this).closest('tr').find('.from_current_onhand').val()) -
                  +($(this).closest('tr').find('.transaction_quantity').val());

          var to_future_onhand = +($(this).closest('tr').find('.to_current_onhand').val()) +
                  +($(this).closest('tr').find('.transaction_quantity').val());

          $(this).closest('tr').find('.from_future_onhand').val(from_future_onhand);
          $(this).closest('tr').find('.to_future_onhand').val(to_future_onhand);
         });


 onClick_addDetailLine(1, '.add_row_detail_img1');

 $('body').off('change', '#transaction_action').on('change', '#transaction_action', function () {
  var selected_value = $(this).val();
  switch (selected_value) {
   case 'ADD_LINES' :
    add_interorg_transfer_lines();
    break;

   default :
    break;
  }
 });

});

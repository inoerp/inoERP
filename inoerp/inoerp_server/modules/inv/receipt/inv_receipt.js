function beforeSave() {
 return lotSerial_quantityValidation();
}

//Popup for adding receipt lines
function add_receipt_lines() {
 var inv_receipt_header_id = $("#inv_receipt_header_id").val();
 if (inv_receipt_header_id) {
  var link = 'multi_select.php?class_name=po_all_v&action=multi_receipt&mode=9&action_class_name=inv_receipt_line&';
  link += 'po_status=APPROVED&inv_receipt_header_id=' + inv_receipt_header_id + '&org_id=' + $('#org_id').val();
  localStorage.removeItem("reset_link");
  localStorage.setItem("reset_link", link);
  localStorage.removeItem("jsfile");
  localStorage.setItem("jsfile", "modules/inv/receipt/extra/extra_inv_receipt.js");
  void window.open(link, '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 } else {
  alert('No Receipt Header ID/nEnter or Save The Header Details ');
 }
}

$(document).ready(function () {

//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'inv_receipt_header_id';
 mandatoryCheck.mandatoryHeader();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 $('body').off('click', '.popup.view-item-config').on('click', '.popup.view-item-config', function () {
  var openUrl = $(this).find('a').prop('href') + '&reference_key_name=po_line';
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  if ($('#form_line').find(trClass).find('input.po_line_id').val()) {
   openUrl += '&reference_key_value=' + $('#form_line').find(trClass).find('.po_line_id').val();
  }
  void window.open(openUrl, '_blank',
          'width=1200,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//verify entered qty is less than open quantity
 $('body').off('blur', '.received_quantity').on('blur', '.received_quantity', function () {
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
 $('body').off('blur', '.transaction_quantity').on('blur', '.transaction_quantity', function () {
  var trClass = '.' + $(this).closest('tr').prop('class');
  trClass = trClass.replace(/\s+/g, '.');
  $(this).closest('.tabContainer').find(trClass).find('.transaction_type_id').val($('#transaction_type_id').val());
  $(this).closest('.tabContainer').find(trClass).find('.org_id').val($('#org_id').val());
  $(this).closest('.tabContainer').find(trClass).find('.inv_receipt_header_id').val($('#inv_receipt_header_id').val());
 });


 $('body').off('blur', '#transaction_type_id').on('blur', '#transaction_type_id', function () {
  $('.transaction_type_id').val($('#transaction_type_id').val());
 });


 //get Subinventory Name
 $('body').off('change', '#org_id').on("change", '#org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $("#org_id").val()
  });
  $('.org_id').val($(this).val());
 });

 if ($('#org_id').val()) {
  var org_id_val = +($('#org_id').val());
  $('.org_id').val(org_id_val);
 }

 //get locators on changing sub inventory
 $('body').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', trClass);
 });

 //selecting Header Id
 $(".inv_receipt_header_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=inv_receipt_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 onClick_addDetailLine(1, '.add_row_detail_img1');

 $('body').off('blur', '.subinventory_id, .locator_id')
         .on('blur', '.subinventory_id, .locator_id', function () {
          var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
          var trClass_d = '.' + trClass;
          var generation_type = $('#content').find(trClass_d).find('.serial_generation').val();

          if (!generation_type) {
           var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
           $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
           $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
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

 $('body').off('change', '#transaction_action').
         on('change', '#transaction_action', function () {
          var selected_value = $(this).val();
          switch (selected_value) {
           case 'ADD_LINES' :
            add_receipt_lines();
            break;

           default :
            break;
          }
         });

});

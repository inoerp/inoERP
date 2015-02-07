function setValFromSelectPage(inv_receipt_header_id, combination, ar_customer_id, ar_customer_site_id,
        customer_name, customer_number, customer_site_name, customer_site_number,
        item_id_m, item_number, revision_name, item_description, uom_id, sd_so_header_id, sd_so_line_id,
        so_number, line_number, line_quantity, shipped_quantity,
        serial_generation, lot_generation) {
 this.inv_receipt_header_id = inv_receipt_header_id;
 this.combination = combination;
 this.ar_customer_id = ar_customer_id;
 this.ar_customer_site_id = ar_customer_site_id;
 this.customer_name = customer_name;
 this.customer_site_number = customer_site_number;
 this.customer_site_name = customer_site_name;
 this.customer_number = customer_number;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.revision_name = revision_name;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.sd_so_header_id = sd_so_header_id;
 this.sd_so_line_id = sd_so_line_id;
 this.so_number = so_number;
 this.line_number = line_number;
 this.line_quantity = line_quantity;
 this.shipped_quantity = shipped_quantity;
 this.serial_generation = serial_generation;
 this.lot_generation = lot_generation;
}

setValFromSelectPage.prototype.setVal = function () {
 var inv_receipt_header_id = this.inv_receipt_header_id;
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (inv_receipt_header_id) {
  $("#inv_receipt_header_id").val(inv_receipt_header_id);
 }
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');

 var item_obj = [{id: 'item_id_m', data: this.item_id_m},
  {id: 'po_line_id', data: this.po_line_id},
  {id: 'revision_name', data: this.revision_name},
  {id: 'item_number', data: this.item_number},
  {id: 'item_description', data: this.item_description},
  {id: 'uom_id', data: this.uom_id}
 ];

 var customer_obj = [{id: 'ar_customer_id', data: this.ar_customer_id},
  {id: 'ar_customer_site_id', data: this.ar_customer_site_id},
  {id: 'customer_name', data: this.customer_name},
  {id: 'customer_number', data: this.customer_number},
  {id: 'customer_site_name', data: this.customer_site_name},
  {id: 'customer_site_number', data: this.customer_site_number}
 ];


 var so_obj = [{id: 'sd_so_header_id', data: this.sd_so_header_id},
  {id: 'sd_so_line_id', data: this.sd_so_line_id},
  {id: 'po_detail_id', data: this.po_detail_id},
  {id: 'so_number', data: this.so_number},
  {id: 'so_line_number', data: this.line_number},
  {id: 'quantity', data: this.line_quantity},
  {id: 'received_quantity', data: this.received_quantity}
 ];

 $(customer_obj).each(function (i, value) {
  if (value.data) {
   var fieldClass = '.' + value.id;
   $('#content').find(rowClass).find(fieldClass).val(value.data);
  }
 });

 $(item_obj).each(function (i, value) {
  if (value.data) {
   var fieldClass = '.' + value.id;
   $('#content').find(rowClass).find(fieldClass).val(value.data);
  }
 });

 $(so_obj).each(function (i, value) {
  if (value.data) {
   var fieldClass = '.' + value.id;
   $('#content').find(rowClass).find(fieldClass).val(value.data);
  }
 });

 if (this.serial_generation) {
  $('#content').find(rowClass).find('.serial_generation').val(this.serial_generation);
  $('#content').find(rowClass).find('.serial_number').attr('required', true).css('background-color', 'pink');
 }
 if (this.lot_generation) {
  $('#content').find(rowClass).find('.lot_generation').val(this.lot_generation);
  $('#content').find(rowClass).find('.lot_number').attr('required', true).css('background-color', 'pink');
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("row_class");

};

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
// var mandatoryCheck = new mandatoryFieldMain();
// mandatoryCheck.header_id = 'inv_receipt_header_id';
// mandatoryCheck.mandatoryHeader();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

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


 //get Subinventory Name
 $('body').off('change', '#org_id').on("change", '#org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: val($("#org_id").val())
  });
  $('.org_id').val($(this).val());
 });

 //get locators on changing sub inventory
 $('body').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', trClass);
 });

//popu for selecting SO number
 $('#content').off('click', '.select_so_number.select_popup').on('click', '.select_so_number.select_popup', function () {
  var rowClass = $(this).closest('tr').prop('class');
  var fieldClass = $(this).closest('td').find('.select_po_number').prop('class');
  localStorage.setItem("row_class", rowClass);
  localStorage.setItem("field_class", fieldClass);
  var openUrl = 'select.php?class_name=sd_so_all_v&line_status=AWAITING_RETURN&shipping_org_id=' + $('#org_id').val();
  void window.open(openUrl, '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
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

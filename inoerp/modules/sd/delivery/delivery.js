function setValFromSelectPage(sd_delivery_header_id, sd_delivery_line_id, ar_customer_id, ar_customer_number,
        ar_customer_name, ar_customer_site_id, ar_customer_site_name, ar_customer_site_number,
        item_id_m, item_number, item_description, uom_id, sd_so_header_id, sd_so_line_id, po_detail_id,
        sd_number, line_number, shipment_number, quantity, shipped_quantity) {
 this.sd_delivery_header_id = sd_delivery_header_id;
 this.sd_delivery_line_id = sd_delivery_line_id;
 this.ar_customer_id = ar_customer_id;
 this.ar_customer_number = ar_customer_number;
 this.ar_customer_name = ar_customer_name;
 this.ar_customer_site_id = ar_customer_site_id;
 this.ar_customer_site_name = ar_customer_site_name;
 this.ar_customer_site_number = ar_customer_site_number;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.sd_so_header_id = sd_so_header_id;
 this.sd_so_line_id = sd_so_line_id;
 this.po_detail_id = po_detail_id;
 this.sd_number = sd_number;
 this.line_number = line_number;
 this.shipment_number = shipment_number;
 this.quantity = quantity;
 this.shipped_quantity = shipped_quantity;
}

setValFromSelectPage.prototype.setVal = function () {
 var sd_delivery_header_id = this.sd_delivery_header_id;
 var sd_delivery_line_id = this.sd_delivery_line_id;
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 var adding_header = localStorage.getItem("adding_header");
 if (sd_delivery_header_id === -1) {
  alert('Selected delivery is assigned to a different delivery number');
  return;
 }
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (sd_delivery_line_id) {
  $('#content').find(rowClass).find('.sd_delivery_line_id').val(sd_delivery_line_id);
 }

 if (sd_delivery_header_id && adding_header == 99) {
  $('#sd_delivery_header_id').val(sd_delivery_header_id);
  if (this.sd_delivery_header_id) {
   $('a.show.sd_delivery_header_id').trigger('click');
  }
 }


 var item_obj = [{id: 'item_id_m', data: this.item_id_m},
  {id: 'sd_so_line_id', data: this.sd_so_line_id},
  {id: 'item_number', data: this.item_number},
  {id: 'item_description', data: this.item_description},
  {id: 'uom_id', data: this.uom_id}
 ];
 var customer_obj = [{id: 'ar_customer_id', data: this.ar_customer_id},
  {id: 'ar_customer_site_id', data: this.ar_customer_site_id},
  {id: 'ar_customer_number', data: this.ar_customer_number},
  {id: 'ar_customer_name', data: this.ar_customer_name},
  {id: 'ar_customer_site_number', data: this.ar_customer_site_number},
  {id: 'ar_customer_site_name', data: this.ar_customer_site_name}
 ];
 var so_obj = [{id: 'sd_so_header_id', data: this.sd_so_header_id},
  {id: 'sd_so_line_id', data: this.sd_so_line_id},
  {id: 'po_detail_id', data: this.po_detail_id},
  {id: 'sd_number', data: this.sd_number},
  {id: 'shipment_number', data: this.shipment_number},
  {id: 'sd_so_line_number', data: this.line_number},
  {id: 'shipment_number', data: this.shipment_number},
  {id: 'shipped_quantity', data: this.shipped_quantity},
  {id: 'quantity', data: this.quantity}
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
 localStorage.removeItem("row_class");
 localStorage.removeItem("fieldClass");
 localStorage.removeItem("adding_header");
};
$(document).ready(function () {

//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'sd_delivery_header_id';
// mandatoryCheck.mandatoryHeader();

//verify entered qty is less than open quantity
 $('#content').off('blur', '.shipped_quantity').on('blur', '.shipped_quantity', function () {
  var newQty = $(this).val();
  var shipmentQty = $(this).closest('tr').find('.quantity').val();
  var poReceivedQty = $(this).closest('tr').find('.po_shipped_quantity').val();
  if ((+poReceivedQty + +newQty) > shipmentQty) {
   alert('Entered quantity is more than open quantity!');
   $(this).val('');
   $(this).focus();
  }
 });
//shipped qty is less than picked qty
 $('body').off('blur', '.shipped_quantity').on('blur', '.shipped_quantity', function () {
  var dev_qty = +$(this).closest('tr').find('.quantity').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var ship_qty = +$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var qty_change = dev_qty - ship_qty;
  if (qty_change < 0) {
   alert('You cant ship more than picked quantity');
   $(this).val('');
   $(this).closest('tr').find('.so_qty_change').val('');
  } else {
   $(this).closest('tr').find('.so_qty_change').val(qty_change);
  }
 })

//Default header values to line
 $('#content').off('blur', '.transaction_quantity').on('blur', '.transaction_quantity', function () {
  var trClass = '.' + $(this).closest('tr').prop('class');
  trClass = trClass.replace(/\s+/g, '.');
  $(this).closest('.tabContainer').find(trClass).find('.transaction_type_id').val($('#transaction_type_id').val());
  $(this).closest('.tabContainer').find(trClass).find('.org_id').val($('#org_id').val());
  $(this).closest('.tabContainer').find(trClass).find('.sd_delivery_header_id').val($('#sd_delivery_header_id').val());
 });
//popu for delivery lines
 $('#content').off('click', '.select_delivery_line.select_popup')
         .on('click', '.select_delivery_line.select_popup', function () {
          var rowClass = $(this).closest('tr').prop('class');
          var fieldClass = $(this).closest('td').find('.select_sd_number').prop('class');
          localStorage.setItem("row_class", rowClass);
          localStorage.setItem("field_class", fieldClass);
          var openUrl = 'select.php?class_name=sd_delivery_line&sd_delivery_header_id=-1&delivery_status=AWAITING_SHIPPING';
          void window.open(openUrl, '_blank',
                  'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
         });
 //selecting Header Id
 $('body').off("click", '.sd_delivery_header_id.select_popup')
         .on("click", '.sd_delivery_header_id.select_popup', function () {
          localStorage.setItem("adding_header", '99');
          void window.open('select.php?class_name=sd_delivery_header&status=AWAITING_SHIPPING', '_blank',
                  'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
         });
 $('body').off('change', '#action').on('change', '#action', function () {
  var actionValue = $(this).val();
  var lineCount = 0;
  $('input[name="line_id_cb"]:checked').each(function () {
   $(this).closest('tr').find('.action').val(actionValue);
   lineCount++;
  });
  switch (actionValue) {
   case 'COMPLETE_SHIPMENT' :
    if (confirm("Do you want to ship all the lines?")) {
     $('.action').val(actionValue);
     $('input[name="line_id_cb"]').each(function () {
      $(this).prop('checked', true);
     });
     $('.shipped_quantity').prop('readonly', false).css('background-color', '#fff');
    } else if (lineCount > 0) {
     alert(lineCount + ' line(s) selected for shipment\nChange the shipment quantity if required and then save the transaction');
     $('.shipped_quantity').prop('readonly', false).css('background-color', '#fff');
    } else {
     alert('No Line Selected For Shipment\nRemove/Reverse the required lines and the select the shipment action again');
     $('.action').val('');
    }

    break;
   default :
    break;
  }
 });
});

function copy_line_to_details() {
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function () {
  var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
  if (detailExists === 0) {
   var lineQuantity = $(this).closest('tr').find('.line_quantity').val();
   $(this).closest("td").find(".quantity:first").val(lineQuantity);
  }
 });
}

function po_requisition_update_supply_field(supply_type) {
 if (supply_type == 'INTERNAL') {
  $('#supply_org_id').removeAttr('readonly').removeClass('readonly');
  $('#supplier_name, #supplier_id, .supplier_id.select_popup, #supplier_number, #supplier_site_id').attr('readonly', true).addClass('readonly');
 } else {
  $('#supply_org_id').attr('readonly', true).addClass('readonly');
  $('#supplier_name, #supplier_id, .supplier_id.select_popup, #supplier_number, #supplier_site_id').removeAttr('readonly').removeClass('readonly');
 }
}

$(document).ready(function () {

 $('#form_line').find('.line_type').each(function (e) {
//  e.stopPropagation();
  if (!$(this).val()) {
   $(this).val('GOODS');
  }
 });

 $('body').off('change', '#bu_org_id').on('change', '#bu_org_id', function () {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && ($('#bu_org_id').attr('disabled') != 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.shipment_number:first').val())) {
  $('.shipment_number:first').val('1');
 }

 lineDetail_QuantityValidation();
// $('.need_by_date:first').datepicker("setDate", new Date());
// $('.promise_date:first').datepicker("setDate", new Date());

//get locators on changing sub inventory
 $('#content').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_value = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_value, 'subinventory', trClass);
 });


 $("#content").off("click", "table.form_line_data_table .add_detail_values_img")
         .on("click", "table.form_line_data_table .add_detail_values_img", function () {
          var lineQuantity = $(this).closest('tr').find('.line_quantity:first').val();
          if (!$(this).closest("td").find(".quantity:first").val())
          {
           $(this).closest("td").find(".quantity:first").val(lineQuantity);
          }
         });
//get supplier details
 get_supplier_detail_for_bu();

 $("#content").off("change", "#supplier_site_id").on("change", "#supplier_site_id", function () {
  var supplier_site_id = $("#supplier_site_id").val();
  if (supplier_site_id) {
   getSupplierSiteDetails('modules/ap/supplier/json_supplier.php', supplier_site_id);
  }
 });

 $("#content").off("change", '.receving_org_id').on("change", '.receving_org_id', function () {
  var receving_org_id = $(this).val();
  var rowTrClass = $(this).closest("tr").attr("class");
  var classValue = "tr." + rowTrClass;
  var classValue1 = classValue.replace(/ /g, '.');
  getAllInventoryAccounts('modules/org/inventory/json_inventory.php', receving_org_id, classValue1);
 });


 //selecting PO Header Id
 $('body').off("click", '.po_requisition_header_id.select_popup')
         .on("click", '.po_requisition_header_id.select_popup', function () {
          void window.open('select.php?class_name=po_requisition_HEADER', '_blank',
                  'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
         });

 copy_line_to_details();

//set the line price
 $('#form_line').off('blur', '.item_id_m, .item_number, .price_list_header_id, .price_date')
         .on('blur', '.item_id_m, .item_number, .price_list_header_id, .price_date', function () {
          var rowClass = '.' + $(this).closest('tr').prop('class');
          var item_id_m = $(this).closest('.tabContainer').find(rowClass).find('.item_id_m').val();
          var price_date = $(this).closest('.tabContainer').find(rowClass).find('.price_date').val();
          var price_list_header_id = $(this).closest('#form_line').find(rowClass).find('.price_list_header_id').val();
          getPriceDetails({
           rowClass: rowClass,
           item_id_m: item_id_m,
           price_list_header_id: price_list_header_id,
           price_date: price_date
          });
         });

 $('#content').off('blur', '.unit_price, .line_quantity , .line_price')
         .on('blur', '.unit_price, .line_quantity , .line_price', function () {
          var trClass = '.' + $(this).closest('tr').attr('class');
          var unitPrice = +($(this).closest('#form_line').find(trClass).find('.unit_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
          var lineQuantity = +($(this).closest('#form_line').find(trClass).find('.line_quantity').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
          var linePrice = unitPrice * lineQuantity;
          $(this).closest('#form_line').find(trClass).find('.line_price').val(linePrice);
         });

//total header & tax amount
 $('#content').off('blur', '.line_quantity, .unit_price, .line_price')
         .on('blur', '.line_quantity, .unit_price, .line_price', function () {
          var header_amount = 0;
          $('#form_line').find('.line_price').each(function () {
           header_amount += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
          });
          $('#header_amount').val(header_amount);
         });

 $('#content').off('blur', '.item_number').on('blur', '.item_number', function () {
  if ($('#bu_org_id').val() && $('#supplier_site_id').val() && $(this).val()) {
   getBPAList({
    'bu_org_id': $('#bu_org_id').val(),
    'supplier_site_id': $('#supplier_site_id').val(),
    'item_id_m': $(this).closest('tr').find('.item_id_m').val(),
    'field_name': 'bpa_po_line_id',
    'replacing_field': 'bpa_po_line_id',
    'trclass': $(this).closest('tr').attr('class'),
   });
  }
 });
 po_requisition_update_supply_field($('#po_requisition_type').val());

 $('body').off('change', '#po_requisition_type').on('change', '#po_requisition_type', function () {
  po_requisition_update_supply_field($(this).val());
 });

 $('body').off('click', '#menu_button4_1, #menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_1, #menu_button4_2, #menu_button4_2_1', function () {
  $('#status, .order_type, .order_number').val('');
  $('#po_requisition_type').removeAttr('readonly').removeClass('readonly');
 });

//verify Qty
 $('#inv_ir_receipt_formid').on('blur', '.transaction_quantity', function () {
  var transaction_quantity = +$(this).val();
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  var ship_q = +$(trClass).find('.iso_shipped_quantity').val();

  if (transaction_quantity > ship_q) {
   $(this).val('');
   alert('IR Receipt Quantity ' + transaction_quantity + ' is greater than ISO Shipped Qty ' + ship_q);
  }

 });

});


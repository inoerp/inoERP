function setValFromSelectPage(po_requisition_header_id, combination, supplier_id, supplier_number, supplier_name,
        item_id_m, item_number, item_description, uom_id, address_id, address_name, address,
        country, postal_code) {
 this.po_requisition_header_id = po_requisition_header_id;
 this.combination = combination;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.address_id = address_id;
 this.address_name = address_name;
 this.address = address;
 this.country = country;
 this.postal_code = postal_code;
}

setValFromSelectPage.prototype.setVal = function () {
 var po_requisition_header_id = this.po_requisition_header_id;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var combination = this.combination;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 var address_id = this.address_id;
 var address_name = this.address_name;
 var address = this.address;
 var country = this.country;
 var postal_code = this.postal_code;
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (po_requisition_header_id) {
  $("#po_requisition_header_id").val(po_requisition_header_id);
 }
 if (supplier_id) {
  $("#supplier_id").val(supplier_id);
 }
 if (supplier_number) {
  $("#supplier_number").val(supplier_number);
 }
 if (supplier_name) {
  $("#supplier_name").val(supplier_name);
 }
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
  $('#content').find(rowClass).find(fieldClass).val(combination);
 }
 if (item_id_m) {
  $('#content').find(rowClass).find('.item_id_m').val(item_id_m);
 }
 if (item_number) {
  $('#content').find(rowClass).find('.item_number').val(item_number);
 }
 if (item_description) {
  $('#content').find(rowClass).find('.item_description').val(item_description);
 }
 if (uom_id) {
  $('#content').find(rowClass).find('.uom_id').val(uom_id);
 }
 var addressPopupDivClass = '.' + localStorage.getItem("addressPopupDivClass");
 addressPopupDivClass = addressPopupDivClass.replace(/\s+/g, '.');
 if (address_id) {
  $('#form_header').find(addressPopupDivClass).find('.address_id').val(address_id);
 }
 if (address_name) {
  $('#form_header').find(addressPopupDivClass).find('.address_name').val(address_name);
 }
 if (address) {
  $('#form_header').find(addressPopupDivClass).find('.address').val(address);
 }
 if (country) {
  $('#form_header').find(addressPopupDivClass).find('.country').val(country);
 }
 if (postal_code) {
  $('#form_header').find(addressPopupDivClass).find('.postal_code').val(postal_code);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("addressPopupDivClass");
  if (this.po_requisition_header_id) {
  $('a.show.po_requisition_header_id').trigger('click');
 }
};

function copy_line_to_details() {
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function () {
  var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
  if (detailExists === 0) {
   var lineQuantity = $(this).closest('tr').find('.line_quantity').val();
   $(this).closest("td").find(".quantity:first").val(lineQuantity);
  }
 });
}

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'po_requisition_header_id';
 mandatoryCheck.mandatoryHeader();
// mandatoryCheck.form_area = 'form_header';
// mandatoryCheck.mandatory_fields = ["bu_org_id", "po_requisition_type"];
// mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Requisition Type"];
// mandatoryCheck.mandatoryField();

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

});

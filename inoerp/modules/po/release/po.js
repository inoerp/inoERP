function setValFromSelectPage(po_header_id, combination, supplier_id, supplier_number, supplier_name,
 item_id_m_m, item_number, item_description, uom_id, address_id, address_name, address,
 country, postal_code) {
 this.po_header_id = po_header_id;
 this.combination = combination;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.item_id_m_m = item_id_m_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.address_id = address_id;
 this.address_name = address_name;
 this.address = address;
 this.country = country;
 this.postal_code = postal_code;
}

setValFromSelectPage.prototype.setVal = function() {
 var po_header_id = this.po_header_id;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var combination = this.combination;
 var item_id_m_m = this.item_id_m_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 var address_id = this.address_id;
 var address_name = this.address_name;
 var address = this.address;
 var country = this.country;
 var postal_code = this.postal_code;
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (po_header_id) {
  $("#po_header_id").val(po_header_id);
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

 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
  $('#content').find(rowClass).find(fieldClass).val(combination);
 }
 if (item_id_m_m) {
  $('#content').find(rowClass).find('.item_id_m_m').val(item_id_m_m);
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

};

function afterAddNewRow(){
 $("[class^=new_object]").find(':input').not('.agreed_quantity,.agreed_amount,.released_quantity,.released_amount,.line_id,\n\
.po_detail_id,.received_quantity,.accepted_quantity,.delivered_quantity,.invoiced_quantity,.paid_quantity').attr('disabled', false);
}

function afterAddNewDetail(){
  $("[class^=new_object]").find(':input').not('.agreed_quantity,.agreed_amount,.released_quantity,.released_amount,.line_id,\n\
.po_detail_id,.received_quantity,.accepted_quantity,.delivered_quantity,.invoiced_quantity,.paid_quantity').attr('disabled', false);
}
$(document).ready(function() {
 //defalut values
 if (!$('#po_type').val()) {
  $('#po_type').val('STANDARD');
 }
$('#release_number').on('change', function() {
  $('#po_header_id').val('');
  $('#po_status').val('');
  $('#action').val('');
 })
 $('#form_line').find('.line_type').each(function() {
  if (!$(this).val()) {
   $(this).val('GOODS');
  }
 });

 if ($('#po_type').val() == 'BLANKET') {
  $('.class_detail_form').html('');
 }

 $('#po_type').on('change', function() {
  if ($(this).val() === 'BLANKET') {
   $('.class_detail_form').html('');
  }
 });
 
 $('#form_line').on('change', '.bpa_line_id' , function(){
getBPALineDetails({
  'po_line_id' : $(this).val(),
  'trClass' : $(this).closest('tr').attr('class')
});
    
});

$('#release_number').on('change', function(){
 $('a.show.ref_po_header_id').trigger('click');
 
})

//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'po_header_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "po_type"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No PO Type"];
 mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.detail_number:first').val())) {
  $('.detail_number:first').val('1');
 }
 lineDetail_QuantityValidation();

 //default quantity
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
  var lineQuantity = $(this).closest('tr').find('.line_quantity:first').val();
  if (!$(this).closest("td").find(".quantity:first").val())
  {
   $(this).closest("td").find(".quantity:first").val(lineQuantity);
  }
  if (!$(this).closest("td").find(".detail_number:first").val())
  {
   $(this).closest("td").find(".detail_number:first").val(1);
  }
 });

//get supplier details
 get_supplier_detail_for_bu();

 $("#content").on("change", "#supplier_site_id", function() {
  var supplier_site_id = $("#supplier_site_id").val();
  if (supplier_site_id) {
   getSupplierSiteDetails('modules/ap/supplier/json_supplier.php', supplier_site_id);
  }
 });

 $("#form_line").on("blur", '.receving_org_id, .add_detail_values_img', function() {
  var receving_org_id = $(this).closest('tr').find('.receving_org_id').val();
  var rowTrClass = $(this).closest("tr").attr("class");
  var classValue = "tr." + rowTrClass;
  var classValue1 = classValue.replace(/ /g, '.');
  getAllInventoryAccounts('modules/org/inventory/json_inventory.php', receving_org_id, classValue1);
        getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: receving_org_id
  });
 });
 
  $("#form_line").on("click", '.add_detail_values_img', function() {
  var receving_org_id = $(this).closest('tr').find('.receving_org_id').val();
  var rowTrClass = $(this).closest("tr").attr("class");
  var classValue = "tr." + rowTrClass;
  var classValue1 = classValue.replace(/ /g, '.');
  getAllInventoryAccounts('modules/org/inventory/json_inventory.php', receving_org_id, classValue1);
          getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: receving_org_id
  });
 });

//get locators on changing sub inventory
 $('#form_line').on('blur', '.subinventory_id', function() {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_value = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_value, 'subinventory', trClass);
 });

////get Subinventory Name
// $("#form_line").on("blur", '.receving_org_id, .add_detail_values_img', function() {
//  var receving_org_id = $(this).closest('tr').find('.receving_org_id').val();
//  getSubInventory('modules/inv/subinventory/json_subinventory.php', $(this).val());
// });

 //selecting PO Header Id
 $(".po_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=po_blanket_v', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Popup for selecting address 
 $(".address_popup").click(function() {
  var addressPopupDivClass = $(this).closest('div').prop('class');
  localStorage.setItem("addressPopupDivClass", addressPopupDivClass);
  void window.open('select.php?class_name=address', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

 //Get the supplier_id on refresh button click
 $('a.show.po_header_id').click(function() {
  var po_header_id = $('#po_header_id').val();
  $(this).attr('href', modepath() + 'po_header_id=' + po_header_id);

 });
 $('a.show.ref_po_header_id').click(function() {
  var ref_po_header_id = $('#ref_po_header_id').val();
  var release_number = $('#release_number').val();
  $(this).attr('href', modepath() + 'ref_po_header_id=' + ref_po_header_id + '&release_number=' + release_number);
 });

// $('a.show.supplier_number').click(function() {
//  var supplier_number = $('#supplier_number').val();
//  if ($('#org_id').val().length > 0) {
//   var org_id = $('#org_id').val();
//   $(this).attr('href', modepath() + 'supplier_number=' + supplier_number + '&org_id=' + org_id);
//  } else {
//   alert("Query Error!!! \n Select the query mode by pressing Ctrl + Q \n Select the organization name");
//  }
// });
//
// $('a.show.supplier_site_id').click(function() {
//  var supplier_id = $('#headerId').val();
//  var supplier_site_id = $('#supplier_site_id').val();
//  $(this).attr('href', '?supplier_id=' + supplier_id + '&supplier_site_id=' + supplier_site_id);
// });
//
// $("#supplier_site_name").on("change", function() {
//  if ($(this).val() == 'newentry') {
//   if (confirm("Do you want to create a new supplier site?")) {
//    $(this).replaceWith('<input id="supplier_site_name" class="textfield supplier_site_name" type="text" size="25" maxlength="50" name="supplier_site_name[]">');
//    $(".show.supplier_site_id").hide();
//    $("#supplier_site_id").val("");
//    $("#supplier_site_number").val("");
//   }
//
//  }
// });


//add or show linw details
 addOrShow_lineDetails(afterAddNewDetail);

//copy_line_to_details();


 //Get the po_id on find button click
 $('#form_box a.show').click(function() {
  var poId = $('#po_header_id').val();
//$(this).prop('href','po.php?po_header_id=' + poId);
  $(this).attr('href', 'po.php?po_header_id=' + poId);
 });


 $("#content").on("click", ".add_row_img", function() {
//	add_new_row('tr.po_line0', 'tbody.form_data_line_tbody', 3);
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'po_line';
  addNewRow.tbodyClass = 'form_data_line_tbody';
  addNewRow.noOfTabs = 3;
  addNewRow.removeDefault = true;
  addNewRow.divClassToBeCopied = 'copyValue';
  addNewRow.add_new_row(afterAddNewRow);
  $(".tabsDetail").tabs();
 });

 onClick_addDetailLine('tr.po_detail0-0', 'tbody.form_data_detail_tbody', 4);

//remove po lines
 $("#remove_row").click(function() {
  $('input[name="po_line_id_cb"]:checked').each(function() {
   $(this).closest('tr').remove();
  });
 });

 $('#bu_org_id').on('change', function() {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && ($('#bu_org_id').attr('disabled') != 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

 deleteData('form.php?class_name=po_header&line_class_name=po_line&detail_class_name=po_detail');

 //exhhnge rate
 if ($('#currency').val() != $('#doc_currency').val()) {
  getExchangeRate();
 }

 $('#content').on('blur', '#currency, #doc_currency, #exchange_rate_type, #exchange_rate', function() {
  getExchangeRate();
 });

//set the line price
 $('#form_line').on('change', '.item_id_m, .item_number, .price_list_header_id, .price_date', function() {
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

 $('#content').on('blur, change, lineChange_t', '.unit_price, .line_quantity , .line_price', function() {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var unitPrice = +($(this).closest('#form_line').find(trClass).find('.unit_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  var lineQuantity = +($(this).closest('#form_line').find(trClass).find('.line_quantity').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  var linePrice = unitPrice * lineQuantity;
  $(this).closest('#form_line').find(trClass).find('.line_price').val(linePrice);
 });

//total header & tax amount
 $('#content').on('blur, change', '.line_quantity, .unit_price, .line_price', function() {
  var header_amount = 0;
  $('#form_line').find('.line_price').each(function() {
   header_amount += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#header_amount').val(header_amount);
 });
 
 $('#form_line .received_quantity').each(function(){
  if($(this).val()){
     var trClass = '.' + $(this).closest('td.add_detail_values').closest('tr').attr('class').replace(/\+s/g,'.');
    $('#form_line').find(trClass).find(':input').not('.date,.allow_change').attr('disabled',true);
  }
});

});


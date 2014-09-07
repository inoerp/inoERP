function setValFromSelectPage(po_rfq_header_id, combination, supplier_id, supplier_number, supplier_name,
 item_id_m, item_number, item_description, uom_id, address_id, address_name, address,
 country, postal_code) {
 this.po_rfq_header_id = po_rfq_header_id;
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

setValFromSelectPage.prototype.setVal = function() {
 var po_rfq_header_id = this.po_rfq_header_id;
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
 rowClass = rowClass.replace(/\s+/g, '.');
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (po_rfq_header_id) {
  $("#po_rfq_header_id").val(po_rfq_header_id);
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

};


$(document).ready(function() {

 $('#form_line').find('.line_type').each(function() {
  if (!$(this).val()) {
   $(this).val('GOODS');
  }
 });

 $('#release_number').on('change', function() {
    $('#po_rfq_header_id').val('');
  $('#po_rfq_status').val('');
  $('#action').val('');
 })

 if ($('#po_rfq_type').val() == 'BLANKET') {
  $('.class_detail_form').html('');
  $(this).attr('disabled', true);
 }


//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'po_rfq_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "po_rfq_type"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No PO Type"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.detail_number:first').val())) {
  $('.detail_number:first').val('1');
 }

 $("#content").on("change", "#supplier_site_id", function() {
  var supplier_site_id = $("#supplier_site_id").val();
  if (supplier_site_id) {
   getSupplierSiteDetails('modules/ap/supplier/json_supplier.php', supplier_site_id);
  }
 });

 
 //selecting PO Header Id
 $(".po_rfq_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=po_rfq_header', '_blank',
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

 //Get the po header id on refresh button click
 $('a.show.po_rfq_header_id').click(function() {
  var po_rfq_header_id = $('#po_rfq_header_id').val();
  $(this).attr('href', modepath() + 'po_rfq_header_id=' + po_rfq_header_id);

 });


 //Get the po_rfq_id on find button click
 $('#form_box a.show').click(function() {
  var poId = $('#po_rfq_header_id').val();
//$(this).prop('href','po.php?po_rfq_header_id=' + poId);
  $(this).attr('href', 'po.php?po_rfq_header_id=' + poId);
 });


 $("#content").on("click", ".add_row_img", function() {
//	add_new_row('tr.po_rfq_line0', 'tbody.form_data_line_tbody', 3);
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'po_rfq_line';
  addNewRow.tbodyClass = 'form_data_line_tbody';
  addNewRow.noOfTabs = 3;
  addNewRow.removeDefault = true;
  addNewRow.divClassToBeCopied = 'copyValue';
  addNewRow.add_new_row();
  $(".tabsDetail").tabs();
 });

//add or show linw details
 addOrShow_lineDetails('tr.po_rfq_line0');
 onClick_addDetailLine('tr.po_rfq_detail0-0', 'tbody.form_data_detail_tbody', 4);

//remove po lines
 $("#remove_row").click(function() {
  $('input[name="po_rfq_line_id_cb"]:checked').each(function() {
   $(this).closest('tr').remove();
  });
 });

 $('#bu_org_id').on('change', function() {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && ($('#bu_org_id').attr('disabled') != 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }


 deleteData('form.php?class_name=po_rfq_header&line_class_name=po_rfq_line&detail_class_name=po_rfq_detail');


});


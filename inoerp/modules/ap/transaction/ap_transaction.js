function setValFromSelectPage(ap_transaction_header_id, combination, supplier_id, supplier_number, supplier_name,
 item_id_m, item_number, item_description, uom_id, bu_org_id, supplier_site_id) {
 this.ap_transaction_header_id = ap_transaction_header_id;
 this.combination = combination;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.bu_org_id = bu_org_id;
 this.supplier_site_id = supplier_site_id;

}

setValFromSelectPage.prototype.setVal = function() {
 var ap_transaction_header_id = this.ap_transaction_header_id;
 var supplier_id = this.supplier_id;
 var supplier_site_id = this.supplier_site_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var combination = this.combination;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (this.bu_org_id) {
  $("#bu_org_id").val(this.bu_org_id);
 }
 if (ap_transaction_header_id) {
  $("#ap_transaction_header_id").val(ap_transaction_header_id);
 }
 if (supplier_id) {
  $("#supplier_id").val(supplier_id);
  var bu_org_id = $("#bu_org_id").val();
  if (this.supplier_site_id) {
   $.when(getSupplierDetails('modules/ap/supplier/json_supplier.php', bu_org_id)).done(function(data, textStatus, jqXHR) {
    $('#supplier_site_id').val(supplier_site_id);
   });
  }
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

 localStorage.removeItem("row_class");
 localStorage.removeItem("row_class");

};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'ap_transaction_header_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "po_type"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No PO Type"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.detail_number:first').val())) {
  $('.detail_number:first').val('1');
 }

 $('#form_line').find('.line_type').each(function() {
  if (!$(this).val()) {
   $(this).val('GOODS');
  }
 });

 $('#bu_org_id').on('change', function() {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && ($('#bu_org_id').attr('disabled') != 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

 $('#transaction_type').on('change', function() {
  if ($(this).val() == 'PO_DEFAULT') {
   var link = 'select.php?class_name=po_all_v&po_status=%3DAPPROVED&mode=9&action_class_name=ap_transaction_header';
   void window.open(link, '_blank',
    'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
   $(this).val('INVOICE');
   return false;
  }
 })

//get supplier details
 $("#supplier_id, #supplier_name, #supplier_number").on("focusout", function() {
  if (($("#bu_org_id").val()) && ($('#supplier_id').val())) {
   var bu_org_id = $("#bu_org_id").val();
   getSupplierDetails('modules/ap/supplier/json_supplier.php', bu_org_id);
  }
 });

 $("#content").on("change", "#supplier_site_id", function() {
  var supplier_site_id = $("#supplier_site_id").val();
  if (supplier_site_id) {
   getSupplierSiteDetails('modules/ap/supplier/json_supplier.php', supplier_site_id);
  }
 });

 $("#content").on("focusout", '.ship_to_inventory', function() {
  var ship_to_inventory = $(this).val();
  var rowTrClass = $(this).closest("tr").attr("class");
  var classValue = "tr." + rowTrClass;
  var classValue1 = classValue.replace(/ /g, '.');
  getAllInventoryAccounts('modules/org/inventory/json_inventory.php', ship_to_inventory, classValue1);
 });


 //selecting PO Header Id
 $(".ap_transaction_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=ap_transaction_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


//selecting supplier
 $(".find_popup.supplierId").on("click", function() {
  localStorage.idValue = "";
  void window.open('select.php?class_name=supplier', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 
 //function to coply line to details
 function copy_line_to_details() {
  $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
   var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
   if (detailExists === 0) {
    var lineQuantity = $(this).closest('tr').find('.inv_line_quantity').val();
    $(this).closest("td").find(".quantity:first").val(lineQuantity);
   }
  });
 }

 copy_line_to_details();


 

//remove po lines
 $("#remove_row").click(function() {
  $('input[name="ap_transaction_line_id_cb"]:checked').each(function() {
   $(this).closest('tr').remove();
  });
 });

 deleteData('form.php?class_name=ap_transaction_header&line_class_name=ap_transaction_line&detail_class_name=ap_transaction_detail');
//exhhnge rate
// if ($('#currency').val() != $('#doc_currency').val()) {
//  getExchangeRate();
// }

 $('#content').on('blur', '#currency, #doc_currency, #exchange_rate_type, #exchange_rate', function() {
  getExchangeRate();
 });

//set the line quantity & price
 lineDetail_QuantityValidation();

 //default quantity
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
  var inv_line_price = $(this).closest('tr').find('.inv_line_price:first').val();
  if (!$(this).closest("td").find(".inv_line_price:first").val())
  {
   $(this).closest("td").find(".inv_line_price:first").val(inv_line_price);
  }
 });

 $('#content').on('blur', '.inv_unit_price, .inv_line_quantity , .inv_line_price', function() {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var unitPrice = +($(this).closest('#form_line').find(trClass).find('.inv_unit_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  var lineQuantity = +($(this).closest('#form_line').find(trClass).find('.inv_line_quantity').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  var linePrice = unitPrice * lineQuantity;
  $(this).closest('#form_line').find(trClass).find('.inv_line_price').val(linePrice);
 });

 //calculate the tax amount
 //get tax code
 $('#content').on('change', 'bu_org_id', function() {
  var org_id = $(this).val();
  getTaxCodes('modules/mdm/tax_code/json_tax_code.php', org_id, 'IN');
 });
 if ($('#bu_org_id').val()) {
  getTaxCodes('modules/mdm/tax_code/json_tax_code.php', $('#bu_org_id').val(), 'IN');
 }

 $('#content').on('blur', '.inv_line_quantity, .inv_unit_price, .inv_line_price, .tax_amount, .tax_code_id', function() {
  var trClass = '.' + $(this).closest('tr').prop('class');
  var linePrice = 0;
  if ($('#content').find(trClass).find('.inv_line_price').val()) {
   linePrice = +($('#content').find(trClass).find('.inv_line_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  }
  var taxCodeVal = 0;
  if ($('#content').find(trClass).find('.tax_code_value').val()) {
   taxCodeVal = $('#content').find(trClass).find('.tax_code_value').val();
  } else if ($('#content').find(trClass).find('.input_tax').find('option:selected').prop('class')) {
   taxCodeVal = $('#content').find(trClass).find('.input_tax').find('option:selected').prop('class');
  }

  if (taxCodeVal.length >= 3) {
   var taxCodeVal_a = taxCodeVal.split('_');
  } else {
   return;
  }

  var taxAmount = 0;
  var taxPercentage = 0;
  if (taxCodeVal_a[0] === 'p') {
   taxPercentage = +taxCodeVal_a[1];
  } else if (taxCodeVal_a[0] === 'a') {
   taxAmount = +taxCodeVal_a[1];
  }
  var taxValue = 0;
  if (taxPercentage) {
   taxValue = ((taxPercentage * linePrice) / 100).toFixed(5);
  } else if (taxAmount) {
   taxValue = taxAmount.toFixed(5);
  }

  $('#content').find(trClass).find('.tax_amount').val(taxValue);
 });

//total header & tax amount
// $('#content').on('change', '.line_quantity, .unit_price, .line_price, .tax_amount', function() {
//  var total_tax = 0;
//  $('#form_line').find('.tax_amount').each(function() {
//   total_tax += (+$(this).val());
//   $('#tax_amount').val(total_tax);
//  });
//
//  var header_amount = 0;
//  $('#form_line').find('.line_price').each(function() {
//   header_amount += (+$(this).val());
//   $('#header_amount').val(header_amount);
//  });
// });

//total header & tax amount
 $('#content').on('blur', '.inv_line_quantity, .inv_unit_price, .inv_line_price, .tax_amount', function() {
  var total_tax = 0;
  $('#form_line').find('.tax_amount').each(function() {
   total_tax += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#tax_amount').val(total_tax);

  var header_amount = 0;
  $('#form_line').find('.inv_line_price').each(function() {
   header_amount += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#header_amount').val(header_amount);
 });

//all actions
//Popup for selecting match 
 function match_purchase_order() {
  var ap_transaction_header_id = $("#ap_transaction_header_id").val();
  var supplier_site_id = $("#supplier_site_id").val();
  if (ap_transaction_header_id && supplier_site_id) {
   var link = 'multi_select.php?class_name=ap_po_matching_v&action=match_purchase_order&mode=9&action_class_name=ap_transaction_line&po_status=%3DAPPROVED'
   link += '&ap_transaction_header_id=' + ap_transaction_header_id + '&supplier_site_id=%3D' + supplier_site_id;
   var po_header_id = $("#po_header_id").val();
   var po_number = $("#po_number").val();
   if (po_header_id) {
    link += '&po_header_id=' + po_header_id;
   } else if (po_number) {
    link += '&po_number=' + po_number;
   } else {
    var supplier_id = $("#supplier_id").val();
    link += '&supplier_id=' + supplier_id;
   }
   void window.open(link, '_blank',
    'width=1000,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
   return false;
  } else {
   alert('No Transaction Header ID/nEnter or Save The Header Details ');
  }
 }

 function apply_transaction() {
  var ap_transaction_header_id = $("#ap_transaction_header_id").val();
  var supplier_site_id = $("#supplier_site_id").val();
  if (ap_transaction_header_id && supplier_site_id) {
   var link = 'multi_select.php?class_name=ap_transaction_all_v&action=apply_transaction&mode=9&action_class_name=ap_transaction_cm&transaction_type=%3DINVOICE&account_type=ITEM&po_status=%3DAPPROVED'
   link += '&cm_transaction_header_id=' + ap_transaction_header_id + '&supplier_site_id=%3D' + supplier_site_id;
   var po_header_id = $("#po_header_id").val();
   var po_number = $("#po_number").val();
   if (po_header_id) {
    link += '&po_header_id=' + po_header_id;
   } else if (po_number) {
    link += '&po_number=' + po_number;
   } else {
    var supplier_id = $("#supplier_id").val();
    link += '&supplier_id=' + supplier_id;
   }
   void window.open(link, '_blank',
    'width=1000,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
   return false;
  } else {
   alert('No Transaction Header ID/nEnter or Save The Header Details ');
  }
 }

 function create_accounting() {
  var ap_transaction_header_id = $("#ap_transaction_header_id").val();
  if (ap_transaction_header_id) {
   var link = 'multi_select.php?class_name=ap_transaction_header&action=create_accounting&mode=9&action_class_name=ap_transaction_header&ap_transaction_header_id=' + ap_transaction_header_id;
   localStorage.removeItem("reset_link");
   localStorage.setItem("reset_link", link);
   localStorage.removeItem("jsfile");
   localStorage.setItem("jsfile", "modules/ap/ap_transaction/extra_ap_transaction.js");
   void window.open(link, '_blank',
    'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
   return false;
  } else {
   alert('No Transaction Header ID/nEnter or Save The Header Details ');
  }
 }

 $('#transaction_action').on('change', function() {
  var selected_value = $(this).val();
  switch (selected_value) {
   case 'CREATE_ACCOUNT' :
    create_accounting();
    break;

   case 'MATCH_PO' :
    match_purchase_order();
    break;

   case 'APPLY_TRANSACTION' :
    apply_transaction();
    break;

   default :
    break;
  }
 });


});


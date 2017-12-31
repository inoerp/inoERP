function afterAddNewRow() {
 $("[class^=new_object]").find(':input').not('.agreed_quantity,.agreed_amount,.released_quantity,.released_amount,.line_id,\n\
.po_detail_id,.received_quantity,.accepted_quantity,.delivered_quantity,.invoiced_quantity,.paid_quantity').attr('disabled', false);
}

function afterAddNewDetail() {
 $("[class^=new_object]").find(':input').not('.agreed_quantity,.agreed_amount,.released_quantity,.released_amount,.line_id,\n\
.po_detail_id,.received_quantity,.accepted_quantity,.delivered_quantity,.invoiced_quantity,.paid_quantity').attr('disabled', false);
}


//function to coply line to details
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
 //defalut values
 if (!$('#po_type').val()) {
  $('#po_type').val('STANDARD');
 }

 $('#form_line').find('.line_type').each(function () {
  if (!$(this).val()) {
   $(this).val('GOODS');
  }
 });

 $('body').off('blur', '#release_number').on('blur', '#release_number', function () {
  $('#po_header_id').val('');
  $('#po_status').val('');
  $('#action').val('');
 })

 if ($('#po_type').val() == 'BLANKET') {
  $('.class_detail_form').html('');
  $(this).attr('disabled', true);
 }

 $('body').off('change', '#po_header .po_type').on('change', '#po_header .po_type', function () {
  if ($(this).val() === 'BLANKET') {
   $('.class_detail_form').html('');
   $(this).attr('disabled', true);
  }

  if ($(this).val() === 'CONTRACT') {
   $('#form_line').html('');
   $(this).attr('disabled', true);
  }

  if ($(this).val() === 'BLANKET_RELEASE') {
   getBPAList();
  }
 })

 $('#content').off('change', '#po_number').on('change', '#po_number', function () {
  if ($('#po_type').val() == 'BLANKET_RELEASE') {
   getBPADetails({
    'po_header_id': $(this).find('option:selected').data('ref_po_hedader_id')
   });
  }
 });

 $('body').off('click', '.popup.view-item-config').on('click', '.popup.view-item-config', function (e) {
  e.preventDefault();
  localStorage.removeItem("row_class_b");
  var openUrl = $(this).prop('href') + '&reference_key_name=po_line';
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  if ($('#form_line').find(trClass).find('input.po_line_id').val()) {
   openUrl += '&reference_key_value=' + $('#form_line').find(trClass).find('.po_line_id').val();
  } else {
   if ($('#form_line').find(trClass).find('.org_id').val()) {
    openUrl += '&org_id=' + $('#form_line').find(trClass).find('.org_id').val();
   }
   if ($('#form_line').find(trClass).find('.item_id_m').val()) {
    openUrl += '&item_id_m=' + $('#form_line').find(trClass).find('.item_id_m').val();
   }
  }
  if ($('#form_line').find(trClass).find('.line_quantity').val()) {
   openUrl += '&quantity=' + $('#form_line').find(trClass).find('.line_quantity').val();
  }
  var rowClass = $(this).closest('tr').prop('class');
  localStorage.setItem("row_class_b", rowClass);
  void window.open(openUrl, '_blank',
          'width=1200,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.shipment_number:first').val())) {
  $('.shipment_number:first').val('1');
 }


 //default quantity
 $('#content').off("click", "table.form_line_data_table .add_detail_values_img")
         .on("click", "table.form_line_data_table .add_detail_values_img", function () {
          var lineQuantity = $(this).closest('tr').find('.line_quantity:first').val();
          if (!$(this).closest("td").find(".quantity:first").val())
          {
           $(this).closest("td").find(".quantity:first").val(lineQuantity);
          }
          var trClass = '.' + $(this).closest('tr').attr('class');
          $('body').trigger('getNeedByDate', [trClass]);
         });

//get supplier details
 get_supplier_detail_for_bu();

 $("#content").off("change", "#supplier_site_id").on("change", "#supplier_site_id", function () {
  var supplier_site_id = $("#supplier_site_id").val();
  if (supplier_site_id) {
   getSupplierSiteDetails('modules/ap/supplier/json_supplier.php', supplier_site_id);
  }
 });

 $('body').off("blur", '.receving_org_id')
         .on("blur", '.receving_org_id', function () {
          var receving_org_id = $(this).val();
          var rowTrClass = $(this).closest("tr").attr("class");
          var classValue = "tr." + rowTrClass;
          var classValue1 = classValue.replace(/ /g, '.');
          getAllInventoryAccounts('modules/org/inventory/json_inventory.php', receving_org_id, classValue1);
         });

 $('body').on('click', '.account_combination', function () {
  if ($(this).val()) {
   //ignore the code  
  } else {

   //find the code combination
   var rowTrClass = $(this).closest("tr.line_rows").attr("class");
   var classValue = "tr." + rowTrClass;
   var classValue1 = classValue.replace(/ /g, '.');
   var receving_org_id = $(classValue1).find('.receving_org_id').val();
   getAllInventoryAccounts('modules/org/inventory/json_inventory.php', receving_org_id, classValue1);
  }

 })

//get locators on changing sub inventory
 $('#content').off('change', '.subinventory_id')
         .on('change', '.subinventory_id', function () {
          var trClass = '.' + $(this).closest('tr').attr('class');
          var subinventory_value = $(this).val();
          getLocator('modules/inv/locator/json_locator.php', subinventory_value, 'subinventory', trClass);
         });

//get Subinventory Name
 $("#form_line").off("change", '.receving_org_id').on("change", '.receving_org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $(this).val()
  });
 });

 //selecting PO Header Id
 $(".po_header_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=po_all_v', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//Get the release number on refresh button click
 $('a.show.ref_po_header_id').click(function () {
  var ref_po_header_id = $('#ref_po_header_id').val();
  var release_number = $('#release_number').val();
  $(this).attr('href', modepath() + 'ref_po_header_id=' + ref_po_header_id + '&release_number=' + release_number);

 });

 copy_line_to_details();

 $('body').off('change', '#bu_org_id').on('change', '#bu_org_id', function () {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && (!$('#po_header_id').val()) && ($('#bu_org_id').attr('disabled') !== 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }


//
 //exhhnge rate
 $('body').on('change', '#doc_currency', function () {
  if ($(this).val() !== $('#currency').val()) {
   $('#exchange_rate').prop('required', true).css('background', 'rgba(233, 209, 234, 0.61)');
  }
 });

 if ($('#currency').val() == $('#doc_currency').val()) {
  $('#exchange_rate').val('1');
 } else if ((!$('#exchange_rate').val()) && $('#currency').val() != $('#doc_currency').val()) {
  getExchangeRate();
 }

 $('body').off('change', '#currency, #doc_currency, #exchange_rate_type')
         .on('change', '#currency, #doc_currency, #exchange_rate_type', function () {
          getExchangeRate();
         });

//set the line price
 $('#form_line').off('change', '.item_id_m, .item_number, .price_list_header_id, .price_date')
         .on('change', '.item_id_m, .item_number, .price_list_header_id, .price_date', function () {
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

 //get tax code
 $('#content').off('change', 'bu_org_id').on('change', 'bu_org_id', function () {
  var org_id = $(this).val();
  getTaxCodes('modules/mdm/tax_code/json_tax_code.php', org_id, 'IN');
 });
 if ($('#bu_org_id').val() && (!$('#po_header_id').val())) {
  getTaxCodes('modules/mdm/tax_code/json_tax_code.php', $('#bu_org_id').val(), 'IN');
 }


 $('#form_line .received_quantity').each(function () {
  if ($(this).val()) {
   var trClass = '.' + $(this).closest('td.add_detail_values').closest('tr').attr('class').replace(/\+s/g, '.');
   $('#form_line').find(trClass).find(':input').not('.date,.allow_change').attr('disabled', true);
  }
 });

 $("body").off("click", ".add_row_img").on("click", ".add_row_img", function () {
  $("[class^=new_object]").find(':input').not('.agreed_quantity,.agreed_amount,.released_quantity,.released_amount,.line_id,\n\
.po_detail_id,.received_quantity,.accepted_quantity,.delivered_quantity,.invoiced_quantity,.paid_quantity').attr('disabled', false).removeAttr('readonly').removeAttr('disabled');

 });

 $("body").off("click", ".add_row_detail_img").on("click", ".add_row_detail_img", function () {
  $("[class^=new_object]").find(':input').not('.agreed_quantity,.agreed_amount,.released_quantity,.released_amount,.line_id,\n\
.po_detail_id,.received_quantity,.accepted_quantity,.delivered_quantity,.invoiced_quantity,.paid_quantity').attr('disabled', false).removeAttr('readonly').removeAttr('disabled');

 });

//get GL Price form line price & exchage rate
 $('body').on('getGlPrice', function (e, trClass) {
  if ($('#exchange_rate').val()) {
   var exch_rate = +$('#exchange_rate').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  } else {
   exch_rate = 1;
  }
  if ($('#form_line').find(trClass).find('.line_price').val()) {
   var gl_line_price_val = (+$('#form_line').find(trClass).find('.line_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1")) * exch_rate;
  } else {
   var gl_line_price_val = 0;
  }
  gl_line_price_val = gl_line_price_val.toFixed(5);
  $('#form_line').find(trClass).find('.gl_line_price').val(gl_line_price_val);

  if ($('#form_line').find(trClass).find('.tax_amount').val()) {
   var gl_tax_amount_val = (+$('#form_line').find(trClass).find('.tax_amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1")) * exch_rate;
  } else {
   var gl_tax_amount_val = 0;
  }
  gl_tax_amount_val = gl_tax_amount_val.toFixed(5);
  $('#form_line').find(trClass).find('.gl_tax_amount').val(gl_tax_amount_val);

 });


 $('body').on('calculateTax', function (e, trClass) {
  var linePrice = +$('#content').find(trClass).find('.line_price').val();
  var taxAmount = 0;
  var taxPercentage = 0;
  var taxValue = 0;

  if ($('#content').find(trClass).find('.tax_code_id').val()) {
   taxPercentage = $('#content').find(trClass).find('.tax_code_id').find('option:selected').data('percentage');
   taxAmount = $('#content').find(trClass).find('.tax_code_id').find('option:selected').data('amount');
  }
  if (taxPercentage) {
   taxValue = ((taxPercentage * linePrice) / 100).toFixed(5);
  } else if (taxAmount) {
   taxValue = taxAmount.toFixed(5);
  }

  $('#content').find(trClass).find('.tax_amount').val(taxValue);
 });

 //total header & tax amount
 $('body').on('calculateHeaderAmount', function () {
  var total_tax = 0;
  $('#form_line').find('.tax_amount').each(function () {
   total_tax += (+$(this).val());
   $('#tax_amount').val(total_tax);
  });
  var header_amount = 0;
  $('#form_line').find('.line_price').each(function () {
   header_amount += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#header_amount').val(header_amount);
 });


 //total header & tax amount
 $('body').on('getNeedByDate', function (e, trClass) {
  var today = new Date();
  var dd = today.getDate();
  var mm = today.getMonth() + 1; //January is 0!
  var yyyy = today.getFullYear();

  if ($(trClass).find('.processing_lt').val()) {
   var processing_lt = +$(trClass).find('.processing_lt').val();
  } else {
   var processing_lt = 0;
  }
  var newDate = (dd + (processing_lt));
  var cd = new Date(yyyy, mm, newDate);
  var foramtedDate = cd.getFullYear() + '-' + cd.getMonth() + '-' + cd.getDate();
  $(trClass).find('.need_by_date').val(foramtedDate);
  $(trClass).find('.promise_date').val(foramtedDate);
 });

 $('#content').off('keyup', '.receving_org_id, .item_id_m, .item_number')
         .on('keyup', '.receving_org_id, .item_id_m, .item_number', function () {
          var item_id_m = $(this).closest('tr').find('.item_id_m').val();
          var receving_org_id = $(this).closest('tr').find('.receving_org_id').val();
          if (receving_org_id && item_id_m) {
           getItemRevision({
            'org_id': $(this).closest('tr').find('.receving_org_id').val(),
            'item_id_m': $(this).closest('tr').find('.item_id_m').val(),
            'trclass': $(this).closest('tr').attr('class')
           });
          }
         });

 po_calculate_all_amounts();
 lineDetail_QuantityValidation(po_calculate_amounts_withLinePrice);
});

function po_calculate_all_amounts() {
 //calucalte line & tax amounts
 $('body').off('keyup', '.unit_price, .line_quantity , .line_price')
         .on('keyup', '.unit_price, .line_quantity , .line_price ', function () {
          po_calculate_amounts_withLinePrice($(this));
         });

 //calculate the tax amount
 $('body').off('keyup', '.line_quantity, .unit_price, .line_price, .tax_amount, .tax_code_id')
         .on('keyup, change', '.line_quantity, .unit_price, .line_price, .tax_amount, .tax_code_id', function () {
          po_calculate_amounts($(this));
         });

//total header & tax amount

}
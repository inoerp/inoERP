function setValFromSelectPage(am_wo_header_id, wo_number, org_id) {
 this.am_wo_header_id = am_wo_header_id;
 this.wo_number = wo_number;
 this.org_id = org_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var wo_obj = [{id: 'am_wo_header_id', data: this.am_wo_header_id},
  {id: 'wo_number', data: this.wo_number},
  {id: 'org_id', data: this.org_id}
 ];

 $(wo_obj).each(function (i, value) {
  if (value.data) {
   var fieldId = '#' + value.id;
   $('#content').find(fieldId).val(value.data);
  }
 });
  if (this.am_wo_header_id) {
    $('a.show.am_wo_header_id').trigger('click');
 }
};

function serial_details(generation_type, trClass) {
 var trClass_d = '.' + trClass;
 if (!generation_type) {
  var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
  $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
  $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
  return;
 }
 var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
 if (!itemIdM) {
  return;
 }


 switch ($('#transaction_type_id').val()) {
  case '25' :
   $.when(getSerialNumber({
    'org_id': $('#org_id').val(),
    'status': 'IN_WIP',
    'item_id_m': itemIdM,
    'trclass': trClass
   })).then(function (data, textStatus, jqXHR) {
    if ($.trim(data) == 'false' || $.trim(data) == 'undefined') {
     alert('No Serial Number Found!\nCheck the subinventory, locator and item number');
    }
   });

   break;

  case '24' :
   $.when(getSerialNumber({
    'org_id': $('#org_id').val(),
    'status': 'IN_STORE',
    'item_id_m': itemIdM,
    'trclass': trClass,
    'subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
    'locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
   })).then(function (data, textStatus, jqXHR) {
    if ($.trim(data) == 'false' || $.trim(data) == 'undefined') {
     alert('No Serial Number Found!\nCheck the subinventory, locator and item number');
    }
   });

   break;

  case 'undefined' :
  case '' :
   alert('Enter the transaction type');
   break;
 }

 $('#content').find(trClass_d).find('.serial_number, .inv_serial_number_id').attr('required', true).css('background-color', 'pink');
}

function callGetLocatorForFrom(subinventory_id, rowIdValue) {
 var subinventory_type = "from_subinventory_id";
 getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
}
function callGetLocatorForTo(subinventory_id, rowIdValue) {
 var subinventory_type = "to_subinventory_id";
 getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
}

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'am_wo_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "transaction_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Transaction Type"];
// mandatoryCheck.mandatoryField();

 $('body').off("change", ".from_subinventory_id").on("change", ".from_subinventory_id", function () {
  var rowIdValue = $(this).closest("tr").attr("id");
  var idValue = "tr#" + rowIdValue;
  var subinventory_id = $(this).val();
  callGetLocatorForFrom(subinventory_id, idValue);
 });
 $('body').off("change", ".to_subinventory_id").on("change", ".to_subinventory_id", function () {
  var rowIdValue = $(this).closest("tr").attr("id");
  var idValue = "tr#" + rowIdValue;
  var subinventory_id = $(this).val();
  callGetLocatorForTo(subinventory_id, idValue);
 });


 var document_type = 'Work Order';
 var reference = 'am_wo_header_id';
 var documentNumber = $('#wo_number').val();
 var documentId = $('#am_wo_header_id').val();

// addOrShow_lineDetails('tr.inv_transaction_row0');
// onClick_addDetailLine(1, '.add_row_detail_img');
 onClick_addDetailLine(2, '.add_row_detail_img1');


 $('#content').off('blur', '.bom_sequence').on('blur', '.bom_sequence', function () {
  if (!$('#allData tr').length) {
   alert('No BOM found for the work order#' + $('#wo_number').val());
   $(this).val('');
   return false;
  }

  var bomSeq = $(this).val();
  var trClass = '.' + $(this).closest('tr').attr('class');
  var bomId = $('#allData tr.' + bomSeq).find('.am_wo_bom_id').val();
  var transaction_type_id = $('#transaction_type_id').val();
  $(this).closest('tr').find('.am_wo_bom_id').val(bomId);
  $(this).closest('.tabContainer').find(trClass).find('.am_wo_bom_id').val(bomId);

  var itemId = $('#allData tr.' + bomSeq).find('.component_item_id_m').val();
  $(this).closest('tr').find('.item_id_m').val(itemId);

  var item_number = $('#allData tr.' + bomSeq).find('.component_item_number').val();
  $(this).closest('tr').find('.item_number').val(item_number);

  var item_description = $('#allData tr.' + bomSeq).find('.component_description').val();
  $(this).closest('tr').find('.item_description').val(item_description);

  var uom_id = $('#allData tr.' + bomSeq).find('.component_uom').val();
  $(this).closest('tr').find('.uom_id').val(uom_id);
  var subinventory_id = $('#allData tr.' + bomSeq).find('.supply_sub_inventory').val();
  var locator_html = $('#allData tr.' + bomSeq).find('.supply_locator').html();
  if (transaction_type_id == 24) {
   $(this).closest('.tabContainer').find(trClass).find('.from_subinventory_id').val(subinventory_id);
   $(this).closest('.tabContainer').find(trClass).find('.from_locator_id').empty().append(locator_html);
   $(this).closest('.tabContainer').find(trClass).find('.to_subinventory_id').val('');
   $(".to_subinventory_id").attr("disabled", true);
   $(".to_locator_id").attr("disabled", true);
  }
  else if (transaction_type_id == 25) {
   $(this).closest('.tabContainer').find(trClass).find('.to_subinventory_id').val(subinventory_id);
   $(this).closest('.tabContainer').find(trClass).find('.to_locator_id').empty().append(locator_html);
   $(this).closest('.tabContainer').find(trClass).find('.from_subinventory_id').val('');
   $(".from_subinventory_id").attr("disabled", true);
   $(".from_locator_id").attr("disabled", true);
  } else {
   $(this).closest('.tabContainer').find(trClass).find('.to_subinventory_id').val('');
   $(this).closest('.tabContainer').find(trClass).find('.from_subinventory_id').val('');
   $(".from_subinventory_id").attr("disabled", true);
   $(".from_locator_id").attr("disabled", true);
   $(".to_subinventory_id").attr("disabled", true);
   $(".to_locator_id").attr("disabled", true);
  }

  $(this).closest('.tabContainer').find(trClass).find('.document_type').val(document_type);
  $(this).closest('.tabContainer').find(trClass).find('.document_number').val(documentNumber);
  $(this).closest('.tabContainer').find(trClass).find('.document_id').val(documentId);
  $(this).closest('.tabContainer').find(trClass).find('.reference_type').val('table');
  $(this).closest('.tabContainer').find(trClass).find('.reference_key_name').val('am_wo_header');
  $(this).closest('.tabContainer').find(trClass).find('.reference_key_value').val(documentId);
  $(this).closest('.tabContainer').find(trClass).find('.reference').val(reference);
  var lot_generation = $('#allData tr.' + bomSeq).find('.lot_generation').val();
  $(this).closest('.tabContainer').find(trClass).find('.lot_generation').val(lot_generation);
  var serial_generation = $('#allData tr.' + bomSeq).find('.serial_generation').val();
  $(this).closest('.tabContainer').find(trClass).find('.serial_generation').val(serial_generation);
  serial_details(serial_generation, $(this).closest('tr').attr('class'));
 });

 $('body').off("blur", '#transaction_type_id').on("blur", '#transaction_type_id', function () {
  $("tr.transfer_info").find("td select").each(function () {
   $(this).val("");
  });
  var transaction_type_id = $(this).val();
  switch (transaction_type_id) {
   case "24":
    $(".from_subinventory_id").attr("disabled", false);
    $(".from_locator_id").attr("disabled", false);
    $(".to_subinventory_id").attr("disabled", true);
    $(".to_locator_id").attr("disabled", true);
    break;

   case "25":
    $(".to_subinventory_id").attr("disabled", false);
    $(".to_locator_id").attr("disabled", false);
    $(".from_subinventory_id").attr("disabled", true);
    $(".from_locator_id").attr("disabled", true);
    break;

   default:
    $(".to_subinventory_id").attr("disabled", false);
    $(".to_locator_id").attr("disabled", false);
    $(".from_subinventory_id").attr("disabled", false);
    $(".from_locator_id").attr("disabled", false);
  }

 });

 $('#content').off('blur', '.from_subinventory_id, .from_locator_id')
         .on('blur', '.from_subinventory_id, .from_locator_id', function () {
          var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
          var trClass_d = '.' + trClass;
          var generation_type = $('#content').find(trClass_d).find('.serial_generation').val();

          if (!generation_type) {
           var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
           $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
           $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
           return;
          }
          var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
          if (!itemIdM) {
           return;
          }

          getSerialNumber({
           'org_id': $('#org_id').val(),
           'status': 'IN_STORE',
           'item_id_m': itemIdM,
           'trclass': trClass,
           'subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
           'locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
          });
         });

 $('#content').off('blur', '.subinventory_id, .locator_id')
         .on('blur', '.subinventory_id, .locator_id', function () {
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

          var subinventory_id = null;
          var locator_id = null;

          switch ($('#transaction_type_id').val()) {
           case '24':
            subinventory_id = $('#content').find(trClass_d).find('.from_subinventory_id').val();
            locator_id = $('#content').find(trClass_d).find('.from_locator_id').val();
            getlotNumber({
             'org_id': $('#from_org_id').val(),
             'status': 'ACTIVE',
             'item_id_m': itemIdM,
             'trclass': trClass,
             'subinventory_id': subinventory_id,
             'locator_id': locator_id
            });
            break;

           case '25':
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

           default :
            break;
          }


         });



 //selecting wo header id data
 $('body').off("click", '.am_wo_header_id.select_popup')
         .on("click", '.am_wo_header_id.select_popup', function () {
          var openUrl = 'select.php?class_name=am_wo_header&wo_status=%3DRELEASED';
          void window.open(openUrl, '_blank',
                  'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
         });

 $('body').off('click', 'a.am_material_transaction_id').on('click', 'a.am_material_transaction_id', function (e) {
  e.preventDefault();
  var transaction_type_id = $('#transaction_type_id').val();
  var am_wo_header_id = $('#am_wo_header_id').val();
  var wo_number = $('#wo_number').val();
  var link = '&transaction_type_id=' + transaction_type_id;
  if (am_wo_header_id) {
   link += '&am_wo_header_id=' + am_wo_header_id;
  } else if (wo_number) {
   link += '&wo_number=' + wo_number;
  }
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + link;
  getFormDetails(formUrl);
 }).one();


 //get Subinventory on Inventory change
 $('#content').off('blur', '#org_id').on('blur', '#org_id', function () {
  var orgId = $(this).val();
  if (orgId) {
   getSubInventory({
    json_url: 'modules/inv/subinventory/json_subinventory.php',
    org_id: orgId
   });
  }
 });

 //get locatot on Subinventory change
 $('#content').off('blur', '.sub_inventory').on('blur', '.sub_inventory', function () {
  var subInventoryId = $(this).val();
  if (subInventoryId > 0) {
   var trClass = '.' + $(this).closest('tr').attr('class');
   getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'subinventory', trClass);
  }
 });


});
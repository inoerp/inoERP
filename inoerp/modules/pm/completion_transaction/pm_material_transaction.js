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
  case '7' :
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

  case '6' :
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
 mandatoryCheck.header_id = 'wip_wo_header_id';
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
 var reference = 'wip_wo_header_id';
 var documentNumber = $('#wo_number').val();
 var documentId = $('#wip_wo_header_id').val();

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
  var bomId = $('#allData tr.' + bomSeq).find('.wip_wo_bom_id').val();
  var transaction_type_id = $('#transaction_type_id').val();
  $(this).closest('tr').find('.wip_wo_bom_id').val(bomId);
  $(this).closest('.tabContainer').find(trClass).find('.wip_wo_bom_id').val(bomId);

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
  if (transaction_type_id == 6) {
   $(this).closest('.tabContainer').find(trClass).find('.from_subinventory_id').val(subinventory_id);
   $(this).closest('.tabContainer').find(trClass).find('.from_locator_id').empty().append(locator_html);
   $(this).closest('.tabContainer').find(trClass).find('.to_subinventory_id').val('');
   $(".to_subinventory_id").attr("disabled", true);
   $(".to_locator_id").attr("disabled", true);
  }
  else if (transaction_type_id == 7) {
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
  $(this).closest('.tabContainer').find(trClass).find('.reference_key_name').val('wip_wo_header');
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
   case "6":
    $(".from_subinventory_id").attr("disabled", false);
    $(".from_locator_id").attr("disabled", false);
    $(".to_subinventory_id").attr("disabled", true);
    $(".to_locator_id").attr("disabled", true);
    break;

   case "7":
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
           case '6':
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

           case '7':
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



 $('body').off('click', 'a.pm_material_transaction_id').on('click', 'a.pm_material_transaction_id', function (e) {
  e.preventDefault();
  var transaction_type_id = $('#transaction_type_id').val();
  var pm_batch_header_id = $('#pm_batch_header_id').val();
  var org_id = $('#org_id').val();
  var batch_name = $('#batch_name').val();
  var link = '&transaction_type_id=' + transaction_type_id;
  if (pm_batch_header_id) {
   link += '&pm_batch_header_id=' + pm_batch_header_id;
  } else if (batch_name) {
   link += '&batch_name=' + batch_name;
  }
  link += '&org_id=' + org_id;
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



 //Get the primary_id on refresh button click
// $('a.show.wip_wo_headerid_show').click(function () {
//  var wip_wo_header_id = $('#wip_wo_header_id').val();
//  var transaction_type_id = $('#transaction_type_id').val();
//  var wo_number = $('#wo_number').val();
//  var link = 'transaction_type_id=' + transaction_type_id;
//  if (wip_wo_header_id) {
//   link += '&wip_wo_header_id=' + wip_wo_header_id;
//  } else if (wo_number) {
//   link += '&wo_number=' + wo_number;
//  }
//  $(this).attr('href', modepath() + link);
// });

// function popup() {
//  $("#content").on("click", ".popup.itemId", function () {
//   var idValue = $(this).closest("tr").attr("id");
//   localStorage.idValue = idValue;
//   var link = '../../inv/item/find_item.php?org_id=' + $("#org_id").val() + '&RowDivId=' + idValue;
//   void window.open(link, '_blank',
//           'width=900,height=900,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
//   return false;
//  }).one();
// }
// popup();

//add new line
// onClick_add_new_row('tr.inv_transaction_row0', 'tbody.inv_transaction_values', 4);
// $("#content").on("click", ".add_row_img", function () {
//  var addNewRow = new add_new_rowMain();
//  addNewRow.trClass = 'inv_transaction_row';
//  addNewRow.tbodyClass = 'form_data_line_tbody';
//  addNewRow.noOfTabs = 5;
//  addNewRow.removeDefault = false;
//  addNewRow.add_new_row();
// });

});


function callGetLocatorForFrom(subinventory_id, rowIdValue) {
 var subinventory_type = "from_subinventory_id";
 getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
}
function callGetLocatorForTo(subinventory_id, rowIdValue) {
 var subinventory_type = "to_subinventory_id";
 getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
}

function changeSubLoc(transaction_type_id, trClass) {
 if (transaction_type_id === 32) {
  $(trClass).find('.from_subinventory_id, .from_locator_id').val('').removeAttr('disabled');
  $(trClass).find('.to_subinventory_id, .to_locator_id').attr("disabled", true);
 }
 else if (transaction_type_id === 31) {
  $(trClass).find('.to_subinventory_id, .to_locator_id').val('').removeAttr('disabled');
  $(trClass).find('.from_subinventory_id, .from_locator_id').attr("disabled", true);
 }
}

$(document).ready(function () {

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


 var document_type = 'Batch';
 var reference = 'pm_batch_header_id';
 var documentNumber = $('#batch_name').val();
 var documentId = $('#pm_batch_header_id').val();

// addOrShow_lineDetails('tr.inv_transaction_row0');
// onClick_addDetailLine(1, '.add_row_detail_img');
 onClick_addDetailLine(2, '.add_row_detail_img1');


 $('body').off('blur', '.bom_sequence').on('blur', '.bom_sequence', function () {
  var transaction_type_id = +$('#transaction_type_id').val();
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  if ($(this).find('option:selected').val() == 'undefined' || $(this).find('option:selected').val() == "") {
   $(trClass).find('.item_description,.item_number,.item_id_m,.uom_id, .step_no, .serial_generation .lot_generation').val('');
   return false;
  } else {
   var selected = $(this).find('option:selected');
   $(trClass).find('.item_description').val($(selected).data('item_description'));
   $(trClass).find('.item_number').val($(selected).data('item_number'));
   $(trClass).find('.line_type').val($(selected).data('line_type'));
   $(trClass).find('.line_type_code').val($(selected).data('line_type_code'));
   $(trClass).find('.item_id_m').val($(selected).data('item_id_m'));
   $(trClass).find('.uom_id').val($(selected).data('uom_id'));
   $(trClass).find('.step_no').val($(selected).data('step_no'));
   $(trClass).find('.serial_generation').val($(selected).data('serial_generation'));
   $(trClass).find('.lot_generation').val($(selected).data('lot_generation'));
   $(trClass).find('.line_id').val($(selected).val());
   $(trClass).find('.planned_quantity').val($(selected).data('planned_quantity'));
   $(trClass).find('.actual_quantity').val($(selected).data('actual_quantity'));

  }

  changeSubLoc(transaction_type_id, trClass);

 });


 $('body').off('change', '#transaction_type_id').on('change', '#transaction_type_id', function () {
  var transaction_type_id = +$('#transaction_type_id').val();
  $('body').find('.bom_sequence').each(function () {
   var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
   changeSubLoc(transaction_type_id, trClass);
  });
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
           case '29':
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

           case '30':
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



 $('body').off('click', 'a.pm_completion_transaction_id').on('click', 'a.pm_completion_transaction_id', function (e) {
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


});


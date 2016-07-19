//function setValFromSelectPage(wip_wo_header_id, item_id_m, item_number, item_description,
//        uom_id, processing_lt, wip_wol_transaction_id) {
// this.wip_wo_header_id = wip_wo_header_id;
// this.item_id_m = item_id_m;
// this.item_number = item_number;
// this.item_description = item_description;
// this.uom_id = uom_id;
// this.processing_lt = processing_lt;
// this.wip_wol_transaction_id = wip_wol_transaction_id;
//}
//
//setValFromSelectPage.prototype.setVal = function () {
// if (this.wip_wo_header_id) {
//  $("#wip_wo_header_id").val(this.wip_wo_header_id);
// }
// var rowClass = '.' + localStorage.getItem("row_class");
// var itemType = localStorage.getItem("itemType");
// rowClass = rowClass.replace(/\s+/g, '.');
//
//
// var item_obj = [{id: 'item_id_m', data: this.item_id_m},
//  {id: 'item_number', data: this.item_number},
//  {id: 'item_description', data: this.item_description},
//  {id: 'uom', data: this.uom_id},
//  {id: 'processing_lt', data: this.processing_lt}
// ];
//
// var component_obj = [{id: 'component_item_id_m', data: this.item_id_m},
//  {id: 'component_item_number', data: this.item_number},
//  {id: 'component_description', data: this.item_description},
//  {id: 'component_uom', data: this.uom_id}
// ];
//
// if (localStorage.getItem("li_divId")) {
//  var li_divId = '#' + localStorage.getItem("li_divId");
//  $(item_obj).each(function (i, value) {
//   if (value.data) {
//    var fieldId = '#' + value.id;
//    $('#content').find(fieldId).val(value.data);
//   }
//  });
// } else {
//  $(component_obj).each(function (i, value) {
//   if (value.data) {
//    var fieldClass = '.' + value.id;
//    $('#content').find(rowClass).find(fieldClass).val(value.data);
//   }
//  });
// }
// localStorage.removeItem("row_class");
// localStorage.removeItem("field_class");
// localStorage.removeItem("li_divId");
// localStorage.removeItem("itemType");
// if(this.wip_wol_transaction_id){
//  $('#wip_wol_transaction_id').val(this.wip_wol_transaction_id);
////  $('#wip_wol_transaction_id').trigger('click');
// }
//};


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
  case '12' :
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

  case '10' :
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
 

// $('body').off("blur", '#transaction_type_id').on("blur", '#transaction_type_id', function () {
//  $("tr.transfer_info").find("td select").each(function () {
//   $(this).val("");
//  });
//  var transaction_type_id = $(this).val();
//  switch (transaction_type_id) {
//   case "6":
//    $(".from_subinventory_id").attr("disabled", false);
//    $(".from_locator_id").attr("disabled", false);
//    $(".to_subinventory_id").attr("disabled", true);
//    $(".to_locator_id").attr("disabled", true);
//    break;
//
//   case "7":
//    $(".to_subinventory_id").attr("disabled", false);
//    $(".to_locator_id").attr("disabled", false);
//    $(".from_subinventory_id").attr("disabled", true);
//    $(".from_locator_id").attr("disabled", true);
//    break;
//
//   default:
//    $(".to_subinventory_id").attr("disabled", false);
//    $(".to_locator_id").attr("disabled", false);
//    $(".from_subinventory_id").attr("disabled", false);
//    $(".from_locator_id").attr("disabled", false);
//  }
//
// });

 $('#form_line').off('blur', '.from_subinventory_id, .from_locator_id')
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

 $('#form_line').off('blur', '.subinventory_id, .locator_id')
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


 $('body').off('click', 'a.show2.wip_wol_transaction_id').on('click', 'a.show2.wip_wol_transaction_id', function (e) {
  e.preventDefault();
  var transaction_type_id = $('#transaction_type_id').val();
  var org_id = $('#org_id').val();
  var item_id_m = $('#item_id_m').val();
  var revision_name = $('#revision_name').val();
  var link = '&transaction_type_id=' + transaction_type_id;
  if (item_id_m) {
   link += '&item_id_m=' + item_id_m;
  } 
  if (org_id) {
   link += '&org_id=' + org_id;
  }
    if (revision_name) {
   link += '&revision_name=' + revision_name;
  }
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + link;
  getFormDetails(formUrl);
 }).one();



 $('#content').off('blur', '#org_id, #item_number').on('blur', '#org_id, #item_number', function () {
  if ($('#org_id').val() && $('#item_id_m').val()) {
   getItemRevision({
    'org_id': $('#org_id').val(),
    'item_id_m': $('#item_id_m').val(),
    'show_date': false
   });
  }

 });

 //get Subinventory Name
 $('body').off("change",'#org_id').on("change",'#org_id' ,function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $("#org_id").val()
  });
  getWipAccountingGroup('modules/wip/accounting_group/json_accounting_group.php', $("#org_id").val());
  $('.org_id').val($(this).val());
 });


 //get locatot on Subinventory change in form header
 $('#form_header').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var subInventoryId = $(this).val();
  if (subInventoryId > 0) {
   getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'oneSubinventory', '');
  }
 });

 //get locatot on Subinventory change
 $('#form_line').off('blur', '.sub_inventory').on('blur', '.sub_inventory', function () {
  var subInventoryId = $(this).val();
  if (subInventoryId > 0) {
   var trClass = '.' + $(this).closest('tr').attr('class');
   getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'subinventory', trClass);
  }
 });

$('body').off('blur','#quantity').on('blur','#quantity', function(){
var complQty =  $(this).val();
  $('#form_line').find('.usage_quantity').each(function(){
    if($(this).val()){
    $(this).closest('td').find('.final_quantity').val($(this).val()*complQty);
    }
  });
  
});

 $('body').off("click", '.wip_wol_transaction_id.select_popup').on("click", '.wip_wol_transaction_id.select_popup', function() {
	localStorage.idValue = "";
	var link = 'select.php?class_name=wip_wol_transaction';
	void window.open(link, '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});


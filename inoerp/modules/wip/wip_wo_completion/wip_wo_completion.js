function setValFromSelectPage(wip_wo_header_id, wo_number, org_id) {
 this.wip_wo_header_id = wip_wo_header_id;
 this.wo_number = wo_number;
 this.org_id = org_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var wo_obj = [{id: 'wip_wo_header_id', data: this.wip_wo_header_id},
  {id: 'wo_number', data: this.wo_number},
  {id: 'org_id', data: this.org_id}
 ];

 $(wo_obj).each(function(i, value) {
  if (value.data) {
   var fieldId = '#' + value.id;
   $('#content').find(fieldId).val(value.data);
  }
 });
};

function serial_details(generation_type, trClass) {
 var trClass_d = '.' + trClass;
 if (!generation_type) {
  var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
  $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
  $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
  alert('Item is not serial controlled.\nNo serial informatio \'ll be saved in database');
  return;
 }
 var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
 if (!itemIdM) {
  return;
 }


 switch ($('#transaction_type_id').val()) {
  case '7' :
   getSerialNumber({
    'org_id': $('#org_id').val(),
    'status': 'IN_WIP',
    'item_id_m': itemIdM,
    'trclass': trClass
   });
   break;

  case '6' :
   getSerialNumber({
    'org_id': $('#org_id').val(),
    'status': 'IN_STORE',
    'item_id_m': itemIdM,
    'trclass': trClass,
    'subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
    'locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
   });
   break;

  case 'undefined' :
  case '' :
   alert('Enter the transaction type');
   break;
 }


}

function callGetLocatorForFrom(subinventory_id, rowIdValue) {
 var subinventory_type = "from_subinventory_id";
 getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
}
function callGetLocatorForTo(subinventory_id, rowIdValue) {
 var subinventory_type = "to_subinventory_id";
 getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
}

function serial_detils(){
 
}

$(document).ready(function() {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'wip_wo_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["wip_wo_header_id", "transaction_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Transaction Type"];

 $('#content').on('change', '.quantity', function() {
  var enteredQty = $(this).val();
  var availableQty = $(this).closest('tr').find('.available_quantity').val();
  if (+enteredQty > +availableQty) {
   $(this).val('');
   alert('Entered quantity is more than available quantity');
  }
 });

 function enableDisable() {
  var transaction_type_id = $('#transaction_type_id').val();
  switch (transaction_type_id) {
   case "13":
    $(".from_subinventory_id").attr("disabled", false);
    $(".from_locator_id").attr("disabled", false);
    $(".to_subinventory_id").attr("disabled", true);
    $(".to_locator_id").attr("disabled", true);
    $(".to_subinventory_id").val('');
    $(".to_locator_id").val('');
    break;

   case "11":
    $(".to_subinventory_id").attr("disabled", false);
    $(".to_locator_id").attr("disabled", false);
    $(".from_subinventory_id").attr("disabled", true);
    $(".from_locator_id").attr("disabled", true);
    $(".from_subinventory_id").val('');
    $(".from_locator_id").val('');
    break;

   default:
    $(".to_subinventory_id").attr("disabled", true);
    $(".to_locator_id").attr("disabled", true);
    $(".from_subinventory_id").attr("disabled", true);
    $(".from_locator_id").attr("disabled", true);
    $(".to_subinventory_id").val('');
    $(".to_locator_id").val('');
    $(".from_subinventory_id").val('');
    $(".from_locator_id").val('');
  }
 }

 enableDisable();

 $("#transaction_type_id").on("blur", function() {
  enableDisable();
 });

 //selecting wo header id data
 $(".wip_wo_header_id.select_popup").on("click", function() {
  localStorage.idValue = "";
  var link = 'select.php?class_name=wip_wo_header&wo_status=%3DRELEASED';
  void window.open(link, '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 //Get the primary_id on refresh button click
 $('a.show.wip_wo_headerid_show').click(function() {
  var wip_wo_header_id = $('#wip_wo_header_id').val();
  var transaction_type_id = $('#transaction_type_id').val();
  var wo_number = $('#wo_number').val();
  var link = 'transaction_type_id=' + transaction_type_id;
  if (wip_wo_header_id) {
   link += '&wip_wo_header_id=' + wip_wo_header_id;
  } else if (wo_number) {
   link += '&wo_number=' + wo_number;
  }
  $(this).attr('href', modepath() + link);

 });

 addOrShow_lineDetails('tr.inv_transaction_row0');
 onClick_addDetailLine(1);

 $(".form_line_data_table").on("change", ".from_subinventory_id", function() {
  var rowIdValue = $(this).closest("tr").attr("id");
  var idValue = "tr#" + rowIdValue;
  var subinventory_id = $(this).val();
  callGetLocatorForFrom(subinventory_id, idValue);
 });
 $(".form_line_data_table").on("change", ".to_subinventory_id", function() {
  var rowIdValue = $(this).closest("tr").attr("id");
  var idValue = "tr#" + rowIdValue;
  var subinventory_id = $(this).val();
  callGetLocatorForTo(subinventory_id, idValue);
 });

 $('#content').on('blur', '.quantity, .subinventory_id, .locator_id', function() {
  var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
  var trClass_d = '.' + trClass;
  var generation_type = $('#content').find(trClass_d).find('.serial_generation').val();

  if (!generation_type) {
   var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
   $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
   $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
   alert('Item is not serial controlled.\nNo serial informatio \'ll be saved in database');
   return;
  } else if (generation_type != 'PRE_DEFINED') {
   var field_stmt = '<input class="textfield serial_number" type="text" size="25" name="serial_number[]" >';
   $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
   $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
  }
  var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
  if (!itemIdM) {
   return;
  }
  switch ($('#transaction_type_id').val()) {
   case '11' :
    if (generation_type === 'PRE_DEFINED') {
     $.when(getSerialNumber({
      'org_id': $('#org_id').val(),
      'status': 'DEFINED',
      'item_id_m': itemIdM,
      'trclass': trClass
     })).then(function(data, textStatus, jqXHR) {
      if ($.trim(data) == 'false' || $.trim(data) == 'undefined') {
       alert('No Serial Number Found!\nCheck the subinventory, locator and item number');
      }
     });
    }
    break;

   case '13' :
    $.when(getSerialNumber({
     'org_id': $('#org_id').val(),
     'status': 'IN_STORE',
     'item_id_m': itemIdM,
     'trclass': trClass,
     'subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
     'locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
    })).then(function(data, textStatus, jqXHR) {
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

 });

});


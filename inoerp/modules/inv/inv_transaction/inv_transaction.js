function setValFromSelectPage(inv_transaction_header_id, combination, item_id_m, item_number, item_description, uom_id,
 serial_generation, lot_generation) {
 this.inv_transaction_header_id = inv_transaction_header_id;
 this.combination = combination;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.serial_generation = serial_generation;
 this.lot_generation = lot_generation;
}

setValFromSelectPage.prototype.setVal = function() {
 var inv_transaction_header_id = this.inv_transaction_header_id;
 var combination = this.combination;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;

 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (inv_transaction_header_id) {
  $("#inv_transaction_header_id").val(inv_transaction_header_id);
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
 if (this.serial_generation) {
  $('#content').find(rowClass).find('.serial_generation').val(this.serial_generation);
  $('#content').find(rowClass).find('.serial_number').attr('required', true).css('background-color', 'pink');
 }
 if (this.lot_generation) {
  $('#content').find(rowClass).find('.lot_generation').val(this.lot_generation);
  $('#content').find(rowClass).find('.lot_number').attr('required', true).css('background-color', 'pink');
 }
 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");

};

function beforeSave() {
 var retValue = 1;
 $('.add_detail_values').each(function() {
  if ($(this).children('.serial_generation').val()) {
   var trClass = '.' + $(this).closest("tr").attr('class').replace(/\s+/g, '.');
   var qty = +$('#content').find(trClass).find('.quantity').val();
   var noOfSerialIds = 0;
   $(this).closest('td').find('.inv_serial_number_id').each(function() {
    if ($(this).val()) {
     noOfSerialIds++;
    }
   })

   if (noOfSerialIds != qty) {
    var noOfSerials = 0;
    $(this).closest('td').find('.serial_number').each(function() {
     if ($(this).val()) {
      noOfSerials++;
     }
    })
    if (noOfSerials != qty) {
     alert('Can\'t save data as no of serial numbers doesnt match quantity');
     retValue = -10;
     return false;
    }
   }
  }
 });
 return retValue;
}

$(document).ready(function() {
 //mandatory and field sequence
// var mandatoryCheck = new mandatoryFieldMain();
// mandatoryCheck.header_id = 'inv_transaction_header_id';
//// mandatoryCheck.mandatoryHeader();
// mandatoryCheck.form_area = 'form_header';
// mandatoryCheck.mandatory_fields = ["bu_org_id", "transaction_type_id"];
// mandatoryCheck.mandatory_messages = ["First Select BU Org", "First Select Transaction Type"];
//// mandatoryCheck.mandatoryField();


 $("#transaction_type_id").on("change", function() {
  var transaction_type_id = $(this).val();
  $(".transaction_type_id").val(transaction_type_id);
  switch (transaction_type_id) {
   case "1":
    $(".from_subinventory_id").prop("disabled", false);
    $(".from_locator_id").prop("disabled", false);
    $(".account_id").prop("required", true);
    $(".to_subinventory_id").val('');
    $(".to_subinventory_id").prop("disabled", true);
    $(".to_locator_id").val('');
    $(".to_locator_id").prop("disabled", true);
    break;

   case "2":
    $(".to_subinventory_id").prop("disabled", false);
    $(".to_locator_id").prop("disabled", false);
    $(".account_id").prop("required", true);
    $(".from_subinventory_id").val('');
    $(".from_subinventory_id").prop("disabled", true);
    $(".from_locator_id").val("");
    $(".from_locator_id").prop("disabled", true);
    break;

   case "3":
    $(".to_subinventory_id").prop("disabled", false);
    $(".to_locator_id").prop("disabled", false);
    $(".from_subinventory_id").prop("disabled", false);
    $(".from_locator_id").prop("disabled", false);
    break;

   default:
    $(".to_subinventory_id").prop("disabled", true);
    $(".to_locator_id").prop("disabled", true);
    $(".from_subinventory_id").prop("disabled", true);
    $(".from_locator_id").prop("disabled", true);
  }
 });


// //get Subinventory Name
 $("#org_id").on("change", function() {
  $('.org_id').val($(this).val());
  getSubInventory('modules/inv/subinventory/json_subinventory.php', $("#org_id").val());
  $('.org_id').val($(this).val());
 });

 function callGetLocatorForFrom(subinventory_id, rowIdValue) {
  var subinventory_type = "from_subinventory_id";
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
 }

 function callGetLocatorForTo(subinventory_id, rowIdValue) {
  var subinventory_type = "to_subinventory_id";
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
 }

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

// var classSave = new saveMainClass();
// classSave.json_url = 'form.php?class_name=inv_transaction';
// classSave.line_key_field = 'item_id_m';
// classSave.single_line = false;
// classSave.savingOnlyHeader = false;
// classSave.lineClassName = 'inv_transaction';
// classSave.saveMain(beforeSave);

 //add new row in multi action template
 $("#content").on("click", ".add_row_img", function() {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'inv_transaction_line';
  addNewRow.tbodyClass = 'form_data_line_tbody';
  addNewRow.noOfTabs = 5;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

 //add or show linw details
 addOrShow_lineDetails('tr.inv_transaction_line0');

 onClick_addDetailLine(1);


 $('#content').on('blur', '.item_number', function() {
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
   case '2' :
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

   case '1' :
   case '3' :
    $.when(getSerialNumber({
     'org_id': $('#org_id').val(),
     'status': 'IN_STORE',
     'item_id_m': itemIdM,
     'trclass': trClass,
     'current_subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
     'current_locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
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


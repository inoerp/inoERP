function setValFromSelectPage(inv_transaction_header_id, combination, item_id_m, item_number, item_description, uom_id,
        serial_generation, lot_generation, bom_config_header_id) {
 this.inv_transaction_header_id = inv_transaction_header_id;
 this.combination = combination;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.serial_generation = serial_generation;
 this.lot_generation = lot_generation;
 this.bom_config_header_id = bom_config_header_id;
}

setValFromSelectPage.prototype.setVal = function () {
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
 if (this.bom_config_header_id) {
  var rowClass_b = '.' + localStorage.getItem("row_class_b");
  rowClass_b = rowClass_b.replace(/\s+/g, '.');
  $('#content').find(rowClass_b).find('.bom_config_header_id').val(this.bom_config_header_id);
 }
 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");

};

function beforeSave() {
 return lotSerial_quantityValidation({
  quantity_divClass: '.quantity'
 });
}

function setSubinventory(transaction_type_id) {
 $(".transaction_type_id").val(transaction_type_id);
 switch (transaction_type_id) {
  case "1":
   $(".from_subinventory_id, .from_locator_id").removeAttr("disabled");
   $(".from_subinventory_id,.account_id").prop("required", true).css('backgroundColor', mandatory_field_color);
   $(".to_subinventory_id, .to_locator_id").val('').prop("disabled", true).removeAttr("required").css('backgroundColor', '');
   break;

  case "2":
   $(".to_subinventory_id, .to_locator_id").removeAttr("disabled");
   $(".to_subinventory_id,.account_id").prop("required", true).css('backgroundColor', mandatory_field_color);
   $(".from_subinventory_id, .from_locator_id").val('').prop("disabled", true).removeAttr("required").css('backgroundColor', '');
   break;

  case "3":
   $(".to_subinventory_id, .to_locator_id, .from_subinventory_id, .from_locator_id").removeAttr("disabled");
   $(".to_subinventory_id, .from_subinventory_id").prop("required", true).css('backgroundColor', mandatory_field_color);;
   $(".account_id").removeAttr("required disabled").css('backgroundColor', '#fff');
   break;

  default:
   $(".to_subinventory_id, .to_locator_id, .from_subinventory_id, .from_locator_id ,.account_id").removeAttr("required").prop("disabled", true).css('backgroundColor', '');
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

$(document).ready(function () {
 $("body").off("change", '#transaction_type_id').on("change", '#transaction_type_id', function () {
  var transaction_type_id = $(this).val();
  setSubinventory(transaction_type_id);
 });

 if ($("#transaction_type_id").val()) {
  setSubinventory($("#transaction_type_id").val());
 }

 $('#form_line').off('click', '.popup.view-item-config').on('click', '.popup.view-item-config', function (e) {
  e.preventDefault();
  localStorage.removeItem("row_class_b");
  var openUrl = $(this).prop('href') + '&reference_key_name=sd_so_line';
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  if ($('#form_line').find(trClass).find('.org_id').val()) {
   openUrl += '&org_id=' + $('#form_line').find(trClass).find('.org_id').val();
  }
  if ($('#form_line').find(trClass).find('.item_id_m').val()) {
   openUrl += '&item_id_m=' + $('#form_line').find(trClass).find('.item_id_m').val();
  }
  if ($('#form_line').find(trClass).find('.quantity').val()) {
   openUrl += '&quantity=' + $('#form_line').find(trClass).find('.quantity').val();
  }
  var rowClass = $(this).closest('tr').prop('class');
  localStorage.setItem("row_class_b", rowClass);
  void window.open(openUrl, '_blank',
          'width=1200,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

// //get Subinventory Name
 $('body').off('blur', '#org_id').on("blur", "#org_id", function () {
  $('.org_id').val($(this).val());
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $("#org_id").val()
  });
  $('.org_id').val($(this).val());
 });



 $('body').off('blur', '.from_subinventory_id').on("change", ".from_subinventory_id", function () {
  var rowIdValue = $(this).closest("tr").attr("id");
  var idValue = "tr#" + rowIdValue;
  var subinventory_id = $(this).val();
  callGetLocatorForFrom(subinventory_id, idValue);
 });

 $('body').off('blur', '.to_subinventory_id').on("change", ".to_subinventory_id", function () {
  var rowIdValue = $(this).closest("tr").attr("id");
  var idValue = "tr#" + rowIdValue;
  var subinventory_id = $(this).val();
  callGetLocatorForTo(subinventory_id, idValue);
 });


 onClick_addDetailLine(1, '.add_row_detail_img1');

 $('body').off('blur', '.item_number, .from_subinventory_id, .from_locator_id ')
         .on('blur', '.item_number, .from_subinventory_id, .from_locator_id', function () {
          var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
          var trClass_d = '.' + trClass;
          var generation_type = $('#content').find(trClass_d).find('.serial_generation').val();

          if (!generation_type) {
           var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
           $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
           $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
//   alert('Item is not serial controlled.\nNo serial informatio \'ll be saved in database');
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
             })).then(function (data, textStatus, jqXHR) {
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

         });

 $('body').off('blur', '.item_number, .from_subinventory_id, .from_locator_id ')
         .on('blur', '.item_number, .from_subinventory_id, .from_locator_id', function () {
          var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
          var trClass_d = '.' + trClass;
          var generation_type = $('#content').find(trClass_d).find('.lot_generation').val();

          if (!generation_type) {
           var field_stmt = '<input class="textfield lot_number" type="text" size="25" readonly name="lot_number[]" >';
           $('#content').find(trClass_d).find('.inv_lot_number_id').replaceWith(field_stmt);
           $('#content').find(trClass_d).find('.lot_number').replaceWith(field_stmt);
//   alert('Item is not lot controlled.\nNo lot informatio \'ll be saved in database');
           return;
          } else if (generation_type != 'PRE_DEFINED') {
           var field_stmt = '<input class="textfield lot_number" type="text" size="25" name="lot_number[]" >';
           $('#content').find(trClass_d).find('.inv_lot_number_id').replaceWith(field_stmt);
           $('#content').find(trClass_d).find('.lot_number').replaceWith(field_stmt);
          }
          var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
          if (!itemIdM) {
           return;
          }


          switch ($('#transaction_type_id').val()) {
           case '2' :
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

           case '1' :
           case '3' :
            var subinventory_id = $('#content').find(trClass_d).find('.from_subinventory_id').val();
            if (!subinventory_id) {
             alert('No from subinventory');
             return;
            }
            $.when(getlotNumber({
             'org_id': $('#org_id').val(),
             'status': 'ACTIVE',
             'item_id_m': itemIdM,
             'trclass': trClass,
             'subinventory_id': subinventory_id,
             'locator_id': $('#content').find(trClass_d).find('.from_locator_id').val(),
            })).then(function (data, textStatus, jqXHR) {
             if ($.trim(data) == 'false' || $.trim(data) == 'undefined') {
              alert('No lot Number Found!\nCheck the subinventory, locator and item number');
             }
            });
            break;

           case 'undefined' :
           case '' :
            alert('Enter the transaction type');
            break;
          }
          $('#content').find(trClass_d).find('.lot_number, .inv_lot_number_id').attr('required', true).css('background-color', 'pink');

         });

 $('body').off('blur', '.item_id_m, .item_number').on('blur', '.item_id_m, .item_number', function () {
  var item_id_m = $(this).closest('tr').find('.item_id_m').val();
  var org_id = $('#org_id').val();
  if (org_id && item_id_m) {
   getItemRevision({
    'org_id': org_id,
    'item_id_m': item_id_m,
    'trclass': $(this).closest('tr').attr('class')
   });
  }
 });

});


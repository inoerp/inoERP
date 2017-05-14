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
   $(".to_subinventory_id, .from_subinventory_id").prop("required", true).css('backgroundColor', mandatory_field_color);
   ;
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
  $('.org_id').val($('#org_id').val());
 });

 $('body').off('blur', '.to_subinventory_id').on("change", ".to_subinventory_id", function () {
  var rowIdValue = $(this).closest("tr").attr("id");
  var idValue = "tr#" + rowIdValue;
  var subinventory_id = $(this).val();
  callGetLocatorForTo(subinventory_id, idValue);
 });

 $('body').off('blur', '.item_number').on("change", ".item_number", function () {
  $('.org_id').val($('#org_id').val());
 });

 //get onhand
 $('body').off('change', '.subinventory_id, .locator_id')
         .on('change', '.subinventory_id, .locator_id', function () {
          rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
          if (!$(rowClass_d).find('.subinventory_id').val()) {
           return false;
          }
          getOnhandDetails({
           item_id_m: $(rowClass_d).find('.item_id_m').val(),
           org_id: $(rowClass_d).find('.org_id').val(),
           subinventory_id: $(rowClass_d).find('.subinventory_id').val(),
           locator_id: $(rowClass_d).find('.locator_id').val(),
           trClass: rowClass_d
          });
         });


 onClick_addDetailLine(1, '.add_row_detail_img1');

 $('body').off('blur', '.from_subinventory_id, .from_locator_id ')
         .on('blur', '.from_subinventory_id, .from_locator_id', function () {
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
             'subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
             'locator_id': $('#content').find(trClass_d).find('.from_locator_id').val()
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

 $('body').off('blur', '.from_subinventory_id, .from_locator_id ')
         .on('blur', '.from_subinventory_id, .from_locator_id', function () {
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
               $(".error").prepend('No Lot Number Found!\nCheck the subinventory, locator and item number');
               $("#accordion").accordion({active: 0});
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
               $(".error").prepend('No Lot Number Found!\nCheck the subinventory, locator and item number');
               $("#accordion").accordion({active: 0});
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


function setValFromSelectPage(wip_wo_header_id, item_id_m, item_number, item_description,
        uom_id, processing_lt) {
 this.wip_wo_header_id = wip_wo_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.processing_lt = processing_lt;
}

setValFromSelectPage.prototype.setVal = function () {
 if (this.wip_wo_header_id) {
  $("#wip_wo_header_id").val(this.wip_wo_header_id);
 }
 var rowClass = '.' + localStorage.getItem("row_class");
 var itemType = localStorage.getItem("itemType");
 rowClass = rowClass.replace(/\s+/g, '.');


 var item_obj = [{id: 'item_id_m', data: this.item_id_m},
  {id: 'item_number', data: this.item_number},
  {id: 'item_description', data: this.item_description},
  {id: 'uom', data: this.uom_id},
  {id: 'processing_lt', data: this.processing_lt}
 ];

 var component_obj = [{id: 'component_item_id_m', data: this.item_id_m},
  {id: 'component_item_number', data: this.item_number},
  {id: 'component_description', data: this.item_description},
  {id: 'component_uom', data: this.uom_id}
 ];

 if (localStorage.getItem("li_divId")) {
  var li_divId = '#' + localStorage.getItem("li_divId");
  $(item_obj).each(function (i, value) {
   if (value.data) {
    var fieldId = '#' + value.id;
    $('#content').find(fieldId).val(value.data);
   }
  });
 } else {
  $(component_obj).each(function (i, value) {
   if (value.data) {
    var fieldClass = '.' + value.id;
    $('#content').find(rowClass).find(fieldClass).val(value.data);
   }
  });
 }
 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");
 localStorage.removeItem("li_divId");
 localStorage.removeItem("itemType");
 
 if(this.wip_wo_header_id){
  $('a.show.wip_wo_header_id').trigger('click');
 }
};

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'wip_wo_header_id';
 mandatoryCheck.mandatoryHeader();
// mandatoryCheck.form_area = 'form_header';
// mandatoryCheck.mandatory_fields = ["org_id", 'wo_type', "wip_accounting_group_id"];
// mandatoryCheck.mandatory_messages = ["First Select Org", 'No Work Order Type', "No WIP Accounting Group"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('10');
 }

 if (!($('.detail_number:first').val())) {
  $('.detail_number:first').val('10');
 }

 $('body').off('blur', '#quantity').on('blur', '#quantity', function () {
  if ($(this).val()) {
   $('#nettable_quantity').val($(this).val());
  }
 })

 //selecting Header Id
 $('body').off("click", '.wip_wo_header_id.select_popup').on("click", '.wip_wo_header_id.select_popup' , function () {
  void window.open('select.php?class_name=wip_wo_header', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


//start date & completion date calculation
 $('#content').off('blur', '#start_date').on('blur', '#start_date', function () {
  var startDate = $('#start_date').val();
  var str = startDate.split(/-/);
  if ($('#processing_lt').val()) {
   var processing_lt = +$('#processing_lt').val();
  } else {
   var processing_lt = 0;
  }
  var newDate = (parseInt(str[2]) + (processing_lt));
  var cd = new Date(str[0], str[1], newDate);
  var foramtedDate = cd.getFullYear() + '-' + cd.getMonth() + '-' + cd.getDate();
//  alert(processing_lt + '' + foramtedDate);
  $('#completion_date').val(foramtedDate);
 });

 $('#content').off('blur', '#completion_date').on('blur', '#completion_date', function () {
  var completionDate = $('#completion_date').val();
  var str = completionDate.split(/-/);
  if ($('#processing_lt').val()) {
   var processing_lt = +$('#processing_lt').val();
  } else {
   var processing_lt = 0;
  }
  var newDate = (parseInt(str[2]) + (processing_lt));
  var cd = new Date(str[0], str[1], newDate);
  var foramtedDate = cd.getFullYear() + '-' + cd.getMonth() + '-' + cd.getDate();
  $('#start_date').val(foramtedDate);
 });

//Required Resource Quantity
 $('body').off('focusout', '.usage').on('focusout', '.usage', function () {
  var usageValue = $(this).val();
  var quantity = $("#quantity").val();
  var trClass = '.' + $(this).closest('tr').attr('class');
  var newtrClass = trClass.split(' ').join('.');
  var RequiredQuanity = usageValue * quantity;
  $(this).closest('.tabContainer').find(newtrClass).find('.required_quantity').val(RequiredQuanity);
 });

//Required BOM Quantity
 $('body').off('focusout', '.usage_quantity').on('focusout', '.usage_quantity', function () {
  var usageValue = $(this).val();
  var quantity = $("#quantity").val();
  var trClass = '.' + $(this).closest('tr').attr('class');
  var newtrClass = trClass.split(' ').join('.');
  var RequiredQuanity = usageValue * quantity;
  $(this).closest('.tabContainer').find(newtrClass).find('.required_quantity').val(RequiredQuanity);
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

 //get locatot on Subinventory change in form line
 $('#form_line2').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var subInventoryId = $(this).val();
  if (subInventoryId > 0) {
   var trClass = '.' + $(this).closest('tr').attr('class');
   getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'subinventory', trClass);
  }
 });

//add or show linw details
// addOrShow_lineDetails('tr.wip_wo_routing0');

 //add new lines
 //add new lines
 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = 'wip_wo_bom';
  addNewRow.tbodyClass = 'form_data_line_tbody2';
  addNewRow.noOfTabs = 2;
  addNewRow.removeDefault = true;
  addNewRow.add_new_row();
 });

 $('#content').off('blur', '#org_id, #item_number').on('blur', '#org_id, #item_number', function () {
  getItemRevision({
   'org_id': $('#org_id').val(),
   'item_id_m': $('#item_id_m').val(),
   'show_date': false
  });
 });
 
 $('body').on('click','#menu_button4', function(){
  $('#bom_exploded_cb, #routing_exploded_cb').attr('checked', false);
 });
 
});



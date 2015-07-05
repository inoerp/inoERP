function setValFromSelectPage(bom_config_header_id, item_id_m, item_number, item_description, uom_id, org_id) {
 this.bom_config_header_id = bom_config_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.org_id = org_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var bom_config_header_id = this.bom_config_header_id;
 if (bom_config_header_id) {
  $("#bom_config_header_id").val(bom_config_header_id);
 }
 var row_class = localStorage.getItem("row_class");
 ;
 var rowClass = '.' + row_class;
 rowClass = rowClass.replace(/\s+/g, '.');

 if (this.org_id) {
  $('#org_id').val(this.org_id);
 }

 if (!(row_class) || row_class == 'null') {
  if (this.item_number) {
   $('#item_number').val(this.item_number);
  }
  if (this.item_id_m) {
   $('#item_id_m').val(this.item_id_m);
  }
  if (this.item_description) {
   $('#item_description').val(this.item_description);
  }
 }

 var item_obj = [{id: 'component_item_id_m', data: this.item_id_m},
  {id: 'component_item_number', data: this.item_number},
  {id: 'component_description', data: this.item_description},
  {id: 'uom', data: this.uom_id}
 ];

 $(item_obj).each(function (i, value) {
  if (value.data) {
   var fieldClass = '.' + value.id;
   $('#content').find(rowClass).find(fieldClass).val(value.data);
  }
 });

 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");
  if (this.bom_config_header_id) {
  $('a.show.bom_config_header_id').trigger('click');
 }
};

function disableField_forCommonBom() {
 $('#form_line').find(':input').not('input[name="line_id_cb"]')
         .not('.bom_config_line_id, .bom_config_header_id, .routing_sequence,.item_id_m , .wip_supply_type, .supply_sub_inventory, .yield, .planning_percentage, .supply_locator')
         .attr('disabled', true).css("background-color", "#ccc");
}

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'bom_config_header_id';
// mandatoryCheck.mandatoryHeader();
// mandatoryCheck.form_area = 'form_header';
// mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
// mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

 //setting the first line number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('10');
 }

 $(".bom_config_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=bom_config_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 $('body').off('click', 'a.bom_config_header_withRev_id').on('click', 'a.bom_config_header_withRev_id', function (e) {
  e.preventDefault();
  var item_id_m = $('#item_id_m').val();
  var org_id = $('#org_id').val();
  var revision_name = $('#revision_name').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&item_id_m=' + item_id_m + '&org_id=' + org_id + '&revision_name=' + revision_name;
  getFormDetails(formUrl);
 }).one();



 //get subinventories on selecting org
 $('#content').off('blur', '#org_id').on('blur', '#org_id', function () {
  var org_id = $(this).val();
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: org_id
  });
 });


 //get locators on changing sub inventory
 $('#content').off('blur', '.subinventory_id').on('blur', '.subinventory_id', function () {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', trClass);
 });

 //popu for selecting items
 $('#content').off('click', '.select_item_number1.select_popup')
         .on('click', '.select_item_number1.select_popup', function () {
          var openUrl = 'select.php?class_name=item';
          if ($(this).siblings('.item_number').val()) {
           openUrl += '&item_number=' + $(this).siblings('.item_number').val();
          }
          void window.open(openUrl, '_blank',
                  'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
         });

 $('#content').off('blur', '#org_id, #item_number').on('blur', '#org_id, #item_number', function () {
  getItemRevision({
   'org_id': $('#org_id').val(),
   'item_id_m': $('#item_id_m').val(),
   'show_date': false
  });
 });

      
});

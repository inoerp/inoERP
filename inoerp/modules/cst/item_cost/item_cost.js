function setValFromSelectPage(cst_item_cost_header_id, item_id_m, item_number, item_description,
        uom_id) {
 this.cst_item_cost_header_id = cst_item_cost_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var cst_item_cost_header_id = this.cst_item_cost_header_id;
 var item_obj = [{id: 'item_id_m', data: this.item_id_m},
  {id: 'item_number', data: this.item_number},
  {id: 'item_description', data: this.item_description},
  {id: 'uom_id', data: this.uom_id}
 ];
 if (cst_item_cost_header_id) {
  $("#cst_item_cost_header_id").val(cst_item_cost_header_id);
 }
 $(item_obj).each(function (i, value) {
  if (value.data) {
   var fieldId = '#' + value.id;
   $('#content').find(fieldId).val(value.data);
  }
 });
   if (this.cst_item_cost_header_id) {
  $('a.show.cst_item_cost_header_id').trigger('click');
 }
};

function getCostElement(json_url, cost_element_type, row_class) {
 switch (cost_element_type) {
  case 'MAT' :
   var className = 'bom_material_element';
   break;

  case 'MOH' :
  case 'OH' :
   var className = 'bom_overhead';
   break;

  case 'RES' :
   var className = 'bom_resource';
   break;

  case 'default':
   var className = false;
   break;
 }

 if (className === false) {
  return;
 }

 $.ajax({
  url: json_url,
  type: 'get',
  data: {
   class_name: className,
   element_type: cost_element_type,
   find_cost_elements: '1'
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var div = $(result).filter('div#cost_elements_find_all').html();
  var asisClass = '.' + row_class;
  var asisClass_d = asisClass.replace(/\s+/g, '.');
  $("#content").find(asisClass_d).find('.cost_element_id').empty().append(div);
 }).fail(function () {
  alert(" Cost Element Not Found!");
 });
}

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'item_cost_header_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "ledger_id"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Ledger Id"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }


 //selecting Header Id
 $(".cst_item_cost_header_id.select_popup").on("click", function () {
  var link = 'select.php?class_name=cst_item_cost_header';
  void window.open(link, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 $('body').off('change', '#bom_cost_type').on('change', '#bom_cost_type', function () {
  if ($(this).val() === 'FROZEN') {
   alert('You cant directly entered FROZEN cost.\nEnter pending cost and then run standard cost update');
  }
 });


 deleteData('form.php?class_name=cst_item_cost_header&line_class_name=cst_item_cost_line');



 $('#content').off('change', '.cost_element_type').on('change', '.cost_element_type', function () {
  var json_url = 'modules/cst/item_cost/json_item_cost.php';
  var cost_element_type = $(this).val();
  var row_class = $(this).closest('tr').prop('class');
  getCostElement(json_url, cost_element_type, row_class);
 });
});

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
   $(this).val('');
   alert('You cant directly entered FROZEN cost.\nEnter pending cost and then run standard cost update');
  }
 });


  $('#content').off('change', '.cost_element_type').on('change', '.cost_element_type', function () {
  var json_url = 'modules/cst/item_cost/json_item_cost.php';
  var cost_element_type = $(this).val();
  var row_class = $(this).closest('tr').prop('class');
  getCostElement(json_url, cost_element_type, row_class);
 });
 
  $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('#item_number, #item_id_m, #item_description').val('');
 });
});
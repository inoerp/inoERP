$(document).ready(function () {
// $('#generic_search_form').find('.line_status').val('AWAITING_PICKING');

 $('#content').off('click', '.line_status').on('click', '.line_status', function () {
  alert('You can only search lines which are not picked');
  $(this).attr('readonly', true);
 });

 $('body').off('click', '.line_id_cb').on('click', '.line_id_cb', function () {
  var this_e = $(this);
  var Onhand = +$(this).closest('tr').find('.onhand').val();
  var lineQuantity = +$(this).closest('tr').find('.line_quantity').val();
  var pickedQuantity = +$(this).closest('tr').find('.picked_quantity').val();
  var kitItem = false;
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\+s/g, '.');
  if ($('#form_line').find(trClass).find('.kit_cb').val()) {
   var kitItem = true;
  }

  if ((Onhand < lineQuantity) && (!kitItem)) {
   alert('Available Onhand is less than line quantity');
  }

  if (pickedQuantity >= lineQuantity) {
   $('#form_line').find(trClass).find('.line_id_cb').prop('disabled', true);
   alert('All line quantities are in picked status!');
  }

 });

 $('.line_id_cb').each(function () {
  var Onhand = +$(this).closest('tr').find('.onhand').val();
  var lineQuantity = +$(this).closest('tr').find('.line_quantity').val();
  var pickedQuantity = +$(this).closest('tr').find('.picked_quantity').val();
  var kitItem = false;
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\+s/g, '.');
  if ($('#form_line').find(trClass).find('.kit_cb').val()) {
   var kitItem = true;
  }

  if (lineQuantity > Onhand + pickedQuantity && !kitItem) {
   $(this).closest('tr').find('input').each(function () {
    $(this).css('background', 'rgba(255,40,0,0.5)');
   });
   if(Onhand == 0){
   $(this).closest('tr').find('.line_id_cb').prop('disabled', true); 
   }
  } else {
   $(this).closest('tr').find('input').each(function () {
    $(this).css('background', 'rgba(204,255,153,0.8)');
   });
  }

  if (pickedQuantity >= lineQuantity) {
   $('#form_line').find(trClass).find('.line_id_cb').prop('disabled', true);
  }

 });

//quantity validation
$('body').off('blur','.pick_quantity').on('blur','.pick_quantity', function(){
  if(+$(this).val() > +$(this).closest('tr').find('.onhand').val()){
  alert('Picked quantity is more than available quantity');
  }
  
  if(+$(this).val() > +$(this).closest('tr').find('.line_quantity').val()){
  alert('Picked quantity is more than line quantity');
  }
  
});


 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.trClass = 'multi_select_value_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 5;
 classContextMenu.contextMenu();



// $('body').off('click', '.pick_list.button').on('click', '.pick_list.button', function () {
//  var lineIds = $('#form_line').find('input.line_id_cb[type="checkbox"]:checked').serializeArray();
//  save_dataInSession({
//   data_name: 'pick_list',
//   data_value: lineIds
//
//  });

 $('body').off('click', '.pick_list.button').on('click', '.pick_list.button', function () {
  var allData = [];
  $('#form_line').find('input.line_id_cb[type="checkbox"]:checked').each(function () {
   var trClass = '.' + $(this).closest('tr').prop('class').replace(/\+s/g, '.');
   var lineData = [];
   $("#form_line").find(trClass).each(function () {
    var ThisLineData = $(this).find(":input").serializeArray();
    lineData = $.merge(lineData, ThisLineData);
   });
   allData = $.merge(allData, lineData);
  });
  save_dataInSession({
   data_name: 'pick_list',
   data_value: allData,
   openUrl: 'form.php?class_name=sd_pick_list_v&mode=2&window_type=popup'

  });


 });

});

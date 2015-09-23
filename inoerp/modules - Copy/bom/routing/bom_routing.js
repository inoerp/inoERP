function setValFromSelectPage(item_id_m, item_number, item_description, uom_id, bom_routing_header_id) {
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.bom_routing_header_id = bom_routing_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bom_routing_header_id = this.bom_routing_header_id;

 var item_obj = [{id: 'item_id_m', data: this.item_id_m},
  {id: 'item_number', data: this.item_number},
  {id: 'item_description', data: this.item_description},
  {id: 'uom_id', data: this.uom_id}
 ];

 $(item_obj).each(function(i, value) {
  if (value.data) {
   var fieldId = '#' + value.id;
   $('#content').find(fieldId).val(value.data);
  }
 });

 if (bom_routing_header_id) {
  $('#bom_routing_header_id').val(bom_routing_header_id);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");
      if (this.bom_routing_header_id) {
  $('a.show.bom_routing_header_id').trigger('click');
 }
};

function disableField_forCommonRouting() {
 $('#form_line').find(':input').attr('required', false).attr('disabled', true).css("background-color", "#ccc");
}

$(document).ready(function() {
//mandatory and field sequence
// var mandatoryCheck = new mandatoryFieldMain();
// mandatoryCheck.mandatoryHeader();
// mandatoryCheck.form_area = 'form_header';
// mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
// mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('10');
 }

 if (!($('.detail_number:first').val())) {
  $('.detail_number:first').val('10');
 }


 if ($('#commonRouting_item_number').val()) {
  disableField_forCommonRouting();
 }

 $('body').off('blur', '#commonRouting_item_number')
         .on('blur', '#commonRouting_item_number' ,function() {
  if ($(this).val()) {
   disableField_forCommonRouting();
  }
 });

 //selecting Header Id
 $('body').off("click", '.bom_routing_header_id.select_popup') 
         .on("click", '.bom_routing_header_id.select_popup' , function() {
  void window.open('select.php?class_name=bom_routing_v', '_blank',
   'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('body').off("click", '.item_id_m.select_popup')
         .on("click", '.item_id_m.select_popup', function() {
  void window.open('select.php?class_name=item', '_blank',
   'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //function to coply line to details
  $("#content").off("click", "table.form_line_data_table .add_detail_values_img")
          .on("click", "table.form_line_data_table .add_detail_values_img", function() {
   var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
   if (detailExists === 0) {
    var lineQuantity = $(this).closest('tr').find('.inv_line_quantity').val();
    $(this).closest("td").find(".quantity:first").val(lineQuantity);
   }
  });
 
//
// $("#content").on("click", ".add_row_img", function() {
//  var addNewRow = new add_new_rowMain();
//  addNewRow.trClass = 'bom_routing_line';
//  addNewRow.tbodyClass = 'form_data_line_tbody';
//  addNewRow.noOfTabs = 4;
//  addNewRow.lineNumberIncrementValue = 10;
//  addNewRow.removeDefault = true;
//  addNewRow.add_new_row();
//  $(".tabsDetail").tabs();
// });
//
//

 
  onClick_addDetailLine(2, '.add_row_detail_img1','tabsDetailC')

 $('#content').off('change', '.extra_field_name').on('change', '.extra_field_name', function() {
  var count = 0;
  $(this).closest('td').find('.extra_field_name').each(function() {
   if (!$(this).val()) {
    count++;
   }
  });
  if ($(this).val()) {
   if (count <= 0) {
    $(this).clone().appendTo($(this).closest('td'));
   } else if (count > 1) {
    $(this).remove();
   }
  } else if (count > 1) {
   $(this).remove();
  }

 });

});
function setValFromSelectPage(bom_header_id, item_id_m, item_number, item_description, uom_id) {
 this.bom_header_id = bom_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var bom_header_id = this.bom_header_id;
 $("#bom_header_id").val(bom_header_id);
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');

 var item_obj = [{id: 'item_id_m', data: this.item_id_m},
  {id: 'item_number', data: this.item_number},
  {id: 'item_description', data: this.item_description},
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
};
$(document).ready(function () {
 //Popup for selecting bom
 $(".bom_header_id.select_popup").click(function () {
  void window.open('select.php?class_name=bom_all_v', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

 //Get the bom_id on find button click
// $('#form_header a.show.bom_header_id').click(function () {
//  var headerId = $('#bom_header_id').val();
//  $(this).attr('href', modepath() + 'bom_header_id=' + headerId);
// });
});
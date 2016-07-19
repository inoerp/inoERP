function setValFromSelectPage(inv_count_header_id, item_id_m, item_number, item_description, uom_id,
 count_name, org_id) {
 this.inv_count_header_id = inv_count_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.count_name = count_name;
 this.org_id = org_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var inv_count_header_id = this.inv_count_header_id;
 var count_name = this.count_name;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;

 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");


var org_id = this.org_id;

 if (count_name) {
  $("#count_name").val(count_name);
 }
 if (org_id) {
  $("#org_id").val(org_id);
 }

 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
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

 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");
 
  if (inv_count_header_id) {
  $("#inv_count_header_id").val(inv_count_header_id);
  $('a.show2.inv_count_entries_id').trigger('click');
 }
 

};
 function default_counted_by(counted_by) {
  $('#form_line').find('.counted_by').each(function() {
   if ($(this).val().length < 1) {
    $(this).val(counted_by);
   }
  });
 }

$(document).ready(function() {
 //Popup for selecting 
 $(".inv_count_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=inv_count_header', '_blank',
   'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".inv_abc_assignment_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=inv_abc_assignment_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });



 $('body').off('change', '.subinventory_id').on('change', '.subinventory_id', function() {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_id = $(this).val();
  getLocator('modules/inv/locator/json_locator.php', subinventory_id, 'subinventory', trClass);

 });

 //defalut values to line
 $('body').off('blur', '#adjustment_ac_id').on('blur', '#adjustment_ac_id' , function() {
  var acvalue = $(this).val();
  $('#form_line').find('.adjustment_ac_id').each(function() {
   if ($(this).val().length < 5) {
    $(this).val(acvalue);
   }

  });
 });
 
 var counted_by = $('#counted_by').val();
 default_counted_by(counted_by);
 
 $('body').off('blur', '#counted_by').on('blur', '#counted_by', function() {
  var counted_by = $(this).val();
  default_counted_by(counted_by);
 });
 
  $('body').off('click', 'a.inv_count_entries_id').on('click', 'a.inv_count_entries_id', function (e) {
  e.preventDefault();
  var inv_count_header_id = $('#inv_count_header_id').val();
  var count_date = $('.count_date').first().val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&inv_count_header_id=' + inv_count_header_id + '&count_date=' + count_date;
  getFormDetails(formUrl);
 }).one();


});
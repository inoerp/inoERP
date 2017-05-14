function setValFromSelectPage(am_maintenance_schedule_id, item_id_m, item_number, schedule_name, schedule_number,
  org_id) {
 this.am_maintenance_schedule_id = am_maintenance_schedule_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.schedule_name = schedule_name;
 this.schedule_number = schedule_number;
 this.org_id = org_id;
}

setValFromSelectPage.prototype.setVal = function() {
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
 
  if (this.am_maintenance_schedule_id) {
  $("#am_maintenance_schedule_id").val(this.am_maintenance_schedule_id);
  $('a.show.am_maintenance_schedule_id').trigger('click');
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
 $(".am_maintenance_schedule_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=am_maintenance_schedule', '_blank',
   'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".inv_abc_assignment_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=inv_abc_assignment_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //defalut values to line
$('body').off('blur', '.base_interval_days').on('blur', '.base_interval_days', function(){
  if($(this).val()){
  var cycle_interval_days = (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"))*(+$('#intervals_per_cycle').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  $(this).closest('tr').find('.cycle_interval_days').val(cycle_interval_days);
  }
});
 
  $('body').off('click', 'a.am_ms_calendar_date_id').on('click', 'a.am_ms_calendar_date_id', function (e) {
  e.preventDefault();
  var am_maintenance_schedule_id = $('#am_maintenance_schedule_id').val();
  var count_date = $('.count_date').first().val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&am_maintenance_schedule_id=' + am_maintenance_schedule_id + '&count_date=' + count_date;
  getFormDetails(formUrl);
 }).one();


});


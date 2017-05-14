$(document).ready(function () {

 //selecting Id
 $("body").off("click", '.address.select_popup').on("click", '.address.select_popup', function () {
  var close_field_class = '.' + $(this).parent().find(':input').not('hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  localStorage.setItem("auto_refresh_class", 'a.show2.address_id');
  void window.open('select.php?class_name=address', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Tax Region Id
 $("body").off("click", '.tax_region_id.select_popup').on("click", '.tax_region_id.select_popup' , function () {
  var close_field_class = '.' + $(this).parent().find(':input').not('hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  void window.open('select.php?class_name=mdm_tax_region', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('body').off('click', 'a.show2.address_id').on('click', 'a.show2.address_id', function (e) {
  e.preventDefault();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var address_id = $('#address_id').val();
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&address_id=' + address_id;
  if ($('#window_type').val()) {
   formUrl += '&window_type=' + $('#window_type').val();
  }
  getFormDetails(formUrl);
 }).one();

});


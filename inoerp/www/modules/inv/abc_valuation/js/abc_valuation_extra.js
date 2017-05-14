function setPopUpValue(options) {
 var defaults = {
  inv_abc_valuation_id: '',
  valuation_name: ''
 };
 var settings = $.extend({}, defaults, options);
 if (settings.valuation_name) {
  $("#valuation_name").val(settings.valuation_name);
 }
 if (settings.scope_org_id) {
  $("#org_id").val(settings.scope_org_id);
 }
  if (settings.inv_abc_valuation_id) {
  $("#inv_abc_valuation_id").val(settings.inv_abc_valuation_id);
 }
}

$(document).ready(function () {
 //selecting Id
 $(".valuation_name.select_popup, #valuation_name").on("click", function () {
  void window.open('select.php?class_name=inv_abc_valuation', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
});

function setValFromSelectPage(am_meter_id, combination) {
 this.am_meter_id = am_meter_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function () {
 var am_meter_id = this.am_meter_id;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (am_meter_id) {
  $("#am_meter_id").val(am_meter_id);
 }
 if (combination) {
  $('#content').find(fieldClass).val(combination);
  localStorage.removeItem("field_class");
 }
};


$(document).ready(function () {
 //selecting Id
 $(".am_meter_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=am_meter', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
});


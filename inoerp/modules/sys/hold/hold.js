function setValFromSelectPage(sys_hold_id) {
 this.sys_hold_id = sys_hold_id;
}


setValFromSelectPage.prototype.setVal = function () {
 if (this.sys_hold_id) {
  $("#sys_hold_id").val(this.sys_hold_id);
 }
};

$(document).ready(function () {
 //selecting Id
 $(".sys_hold_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=sys_hold', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

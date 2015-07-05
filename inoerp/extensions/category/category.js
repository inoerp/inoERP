function setValFromSelectPage(category_id, address_id) {
 this.category_id = category_id;
 this.address_id = address_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var category_id = this.category_id;
 var address_id = this.address_id;
 if (category_id) {
  $("#category_id").val(category_id);
 }
 if (address_id) {
  $("#address_id").val(address_id);
 }
};

$(document).ready(function () {
 $("table#category_list tr.second").hide();
 $("table#category_list tr.third").hide();
 $("table#category_list tr.four").hide();


 $("table#category_list tr.first").click(function () {
  $(this).nextUntil("tr.first").toggle();
 });

 //selecting Id
 $(".category_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=category', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('#primary_cb').on('change', function () {
  if ($(this).is(':checked')) {
   $('#parent_id').val('').prop('disabled', true);
  }
 });

 if ($('#primary_cb').is(':checked')) {
  $('#parent_id').val('').prop('disabled', true);
 }

 

});

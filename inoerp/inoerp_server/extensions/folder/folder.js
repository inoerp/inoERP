function setValFromSelectPage(folder_id, address_id) {
 this.folder_id = folder_id;
 this.address_id = address_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var folder_id = this.folder_id;
 var address_id = this.address_id;
 if (folder_id) {
  $("#folder_id").val(folder_id);
 }
 if (address_id) {
  $("#address_id").val(address_id);
 }
};

$(document).ready(function () {
 $("table#folder_list tr.second").hide();
 $("table#folder_list tr.third").hide();
 $("table#folder_list tr.four").hide();


 $("table#folder_list tr.first").click(function () {
  $(this).nextUntil("tr.first").toggle();
 });

 //selecting Id
 $(".folder_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=folder', '_blank',
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
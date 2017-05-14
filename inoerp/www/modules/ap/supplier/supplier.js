
$(document).ready(function () {
$('body').off('change','#supplier_site_id').on('change','#supplier_site_id', function(){
 $('a.document_id.supplier_site_id').trigger('click');
});
   //Popup for selecting address
 $('body').off('click','.address_popup').on('click','.address_popup',function (e) {
  e.preventDefault();
  var rowClass = $(this).closest('div').prop('class');
  localStorage.setItem("addressPopupDivClass", rowClass);
  void window.open('form.php?class_name=address&mode=9&window_type=popup', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });
 
 $("#supplier_site_name").on("change", function () {
  if ($(this).val() == 'newentry') {
   if (confirm("Do you want to create a new supplier site?")) {
    $(this).replaceWith('<input id="supplier_site_name" class="textfield supplier_site_name" type="text" size="25" maxlength="50" name="supplier_site_name[]">');
    $(".show.supplier_site_id").hide();
    $("#supplier_site_id").val("");
    $("#supplier_site_number").val("");
   }

  }
 });


});



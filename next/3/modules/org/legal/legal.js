$(document).ready(function () {

 $("body").on("click",'.legal.select_popup' ,function () {
   var close_field_class = '.' + $(this).parent().find(':input').not('hidden').prop('class').replace(/\s+/g, '.');
 localStorage.setItem("close_field_class", close_field_class);
 localStorage.setItem("auto_refresh_class", 'a.show.legal_id');
  void window.open('select.php?class_name=legal', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});
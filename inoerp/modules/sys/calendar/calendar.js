$(document).ready(function () {
 $('body').off('click', 'table.cal-week td').on('click', 'table.cal-week td', function () {

  var openUrl = 'form.php?class_name=hr_event_header&mode=9&window_type=popup';
  void window.open(openUrl, '_blank',
          'width=1200,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


});
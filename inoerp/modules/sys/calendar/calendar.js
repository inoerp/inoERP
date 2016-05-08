$(document).ready(function () {
 $('body').off('click', 'table.cal-week td, table.cal-month td, table.cal-day td').on('click', 'table.cal-week td, table.cal-month td, table.cal-day td', function () {

  var userid = $('#user_id').val();
  var date = $(this).attr('date');
  var openUrl = 'form.php?class_name=hr_event_header&mode=9&window_type=popup&user_id='+userid+'&date='+date;
  void window.open(openUrl, '_blank',
          'width=1200,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


});
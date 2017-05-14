$(document).ready(function () {
 //function calendar_update

 $('body').off('click', 'table.cal-week td, table.cal-month td, table.cal-day td').on('click', 'table.cal-week td, table.cal-month td, table.cal-day td', function () {

  var userid = $('#user_id').val();
  var event_id = $(this).find('div.event-msg').first().attr('event_id');
  var date = $(this).attr('date');
  var openUrl = 'form.php?class_name=hr_event_header&mode=9&window_type=popup&user_id=' + userid + '&date=' + date;
  if (event_id != 'undefined') {
   openUrl += '&hr_event_header_id=' + event_id;
  }
  void window.open(openUrl, '_blank',
          'width=1200,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

$('body').off('click' , '#sys_calendar .ui-tabs-anchor').on('click' , '#sys_calendar .ui-tabs-anchor', function(){
calendar_size_update();
});


});
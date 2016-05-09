$(document).ready(function () {
 $('body').off('click', 'table.cal-week td, table.cal-month td, table.cal-day td').on('click', 'table.cal-week td, table.cal-month td, table.cal-day td', function () {

  var userid = $('#user_id').val();
  var date = $(this).attr('date');
  var openUrl = 'form.php?class_name=hr_event_header&mode=9&window_type=popup&user_id=' + userid + '&date=' + date;
  void window.open(openUrl, '_blank',
          'width=1200,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


});



var data_arr = [];
$('tbody.cal-year-tbdy').find('td.col3').each(function () {
 var this_arr = [];
 this_arr['start_date'] = $(this).attr('start_date');
 this_arr['end_date'] = $(this).attr('end_date');
 this_arr['start_time'] = $(this).attr('start_time');
 this_arr['end_time'] = $(this).attr('end_time');
 this_arr['title'] = $(this).closest('tr').find('td.col2').text();
  data_arr.push(this_arr);

});


$('tbody.cal-week-tbdy').find('td').not('.col_0').empty();

for (var key in data_arr) {
 var this_arr = data_arr[key];
 var start_date = this_arr['start_date'];
 var start_time = this_arr['start_time'];
 var end_time = this_arr['end_time'];
 var title = this_arr['title'];

 var start_time_spla = start_time.split(':');
 var end_time_spla = end_time.split(':');
 var total_time = (end_time_spla[0] - start_time_spla[0]) * 60 + (end_time_spla[1] - start_time_spla[1]);
 var tilte_height = total_time / 30;

 var msg1 = '<div class="event-msg" height="' + tilte_height + '">'+title+'</div>';
 $('tbody.cal-week-tbdy').find("td[date='" + start_date + "'][time='" + start_time + "']").empty().append(msg1);

}

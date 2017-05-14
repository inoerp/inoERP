$(document).ready(function () {
 $('body').off('blur, change', '.date,.timesheet_period').on('blur, change', '.date,.timesheet_period', function () {
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType == 'LI') {
   var timesheet_period = $('.from_date').val() + ' - ' + $('.to_date').val();
   $('#timesheet_period').val(timesheet_period);

  } else if (elemenType == 'TD') {
   var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
   var timesheet_period = $(trClass).find('.from_date').val() + ' - ' + $(trClass).find('.to_date').val();
   $(trClass).find('.timesheet_period').val(timesheet_period);
  }
 });

});
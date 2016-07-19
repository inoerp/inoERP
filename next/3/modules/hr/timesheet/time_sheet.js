$(document).ready(function () {
//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 $('body').off('change', '#hr_timesheet_period_id').on('change', '#hr_timesheet_period_id', function () {
  var link = $('a.hr_timesheet_header_id').prop('href') + '&hr_timesheet_period_id=' + $(this).val();
  $('a.hr_timesheet_header_id').prop('href', link);
  $('a.hr_timesheet_header_id').trigger('click');
 });
 
  $("body").off('click', '#menu_button4_2, #menu_button4_2, #menu_button4')
         .on('click', '#menu_button4_2, #menu_button4_2, #menu_button4', function () {
          $('#status').val('ENTERED');
          $('#claim_number,.approved_date').val('');
          $('#header_top_container').append(get_formTopImage());
         });
});
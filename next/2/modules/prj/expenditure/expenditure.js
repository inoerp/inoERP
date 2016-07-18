$(document).ready(function () {
 $('body').off('blur', '.quantity,.rate').on('blur', '.quantity,.rate', function () {
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  if ($(trClass).find('.rate').val()) {
   var line_amount = $(trClass).find('.rate').val() * $(trClass).find('.quantity').val();
  } else {
   var line_amount = $(trClass).find('.quantity').val();
  }

  $(trClass).find('.line_amount').val(line_amount);
 });



 $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('.status2').val('ENTERED');
  $('.debit_ac_id, .credit_ac_id').val('');
  $('.gl_journal_interface_cb').attr('checked', false)
 });

});
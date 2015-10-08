$(document).ready(function () {
 $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('.status2').val('ENTERED');
  $('.debit_ac_id, .credit_ac_id').val('');
  $('.gl_journal_interface_cb').attr('checked', false)
 });

});
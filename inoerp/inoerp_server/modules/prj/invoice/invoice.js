$(document).ready(function () {
 $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('.status2').val('ENTERED');
  $('.debit_ac_id, .credit_ac_id').val('');
  $('.gl_journal_interface_cb').attr('checked', false)
 });

 $('body').off('change', '#bu_org_id').on('change', '#bu_org_id', function () {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && (!$('#prj_invoice_header_id').val()) && ($('#bu_org_id').attr('disabled') !== 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }
 
});
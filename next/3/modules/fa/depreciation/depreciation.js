$(document).ready(function () {

 $('body').off('click', '#post_depreciation').on('click', '#post_depreciation', function () {
  if (confirm("Do you want to post the depreciation") == true) {
   $('#action').val('POST_DEPRECIATION');
   $('#save').trigger('click');
  }
 });

 $('body').off('change', '#fa_asset_book_id').on('change', '#fa_asset_book_id', function () {
  var gl_ledger_id = $(this).find('option:selected').data('ledger_id');
  getOpenPeriodsFromLedgerId({
   gl_ledger_id: gl_ledger_id
  });
 });

});


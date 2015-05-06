function setValFromSelectPage(fa_depreciation_header_id, fa_asset_book_id, gl_period_id) {
 this.fa_depreciation_header_id = fa_depreciation_header_id;
 this.fa_asset_book_id = fa_asset_book_id;
 this.gl_period_id = gl_period_id;
}

setValFromSelectPage.prototype.setVal = function () {
 if (this.fa_depreciation_header_id) {
  $("#fa_depreciation_header_id").val(this.fa_depreciation_header_id);
 }

 if (this.fa_asset_book_id) {
  $("#fa_asset_book_id").val(this.fa_asset_book_id);
 }

 if (this.gl_period_id) {
  $("#gl_period_id").val(this.gl_period_id);
 }
};


$(document).ready(function () {

 //Popup for selecting option type
 $(".fa_depreciation_header_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=fa_depreciation_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

$('body').off('change', '#fa_asset_book_id').on('change', '#fa_asset_book_id', function () {
  var gl_ledger_id = $(this).find('option:selected').data('ledger_id');
  getOpenPeriodsFromLedgerId({
   gl_ledger_id: gl_ledger_id
  });
 });

});


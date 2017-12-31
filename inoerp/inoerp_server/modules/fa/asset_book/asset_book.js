function setValFromSelectPage(fa_asset_book_id, asset_book_name) {
 this.fa_asset_book_id = fa_asset_book_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var fa_asset_book_id = this.fa_asset_book_id;
  if (fa_asset_book_id) {
  $("#fa_asset_book_id").val(fa_asset_book_id);
  $("a.show.fa_asset_book_id").trigger('click');
 }
};

$(document).ready(function() {

 //selecting Id
 $(".fa_asset_book_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=fa_asset_book', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});
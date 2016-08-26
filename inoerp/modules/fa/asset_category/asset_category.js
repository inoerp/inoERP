function setValFromSelectPage(fa_asset_category_id) {
 this.fa_asset_category_id = fa_asset_category_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var fa_asset_category_id = this.fa_asset_category_id;

 if (fa_asset_category_id) {
  $("#fa_asset_category_id").val(fa_asset_category_id);
  $("a.show.fa_asset_category_id").trigger('click');
 }
 
};

$(document).ready(function () {
 //selecting Id
 $(".fa_asset_category_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=fa_asset_category', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('body').off('click', 'a.fa_book_category_assoc_id').on('click', 'a.fa_book_category_assoc_id', function (e) {
  e.preventDefault();
  var fa_asset_book_id = $('#fa_asset_book_id').val();
  var fa_asset_category_id = $('#fa_asset_category_id').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&fa_asset_book_id=' + fa_asset_book_id + '&fa_asset_category_id=' + fa_asset_category_id;
  getFormDetails(formUrl);
 }).one();


});


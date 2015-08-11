function setValFromSelectPage(fa_asset_retirement_id, asset_number, fa_asset_id, asset_book_name, fa_asset_book_id) {
 this.fa_asset_retirement_id = fa_asset_retirement_id;
 this.asset_book_name = asset_book_name;
 this.fa_asset_id = fa_asset_id;
 this.asset_number = asset_number;
 this.fa_asset_book_id = fa_asset_book_id;
}

setValFromSelectPage.prototype.setVal = function () {

 if (this.fa_asset_retirement_id) {
  $("#fa_asset_retirement_id").val(this.fa_asset_retirement_id);
 }

 if (this.fa_asset_id) {
  $("#fa_asset_id").val(this.fa_asset_id);
 }
 if (this.asset_book_name) {
  $("#asset_book_name").val(this.asset_book_name);
 }
 if (this.asset_number) {
  $("#asset_number").val(this.asset_number);
 }

 if (this.fa_asset_retirement_id) {
  $("a.show.fa_asset_retirement_id").trigger('click');
 }
};

$(document).ready(function () {

 $('body').off('click', 'a.fa_asset_retirement_with_asset_book').on('click', 'a.fa_asset_retirement_with_asset_book', function (e) {
  e.preventDefault();
  var fa_asset_book_id = $('#fa_asset_book_id').val();
  var fa_asset_id = $('#fa_asset_id').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&fa_asset_book_id=' + fa_asset_book_id + '&fa_asset_id=' + fa_asset_id;
  getFormDetails(formUrl);
 }).one();

 //selecting Id
 $(".fa_asset_retirement_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=fa_asset_retirement', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //selecting Id
 $(".fa_asset_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=fa_asset', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //selecting Id
 $(".fa_asset_book_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=fa_asset_book', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('body').on('blur', '#current_cost', function () {
  if (!$('#fa_asset_retirement_id').val()) {
   $('#original_cost').val($(this).val());
  }
 });


 $('#content').off('blur', '#salvage_value_percentage , #salvage_value_amount ,#current_cost')
         .on('blur', '#salvage_value_percentage , #salvage_value_amount ,#current_cost', function () {
          var sal_percentage = $('#salvage_value_percentage').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
          var current_cost = $('#current_cost').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");

          if (sal_percentage) {
           var sal_val = ((sal_percentage * current_cost) / 100).toFixed(5);
           $('#salvage_value_amount').val(sal_val);
          } else {
           var sal_val = $('#salvage_value_amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
          }

          if (sal_val && current_cost) {
           var recoverable_amount = current_cost - sal_val;
           $('#recoverable_amount').val(recoverable_amount);
          }
         });

});
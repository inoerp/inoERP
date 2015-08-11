
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

 $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('#status').val('');
  $('.retire_date').val('');
 });

});
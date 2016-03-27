$(document).ready(function () {
 $('body').off('click', 'a.pm_recipe_material_header_id_withRecipeName').on('click', 'a.pm_recipe_material_header_id_withRecipeName', function (e) {
  e.preventDefault();
  var pm_recipe_header_id = $('#pm_recipe_header_id').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&pm_recipe_header_id=' + pm_recipe_header_id ;
  getFormDetails(formUrl);
 }).one();


});
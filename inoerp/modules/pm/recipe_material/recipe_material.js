$(document).ready(function () {
 $('body').off('click', 'a.pm_recipe_material_header_id_withRecipeName').on('click', 'a.pm_recipe_material_header_id_withRecipeName', function (e) {
  e.preventDefault();
  var pm_recipe_header_id = $('#pm_recipe_header_id').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&pm_recipe_header_id=' + pm_recipe_header_id ;
  getFormDetails(formUrl);
 }).one();


$('#form_line').on('change', '.pm_formula_ingredient_id', function(){
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/,'.');
  $(trClass).find('.uom_id').val($(this).find('option:selected').data('uom_id'));
  $(trClass).find('.quantity').val($(this).find('option:selected').data('quantity'));

});

$('body').off('change', 'select.pm_process_routing_line_id').on('change', 'select.pm_process_routing_line_id' , function (e) {
  $(this).closest('tr').find('input.step').val($(this).find('option:selected').data('step_no'));
 });
 
});
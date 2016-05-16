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
  $(this).closest('tr').find('input.step_no').val($(this).find('option:selected').data('step_no'));
 });
 
 $('body').off('change','.one_value').on('change','.one_value' , function(){
   $(this).closest('tr').find('.one_value').not($(this)).val('').attr('disabled', true);
});

 $('body').find('.one_value').each(function(){
  if($(this).val() != 'undefined' && $(this).val() != ''){
   $(this).closest('tr').find('.one_value').not($(this)).val('').attr('disabled', true);
  }
  });
  
    $('form#pm_recipe_material_line').off('click','input[name="line_id_cb"]').on('click','input[name="line_id_cb"]', function(){
  $(this).closest('tr').find('.one_value').removeAttr('disabled');
});
 
});
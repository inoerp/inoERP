$(document).ready(function () {

 $('body').off('change', '#qa_cp_header_id').on('change', '#qa_cp_header_id', function () {
  $('#form_line').find('.qa_cp_header_id').val($(this).val());
 });


 var default_form = '<input type="text" data-toggle="tooltip" title="" placeholder="" class="textfield  value_from" size="20" maxlength="256" value="" name="value_from[]">';
 var default_to = '<input type="text" data-toggle="tooltip" title="" placeholder="" class="textfield  value_from" size="20" maxlength="256" value="" name="value_from[]">';

 var category_form = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="category" data-val_value="category" class="val_field textfield  value_from ui-autocomplete-input" size="20" value="" name="value_from[]" autocomplete="off">';
 var category_to = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="category" data-val_value="category" class="val_field textfield  value_to ui-autocomplete-input" size="20" value="" name="value_to[]" autocomplete="off">';
 var supplier_form = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="supplier" data-val_value="supplier_name" class="val_field textfield  value_from ui-autocomplete-input" size="20" value="" name="value_from[]" autocomplete="off">';
 var supplier_to = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="supplier" data-val_value="supplier_name" class="val_field textfield  value_to ui-autocomplete-input" size="20" value="" name="value_to[]" autocomplete="off">';
 var item_form = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="item" data-val_value="item_number" class="val_field textfield  value_from ui-autocomplete-input" size="20" value="" name="value_from[]" autocomplete="off">';
 var item_to = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="item" data-val_value="item_number" class="val_field textfield  value_to ui-autocomplete-input" size="20" value="" name="value_to[]" autocomplete="off">';
 var orgcode_form = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="org" data-val_value="code" class="val_field textfield  value_from ui-autocomplete-input" size="20" value="" name="value_from[]" autocomplete="off">';
 var orgcode_to = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="org" data-val_value="code" class="val_field textfield  value_to ui-autocomplete-input" size="20" value="" name="value_to[]" autocomplete="off">';
 var orgid_form = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="org" data-val_value="org_id" class="val_field textfield  value_from ui-autocomplete-input" size="20" value="" name="value_from[]" autocomplete="off">';
 var orgid_to = '<input type="text" data-toggle="tooltip" title="" data-dependent_field="" data-val_field="org" data-val_value="org_id" class="val_field textfield  value_to ui-autocomplete-input" size="20" value="" name="value_to[]" autocomplete="off">';


 $('#form_line').on('change', '.trigger_name', function () {
  var trClass = '.' + $(this).closest('tr').prop('class').replace(/\s+/g, '.');
  switch ($(this).val()) {
   case 'org.org_code' :
    $(trClass).find('input.value_from').replaceWith(orgcode_form);
    $(trClass).find('input.value_to').replaceWith(orgcode_to);
    break;

   case 'org.org_id' :
    $(trClass).find('input.value_from').replaceWith(orgid_form);
    $(trClass).find('input.value_to').replaceWith(orgid_to);
    break;

   case 'item.item_number' :
    $(trClass).find('input.value_from').replaceWith(item_form);
    $(trClass).find('input.value_to').replaceWith(item_to);
    break;

   case 'category.category' :
    $(trClass).find('input.value_from').replaceWith(category_form);
    $(trClass).find('input.value_to').replaceWith(category_to);
    break;

   case 'supplier.supplier_name' :
    $(trClass).find('input.value_from').replaceWith(supplier_form);
    $(trClass).find('input.value_to').replaceWith(supplier_to);
    break;

   default :
    $(trClass).find('input.value_from').replaceWith(default_form);
    $(trClass).find('input.value_to').replaceWith(default_to);
    break;
  }

 });

});
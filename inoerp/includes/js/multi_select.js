 function beforeSave() {
  if (($('.action').first().val() === 'confirm_payment') || ($('.action').first().val() === 'confirm_receipt')) {
   $('.line_id_cb').first().prop('checked', true);
  }
 }
 
$(document).ready(function () {
 $('.select_popup').hide();

 $('#multi_select').on('click', '#search_reset_btn', function (e) {
  e.preventDefault();
  $(this).closest('#searchForm').find('.search_form').find('input:text, select').each(function () {
   $(this).val('');
  });
 });
 
 $('#form_line').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
 var subInventoryId = $(this).val();
 if (subInventoryId > 0) {
  rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'subinventory', rowClass_d);
 }
});

 $('#form_line').off('blur', '.subinventory_id').on('blur', '.subinventory_id', function () {
 var subInventoryId = $(this).val();
 if (subInventoryId > 0) {
  rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  $(rowClass_d).find('.hidden.subinventory_id').val(subInventoryId);
 }
});

 $('#form_line').off('blur', '.locator_id').on('blur', '.locator_id', function () {
 var locator_id = $(this).val();
 if (locator_id > 0) {
  rowClass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  $(rowClass_d).find('.hidden.locator_id').val(locator_id);
 }
});

 //multi select save
 var line_key_field = $('input[type="checkbox"]').first().prop('name');
 if (line_key_field) {
  line_key_field = line_key_field.replace(/\[]/g, " ");
 }
 var action_class = $('[name="multi_action_class"]').val();
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=' + action_class;
 classSave.single_line = false;
 classSave.line_key_field = line_key_field;
 classSave.lineClassName = action_class;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = action_class;
 classSave.form_line_id = 'form_line';
 var actionValue = $('.action').first().val();
 switch (actionValue) {
  case 'convert_requisition' :
  case 'sales_order_picking' :
  case 'multi_receipt' :
  case 'po_receipt' :
  case 'import_ar_transaction' :
   classSave.allLineTogether = true;
   break;

  default :
   classSave.allLineTogether = false;
   break
 }
 classSave.saveMain(beforeSave);


});
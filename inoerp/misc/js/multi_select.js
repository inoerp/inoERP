$(document).ready(function () {
 function beforeSave() {
  if (($('.action').first().val() === 'confirm_payment') || ($('.action').first().val() === 'confirm_receipt')) {
   $('.line_id_cb').first().prop('checked', true);
  }
 }
 $('#multi_select').on('click', '#search_reset_btn', function (e) {
  e.preventDefault();
  $(this).closest('#searchForm').find('.search_form').find('input:text, select').each(function () {
   $(this).val('');
  });
 })
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
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = action_class;
 var actionValue = $('.action').first().val();
 if ((actionValue === 'convert_requisition') || 'sales_order_picking' || 'multi_receipt' || 'po_receipt'
         || 'import_ar_transaction') {
  classSave.allLineTogether = true;
 }
 classSave.saveMain(beforeSave);

});
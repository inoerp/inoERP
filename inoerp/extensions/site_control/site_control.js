$(document).ready(function () {
 var Mandatory_Fields = ["#org_id", "First Select BU Name", "#item_number", "First enter item number"];
 select_mandatory_fields_all('#site_control_divId', Mandatory_Fields);

 //dont allow line entry with out site_control_header id
 $('#form_line').on("click", function () {
  if (!$('#site_control_header_id').val()) {
   alert('No header Id : First enter/save header details');
  } else {
   var PO_ID = $('#site_control_header_id').val();
   if (!$(this).find('.site_control_header_id').val()) {
    $(this).find('.site_control_header_id').val(PO_ID);
   }
  }
 });

 //add a new row
 $("#content").on("click", ".add_row_img", function () {
  add_new_row('tr.site_control_line0', 'tbody.form_data_line_tbody', 3);
 });

//auto complete
 itemNumber_autoComplete('../inv/item/item_search.php');

 //get subinventories on selecting org
 $('#content').on('blur', '#org_id', function () {
  var org_id = $(this).val();
  getSubInventory({
   json_url: '../inv/subinventory/json.subinventory.php',
   org_id: org_id});
 });

 //get locators on changing sub inventory
 $('#content').on('blur', '.subinventory_id', function () {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var subinventory_id = $(this).val();
  getLocator('../inv/locator/json.locator.php', subinventory_id, 'subinventory', trClass);
 });

 //Get the site_control_id on find button click
 $('#form_header a.show').click(function () {
  var site_controlId = $('#site_control_header_id').val();
//$(this).prop('href','site_control.php?site_control_header_id=' + site_controlId);
  $(this).attr('href', 'site_control.php?site_control_header_id=' + site_controlId);
 });

//down load to excel
 $("#indentedBom_divId .export_to_excel").on('click', function (e) {
  exportToExcel_fromDivId('#indentedBom_divId #form_line', 3);
  e.preventDefault();
 });

 $("#site_control_divId .export_to_excel").on('click', function (e) {
  exportToExcel_fromDivId('#site_control_divId #form_line', 3);
  e.preventDefault();
 });

//remove site_control lines
 $("#remove_row").click(function () {
  $('input[name="site_control_line_id_cb"]:checked').each(function () {
   $(this).closest('tr').remove();
  });
 });

//get the attachement form
 deleteData('json.site_control.php');
 save('json.site_control.php', '#site_control_header', 'line_id_cb', 'site_name', '#site_control_header_id');

});

function setValFromSelectPage(po_asl_header_id, asl, supplier_id, supplier_number, supplier_name,
        supplier_site_id, supplier_site_name, item_id_m, item_number, item_description) {
 this.po_asl_header_id = po_asl_header_id;
 this.asl = asl;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.supplier_site_id = supplier_site_id;
 this.supplier_site_name = supplier_site_name;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
}

setValFromSelectPage.prototype.setVal = function () {
 var supplier_site_id = this.supplier_site_id;
 var asl = this.asl;
 var po_asl_header_id = this.po_asl_header_id;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var supplier_site_name = this.supplier_site_name;
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');

 if (po_asl_header_id) {
  $('#content').find('#po_asl_header_id').val(po_asl_header_id);
 }
 if (asl) {
  $('#content').find('#asl').val(asl);
 }
 if (supplier_id) {
  $('#content').find(rowClass).find(".supplier_id").val(supplier_id);
 }
 if (supplier_site_id) {
  $('#content').find(rowClass).find(".supplier_site_id").val(supplier_site_id);
 }
 if (supplier_number) {
  $('#content').find(rowClass).find(".supplier_number").val(supplier_number);
 }

 if (supplier_site_name) {
  $('#content').find(rowClass).find(".supplier_site_name").val(supplier_site_name);
 }

 if (supplier_name) {
  $('#content').find(rowClass).find(".supplier_name").val(supplier_name);
  $('#content').find(rowClass).find(".select_supplier_name").val(supplier_name);
 }

 if (this.item_id_m) {
  $('#item_id_m').val(this.item_id_m);
 }
 if (this.item_number) {
  $('#item_number').val(this.item_number);
 }
 if (this.item_description) {
  $('#description').val(this.item_description);
 }
 localStorage.removeItem("row_class");

 if (this.po_asl_header_id) {
  $('a.show.po_asl_header_id').trigger('click');
 }

};

function afterAddNewRow() {
 $('.supplier_site_id').last().replaceWith('<input class="textfield supplier_site_id" type="text" title="" size="15" maxlength="256" value="" name="supplier_site_id[]" >');
}

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'po_asl_header_id';
 mandatoryCheck.mandatoryHeader();
// mandatoryCheck.form_area = 'form_header';
// mandatoryCheck.mandatory_fields = ["bu_org_id", "item_number"];
// mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

 //Popup for selecting asl
 $(".po_asl_header_id.select_popup").click(function () {
  void window.open('select.php?class_name=po_asl_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

 $("#content").off("change", '.supplier_name, .supplier_id').on("change", '.supplier_name, .supplier_id', function () {
  var trClass = '.' + $(this).closest('tr').prop('class');
  if (($(this).closest('tr').find('.supplier_id').val())) {
   var supplier_id = $(this).closest('tr').find('.supplier_id').val();
   getSupplierDetails('modules/ap/supplier/json_supplier.php', '', supplier_id, trClass);
  }
 });

 //selecting supplier
 $("#content").off("click", '.select_supplier_name.select_popup').on("click", '.select_supplier_name.select_popup', function () {
  var rowClass = $(this).closest('tr').prop('class');
  localStorage.setItem("row_class", rowClass);
  void window.open('select.php?search_class_name=supplier_all_v', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 $("body").off("click", ".add_row_img").on("click", ".add_row_img", function () {
  $('.supplier_site_id').last().replaceWith('<input class="textfield supplier_site_id" type="text" title="" size="15" maxlength="256" value="" name="supplier_site_id[]" >');

 });

});

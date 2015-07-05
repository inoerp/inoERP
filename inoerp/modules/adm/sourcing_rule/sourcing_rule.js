function setValFromSelectPage(po_sourcing_rule_header_id, sourcing_rule, supplier_id, supplier_number, supplier_name,
				supplier_site_id, supplier_site_name) {
 this.po_sourcing_rule_header_id = po_sourcing_rule_header_id;
 this.sourcing_rule = sourcing_rule;
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.supplier_site_id = supplier_site_id;
 this.supplier_site_name = supplier_site_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var supplier_site_id = this.supplier_site_id;
 var sourcing_rule = this.sourcing_rule;
 var po_sourcing_rule_header_id = this.po_sourcing_rule_header_id;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var supplier_site_name = this.supplier_site_name;
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');

 if (po_sourcing_rule_header_id) {
	$('#content').find('#po_sourcing_rule_header_id').val(po_sourcing_rule_header_id);
 }
 if (sourcing_rule) {
	$('#content').find('#sourcing_rule').val(sourcing_rule);
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

 localStorage.removeItem("row_class");

if(this.po_sourcing_rule_header_id){
 $('a.show.po_sourcing_rule_header_id').trigger('click');
}

};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'sourcing_rule_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();

 //Popup for selecting sourcing_rule
 $('body').off( 'click' , '.po_sourcing_rule_header_id.select_popup')
         .on( 'click' , '.po_sourcing_rule_header_id.select_popup' ,function() {
	void window.open('select.php?class_name=po_sourcing_rule_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });


 $("#content").off("blur", '.supplier_name, .supplier_id').on("blur", '.supplier_name, .supplier_id', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	if (($(this).closest('tr').find('.supplier_id').val())) {
	 var supplier_id = $(this).closest('tr').find('.supplier_id').val();
	 getSupplierDetails('modules/ap/supplier/json_supplier.php', '', supplier_id, trClass);
	}
 });

 //selecting supplier
 $("#content").off("click", '.select_supplier_name.select_popup').on("click", '.select_supplier_name.select_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	localStorage.setItem("row_class", rowClass);
	void window.open('select.php?search_class_name=supplier_all_v', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});
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
 $(".sourcing_rule_header_id.select_popup").click(function() {
	void window.open('select.php?class_name=po_sourcing_rule_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the sourcing_rule_id on find button click
 $('a.show.po_sourcing_rule_header_id').click(function() {
	var headerId = $('#po_sourcing_rule_header_id').val();
	$(this).attr('href', modepath() + 'po_sourcing_rule_header_id=' + headerId);
 });

 $("#content").on("change", '.supplier_name, .supplier_id', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	function afterFunction(result) {
	 var supplier_sites = $(result).find('div#json_supplierSites_find_all').html();
	  $('#content').find(trClass).find('.supplier_site_id').replaceWith(supplier_sites);
		$('#content').find(trClass).find('.supplier_site_id').removeAttr('id');
	 trClass = null;
	}
	if (($(this).closest('tr').find('.supplier_id').val())) {
	 var supplier_id = $(this).closest('tr').find('.supplier_id').val();
	 getSupplierDetails('modules/ap/supplier/json_supplier.php', '', supplier_id, afterFunction);
	}
 });

 //selecting supplier
 $("#content").on("click", '.select_supplier_name.select_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	localStorage.setItem("row_class", rowClass);
	void window.open('select.php?search_class_name=supplier_all_v', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //add a new row
// onClick_add_new_row('sourcing_rule_line', 'form_data_line_tbody', 1)
 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'sourcing_rule_line0';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 deleteData('form.php?class_name=po_sourcing_rule_header&line_class_name=po_sourcing_rule_line');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'po_ourcing_rule_header_id';
 classContextMenu.docLineId = 'po_sourcing_rule_line_id';
 classContextMenu.btn1DivId = 'sourcing_rule_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'po_sourcing_rule_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 1;
 classContextMenu.contextMenu();

//remove sourcing_rule lines
 $("#remove_row").click(function() {
	$('input[name="sourcing_rule_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//get the attachement form
 deleteData('form.php?class_name=po_sourcing_rule_header&line_class_name=po_sourcing_rule_line');

// save('json.sourcing_rule.php', '#sourcing_rule_header', 'line_id_cb', 'component_item_id', '#sourcing_rule_header_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=po_sourcing_rule_header';
 classSave.form_header_id = 'sourcing_rule_header';
 classSave.primary_column_id = 'po_sourcing_rule_header_id';
 classSave.line_key_field = 'rank';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'po_sourcing_rule_header';
 classSave.lineClassName = 'po_sourcing_rule_line';
 classSave.saveMain();
});

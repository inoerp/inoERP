function setValFromSelectPage(wip_wo_header_id, wo_number, org_id) {
 this.wip_wo_header_id = wip_wo_header_id;
 this.wo_number = wo_number;
 this.org_id = org_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var wo_obj = [{id: 'wip_wo_header_id', data: this.wip_wo_header_id},
	{id: 'wo_number', data: this.wo_number},
	{id: 'org_id', data: this.org_id}
 ];

 $(wo_obj).each(function(i, value) {
	if (value.data) {
	 var fieldId = '#' + value.id;
	 $('#content').find(fieldId).val(value.data);
	}
 });
};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'wip_wo_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "transaction_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Transaction Type"];
// mandatoryCheck.mandatoryField();

 var document_type = 'Work Order';
 var reference = 'wip_wo_header_id';
 var documentNumber = $('#wo_number').val();
 var documentId = $('#wip_wo_header_id').val();

 $('#content').on('blur', '.bom_sequence', function() {
	if (!$('#allData tr').length) {
	 alert('No BOM found for the work order#' + $('#wo_number').val());
	 $(this).val('');
	 return false;
	}

	var bomSeq = $(this).val();
	var trClass = '.' + $(this).closest('tr').attr('class');
	var bomId = $('#allData tr.' + bomSeq).find('.wip_wo_bom_id').val();
	var transaction_type_id = $('#transaction_type_id').val();
	$(this).closest('tr').find('.wip_wo_bom_id').val(bomId);

	var itemId = $('#allData tr.' + bomSeq).find('.component_item_id_m_m').val();
	$(this).closest('tr').find('.item_id_m_m').val(itemId);

	var item_number = $('#allData tr.' + bomSeq).find('.component_item_number').val();
	$(this).closest('tr').find('.item_number').val(item_number);

	var item_description = $('#allData tr.' + bomSeq).find('.component_description').val();
	$(this).closest('tr').find('.item_description').val(item_description);

	var uom_id = $('#allData tr.' + bomSeq).find('.component_uom').val();
	$(this).closest('tr').find('.uom_id').val(uom_id);
	var subinventory_id = $('#allData tr.' + bomSeq).find('.supply_sub_inventory').val();
	var locator_html = $('#allData tr.' + bomSeq).find('.supply_locator').html();

	if (transaction_type_id == 6) {
	 $(this).closest('.tabContainer').find(trClass).find('.from_subinventory_id').val(subinventory_id);
	 $(this).closest('.tabContainer').find(trClass).find('.from_locator_id').empty().append(locator_html);
	 $(this).closest('.tabContainer').find(trClass).find('.to_subinventory_id').val('');
	 $(".to_subinventory_id").attr("disabled", true);
	 $(".to_locator_id").attr("disabled", true);
	}
	else if (transaction_type_id == 7) {
	 $(this).closest('.tabContainer').find(trClass).find('.to_subinventory_id').val(subinventory_id);
	 $(this).closest('.tabContainer').find(trClass).find('.to_locator_id').empty().append(locator_html);
	 $(this).closest('.tabContainer').find(trClass).find('.from_subinventory_id').val('');
	 $(".from_subinventory_id").attr("disabled", true);
	 $(".from_locator_id").attr("disabled", true);
	} else {
	 $(this).closest('.tabContainer').find(trClass).find('.to_subinventory_id').val('');
	 $(this).closest('.tabContainer').find(trClass).find('.from_subinventory_id').val('');
	 $(".from_subinventory_id").attr("disabled", true);
	 $(".from_locator_id").attr("disabled", true);
	 $(".to_subinventory_id").attr("disabled", true);
	 $(".to_locator_id").attr("disabled", true);
	}

	$(this).closest('.tabContainer').find(trClass).find('.document_type').val(document_type);
	$(this).closest('.tabContainer').find(trClass).find('.document_number').val(documentNumber);
	$(this).closest('.tabContainer').find(trClass).find('.document_id').val(documentId);
	$(this).closest('.tabContainer').find(trClass).find('.reference').val(reference);
 });

 $("#transaction_type_id").on("blur", function() {
	$("tr.transfer_info").find("td select").each(function() {
	 $(this).val("");
	});
	var transaction_type_id = $(this).val();
	switch (transaction_type_id) {
	 case "6":
		$(".from_subinventory_id").attr("disabled", false);
		$(".from_locator_id").attr("disabled", false);
		$(".to_subinventory_id").attr("disabled", true);
		$(".to_locator_id").attr("disabled", true);
		break;

	 case "7":
		$(".to_subinventory_id").attr("disabled", false);
		$(".to_locator_id").attr("disabled", false);
		$(".from_subinventory_id").attr("disabled", true);
		$(".from_locator_id").attr("disabled", true);
		break;

	 default:
		$(".to_subinventory_id").attr("disabled", false);
		$(".to_locator_id").attr("disabled", false);
		$(".from_subinventory_id").attr("disabled", false);
		$(".from_locator_id").attr("disabled", false);
	}

 });

 //selecting wo header id data
 $(".wip_wo_headerid_popup").on("click", function() {
	var openUrl = 'select.php?class_name=wip_wo_header&wo_status=RELEASED';
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the primary_id on refresh button click
 $('a.show.wip_wo_headerid_show').click(function() {
	var wip_wo_header_id = $('#wip_wo_header_id').val();
	var transaction_type_id = $('#transaction_type_id').val();
	var wo_number = $('#wo_number').val();
	var link = 'transaction_type_id=' + transaction_type_id;
	if (wip_wo_header_id) {
	 link += '&wip_wo_header_id=' + wip_wo_header_id;
	} else if (wo_number) {
	 link += '&wo_number=' + wo_number;
	}
	$(this).attr('href', modepath() + link);
 });

 //get Subinventory on Inventory change
 $('#content').on('blur', '#org_id', function() {
	var orgId = $(this).val();
	if (orgId > 0) {
	 getSubInventory('modules/inv/subinventory/json_subinventory.php', orgId);
	}
 });

 //get locatot on Subinventory change
 $('#content').on('change', '.sub_inventory', function() {
	var subInventoryId = $(this).val();
	if (subInventoryId > 0) {
	 var trClass = '.' + $(this).closest('tr').attr('class');
	 getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'subinventory', trClass);
	}
 });

//ajax for char of account combinations
// $('.account').autocomplete({source: '../../gl/coa_combination/coa_search.php', minLength: 2});

// itemNumber_autoComplete('../../inv/item/item_search.php');

 function popup() {
	$("#content").on("click", ".popup.itemId", function() {
	 var idValue = $(this).closest("tr").attr("id");
	 localStorage.idValue = idValue;
	 var link = '../../inv/item/find_item.php?org_id=' + $("#org_id").val() + '&RowDivId=' + idValue;
	 void window.open(link, '_blank',
					 'width=900,height=900,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
	 return false;
	}).one();
 }
 popup();

//add new line
// onClick_add_new_row('tr.inv_transaction_row0', 'tbody.inv_transaction_values', 4);
   $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'inv_transaction_row';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 4;
	addNewRow.removeDefault = false;
	addNewRow.add_new_row();
 });
 
// save('../../inv/inv_transaction/json.inv_transaction.php', '#inv_transaction', 'inv_transaction_id_cb', 'item_id_m_m', '#inv_transaction_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=wip_material_transaction';
 classSave.line_key_field = 'item_id_m_m';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.lineClassName = 'wip_material_transaction';
 classSave.saveMain();
});


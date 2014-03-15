$(document).ready(function() {
// $(".document_number").attr("required", true);
////Make subinevntory locator changes after selcting transaction type
// var Mandatory_Fields = ["#wip_wo_header_id", "First Select Work Order", "#transaction_type_id", "First Select Transaction Type Id"];
// select_mandatory_fields(Mandatory_Fields);

var document_type = 'Work Order';
var reference='wip_wo_header_id';
var documentNumber = $('#wo_number').val();
var documentId = $('#wip_wo_header_id').val();

$('#content').on('blur','.bom_sequence', function(){
var bomSeq = $(this).val();
var trClass = '.'+$(this).closest('tr').attr('class');
var bomId = $('#allData tr.'+bomSeq).find('.wip_wo_bom_id').val();
var transaction_type_id = $('#transaction_type_id').val();
$(this).closest('tr').find('.wip_wo_bom_id').val(bomId);

var itemId = $('#allData tr.'+bomSeq).find('.component_item_id').val();
$(this).closest('tr').find('.item_id').val(itemId);

var item_number = $('#allData tr.'+bomSeq).find('.component_item_number').val();
$(this).closest('tr').find('.item_number').val(item_number);

var item_description = $('#allData tr.'+bomSeq).find('.component_description').val();
$(this).closest('tr').find('.item_description').val(item_description);

var uom_id = $('#allData tr.'+bomSeq).find('.component_uom').val();
$(this).closest('tr').find('.uom_id').val(uom_id);
var subinventory_id = $('#allData tr.'+bomSeq).find('.supply_sub_inventory').val();
var locator_html = $('#allData tr.'+bomSeq).find('.supply_locator').html();

if (transaction_type_id == 6){
$(this).closest('.tabContainer').find(trClass).find('.from_subinventory_id').val(subinventory_id);
$(this).closest('.tabContainer').find(trClass).find('.from_locator_id').empty().append(locator_html);
$(this).closest('.tabContainer').find(trClass).find('.to_subinventory_id').val('');
		$(".to_subinventory_id").attr("disabled", true);
		$(".to_locator_id").attr("disabled", true);
}
else if(transaction_type_id == 7){
$(this).closest('.tabContainer').find(trClass).find('.to_subinventory_id').val(subinventory_id);
$(this).closest('.tabContainer').find(trClass).find('.to_locator_id').empty().append(locator_html);
$(this).closest('.tabContainer').find(trClass).find('.from_subinventory_id').val('');
		$(".from_subinventory_id").attr("disabled", true);
		$(".from_locator_id").attr("disabled", true);
}else{
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
	localStorage.idValue = "";
	var link = '../wip_wo/find_wip_wo_released.php?wo_status=RELEASED';
	void window.open(link, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
 //Get the primary_id on refresh button click
 $('a.show.wip_wo_headerid_show').click(function() {
	var wip_wo_header_id = $('#wip_wo_header_id').val();
	var transaction_type_id = $('#transaction_type_id').val();
	var wo_number = $('#wo_number').val();
	var link = '?transaction_type_id='+transaction_type_id;
	if(wip_wo_header_id){
	 link +='&wip_wo_header_id=' + wip_wo_header_id;
	}else if(wo_number){
	 link +='&wo_number=' + wo_number;
	}
	$(this).attr('href', link);

 });

 //get Subinventory on Inventory change
 $('#content').on('blur', '#org_id', function() {
	var orgId = $(this).val();
	if (orgId > 0) {
	 getSubInventory('../../inv/subinventory/json.subinventory.php', orgId);
	}
 });

 //get locatot on Subinventory change
 $('#content').on('change', '.sub_inventory', function() {
	var subInventoryId = $(this).val();
	if (subInventoryId > 0) {
	 var trClass = '.' + $(this).closest('tr').attr('class');
	 getLocator('../../inv/locator/json.locator.php', subInventoryId, 'subinventory', trClass);
	}
 });

//ajax for char of account combinations
 $('.account').autocomplete({source: '../../gl/coa_combination/coa_search.php', minLength: 2});

 itemNumber_autoComplete('../../inv/item/item_search.php');

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
 onClick_add_new_row('tr.inv_transaction_row0', 'tbody.inv_transaction_values', 4);
 save('../../inv/inv_transaction/json.inv_transaction.php', '#inv_transaction', 'inv_transaction_id_cb', 'item_id', '#inv_transaction_id');
 $(" :required").css("background-color", "pink");
});


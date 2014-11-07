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
 mandatoryCheck.mandatory_fields = ["wip_wo_header_id", "transaction_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Transaction Type"];

 $('#content').on('change', '.quantity', function() {
	var enteredQty = $(this).val();
	var availableQty = $(this).closest('tr').find('.available_quantity').val();
	if (+enteredQty > +availableQty) {
	 $(this).val('');
	 alert('Entered quantity is more than available quantity');
	}
 });

 function enableDisable() {
	var transaction_type_id = $('#transaction_type_id').val();
	switch (transaction_type_id) {
	 case "13":
		$(".from_subinventory_id").attr("disabled", false);
		$(".from_locator_id").attr("disabled", false);
		$(".to_subinventory_id").attr("disabled", true);
		$(".to_locator_id").attr("disabled", true);
		$(".to_subinventory_id").val('');
		$(".to_locator_id").val('');
		break;

	 case "11":
		$(".to_subinventory_id").attr("disabled", false);
		$(".to_locator_id").attr("disabled", false);
		$(".from_subinventory_id").attr("disabled", true);
		$(".from_locator_id").attr("disabled", true);
		$(".from_subinventory_id").val('');
		$(".from_locator_id").val('');
		break;

	 default:
		$(".to_subinventory_id").attr("disabled", true);
		$(".to_locator_id").attr("disabled", true);
		$(".from_subinventory_id").attr("disabled", true);
		$(".from_locator_id").attr("disabled", true);
		$(".to_subinventory_id").val('');
		$(".to_locator_id").val('');
		$(".from_subinventory_id").val('');
		$(".from_locator_id").val('');
	}
 }

 enableDisable();

 $("#transaction_type_id").on("blur", function() {
	enableDisable();
 });

 //selecting wo header id data
 $(".wip_wo_headerid_popup").on("click", function() {
	localStorage.idValue = "";
	var link = 'select.php?class_name=wip_wo_header&wo_status=RELEASED';
	void window.open(link, '_blank',
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

 //get locatot on Subinventory change
 $('#content').on('change', '.from_subinventory_id', function() {
	var subInventoryId = $(this).val();
	if (subInventoryId > 0) {
	 var trClass = '.' + $(this).closest('tr').attr('class');
	 getLocator('inv/locator/json_locator.php', subInventoryId, 'from_subinventory_id', trClass);
	}
 });

 $('#content').on('change', '.to_subinventory_id', function() {
	var subInventoryId = $(this).val();
	if (subInventoryId > 0) {
	 var trClass = '.' + $(this).closest('tr').attr('class');
	 getLocator('inv/locator/json_locator.php', subInventoryId, 'to_subinventory_id', trClass);
	}
 });


 function popup() {
	$("#content").on("click", ".popup.itemId", function() {
	 var idValue = $(this).closest("tr").attr("id");
	 localStorage.idValue = idValue;
	 var link = 'search.php?class_name=item&org_id=' + $("#org_id").val() + '&RowDivId=' + idValue;
	 void window.open(link, '_blank',
					 'width=900,height=900,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
	 return false;
	}).one();
 }
 popup();

//add new line
// onClick_add_new_row('tr.inv_transaction_row0', 'tbody.inv_transaction_values', 4);

// $("body table.form_table").on("click", ".add_row_img", function() {
//	add_new_row_withDefault('tr.inv_transaction_row0', 'tbody.inv_transaction_values', 4);
// });

// save('json.wip_move_transaction.php', '#wip_move_transaction', '', '', '#wip_move_transaction_id', '');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=wip_wo_completion';
 classSave.form_header_id = 'wip_wo_completion';
 classSave.primary_column_id = 'inv_transaction_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = false;
 classSave.headerClassName = 'wip_wo_completion';
 classSave.saveMain();
 
// save('../../inv/inv_transaction/json.inv_transaction.php', '#inv_transaction', 'inv_transaction_id_cb', 'item_id_m', '#inv_transaction_id');

});


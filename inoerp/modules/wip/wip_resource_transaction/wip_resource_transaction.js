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

 $('#content').on('focusout', '#to_operation_step', function() {
	if (($('#to_operation_step').val() == $('#from_operation_step')) && ($('#to_routing_sequence').val() == $('#to_routing_sequence').val())) {
	 $('#to_routing_sequence').val('');
	 alert('Invalid Operation! - Source & Destination should be different.');
	}
 });

 $("#transaction_type_id").on("change", function() {
	$("tr.transfer_info").find("td select").each(function() {
	 $(this).val("");
	})
	var transaction_type_id = $(this).val();
	switch (transaction_type_id) {
	 case "1":
		$(".from_subinventory_id").attr("disabled", false);
		$(".from_locator_id").attr("disabled", false);
		$("#account_id").attr("required", true);
		$(".to_subinventory_id").attr("disabled", true);
//		$(".to_locator_id").val("");
		$(".to_locator_id").attr("disabled", true);
		break;

	 case "2":
		$(".to_subinventory_id").attr("disabled", false);
		$(".to_locator_id").attr("disabled", false);
		$("#account_id").attr("required", true);
		$(".from_subinventory_id").attr("disabled", true);
//		$(".from_locator_id").val("");
		$(".from_locator_id").attr("disabled", true);
		break;

	 default:
		$(".to_subinventory_id").attr("disabled", false);
		$(".to_locator_id").attr("disabled", false);
		$(".from_subinventory_id").attr("disabled", false);
		$(".from_locator_id").attr("disabled", false);
	}

 });

//validation of entered quantity
 $('#content').on('focusout', '#from_operation_step', function() {
	var fromStep = '.' + $(this).val() + '_quantity';
	var fromSeq = $('#from_routing_sequence').val();
	var rowClass = '';
	$('.routing_sequence').each(function() {
	 if ($(this).val() == fromSeq) {
		rowClass = '.' + $(this).closest('tr').attr('class');
	 }
	});
	var availableQuantity = $(rowClass).find(fromStep).val();
	if (availableQuantity) {
	 $('#available_quantity').val(availableQuantity);
	} else {
	 $('#available_quantity').val('0')
	 alert('Error!! : No available quantity to move!');
	}
 });

 $("#content").on('focusout', '#move_quantity', function() {
	if (+($(this).val()) > +($('#available_quantity')).val()) {
	 $(this).val('');
	 alert('Error!! : Entered move quantity is more than available quantity');
	} else if (($(this).val()) < 0) {
	 alert('Error!! : Entered more than zero quantity');
	}
 });


 //selecting wo header id data
 $(".wip_wo_header_id.select_popup").on("click", function() {
	localStorage.idValue = "";
	var link = 'select.php?class_name=wip_wo_header&wo_status=RELEASED';
	void window.open(link, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the primary_id on refresh button click
 $('a.show.wip_wo_headerid_show').click(function() {
	var wip_wo_header_id = $('#wip_wo_header_id').val();
	$(this).attr('href', modepath() + 'wip_wo_header_id=' + wip_wo_header_id);
 });

//add new line
 onClick_add_new_row('tr.wip_resource_transaction_row0', 'tbody.wip_resource_transaction_values', 4);
//  save('json.wip_resource_transaction.php', '#wip_resource_transaction', 'line_id_cb', 'wip_wo_routing_detail_id', '#wip_resource_transaction_id', '');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=wip_resource_transaction';
 classSave.line_key_field = 'transaction_quantity';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.lineClassName = 'wip_resource_transaction';
 classSave.enable_select = true;
 classSave.saveMain();
 
//delete line
 deleteData('json.wip_resource_transaction.php');


});


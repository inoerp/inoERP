$(document).ready(function() {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'wip_wo_header_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "transaction_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Transaction Type"];

 $('body').off("change", '#transaction_type_id').on("change", '#transaction_type_id', function() {
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
  $('body').off('blur', '#wip_move_transaction #from_operation_step').on('blur', '#wip_move_transaction #from_operation_step', function() {
	var fromStep = '.' + $(this).val() + '_quantity';
	var fromSeq = $('#from_routing_sequence').val();
	var rowClass = '';
	$('.routing_sequence').each(function() {
    if ($(this).val() == fromSeq) {
		rowClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g,'.');
    return false;
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

 $('body').off('blur', '#wip_move_transaction #move_quantity').on('blur', '#wip_move_transaction #move_quantity', function() {
	if (+($(this).val()) > +($('#available_quantity')).val()) {
	 $(this).val('');
	 alert('Error!! : Entered move quantity is more than available quantity');
	} else if (($(this).val()) < 0) {
	 alert('Error!! : Entered more than zero quantity');
	}
 });



});


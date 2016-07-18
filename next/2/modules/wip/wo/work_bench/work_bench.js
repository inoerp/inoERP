
$(document).ready(function() {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'wip_wo_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "transaction_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Transaction Type"];

 $('#wip_wo_work_bench').off("change", '#transaction_type_id').on("change", '#transaction_type_id', function() {
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
 $('#wip_wo_work_bench').off('focusout', '#from_operation_step').on('focusout', '#from_operation_step', function() {
	var fromStep = '.' + $(this).val() + '_quantity';
	var fromSeq = $('#from_routing_sequence').val();
	var rowClass = '';
	$('.routing_sequence').each(function() {
    if ($(this).val() == fromSeq) {
		rowClass = '.' + $(this).closest('tr').attr('class');
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

 $("#wip_wo_work_bench").off('focusout', '#move_quantity').on('focusout', '#move_quantity', function() {
	if (+($(this).val()) > +($('#available_quantity')).val()) {
	 $(this).val('');
	 alert('Error!! : Entered move quantity is more than available quantity');
	} else if (($(this).val()) < 0) {
	 alert('Error!! : Entered more than zero quantity');
	}
 });


//selecting wo header id data
 $('#wip_wo_work_bench').off("click", '.wip_wo_header_id.select_popup').on("click", '.wip_wo_header_id.select_popup', function() {
	localStorage.idValue = "";
	var link = 'select.php?class_name=wip_wo_header&wo_status=%3DRELEASED';
	void window.open(link, '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
 
$('#wip_wo_work_bench').off('change', '#from_routing_sequence').on('change', '#from_routing_sequence' ,function(){
  if($(this).val()){
    $(this).closest('ul').find(':input').attr('required',true).css('background-color','pink');
  }else{
  $(this).closest('ul').find(':input').attr('required',false).css('background-color','white');
  }


});
});


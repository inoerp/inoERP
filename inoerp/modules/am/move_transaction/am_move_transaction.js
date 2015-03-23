function setValFromSelectPage(am_wo_header_id, wo_number, org_id, combination) {
 this.am_wo_header_id = am_wo_header_id;
 this.wo_number = wo_number;
 this.org_id = org_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var wo_obj = [{id: 'am_wo_header_id', data: this.am_wo_header_id},
	{id: 'wo_number', data: this.wo_number},
	{id: 'org_id', data: this.org_id}
 ];

 $(wo_obj).each(function(i, value) {
	if (value.data) {
	 var fieldId = '#' + value.id;
	 $('#content').find(fieldId).val(value.data);
	}
 });
 
  if (this.combination) {
	$('#scrap_account_id').val(this.combination);
	localStorage.removeItem("field_class");
 }
 
  if (this.am_wo_header_id) {
    $('a.show.am_wo_header_id').trigger('click');
 }
};

$(document).ready(function() {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'am_wo_header_id';
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
 $('#content').off('focusout', '#from_operation_step').on('focusout', '#from_operation_step', function() {
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

 $("#content").off('focusout', '#move_quantity').on('focusout', '#move_quantity', function() {
	if (+($(this).val()) > +($('#available_quantity')).val()) {
	 $(this).val('');
	 alert('Error!! : Entered move quantity is more than available quantity');
	} else if (($(this).val()) < 0) {
	 alert('Error!! : Entered more than zero quantity');
	}
 });


//selecting wo header id data
 $('body').off("click", '.am_wo_header_id.select_popup').on("click", '.am_wo_header_id.select_popup', function() {
	localStorage.idValue = "";
	var link = 'select.php?class_name=am_wo_header&wo_status=%3DRELEASED';
	void window.open(link, '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});


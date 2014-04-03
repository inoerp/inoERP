$(document).ready(function() {
// var Mandatory_Fields = ["#bu_org_id", "First Select BU Name", "#receipt_type", "First Select PO Type"];
// select_mandatory_fields(Mandatory_Fields);

// $('#form_line').on("click", function() {
//	if (!$('#receipt_header_id').val()) {
//	 alert('No header Id : First enter/save header details');
//	} else {
//	 var PO_ID = $('#receipt_header_id').val();
//	 if (!$(this).find('.receipt_header_id').val()) {
//		$(this).find('.receipt_header_id').val(PO_ID);
//	 }
//	}
//
// });

//dont allow search till ship to org is entered
 $('#receipt_pageId #search_submit_btn').prop('disabled', true);
 $('.ship_to_org:first').focus();
 $('.ship_to_org:first').on('focusout', function() {
	if (!$('.ship_to_org:first').val()) {
	 alert('Enter Ship to Org & then click on Search');
	 $('.ship_to_org:first').focus();
	} else {
	 $('#receipt_pageId #search_submit_btn').prop('disabled', false);
	}
 });

//verify entered qty is less than open quantity
$('#content').on('change','.received_quantity', function(){
var newQty = $(this).val();
var shipmentQty = $(this).closest('tr').find('.quantity').val();
var poReceivedQty = $(this).closest('tr').find('.po_received_quantity').val();
if( (+poReceivedQty + +newQty ) > shipmentQty ){
alert('Entered quantity is more than open quantity!');
$(this).val('');
$(this).focus();
}
});

//save & hide save box depending on check box & header id
 $('#save').hide();
 $('#receipt_line_form').on('change', '.checkbox', function() {
	//check if the check box is checked
	if (this.checked) {
	 var trClass = '.' + $(this).closest('tr').attr('class');
	 var subinventory_id = $(this).closest('.tabContainer').find('#tabsLine-2' + ' ' + trClass).find('.subinventory_id').val();
	 var received_quantity = $(this).closest('.tabContainer').find('#tabsLine-2' + ' ' + trClass).find('.received_quantity').val();
	 //check if subinventory is selected else show the error
	 if ((subinventory_id.length > 0) && (received_quantity.length > 0)) {
		//show the save button
		$('#save').show();
//show all the locators
		getLocator('../locator/json.locator.php', subinventory_id, 'subinventory', trClass);

		//SAVE HEADER
		if (!$("#receipt_header_id").val()) {
		 var headerData = $('#receipt_header_form').serializeArray();
		 saveHeader('json.receipt.php', headerData, '#receipt_header_id', '#receipt_number');
		 // $('#save').trigger('click');
		}

	 } else {
		alert('Select the subinventory & received quantity!');
		$(this).prop('checked', false);
	 }
	} else {
	 if (!$("#receipt_header_id").val()) {
		var atLeastOneIsChecked = $('#receipt_line_form :checkbox:checked').length > 0;
		if (!atLeastOneIsChecked) {
		 $('#save').hide();
		 alert('First select line to save!');
		}
	 }
	}
 });
 
 //get locators on changing sub inventory
 $('#content').on('blur', '.subinventory_id', function(){
	var trClass = '.' + $(this).closest('tr').attr('class');
	 var subinventory_id = $(this).val();
 getLocator('../locator/json.locator.php', subinventory_id, 'subinventory', trClass);
 });

// $(".ship_to_inventory").on("focusout", function() {
//	var ship_to_inventory = $(this).val();
//	var rowTrClass = $(this).closest("tr").attr("class");
//	var classValue = "tr." + rowTrClass;
//	getAllInventoryAccounts('../org/inventory/json.inventory.php', ship_to_inventory, classValue);
// });

 //Get the receipt_id on find button click
 $('#form_box a.show').click(function() {
	var receiptId = $('#receipt_header_id').val();
//$(this).prop('href','receipt.php?receipt_header_id=' + receiptId);
	$(this).attr('href', 'receipt.php?receipt_header_id=' + receiptId);
 });

//remove receipt lines
 $("#remove_row").click(function() {
	$('input[name="receipt_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//get the attachement form
 deleteData('json.receipt.php');
 save('json.receipt.php', '#receipt_header_form', 'line_id_cb', 'po_detail_id', '#receipt_header_id', '', '#receipt_number');

});

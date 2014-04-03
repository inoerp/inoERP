$(document).ready(function() {

//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'receipt_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "receipt_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Receipt Type"];
// mandatoryCheck.mandatoryField();

//dont allow search till ship to org is entered
// $('#receipt_pageId #search_submit_btn').prop('disabled', true);
// $('.ship_to_org:first').focus();
// $('.ship_to_org:first').on('focusout', function() {
//	if (!$('.ship_to_org:first').val()) {
//	 alert('Enter Ship to Org & then click on Search');
//	 $('.ship_to_org:first').focus();
//	} else {
//	 $('#receipt_pageId #search_submit_btn').prop('disabled', false);
//	}
// });

$('#search_submit_btn').on('click', function(e){
 if($('.ship_to_org').first().val()){
	
 }else{
	e.preventDefault();
	alert('Enter Ship to Org and then Click on Search');
 }
});

//verify entered qty is less than open quantity
 $('#content').on('change', '.received_quantity', function() {
	var newQty = $(this).val();
	var shipmentQty = $(this).closest('tr').find('.quantity').val();
	var poReceivedQty = $(this).closest('tr').find('.po_received_quantity').val();
	if ((+poReceivedQty + +newQty) > shipmentQty) {
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
 $('#content').on('blur', '.subinventory_id', function() {
	var trClass = '.' + $(this).closest('tr').attr('class');
	var subinventory_id = $(this).val();
	getLocator('../locator/json.locator.php', subinventory_id, 'subinventory', trClass);
 });

 //Get the receipt_id on find button click
 $('#form_box a.show').click(function() {
	var receiptId = $('#receipt_header_id').val();
	$(this).attr('href', 'receipt.php?receipt_header_id=' + receiptId);
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'receipt_header_id';
 classContextMenu.docLineId = 'receipt_line_id';
 classContextMenu.btn1DivId = 'receipt_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'receipt_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 5;
 classContextMenu.contextMenu();


 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=receipt_header';
 classSave.form_header_id = 'receipt_header_form';
 classSave.primary_column_id = 'receipt_header_id';
 classSave.line_key_field = 'item_description';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'receipt_header';
 classSave.lineClassName = 'receipt_line';
 classSave.enable_select = true;
 classSave.saveMain();

});

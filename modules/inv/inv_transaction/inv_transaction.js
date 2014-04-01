function setValFromSelectPage(inv_transaction_header_id, combination, item_id, item_number, item_description, uom_id) {
 this.inv_transaction_header_id = inv_transaction_header_id;
 this.combination = combination;
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;

}

setValFromSelectPage.prototype.setVal = function() {
 var inv_transaction_header_id = this.inv_transaction_header_id;
 var combination = this.combination;
 var item_id = this.item_id;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;

 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (inv_transaction_header_id) {
	$("#inv_transaction_header_id").val(inv_transaction_header_id);
 }
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(rowClass).find(fieldClass).val(combination);
 }
 if (item_id) {
	$('#content').find(rowClass).find('.item_id').val(item_id);
 }
 if (item_number) {
	$('#content').find(rowClass).find('.item_number').val(item_number);
 }
 if (item_description) {
	$('#content').find(rowClass).find('.item_description').val(item_description);
 }
 if (uom_id) {
	$('#content').find(rowClass).find('.uom_id').val(uom_id);
 }
 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");

};

$(document).ready(function() {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'inv_transaction_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "transaction_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "First Select Transaction Type"];
// mandatoryCheck.mandatoryField();


 $("#transaction_type_id").on("change", function() {
	$('.transaction_type_id').val($(this).val());
//	$("tr.transfer_info").find("td select").each(function() {
//	 $(this).val("");
//	})
	var transaction_type_id = $(this).val();
	switch (transaction_type_id) {
	 case "1":
		$(".from_subinventory_id").prop("disabled", false);
		$(".from_locator_id").prop("disabled", false);
		$(".account_id").prop("required", true);
		$(".to_subinventory_id").val('');
		$(".to_subinventory_id").prop("disabled", true);
		$(".to_locator_id").val('');
		$(".to_locator_id").prop("disabled", true);
		break;

	 case "2":
		$(".to_subinventory_id").prop("disabled", false);
		$(".to_locator_id").prop("disabled", false);
		$(".account_id").prop("required", true);
		$(".from_subinventory_id").val('');
		$(".from_subinventory_id").prop("disabled", true);
		$(".from_locator_id").val("");
		$(".from_locator_id").prop("disabled", true);
		break;

	 case "3":
		$(".to_subinventory_id").prop("disabled", false);
		$(".to_locator_id").prop("disabled", false);
		$(".from_subinventory_id").prop("disabled", false);
		$(".from_locator_id").prop("disabled", false);
		break;

	 default:
		$(".to_subinventory_id").prop("disabled", true);
		$(".to_locator_id").prop("disabled", true);
		$(".from_subinventory_id").prop("disabled", true);
		$(".from_locator_id").prop("disabled", true);
	}
 });


 //get Subinventory Name
 $("#org_id").on("change", function() {
	getSubInventory('modules/inv/subinventory/json_subinventory.php', $("#org_id").val());
	$('.org_id').val($(this).val());
 });

 function callGetLocatorForFrom(subinventory_id, rowIdValue) {
	var subinventory_type = "from_subinventory_id";
	getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
 }

 function callGetLocatorForTo(subinventory_id, rowIdValue) {
	var subinventory_type = "to_subinventory_id";
	getLocator('modules/inv/locator/json_locator.php', subinventory_id, subinventory_type, rowIdValue);
 }

 $(".form_table").on("change", ".from_subinventory_id", function() {
	var rowIdValue = $(this).closest("tr").attr("id");
	var idValue = "tr#" + rowIdValue;
	var subinventory_id = $(this).val();
	callGetLocatorForFrom(subinventory_id, idValue);
 });

 $(".form_table").on("change", ".to_subinventory_id", function() {
	var rowIdValue = $(this).closest("tr").attr("id");
	var idValue = "tr#" + rowIdValue;
	var subinventory_id = $(this).val();
	callGetLocatorForTo(subinventory_id, idValue);
 });

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=inv_transaction';
 classSave.line_key_field = 'item_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.lineClassName = 'inv_transaction';
 classSave.saveMain();

 //add new row in multi action template
 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'inv_transaction_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 5;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

});


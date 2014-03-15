$(document).ready(function() {
//Make subinevntory locator changes after selcting transaction type
 var Mandatory_Fields = ["#org_id", "First Select Inventory Org", "#transaction_type_id", "First Select Transaction Type Id"];
 select_mandatory_fields(Mandatory_Fields);

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

//get Subinventory Name
 $("#org_id").on("change", function() {
	getSubInventoryName();
 });

 function getSubInventoryName() {
	$('#loading').show();
	var org_id = $(".form_table #org_id").val();
	$.ajax({
	 url: '../subinventory/json.subinventory.php',
	 data: {org_id: org_id,
		find_all_subinventory: 1},
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#json_subinventory_find_all').html();
	 $(".form_table .from_subinventory_id").append(div);
	 $(".form_table .to_subinventory_id").append(div);
	 $('#loading').hide();
	}).fail(function() {
	 alert("org name loading failed");
	 $('#loading').hide();
	});
	$(".form_table .from_subinventory_id").attr("disabled", false);
 }

//get locator name
function getLocator(subinventory_id, subinventory_type, idValue) {
$('#loading').show();
$.ajax({
 url: '../locator/json.locator.php',
 data: {subinventory_id: subinventory_id,
	find_all_locator: 1},
 type: 'get'
}).done(function(result) {
//   var div = $('#json_locator', $(data)).html();
 var div = $(result).filter('div#json_locator_find_all').html();

 if (subinventory_type == "from_subinventory_id") {
	$(idValue + " .from_locator_id").find('option').remove();
	$(idValue + " .from_locator_id").append(div);
 }
 if (subinventory_type == "to_subinventory_id") {
	$(idValue + " .to_locator_id").find('option').remove();
	$(idValue + " .to_locator_id").append(div);
 }
 $('#loading').hide();
}).fail(function() {
 alert("Locator name loading failed");
 $('#loading').hide();
});
$(".form_table .from_locator_id").attr("disabled", false);
}

function callGetLocatorForFrom(subinventory_id, rowIdValue) {
var subinventory_type = "from_subinventory_id";
getLocator(subinventory_id, subinventory_type, rowIdValue);
}

function callGetLocatorForTo(subinventory_id, rowIdValue) {
var subinventory_type = "to_subinventory_id";
getLocator(subinventory_id, subinventory_type, rowIdValue);
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

// function getLocator(subinventory_id, subinventory_type, objectCount) {
//	$('#loading').show();
//	var idValue = "#" + localStorage.rowIdValue;
//	$.ajax({
//	 url: '../locator/json.locator.php',
//	 data: {subinventory_id: subinventory_id,
//		find_all_locator: 1},
//	 type: 'get'
//	}).done(function(result) {
////   var div = $('#json_locator', $(data)).html();
//	 var div = $(result).filter('div#json_locator_find_all').html();
//	 if (subinventory_type == "from_subinventory_id") {
//		$(idValue + ".from_locator_id").find('option').remove();
//		$(idValue + ".from_locator_id").append(div);
////		if (objectCount > 0) {
////		 $(".form_table .from_locator_id #new_object" + objectCount).find('option').remove();
////		 $(".form_table .from_locator_id #new_object" + objectCount).append(div);
////		} else {
////		 $(".form_table .from_locator_id").find('option').remove();
////		 $(".form_table .from_locator_id").append(div);
////		}
//	 }
//	 if (subinventory_type == "to_subinventory_id") {
//		$(idValue + ".to_locator_id").find('option').remove();
//		$(idValue + ".to_locator_id").append(div);
////		if (objectCount > 0) {
////		 $(".form_table .to_locator_id #new_object" + objectCount).find('option').remove();
////		 $(".form_table .to_locator_id #new_object" + objectCount).append(div);
////		} else {
////		 $(".form_table .to_locator_id").find('option').remove();
////		 $(".form_table .to_locator_id").append(div);
////		}
//	 }
//	 $('#loading').hide();
//	}).fail(function() {
//	 alert("Locator name loading failed");
//	 $('#loading').hide();
//	});
//	$(".form_table .from_locator_id").attr("disabled", false);
// }
//
// function callGetLocatorForFrom(subinventory_id) {
////	var subinventory_id = $(".from_subinventory_id").val();
//	var subinventory_type = "from_subinventory_id";
//	getLocator(subinventory_id, subinventory_type);
// }
//
// function callGetLocatorForTo(subinventory_id) {
////	var subinventory_id = $(".to_subinventory_id").val();
//	var subinventory_type = "to_subinventory_id";
//	getLocator(subinventory_id, subinventory_type);
// }
//
// $(".form_table").on("change", ".from_subinventory_id", function() {
//	localStorage.rowIdValue = $(this).closest("tr").attr("id");
//	var subinventory_id = $(this).val();
//	callGetLocatorForFrom(subinventory_id);
// });
//
// $(".form_table").on("change", ".to_subinventory_id", function() {
//	localStorage.rowIdValue = $(this).closest("tr").attr("id");
//	var subinventory_id = $(this).val();
//	callGetLocatorForTo(subinventory_id);
// });

//ajax for char of account combinations
 $('.account').autocomplete({source: '../../gl/coa_combination/coa_search.php', minLength: 2});

 function itemNumber_autoComplete() {
	$('#content').on("focus", ".item_number", function() {
	 if (!$(this).data("autocomplete")) {
		$(this).autocomplete({
		 source: function(request, response) {
			$.ajax({
			 url: "../item/item_search.php",
			 dataType: "json",
			 data: {
				org_id: $("#org_id").val(),
				term: request.term
			 },
			 success: function(data) {
				response(data);
			 },
			 error: function(result) {
				alert("Error" + result);
			 }
			});
		 },
		 select: function(event, ui) {
			$(this).val(ui.item.item_number);
			$(this).closest("td").siblings().find('input.item_id[type="text"]').val(ui.item.item_id);
			$(this).closest("td").siblings().find('input.item_description[type="text"]').val(ui.item.description);
		 },
		 minLength: 2
		});
	 }
	});
 }

 itemNumber_autoComplete();


 function popup() {
	$("#content").on("click", ".popup.itemId", function() {
	 var idValue = $(this).closest("tr").attr("id");
	 localStorage.idValue = idValue;
	 var link = '../item/find_item.php?org_id=' + $("#org_id").val() + '&RowDivId=' + idValue;
	 void window.open(link, '_blank',
					 'width=900,height=900,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
	 return false;
	}).one();
 }
 popup();

//add new line
 onClick_add_new_row('tr.inv_transaction_row0', 'tbody.inv_transaction_values', 4);
//$("#inv_transaction").on(function(){
// itemNumber_autoComplete();
//}).one();
//Save record
 save('json.inv_transaction.php', '#inv_transaction', 'inv_transaction_id_cb', 'item_id', '#inv_transaction_id');

//delete line
 deleteData('json.inv_transaction.php');


});


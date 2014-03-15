homePageUrl = 'http://www.inoideas.com/inoerp/';
//move to animated block
//$("#animated_block > div:gt(0)").hide();
//
//setInterval(function() { 
//  $('#animated_block > div:first')
//    .fadeOut(1000)
//    .next()
//    .fadeIn(1000)
//    .end()
//    .appendTo('#animated_block');
//},  5000);

//$("#animated_block > div:gt(0)").hide();
//
//setInterval(function() { 
//  $('#animated_block > div:first')
//    .slideUp(1000)
//    .next()
//    .delay(1000)
//    .slideDown(1000)
//    .end()
//    .appendTo('#animated_block');
//},  5000);

function animateCycle()
{
 var interval = null;
 $("#animated_content > div:gt(0)").hide();

 function animateContent() {
	$('#animated_content > div:first')
					.slideUp(1000)
					.next()
					.delay(1000)
					.slideDown(1000)
					.end()
					.appendTo('#animated_content');
 }

 interval = setInterval(animateContent, 5000);

 $('#all_contents').on('click', '#animated_block', function() {
	clearInterval(interval);
 });

 $('#all_contents').on('click', '.stop_play', function() {
	clearInterval(interval);
 });

}
animateCycle();
$('#all_contents').on('click', '.start_play', function() {
 animateCycle();
});

$('#all_contents').on('focusIn', '#animated_block', function() {
 clearInterval(interval);
});

$('#all_contents').on('focusOut', '#animated_block', function() {
 animateCycle();
});
//get blocks
function setConetntRightLeft() {
 var content_right_right = $("#content_right_right").html();
 if ((content_right_right === undefined) ||
				 (content_right_right === "")) {
	$("#content_right_left").width("100%");
	$("#content_right_right").width("0%");
 } else {
	$("#content_right_left").width("84%");
	$("#content").css("float:left");
	$("#content_right_right").width("12%");
 }

}

function getBlocks() {
 $('#loading').show();
 $('#content_left').html('<img src="' + homePageUrl + 'themes/images/small_loading.gif"> loading...');
 var pathname = window.location.pathname;
 $.ajax({
	url: homePageUrl + 'includes/basics/json.basics.php',
	data: {all_blocks: '1',
	 pathname: pathname},
	type: 'POST'

 }).done(function(data) {
	var header_top = $('#header_top', $(data)).html();
	var header_bottom = $('#header_bottom', $(data)).html();
	var navinagtion_top = $('#navinagtion_top', $(data)).html();
	var navinagtion_bottom = $('#navinagtion_bottom', $(data)).html();
	var content_top = $('#content_top', $(data)).html();
	var content_bottom = $('#content_bottom', $(data)).html();
	var content_left = $('#content_left', $(data)).html();
	var content_right_right = $('#content_right_right', $(data)).html();
	var footer_top = $('#footer_top', $(data)).html();
	var footer_bottom = $('#footer_bottom', $(data)).html();
	$("#header_top").append(header_top);
	$("#header_bottom").append(header_bottom);
	$("#navinagtion_top").append(navinagtion_top);
	$("#navinagtion_bottom").append(navinagtion_bottom);
	$("#content_top").append(content_top);
	$("#content_bottom").append(content_bottom);
	$("#content_left").html(content_left);
	$("#content_right_right").append(content_right_right);
	$("#footer_top").append(footer_top);
	$("#footer_bottom").append(footer_bottom);
	setConetntRightLeft();
	$('#loading').hide();
 }).fail(function() {
//     alert("Block block loading failed");
	$('#loading').hide();
 });
// $(".form_table #subinventory_id").attr("disabled",false);
}

//show Default Dialog Box 
function show_dialog_box() {
 $("#dialog_box").dialog({
	dialogClass: "no-close",
	modal: true,
	minWidth: 600,
	title: "Action Message",
	buttons: [
	 {
		text: "OK",
		click: function() {
		 $(this).dialog("close");
		}
	 }
	],
	closeOnEscape: true,
	position: {my: "left top", at: "left top", of: "#structure "}
 });
}

//get parameter value from window.location - equivalent og $_GET
function getUrlValues(name) {
 name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
 var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
				 results = regex.exec(location.search);
 return results == null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
}

function modepath() {
 var url = '';
 url += getUrlValues('class_name') == null ? '' : 'class_name=' + getUrlValues('class_name') + '&';
 url += getUrlValues('mode') == null ? '' : 'mode=' + getUrlValues('mode') + '&';
 if (url != null) {
	url = '?' + url;
 }
 return url;
}

//select mandatory fields
var Mandatory_Fields = "";
function select_mandatory_fields_all(form_area, Mandatory_Fields) {
 var i = 0;
 if (Mandatory_Fields.length / 2 >= 1) {
	var fieldId = Mandatory_Fields[i];
	var msg = Mandatory_Fields[i + 1];
	$(form_area + " :input").not(fieldId).on("focusin", function() {
	 if ($(fieldId).val().length === 0) {
		alert(msg);
		$(fieldId).focus();
	 }
	});
	$(fieldId).on("change", function() {
	 if ($(fieldId).val().length === 0) {
		alert(msg);
		$(fieldId).focus();
	 }
	 else if (Mandatory_Fields.length >= 2) {
		Mandatory_Fields.splice(0, 2);
		if (Mandatory_Fields.length >= 2) {
		 select_mandatory_fields(Mandatory_Fields);
		}
	 }
	});
 }

}


function select_mandatory_fields(Mandatory_Fields) {
 select_mandatory_fields_all('#content', Mandatory_Fields);
}

function select_mandatory_fields_line(Mandatory_Fields) {
 select_mandatory_fields_all('#form_line', Mandatory_Fields);
}

function remove_row() {
 $("body").on("click", ".remove_row_img", function() {
	trclass = $(this).closest('tr').attr("class");
	newTrclass = trclass.replace(/ /g, '.');
	if (($("tr." + newTrclass).closest('form').find('tbody').first().children().filter('tr').length) > 1) {
	 $("tr." + newTrclass).remove();
	}
 });
}

//add new search criteria
function new_searchCriteria_onClick(json_url) {
 $("#new_search_criteria_add").on("click", function() {
	$('#loading').show();
	var new_search_criteria = $(".new_search_criteria").val();
	$.ajax({
	 url: json_url,
	 data: {new_search_criteria: new_search_criteria},
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#new_search_criteria').html();
	 $("ul.search_form").append(div);
	 $('#loading').hide();
	}).fail(function() {
	 $('#loading').hide();
	});
 });
}

//add a new line on clickint add a new line
//objectCount = 5000;
//dateCount = 10000;
//function add_new_row(trClass, tbodyClass, noOfTabs) {
// var lastLineSeqNumber = $('.lines_number:last').val();
// var nextLineSeqNumber = (+lastLineSeqNumber + 1);
// if (noOfTabs > 1) {
//	var startingTab = $(trClass + ':first').closest('.tabContent').attr('id');
//	var startingTabArray = startingTab.split('-');
//	var startingTabNumber = startingTabArray[1];
//	tabCount = 1;
//	do {
//	 $("#tabsLine-" + startingTabNumber + " " + trClass).clone().attr("id", "new_object" + startingTabNumber + "_" + objectCount).attr("class", "new_object" + objectCount).appendTo($("#tabsLine-" + startingTabNumber + " " + tbodyClass));
//	 startingTabNumber++;
//	 tabCount++;
//	}
//	while (tabCount <= noOfTabs);
// } else {
//	$(trClass).clone().attr("class", "new_object" + objectCount).appendTo($(tbodyClass));
// }
//
// $("tr.new_object" + objectCount).find(".class_detail_form").replaceWith("");
// //remove default values from text, number, select and check box. Hidden values needs to be copied
// $("tr.new_object" + objectCount).find("td input[type=text]").each(function() {
//	$(this).val("");
// });
// $("tr.new_object" + objectCount).find("td input[type=number]").each(function() {
//	$(this).val("");
// });
// $("tr.new_object" + objectCount).find("td select").each(function() {
//	$(this).val("");
// });
//// $("tr.new_object" + objectCount).find("td :input").each(function() {
////	$(this).val("");
//// });
// $("tr.new_object" + objectCount).find(':checkbox').prop('checked', false);
//
// $('.lines_number:last').val(nextLineSeqNumber);
// $(".new_object" + objectCount).find(".date").each(function() {
//	$(this).attr("id", "date" + dateCount);
//	$(this).attr("class", "date");
//	dateCount++;
// });
// objectCount++;
//}
//
////check object file for new vesriosn
//function add_new_row_withDefault(trClass, tbodyClass, noOfTabs, divClassNotToBeCopied) {
// var lastLineSeqNumber = $('.lines_number:last').val();
// var nextLineSeqNumber = (+lastLineSeqNumber + 1);
// var newtrClass = '.' + $("tr[class*='" + trClass + "']:last").first().prop('class');
// if (noOfTabs > 1) {
////	var startingTab = $(trClass + ':first').closest('.tabContent').attr('id');
//	var startingTab = $("tr[class*='" + trClass + "']:first").closest('.tabContent').attr('id');
//	var startingTabArray = startingTab.split('-');
//	var startingTabNumber = startingTabArray[1];
//	tabCount = 1;
//	do {
//	 $("#tabsLine-" + startingTabNumber + " " + newtrClass).clone().attr("id", "new_object" + startingTabNumber + "_" + objectCount).attr("class", "new_object" + objectCount).appendTo($("#tabsLine-" + startingTabNumber + " " + tbodyClass));
//	 //   alert(newtrClass); 
////	 alert(startingTab);
////	 alert($("#tabsLine-" + startingTabNumber + " " + newtrClass).clone().html());
////						 alert($("#tabsLine-" + startingTabNumber + " " + tbodyClass).html());
//	 startingTabNumber++;
//	 tabCount++;
//	}
//	while (tabCount <= noOfTabs);
// } else {
//	$(newtrClass).clone().attr("class", "new_object" + objectCount).appendTo($(tbodyClass));
// }
// $("tr.new_object" + objectCount).find(divClassNotToBeCopied).each(function() {
//	$(this).val("");
// });
// $("tr.new_object" + objectCount).find(".class_detail_form").replaceWith("");
// $('.lines_number:last').val(nextLineSeqNumber);
// $(".new_object" + objectCount).find(".date").each(function() {
//	$(this).attr("id", "date" + dateCount);
//	$(this).attr("class", "date");
//	dateCount++;
// });
// objectCount++;
//}
//add a new line on clickint add a new detail line
detailObjectCount = 3000;
dateCount = 30000;
function onClick_addDetailLine(trClass, tbodyClass, noOfTabs) {
 $("#content").on("click", "table.form_detail_data_table .add_row_detail_img", function() {
	var lastDetailSeqNumber = $('.details_number:last').val();
	var nextDetailSeqNumber = (+lastDetailSeqNumber + 1);
//	var nextDetailSeqNumber = (+lastDetailSeqNumber + 0.1).toFixed(1);
	var closetLineRowClass = $(this).closest(".class_detail_form").closest('tr').attr('class');
	var closetLineRowClass = '.' + closetLineRowClass;
	var tabLink = $(this).closest(".tabContent").attr('id');
	if (noOfTabs > 1) {
	 var n = tabLink.lastIndexOf("-");
	 var primaryTabNumber = tabLink.substring(n);
	}

	if (noOfTabs > 1) {
	 tabCount = 1;
	 do {
		$("#tabsDetail-" + tabCount + "-1 " + trClass).clone().attr("id", "new_object" + detailObjectCount).attr("class", "new_object " + detailObjectCount).appendTo($(closetLineRowClass + " #tabsDetail-" + tabCount + primaryTabNumber + " " + tbodyClass));
		tabCount++;
	 }
	 while (tabCount <= noOfTabs);
	} else {
	 $(trClass + ':first').clone().attr("class", "new_object " + detailObjectCount).appendTo($(closetLineRowClass + ' ' + tbodyClass));
	}

	$("tr.new_object." + detailObjectCount).find("td input[type=text]").each(function() {
	 $(this).val("");
	});
	$("tr.new_object." + detailObjectCount).find("td input[type=number]").each(function() {
	 $(this).val("");
	});
	$("tr.new_object." + detailObjectCount).find("td select").each(function() {
	 $(this).val("");
	});
	$('.details_number:last').val(nextDetailSeqNumber);
	$(".new_object" + detailObjectCount).find(".date").each(function() {
	 $(this).attr("id", "date" + dateCount);
	 $(this).attr("class", "date");
	 dateCount++;
	});
	detailObjectCount++;
 });
}

function onClick_add_new_row(trClass, tbodyClass, noOfTabs, divClassToBeCopied) {
 $("body table.form_table").on("click", ".add_row_img", function() {
//	add_new_row(trClass, tbodyClass, noOfTabs);

	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = trClass;
	addNewRow.tbodyClass = tbodyClass;
	addNewRow.noOfTabs = noOfTabs;
	addNewRow.removeDefault = true;
	addNewRow.divClassToBeCopied = divClassToBeCopied;
	addNewRow.add_new_row();
 });
 return 1;
}
//onClick_add_new_row();
//toggle detail lines if exists else create a new detail line
var objectDetailTabCount = 2;
var detailObjectRowCount = 600;
function addOrShow_lineDetails(trClassToCopy) {
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
	var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
	if (detailExists > 0) {
	 $(this).closest("td").find(".form_detail_data_fs").toggle();
	} else {
//	 var lineNumber = $(this).closest('tr').find('.lines_number').val();
//	 var detailNumber = lineNumber + '.1';
	 var detailNumber = 1;
	 elementToBeCloned = $(trClassToCopy + " .class_detail_form");
	 clonedElement = elementToBeCloned.clone();
	 clonedElement.find(".new_object").remove();
	 $(clonedElement).find('tbody tr').attr("class", "new_object" + detailObjectRowCount);
	 clonedElement.find("input").not('.hidden').each(function() {
		$(this).val("");
	 });
	 clonedElement.appendTo($(this).closest("td"));
	 $(this).closest("td").find("li.tabLink").each(function() {
		var tabLink = $(this).find("a[href]").attr('href');
		var n = tabLink.lastIndexOf("-");
		var newStr = tabLink.substring(0, n);
		var newTabLink = newStr + '-' + objectDetailTabCount;
		$(this).find("a[href]").attr('href', newTabLink);
	 });
	 $(this).closest("td").find(".tabContent").each(function() {
		var tabLink = $(this).attr('id');
		var n = tabLink.lastIndexOf("-");
		var newStr = tabLink.substring(0, n);
		var newTabLink = newStr + '-' + objectDetailTabCount;
		$(this).attr('id', newTabLink);
	 });
	 $(".tabsDetail").tabs();
	 $(this).closest("td").find(".form_detail_data_fs").toggle();
	 $(this).closest("td").find(".detail_number:first").val(detailNumber);
	}
	objectDetailTabCount++;
	detailObjectRowCount++;
 });
}

function deleteLine(json_url, line_id, isDetail) {
 if (isDetail == 1) {
	var deleteType = 'detail';
 } else {
	var deleteType = 'line';
 }
 $.ajax({
	url: json_url,
	data: {
	 delete: '1',
	 line_id: line_id,
	 deleteType: deleteType},
	type: 'get'
 }).done(function(result) {
	if (isDetail == 1) {
	 var div = $(result).filter('div#json_delete_detail').html();
	} else {
	 var div = $(result).filter('div#json_delete_line').html();
	}
	$(".error").append(div);
	$("#delete_button").removeClass("show_loading_small");
	$("#delete_button").prop('disabled', false);
 }).fail(function(error, textStatus, xhr) {
	alert("delete failed \n" + error + textStatus + xhr);
	$("#delete_button").removeClass("show_loading_small");
	$("#delete_button").prop('disabled', false);
 });
}
//used for deleting header forms like content/page/comment
function deleteHeader(json_url, headerId) {
 $("#delete_button").click(function(e) {
	$("#delete_button").addClass("show_loading_small");
	$("#delete_button").prop('disabled', true);
	e.preventDefault();
	if (confirm("Do you really want to delete ?\n" + headerId)) {
	 $.ajax({
		url: json_url,
		data: {
		 header_id: headerId,
		 delete: '1'},
		type: 'get'
	 }).done(function(result) {
		var div = $(result).filter('div#json_delete_header').html();
		$(".error").append(div);
		$("#delete_button").removeClass("show_loading_small");
		$("#delete_button").prop('disabled', false);
	 }).fail(function(error, textStatus, xhr) {
		alert("delete failed \n" + error + textStatus + xhr);
		$("#delete_button").removeClass("show_loading_small");
		$("#delete_button").prop('disabled', false);
	 });
	}
 });
}

function deleteData(json_url) {
 $("#delete_button").click(function(e) {
	$("#delete_button").addClass("show_loading_small");
	$("#delete_button").prop('disabled', true);
	e.preventDefault();
	$('input[name="detail_id_cb"]:checked').each(function() {
	 var detail_id = $(this).val();
	 if (confirm("Are you sure?")) {
		deleteLine(json_url, detail_id, 1);
	 }
	});
	$('input[name="line_id_cb"]:checked').each(function() {
	 var line_id = $(this).val();
	 if (confirm("Are you sure?")) {
		deleteLine(json_url, line_id);
	 }
	});
 });
}

function deleteFile(json_url, file_reference_id) {
 $('.show_loading_small').show();
 $.ajax({
	url: json_url,
	data: {delete: '1',
	 file_reference_id: file_reference_id
	},
	type: 'get'
 }).done(function(result) {
	var div = $(result).filter('div#json_delete_file').html();
	$(".error").append(div);
	$('.show_loading_small').hide();
 }).fail(function() {
	alert("File delete failed");
	$('#loading').hide();
 });
// $(".form_table #subinventory_id").attr("disabled",false);
}

function getAttachmentForm(divId, jsonFileLink) {
 $('#loading').show();
//var org_id = $(".form_table #org_id").val();
 $.ajax({
	url: jsonFileLink,
	type: 'get'
 }).done(function(data) {
	var div = $('#add_attachments', $(data)).html();
	$(divId).append(div);
	$('#loading').hide();
	$('li#loading').hide();
 }).fail(function() {
	alert("Attachment loading failed");
	$('#loading').hide();
 });
}

//get the attachement form
function get_attachment_form(jsonFileLink) {
 $("body").on("click", ".attachment_button", function() {
	var closestDiv = $(this).closest("div").attr("id");
	divId = "#" + closestDiv;
	getAttachmentForm(divId, jsonFileLink);
 });
}

//get default values
//get Supplier details - supplier Sites, addresses etc
function getSupplierDetails(jsonurl, org_id) {
 $('.show_loading_small').show();
 var supplier_id = $("#supplier_id").val();
 $.ajax({
	url: jsonurl,
	data: {supplier_id: supplier_id,
	 org_id: org_id,
	 find_all_sites: 1},
	type: 'get'
 }).done(function(result) {
	var supplier_sites = $(result).find('div#json_supplierSites_find_all').html();
	var supplier_attachment = $(result).find('#supplier_header_level_attachement').html();
	var ship_to_id = $(result).find('#ship_to_id').html();
	var bill_to_id = $(result).find('#bill_to_id').html();
	var ship_to_address = $(result).find('#ship_to_address').html();
	var bill_to_address = $(result).find('#bill_to_address').html();
	var errorMsg = $(result).filter('.errorMsg').html();
	if (supplier_sites.length > 5) {
	 $("#supplier_site_id").replaceWith(supplier_sites);
	}
	if (supplier_attachment.length > 5) {
	 $("#supplier_header_level_attachement").replaceWith(supplier_attachment);
	}
	$("#ship_to_id").val(ship_to_id);
	$("#bill_to_id").val(bill_to_id);
	$("#ship_to_address").val(ship_to_address);
	$("#bill_to_address").val(bill_to_address);
	if (errorMsg !== undefined) {
	 $(".error").append(errorMsg);
	}
	$('.show_loading_small').hide();
 }).fail(function() {
	alert("Supplier Site Loading failed");
	$('.show_loading_small').hide();
 }).always(function() {
	$('.show_loading_small').hide();
 });
 $(".form_table .from_subinventory_id").attr("disabled", false);
}

//get Supplier site details - currency, payment terms, attachements
function getSupplierSiteDetails(jsonUrl, supplier_site_id) {
 $('.show_loading_small').show();
 $.ajax({
	url: jsonUrl,
	data: {supplier_site_id: supplier_site_id,
	 find_site_details: 1},
	type: 'get'
 }).done(function(result) {
	var div = $(result).filter('div#json_supplier_site_details').html();
	var supplier_site_currency = $(result).find('div#json_supplier_site_currency').html();
	var supplier_site_payment_terms = $(result).find('div#json_supplier_site_payment_terms').html();
	var errorMsg = $(div).filter('.errorMsg').html();
	$("#payment_term_id").replaceWith(supplier_site_payment_terms);
	$("#currency").replaceWith(supplier_site_currency);
	if (errorMsg !== undefined) {
	 $(".error").append(errorMsg);
	}
	$('.show_loading_small').hide();
 }).fail(function() {
	alert("Supplier Site Loading failed");
	$('.show_loading_small').hide();
 });
 $(".form_table .from_subinventory_id").attr("disabled", false);
}

//get Subinventories
function getSubInventory(json_url, org_id) {
 $('#loading').show();
 $.ajax({
	url: json_url,
	data: {org_id: org_id,
	 find_all_subinventory: 1},
	type: 'get'
 }).done(function(result) {
	var div = $(result).filter('div#json_subinventory_find_all').html();
	$(".subinventory_id").append(div);
	$('#loading').hide();
 }).fail(function() {
	alert("org name loading failed");
	$('#loading').hide();
 });
 $(".form_table .from_subinventory_id").attr("disabled", false);
}

//get locator name
function getLocator(json_url, subinventory_id, subinventory_type, trClass) {
 $('#loading').show();
 $.ajax({
	url: json_url,
	data: {subinventory_id: subinventory_id,
	 find_all_locator: 1},
	type: 'get'
 }).done(function(result) {
//   var div = $('#json_locator', $(data)).html();
	var div = $(result).filter('div#json_locator_find_all').html();
	if (subinventory_type == "from_subinventory_id") {
	 $(trClass + " .from_locator_id").find('option').remove();
	 $(trClass + " .from_locator_id").append(div);
	}
	if (subinventory_type == "to_subinventory_id") {
	 $(trClass + " .to_locator_id").find('option').remove();
	 $(trClass + " .to_locator_id").append(div);
	}
	if (subinventory_type == "subinventory") {
	 $(trClass).find(".locator_id").find('option').remove();
	 $(trClass).find(".locator_id").append(div);
	}

	if (subinventory_type == "oneSubinventory") {
	 $('#content').find(".locator_id").find('option').remove();
	 $('#content').find(".locator_id").append(div);
	}

	$('#loading').hide();
 }).fail(function() {
	alert("Locator name loading failed");
	$('#loading').hide();
 });
 $(".form_table .from_locator_id").attr("disabled", false);
}

//fetch all the accounts from inventory details
function getAllInventoryAccounts(jsonUrl, ship_to_inventory, classValue) {
 $('.show_loading_small').show();
 $.ajax({
	url: jsonUrl,
	data: {ship_to_inventory: ship_to_inventory,
	 find_account_details: 1},
	type: 'get'
 }).done(function(result) {
	var div = $(result).filter('div#json_inventory_ac_all').html();
	var inv_ap_accrual_ac_id = $(result).find('div#json_ap_accrual_ac_id').html();
	var material_ac_id = $(result).find('div#json_material_ac_id').html();
	var inv_ppv_ac_id = $(result).find('div#json_inv_ppv_ac_id').html();
	$(classValue).closest('.tabContainer').find(classValue).find('.charge_ac_id').val(material_ac_id);
	$(classValue).closest('.tabContainer').find(classValue).find('.accrual_ac_id').val(inv_ap_accrual_ac_id);
	$(classValue).closest('.tabContainer').find(classValue).find('.ppv_ac_id').val(inv_ppv_ac_id);
	$('.show_loading_small').hide();
 }).fail(function() {
	alert("Supplier Site Loading failed");
	$('#loading').hide();
 });
 $(".form_table .from_subinventory_id").attr("disabled", false);
}
//end of get default values

//end of global functions
$(document).ready(function() {

 $('#loading').hide();
 $('.show_loading_small').hide();
//hiding the loader
 var $loader = $('#loading'), timer;
 $loader.hide().ajaxStart(function()
 {
	timer && clearTimeout(timer);
	timer = setTimeout(function()
	{
	 $loader.show();
	},
					10000);
 }).ajaxStop(function()
 {
	clearTimeout(timer);
	$loader.hide();
 });

//select page data selction in parent window
 $(".quick_select").click(function() {
	var setData = new opener.setValFromSelectPage;
	$(this).closest('tr').find('td').each(function() {
	 setData[$(this).prop('class')] = $(this).text();
	});
	setData.setVal();
	localStorage.removeItem("reset_link");
	window.close();
 });

 //search reset button
 var link = localStorage.getItem("reset_link");
 if (link) {
	$('#multi_select a#search_reset_btn').on('click', function() {
	 $(this).attr('href', link);
	});
 }

 var reset_link_ofSelect = localStorage.getItem("reset_link_ofSelect");
 if (reset_link_ofSelect) {
	$('#select_page a#search_reset_btn').on('click', function() {
	 $(this).attr('href', reset_link_ofSelect);
	});
 }

 //Coa auto complete
 var coaCombination = new autoCompleteMain();
// var coa_id = $('#coa_id').val();
 coaCombination.json_url = 'modules/gl/coa_combination/coa_search.php';
 coaCombination.primary_column1 = 'coa_id';
 coaCombination.select_class = 'select_account';
 coaCombination.min_length = 4;
 coaCombination.autoComplete();

 var supplierName = new autoCompleteMain();
 supplierName.json_url = 'modules/ap/supplier/json_supplier.php';
 supplierName.primary_column1 = 'bu_org_id';
 supplierName.select_class = 'select_supplier_name';
 supplierName.extra_elements = ['supplier_id', 'supplier_number'];
 supplierName.min_length = 3;
 supplierName.autoComplete();

 var itemNumber = new autoCompleteMain();
 itemNumber.json_url = 'modules/inv/item/item_search.php';
 itemNumber.select_class = 'select_item_number';
 itemNumber.extra_elements = ['item_id', 'item_description', 'uom_id'];
 itemNumber.min_length = 2;
 itemNumber.autoComplete();

 //toggle sereah form
 $('#searchForm').on('dblclick', function() {
	$(this).find('.search_form').toggle();
 });
 //add new columns
 $('#content').on('change', '.new_column:first', function() {
	if ($(this).val()) {
	 $(this).clone().insertBefore($(this));
	}
 });
 //add new order by
 $('#content').on('change', '.search_order_by', function() {
	if ($(this).val() !== 'remove') {
	 $(this).closest('li').clone().insertAfter($(this).closest('li'));
	} else {
	 $(this).closest('li').remove();
	}
 });

 $('#searchForm').on('change', '.new_search_criteria', function() {
	if ($(this).val()) {
	 var newSearchCriteria = $(this).val();
	 var elementToBeCloned = $('.text_search').first().closest('li');
	 var elementClass = $('.text_search').first().prop('class');
	 var elementName = $('.text_search').first().prop('name');
	 var elementLabelClass = '.label_' + elementName;
	 clonedElement = elementToBeCloned.clone();
	 $('label[for="' + elementName + '"]').text(newSearchCriteria);
	 clonedElement.children().removeClass(elementClass);
	 clonedElement.children().addClass(newSearchCriteria);
	 clonedElement.children().prop('name', newSearchCriteria);
	 clonedElement.find("input").each(function() {
		$(this).val("");
	 });
//	 clonedElement.appendTo($(this).closest("ul"));
	 clonedElement.insertBefore($(this).closest("li"));
	 $(elementLabelClass + ':last').text(newSearchCriteria);
	}
 });

//get the new search criteria
// var json_url = homePageUrl + 'include/basics/json.basics.php';
// new_searchCriteria_onClick(json_url);
 //toggle detail lines
 $(".form_detail_data_fs").hide();
 $(".error").dblclick(function() {
	$(this).html("");
 });
 //export to excel from search result
 $("#content").on('click', '#export_excel_searchResult', function(e) {
	window.open('data:application/vnd.ms-excel,' + encodeURIComponent($('#search_result').html()));
	e.preventDefault();
 });
//remove row
 remove_row();

 //remove attached files
 $('#content').on('click', '.remove_file', function() {
	$(this).closest('ul').remove();
 });
 //date picker
 $('body').on('focus', ".date", function() {
	var currentDate = new Date();
	$(this).datepicker({
	 defaultDate: 0,
	 changeMonth: true,
	 changeYear: true,
	 dateFormat: "yy-mm-dd",
	 setDate: currentDate
	});
 });
 $('body').on('focus', ".anyDate", function() {
	var currentDate = new Date();
	$(this).datepicker({
	 defaultDate: 0,
	 changeMonth: true,
	 changeYear: true,
	 dateFormat: "yy-mm-dd",
	 setDate: currentDate
	});
 });
 $('body').on('focus', ".dateFromToday", function() {
	var currentDate = new Date();
	$(this).datepicker({
	 defaultDate: 0,
	 minDate: 0,
	 changeMonth: true,
	 changeYear: true,
	 dateFormat: "yy-mm-dd",
	 setDate: currentDate
	});
 });
 //dont allow past dates if manually entered
 $('body').on('change', '.dateFromToday', function() {
	var toDay = new Date();
	var enteredDate = $(this).datepicker("getDate");
	if ((enteredDate) && (enteredDate < toDay)) {
	 $(this).val('');
	 $(this).focus();
	 alert("Cant enter any past date");
	}
 });
 //creating tabs
 $("#tabs").tabs();
 //creating tabs
 $(function() {
	var tabs = $("#tabsHeader").tabs();
	var tabs = $("#tabsLine").tabs();
	tabs.find(".ui-tabs-nav").sortable({
	 axis: "x",
	 stop: function() {
		tabs.tabs("refresh");
	 }
	});
 });
// $("#tabsHeader").tabs();
// $("#tabsLine").tabs();
 $("#tabsDetail").tabs();
 $(".tabsDetail").tabs();
//Refresh the page
 $("#refresh_button").on("click", function() {
	location.reload(true);
 });
//setConetntRightLeft();
 getBlocks();
 tinymce.init({
	selector: '.mediumtext',
	mode: "exact",
//    theme: "modern",
	plugins: 'textcolor link image lists code table emoticons',
	width: 680,
	height: 70,
	toolbar: "styleselect code | emoticons forecolor backcolor bold italic pagebreak | alignleft aligncenter alignright | bullist numlist outdent indent | link image inserttable ",
	menubar: false,
	statusbar: false,
	file_browser_callback: function() {
	 $('#attachment_button').click();
	}
 });

 tinymce.init({
	selector: '.bigtext',
	mode: "exact",
//    theme: "modern",
	plugins: 'textcolor link image lists code table emoticons',
	width: 700,
	height: 250,
	toolbar: "styleselect code | emoticons forecolor backcolor bold italic pagebreak | alignleft aligncenter alignright | bullist numlist outdent indent | link image inserttable ",
	menubar: false,
	statusbar: false,
	file_browser_callback: function() {
	 $('#attachment_button').click();
	}
 });
 //include tinymce for all text areas
 tinymce.init({
//  selector:'textarea',
	mode: "exact",
	theme: "modern",
	width: 200,
	height: 30,
	toolbar: false,
	menubar: "format edit",
	statusbar: false
 });

 //Popup for selecting legal name
 $(".select.popup").click(function() {
	event.preventDefault();
	void window.open($(this).attr('href'), '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });


 //basic finction --making background colors for form fields
 $("input").focus(function() {
	$(this).css("background-color", "#cccccc");
 });
 $("input").blur(function() {
	$(this).css("background-color", "#ffffff");
 });
 $(" :required").css("background-color", "pink");
 $("[readonly]").css("background-color", "#ddd");
// $("select:required").css("background-color", "pink");
// $("input:required").focus(function() {
//	$(this).css("background-color", "pink");
// });
 $("input:required").blur(function() {
	$(this).css("background-color", "pink");
 });
 //Popup for print
 $(".print").click(function() {
	window.print();
 });
 //all download
 $('#export_excel_allResult').on('click', function() {
	$('#download_all').submit();
 });

 show_dialog_box();
 //shortcut keys
 $(document).bind('keydown', 'alt+r', function(e) {
	e.preventDefault();
	$("#refresh_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+o', function(e) {
	e.preventDefault();
	$("#new_object_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+n', function(e) {
	e.preventDefault();
	$(".add_row_img").trigger("click").one();
 });
 $(document).bind('keydown', 'alt+s', function(e) {
	e.preventDefault();
	$("#save").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+d', function(e) {
	e.preventDefault();
	$("#delete_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+m', function(e) {
	e.preventDefault();
	$("#remove_row_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+t', function(e) {
	e.preventDefault();
	$("#reset_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+b', function(e) {
	e.preventDefault();
	$("#go_back_button").first().trigger('click');
 });
});









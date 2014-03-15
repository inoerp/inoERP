$(document).ready(function() {
 //creating tabs
 $(function() {
	$("#tabsHeader").tabs();
	$("#tabsLine").tabs();
 });


//query mode for item
 $("#item_id").bind('keydown', 'Ctrl+q', function() {
	$(this).attr('readonly', false);
	getAllOrgName();
 });

 //copy Item
 $('#content').on('click', '#copy_docHeader', function() {
	$('#item_id').val('');
	$('#item_number').val('');
	$('#item_description').val('');
	$('#org_id').val('');
	alert('Item copied \nSelect Org, Enter Item Number & Description \nMaky any other necessary changes & Save the record!')
 });

//Show the org name after the item_id is selected
 $("#org_id.getOrgName").blur(function() {
	getOrgName();
 });

//ajax for uom - unit of measures
 $('#uom').autocomplete({source: '../uom/uom_search.php', minLength: 2});

//ajax for accounts
 $('#material_ac').autocomplete({
	source: '../../gl/coa_combination/coa_search.php',
	minLength: 2});

 $('#material_oh_ac').autocomplete({
	source: '../../gl/coa_combination/coa_search.php',
	minLength: 2});

 $('#overhead_ac').autocomplete({
	source: '../../gl/coa_combination/coa_search.php',
	minLength: 2});

 $('#resource_ac').autocomplete({
	source: '../../gl/coa_combination/coa_search.php',
	minLength: 2});

 $('#expense_ac').autocomplete({
	source: '../../gl/coa_combination/coa_search.php',
	minLength: 2});

 $('#osp_ac').autocomplete({
	source: '../../gl/coa_combination/coa_search.php',
	minLength: 2});

 $('#sales_ac').autocomplete({
	source: '../../gl/coa_combination/coa_search.php',
	minLength: 2});

//item number jquery
 $('#item_number').autocomplete({source: 'item_search.php', minLength: 2});

//selecting item

 $(".item_id_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('find_item.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

// function setParnetWindowValues(itemId, itemNumber, itemDescription, orgId)
// {
//	if ((typeof localStorage.idValue !== 'undefined') && (localStorage.idValue.length > 0)) {
//	 var RowDivId = 'tr#' + localStorage.idValue;
//	 window.opener.$(RowDivId).find(".item_id").val(itemId);
//	 window.opener.$(RowDivId).find(".item_number").val(itemNumber);
//	 window.opener.$(RowDivId).find(".item_description").val(itemDescription);
//	 window.opener.$(RowDivId).find(".org_id").val(orgId);
//	} else {
//	 window.opener.$(".item_id").val(itemId);
//	 window.opener.$(".item_number").val(itemNumber);
//	 window.opener.$(".item_description").val(itemDescription);
//	 window.opener.$(".org_id").val(orgId);
//	}
// }
//
// $(".quick_select").on("click", function() {
//	var itemId = $(this).val();
//	var itemNumber = $(this).closest("td").siblings("td.item_number").html();
//	var itemDescription = $(this).closest("td").siblings("td.item_description").html();
//	var orgId = $(this).closest("td").siblings("td.org_id").html();
//	setParnetWindowValues(itemId, itemNumber, itemDescription, orgId);
//	window.close();
// });


//Get the item_id on refresh button click
 $('a.show.item_id').click(function() {
	var item_id = $('#item_id').val();
	$(this).attr('href', '?item_id=' + item_id);

 });

 $('a.show.item_number').click(function() {
	var item_number = $('#item_number').val();
	if ($('#org_id').val().length > 0) {
	 var org_id = $('#org_id').val();
	 $(this).attr('href', '?item_number=' + item_number + '&org_id=' + org_id);
	} else {
	 alert("Query Error!!! \n Select the query mode by pressing Ctrl + Q \n Select the organization name");
	}


 });
 
  //get locatot on Subinventory change
 $('#content').on('change','.wip_supply_subinventory', function(){
var subInventoryId = $(this).val();
if(subInventoryId > 0){
getLocator('../locator/json.locator.php', subInventoryId, 'oneSubinventory', '');
}

})
//

//Get the item id on fly after clicking the submit header
//enables the account field
//  $('#item #submit_header').click(function() {
//    var itemId = $('#item_id').val();
//    $('#item_id').attr('action', 'item.php?item_id=' + itemId);
//    
//  });

//script for item_segment_values.php
//change the save & delete button values
 onClick_add_new_row('tr.item0', 'tbody.item_values', 3);

//Save record
// save('json.item.php', '#item', '', 'item', '#item_id', '');

//delete line
 deleteData('json.item.php');

});

$(document).ready(function() {
  var Mandatory_Fields = ["#org_id", "First Select Inventory", "#wip_class", "First Select AC Class"];
 select_mandatory_fields_all('#wip_wo_divId',Mandatory_Fields);
 
 //dont allow line entry with out bom_header id
  $('#form_line').on("click", function() {
	if (!$('#wip_wo_header_id').val()) {
	 alert('No header Id : First enter/save header details');
	} else {
	 var headerIdValue = $('#wip_wo_header_id').val();
	 if (!$(this).find('.wip_wo_header_id').val()) {
		$(this).find('.wip_wo_header_id').val(headerIdValue);
	 }
	}
 });
 
//Required Resource Quantity
$('body').on('focusout','.usage', function(){
var usageValue = $(this).val();
var quantity = $("#quantity").val();
var trClass = '.' + $(this).closest('tr').attr('class');
var newtrClass = trClass.split(' ').join('.');
var RequiredQuanity = usageValue * quantity;
$(this).closest('.tabContainer').find(newtrClass).find('.required_quantity').val(RequiredQuanity);
});

//Required BOM Quantity
$('body').on('focusout','.usage_quantity', function(){
var usageValue = $(this).val();
var quantity = $("#quantity").val();
var trClass = '.' + $(this).closest('tr').attr('class');
var newtrClass = trClass.split(' ').join('.');
var RequiredQuanity = usageValue * quantity;
$(this).closest('.tabContainer').find(newtrClass).find('.required_quantity').val(RequiredQuanity);
});

 //selecting data
 $(".wip_wo_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('find_wip_wo.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 function setParnetWindowValues(wip_wo_header_id, wo_number, item_id, orgId)
 {
	if ((typeof localStorage.idValue !== 'undefined') && (localStorage.idValue.length > 0)) {
	 var RowDivId = 'tr#' + localStorage.idValue;
	 window.opener.$(RowDivId).find(".wip_wo_header_id").val(wip_wo_header_id);
	 window.opener.$(RowDivId).find(".wo_number").val(wo_number);
	 window.opener.$(RowDivId).find(".item_id").val(item_id);
	 window.opener.$(RowDivId).find(".org_id").val(orgId);
	} else {
	 window.opener.$(".wip_wo_header_id").val(wip_wo_header_id);
	 window.opener.$(".wo_number").val(wo_number);
	 window.opener.$(".item_id").val(item_id);
	 window.opener.$(".org_id").val(orgId);
	}
 }

 $(".quick_select").on("click", function() {
	var wip_wo_header_id = $(this).val();
	var wo_number = $(this).closest("td").siblings("td.wo_number").html();
	var orgId = $(this).closest("td").siblings("td.org_id").html();
	var item_id = $(this).closest("td").siblings("td.item_id").html();
		setParnetWindowValues(wip_wo_header_id, wo_number, item_id, orgId);
	window.close();
 });
 
  //get locatot on Subinventory change in form header
 $('#form_header').on('change','.sub_inventory', function(){
var subInventoryId = $(this).val();
if(subInventoryId > 0){
getLocator('../../inv/locator/json.locator.php', subInventoryId, 'oneSubinventory', '');
}
});

 //get locatot on Subinventory change in form line
 $('#form_line').on('change','.sub_inventory', function(){
var subInventoryId = $(this).val();
if(subInventoryId > 0){
var trClass = '.'+$(this).closest('tr').attr('class');
getLocator('../../inv/locator/json.locator.php', subInventoryId, 'subinventory', trClass);
}
});

//add or show linw details
 addOrShow_lineDetails('tr.wip_wo_routing0');
 
 //add new lines
 $("#content tbody.wip_wo_bom_values").on("click", ".add_row_img", function() {
	add_new_row('tr.wip_wo_bom0', 'tbody.wip_wo_bom_values', 2);
 });

 $("#content tbody.wip_wo_routing_line_values").on("click", ".add_row_img", function() {
	add_new_row('tr.wip_wo_routing0', 'tbody.wip_wo_routing_line_values', 2);
 });

 onClick_addDetailLine('tr.wip_wo_routing_detail0-0', 'tbody.form_data_detail_tbody', 2);
 
 //Get the wip_wo_id on refresh button click
 $('a.show.wip_wo_id_show').click(function() {
	var wip_wo_header_id = $('#wip_wo_header_id').val();
	$(this).attr('href', '?wip_wo_header_id=' + wip_wo_header_id);
 });
 
 //auto complete
itemNumber_autoComplete('../../inv/item/item_search.php');

 //right click menu
 var menuContent = "<div><ul>";
 menuContent += "<li id='menu_button1'>Export Resource Assigment</li>";
 menuContent += "<li id='menu_button2'>Export Rate Assigment</li>";
 menuContent += "<li id='menu_button3'>Copy Line</li>";
 menuContent += "<div><ul>";

//rightClickMenu(menuContent);


 $("#content").on('click', '#menu_button1', function() {
	exportToExcel_fromDivId('#wip_wo_resource_assignment_line', 3);
 });

 $("#content").on('click', '#menu_button2', function() {
	exportToExcel_fromDivId('#wip_wo_rate_assignment_line', 3);
 });
 
 //Save record
 save('json.wip_wo.php', '#wip_wo_header', 'line_id_cb', 'routing_sequence', '#wip_wo_header_id', '','#wo_number');
 

//delete line
 deleteData('json.wip_wo.php');

});



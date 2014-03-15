$(document).ready(function() {
//Make subinevntory locator changes after selcting transaction type
//  var Mandatory_Fields = ["#org_id", "First Select Inventory", "#overhead", "First enter overhead"];
// select_mandatory_fields_all('#wip_wo_divId',Mandatory_Fields);
// 
// //dont allow line entry with out bom_header id
//  $('#form_line').on("click", function() {
//	if (!$('#wip_wo_id').val()) {
//	 alert('No header Id : First enter/save header details');
//	} else {
//	 var headerIdValue = $('#wip_wo_id').val();
//	 if (!$(this).find('.wip_wo_id').val()) {
//		$(this).find('.wip_wo_id').val(headerIdValue);
//	 }
//	}
// });

$('#content').on('focusout','#to_operation_step', function(){
if(($('#to_operation_step').val()==$('#from_operation_step')) && ($('#to_routing_sequence').val()== $('#to_routing_sequence').val())){
$('#to_routing_sequence').val('');
alert('Invalid Operation! - Source & Destination should be different.');
}
});

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

//validation of entered quantity
$('#content').on('focusout','#from_operation_step', function(){
var fromStep = '.'+$(this).val()+'_quantity';
var fromSeq = $('#from_routing_sequence').val();
var rowClass='';
$('.routing_sequence').each(function(){
if($(this).val() == fromSeq){
rowClass = '.'+$(this).closest('tr').attr('class');
}
});
var availableQuantity = $(rowClass).find(fromStep).val();
if(availableQuantity){
$('#available_quantity').val(availableQuantity);
}else{
$('#available_quantity').val('0')
alert('Error!! : No available quantity to move!');
}
});

$("#content").on('focusout','#move_quantity', function(){
if(+($(this).val()) > +($('#available_quantity')).val()){
$(this).val('');
alert('Error!! : Entered move quantity is more than available quantity');
}else if(($(this).val()) <0 ){
alert('Error!! : Entered more than zero quantity');
}
});
 
//ajax for char of account combinations
 $('.account').autocomplete({source: '../../gl/coa_combination/coa_search.php', minLength: 2});

itemNumber_autoComplete('../item/item_search.php');

 //selecting wo header id data
 $(".wip_wo_headerid_popup").on("click", function() {
	localStorage.idValue = "";
	var link = '../wip_wo/find_wip_wo_released.php?wo_status=RELEASED';
	void window.open(link, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
 //Get the primary_id on refresh button click
 $('a.show.wip_wo_headerid_show').click(function() {
	var wip_wo_header_id = $('#wip_wo_header_id').val();
	$(this).attr('href', '?wip_wo_header_id=' + wip_wo_header_id);

 });
 
//add new line
 onClick_add_new_row('tr.wip_resource_transaction_row0', 'tbody.wip_resource_transaction_values', 4);
//$("#wip_resource_transaction").on(function(){
// itemNumber_autoComplete();
//}).one();
//Save record
  save('json.wip_resource_transaction.php', '#wip_resource_transaction', 'line_id_cb', 'wip_wo_routing_detail_id', '#wip_resource_transaction_id', '');
 
//delete line
 deleteData('json.wip_resource_transaction.php');


});


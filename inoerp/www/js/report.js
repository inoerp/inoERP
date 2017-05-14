////get Subinventories
//function getSubInventory(json_url, org_id) {
// $('#loading').show();
// $.ajax({
//	url: json_url,
//	data: {org_id: org_id,
//	 find_all_subinventory: 1},
//	type: 'get',
//	beforeSend: function() {
//	 $('.show_loading_small').show();
//	},
//	complete: function() {
//	 $('.show_loading_small').hide();
//	}
// }).done(function(result) {
//	var div = $(result).filter('div#json_subinventory_find_all').html();
//	$(".subinventory_id").empty().append(div);
//	return div;
// }).fail(function() {
//	alert("org name loading failed");
// }).always(function() {
//	$('#loading').hide();
// });
// $(".form_table .from_subinventory_id").attr("disabled", false);
//}


//end of global functions
$(document).ready(function() {

});









$(document).ready(function() {
 
//add a new line on clickint add a new line
 function add_new_row() {
	$(".add_row_img").on("click", function() {
	 var objectCount = 1000;
	 $("#tabsHeader-1 tr.subinventory0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-1 tbody.subinventory_values"));
	 $("#tabsHeader-2 tr.subinventory0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-2 tbody.subinventory_values"));
	 $("#tabsHeader-3 tr.subinventory0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-3 tbody.subinventory_values"));
	 $("#new_object" + objectCount + " .subinventory_id").val("");
	 objectCount++;
	 remove_row();
	});
 }
 add_new_row();
 
 var objectCount = 100;
 $("#add_object").on("click", function() {
	$("#tabsHeader-1 tr.subinventory_values0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-1 tbody.subinventory_values"));
	$("#tabsHeader-2 tr.subinventory_values0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-2 tbody.subinventory_values"));
	$("#tabsHeader-3 tr.subinventory_values0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-3 tbody.subinventory_values"));
	$("#new_object" + objectCount + " .subinventory_id").val("");
	objectCount++;
	remove_row();
 }
 );

//add new line by using + sign    




 save('json.subinventory.php', '#subinventory', '', 'subinventory', '#subinventory_id');

//delete line
 function deleteLine(json_url, line_id) {
	$.ajax({
	 url: json_url,
	 data: {delete: '1',
		line_id: line_id},
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#json_delete_line').html();
	 $(".error").append(div);
	 $("#delete_button").removeClass("show_loading_small");
	 $("#delete_button").prop('disabled', false);
	}).fail(function(error, textStatus, xhr) {
	 alert("delete failed \n" + error + textStatus + xhr);
	 $("#delete_button").removeClass("show_loading_small");
	 $("#delete_button").prop('disabled', false);
	});
 }

 function deleteData(json_url) {
	$("#delete_button").click(function(e) {
	 $("#delete_button").addClass("show_loading_small");
	 $("#delete_button").prop('disabled', true);
	 e.preventDefault();

	 $('input[name="line_id_cb"]:checked').each(function() {
		var line_id = $(this).val();
		if (confirm("Are you sure?")) {
		 deleteLine(json_url, line_id);
		}
	 });
	});
 }

 deleteData('json.subinventory.php');


});

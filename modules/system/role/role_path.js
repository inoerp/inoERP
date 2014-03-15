$(document).ready(function() {
 $('#loading').hide();

 //Refresh the content
 $('.refresh').click(function() {
	location.reload(true);
 });

 //Get the path_id on find button click
 $('#form_header a.show').click(function() {
	var role_id = $('#role_id').val();
	$(this).attr('href', 'role_path.php?role_id=' + role_id);
 });

//add a new line
 function remove_line() {
	$(".remove_row_img").on("click", function() {
	 $(this).closest('tr').remove();
	});
 }
 objectCount = 5000;
 function click_add_new_line_row() {
	$("table#form_data_table .add_row_img").on("click", function(e) {
	 $("table#form_data_table tr.option_line_tr0").clone().one().attr("class", "new_object" + objectCount).attr("id", "new_object" + objectCount).appendTo($("table#form_data_table tbody#form_data_line_tbody"));
	 $("tr.new_object" + objectCount).find("td input[type=text]").each(function() {
		$(this).val("");
	 });
	 $("#new_object" + objectCount + " .option_line_id").focus();
	 objectCount++;
	 remove_line();
	 click_add_new_line_row();
	});
 }

 click_add_new_line_row();

//get the new search criteria
 $("#new_search_criteria_add").click(function() {
	$('#loading').show();
	var new_search_criteria = $(".new_search_criteria").val();
	$.ajax({
	 url: 'json.option.php',
	 data: {new_search_criteria: new_search_criteria},
	 type: 'get'
	}).done(function(result) {
	 //      var div = $('#new_search_criteria', $(result)).html();
	 var div = $(result).filter('div#new_search_criteria').html();
	 $("ul.search_form").append(div);
	 $('#loading').hide();
	}).fail(function() {
//     alert("org name loading failed");
	 $('#loading').hide();
	});
 });


//remove option lines
 $("#remove_row").click(function() {
	$('input[name="option_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//delete option lines
 $("#delete_button").click(function(e) {
	$("#delete_button").addClass("show_loading_small");
	$("#delete_button").prop('disabled', true);
	e.preventDefault();
	$('input[name="role_path_id_cb"]:checked').each(function() {
	 var line_id = $(this).val();
	 if (confirm("Are you sure?")) {
		deleteLine(line_id);
		(line_id);
	 }
	});
 });

 function deleteLine(line_id) {
		$.ajax({
	 url: 'json.role_path.php',
	 data: {delete: '1',
		line_id: line_id},
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#json_delete_line').html();
	 $(".error").append(div);
	 	}).fail(function(error, textStatus, xhr) {
	 alert("delete failed \n" + error + textStatus + xhr);
	 	});
	 $("#delete_button").removeClass("show_loading_small");
	 $("#delete_button").prop('disabled', false);
 }

//save option line & header
 function saveOptionHeader(option_header) {
	$.ajax({
	 url: 'json.option.php',
	 data: {option_header: option_header},
	 type: 'post'
	}).done(function(result) {
	 var div = $(result).filter('div#json_save_option_header').html();
	 var option_header_id = $(div).filter('div#option_headerId').html();
	 $(".error").append(div);
	 $("#option_header_id").val(option_header_id);
	 $("#save").removeClass("show_loading_small");
	 $("#save").prop('disabled', false);
	}).fail(function(error, textStatus, xhr) {
	 alert("save failed \n" + error + textStatus + xhr);
	 $("#save").removeClass("show_loading_small");
	 $("#save").prop('disabled', false);
	});
 }

 function saveLine(lineData, trclass) {
	var role_id = $("#role_id").val();
	$.ajax({
	 url: 'json.role_path.php',
	 data: {save_line: '1',
		lineData: lineData,
		role_id: role_id},
	 type: 'post'
	}).done(function(result) {
	 var div = $(result).filter('div#json_save_option_line').html();
	 var option_line_id = $(div).filter('.option_lineId').html();
	 $('#form_data_table tbody tr' + '.' + trclass).find(".option_line_id").val(option_line_id);
	 $(".error").append(div);
	}).fail(function(error, textStatus, xhr) {
	 alert("save failed \n" + error + textStatus + xhr);
	});
	$("#save").removeClass("show_loading_small");
	$("#save").prop('disabled', false);
 }

 $("#save").on('click', function(e) {
	$("#save").addClass("show_loading_small");
	$("#save").prop('disabled', true);
	e.preventDefault();

	if ($('#form_data_table :checkbox:checked').length > 0) {
	 $('input[name="role_path_id_cb"]:checked').each(function() {
		var lineData = $(this).closest("tr").find(":input").serializeArray();
		var trclass = $(this).closest("tr").attr('class');
		saveLine(lineData, trclass);
	 });
	}
	else if ($(".path_id").val().length > 0) {
	 $("tbody#form_data_line_tbody > tr").each(function() {
		var lineData = $(this).find(":input").serializeArray();
		var trclass = $(this).attr('class');
		saveLine(lineData, trclass);
	 });
	}
 });


});


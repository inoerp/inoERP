$(document).ready(function() {
 //Popup for selecting option type
 $(".popup").click(function() {
	void window.open('find_option.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 function parentWindow(findElement)
 {
	$(window.opener.document).find("#option_header_id").val(findElement);
	$('#form_box a.show').prop('href', 'option.php?option_header_id=' + findElement);
 }

 $("#selected").click(function() {
	var findElement = $(".select_option_header_id:checked").val();
	parentWindow(findElement);
	window.close();
 });
 
  $(".quick_select").click(function() {
    var findElement = $(this).val();
	parentWindow(findElement);
	window.close();
  });
	
//get the new search criteria
//$("#new_search_criteria_add").click(function(){
//  $('#loading').show();
//var new_search_criteria = $(".new_search_criteria").val();
//$.ajax({
//     url:'json.option.php' ,
//     data : { new_search_criteria : new_search_criteria},
//     type: 'get'
//     }).done(function(result){
//			//      var div = $('#new_search_criteria', $(result)).html();
//			var div = $(result).filter('div#new_search_criteria').html();
//			  $("ul.search_form").append(div);       
//        $('#loading').hide();
//      }).fail(function(){
////     alert("org name loading failed");
//     $('#loading').hide();
//     });
//});


//toggle detail lines
// $(".form_detail_data_fs").hide();
//
// function toggle_detail_value() {
//	$(".add_detail_values_img").on("click", function() {
//	 $(this).closest("td").find(".form_detail_data_fs").toggle();
//	});
// }
//
// toggle_detail_value();
 
 //add or show linw details
 addOrShow_lineDetails('tr.option_line0');
 
 //Check the option_id while entering the option line code
 function copy_option_header_id() {
	$(".option_line_code").blur(function()
	{
	 if ($("#option_header_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".option_line_code").val("");
	 } else {
		$(".option_header_id").val($("#option_header_id").val());
	 }
	});
 }

 copy_option_header_id();

 //Get the option_id on find button click
 $('#form_box a.show').click(function() {
	var optionId = $('#option_header_id').val();
//$(this).prop('href','option.php?option_header_id=' + optionId);
	$(this).attr('href', 'option.php?option_header_id=' + optionId);
 });

////Get the option id on fly after clicking the submit header
// $('#submit_header').click(function() {
//	var optionId = $('#option_header_id').val();
//	$('#option_header').attr('action', 'option.php?option_header_id=' + optionId);
// });
//
////Get the option id on fly after clicking the submit line
// $('#submit_line').click(function() {
//	var optionId = $('#option_header_id').val();
//	$('#option_line').attr('action', 'option.php?option_header_id=' + optionId);
// });

//copy line & detail field
//function remove_option() {
//$("#content").on("click",".remove_row_img", function() {
// $(this).closest('tr').remove();
//});
//}

//objectDetailCount = 10;
//dateDetailCount = 1000;
//function click_add_new_detail_row() {
//$("#content").on("click", "table.form_detail_data_table .add_row_detail_img", function() {
// $(this).closest("tr").clone().one().attr("class", "new_object" + objectDetailCount).attr("id", "new_object" + objectDetailCount).appendTo($(this).closest("tbody"));
// $("tr.new_object" + objectDetailCount).find("td input[type=text]").each(function() {
//	$(this).val("");
// });
// $(".new_object" + objectDetailCount).find(".date").each(function() {
//	$(this).attr("id", "date" + dateDetailCount);
//	$(this).attr("class", "date");
//	dateDetailCount++;
// });
// $("#new_object" + objectDetailCount + " .option_line_id").focus();
// objectDetailCount++;
// $(".date").datepicker();
//// remove_option();
//// click_add_new_detail_row();
//});
//}
//
//click_add_new_detail_row();
//objectCount = 5000;
//dateCount = 10000;

//function click_add_new_line_row() {
//$("table#form_line_data_table").on("click", ".add_row_img", function(e) {
// $("table#form_line_data_table tr.option_line0").clone().one().attr("class", "new_object" + objectCount).attr("id", "new_object" + objectCount).appendTo($("table#form_line_data_table tbody#form_data_line_tbody"));
// $("tr.new_object" + objectCount).find("td input[type=text]").each(function() {
//	$(this).val("");
// });
// $(".new_object" + objectCount).find(".date").each(function() {
//	$(this).attr("id", "date" + dateCount);
//	$(this).attr("class", "date");
//	dateCount++;
// });
// $("tr.new_object" + objectCount ).find(".add_detail_values_img").on("click", function() {
//	$(this).closest("td").find(".form_detail_data_fs").toggle();
// });
// $("#new_object" + objectCount + " .option_line_id").focus();
// objectCount++;
// $(".date").datepicker();
//// remove_option();
//// click_add_new_detail_row();
//// click_add_new_line_row();
//});
//}
//
//click_add_new_line_row();

onClick_add_new_row('tr.option_line0', 'tbody.form_data_line_tbody', 1);

 $("#content").on("click", ".add_row_img", function() {
	alert ('trying to add new line');
	add_new_row('tr.option_line0', 'tbody.form_data_line_tbody', 1);
 });

 onClick_addDetailLine('tr.option_detail_tr0', 'tbody.form_data_detail_tbody', 1);

//remove option lines
 $("#remove_row").click(function() {
	$('input[name="option_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });
 
 //delete option details
// $("#delete_button").click(function() {
//	$('input[name="option_detail_id_cb"]:checked').each(function() {
//	 var option_detail_id = $(this).val();
//	 if (confirm("Are you sure?")) {
//		deleteOptionDetail(option_detail_id);
//	 }
//	});
// });
//
// function deleteOptionDetail(option_detail_id) {
//	$('#loading').show();
//	$.ajax({
//	 url: 'json.option.php',
//	 data: {delete: '1',
//		option_detail_id: option_detail_id},
//	 type: 'get'
//	}).done(function(result) {
//	 var div = $(result).filter('div#json_delete_option_detail').html();
//	 $(".error").append(div);
//	 $('#loading').hide();
//	}).fail(function(error, textStatus, xhr) {
//	 alert("delete failed \n" + error + textStatus + xhr);
//	 $('#loading').hide();
//	});
//// $(".form_table #subinventory_id").attr("disabled",false);
// }

//delete option lines
// $("#delete_button").click(function() {
//	$('input[name="option_line_id_cb"]:checked').each(function() {
//	 var option_line_id = $(this).val();
//	 if (confirm("Are you sure?")) {
//		deleteOptionLine(option_line_id);
//	 }
//	});
// });
//
// function deleteOptionLine(option_line_id) {
//	$('#loading').show();
//	$.ajax({
//	 url: 'json.option.php',
//	 data: {delete: '1',
//		option_line_id: option_line_id},
//	 type: 'get'
//	}).done(function(result) {
//	 var div = $(result).filter('div#json_delete_option_line').html();
//	 $(".error").append(div);
//	 $('#loading').hide();
//	}).fail(function(error, textStatus, xhr) {
//	 alert("delete failed \n" + error + textStatus + xhr);
//	 $('#loading').hide();
//	});
//// $(".form_table #subinventory_id").attr("disabled",false);
// }

//save option line & header
// function saveOptionHeader(option_header) {
//	$.ajax({
//	 url: 'json.option.php',
//	 data: {option_header: option_header},
//	 type: 'post'
//	}).done(function(result) {
//	 var div = $(result).filter('div#json_save_option_header').html();
//	 var option_header_id = $(div).filter('div#option_headerId').html();
//	 $(".error").append(div);
//	 $("#option_header_id").val(option_header_id);
//	 $("#save").removeClass("show_loading_small");
//	 $("#save").prop('disabled', false);
//	}).fail(function(error, textStatus, xhr) {
//	 alert("save failed \n" + error + textStatus + xhr);
//	 $("#save").removeClass("show_loading_small");
//	 $("#save").prop('disabled', false);
//	});
// }
//
// function saveOptionLine(option_line, trclass, detail_line) {
//	var option_header_id = $("#option_header_id").val();
//	$.ajax({
//	 url: 'json.option.php',
//	 data: {option_line: option_line,
//		detail_line : detail_line,
//		option_header_id: option_header_id},
//	 type: 'post'
//	}).done(function(result) {
//	 var div = $(result).filter('div#json_save_option_line').html();
//	 var option_line_id = $(div).filter('.option_lineId').html();
//	 $('#form_data_table tbody tr' + '.' + trclass).find(".option_line_id").val(option_line_id);
//	 $(".error").append(div);
//	}).fail(function(error, textStatus, xhr) {
//	 alert("save failed \n" + error + textStatus + xhr);
//	});
////	$("#save").removeClass("show_loading_small");
////  $("#save").prop('disabled', false);
// }
//
// $("#option #save").on('click', function(e) {
//	$("#save").addClass("show_loading_small");
//	$("#save").prop('disabled', true);
//	e.preventDefault();
//	var option_header = $("#option_header").serializeArray();
//	saveOptionHeader(option_header);
//	if ($('#form_data_table :checkbox:checked').length > 0) {
//	 $('input[name="option_line_id_cb"]:checked').each(function() {
//		var option_line = $(this).closest("tr").find(":input").serializeArray();
//		var trclass = $(this).closest("tr").attr('class');
//		var detail_line = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
//		saveOptionLine(option_line, trclass, detail_line);
//	 });
//	}
//	else if ($(".option_line_code").val().length > 0) {
//	 $("tbody#form_data_line_tbody > tr").each(function() {
//		var option_line = $(this).find(":input").serializeArray();
//		var trclass = $(this).attr('class');
//		var detail_line = $(this).find("tbody.form_data_detail_tbody").find(":input").serializeArray();
//		saveOptionLine(option_line, trclass, detail_line);
//	 });
//	}
// });
//$("#content").on("click","#new_line",function(){
// $(".add_row_img").trigger("click");
//});
//onClick_add_new_row('tr.option_line0', 'tbody.option_line_values', 1);
deleteData('json.option.php');
 save('json.option.php', '#option_header', 'line_id_cb', 'option_line_code', '#option_header_id');
 remove_row();
});


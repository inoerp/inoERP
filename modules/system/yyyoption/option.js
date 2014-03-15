$(document).ready(function() {
 $('#loading').hide();
 //basic finction --making background colors for form fields
 $("input").focus(function() {
	$(this).css("background-color", "#cccccc");
 });
 $("input").blur(function() {
	$(this).css("background-color", "#ffffff");
 });
 $("input:required").css("background-color", "pink");
 $("input:required").focus(function() {
	$(this).css("background-color", "pink");
 });
 $("input:required").blur(function() {
	$(this).css("background-color", "pink");
 });

 //end of basic functions

 //Refresh the content
 $('.refresh').click(function() {
	location.reload(true);
 });

//Popup for selecting option type
 $(".popup").click(function() {
	void window.open('find_option.php', '_blank',
					'width=700,height=500,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
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

//Get the option id on fly after clicking the submit header
 $('#submit_header').click(function() {
	var optionId = $('#option_header_id').val();
	$('#option_header').attr('action', 'option.php?option_header_id=' + optionId);
 });

//Get the option id on fly after clicking the submit line
 $('#submit_line').click(function() {
	var optionId = $('#option_header_id').val();
	$('#option_line').attr('action', 'option.php?option_header_id=' + optionId);
 });
 
 //create new ddetail line
 function json_remove_row(){
$(".json_remove_row_img").on("click", function(){
$(this).closest("tr").remove();
});
}
objectCount = 100;
 dateCount=1000;
 function json_click_add_new_field() {
$(".json_add_row_img").on("click", function() {
 $(this).closest("tr").clone().attr("class", "json_new_object" + objectCount).attr("id", "json_new_object" + objectCount).appendTo($(this).closest("tbody"));
	 $("tr.json_new_object" + objectCount).find("td input[type=text]").each(function() {
		$(this).val("");
	 });
	 $(".json_new_object" + objectCount).find(".date").each(function() {
		$(this).attr("id", "date" + dateCount);
		$(this).attr("class", "date");
		dateCount++;
	 });
	 $("#json_new_object" + objectCount + " .option_detail_id").focus();
	 objectCount++;
	 $(".date").datepicker();
	 json_remove_row();
	 json_click_add_new_field();
	});
 }

 json_click_add_new_field();

//create a new option line
 function remove_option() {
	$(".remove_row_img").dblclick(function() {
	 $(this).closest('tr').remove();
	});
 }

 objectCount = 10;
 dateCount=10000;
 function click_add_new_field() {
$("table#form_data_table .add_row_img").on("click", function() {
 $("table#form_data_table tr.option_line_tr0").clone().attr("class", "new_object" + objectCount).attr("id", "new_object" + objectCount).appendTo($("table#form_data_table tbody#form_data_tbody"));
	 $("tr.new_object" + objectCount).find("td input[type=text]").each(function() {
		$(this).val("");
	 });
	 $(".new_object" + objectCount).find(".date").each(function() {
		$(this).attr("id", "date" + dateCount);
		$(this).attr("class", "date");
		dateCount++;
	 });
	 $("#new_object" + objectCount + " .option_line_id").focus();
	 objectCount++;
	 $(".date").datepicker();
	 remove_option();
	 onClick_detailForm();
	 json_click_add_new_field();
	 click_add_new_field();
	 json_click_add_new_field();
	});
 }

 click_add_new_field();

//remove option lines
 $("#remove_row").click(function() {
	$('input[name="option_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//delete option lines
 $("#delete_row").click(function() {
	$('input[name="option_line_id_cb"]:checked').each(function() {
	 var option_line_id = $(this).val();
	 if (confirm("Are you sure?")) {
		deleteOptionLine(option_line_id);
	 }
	});
 });

 function deleteOptionLine(option_line_id) {
	$('#loading').show();
	$.ajax({
	 url: 'json.option.php',
	 data: {delete: '1',
		option_line_id: option_line_id},
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#json_delete_option_line').html();
	 $(".error").append(div);
	 $('#loading').hide();
	}).fail(function(error, textStatus, xhr) {
	 alert("delete failed \n" + error + textStatus + xhr);
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }

//hide detail from
function hideDetailForm(){
$("table.json_form_data_table").on("click",function(){
$(this).hide();
});
}
hideDetailForm();
//get the detail form form
function getDetailForm(option_line_id,trclass){
       $.ajax({
     url:'json.option.php' ,
		 data: {option_line_id: option_line_id,
		        option_line_page:'1'},
     type: 'get'
     }).done(function(result){
     var div = $(result).filter('div#option_line_values').html();
		 var option_line_values_form = $(div).filter('#option_line_values_form').html();
		 $('#form_data_table tbody tr' + '.' + trclass + ' td.add_detail_values').append(option_line_values_form);
		 $('#form_data_table tbody tr' + '.' + trclass + '.add_detail_values').removeClass("show_loading_small");
		 $('#form_data_table tbody tr' + '.' + trclass + '.add_detail_values').prop('disabled', false);
             }).fail(function(){
     alert("Value page loading failed");
		 $('#form_data_table tbody tr' + '.' + trclass + '.add_detail_values').removeClass("show_loading_small");
		 $('#form_data_table tbody tr' + '.' + trclass + '.add_detail_values').prop('disabled', false);
          });
json_click_add_new_field();
hideDetailForm();
}

function onClick_detailForm(){
$(".add_detail_values_img").click(function () {
 	$("this").addClass("show_loading_small");
	$("this").prop('disabled', true);
 var trclass = $(this).closest("tr").attr('class');
  var option_line_id = $(this).closest("tr").find(".option_line_id").val();
 getDetailForm(option_line_id,trclass);
 json_click_add_new_field();
 hideDetailForm();
// click_add_new_field();
 });
}

onClick_detailForm();


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

 function saveOptionLine(option_line, trclass) {
	var option_header_id = $("#option_header_id").val();
	$.ajax({
	 url: 'json.option.php',
	 data: {option_line: option_line,
		option_header_id: option_header_id},
	 type: 'post'
	}).done(function(result) {
	 var div = $(result).filter('div#json_save_option_line').html();
	 var option_line_id = $(div).filter('.option_lineId').html();
	 $('#form_data_table tbody tr' + '.' + trclass).find(".option_line_id").val(option_line_id);
	 $(".error").append(div);
	}).fail(function(error, textStatus, xhr) {
	 alert("save failed \n" + error + textStatus + xhr);
	});
//	$("#save").removeClass("show_loading_small");
//  $("#save").prop('disabled', false);
 }

 $("#option #save").on('click', function(e) {
	$("#save").addClass("show_loading_small");
	$("#save").prop('disabled', true);
	e.preventDefault();
	var option_header = $("#option_header").serializeArray();
	saveOptionHeader(option_header);
	if ($('#form_data_table :checkbox:checked').length > 0) {
	 $('input[name="option_line_id_cb"]:checked').each(function() {
		var option_line = $(this).closest("tr").find(":input").serializeArray();
		var trclass = $(this).closest("tr").attr('class');
		saveOptionLine(option_line, trclass);
	 });
	}
	else if ($(".option_line_code").val().length > 0) {
	 $('#form_data_table tbody tr ').each(function() {
		var option_line = $(this).find(":input").serializeArray();
		var trclass = $(this).attr('class');
		saveOptionLine(option_line, trclass);
	 });
	}
 });

});


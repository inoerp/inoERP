$(document).ready(function() {
 $(".field_option").attr("disabled", true);
 $(".field_type").attr('disabled', true);
 $(".field_num").attr("readonly", true);
 $(".field_enum").attr("readonly", true);

//Delete columns
 $("#delete_button").click(function() {
	$('input[name="field_name_cb"]:checked').each(function() {
	 var field_name = $(this).val();
	 var content_name = $("#content_type").val();
	 if (field_name == 'content_id') {
		alert('You can\'t delete content_id.\n. Content_id is auto removed on deleting content type. ');
		$(this).attr('checked', false);
	 } else if (confirm("Do you want to delete column?\n" + field_name)) {
		dropField(field_name, content_name);
	 }
	});
 });

 function dropField(field_name, content_name) {
	$('.show_loading_small').show();
	$.ajax({
	 url: 'json.content_type.php',
	 data: {delete: '1',
		field_name: field_name,
		content_name: content_name},
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#json_drop_column').html();
	 $(".error").append(div);
	 $('.show_loading_small').hide();
	}).fail(function() {
	 alert("Column delete failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }


//Delete content type : drop table
 $("#drop_table").click(function() {
	var content_name = $("#content_type").val();
	if (confirm("Are you sure?")) {
	 dropTable(content_name);
	}
 });

 function dropTable(content_name) {
	$('.show_loading_small').show();
	$.ajax({
	 url: 'json.content_type.php',
	 data: {delete: '2',
		content_name: content_name},
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#json_drop_column').html();
	 $(".error").append(div);
	 $('.show_loading_small').hide();
	}).fail(function() {
	 alert("Content type drop failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }

//Delete major category

 function removeCategory(category_id, content_type_id) {
	$('.show_loading_small').show();
	$.ajax({
	 url: '../category/json.category.php',
	 data: {delete: '1',
		category_id: category_id,
		content_type_id: content_type_id},
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#json_drop_column').html();
	 $(".error").append(div);
	 $('.show_loading_small').hide();
	}).fail(function() {
	 alert("Category reomval failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }

 //add remove category
 var new_object = 1000;
 $("#tabsHeader").on('click', '.add_row_img', function() {
	$(this).closest('li').clone().attr('class', 'new_object' + new_object).appendTo($(this).closest('ul'));
	new_object++;
 });
//
 $("#tabsHeader").on('click', '.remove_row_img', function() {
	var category_id = $(this).closest('li').find('.category_id').val();
	var content_type_id = $("#content_type_id").val();
	if (confirm("Do you want to delete \n Category " + category_id + " ?")) {
	 removeCategory(category_id, content_type_id);
	}
 });

//on click refresh
 $('#form_header a.show').click(function() {
	var content_type_id = $('#content_type_id').val();
	$(this).attr('href', 'content_type.php?mode=9&content_type_id=' + content_type_id);
 });

//field enable disable
 $("#content tbody.field_values_list").on("click", ".add_row_img", function() {
	add_new_row('tr.content_type0', 'tbody.field_values_list', 2);
	$("tbody.field_values_list").find(".field_name:last").attr("readonly", false);
	$("tbody.field_values_list").find(".field_type:last").attr("disabled", false);
 });

 $('#content').on('blur', '.field_type', function() {
	if (($(this).val() == 'int') || ($(this).val() == 'varchar')) {
	 $(this).closest('tr').find('.field_num').attr("readonly", false);
	 $(this).closest('tr').find('.field_enum').attr("readonly", true);
	 $(this).closest('tr').find(".field_option").attr("disabled", true);
	} else if ($(this).val() == 'enum') {
	 $(this).closest('tr').find('.field_enum').attr("readonly", false).attr("placeholder", "comma(,) separated values");
	 $(this).closest('tr').find('.field_num').attr("readonly", true);
	 $(this).closest('tr').find(".field_option").attr("disabled", true);
	} else if ($(this).val() == 'option') {
	 $(this).closest('tr').find('.field_num').attr("readonly", true);
	 $(this).closest('tr').find('.field_enum').attr("readonly", true);
	 $(this).closest('tr').find(".field_option").attr("disabled", false);
	}
	else {
	 $(this).closest('tr').find('.field_num').val('');
	 $(this).closest('tr').find('.field_num').attr("readonly", true);
	 $(this).closest('tr').find('.field_enum').val('');
	 $(this).closest('tr').find('.field_enum').attr("readonly", true);
	 $(this).closest('tr').find(".field_option").attr("disabled", true);
	}
 });

 $('#content').on('blur', '.field_name', function() {
	if ($(this).val()) {
	 $(this).closest('tr').find('.field_type').attr("disabled", false);
	}
 });


 $('#form_line').on('change', '.checkBox', function() {
	if (this.checked) {
	 $(this).val(($(this).closest('tr').find('.field_name').val()));
	} else {
	 $(this).val(1);
	}
 });

//save
// save('json.content_type.php', '#content_type_header', 'line_id_cb', 'content_type', '#content_type_id', '', '');

//$('#save').on('click', function(){
// $(".error").append('Saving Data');
//var form_header_id ='#content_type_header';
//$(form_header_id).find('select').attr('disabled', false);
//var headerData = $(form_header_id).serializeArray();
// saveHeader('json.content_type.php', headerData, '#content_type_id', '');
//});

 $('#save').on('click', function() {
	$(".error").append('Saving Data');
	var form_header_id = '#content_type_header';
	$(form_header_id).find('select').attr('disabled', false);
	var headerData = $(form_header_id).serializeArray();
	saveHeader('content_type.php', headerData, '#content_type_id', '', true, 'content_type');
	$(form_header_id).find('select').attr('disabled', true);
 });

// var classSave = new saveMainClass();
// classSave.json_url = 'content_type.php';
// classSave.form_header_id = 'content_type_header';
// classSave.primary_column_id = 'content_type_id';
// classSave.single_line = false;
// classSave.savingOnlyHeader = true;
// classSave.headerClassName = 'content_type';
// classSave.saveMain();

});

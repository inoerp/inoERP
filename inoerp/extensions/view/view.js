function getFieldNames(tableName, parentClass) {
 $('#loading').show();
 $.ajax({
	url: 'extensions/view/json_view.php',
	data: {tableName: tableName,
	 get_fieldName: 1},
	type: 'get'
 }).done(function(result) {
	var tableClass = '.'+parentClass.replace(/\s+/g, '.');
	var div = $(result).filter('div#json_filed_names').html();
  if(div.length > 5 ){
	$('#content').find(tableClass).find('.table_fields').empty().append(div);
 }
	$('#loading').hide();
 }).fail(function() {
	alert("table field loading failed");
	$('#loading').hide();
 });
 $(".table_fields").attr("disabled", false);
}

function setValFromSelectPage(view_id) {
 this.view_id = view_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var view_id = this.view_id;
  if (view_id) {
	$("#view_id").val(view_id);
 }
};

$(document).ready(function() {
 //togle values
 $("#view_query label").click(function() {
	$("#view_query").find("textarea").toggle();
 });

 $("#live_display label").click(function() {
	$("#live_display").find("#live_display_data").toggle();
 });

 $("#logical_settings label").click(function() {
	$("#logical_settings").find("ul").toggle();
 });

//function add remove view path
 objectcount1 = 100;
 $("#content").on("click", '.add_new_path', function() {
	$(".view_path").first().clone().attr("class", "view_path new_object" + objectcount1).appendTo($(this).parent());
	objectcount1++;
 });
 $("#content").on('change', '.view_path', function() {
	if ($(this).val() === 'remove') {
	 if ($('#content').find('.view_path').length > 1) {
		$(this).remove();
	 } else {
		alert('You cant remove the last node');
	 }
	}
 });


//get table fields
 $("#content").on('change', '.all_table_names', function() {
	var tableName = $(this).val();
	var parentClass = $(this).closest('ul').attr("class");
	if(tableName !=='remove_table'){
	getFieldNames(tableName, parentClass);
 }
 });

 $("#content").on('click', '.remove_option', function() {
	if ($(this).closest('ul').find('li').length > 2) {
	 $(this).closest('li').remove();
	} else {
	 alert('You cant remove first field\nRemove table if required');
	}
 });

 $("#content").on('click', '.remove_table', function() {
	if ($(this).closest('div#display_div').find('ul').length > 1) {
	 $(this).closest('ul').remove();
	} else {
	 alert('You cant remove first table name ');
	}
});

 var objectCount = 1000;
	$("#content").on("click",'.add_new_table' ,function() {
	 $("ul.display_records").first().clone().attr("class", "display_records table_object" + objectCount).appendTo($("#display_div"));
	 $("#new_object" + objectCount + " .table_fields option").replaceWith("");
	 objectCount++;
	});
 

 var objectCount1 = 10;
 $("#content").on("change", 'select.table_fields', function() {
	if($(this).val() && ($(this).val()!=='remove')){
	$(this).closest("ul").find('li.field_records').first().clone().attr("class", "field_records record_no" + objectCount1).appendTo($(this).closest('ul'));
	objectCount1++;
 }
 });
//end of get tables

//condition
 function condition_operator_type_selection() {
	$(".condition_operator_type").blur(function() {
	 var conditionValue = $(this).val();
	 if (conditionValue == 'database') {
		$(this).closest("td").next(".condition_row_value").children(".condition_row_value_input").remove();
	 } else if (conditionValue == 'remove') {
		$(this).closest("tr").remove();
	 } else {
		var InputText = '<input type="text" class="condition_row_value_input input">';
		$(this).closest("td").next(".condition_row_value").html(InputText);
	 }
	});
 }
 condition_operator_type_selection();


//allow to drag & drop
 function remove_from_dragged_element() {
	$(".draggable_element.ui-draggable").dblclick(function() {
	 $(this).remove();
	});
 }

 function drag_drop_condition() {
	$(".draggable_element").draggable(
					{helper: 'clone'},
	{cursor: "crosshair"});
	$(".condition_row_parameter").droppable({
	 accept: ".draggable_element",
	 drop: function(event, ui) {
		console.log("Item was Dropped");
		$(this).append($(ui.draggable).clone());
		remove_from_dragged_element();
	 }
	});
 }
 function drag_drop_condition_value() {
	$(".draggable_element").draggable(
					{helper: 'clone'},
	{cursor: "crosshair"});
	$(".condition_row_value").droppable({
	 accept: ".draggable_element",
	 drop: function(event, ui) {
		console.log("Item was Dropped");
		$(this).append($(ui.draggable).clone());
		remove_from_dragged_element();
	 }
	});
 }

 function drag_drop_condition_sort() {
	$(".draggable_element").draggable(
					{helper: 'clone'},
	{cursor: "crosshair"});
	$(".sort_fields_field_value").droppable({
	 accept: ".draggable_element",
	 drop: function(event, ui) {
		console.log("Item was Dropped");
		$(this).append($(ui.draggable).clone());
		remove_from_dragged_element();
	 }
	});
 }
 drag_drop_condition();
 drag_drop_condition_value();
 drag_drop_condition_sort();
 remove_from_dragged_element();

 var objectCount2 = 500;
 function click_add_new_condition() {
	$(".add_new_conditions").on("click", function() {
	 $("tr.condition_row").clone().appendTo($("table#condition_buttons_table tbody"));
	 objectCount1++;
	 select_tableName();
//	click_add_new_field();
	 
	 drag_drop_condition();
	 drag_drop_condition_value();
	 drag_drop_condition_sort();
	 remove_from_dragged_element();
	 condition_operator_type_selection();
	});
 }

 click_add_new_condition();

 var objectCount2 = 1500;
 function click_add_new_sort_criteria() {
	$(".add_new_sort_criteria").on("click", function() {
	 $("tr.sort_fields_row").clone().appendTo($("table#sort_fields_table tbody"));
	 objectCount1++;
	 select_tableName();
//	click_add_new_field();
	 
	 drag_drop_condition();
	 drag_drop_condition_value();
	 drag_drop_condition_sort();
	 remove_from_dragged_element();
	 condition_operator_type_selection();
	});
 }

 click_add_new_sort_criteria();



//create the SQL query
//function create_sql_query(){
//tableArray = [];
//$(".all_table_names option:selected").each(function(){
//tableName=$(this).val();
//tableArray.push(tableName);
//});
//fieldArray = [];
//$(".table_fields option:selected").each(function(){
//tableName = $(this).closest("ul").children("#table_records").children(".all_table_names").val();
//fieldTableName=tableName+'.'+$(this).val();
//fieldArray.push(fieldTableName);
//});
//
//whereClauseArray = [];
//$(".condition_row").each(function(){
//var parameter = $(this).find(".condition_buttons").val();
//var operator = $(this).find(".condition_operator").val();
//var operator_type = $(this).find(".condition_operator").val();
//if(operator_type =='database')
//{
//var valueClass="condition_buttons";
//}else{
//var valueClass="condition_row_value_input";
//}
//var value = $(this).find('.' + valueClass).val();
//var whereClause = parameter + " " + operator + " " + value;
//whereClauseArray.push(whereClause);
//});
//
//alert(whereClauseArray);
//
//sql = "SELECT " + fieldArray + "\nFROM \n " + tableArray + "\n WHERE" + whereClauseArray ;
//
//$("#sql_query").val(sql);
//}

 function create_sql_query() {
	tableArray = [];
	$(".all_table_names option:selected").each(function() {
	 tableName = $(this).val();
	 tableArray.push(tableName);
	});

	show_fieldArray = [];
	$("#show_field_buttons .showField_buttons").each(function() {
	 fieldName = $(this).val();
	 fieldNameSeparated = fieldName.replace(/\./g, '__');
	 fieldNameAs = fieldName + ' AS ' + fieldNameSeparated;
	 show_fieldArray.push(fieldNameAs);
	});

	fieldArray = [];
	$(".table_fields option:selected").each(function() {
	 tableName = $(this).closest("ul").children("#table_records").children(".all_table_names").val();
	 fieldTableName = tableName + '.' + $(this).val();
	 fieldArray.push(fieldTableName);
	});

	filterArray = [];
	$("#condition_buttons_div .condition_buttons").each(function() {
	 conditionName = $(this).val();
	 filterArray.push(conditionName);
	});

	whereClauseArray = [];
	$(".condition_row").each(function() {
	 var parameter = $(this).find(".condition_buttons").val();
	 var operator = $(this).find(".condition_operator").val();
	 var operator_type = $(this).find(".condition_operator_type").val();
	 if (operator_type == 'database')
	 {
		var valueClass = "condition_buttons";
		var value = $(this).find(".condition_row_value").children().children().val();
		var whereClause = parameter + " " + operator + " " + value;
	 } else {
		var valueClass = "condition_row_value_input";
		var value = $(this).find('.' + valueClass).val();
		var whereClause = parameter + " " + operator + " " + '\'' + value + '\'';
	 }

	 if (parameter) {
		whereClauseArray.push(whereClause);
	 }
	});

	sortArray = [];
	$(".sort_fields_row").each(function() {
	 sortFieldName = $(this).find(".showField_buttons").val();
	 sortFieldValue = $(this).find(".sort_fields_values").val();
	 if ((sortFieldName) && (sortFieldName.length > 0)) {
		sortField = sortFieldName + " " + sortFieldValue;
		sortArray.push(sortField);
	 }
	});

	if (whereClauseArray) {
	 whereClauseArray2 = whereClauseArray.join("\nAND ");
	}

	var sql = "";
	if ((show_fieldArray) && (show_fieldArray.length > 0) && (tableArray) && (tableArray.length > 0)) {
	 sql = "SELECT " + show_fieldArray + "\nFROM \n" + tableArray;
	}
	if ((whereClauseArray2) && (whereClauseArray2.length > 0)) {
	 sql += "\nWHERE " + whereClauseArray2;
	}

	if ((sortArray) && (sortArray.length > 0)) {
	 sql += "\nORDER BY " + sortArray;
	}

	if (sql) {
	 $("#query").val(sql);
	 $("#select").val(show_fieldArray);
	 $("#from").val(tableArray);
	 $("#where").val(whereClauseArray2);
	 $("#order_by").val(sortArray);
	 $("#filters").val(filterArray);
	}
 }

 function update_conditions() {
	var condition_buttons = "";
	var showField_buttons = "";
	$(fieldArray).each(function(index) {
	 condition_buttons += '<div class="draggable_element">';
	 condition_buttons += '<input type="text" value="' + fieldArray[index] + '" class="condition_buttons ' + fieldArray[index] + '">';
	 condition_buttons += '</div>';
	});
	$(fieldArray).each(function(index) {
	 showField_buttons += '<div class="draggable_element">';
	 showField_buttons += '<input type="text" value="' + fieldArray[index] + '" class="showField_buttons ' + fieldArray[index] + '">';
	 showField_buttons += '</div>';
	});
	$("#condition_buttons_div").html(condition_buttons);
	$("#show_field_buttons").html(showField_buttons);
 }

 function change_attr_of_selected_elements() {
	$(".table_fields").find(':selected').attr("selected", "selected");
	$(".all_table_names").find(':selected').attr("selected", "selected");
 }

 $("#save_tables").click(function() {
	create_sql_query();
	update_conditions();
	drag_drop_condition();
	drag_drop_condition_value();
	drag_drop_condition_sort();
	condition_operator_type_selection();
	remove_from_dragged_element();
	change_attr_of_selected_elements();
 });

 $("#save_query").click(function() {
	create_sql_query();
//update_conditions();
//drag_drop_condition();
//drag_drop_condition_value();
//condition_operator_type_selection();
//remove_from_dragged_element();
 });

//get the new search criteria
 $("#new_search_criteria_add").click(function() {
	$('#loading').show();
	var new_search_criteria = $(".new_search_criteria").val();
	$.ajax({
	 url: 'json.view.php',
	 data: {new_search_criteria: new_search_criteria},
	 type: 'get'
	}).done(function(result) {
//      var div = $('#new_search_criteria', $(data)).html();
	 var div = $(result).filter('div#new_search_criteria').html();
	 $("ul.search_form").append(div);
	 $('#loading').hide();
	}).fail(function() {
//     alert("org name loading failed");
	 $('#loading').hide();
	});
 });

 $("#submit_view").click(function() {
	var logical_settings = $("ul#logical_settings").html();
	$("#logical_settings_value").val(logical_settings);
//alert($("#logical_settings_value").val());
 });
 
  //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=view';
 classSave.form_header_id = 'view_header';
 classSave.primary_column_id = 'view_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'view';
 classSave.saveMain();

  $(".view_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=view', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
 //Get the ext_url_alias_id on find button click
 $('a.show.view_id').click(function(e) {
	var headerId = $('#view_id').val();
	$(this).attr('href', modepath() + 'view_id=' + headerId);
 });

});

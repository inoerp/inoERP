function setValFromSelectPage(view_id) {
 this.view_id = view_id;
}

function condition_operator_type_selection() {
 $(".condition_operator_type").blur(function () {
  var conditionValue = $(this).val();
  if (conditionValue == 'database') {
   $(this).closest("td").next(".condition_row_value").find('inpur').remove();
  } else if (conditionValue == 'remove') {
   $(this).closest("tr").remove();
  } else {
   var InputText = '<input type="text" class="condition_row_value input">';
   $(this).closest("td").next(".condition_row_value").html(InputText);
  }
 });
}

function drag_drop_condition_value() {
 $(".draggable_element").draggable(
         {helper: 'clone'},
 {cursor: "crosshair"});
 $(".condition_row_value, .sort_fields_field_value, .group_by_fields, .condition_row_parameter, .ui-droppable").droppable({
  accept: ".draggable_element",
  drop: function (event, ui) {
   $(this).append($(ui.draggable).clone());
//		remove_from_dragged_element();
  }
 });
}

var objectCount2 = 500;
function click_add_new_condition() {
 $(".add_new_conditions").on("click", function () {
  $("tr.condition_row").first().clone().appendTo($("table#condition_buttons_table tbody"));
  objectCount2++;
  drag_drop_condition_value();
  condition_operator_type_selection();
 });
}

var objectCount3 = 1500;


function create_sql_query() {
 var tableArray = [];
 $(".all_table_names option:selected").each(function () {
  var tableName = $(this).val();
  tableArray.push(tableName);
 });

 var show_fieldArray = [];
 $("#show_field_buttons .showField_buttons").each(function () {
  var fieldName = $(this).val();
  var fieldNameSeparated = fieldName.replace(/\./g, '__');
  fieldNameSeparated = fieldNameSeparated.replace(/\(/g, '_');
  fieldNameSeparated = fieldNameSeparated.replace(/\)/g, '');
  var fieldNameAs = fieldName + ' AS ' + fieldNameSeparated;
  show_fieldArray.push(fieldNameAs);
 });

 var fieldArray = [];
 $(".table_fields option:selected").each(function () {
  var tableName = $(this).closest("ul").children("#table_records").children(".all_table_names").val();
  var fieldTableName = tableName + '.' + $(this).val();
  fieldArray.push(fieldTableName);
 });


 var whereClauseArray = [];
 var leftJoinStmt = '';
 var tablesInLeftJoin = [];
 $(".condition_row").each(function () {
  var parameter = $(this).find(".showField_buttons").val();
  var operator = $(this).find(".condition_operator").val().trim();
  var operator_type = $(this).find(".condition_operator_type").val();
  var whereClause = '';
  if (operator === 'LEFT_JOIN') {
   var value = $(this).find(".condition_row_value").find('input').val();
   var parameter_s = parameter.split('.');
   var value_s = value.split('.');
   if (parameter) {
    if (leftJoinStmt.length > 10) {
     leftJoinStmt += '\n ' + " LEFT JOIN " + value_s[0] + " ON " + parameter + ' = ' + value;
    } else {
     leftJoinStmt += ' ' + parameter_s[0] + " LEFT JOIN " + value_s[0] + " ON " + parameter + ' = ' + value;
    }
    tablesInLeftJoin.push(parameter_s[0]);
    tablesInLeftJoin.push(value_s[0]);
   }
  } else if (operator === 'IS_NOT_NULL')
  {
   whereClause += parameter + " IS NOT NULL ";
   whereClauseArray.push(whereClause);
  } else if (operator === 'IS_NULL')
  {
   whereClause += parameter + " IS NULL ";
   whereClauseArray.push(whereClause);
  } else {
   if (operator_type == 'database')
   {
    var value = $(this).find(".condition_row_value").find('input').val();
    whereClause += parameter + " " + operator + " " + value;
   } else {
    var value = $(this).find('.condition_row_value').find('input').val();
    whereClause += parameter + " " + operator + " " + '\'' + value + '\'';
   }

   if (parameter) {
    whereClauseArray.push(whereClause);
   }
  }

 });

 var sortArray = [];
 $(".sort_fields_row").each(function () {
  var sortFieldName = $(this).find(".showField_buttons").val();
  var sortFieldValue = $(this).find(".sort_fields_values").val();
  if ((sortFieldName) && (sortFieldName.length > 0)) {
   var sortField = sortFieldName + " " + sortFieldValue;
   sortArray.push(sortField);
  }
 });

 var groupByArray = [];
 $("td.group_by_fields").each(function () {
  if ($(this).find(".showField_buttons").val()) {
   groupByArray.push($(this).find(".showField_buttons").val());
  }
 });

 if (whereClauseArray) {
  var whereClauseArray2 = whereClauseArray.join("\nAND ");
 }

 var sql = "";
 if ((show_fieldArray) && (show_fieldArray.length > 0) && (tableArray) && (tableArray.length > 0)) {
  sql = "SELECT " + show_fieldArray;
 }

 if (tablesInLeftJoin.length > 1) {
  var fromClause = leftJoinStmt;
  tableArray = tableArray.filter(function (el) {
   return tablesInLeftJoin.indexOf(el) < 0;
  });
  if (tableArray.length > 0) {
   fromClause += ',\n' + tableArray.join(",\n");
  }
 } else {
  var fromClause = tableArray.join(",\n");
 }

 sql += "\nFROM \n" + fromClause;

 if ((whereClauseArray2) && (whereClauseArray2.length > 0)) {
  sql += "\nWHERE " + whereClauseArray2;
 }

 if ((groupByArray) && (groupByArray.length > 0)) {
  sql += "\nGROUP BY " + groupByArray;
 }

 if ((sortArray) && (sortArray.length > 0)) {
  sql += "\nORDER BY " + sortArray;
 }

 if (sql) {
  $("#query_v").val(sql);
  $("#select_v").val(show_fieldArray);
  $("#from_v").val(fromClause);
  $("#where_v").val(whereClauseArray2);
  $("#group_by_v").val(groupByArray);
  $("#order_by").val(sortArray);
 }
}

function update_conditions() {
 var condition_buttons = "";
 var showField_buttons = "";
 var fieldArray = [];
 $(".table_fields option:selected").each(function () {
  var tableName = $(this).closest("ul").children("#table_records").children(".all_table_names").val();
  var fieldTableName = tableName + '.' + $(this).val();
  fieldArray.push(fieldTableName);
 });
 $(fieldArray).each(function (index) {
  condition_buttons += '<li class="draggable_element ui-state-default">';
  condition_buttons += '<input type="text" value="' + fieldArray[index] + '" class="condition_buttons ' + fieldArray[index] + '">';
  condition_buttons += '</li>';
 });
 $(fieldArray).each(function (index) {
  showField_buttons += '<li class="draggable_element ui-state-default">';
  showField_buttons += '<input type="text" value="' + fieldArray[index] + '" class="showField_buttons ' + fieldArray[index] + '">';
  showField_buttons += '</li>';
 });
 $("#show_field_buttons").html(showField_buttons);
}

function change_attr_of_selected_elements() {
 $(".table_fields").find(':selected').attr("selected", "selected");
 $(".all_table_names").find(':selected').attr("selected", "selected");
}

setValFromSelectPage.prototype.setVal = function () {
 var view_id = this.view_id;
 if (view_id) {
  $("#view_id").val(view_id);
 }
};

$(document).ready(function () {
 //togle values
 $("#view_query label").click(function () {
  $("#view_query").find("textarea").toggle();
 });

 $("#live_display label").click(function () {
  $("#live_display").find("#live_display_data").toggle();
 });

// $("#logical_settings label").click(function() {
//  $("#logical_settings").find("ul").toggle();
// });

 $('#display_result').on('click', function () {
  getViewResult();
 });

//remove fields
 $('#content').off('blur', '.table_fields').on('blur', '.table_fields', function () {
  console.log($(this).val());
  if (!$(this).val() || $(this).val() == 'remove') {
   if ($(this).closest('.display_records').find('li').length > 2) {
    $(this).closest('li').remove();
   } else {
    alert('You cant remove first field\nRemove table if required');
   }
  }
 });

 $('#content').off('dblclick', '.draggable_element').on('dblclick', '.draggable_element', function () {
  if ($(this).parent().prop('tagName') == 'TR') {
   if ($('#condition_buttons_table').find('tr').length > 1) {
    $(this).remove();
   }
  } else {
   $(this).remove();
  }
 });

//get table fields
 $("#content").off('change', '.all_table_names').on('change', '.all_table_names', function () {
  if (!$(this).val()) {
   return;
  }
  var tableName = $(this).val();
  var parentClass = $(this).closest('ul').attr("class");
  if (tableName !== 'remove_table') {
   getFieldNames({
    tableName: tableName,
    parentClass: parentClass
   });
  }
 });


 $("#content").off('blur', '.all_table_names').on('blur', '.all_table_names', function () {
  if (!$(this).val()) {
   if ($(this).closest('div#display_div').find('ul').length > 1) {
    $(this).closest('ul').remove();
   } else {
    alert('You cant remove first table name ');
   }
  }
 });

 var objectCount = 1000;
 $("#content").off("click", '.add_new_table').on("click", '.add_new_table', function () {
  $("ul.display_records").first().clone().attr("class", "display_records table_object" + objectCount).appendTo($("#display_div"));
  $("#new_object" + objectCount + " .table_fields option").replaceWith("");
  objectCount++;
 });


 var objectCount1 = 10;
 $("#content").off("change", 'select.table_fields').on("change", 'select.table_fields', function () {
  if ($(this).val() && ($(this).val() !== 'remove')) {
   $(this).closest("ul").find('li.field_records').first().clone().attr("class", "field_records record_no" + objectCount1).appendTo($(this).closest('ul'));
   objectCount1++;
  }
 });
//end of get tables

//condition
 condition_operator_type_selection();
 drag_drop_condition_value();
 click_add_new_condition();
 $("#content").off("click", '.add_new_sort_criteria').on("click", '.add_new_sort_criteria', function () {
  $("tr.sort_fields_row").clone().appendTo($("table#sort_fields_table tbody"));
  drag_drop_condition_value();
  condition_operator_type_selection();
 });

 $("#content").off("click", '.add_new_groupBy_criteria').on("click", '.add_new_groupBy_criteria', function () {
  $('#group_by_table tbody tr').first().clone().appendTo($("table#group_by_table tbody"));
  drag_drop_condition_value();
 });

 $("#save_tables").click(function () {
  update_conditions();
  drag_drop_condition_value();
  condition_operator_type_selection();
  change_attr_of_selected_elements();
 });

// $("#save_tables").trigger('click');

 $("#save_query").click(function () {
  create_sql_query();
 });

//get the new search criteria
 $("#new_search_criteria_add").click(function () {
  $('#loading').show();
  var new_search_criteria = $(".new_search_criteria").val();
  $.ajax({
   url: 'json.view.php',
   data: {new_search_criteria: new_search_criteria},
   type: 'get'
  }).done(function (result) {
//      var div = $('#new_search_criteria', $(data)).html();
   var div = $(result).filter('div#new_search_criteria').html();
   $("ul.search_form").append(div);
   $('#loading').hide();
  }).fail(function () {
//     alert("org name loading failed");
   $('#loading').hide();
  });
 });

 $("#submit_view").click(function () {
  var logical_settings = $("ul#logical_settings").html();
  $("#logical_settings_value").val(logical_settings);
//alert($("#logical_settings_value").val());
 });



 $(".view_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=view', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 $('#page_nos').on('click', 'a', function (e) {
  e.preventDefault();
  var link = $(this).attr('href');
  var class_name = getUrlValues('class_name', link);
  var view_id = getUrlValues('view_id', link);
  var pageno = getUrlValues('pageno', link);
  var per_page = getUrlValues('per_page', link);
  //calling the ajax function
  getViewResult({
   class_name: class_name,
   view_id: view_id,
   pageno: pageno,
   per_page: per_page,
   show_from_query: false,
  });

 });

 $('#content').on('change', '.sort_fields_values', function () {
  if ($(this).val() == 'REMOVE') {
   $(this).closest('tr').find('li').remove();
  }
 });

 $('.update_parent_id_cb').on('click', function () {
  if ($(this).is(':checked')) {
   $('#parent_id').attr('disabled', false);
  } else {
   $('#parent_id').attr('disabled', true);
  }
 });

 $('#draw_svg_image').on('click', function () {
  getSvgImage();
 });

//Mathematical functions
 $('#content').on('focusout', 'input.showField_buttons', function () {
  $('#content').data('lastSelected', $(this));
 });

 $('body').off('click', '#func_sum').on('click', '#func_sum', function () {
  var lastSelected = $('#content').data('lastSelected');
  var sumValue = 'SUM(' + $(lastSelected).val() + ')';
  $(lastSelected).val(sumValue);
 });

 $('body').off('click', '#func_count').on('click', '#func_count', function () {
  var lastSelected = $('#content').data('lastSelected');
  var sumValue = 'COUNT(' + $(lastSelected).val() + ')';
  $(lastSelected).val(sumValue);
 });

 $('body').off('click', '#func_avg').on('click', '#func_avg', function () {
  var lastSelected = $('#content').data('lastSelected');
  var sumValue = 'AVG(' + $(lastSelected).val() + ')';
  $(lastSelected).val(sumValue);
 });

 $('body').off('click', '#func_max').on('click', '#func_max', function () {
  var lastSelected = $('#content').data('lastSelected');
  var sumValue = 'MAX(' + $(lastSelected).val() + ')';
  $(lastSelected).val(sumValue);
 });

 $('body').off('click', '#func_min').on('click', '#func_min', function () {
  var lastSelected = $('#content').data('lastSelected');
  var sumValue = 'MIN(' + $(lastSelected).val() + ')';
  $(lastSelected).val(sumValue);
 });
});

function getReportResult_i(filterData, sortData) {
 if (typeof filterData === 'undefined') {
  filterData = $('.extn_report_filters').find('.filtered_field:input').serializeArray();
 }
 if (typeof sortData === 'undefined') {
  sortData = $('.extn_report_filters').find('.sorted_field:input').serializeArray();
 }
 getReportResult({
  filterData: filterData,
  sortData: sortData,
  extn_report_id: $('#extn_report_id').val(),
  show_from_query: false
 });
}

$.fn.getReportResult_e = function (options) {
 var thisElement = $(this);
 var filterData = $(this).closest('div.extn_report_content').find('.extn_report_filters').find('.filtered_field:input').serializeArray();
 var sortData = $(this).closest('div.extn_report_content').find('.extn_report_filters').find('.sorted_field:input').serializeArray();
 $.when(getReportResult({
  filterData: filterData,
  sortData: sortData,
  extn_report_id: $(this).closest('div.extn_report_content').find('.extn_report_id').val(),
  show_from_query: false,
  update_result: false
 })).then(function (data, textStatus, jqXHR) {
  var divHtml = $(data).filter('div#return_divId').html();
  $(thisElement).closest('div.extn_report_content').find('.live_display_data').empty().append(divHtml);
  $.getScript("includes/js/reload.js");
 });
 return this;
};

$(document).ready(function () {
// $('table.extn_report th').find('img').hide();
// $('.extn_report_content').on('mouseenter', 'table.extn_report th', function() {
//  $(this).find('ul').addClass('icon_header');
//  $(this).find('img').show();
// }).on('mouseleave', 'table.extn_report th', function() {
//  $(this).find('img').hide();
//  $(this).find('ul').removeClass('icon_header');
// });

// $('.extn_report_content').off('click', '.ino_filter').on('click', '.ino_filter', function () {
////  $(this).removeClass('show_add_filter');
//  var fieldName = $(this).closest('th').data('field_name');
//  var filter_value = prompt("Enter value for\n" + fieldName);
//  var newDataField = '<span class="filtered_field show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + filter_value;
//  newDataField += '<input class="hidden filtered_field" type="hidden" value="' + filter_value + '" name="' + $(this).closest('th').data('field_name') + '"></span>';
//  if (filter_value) {
//   $(this).closest('div.extn_report_content').find('.extn_report_filters').append(newDataField);
//   $(this).getReportResult_e();
//  }
// });


 $('#filter_area').off('click', '.apply-filter').on('click', '.apply-filter', function () {
  var inputFieldName = $(this).closest('.list_filter').find('select.field_name').val();
  var inputFieldCondition = $(this).closest('.list_filter').find('select.condition_name').val();
  var inputFieldValue = $(this).closest('.list_filter').find('input.condition_value').val();

  var filterHtml = ' ' + inputFieldName;
  filterHtml += ' ' + inputFieldCondition;
  filterHtml += ' ' + inputFieldValue;
  var elementClass = 'applied-filter ' + inputFieldName;
  var elementToBeCloned = $('.applied_filters').last().clone().attr('data-field_name', inputFieldName).attr('class', elementClass);
  $(elementToBeCloned).find('button.toggle-filter').append(filterHtml);
  $('#searchForm').append(elementToBeCloned);

  var hiddenFieldValue = inputFieldCondition + inputFieldValue;
  var hiddenInput = '<input class="filter_field ' + inputFieldName + ' " type="hidden" value="' + hiddenFieldValue + '" name="' + inputFieldName + '[]" form="generic_search_form">';
  $('#searchForm').find('ul.search_form').append(hiddenInput);

  var newDataField = '<span class="filtered_field show_remove_filter ' + inputFieldName + '">' + inputFieldName + ' : ' + inputFieldValue;
  newDataField += '<input class="hidden filtered_field" type="hidden" value="' + inputFieldValue + '" name="' + inputFieldName + '"></span>';
  if (inputFieldValue) {
   $('div.extn_report_content').find('.extn_report_filters').append(newDataField);
   var report_divid = '#' + localStorage.getItem("report_divid");
   $(report_divid).find('.ino_filter').first().getReportResult_e();
   localStorage.removeItem("report_divid");
  }
 });

 $('.extn_report_content').off('click', '.ino_filter').on('click', '.ino_filter', function () {
  $("#filter_area").dialog("open");
  var select_field = '<select class="field_name form-control" name="field_name">';
  $(this).closest('table.extn_report').find('th').each(function () {
   if ($(this).data('field_name')) {
    var fname = $(this).data('field_name');
    select_field += '<option value="' + fname + '"> ' + fname + ' </option> ';
   }
  });
  select_field += '</select>';
  $("#filter_area").find('input.field_name').replaceWith(select_field);
  $("#filter_area").find('select.field_name').val($(this).closest('th').data('field_name'));
  localStorage.setItem("report_divid", $(this).closest('.extn_report_display_data').attr('id'));

 });

 $('.extn_report_filters').off('click', '.filtered_field, .show_sort_remove').on('click', '.filtered_field, .show_sort_remove', function () {
  var thisElement = $(this);
  var filterData = $(this).closest('div.extn_report_content').find('.extn_report_filters .filtered_field').not(this).find(':input').not(this).serializeArray();
  var sortData = $(this).closest('div.extn_report_content').find('.extn_report_filters .sorted_field').not(this).find(':input').not(this).serializeArray();
  $.when(getReportResult({
   filterData: filterData,
   sortData: sortData,
   extn_report_id: $(this).closest('div.extn_report_content').find('.extn_report_id').val(),
   show_from_query: false,
   update_result: false
  })).then(function (data, textStatus, jqXHR) {
   var divHtml = $(data).filter('div#return_divId').html();
   $(thisElement).closest('div.extn_report_content').find('.live_display_data').empty().append(divHtml);
   $.getScript("includes/js/reload.js");
   $(thisElement).remove();
  });

 });

 $('body').off('click', '.extn_report_content .ino_sort_a_z').on('click', '.extn_report_content .ino_sort_a_z', function () {
  var fieldName = $(this).closest('th').data('field_name');
  var newSortField = '<span class="show_sort_remove show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + 'Sort Up';
  newSortField += '<input class="hidden sorted_field" type="hidden" value="' + 'sort_up' + '" name="' + fieldName + '"></span>';
  $(this).closest('div.extn_report_content').find('.extn_report_filters').append(newSortField);
  $(this).getReportResult_e();
 }).on('click', '.extn_report_content .ino_sort_z_a', function () {
  var fieldName = $(this).closest('th').data('field_name');
  var newSortField = '<span class="show_sort_remove show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + 'Sort Down';
  newSortField += '<input class="hidden sorted_field" type="hidden" value="' + 'sort_down' + '" name="' + fieldName + '"></span>';
  $(this).closest('div.extn_report_content').find('.extn_report_filters').append(newSortField);
  $(this).getReportResult_e();
 });


 $('body').off('click', '.draw_svg_image').on('click', '.draw_svg_image', function () {
  var thisElement = $(this);
  var filterData = $(this).closest('div.extn_report_content').find('.extn_report_filters').find('.filtered_field:input').serializeArray();
  var sortData = $(this).closest('div.extn_report_content').find('.extn_report_filters').find('.sorted_field:input').serializeArray();

  $.when(getSvgImage({
   extn_report_id: $(this).closest('div.extn_report_content').find('.extn_report_id').val(),
   chart_type: $(this).closest('div.extn_report_content').find('.chart_type').val(),
   chart_label: $(this).closest('div.extn_report_content').find('.chart_label').val(),
   chart_value: $(this).closest('div.extn_report_content').find('.chart_value').val(),
   chart_name: $(this).closest('div.extn_report_content').find('.chart_name').val(),
   chart_width: $(this).closest('div.extn_report_content').find('.chart_width').val(),
   chart_height: $(this).closest('div.extn_report_content').find('.chart_height').val(),
   chart_legend: $(this).closest('div.extn_report_content').find('.chart_legend').val(),
   filterData: filterData,
   sortData: sortData,
   update_image: false
  })).then(function (data, textStatus, jqXHR) {
   $(thisElement).closest('div.extn_report_content').find('.svg_image').empty().append(data);
  });

 });

 $('.extn_report_refresh_button').on('click', function () {
  $(this).getReportResult_e();
 });

});


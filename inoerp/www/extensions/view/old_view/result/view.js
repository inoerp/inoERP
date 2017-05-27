function getViewResult_i(filterData, sortData) {
 if (typeof filterData === 'undefined') {
  filterData = $('.view_filters').find('.filtered_field:input').serializeArray();
 }
 if (typeof sortData === 'undefined') {
  sortData = $('.view_filters').find('.sorted_field:input').serializeArray();
 }
 getViewResult({
  filterData: filterData,
  sortData: sortData,
  view_id: $('#view_id').val(),
  show_from_query: false
 });
}

$.fn.getViewResult_e = function(options) {
 var thisElement = $(this);
 var filterData = $(this).closest('div.view_content').find('.view_filters').find('.filtered_field:input').serializeArray();
 var sortData = $(this).closest('div.view_content').find('.view_filters').find('.sorted_field:input').serializeArray();
 $.when(getViewResult({
  filterData: filterData,
  sortData: sortData,
  view_id: $(this).closest('div.view_content').find('.view_id').val(),
  show_from_query: false,
  update_result: false
 })).then(function(data, textStatus, jqXHR) {
  var divHtml = $(data).filter('div#return_divId').html();
  $(thisElement).closest('div.view_content').find('.live_display_data').empty().append(divHtml);
  $.getScript("includes/js/reload.js");
 });
 return this;
};

$(document).ready(function() {
 $('table.view th').find('img').hide();
 $('.view_content').on('mouseenter', 'table.view th', function() {
  $(this).find('ul').addClass('icon_header');
  $(this).find('img').show();
 }).on('mouseleave', 'table.view th', function() {
  $(this).find('img').hide();
  $(this).find('ul').removeClass('icon_header');
 });

 $('.view_content').on('click', '.filter_add', function() {
  $(this).removeClass('show_add_filter');
  var fieldName = $(this).closest('ul').find('.field_value').text();
  var filter_value = prompt("Enter value for\n" + fieldName);
  var newDataField = '<span class="filtered_field show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + filter_value;
  newDataField += '<input class="hidden filtered_field" type="hidden" value="' + filter_value + '" name="' + $(this).closest('th').data('fieldname') + '"></span>';
  if (filter_value) {
   $(this).closest('div.view_content').find('.view_filters').append(newDataField);
   $(this).getViewResult_e();
  }
 });

 $('.view_filters').on('click', '.filtered_field, .show_sort_remove', function() {
  var thisElement = $(this);
  var filterData = $(this).closest('div.view_content').find('.view_filters .filtered_field').not(this).find(':input').not(this).serializeArray();
  var sortData = $(this).closest('div.view_content').find('.view_filters .sorted_field').not(this).find(':input').not(this).serializeArray();
  $.when(getViewResult({
   filterData: filterData,
   sortData: sortData,
   view_id: $(this).closest('div.view_content').find('.view_id').val(),
   show_from_query: false,
   update_result: false
  })).then(function(data, textStatus, jqXHR) {
   var divHtml = $(data).filter('div#return_divId').html();
   $(thisElement).closest('div.view_content').find('.live_display_data').empty().append(divHtml);
   $.getScript("includes/js/reload.js");
   $(thisElement).remove();
  });

 });

 $('.view_content').on('click', '.sort_up', function() {
  $(this).closest('th').addClass('show_sort_up');
  $(this).closest('th').removeClass('show_sort_down');
  var fieldName = $(this).closest('th').data('fieldname');
  var newSortField = '<span class="show_sort_remove show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + 'Sort Up';
  newSortField += '<input class="hidden sorted_field" type="hidden" value="' + 'sort_up' + '" name="' + fieldName + '"></span>';
  $(this).closest('div.view_content').find('.view_filters').append(newSortField);
  $(this).getViewResult_e();
 }).on('click', '.sort_down', function() {
  $(this).closest('th').addClass('show_sort_down');
  $(this).closest('th').removeClass('show_sort_up');
  var fieldName = $(this).closest('th').data('fieldname');
  var newSortField = '<span class="show_sort_remove show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + 'Sort Down';
  newSortField += '<input class="hidden sorted_field" type="hidden" value="' + 'sort_down' + '" name="' + fieldName + '"></span>';
  $(this).closest('div.view_content').find('.view_filters').append(newSortField);
  $(this).getViewResult_e();
 });


// $('.view_content').on('click', '.draw_svg_image', function() {
//  var thisElement = $(this);
//  var filterData = $(this).closest('div.view_content').find('.view_filters').find('.filtered_field:input').serializeArray();
//  var sortData = $(this).closest('div.view_content').find('.view_filters').find('.sorted_field:input').serializeArray();
//
//  $.when(getSvgImage({
//   view_id: $(this).closest('div.view_content').find('.view_id').val(),
//   chart_type: $(this).closest('div.view_content').find('.chart_type').val(),
//   chart_label: $(this).closest('div.view_content').find('.chart_label').val(),
//   chart_value: $(this).closest('div.view_content').find('.chart_value').val(),
//   chart_name: $(this).closest('div.view_content').find('.chart_name').val(),
//   chart_width: $(this).closest('div.view_content').find('.chart_width').val(),
//   chart_height: $(this).closest('div.view_content').find('.chart_height').val(),
//   chart_legend: $(this).closest('div.view_content').find('.chart_legend').val(),
//   filterData: filterData,
//   sortData: sortData,
//   update_image: false
//  })).then(function(data, textStatus, jqXHR) {
//   $(thisElement).closest('div.view_content').find('.svg_image').empty().append(data);
//  });
//
// });

 $('.view_refresh_button').on('click', function() {
  $(this).getViewResult_e();
 });

});


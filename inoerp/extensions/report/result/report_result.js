function getextn_reportResult_i(filterData, sortData) {
 if (typeof filterData === 'undefined') {
  filterData = $('.extn_report_filters').find('.filtered_field:input').serializeArray();
 }
 if (typeof sortData === 'undefined') {
  sortData = $('.extn_report_filters').find('.sorted_field:input').serializeArray();
 }
 getextn_reportResult({
  filterData: filterData,
  sortData: sortData,
  extn_report_id: $('#extn_report_id').val(),
  show_from_query: false
 });
}

$.fn.getextn_reportResult_e = function(options) {
 var thisElement = $(this);
 var filterData = $(this).closest('div.extn_report_content').find('.extn_report_filters').find('.filtered_field:input').serializeArray();
 var sortData = $(this).closest('div.extn_report_content').find('.extn_report_filters').find('.sorted_field:input').serializeArray();
 $.when(getextn_reportResult({
  filterData: filterData,
  sortData: sortData,
  extn_report_id: $(this).closest('div.extn_report_content').find('.extn_report_id').val(),
  show_from_query: false,
  update_result: false
 })).then(function(data, textStatus, jqXHR) {
  var divHtml = $(data).filter('div#return_divId').html();
  $(thisElement).closest('div.extn_report_content').find('.live_display_data').empty().append(divHtml);
  $.getScript("includes/js/reload.js");
 });
 return this;
};

$(document).ready(function() {
// $('table.extn_report th').find('img').hide();
// $('.extn_report_content').on('mouseenter', 'table.extn_report th', function() {
//  $(this).find('ul').addClass('icon_header');
//  $(this).find('img').show();
// }).on('mouseleave', 'table.extn_report th', function() {
//  $(this).find('img').hide();
//  $(this).find('ul').removeClass('icon_header');
// });

 $('.extn_report_content').on('click', '.ino_filter', function() {
//  $(this).removeClass('show_add_filter');
  var fieldName = $(this).closest('th').data('field_name');
  var filter_value = prompt("Enter value for\n" + fieldName);
  var newDataField = '<span class="filtered_field show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + filter_value;
  newDataField += '<input class="hidden filtered_field" type="hidden" value="' + filter_value + '" name="' + $(this).closest('th').data('field_name') + '"></span>';
  if (filter_value) {
   $(this).closest('div.extn_report_content').find('.extn_report_filters').append(newDataField);
   $(this).getextn_reportResult_e();
  }
 });

 $('.extn_report_filters').on('click', '.filtered_field, .show_sort_remove', function() {
  var thisElement = $(this);
  var filterData = $(this).closest('div.extn_report_content').find('.extn_report_filters .filtered_field').not(this).find(':input').not(this).serializeArray();
  var sortData = $(this).closest('div.extn_report_content').find('.extn_report_filters .sorted_field').not(this).find(':input').not(this).serializeArray();
  $.when(getextn_reportResult({
   filterData: filterData,
   sortData: sortData,
   extn_report_id: $(this).closest('div.extn_report_content').find('.extn_report_id').val(),
   show_from_query: false,
   update_result: false
  })).then(function(data, textStatus, jqXHR) {
   var divHtml = $(data).filter('div#return_divId').html();
   $(thisElement).closest('div.extn_report_content').find('.live_display_data').empty().append(divHtml);
   $.getScript("includes/js/reload.js");
   $(thisElement).remove();
  });

 });

 $('body').on('click', '.extn_report_content .ino_sort_a_z', function() {
  var fieldName = $(this).closest('th').data('field_name');
  var newSortField = '<span class="show_sort_remove show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + 'Sort Up';
  newSortField += '<input class="hidden sorted_field" type="hidden" value="' + 'sort_up' + '" name="' + fieldName + '"></span>';
  $(this).closest('div.extn_report_content').find('.extn_report_filters').append(newSortField);
  $(this).getextn_reportResult_e();
 }).on('click', '.extn_report_content .ino_sort_z_a', function() {
  var fieldName = $(this).closest('th').data('field_name');
  var newSortField = '<span class="show_sort_remove show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + 'Sort Down';
  newSortField += '<input class="hidden sorted_field" type="hidden" value="' + 'sort_down' + '" name="' + fieldName + '"></span>';
  $(this).closest('div.extn_report_content').find('.extn_report_filters').append(newSortField);
  $(this).getextn_reportResult_e();
 });


 $('body').on('click', '.draw_svg_image', function() {
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
  })).then(function(data, textStatus, jqXHR) {
   $(thisElement).closest('div.extn_report_content').find('.svg_image').empty().append(data);
  });

 });

 $('.extn_report_refresh_button').on('click', function() {
  $(this).getextn_reportResult_e();
 });

});


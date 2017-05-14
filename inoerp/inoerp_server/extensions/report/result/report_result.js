

$(document).ready(function () {

 $('#filter_area').off('click', '.apply-filter').on('click', '.apply-filter', function () {
  var inputFieldName = $(this).closest('.list_filter').find('select.field_name').val();
  var inputFieldCondition = $(this).closest('.list_filter').find('select.condition_name').val();
  var inputFieldValue = $(this).closest('.list_filter').find('input.condition_value').val();

  var filterHtml = ' ' + inputFieldName;
  filterHtml += ':' + inputFieldCondition;
  filterHtml += ' ' + inputFieldValue;
  var elementClass = 'applied-filter ' + inputFieldName;
  var elementToBeCloned = $('.applied_filters').last().clone().attr('data-field_name', inputFieldName).attr('class', elementClass);
  $(elementToBeCloned).find('button.toggle-filter').append(filterHtml);
  $('div.extn_report_content').find('.extn_report_filters').append(elementToBeCloned);

  var hiddenFieldValue = inputFieldCondition + inputFieldValue;
  var hiddenInput = '<input class="hidden extn_report_filters filtered_field ' + inputFieldName + ' " type="hidden" value="' + hiddenFieldValue + '" name="' + inputFieldName + '" form="generic_search_form">';
  $('div.extn_report_content').find('.extn_report_filters').append(hiddenInput);


  if (inputFieldValue) {
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

 $('.extn_report_filters').off('click', '.remove-sort-desc,.remove-sort-asc').on('click', '.remove-sort-desc,.remove-sort-asc', function (e) {
  e.preventDefault();
  var inputFieldName = $(this).closest('.applied-sorted_elements').data('field_name');
  var thisElement = $(this).closest('.extn_report_filters').find('input.hidden.sorted_field.' + inputFieldName)
  var thisElement_e = $(this);
  var filterData = $(this).closest('div.extn_report_content').find('.extn_report_filters .filtered_field').not(thisElement).find(':input').not(this).serializeArray();
  var sortData = $(this).closest('div.extn_report_content').find('.extn_report_filters .sorted_field').not(thisElement).find(':input').not(this).serializeArray();
  $.when(getReportResult({
   filterData: filterData,
   sortData: sortData,
   extn_report_id: $(this).closest('div.extn_report_content').find('.extn_report_id').val(),
   show_from_query: false,
   update_result: false
  })).then(function (data, textStatus, jqXHR) {
   var divHtml = $(data).filter('div#return_divId').html();
   $(thisElement_e).closest('div.extn_report_content').find('.live_display_data').empty().append(divHtml);
   $.getScript("includes/js/reload.js");
   $(thisElement_e).closest('div.extn_report_filters').find('.hidden.'+inputFieldName).remove();
   $(thisElement_e).closest('div.applied-sorted_elements').remove();
  });

 });

 $('body').off('click', '.extn_report_content .ino_sort_a_z').on('click', '.extn_report_content .ino_sort_a_z', function () {
  var inputFieldName = $(this).closest('th').data('field_name');
  var newSortField = '<input class="hidden sorted_field sorted_field_asc ' + inputFieldName + ' " type="hidden" value="' + 'sort_up' + '" name="' + inputFieldName + '">';
  $(this).closest('div.extn_report_content').find('.extn_report_filters').append(newSortField);
  var elementClass = 'applied-sorted_elements ' + inputFieldName;
  var elementToBeCloned = $('.sorted_elements_asc').last().clone().attr('data-field_name', inputFieldName).attr('class', elementClass);
  $(elementToBeCloned).find('.toggle-sort-asc').append(' ' + inputFieldName);
  $(this).closest('div.extn_report_content').find('.extn_report_filters').append(elementToBeCloned);
  $(this).getReportResult_e();
 }).on('click', '.extn_report_content .ino_sort_z_a', function () {
  var inputFieldName = $(this).closest('th').data('field_name');
  var newSortField = '<input class="hidden sorted_field sorted_field_desc ' + inputFieldName + ' " type="hidden" value="' + 'sort_down' + '" name="' + inputFieldName + '">';
  $(this).closest('div.extn_report_content').find('.extn_report_filters').append(newSortField);
  var elementClass = 'applied-sorted_elements ' + inputFieldName;
  var elementToBeCloned = $('.sorted_elements_desc').last().clone().attr('data-field_name', inputFieldName).attr('class', elementClass);
  $(elementToBeCloned).find('.toggle-sort-desc').append(' ' + inputFieldName);
  $(this).closest('div.extn_report_content').find('.extn_report_filters').append(elementToBeCloned);
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
   chart_value: $(this).closest('div.extn_report_content').find('.parameter.chart_value').val(),
   chart_name: $(this).closest('div.extn_report_content').find('.chart_name').val(),
   chart_width: $(this).closest('div.extn_report_content').find('.chart_width').val(),
   chart_height: $(this).closest('div.extn_report_content').find('.chart_height').val(),
   chart_legend: $(this).closest('div.extn_report_content').find('.chart_legend').val(),
   chart_legend2: $(this).closest('div.extn_report_content').find('.chart_legend2').val(),
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


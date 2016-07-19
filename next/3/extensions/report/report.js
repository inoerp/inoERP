$(document).ready(function(){
  $('body').off('click', '#display_report_result').on('click', '#display_report_result', function () {
  getReportResult();
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
  $('body').off('click', '#draw_svg_image').on('click', '#draw_svg_image', function () {
  getSvgImage();
 });

});
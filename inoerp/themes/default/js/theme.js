$(document).ready(function () {
 $('body').on('click', '#dashborad_menu a', function () {
  $('#structure').css({
   visibility: 'hidden'
  });
  var bgColor = $(this).closest('li').css('background-color');

  var faClass = $(this).closest('li').find('i').attr('class');
  $('#overlay').css('background-color', bgColor);
  $('#overlay').removeClass();
  $('#overlay').addClass(faClass);
  var newStyle = $('<style>#path_by_module ul.child_menu > li > a { background-color: ' + bgColor + '; } #path_by_module ul.child_menu > li { border-color: ' + bgColor + '; }</style>');
  $('html > head').append(newStyle);
 });

 $('body').on('click', '.panel-heading.dashboard a', function () {
  $('#structure').css({
   visibility: 'hidden'
  });
  $('#overlay').removeClass();
  $('#overlay').addClass('fa fa-dashboard');
 });

 $('body').on('click', '#path_by_module a, .ino-breadcrumb-simple a', function () {
  $('#structure').css({
   visibility: 'hidden'
  });
 });
});

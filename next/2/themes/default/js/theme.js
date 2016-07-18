function hideOverLay() {
 var ramNumber = Math.random() * 7;
 var options = {to: {width: 200, height: 60}};
 if (ramNumber > 6) {
  var selectedEffect = 'size';
 } else if (ramNumber > 4) {
  var selectedEffect = 'clip';
 } else if (ramNumber > 3) {
  var selectedEffect = 'fold';
 } else if (ramNumber > 1) {
  var selectedEffect = 'scale';
 } else {
  var selectedEffect = 'slide';
 }
 $('#overlay').hide(selectedEffect, options, 300);
}

function rotate($elie) {
 var degree = 0, timer;
 $elie.css({WebkitTransform: 'rotate(' + degree + 'deg)'});
 $elie.css({'-moz-transform': 'rotate(' + degree + 'deg)'});
 timer = setTimeout(function () {
  ++degree;
  rotate();
 }, 5);
}

function animateSize(options) {
 var defaults = {
  div_element: '#overlay.fa.fa-dashboard',
  muliple: 2,
  animation_interval: '400'
 };
 var settings = $.extend({}, defaults, options);

 var intial_font_size = $(settings.div_element).css('font-size');
 var intial_font_size_val = +intial_font_size.replace(/px/g, '');
 var final_font_size_val = settings.muliple * intial_font_size_val;
 var animateContent = function () {
  $(settings.div_element).animate({
   fontSize: final_font_size_val
  }, function () {
   $(settings.div_element).animate({
    fontSize: intial_font_size
   });
  });
 };
 setInterval(animateContent, settings.animation_interval);
}

$(document).ready(function () {
 $('body').on('click', '#dashborad_menu a', function () {
  $('#structure').css({
   visibility: 'hidden'
  });
  var bgColor = $(this).closest('li').css('background-color');
  var faClass = $(this).closest('li').find('i').attr('class');
  $('#overlay ').css({
   backgroundColor : bgColor
  });
  $('#overlay a').css({
   fontFamily: "Lato"
  });
  $('#overlay').attr('data-actionmsg' , 'Loading...');
  $('#overlay').removeClass();
  $('#overlay').addClass(faClass);
  var newStyle = $('<style>#path_by_module ul.child_menu > li > a { background-color: ' + bgColor + '; } #path_by_module ul.child_menu > li { border-color: ' + bgColor + '; }</style>');
  $('html > head').append(newStyle);
 });

 $('body').on('click', '.panel-heading.dashboard a', function () {
  $('#structure').css({
   visibility: 'hidden'
  });
  $('#overlay').attr('data-actionmsg' , 'Loading...');
  $('#overlay').removeClass();
  $('#overlay').css({
   minHeight: '1200px'
  });
  $('#overlay').addClass('fa fa-dashboard').css({
   opacity :  1
  });
//  animateSize();
 });

 $('body').on('click', '#path_by_module a, .ino-breadcrumb-simple a', function () {
  $('#structure').css({
   visibility: 'hidden'
  });
 });
 
// $('body').on('click', '#save', function(){
//  $('#overlay').attr('data-actionmsg' , 'Saving...');
// });
});
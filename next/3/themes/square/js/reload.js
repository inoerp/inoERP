$(document).ready(function(){
  $('.tabMain').each(function () {
  var li_len_p = 100 / +($(this).find('li').length) + '%';
  $(this).find('li').css('width', li_len_p);

 }); 
});
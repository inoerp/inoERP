
$(document).ready(function () {
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }
 
 $('body').off('setInoVal',  '#content').on('setInoVal',  '#content', function(){
  if($('#prj_project_header_id').val()){
   $('.prj_project_header_id').val($('#prj_project_header_id').val());
  }
  
 });

});
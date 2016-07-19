$(document).ready(function(){
 $('body').off('change', '#frequency_uom').on('change', '#frequency_uom' , function(){
  if($(this).val()== 'CALENDAR'){
     $('#frequency_value').prop('readonly', true).css('background-color', '#F3F3D2');
  }else{
   $('#frequency_value').prop('readonly', false).css('background-color', '#FFF');}
});
 
});
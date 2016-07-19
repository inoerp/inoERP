$(document).ready(function() {
$('body').off('click', '.default_cb').on('click', '.default_cb' , function(){
  if($(this).prop('checked')){
  
  $('.default_cb').prop('checked', false);
  $(this).prop('checked', true);
  }
});

//Name Value
$('#content').on('click', '.uninstall_cb', function(){
if(!$(this).prop('checked')){
return;
}
var trClass = '.'+$(this).closest('tr').prop('class');
var installStatus = $('#form_line').find(trClass).find('.installed_cb').prop('checked');
var enableStatus = $('#form_line').find(trClass).find('.enabled_cb').prop('checked');
if( installStatus === true && enableStatus === false){
alert('System \'ll remove all data & drop all the tables in this module!');
alert('Uninstall is disabled due to security reasons');
}else{
alert('You can only uninstall a module that is installed but disabled!');
$(this).prop('checked', false);
}
});



});  
$(document).ready(function () {
 $('body').off('click', '[id*="menu_button4"]').on('click', '[id*="menu_button4"]', function () {
  $('#header_amount, #tax_amount').val('');
 });
 

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }
$('body').off('blur' , '#percent' ).on('blur' , '#percent' , function(){
  if(+$(this).val() < $('#percent_old').val()){
  alert('You cann\'t reduce completion percentage');
    $(this).val($('#percent_old').val());
  }
});


$('body').off('blur' , '#as_of_date' ).on('blur' , '#as_of_date' , function(){
  if(+$(this).val() < $('#as_of_date_old').val()){
  alert('You cann\'t enter an old as of date');
    $(this).val($('#as_of_date').val());
  }
});

});
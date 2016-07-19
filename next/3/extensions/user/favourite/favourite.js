function setValFromSelectPage( combination) {
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
$('#content').on('blur', '.select.path_id', function(){
  if($(this).val() == 'newentry'){
  $(this).closest('tr').find('.external_link').attr('readonly', false);
  }else{
  $(this).closest('tr').find('.external_link').attr('readonly', true);
  }
  $(this).closest('tr').find('.fav_name').val($(this).find(':selected').text());
  });



});  
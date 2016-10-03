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
// var Mandatory_Fields = ["#org_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').on('focusout', '.year', function() {
	var name = '';
	name += $(this).closest('tr').find('.name_prefix').val();
	name += '-' + $(this).val();
	$(this).closest('tr').find('.name').val(name);
 });
 
 $('#ship_to_address_id').on('change', function(){
  var new_Address = '<div class="panel-body">';
  var new_Address_text = $(this).find(':selected').text();
  var new_Address_text_a = new_Address_text.split('|');
  $(new_Address_text_a).each(function(k, v){
    if(v.length > 2){
    new_Address += '<li>' + v + '</li>';
    } 
  });
  new_Address += '<li class="hidden"><input class="hidden address_id ship_to_address_id" name="ship_to_address_id[]" value="'+$(this).val()+'" type="hidden"></li>';
  new_Address += '</div>';
  $('#selected_ship_to_address').find('.panel-body').replaceWith(new_Address);
});

});  
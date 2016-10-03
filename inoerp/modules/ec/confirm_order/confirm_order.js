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
 
$('body').off('change', '#ship_to_address_id').on('change', '#ship_to_address_id' , function(){
  var new_Address = '<div class="panel-body">';
  new_Address_text = $(this).find(':selected').text();
  new_Address_text_a = new_Address_text.split('|');
  $(new_Address_text_a).each(function(k, v){
    if(v.length > 2){
    new_Address += '<li>' + v + '</li>';
    } 
  });
  new_Address += '<li class="hidden"><input class="hidden address_id ship_to_address_id" name="ship_to_address_id[]" value="'+$(this).val()+'" type="hidden"></li>';
  new_Address += '</div>';
  $('#selected_ship_to_address').find('.panel-body').replaceWith(new_Address);
  
  var new_link = 'form.php?class_name=address&mode=9&window_type=popup&ref_class_name=ec_confirm_order&address_id=' + $(this).val() ;
  $(this).parent().find('#existing-address-details a.view-addrees').attr('href', new_link);
});

$('body').off('change', '#bill_to_address_id').on('change', '#bill_to_address_id' , function(){
  var new_Address = '<div class="panel-body">';
  new_Address_text = $(this).find(':selected').text();
  new_Address_text_a = new_Address_text.split('|');
  $(new_Address_text_a).each(function(k, v){
    if(v.length > 2){
    new_Address += '<li>' + v + '</li>';
    } 
  });
  new_Address += '<li class="hidden"><input class="hidden address_id bill_to_address_id" name="bill_to_address_id[]" value="'+$(this).val()+'" type="hidden"></li>';
  new_Address += '</div>';
  $('#selected_bill_to_address').find('.panel-body').replaceWith(new_Address);
  
  var new_link = 'form.php?class_name=address&mode=9&window_type=popup&ref_class_name=ec_confirm_order&address_id=' + $(this).val() ;
  $(this).parent().find('#existing-address-details a.view-addrees').attr('href', new_link);
});


});  
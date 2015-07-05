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

$('body').on('blur', '#ec_cart_line .quantity', function(){
var qnty = $(this).val();
var unit_price = +$(this).closest('tr').find('.unit-price-value').html();
var line_price = qnty * unit_price;
  $(this).closest('tr').find('.line-price-value').html(' ' + line_price + ' ');
  var total_line_p = 0;
  $('.line-price-value').each(function(){
  var line_p = + $(this).html();
    total_line_p += line_p;
  });
  var tax_amount = +$('.hidden.tax_amount').val();
  var total_amount = tax_amount + total_line_p;
  $('.hidden.total_amount').val(total_amount);
  $('.total-amount').html(total_amount);
})
});  
function setValFromSelectPage(address_name, address_id) {
 this.address_name = address_name;
 this.address_id = address_id;
}

setValFromSelectPage.prototype.setVal = function() {
  var fieldClass = '.' + localStorage.getItem("field_class").replace(/\s+/,'.');
  fieldClass = fieldClass.replace(/\s+/g, '.');
 if (this.address_name) {
	$('body').find(fieldClass).parent().find('.address_name').val(this.address_name);
  $('body').find(fieldClass).val(this.address_id);
 }
};



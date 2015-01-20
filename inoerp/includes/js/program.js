function setValFromSelectPage(item_id, item_number, item_description, uom_id,
        combination, sourcing_rule) {
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.combination = combination;
 this.sourcing_rule = sourcing_rule;
 }

setValFromSelectPage.prototype.setVal = function () {
 var item_number = this.item_number;
 var combination = this.combination;
 var sourcing_rule = this.sourcing_rule;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 var li_field_id = '#' + localStorage.getItem("li_divId");

 if (this.item_number) {
  $(li_field_id).val(this.item_number);
  localStorage.removeItem("li_divId");
 }
 
  if (this.item_id_m) {
  $('#content').find(li_field_id).val(this.item_id_m);
  localStorage.removeItem("li_divId");
 }
 
 
 if (combination) {
  $('#content').find(fieldClass).val(combination);
  localStorage.removeItem("field_class");
 }

 if (sourcing_rule) {
  $('#content').find('.sourcing_rule').val(sourcing_rule);
 }
 

};

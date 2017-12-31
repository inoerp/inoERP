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

 var item_obj = [{id: 'item_id', data: this.item_id},
  {id: 'item_number', data: this.item_number},
  {id: 'item_description', data: this.item_description},
  {id: 'uom_id', data: this.uom_id}
 ];

 if (combination) {
  $('body').find(fieldClass).val(combination);
  localStorage.removeItem("field_class");
 }

 if (sourcing_rule) {
  $('body').find('.sourcing_rule').val(sourcing_rule);
 }
 
 if (localStorage.getItem("item_type") === 'template') {
  if (item_number) {
   $("#item_template").val(item_number);
  }
 } else {
    $(item_obj).each(function (i, value) {
   if (value.data) {
    var fieldId = '#' + value.id;
    $('body').find(fieldId).val(value.data);
   }
  });
   if(this.item_id){
    $('#item_id').val(this.item_id);
  $('a.show.item_id').trigger('click');
 }
 }
 localStorage.removeItem("item_type");

};

$(document).ready(function () {
 //creating tabs
 $(function () {
  $("#tabsHeader").tabs();
  $("#tabsLine").tabs();
 });

 $("body").on('click', '#menu_button4', function () {
  $('#item_id_m').val('');
 });
 
 
 $('body').off('click', 'a.findBy_item_number').on('click', 'a.findBy_item_number', function (e) {
  e.preventDefault();
  var item_number = $('#item_number').val();
  var org_id = $('#org_id').val();
  var itemDefined = false;
  $('#inventory_assignment').find('li :checked').each(function () {
   if ($(this).closest('li').data('org_id') == org_id) {
    itemDefined = true;
    return;
   }
  });
  if (itemDefined) {
   if (org_id) {
    var urlLink = $(this).attr('href');
    var urlLink_a = urlLink.split('?');
    var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&item_number=' + item_number + '&org_id=' + org_id;
    getFormDetails(formUrl);
   } else {
    e.preventDefault();
    alert("Select the Organization or Query by item_id ");
   }
  } else {
   e.preventDefault();
   alert('Item is not defined in the organization.Select a different organization');
  }
 });

});
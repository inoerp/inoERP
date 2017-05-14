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
   $('#template_item_id').val(this.item_id);
  }
 } else {
  $(item_obj).each(function (i, value) {
   if (value.data) {
    var fieldId = '#' + value.id;
    $('body').find(fieldId).val(value.data);
   }
  });
  if (this.item_id) {
   $('#item_id').val(this.item_id);
   $('a.show.item_id').trigger('click');
  }
 }
 localStorage.removeItem("item_type");

};

function applyTemplate() {
 var itemNumber = $('#item_template').val();
 var orgId = $('#org_id').val();
 return $.ajax({
  url: 'includes/json/json_form.php',
  type: 'get',
  data: {
   class_name: 'item',
   mode: '9',
   item_number: itemNumber,
   item_id: $('#template_item_id').val(),
   org_id: orgId
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  if (result) {
   $(result).find('#form_line').find(':input').each(function () {
    if ($(this).val()) {
     if ($(this).prop('class').length > 1) {
      var asisClass = '.' + $(this).prop('class').trim();
      var asisClass_d = asisClass.replace(/\s+/g, '.');
      if (('#content ' + asisClass_d).length > 0) {
       $('#content').find(asisClass_d).val($(this).val());
      }
     }
    }
   });
  }
 }).fail(function () {
  alert("Template update failed");
 });
}



//get subinventory
function itemGetSubinventory() {

}

$(document).ready(function () {
 //creating tabs
 $(function () {
  $("#tabsHeader").tabs();
  $("#tabsLine").tabs();
 });

 $("body").on('click', '#menu_button4', function () {
  $('#item_id_m').val('');
 });

 $('#org_id,.disable_autocomplete.item_number').on('change', function () {
  $('#item_id').val('');
 });
 $(".item_id.select_popup, .select_item_template").on("click", function () {
  if ($(this).hasClass('select_item_template')) {
   localStorage.setItem("item_type", 'template');
  } else {
   localStorage.setItem("item_type", 'item');
  }
  void window.open('select.php?class_name=item', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('#content').on('click', '.select_sourcing_rule', function () {
  void window.open('select.php?class_name=po_sourcing_rule_header', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');

 });

 $('body').off('blur', '#org_id').on('blur', '#org_id', function () {
  var org_id = $(this).val();
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: org_id
  });
  getTaxCodes('modules/mdm/tax_code/json_tax_code.php', org_id, 'IN');
  getTaxCodes('modules/mdm/tax_code/json_tax_code.php', org_id, 'OUT');
 });

 //get locatot on Subinventory change
 $('body').off('change', '.wip_supply_subinventory').on('change', '.wip_supply_subinventory', function () {
  var subInventoryId = $(this).val();
  if (subInventoryId > 0) {
   getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'oneSubinventory', '');
  }
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

//
 $('#item').off('change', '.inventory_item_cb').on('change', '.inventory_item_cb', function () {
  if (!$(this).is(":checked")) {
   $('.stockable_cb,.transactable_cb,.reservable_cb,.cycle_count_enabled_cb').prop('checked', false).prop('disabled', true);
  } else {
   $('.stockable_cb,.transactable_cb,.reservable_cb').prop('checked', true).prop('disabled', false);
  }
 });

 $('#item').off('change', '.customer_ordered_cb').on('change', '.customer_ordered_cb', function () {
  if (!$(this).is(":checked")) {
   $('.internal_ordered_cb,.shippable_cb,.returnable_cb').prop('checked', false).prop('disabled', true);
  } else {
   $('.internal_ordered_cb,.shippable_cb,.returnable_cb').prop('checked', true).prop('disabled', false);
  }
 });



//select template
 var itemTemplate = new autoCompleteMain();
 itemTemplate.json_url = 'modules/inv/item/item_search.php';
 itemTemplate.select_class = 'select_item_template';
 itemTemplate.min_length = 2;
 itemTemplate.autoComplete();

 $('#apply_item_template').on('click', function () {
  applyTemplate();
 });
 onClick_add_new_row('tr.inv_item_revision0', 'tbody.form_data_line_tbody', 1);

 $('body').off('change', '#assign_to_org').on('change', '#assign_to_org', function () {
  $('#org_id').val($(this).val());
  $('#item_id').val('');
 });

 $('body').off('click', '#menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4_2, #menu_button4_2_1', function () {
  $('#org_id, #item_id_m').val('');
  $('.disable_autocomplete').trigger('click');
  $('#org_id').find('option').each(function () {
   if ($(this).data('item_master_cb') != 1) {
    $(this).remove();
   }
  });
 });

});




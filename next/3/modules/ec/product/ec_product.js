function setValFromSelectPage(ec_product_id, asset_number, item_id_m, item_number, item_description, address_id,
        address_name) {
 this.ec_product_id = ec_product_id;
 this.asset_number = asset_number;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.address_id = address_id;
 this.address_name = address_name;
}

setValFromSelectPage.prototype.setVal = function () {
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');

 if (this.ec_product_id) {
  $("#ec_product_id").val(this.ec_product_id);
 }
 if (this.asset_number) {
  $("#asset_number").val(this.asset_number);
 }

 if (this.ec_product_id) {
  $("#ec_product_id").val(this.ec_product_id);
 }
 if (this.asset_number) {
  $("#asset_number").val(this.asset_number);
 }

 if (this.address_id) {
  $("#address_id").val(this.address_id);
 }
 if (this.address_name) {
  $("#address_name").val(this.address_name);
 }

 if (localStorage.getItem("li_divId")) {
  var li_divId = '#' + localStorage.getItem("li_divId");
  var item_obj = [{id: 'item_id_m', data: this.item_id_m},
   {id: 'item_number', data: this.item_number},
   {id: 'item_description', data: this.item_description}
  ];
  $(item_obj).each(function (i, value) {
   if (value.data) {
    var fieldId = '#' + value.id;
    $('#content').find(fieldId).val(value.data);
   }
  });
 } else {
  var item_obj = [{id: 'activity_item_id_m', data: this.item_id_m},
   {id: 'activity_item_number', data: this.item_number}
  ];

  $(item_obj).each(function (i, value) {
   if (value.data) {
    var fieldClass = '.' + value.id;
    $('#content').find(rowClass).find(fieldClass).val(value.data);
   }
  });
 }
 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");
 localStorage.removeItem("li_divId");
};



$(document).ready(function () {
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.mandatoryHeader();

 //selecting Id
 $(".ec_product_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=ec_product', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //get Subinventory Name
 $('body').off("change", '#org_id').on("change", '#org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $("#org_id").val()
  });
 });


 //get locatot on Subinventory change in form header
 $('body').off('change', '.subinventory_id').on('change', '.subinventory_id', function () {
  var subInventoryId = $(this).val();
  if (subInventoryId > 0) {
   getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'oneSubinventory', '');
  }
 });

 $('body').off('change', '#price_list').on('change', '#price_list', function () {
  if ($(this).val()) {
   $('.list_price, .sales_price,sp_form_date,.sp_to_date').prop('readonly', true).val('').addClass('readonly');
  } else {
   $('.list_price, .sales_price,sp_form_date,.sp_to_date').prop('readonly', false).removeClass('readonly');
  }
 });

});
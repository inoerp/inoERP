function setValFromSelectPage(am_asset_id, asset_number) {
 this.am_asset_id = am_asset_id;
 this.asset_number = asset_number;
}

setValFromSelectPage.prototype.setVal = function () {
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');

 if (this.am_asset_id) {
  $("#am_asset_id").val(this.am_asset_id);
 }
 if (this.asset_number) {
  $("#am_asset_number").val(this.asset_number);
 }

 if (localStorage.getItem("li_divId")) {
  var li_divId = '#' + localStorage.getItem("li_divId");
  var item_obj = [{id: 'item_id_m', data: this.item_id_m},
   {id: 'item_number', data: this.item_number}
  ];
  $(item_obj).each(function (i, value) {
   if (value.data) {
    var fieldId = '#' + value.id;
    $('#content').find(fieldId).val(value.data);
   }
  });
 } else {
  var item_obj = [
   {id: 'activity_item_id_m', data: this.item_id_m},
   {id: 'activity_item_number', data: this.item_number}
  ];

  $(item_obj).each(function (i, value) {
   if (value.data) {
    var fieldClass = '.' + value.id;
    $('body').find(rowClass).find(fieldClass).val(value.data);
   }
  });
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("li_divId");

};



$(document).ready(function () {

  $('body').off('click', 'a.sys_catalog_header_id').on('click', 'a.sys_catalog_header_id', function (e) {
  e.preventDefault();
  var reference_id = $('#reference_id').val();
  var reference_table = $('#reference_table').val();
  var sys_catalog_header_id = $('#sys_catalog_header_id').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&sys_catalog_header_id=' + sys_catalog_header_id + '&reference_table=' + reference_table + '&reference_id=' + reference_id;
  getFormDetails(formUrl);
 }).one();

});
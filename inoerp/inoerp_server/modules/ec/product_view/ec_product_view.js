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
 //Rating
 $('body').on('mouseenter', '.ratings_stars', function () {
  $(this).prevAll().andSelf().removeClass('fa-star-o').addClass('ratings_vote fa-star');
  $(this).nextAll().removeClass('ratings_vote');
 }).on('mouseout', '.ratings_stars', function () {
  $(this).prevAll().andSelf().removeClass('ratings_vote fa-star').addClass('fa-star-o');
 }).on('click', '.ratings_stars', function () {
  var rating = $(this).data('rating');
  console.log(rating);
  save_ratings({
   rating: rating,
   reference_table: $('#class_name').val(),
   reference_id: $('#ec_product_id').val()
  });
 });
 
 
 $('body').on('click','.filter-checkbox', function(){
var current_url = $('#current_page_url').val();
  $(this).closest('.vertical-list').find('.filter-checkbox:checked').each(function(){
  var sc_line_id = $(this).closest('li').data('sys_catalog_line_id');
  var sc_line_id_val = $(this).closest('li').data('sys_catalog_line_id_value');
    current_url += '&sys_catalog_line_id[]=' + sc_line_id + '&sys_catalog_line_id_value[]=' + sc_line_id_val;
  });
window.location.assign(current_url);
})

});
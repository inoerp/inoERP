function setValFromSelectPage(address_id, tax_region_name) {
 this.address_id = address_id;
 this.tax_region_name = tax_region_name;
}

setValFromSelectPage.prototype.setVal = function () {
 var address_id = this.address_id;
 var tax_region_name = this.tax_region_name;

 if (tax_region_name) {
  $("#tax_region_name").val(tax_region_name);
 }
 if (address_id) {
  $("#address_id").val(address_id);
 }
};

$(document).ready(function () {

 //selecting Id
 $(".address.select_popup").on("click", function () {
  void window.open('select.php?class_name=address', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Tax Region Id
 $(".tax_region_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=mdm_tax_region', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 $('body').off('click', 'a.show2.address_id').on('click', 'a.show2.address_id', function (e) {
  e.preventDefault();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var address_id = $('#address_id').val();
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&address_id=' + address_id ;
  if ($('#window_type').val()) {
    formUrl += '&window_type=' + $('#window_type').val();
  }
  getFormDetails(formUrl);
 }).one();

});


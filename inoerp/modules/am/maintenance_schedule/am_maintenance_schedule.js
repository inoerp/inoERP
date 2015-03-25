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
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.mandatoryHeader();

 $('body').off('click', '.popup-form.view-date-rule').on('click', '.popup-form.view-date-rule', function (e) {
  e.preventDefault();
  var openUrl = $(this).prop('href');
  void window.open(openUrl, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
  $('body').off('click', '.popup-form.view-meter-rule').on('click', '.popup-form.view-meter-rule', function (e) {
  e.preventDefault();
  var openUrl = $(this).prop('href');
  void window.open(openUrl, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
   $('body').off('click', '.popup-form.view-calendar-date').on('click', '.popup-form.view-calendar-date', function (e) {
  e.preventDefault();
  var openUrl = $(this).prop('href');
  void window.open(openUrl, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
 
 $('body').off('blur', '.interval_multiple').on('blur', '.interval_multiple' , function(){
  if(+$(this).val() > + $('#intervals_per_cycle').val() ){
    $(this).val('');
  alert('Interval Multiple should be less than equal to Intervals Per Cycle');
  }
});

});
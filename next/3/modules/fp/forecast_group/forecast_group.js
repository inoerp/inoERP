function setValFromSelectPage(fp_forecast_group_id, valuation_name) {
 this.fp_forecast_group_id = fp_forecast_group_id;
 this.valuation_name = valuation_name;
}


setValFromSelectPage.prototype.setVal = function () {
 var fp_forecast_group_id = this.fp_forecast_group_id;
 var valuation_name = this.valuation_name;
 if (fp_forecast_group_id) {
  $("#fp_forecast_group_id").val(fp_forecast_group_id);
 }
 if (valuation_name) {
  $("#valuation_name").val(valuation_name);
 }
   if (fp_forecast_group_id) {
  $('a.show.fp_forecast_group_id').trigger('click');
 }
};

$(document).ready(function () {
 //selecting Id
 $('#fp_forecast_group_divId').off("click", '.fp_forecast_group_id.select_popup')
         .on("click", '.fp_forecast_group_id.select_popup', function () {
          void window.open('select.php?class_name=fp_forecast_group', '_blank',
                  'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
         });

});

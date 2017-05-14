function setValFromSelectPage(fp_forecast_group_id, valuation_name ) {
 this.fp_forecast_group_id = fp_forecast_group_id;
 this.valuation_name = valuation_name;
}


setValFromSelectPage.prototype.setVal = function() {
 var fp_forecast_group_id = this.fp_forecast_group_id;
 var valuation_name = this.valuation_name;
 if (fp_forecast_group_id) {
	$("#fp_forecast_group_id").val(fp_forecast_group_id);
 }
 if (valuation_name) {
	$("#valuation_name").val(valuation_name);
 }
};

$(document).ready(function() {
 //selecting Id
 $(".fp_forecast_group_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=fp_forecast_group', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the fp_forecast_group_id on find button click
 $('a.show.fp_forecast_group_id').click(function() {
	var fp_forecast_group_id = $('#fp_forecast_group_id').val();
	$(this).attr('href', modepath() + 'fp_forecast_group_id=' + fp_forecast_group_id);
 });

});

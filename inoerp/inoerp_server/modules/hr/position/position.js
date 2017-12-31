function setValFromSelectPage(hr_position_id) {
 this.hr_position_id = hr_position_id;
 }


setValFromSelectPage.prototype.setVal = function() {
 var hr_position_id = this.hr_position_id;
 if (hr_position_id) {
	$("#hr_position_id").val(hr_position_id);
 }
};

$(document).ready(function() {
 //selecting Id
 $(".hr_position_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_position', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

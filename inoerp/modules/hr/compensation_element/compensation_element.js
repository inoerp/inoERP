function setValFromSelectPage(hr_compensation_element_id) {
 this.hr_compensation_element_id = hr_compensation_element_id;
 }


setValFromSelectPage.prototype.setVal = function() {
 var hr_compensation_element_id = this.hr_compensation_element_id;
 if (hr_compensation_element_id) {
	$("#hr_compensation_element_id").val(hr_compensation_element_id);
 }
};

$(document).ready(function() {
 //selecting Id
 $(".hr_compensation_element_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_compensation_element', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

// //Get the hr_compensation_element_id on find button click
// $('a.show.hr_compensation_element_id').click(function() {
//	var hr_compensation_element_id = $('#hr_compensation_element_id').val();
//	$(this).attr('href', modepath() + 'hr_compensation_element_id=' + hr_compensation_element_id);
// });

});

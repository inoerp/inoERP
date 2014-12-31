function setValFromSelectPage(hr_job_id, combination) {
 this.hr_job_id = hr_job_id;
 this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var hr_job_id = this.hr_job_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (hr_job_id) {
	$("#hr_job_id").val(hr_job_id);
 }
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
 //selecting Id
 $(".hr_job_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_job', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

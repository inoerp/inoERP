function setValFromSelectPage(hr_empoyee_id, combination) {
 this.hr_empoyee_id = hr_empoyee_id;
 this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var hr_empoyee_id = this.hr_empoyee_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (hr_empoyee_id) {
	$("#hr_empoyee_id").val(hr_empoyee_id);
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
 $(".hr_empoyee_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_empoyee', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the hr_empoyee_id on find button click
 $('a.show.hr_empoyee_id').click(function() {
	var hr_empoyee_id = $('#hr_empoyee_id').val();
	$(this).attr('href', modepath() + 'hr_empoyee_id=' + hr_empoyee_id);
 });

});

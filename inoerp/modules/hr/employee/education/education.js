function setValFromSelectPage( combination) {
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
// var Mandatory_Fields = ["#employee_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').on('focusout', '.year', function() {
	var name = '';
	name += $(this).closest('tr').find('.name_prefix').val();
	name += '-' + $(this).val();
	$(this).closest('tr').find('.name').val(name);
 });

////Get the employee_education_id on find button click
// $('a.show.hr_employee_education').click(function() {
//	var headerId = $('#employee_id').val();
//	$(this).prop('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class_name=hr_employee_education&employee_id=' + headerId);
// });


// onClick_add_new_row('tr.employee_education_line0', 'tbody.employee_education_values', 2);
 
// deleteData('json_employee_education.php');
deleteData('form.php?class_name=hr_employee_education&line_class_name=hr_employee_education');

// //context menu
// var classContextMenu = new contextMenuMain();
//  classContextMenu.docLineId = 'hr_employee_education_id';
// classContextMenu.btn2DivId = 'form_line';
// classContextMenu.trClass = 'employee_education_line';
// classContextMenu.tbodyClass = 'form_data_line_tbody';
// classContextMenu.noOfTabbs = 2;
//// classContextMenu.contextMenu();
// 
// var employee_educationSave = new saveMainClass();
// employee_educationSave.json_url = 'form.php?class_name=hr_employee_education';
// employee_educationSave.single_line = false;
// employee_educationSave.line_key_field = 'employee_id';
// employee_educationSave.form_line_id = 'hr_employee_education';
// employee_educationSave.saveMain();

});  
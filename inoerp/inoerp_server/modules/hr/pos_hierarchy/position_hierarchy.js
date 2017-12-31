function setValFromSelectPage(hr_pos_hierarchy_header_id) {
 this.hr_pos_hierarchy_header_id = hr_pos_hierarchy_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var hr_pos_hierarchy_header_id = this.hr_pos_hierarchy_header_id;
 $("#hr_pos_hierarchy_header_id").val(hr_pos_hierarchy_header_id);
};

$(document).ready(function() {

 //setting the first line number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('10');
 }

 //Popup for selecting bom
 $(".hr_pos_hierarchy_header_id.select_popup").click(function() {
	void window.open('select.php?class_name=hr_pos_hierarchy_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

// //Get the bom_id on find button click
// $('#form_header a.show.hr_pos_hierarchy_header_id').click(function() {
//	var headerId = $('#hr_pos_hierarchy_header_id').val();
//	$(this).attr('href', modepath() + 'hr_pos_hierarchy_header_id=' + headerId);
// });
//
// //add a new row
//// onClick_add_new_row('tr.hr_pos_hierarchy_line0', 'tbody.form_data_line_tbody', 3);
// $("#content").on("click", ".add_row_img", function() {
//	var addNewRow = new add_new_rowMain();
//	addNewRow.trClass = 'hr_pos_hierarchy_line';
//	addNewRow.tbodyClass = 'form_data_line_tbody';
//	addNewRow.noOfTabs = 3;
//	addNewRow.lineNumberIncrementValue = 10;
//	addNewRow.removeDefault = true;
//	addNewRow.add_new_row();
// });


});
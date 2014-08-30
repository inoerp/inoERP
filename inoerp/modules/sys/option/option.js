function setValFromSelectPage(option_header_id) {
 this.option_header_id = option_header_id;
}

setValFromSelectPage.prototype.setVal = function() {
 option_header_id = this.option_header_id;
 $("#option_header_id").val(option_header_id);
};

$(document).ready(function() {
 //Popup for selecting option type
 $(".popup").click(function() {
	void window.open('select.php?class_name=option_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //add or show linw details
 addOrShow_lineDetails('tr.option_line0');

 //Check the option_id while entering the option line code
 function copy_option_header_id() {
	$(".option_line_code").blur(function()
	{
	 if ($("#option_header_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".option_line_code").val("");
	 } else {
		$(".option_header_id").val($("#option_header_id").val());
	 }
	});
 }

 copy_option_header_id();

 //Get the option_id on find button click
 $('a.show.option_header_id').click(function() {
	var optionId = $('#option_header_id').val();
//$(this).prop('href','option.php?option_header_id=' + optionId);
	$(this).attr('href', modepath() + 'option_header_id=' + optionId);
 });

 $("#content").on("click", ".add_row_img", function() {
//	add_new_row('tr.option_line0', 'tbody.form_data_line_tbody', 2);
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'option_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 2;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
	$(".tabsDetail").tabs();
 });

 onClick_addDetailLine('tr.option_detail_tr0', 'tbody.form_data_detail_tbody', 1);

//remove option lines
 $("#remove_row").click(function() {
	$('input[name="option_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });


 deleteData('form.php?class_name=option_header&line_class_name=option_line&detail_class_name=option_detail');
 remove_row();

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'option_header_id';
 classContextMenu.docLineId = 'option_line_id';
 classContextMenu.btn1DivId = 'option_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'option_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
 classContextMenu.contextMenu();

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=option_header';
 classSave.form_header_id = 'option_header';
 classSave.primary_column_id = 'option_header_id';
 classSave.line_key_field = 'option_line_code';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'option_header';
 classSave.lineClassName = 'option_line';
 classSave.saveMain();

});


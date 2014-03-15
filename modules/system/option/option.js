$(document).ready(function() {
 //Popup for selecting option type
 $(".popup").click(function() {
	void window.open('find_option.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 function parentWindow(findElement)
 {
	$(window.opener.document).find("#option_header_id").val(findElement);
	$('#form_box a.show').prop('href', 'option.php?option_header_id=' + findElement);
 }

 $("#selected").click(function() {
	var findElement = $(".select_option_header_id:checked").val();
	parentWindow(findElement);
	window.close();
 });
 
  $(".quick_select").click(function() {
    var findElement = $(this).val();
	parentWindow(findElement);
	window.close();
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
 $('#form_box a.show').click(function() {
	var optionId = $('#option_header_id').val();
//$(this).prop('href','option.php?option_header_id=' + optionId);
	$(this).attr('href', 'option.php?option_header_id=' + optionId);
 });


//onClick_add_new_row('tr.option_line0', 'tbody.form_data_line_tbody', 2);

 $("#content").on("click", ".add_row_img", function() {
		add_new_row('tr.option_line0', 'tbody.form_data_line_tbody', 2);
		$(".tabsDetail").tabs();
 });
 
// $("#content").on("click", ".add_row_img", function() {
//	add_new_row('tr.po_line0', 'tbody.form_data_line_tbody', 3);
//	$(".tabsDetail").tabs();
// });

 onClick_addDetailLine('tr.option_detail_tr0', 'tbody.form_data_detail_tbody', 1);

//remove option lines
 $("#remove_row").click(function() {
	$('input[name="option_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });
 

deleteData('json.option.php');
 save('json.option.php', '#option_header', 'line_id_cb', 'option_line_code', '#option_header_id');
 remove_row();
});


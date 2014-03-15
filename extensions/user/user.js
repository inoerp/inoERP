$(document).ready(function() {
// var Mandatory_Fields = ["#username", "First Enter User Name", "#enteredPassword", "First enter password"];
// select_mandatory_fields_all('#userDiv', Mandatory_Fields);

 //dont allow line entry with out bom_header id
 $('#form_line').on("click", function() {
	if (!$('#user_id').val()) {
	 alert('No header Id : First enter/save header details');
	} else {
	 var headerId = $('#user_id').val();
	 if (!$(this).find('.user_id').val()) {
		$(this).find('.user_id').val(headerId);
	 }
	}
 });

 //Get the user_id on find button click
 $('#form_header a.show').click(function() {
	var user_id = $('#user_id').val();
	$(this).attr('href', 'user.php?user_id=' + user_id);
 });

 //Popup for selecting option type
 $(".popup").click(function() {
	void window.open('find_user.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 function parentWindow(findElement)
 {
	$(window.opener.document).find("#user_id").val(findElement);
	$('#form_box a.show').prop('href', 'user.php?user_id=' + findElement);
 }

 $("#selected").click(function() {
	var findElement = $(".select_option_user_id:checked").val();
	parentWindow(findElement);
	window.close();
 });

 $(".quick_select").click(function() {
	var findElement = $(this).val();
	parentWindow(findElement);
	window.close();
 });


 $("#enteredRePassword").on('focusout', function() {
	var enteredPassword = $("#enteredPassword").val();
	if ($(this).val() !== enteredPassword)
	{
	 $('.hint.passwordError').hide();
	 $(this).after('<div class="hint passwordError">Two differnt passwords are entered</div>');
	}else{
	 $('.hint.passwordError').hide();
	}
 });

 $("#content tbody.form_data_line_tbody").on("click", ".add_row_img", function() {
	add_new_row('tr.user_role_assignment0', 'tbody.form_data_line_tbody', 1);
 });

//Save record
// save('json.user.php', '#user_header', 'line_id_cb', 'role_id', '#user_id', '', '');

 deleteData('json.user.php');
});


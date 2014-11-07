function setValFromSelectPage(user_id, address_id) {
 this.user_id = user_id;
 this.address_id = address_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var user_id = this.user_id;
 var address_id = this.address_id;
 if (user_id) {
	$("#user_id").val(user_id);
 }
  if (address_id) {
	$("#address_id").val(address_id);
 }
};

$(document).ready(function() {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'user_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["username", "username"];
 mandatoryCheck.mandatory_messages = ["First Enter User Name", "No Password"];
// mandatoryCheck.mandatoryField();

 //Get the user_id on find button click
 $('#form_header a.show').click(function() {
	var user_id = $('#user_id').val();
	$(this).attr('href', modepath() + 'user_id=' + user_id);
 });

 //Popup for selecting user
 $(".user_id.select_popup").click(function() {
		var link = 'select.php?class_name=user';
	void window.open(link, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
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

onClick_add_new_row('user_role_assignment', 'form_data_line_tbody', 1)

deleteData('form.php?class_name=user&line_class_name=user_role');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'user_header';
 classContextMenu.docLineId = 'user_role';
 classContextMenu.btn1DivId = 'user_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'user_role_assignment';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 1;
 classContextMenu.contextMenu();

// deleteData('json.po.php');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=user';
 classSave.form_header_id = 'user_header';
 classSave.primary_column_id = 'user_id';
 classSave.line_key_field = 'role_code';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'user';
 classSave.lineClassName = 'user_role';
 classSave.enable_select = true;
 classSave.saveMain();

});


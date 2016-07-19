$(document).ready(function() {

//Delete the comment form
// $("#page").on('click', '.delete_button', function() {
//	var comment_id = $(this).val();
//	if (confirm("Are you sure?")) {
//	 deleteComment(comment_id);
//	}
// });


 //FILE attachment
 var fu = new fileUploadMain();
 fu.json_url = 'extensions/file/upload.php';
 fu.fileUpload();


 $('#form_line').on('change', '.checkBox', function() {
	if (this.checked) {
	 $(this).val(($(this).closest('tr').find('.field_name').val()));
	} else {
	 $(this).val(1);
	}
 });

// $('#save').on('click', function() {
//	$(".error").append('Saving Data');
//	var form_header_id = '#page';
//	$(form_header_id).find('textarea').each(function() {
//	 var name = $(this).attr('name');
//	 var data = tinyMCE.get(name).getContent();
//	 $(this).html(data);
//	});
//	var headerData = $(form_header_id).serializeArray();
//	saveHeader('form.php?class_name=page', headerData, '#page_id', '', true, 'page');
//
// });

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=page';
 classSave.form_header_id = 'page_header';
 classSave.primary_column_id = 'page_id';
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = 'page';
 classSave.enable_select = true;
 classSave.saveMain();

// deleteHeader('json.page.php', $('.page_id').val());
 deleteHeader('form.php?class_name=page', $('#hidden_page_id').val());

});



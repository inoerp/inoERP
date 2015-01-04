$(document).ready(function () {

//get the attachement form
// get_attachment_form('../file/json.file.php');

// //FILE attachment
// var fu = new fileUploadMain();
// fu.json_url = 'extensions/file/upload.php';
// fu.fileUpload();

// $('a.show.content_id').click(function() {
//	var content_id = $('.content_id').val();
//	var content_type = $('.content_type').val();
//	$(this).attr('href', 'content.php?content_id=' + content_id + '&content_type=' + content_type);
// });

 $('#form_line').on('change', '.checkBox', function () {
  if (this.checked) {
   $(this).val(($(this).closest('tr').find('.field_name').val()));
  } else {
   $(this).val(1);
  }
 });

 $('#save').on('click', function () {
  $(".error").append('Saving Data');
  var form_header_id = '#content_data';
  if ($('.mce-tinymce').length >= 1) {
   $(form_header_id).find('textarea').each(function () {
    var name = $(this).attr('name');
    var data = tinyMCE.get(name).getContent();
    $(this).html(data);
   });
  }
  var headerData = $(form_header_id).serializeArray();
  saveHeader('content.php', headerData, '#content_id', '', '', true, 'content');
 });

 deleteHeader('form.php?class_name=content', $('#content_id').val());

// var classSave = new saveMainClass();
// classSave.json_url = 'content.php';
// classSave.form_header_id = 'content';
// classSave.primary_column_id = 'content_id';
// classSave.single_line = false;
//classSave.saveMain();

 $('a.show.content_id').on('click', function () {
  var path = 'content.php?mode=2&content_id=' + $('#content_id').val()
          + '&content_type=' + $('#content_type').val();
  $(this).attr('href', path);
 });

});



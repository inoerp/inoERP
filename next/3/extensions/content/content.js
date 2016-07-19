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

  deleteHeader('form.php?class_name=content', $('#content_id').val());


 $('body').off('click', 'a.show2.content_id').on('click', 'a.show2.content_id', function (e) {
  if (!($('#content_id').val())) {
   e.preventDefault();
   return;
  }
  var path = 'content.php?mode=2&content_id=' + $('#content_id').val()
          + '&content_type=' + $('#content_type').val();
  $(this).attr('href', path);
 });

});



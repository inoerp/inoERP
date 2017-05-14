$(document).ready(function () {

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



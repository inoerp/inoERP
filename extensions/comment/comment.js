$(document).ready(function() {
 $('.show_loading_small').hide();
 
  tinymce.init({
	selector: '.mediumtext',
	mode: "exact",
//    theme: "modern",
	plugins: 'textcolor link image lists code table emoticons',
	width: 680,
	height: 70,
	toolbar: "styleselect code | emoticons forecolor backcolor bold italic pagebreak | alignleft aligncenter alignright | bullist numlist outdent indent | link image inserttable ",
	menubar: false,
	statusbar: false,
	file_browser_callback: function() {
	 $('#attachment_button').click();
	}
 });
 
 $('.submit_comment').on('click', function() {
$('.show_loading_small').show();
$(this).closest('form').find('textarea').each(function() {
 var divId = $(this).prop('id');
 var data = tinyMCE.get(divId).getContent();
 $(this).html(data);
});
var headerData = $(this).closest('form').serializeArray();
saveHeader('../comment/comment.php', headerData, '#comment_id', '', true, 'comment');
$(".error").append('<input type="button" value="Reload page" onclick="location.reload();">');
});
});
 
  //FILE attachment
 var fu = new fileUploadMain();
fu.json_url = '../file/upload.php';
fu.fileUpload();
//   $('#loading').hide();
// $('.show_loading_small').hide();
//Beginig of comment post
// function commentShowResponse(responseText, statusText, xhr, $form) {
//  $('li#loading').hide();
//  $("#output").append(responseText);
//  $('#comment_header').resetForm();
//  location.reload(true);
// }
//
//
// var Commentoptions = {
//  success: commentShowResponse,
//  error : commentShowResponse,
//  data: { submit_comment: 'submit_comment' },
//  clearForm : true
//   };
//
// $('#comment_header').submit(function() {
//  tinyMCE.triggerSave();
//  $('li#loading').show();
//  $(this).ajaxSubmit(Commentoptions);
//  return false;

//End of comment post


//beginf of get attachment
//function getAttachmentForm(){
//       $('#loading').show();
////var org_id = $(".form_table #org_id").val();
//$.ajax({
//     url:'../file/json.file.php' ,
//     type: 'get'
//     }).done(function(data){
//     var div = $('#add_attachments', $(data)).html();
//        $("#attachment_comment").append(div);
//        $('#loading').hide();
//      }).fail(function(){
//     alert("Attachment loading failed");
//     $('#loading').hide();
//     });
//}

//$("#comment_attachment_button").click(function() {
// getAttachmentForm();
//});

//end of getting attachment form
//

$(document).ready(function() {

//get the attachement form
 get_attachment_form('../file/json.file.php');

//get the comment form
 function getCommentForm() {
	$('#loading').show();
	var content_id = $("#content_id").val();
	$.ajax({
	 url: '../comment/comment.php',
	 data: {reference_table: 'content',
		reference_id: content_id},
	 type: 'get'
	}).done(function(data) {
	 var div = $('#comment', $(data)).html();
	 $("#new_comment").append(div);
	 $('#loading').hide();
	}).fail(function() {
	 alert("Comment content loading failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }
 $("#comment_button").click(function() {
	getCommentForm();
 });


//Delete the comment form
 $(".delete_button").click(function() {
	var comment_id = $(this).val();
	if (confirm("Are you sure?")) {
	 deleteComment(comment_id);
	}
 });

 function deleteComment(comment_id) {
	$('#loading').show();
	$.ajax({
	 url: '../comment/comment.php',
	 data: {delete: '1',
		comment_id: comment_id},
	 type: 'get'
	}).done(function(result) {
	  var div = $(result).filter('div#delete_comment').html();
	 $(".error").append(div);
	 $('#loading').hide();
	}).fail(function() {
	 alert("Comment delete failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }

//Update the comment form
 $(".update_button").click(function() {
	var comment_id = $(this).val();
	var ulclass = $(this).closest("ul").parent().parent().children("li.line_li");
	if (confirm("Are you sure?")) {
	 updateComment(comment_id, ulclass);
	}
 });

 function updateComment(comment_id, ulclass) {
	$('#loading').show();
	$.ajax({
	 url: '../comment/comment.php',
	 data: {update: '1',
		comment_id: comment_id},
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#commentForm').html();
	 $(ulclass).append(div);
	 $('#loading').hide();
	}).fail(function() {
	 alert("Comment update failed");
	 $('#loading').hide();
	});
 }
 
 //FILE attachment
 var fu = new fileUploadMain();
fu.json_url = '../file/upload.php';
fu.fileUpload();

 $('a.show.content_id').click(function() {
	var content_id = $('.content_id').val();
	var content_type = $('.content_type').val();
	$(this).attr('href', 'contents.php?content_id=' + content_id + '&content_type=' + content_type);
 });
 
$('#form_line').on('change','.checkBox', function(){
if(this.checked) {
$(this).val(($(this).closest('tr').find('.field_name').val()));
}else{
$(this).val(1);
}
});

 $('#save').on('click', function() {
	$(".error").append('Saving Data');
	var form_header_id = '#content';
	$(form_header_id).find('textarea').each(function() {
	 var name = $(this).attr('name');
	 var data = tinyMCE.get(name).getContent();
	 $(this).html(data);
	});
	var headerData = $(form_header_id).serializeArray();
	saveHeader('content.php', headerData, '#content_id', '',true,'content');

 });

  deleteHeader('json.content.php', $('.content_id').val());
	
// var classSave = new saveMainClass();
// classSave.json_url = 'content.php';
// classSave.form_header_id = 'content';
// classSave.primary_column_id = 'content_id';
// classSave.single_line = false;
//classSave.saveMain();

});



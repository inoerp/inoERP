//get the comment form
function getCommentForm() {
 $('#loading').show();
 var content_id = $("#content_id").val();
 $.ajax({
	url: 'comment.php',
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

function deleteComment() {
 var homeUrl = $('#home_url').val();
 var daletePath = homeUrl + 'form.php?class_name=comment';
 $(".delete_button").click(function(e) {
	var headerId = $(this).val();
	$(".delete_button").addClass("show_loading_small");
	$(".delete_button").prop('disabled', true);
	e.preventDefault();
	if (confirm("Do you really want to delete ?\n" + headerId)) {
	 $.ajax({
		url: daletePath,
		data: {
		 delete_id: headerId,
		 deleteType: 'header',
		 delete: '1'},
		type: 'get',
		beforeSend: function() {
		 $('.show_loading_small').show();
		},
		complete: function() {
		 $('.show_loading_small').hide();
		}
	 }).done(function(result) {
		$(".error").append(result);
		$(".delete_button").removeClass("show_loading_small");
		$(".delete_button").prop('disabled', false);
	 }).fail(function(error, textStatus, xhr) {
		alert("delete failed \n" + error + textStatus + xhr);
		$(".delete_button").removeClass("show_loading_small");
		$(".delete_button").prop('disabled', false);
	 });
	}
 });
}

function updateComment(comment_id, ulId) {
 var homeUrl = $('#home_url').val();
  var savePath = homeUrl + 'comment.php';
  
 $('#loading').show();
 $.ajax({
	url: savePath,
	data: {update: '1',
	 comment_id: comment_id},
	type: 'get'
 }).done(function(result) {
	var div = $(result).filter('div#commentForm').html();
  var ulId_h = '#'+ulId;
  	$('#content').find(ulId_h).find('li.line_li').append(div);
	$('#loading').hide();
 }).fail(function(e) {
 	alert("Comment update failed ");
	$('#loading').hide();
 });
}

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

 //Delete the comment form
 deleteComment();


//Update the comment form
 $("#content").on('click', '.update_button', function(e) {
  e.preventDefault();
	var comment_id = $(this).val();
	var ulId = $(this).closest(".commentRecord").prop('id');
  	if (confirm("Are you sure?")) {
	 updateComment(comment_id, ulId);
	}
	e.stopPropagation();
 });


// //FILE attachment
// var fu = new fileUploadMain();
// fu.json_url = 'extensions/file/upload.php';
// fu.fileUpload();

// deleteData('form.php?class_name=comment&line_class_name=comment');

 $('.submit_comment').on('click', function() {
	$('.show_loading_small').show();
	$(this).closest('form').find('textarea').each(function() {
	 var divId = $(this).prop('id');
	 var data = tinyMCE.get(divId).getContent();
	 $(this).html(data);
	});
	var headerData = $(this).closest('form').serializeArray();
	var homeUrl = $('#home_url').val();
	var savePath = homeUrl + 'form.php?class_name=comment';
	saveHeader(savePath, headerData, '#comment_id', '', true, 'comment');
	$(".comment_error").replaceWith('<input type="button" value="Reload page" onclick="location.reload();">');
 });

});


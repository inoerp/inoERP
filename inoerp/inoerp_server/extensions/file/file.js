$(document).ready(function() {
 $('#loading').hide();
 $('li#loading').hide();
//hiding the loader

 //beging of file upload
 function remove_file() {
	$(".remove_file").click(function() {
	 $(this).closest('ul').remove();
	});
 }

////mass uplaod
// var fu = new fileUploadMain();
// if($('#upload_type').val()){
//  var upload_type = $('#upload_type').val();
//  fu.upload_type = upload_type;
//  fu.class_name = $('.class_name').val();
//  fu.directory = 'temp';
// }else{
//  var upload_type = '';
// }
// fu.json_url = homeUrl + 'extensions/file/upload.php';
	
	
 function deleteFile(file_reference_id) {
	$('.show_loading_small').show();
	$.ajax({
	 url: 'json.file.php',
	 data: {delete: '1',
		file_reference_id: file_reference_id
	 },
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#json_delete_file').html();
	 $(".error").append(div);
	 $('.show_loading_small').hide();
	}).fail(function() {
	 alert("File delete failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }


//Delete content type : drop table
 $(".remove_row_img").click(function() {
	var file_reference_id = $(this).closest('ul').find('.delete_file').val();
	if (confirm("Are you sure?")) {
	 deleteFile(file_reference_id);
	}
 });



});

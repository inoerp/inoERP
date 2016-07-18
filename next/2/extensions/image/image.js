$(document).ready(function() {
 $('#loading').hide();
 $('li#loading').hide();
//hiding the loader

 //beging of image upload
 function remove_image() {
	$(".remove_image").click(function() {
	 $(this).closest('ul').remove();
	});
 }

//mass uplaod
 	var fu = new imageUploadMain();
 	fu.json_url = 'extensions/image/upload.php';
 	fu.upload_type = 'only_server';
 	fu.class_name = $('.class_name').val();
 	fu.directory = 'temp';
 	fu.imageUpload();
	
	
 function deleteimage(image_reference_id) {
	$('.show_loading_small').show();
	$.ajax({
	 url: 'json.image.php',
	 data: {delete: '1',
		image_reference_id: image_reference_id
	 },
	 type: 'get'
	}).done(function(result) {
	 var div = $(result).filter('div#json_delete_image').html();
	 $(".error").append(div);
	 $('.show_loading_small').hide();
	}).fail(function() {
	 alert("image delete failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }


//Delete content type : drop table
 $(".remove_row_img").click(function() {
	var image_reference_id = $(this).closest('ul').find('.delete_image').val();
	if (confirm("Are you sure?")) {
	 deleteimage(image_reference_id);
	}
 });

});
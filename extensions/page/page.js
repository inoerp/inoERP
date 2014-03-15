$(document).ready(function() {
  $('#loading').hide();
//hiding the loader
var $loader = $('#loading'), timer;
$loader.hide().ajaxStart(function()
    {
        timer && clearTimeout(timer);
        timer = setTimeout(function()
        {
            $loader.show();
        },
        10000);
    }).ajaxStop(function()
    {
        clearTimeout(timer);
        $loader.hide();
    });
    
//creating tabs
$(function() {
    $( "#tabsHeader" ).tabs();
    $( "#tabsLine" ).tabs();
  });
  
//Refresh the page
$('.refresh').click(function() {
    location.reload(true);
});

//constant ('INC_ORGS');
//constant ('DS');

//Show the org name after the item_id is selected
$("#inventory_id.getOrgName").blur(function() {
getOrgName();
});

//disbale the subinventory id
//$(".form_table #subinventory_id").attr("disabled",true);

//get the attachement form
$("#attachment_button").click(function () {
 getAttachmentForm();
});

function getAttachmentForm(){
       $('#loading').show();
//var org_id = $(".form_table #org_id").val();
$.ajax({
     url:'../file/json.file.php' ,
     type: 'get'
     }).done(function(data){
     var div = $('#add_attachments', $(data)).html();
        $("#show_attachment").append(div);
        $('#loading').hide();
        $('li#loading').hide();
      }).fail(function(){
     alert("Attachment loading failed");
     $('#loading').hide();
     });
// $(".form_table #subinventory_id").attr("disabled",false);
}

//get the comment form
$("#comment_button").click(function () {
 getCommentForm();
});

function getCommentForm(){
       $('#loading').show();
var page_id = $("#page_id").val();
$.ajax({
     url:'../comment/comment.php' ,
     data: { reference_table: 'page' ,
            reference_id: page_id},
     type: 'get'
     }).done(function(data){
     var div = $('#comment', $(data)).html();
        $("#new_comment").append(div);
        $('#loading').hide();
      }).fail(function(){
     alert("Comment page loading failed");
     $('#loading').hide();
     });
// $(".form_table #subinventory_id").attr("disabled",false);
}


//Delete the comment form
$(".delete_button").click(function (){
 var comment_id = $(this).val();
if(confirm ("Are you sure?")){
 deleteComment(comment_id);
}
});

function deleteComment(comment_id){
       $('#loading').show();
$.ajax({
     url:'../comment/json.comment.php' ,
     data: { delete: '1' ,
            comment_id: comment_id},
     type: 'get'
     }).done(function(data){
     var div = $('#json_delete_comment', $(data)).html();
        $(".error").append(div);
        $('#loading').hide();
      }).fail(function(){
     alert("Comment delete failed");
     $('#loading').hide();
     });
// $(".form_table #subinventory_id").attr("disabled",false);
}

//Update the comment form
$(".update_button").click(function (){
 var comment_id = $(this).val();
 var ulclass = $(this).closest("ul").parent().parent().children("li.line_li");
if(confirm ("Are you sure?")){
 updateComment(comment_id, ulclass);
}
});

function updateComment(comment_id,ulclass){
       $('#loading').show();
$.ajax({
     url:'../comment/json.comment.php' ,
     data: { update: '1' ,
            comment_id: comment_id},
     type: 'get'
     }).done(function(data){
     var div = $('#json_update_comment', $(data)).html();
        $(ulclass).append(div);
        $('#loading').hide();
      }).fail(function(){
     alert("Comment update failed");
     $('#loading').hide();
     });
// $(".form_table #subinventory_id").attr("disabled",false);
}


//get the new search criteria
$("#new_search_criteria_add").click(function(){
  $('#loading').show();
var new_search_criteria = $(".new_search_criteria").val();
$.ajax({
     url:'json.subinventory.php' ,
     data : { new_search_criteria : new_search_criteria},
     type: 'get'
     }).done(function(data){
      var div = $('#new_search_criteria', $(data)).html();
	  $("ul.search_form").append(div);       
        $('#loading').hide();
      }).fail(function(){
//     alert("org name loading failed");
     $('#loading').hide();
     });
});



}


 
);  

$("document").ready(function(){
  alert ("window is ready");
});

$("p").clone().add("<span>Again</span>").appendTo(document.body);
$("#form_line").clone().appendTo($("#option"));

$("form_line").clone().appendTo(document.getElementById("option"));


$(document).ready(function(){
var x = $("#option_id").val();
$("#add_object").click(function()
{
$.ajax({
  url: 'test1.php',
  type: 'POST',
  dataType: 'json',
  data: {id:  '50' },
  sucess: function(result){
  alert ("Data : " + data + "\nStatsu : " + result.status);
    }
});
});
});


$.ajax({
    url: '/my/site',
    data: {action: 'test'},
    type: 'post',
    success: function(output) {
        alert(output);
    }
 });